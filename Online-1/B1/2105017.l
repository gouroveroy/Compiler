%option noyywrap

%{
    #include <bits/stdc++.h>
    using namespace std;

    ofstream tokenFile("2105017_token.txt");
    ofstream logFile("2105017_log.txt");

    stack<char> braceStack;
    bool matched = true;

    void handleError(const string &message) {
        logFile << message << endl;
    }

%}

LPAREN                      "("
RPAREN                      ")"
LCURL                       "{"
RCURL                       "}"
LTHIRD                      "["
RTHIRD                      "]"
NEWLINE                     (\r\n|\n)
WHITESPACE                  [ \t\v\r\f]

%%

{WHITESPACE}+   { /* Ignore whitespace */ }

{NEWLINE}    {
    // Handle new line
}

{LPAREN}    {
    braceStack.push('(');
}

{RPAREN}    {
    if (!braceStack.empty() && braceStack.top() == '(') {
        braceStack.pop();
    } else {
        handleError("Unmatched brackets.");
        matched = false;
        return 0;
    }
}

{LCURL}    {
    braceStack.push('{');
}

{RCURL}    {
    if (!braceStack.empty() && braceStack.top() == '{') {
        braceStack.pop();
    } else {
        handleError("Unmatched brackets.");
        matched = false;
        return 0;
    }
}

{LTHIRD}    {
    braceStack.push('[');
}

{RTHIRD}    {
    if (!braceStack.empty() && braceStack.top() == '[') {
        braceStack.pop();
    } else {
        handleError("Unmatched brackets.");
        matched = false;
        return 0;
    }
}

<<EOF>>    {
    if (!braceStack.empty()) {
        handleError("Unmatched brackets.");
        matched = false;
        return 0;
    }
    if (matched) {
        logFile << "Brackets are matched." << endl;
    } else {
        logFile << "Unmatched brackets." << endl;
    }
    return 0;
}

%%

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // ./2105017.l <input_file>
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    FILE *file = fopen(inputFile.c_str(), "r");
    if (!file)
    {
        cout << "Error opening file: " << inputFile << endl;
        return 1;
    }

    yyin = file;

    yylex();

    fclose(file);
    tokenFile.close();
    logFile.close();

    cout << "Lexical analysis completed. Check 2105017_token.txt and 2105017_log.txt for results." << endl;

    return 0;
}
