#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "C8086Lexer.h"
#include "C8086Parser.h"
#include "SymbolTable/2105017_Hash.cpp"
#include "SymbolTable/2105017_symbol_table.h"

using namespace antlr4;
using namespace std;

ofstream parserLogFile; // global output stream
ofstream errorFile; // global error stream
ofstream lexLogFile; // global lexer log stream

int syntaxErrorCount;

SymbolTable *symbolTable;

class CustomErrorListener : public BaseErrorListener {
public:
    void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line,
                     size_t charPositionInLine, const string &msg, exception_ptr e) override {
        string tokenText;
        if (offendingSymbol) {
            auto* vocab = &recognizer->getVocabulary();
            tokenText = vocab->getSymbolicName(offendingSymbol->getType());
            if (tokenText.empty()) tokenText = offendingSymbol->getText();
        }

        // Get expected tokens' symbolic names (only if recognizer is a Parser)
        vector<string> expectedNames;
        auto *parser = dynamic_cast<antlr4::Parser *>(recognizer);
        if (parser) {
            auto expectedTokens = parser->getExpectedTokens();
            auto* vocab = &parser->getVocabulary();
            for (auto t : expectedTokens.toList()) {
                string name = string(vocab->getSymbolicName(t));
                if (!name.empty()) expectedNames.push_back(name);
            }
        }
        string expecting;
        if (!expectedNames.empty()) {
            expecting = expectedNames[0];
            for (size_t i = 1; i < expectedNames.size(); ++i) {
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

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // ---- Input File ----
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
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
    if (!parserLogFile.is_open()) {
        cerr << "Error opening parser log file: " << parserLogFileName << endl;
        return 1;
    }

    errorFile.open(errorFileName);
    if (!errorFile.is_open()) {
        cerr << "Error opening error log file: " << errorFileName << endl;
        return 1;
    }

    lexLogFile.open(lexLogFileName);
    if (!lexLogFile.is_open()) {
        cerr << "Error opening lexer log file: " << lexLogFileName << endl;
        return 1;
    }

    // ---- Parsing Flow ----
    ANTLRInputStream input(inputFile);
    C8086Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    C8086Parser parser(&tokens);

    int numberOfBuckets = 7;
    symbolTable = new SymbolTable(numberOfBuckets, Hash::SDBMHash, parserLogFile);
    // this is necessary to avoid the default error listener and use our custom error handling
    parser.removeErrorListeners();
    lexer.removeErrorListeners();
    // parser.addErrorListener(new CustomErrorListener());


    // start parsing at the 'start' rule
    parser.start();

    // clean up
    delete symbolTable;
    inputFile.close();
    parserLogFile.close();
    errorFile.close();
    lexLogFile.close();
    cout << "Parsing completed. Check the output files for details." << endl;
    return 0;
}
