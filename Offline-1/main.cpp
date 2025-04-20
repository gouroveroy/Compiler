#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "SymbolTable.cpp"

using namespace std;

string paramMismatchError(string s)
{
    return "\tNumber of parameters mismatch for the command " + s;
}

void trimLine(string &line)
{
    line.erase(0, line.find_first_not_of(" \n\r\t"));
    line.erase(line.find_last_not_of(" \n\r\t") + 1);
}

bool checkParamMismatch(const string &command, int expectedCount, int actualCount)
{
    if (expectedCount != actualCount)
    {
        cout << paramMismatchError(command) << endl;
        return true;
    }
    return false;
}

string functionSymbolType(string s[], int size)
{
    string type = s[1] + "," + s[2] + "<==(";
    for (int i = 3; i < size; i++)
    {
        if (i != 3)
        {
            type += ",";
        }
        type += s[i];
    }
    type += ")";
    return type;
}

string structOrUnionSymbolType(string s[], int size)
{
    string type = s[1] + "," + "{";
    for (int i = 2; i < size; i += 2)
    {
        if (i != 2)
        {
            type += ",";
        }
        type += "(";
        type += s[i] + "," + s[i + 1];
        type += ")";
    }
    type += "}";
    return type;
}

int main()
{
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";
    FILE *fin = freopen(inputFileName.c_str(), "r", stdin);
    FILE *fout = freopen(outputFileName.c_str(), "w", stdout);
    if (!fin || !fout)
    {
        cout << "Error opening input or output file." << endl;
        return 0;
    }

    int numberOfBuckets;

    cin >> numberOfBuckets;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the newline character after the number of buckets

    SymbolTable symbolTable(numberOfBuckets);
    string line;
    int commandCount = 0;

    while (getline(cin, line))
    {
        if (line.empty())
        {
            {
                continue;
            } // skip empty lines
        }
        trimLine(line);
        stringstream ss(line);
        string command;
        ss >> command;
        commandCount++;

        string word;
        int wordCount = 0;
        while (ss >> word)
        {
            wordCount++;
        }

        string arguments[wordCount];
        int parameterCount = 0;
        ss.clear();
        ss.str(line);
        ss.seekg(0);

        ss >> word;
        while (ss >> word)
        {
            arguments[parameterCount++] = word;
        }

        cout << "Cmd " << commandCount << ": " << line << endl;

        if (command == "I")
        {
            if (parameterCount < 2)
            {
                cout << paramMismatchError(command) << endl;
                {
                    continue;
                }
            }

            if (arguments[1] == "FUNCTION")
            {
                if (parameterCount < 3)
                {
                    cout << paramMismatchError(command) << endl;
                    {
                        continue;
                    }
                }

                string symbolName = arguments[0];
                string symbolType = functionSymbolType(arguments, parameterCount);
                symbolTable.Insert(symbolName, symbolType);
            }
            else if (arguments[1] == "STRUCT" || arguments[1] == "UNION")
            {
                if (parameterCount % 2)
                {
                    cout << paramMismatchError(command) << endl;
                    {
                        continue;
                    }
                }

                string symbolName = arguments[0];
                string symbolType = structOrUnionSymbolType(arguments, parameterCount);
                symbolTable.Insert(symbolName, symbolType);
            }
            else
            {
                if (checkParamMismatch(command, 2, parameterCount))
                {
                    continue;
                }

                string symbolName = arguments[0];
                string symbolType = arguments[1];
                symbolTable.Insert(symbolName, symbolType);
            }
        }

        else if (command == "L")
        {
            if (checkParamMismatch(command, 1, parameterCount))
            {
                continue;
            }
            string symbolName = arguments[0];
            shared_ptr<SymbolInfo> symbol = symbolTable.LookUp(symbolName);
        }

        else if (command == "D")
        {
            if (checkParamMismatch(command, 1, parameterCount))
            {
                continue;
            }
            string symbolName = arguments[0];
            symbolTable.Remove(symbolName);
        }

        else if (command == "P")
        {
            if (checkParamMismatch(command, 1, parameterCount))
            {
                continue;
            }
            string scopeType = arguments[0];
            if (scopeType == "C")
            {
                symbolTable.PrintCurrentScopeTable();
            }
            else if (scopeType == "A")
            {
                symbolTable.PrintAllScopeTable();
            }
            else
            {
                cout << "Invalid argument for command " << command << endl;
            }
        }

        else if (command == "S")
        {
            if (checkParamMismatch(command, 0, parameterCount))
            {
                continue;
            }
            symbolTable.enterScope();
        }

        else if (command == "E")
        {
            if (checkParamMismatch(command, 0, parameterCount))
            {
                continue;
            }
            if (symbolTable.getCurrentScope()->getScopeId() == 1)
            {
                cout << "\tCannot exit the root scope table" << endl;
                {
                    continue;
                }
            }
            symbolTable.exitScope();
        }

        else if (command == "Q")
        {
            if (checkParamMismatch(command, 0, parameterCount))
            {
                continue;
            }
            while (symbolTable.getCurrentScope()->getParentScope() != nullptr)
            {
                symbolTable.exitScope();
            }
            symbolTable.exitScope();
            break;
        }

        else
        {
            cout << "Invalid command" << endl;
        }
    }
}
