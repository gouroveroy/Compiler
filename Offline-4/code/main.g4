#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "antlr4-runtime.h"
#include "C2105017Lexer.h"
#include "C2105017Parser.h"
#include "SymbolTable/2105017_Hash.cpp"
#include "SymbolTable/2105017_symbol_table.h"

using namespace antlr4;
using namespace std;

ofstream parserLogFile; // global output stream
ofstream errorFile;     // global error stream
ofstream lexLogFile;    // global lexer log stream

int syntaxErrorCount;

SymbolTable *symbolTable;

string optimizeAssembly(const string &code)
{
    vector<string> lines;
    stringstream ss(code);
    string line;
    while (getline(ss, line))
        lines.push_back(line);

    // First pass: Remove redundant MOVs and trivial ops
    vector<string> optimized;
    for (size_t i = 0; i < lines.size(); i++)
    {
        if (i + 1 < lines.size() &&
            lines[i].find("MOV AX,") != string::npos &&
            lines[i + 1].find("MOV") != string::npos &&
            lines[i + 1].find(", AX") != string::npos &&
            lines[i].substr(7) == lines[i + 1].substr(4, lines[i + 1].find(",") - 4))
        {
            optimized.push_back(lines[i]);
            i++; // Skip redundant MOV
        }
        else if (lines[i].find("ADD AX, 0") == string::npos &&
                 lines[i].find("MUL AX, 1") == string::npos)
        {
            optimized.push_back(lines[i]);
        }
    }

    // Second pass: Unify consecutive labels and redirect jumps
    // 1. Find groups of consecutive labels
    unordered_map<string, string> labelMap; // label -> canonical label
    vector<string> unified;
    for (size_t i = 0; i < optimized.size();)
    {
        // Find group of consecutive labels
        vector<size_t> labelIdxs;
        while (i < optimized.size())
        {
            string &l = optimized[i];
            size_t len = l.length();
            if (len > 2 && l[0] == 'L' && l[len - 1] == ':')
            {
                labelIdxs.push_back(i);
                ++i;
            }
            else
            {
                break;
            }
        }
        if (!labelIdxs.empty())
        {
            // Pick the first as canonical
            string canonical = optimized[labelIdxs[0]].substr(0, optimized[labelIdxs[0]].length() - 1);
            for (size_t idx : labelIdxs)
            {
                string label = optimized[idx].substr(0, optimized[idx].length() - 1);
                labelMap[label] = canonical;
            }
            unified.push_back(canonical + ":");
        }
        // Copy non-label line
        if (i < optimized.size())
        {
            unified.push_back(optimized[i]);
            ++i;
        }
    }

    // 2. Redirect all jumps/calls to canonical label
    for (auto &l : unified)
    {
        size_t pos = l.find_first_of("J");
        if (pos != string::npos)
        {
            // Look for jump/call instructions
            if (l.substr(pos, 3) == "JMP" || l.substr(pos, 2) == "JE" || l.substr(pos, 3) == "JNE" ||
                l.substr(pos, 2) == "JL" || l.substr(pos, 2) == "JG" || l.substr(pos, 3) == "JLE" ||
                l.substr(pos, 3) == "JGE" || l.substr(pos, 4) == "CALL")
            {
                size_t labelStart = l.find_last_of(' ');
                if (labelStart != string::npos && labelStart + 1 < l.size())
                {
                    string label = l.substr(labelStart + 1);
                    // Remove trailing comment if any
                    size_t comment = label.find(';');
                    if (comment != string::npos)
                        label = label.substr(0, comment);
                    // Remove trailing colon if any
                    if (!label.empty() && label.back() == ':')
                        label.pop_back();
                    if (labelMap.count(label))
                    {
                        l.replace(labelStart + 1, label.length(), labelMap[label]);
                    }
                }
            }
        }
    }

    // 3. Remove unused labels (not referenced)
    unordered_set<string> referencedLabels;
    for (const auto &l : unified)
    {
        size_t pos = l.find_first_of("J");
        if (pos != string::npos)
        {
            if (l.substr(pos, 3) == "JMP" || l.substr(pos, 2) == "JE" || l.substr(pos, 3) == "JNE" ||
                l.substr(pos, 2) == "JL" || l.substr(pos, 2) == "JG" || l.substr(pos, 3) == "JLE" ||
                l.substr(pos, 3) == "JGE" || l.substr(pos, 4) == "CALL")
            {
                size_t labelStart = l.find_last_of(' ');
                if (labelStart != string::npos && labelStart + 1 < l.size())
                {
                    string label = l.substr(labelStart + 1);
                    size_t comment = label.find(';');
                    if (comment != string::npos)
                        label = label.substr(0, comment);
                    if (!label.empty() && label.back() == ':')
                        label.pop_back();
                    referencedLabels.insert(label);
                }
            }
        }
    }
    vector<string> finalOpt;
    for (size_t i = 0; i < unified.size(); ++i)
    {
        string &l = unified[i];
        size_t len = l.length();
        if (len > 2 && l[0] == 'L' && l[len - 1] == ':')
        {
            string labelName = l.substr(0, len - 1);
            if (referencedLabels.find(labelName) == referencedLabels.end())
                continue;
        }
        finalOpt.push_back(l);
    }

    string result;
    for (const auto &optLine : finalOpt)
        result += optLine + "\n";
    return result;
}

class CustomErrorListener : public BaseErrorListener
{
public:
    void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line,
                     size_t charPositionInLine, const string &msg, exception_ptr e) override
    {
        string tokenText;
        if (offendingSymbol)
        {
            auto *vocab = &recognizer->getVocabulary();
            tokenText = vocab->getSymbolicName(offendingSymbol->getType());
            if (tokenText.empty())
                tokenText = offendingSymbol->getText();
        }

        // Get expected tokens' symbolic names (only if recognizer is a Parser)
        vector<string> expectedNames;
        auto *parser = dynamic_cast<antlr4::Parser *>(recognizer);
        if (parser)
        {
            auto expectedTokens = parser->getExpectedTokens();
            auto *vocab = &parser->getVocabulary();
            for (auto t : expectedTokens.toList())
            {
                string name = string(vocab->getSymbolicName(t));
                if (!name.empty())
                    expectedNames.push_back(name);
            }
        }
        string expecting;
        if (!expectedNames.empty())
        {
            expecting = expectedNames[0];
            for (size_t i = 1; i < expectedNames.size(); ++i)
            {
                expecting += " or " + expectedNames[i];
            }
        }

        errorFile << "Error at line " << line << ": syntax error, unexpected " << tokenText;
        if (!expecting.empty())
            errorFile << ", expecting " << expecting;
        errorFile << endl;
        syntaxErrorCount++;
    }
};

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // ---- Input File ----
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    string outputDirectory = "output/";
    string parserLogFileName = outputDirectory + "parserLog.txt";
    string errorFileName = outputDirectory + "errorLog.txt";
    string lexLogFileName = outputDirectory + "lexerLog.txt";

    // create output directory if it doesn't exist
    system(("mkdir -p " + outputDirectory).c_str());

    // ---- Output Files ----
    parserLogFile.open(parserLogFileName);
    if (!parserLogFile.is_open())
    {
        cerr << "Error opening parser log file: " << parserLogFileName << endl;
        return 1;
    }

    errorFile.open(errorFileName);
    if (!errorFile.is_open())
    {
        cerr << "Error opening error log file: " << errorFileName << endl;
        return 1;
    }

    lexLogFile.open(lexLogFileName);
    if (!lexLogFile.is_open())
    {
        cerr << "Error opening lexer log file: " << lexLogFileName << endl;
        return 1;
    }

    // ---- Parsing Flow ----
    ANTLRInputStream input(inputFile);
    C2105017Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    C2105017Parser parser(&tokens);

    int numberOfBuckets = 7;
    symbolTable = new SymbolTable(numberOfBuckets, Hash::SDBMHash, parserLogFile);
    // this is necessary to avoid the default error listener and use our custom error handling
    parser.removeErrorListeners();
    lexer.removeErrorListeners();
    // parser.addErrorListener(new CustomErrorListener());

    // start parsing at the 'start' rule
    parser.start();

    // Write assembly code to files
    ofstream codeFile(outputDirectory + "code.asm");
    codeFile << parser.assemblyCode;
    codeFile.close();

    ofstream optCodeFile(outputDirectory + "optimized_code.asm");
    string optimizedCode = optimizeAssembly(parser.assemblyCode);
    optCodeFile << optimizedCode;
    optCodeFile.close();

    // clean up
    delete symbolTable;
    inputFile.close();
    parserLogFile.close();
    errorFile.close();
    lexLogFile.close();
    cout << "Assembly code generated. Check output/code.asm and output/optimized_code.asm." << endl;
    return 0;
}
