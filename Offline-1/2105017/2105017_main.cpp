/*
    * open Command Prompt and run:
        g++ 2105017_main.cpp -o 2105017_main.exe
        2105017_main.exe sdbm < input.txt > output.txt

    * or open power shell and run:
        g++ 2105017_main.cpp -o 2105017_main.exe
        Get-Content input.txt | ./2105017_main.exe sdbm | Set-Content output.txt

    * or uncomment (if commented) the following lines to read from a file instead of standard input inside the main function:
        string inputFileName = "input.txt";
        string outputFileName = "output.txt";
        FILE *fin = freopen(inputFileName.c_str(), "r", stdin);
        FILE *fout = freopen(outputFileName.c_str(), "w", stdout);
        if (!fin || !fout)
        {
            cout << "Error opening input or output file." << endl;
            return 0;
        }

    * or run the following command in the Linux terminal:
        g++ 2105017_main.cpp 2105017_symbol_table.cpp 2105017_scope_table.cpp 2105017_symbol_info.cpp 2105017_Hash.cpp -o 2105017_main.exe -fsanitize=address
        ./2105017_main.exe sdbm < input.txt > output.txt
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include "2105017_symbol_table.cpp"

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

int main(int argc, char *argv[])
{
    function<unsigned int(string, unsigned int)> hashFunc = Hash::SDBMHash;

    if (argc > 1)
    {
        string hashType = argv[1];
        hashFunc = Hash::getHashFunction(hashType);
    }

    /*
        string inputFileName = "input.txt";
        string outputFileName = "output.txt";
        FILE *fin = freopen(inputFileName.c_str(), "r", stdin);
        FILE *fout = freopen(outputFileName.c_str(), "w", stdout);
        if (!fin || !fout)
        {
            cout << "Error opening input or output file." << endl;
            return 0;
        }
    */

    int numberOfBuckets;
    int collisions = 0;

    cin >> numberOfBuckets;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the newline character after the number of buckets

    SymbolTable symbolTable(numberOfBuckets, hashFunc);
    string line;
    int commandCount = 0;
    int hashTableCount = 0;

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
            collisions += symbolTable.getCurrentScope()->getTotalCollisions();
            symbolTable.exitScope();
            hashTableCount++;
        }

        else if (command == "Q")
        {
            if (checkParamMismatch(command, 0, parameterCount))
            {
                continue;
            }
            while (symbolTable.getCurrentScope()->getParentScope() != nullptr)
            {
                collisions += symbolTable.getCurrentScope()->getTotalCollisions();
                symbolTable.exitScope();
            }
            collisions += symbolTable.getCurrentScope()->getTotalCollisions();
            symbolTable.exitScope();
            break;
        }

        else
        {
            cout << "Invalid command" << endl;
        }
    }

    ofstream collisionOut("collision.txt");
    if (!collisionOut)
    {
        cerr << "Failed to open collision.txt" << endl;
    }
    else
    {
        collisionOut << "Total Collisions: " << collisions << endl;
        collisionOut << "Collision Ratio: " << 1.0 * collisions / (numberOfBuckets * hashTableCount) << endl;
        collisionOut.close();
    }

    return 0;
}
