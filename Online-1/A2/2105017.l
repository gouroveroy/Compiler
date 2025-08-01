%option noyywrap

%x JSON_TOKENIZER

%{
    #include <bits/stdc++.h>
    using namespace std;

    ofstream tokenFile("2105017_token.txt");
    ofstream logFile("2105017_log.txt");

    int braceCount = 0;
    bool validJson = true;
    bool foundValidPair = false;

    void handleError(const string &message) {
        logFile << "Error: " << message << endl;
        validJson = false;
    }

%}

LCURL                       "{"
RCURL                       "}"
COLON                       ":"
COMMA                       ","
WHITESPACE                  [ \t\v\r\f]
ALPHABET                    [A-Za-z]
DIGIT                       [0-9]
STRING                      ({ALPHABET}|{DIGIT})+|({DIGIT}|{ALPHABET})+
DOUBLE_QUOTE                "\""
STRING_LITERAL              {DOUBLE_QUOTE}{WHITESPACE}*{STRING}{WHITESPACE}*{DOUBLE_QUOTE}{WHITESPACE}*
NEWLINE                     (\r\n|\n)

%%

{LCURL}    {
    BEGIN(JSON_TOKENIZER);
    braceCount++;
}

<JSON_TOKENIZER>{
    {WHITESPACE}+    { /* Ignore whitespace */ }

    {NEWLINE}        {
        // Handle new line
    }

    {STRING_LITERAL}{COLON}{WHITESPACE}*{STRING_LITERAL}{COMMA}?    {
        foundValidPair = true;
    }

    {STRING_LITERAL}{COLON}{WHITESPACE}*{LCURL}    {
        braceCount++;
        foundValidPair = true;
    }

    {DOUBLE_QUOTE}{STRING}    {
        handleError("must be a quoted string");
        BEGIN(INITIAL);
        return 0;
    }

    {STRING}{DOUBLE_QUOTE}    {
        handleError("must be a quoted string");
        BEGIN(INITIAL);
    }

    {STRING_LITERAL}{WHITESPACE}*{STRING_LITERAL}{COMMA}?    {
        handleError("Missing separator");
        BEGIN(INITIAL);
    }

    {RCURL}    {
        braceCount--;
        if (braceCount == 0) {
            if (foundValidPair and validJson) {
                logFile << "Valid JSON Structure" << endl;
            }
            BEGIN(INITIAL);
        }
    }

    <<EOF>>    {
        handleError("unmatched {");
        BEGIN(INITIAL);
    }

    .               {
        handleError("Invalid input");
        BEGIN(INITIAL);
    }
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
