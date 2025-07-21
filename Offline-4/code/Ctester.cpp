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
ofstream tempCodeFile;  // Temporary file stream for on-the-fly code generation

int syntaxErrorCount;

SymbolTable *symbolTable;

string optimizeAssembly(const string &code)
{
    vector<string> lines;
    stringstream ss(code);
    string line;
    while (getline(ss, line))
        lines.push_back(line);

    // First pass: Remove dead code after RET/INT 21H instructions
    // But preserve labels that might be jumped to from before the RET
    vector<string> deadCodeRemoved;
    bool inFunction = false;
    bool foundReturn = false;
    string currentFunctionName = "";

    for (size_t i = 0; i < lines.size(); i++)
    {
        string trimmed = lines[i];
        // Remove leading whitespace for analysis
        size_t start = trimmed.find_first_not_of(" \t");
        if (start != string::npos)
            trimmed = trimmed.substr(start);

        // Check if we're entering a function
        if (trimmed.find(" PROC") != string::npos && trimmed.find(" ENDP") == string::npos)
        {
            inFunction = true;
            foundReturn = false;
            size_t procPos = trimmed.find(" PROC");
            currentFunctionName = trimmed.substr(0, procPos);
            deadCodeRemoved.push_back(lines[i]);
        }
        // Check if we're exiting a function
        else if (trimmed.find(" ENDP") != string::npos)
        {
            inFunction = false;
            foundReturn = false;
            deadCodeRemoved.push_back(lines[i]);
        }
        // Check for return statements
        else if (inFunction && (trimmed.find("RET") != string::npos || trimmed.find("INT 21H") != string::npos))
        {
            if (!foundReturn)
            {
                // Only add the first return statement
                deadCodeRemoved.push_back(lines[i]);
                foundReturn = true;
            }
            // Skip any subsequent return statements
        }
        // After return, keep labels but skip other instructions
        else if (inFunction && foundReturn)
        {
            // Keep labels as they might be jumped to from before the return
            if (trimmed.length() > 0 && trimmed.back() == ':' && trimmed[0] == 'L')
            {
                deadCodeRemoved.push_back(lines[i]);
                foundReturn = false; // Reset foundReturn as we have reachable code after this label
            }
            else
            {
                // Skip this line as it's dead code after return
                continue;
            }
        }
        else
        {
            deadCodeRemoved.push_back(lines[i]);
        }
    }

    // Second pass: Remove redundant MOVs, trivial ops, and redundant PUSH/POP
    vector<string> optimized;
    for (size_t i = 0; i < deadCodeRemoved.size(); i++)
    {
        string currentLine = deadCodeRemoved[i];
        string trimmedCurrent = currentLine;
        size_t start = trimmedCurrent.find_first_not_of(" \t");
        if (start != string::npos)
            trimmedCurrent = trimmedCurrent.substr(start);

        // Check for redundant MOVs
        if (i + 1 < deadCodeRemoved.size() &&
            deadCodeRemoved[i].find("MOV AX,") != string::npos &&
            deadCodeRemoved[i + 1].find("MOV") != string::npos &&
            deadCodeRemoved[i + 1].find(", AX") != string::npos &&
            deadCodeRemoved[i].substr(7) == deadCodeRemoved[i + 1].substr(4, deadCodeRemoved[i + 1].find(",") - 4))
        {
            optimized.push_back(deadCodeRemoved[i]);
            i++; // Skip redundant MOV
        }
        else if (deadCodeRemoved[i].find("ADD AX, 0") == string::npos &&
                 deadCodeRemoved[i].find("MUL AX, 1") == string::npos)
        {
            optimized.push_back(deadCodeRemoved[i]);
        }
    }

    // Third pass: Unify consecutive labels and redirect jumps
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
                l.substr(pos, 3) == "JGE" || l.substr(pos, 4) == "JNGE" || l.substr(pos, 3) == "JNG" ||
                l.substr(pos, 4) == "CALL")
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
                l.substr(pos, 3) == "JGE" || l.substr(pos, 4) == "JNGE" || l.substr(pos, 3) == "JNG" ||
                l.substr(pos, 4) == "CALL")
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
    string tempCodeFileName = outputDirectory + "code.txt";

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

    tempCodeFile.open(tempCodeFileName);
    if (!tempCodeFile.is_open())
    {
        cerr << "Error opening temporary code file: " << tempCodeFileName << endl;
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

    // start parsing at the 'start' rule
    parser.start();

    // Read temporary code file
    string tempCode;
    tempCodeFile.close(); // Close for writing
    ifstream tempCodeReader(tempCodeFileName);
    if (tempCodeReader.is_open())
    {
        string line;
        while (getline(tempCodeReader, line))
        {
            tempCode += line + "\n";
        }
        tempCodeReader.close();
    }
    else
    {
        cerr << "Error reading temporary code file: " << tempCodeFileName << endl;
        return 1;
    }

    // Assemble final assembly code
    string assemblyCode = ".MODEL SMALL\n\n.STACK 1000H\n\n" + parser.dataSegment + ".CODE\n\n" + tempCode;

    // Prepare print procedures string
    string printProcedures = "";
    if (parser.hasPrintln)
    {
        printProcedures = "\n; Print procedures\n" + string(
                                                         "NEW_LINE PROC\n"
                                                         "    PUSH AX\n"
                                                         "    PUSH DX\n"
                                                         "    MOV AH,2\n"
                                                         "    MOV DL,0DH\n"
                                                         "    INT 21H\n"
                                                         "    MOV AH,2\n"
                                                         "    MOV DL,0AH\n"
                                                         "    INT 21H\n"
                                                         "    POP DX\n"
                                                         "    POP AX\n"
                                                         "    RET\n"
                                                         "NEW_LINE ENDP\n\n"
                                                         "PRINT_OUTPUT PROC\n"
                                                         "    PUSH AX\n"
                                                         "    PUSH BX\n"
                                                         "    PUSH CX\n"
                                                         "    PUSH DX\n"
                                                         "    PUSH SI\n"
                                                         "    LEA SI,NUMBER\n"
                                                         "    MOV BX,10\n"
                                                         "    ADD SI,4\n"
                                                         "    CMP AX,0\n"
                                                         "    JNGE NEGATE\n"
                                                         "PRINT:\n"
                                                         "    XOR DX,DX\n"
                                                         "    DIV BX\n"
                                                         "    MOV [SI],DL\n"
                                                         "    ADD [SI],'0'\n"
                                                         "    DEC SI\n"
                                                         "    CMP AX,0\n"
                                                         "    JNE PRINT\n"
                                                         "    INC SI\n"
                                                         "    MOV BYTE PTR [SI + 6], '$'\n"
                                                         "    LEA DX,SI\n"
                                                         "    MOV AH,9\n"
                                                         "    INT 21H\n"
                                                         "    POP SI\n"
                                                         "    POP DX\n"
                                                         "    POP CX\n"
                                                         "    POP BX\n"
                                                         "    POP AX\n"
                                                         "    RET\n"
                                                         "NEGATE:\n"
                                                         "    PUSH AX\n"
                                                         "    MOV AH,2\n"
                                                         "    MOV DL,'-'\n"
                                                         "    INT 21H\n"
                                                         "    POP AX\n"
                                                         "    NEG AX\n"
                                                         "    JMP PRINT\n"
                                                         "PRINT_OUTPUT ENDP\n");
    }

    // Complete assembly with print procedures
    assemblyCode += printProcedures;
    assemblyCode += "END MAIN\n";

    // Write assembly code to files
    ofstream codeFile(outputDirectory + "code.asm");
    codeFile << assemblyCode;
    codeFile.close();

    ofstream optCodeFile(outputDirectory + "optimized_code.asm");
    // Create main code without print procedures for optimization
    string mainCodeOnly = ".MODEL SMALL\n\n.STACK 1000H\n\n" + parser.dataSegment + ".CODE\n\n" + tempCode + "END MAIN\n";
    string optimizedMainCode = optimizeAssembly(mainCodeOnly);

    // Remove "END MAIN" from optimized main code to add print procedures
    size_t endMainPos = optimizedMainCode.find("END MAIN");
    if (endMainPos != string::npos)
    {
        optimizedMainCode = optimizedMainCode.substr(0, endMainPos);
    }

    // Add print procedures to optimized code and END directive
    string optimizedCode = optimizedMainCode + printProcedures + "END MAIN\n";
    optCodeFile << optimizedCode;
    optCodeFile.close();

    // Update code.txt to include the complete assembly with data segment
    ofstream completeCodeFile(tempCodeFileName);
    completeCodeFile << assemblyCode;
    completeCodeFile.close();

    // clean up
    delete symbolTable;
    inputFile.close();
    parserLogFile.close();
    errorFile.close();
    lexLogFile.close();
    cout << "Assembly code generated. Check output/code.asm and output/optimized_code.asm." << endl;
    return 0;
}
