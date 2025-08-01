%option noyywrap

%x VECTOR_TOKENIZER

%{
    #include <bits/stdc++.h>
    using namespace std;

    ofstream tokenFile("2105017_token.txt");
    ofstream logFile("2105017_log.txt");

    int lineCount = 1;
    string vector_text;

    void handleTokenLexeme(const string &token, const string &lexeme) {
        tokenFile << "<" + token + ", " + lexeme + "> " << endl;
        logFile << "Line No. " << lineCount << ": Token <" + token + "> Lexeme " + lexeme + " found" << endl;
    }

    void handleError() {
        logFile << "Line No. " << lineCount << ": " << "Invalid input" << endl;
    }

%}

KEYWORD    "int"|"float"|"double"|"char"
LANG    "<"
RANG    ">"
WHITESPACE                  [ \t\v\r\f]
NEWLINE                     (\r\n|\n)
VECTOR    "vector"

%%

{WHITESPACE}+   { /* Ignore whitespace */ }

{NEWLINE}              {
    lineCount++;
}

{VECTOR}{WHITESPACE}*{LANG}    {
    BEGIN(VECTOR_TOKENIZER);
    vector_text = yytext;
}

<VECTOR_TOKENIZER>{
    {WHITESPACE}*    {
        // Ignore whitespace within vector declaration
    }

    {VECTOR}{WHITESPACE}*{LANG}        {
        vector_text += yytext;
    }

    {RANG}          {
        vector_text += yytext;
        for (int i = vector_text.size() - 2; i >= 0; i--) {
            if (vector_text[i] == ' ') {
                continue; // Ignore trailing spaces before the closing angle bracket
            }
            if (isalpha(vector_text[i])) {
                // If we find a valid character before the last '>', it means this is a complete vector type
                break;
            }
            if (vector_text[i] == '<') {
                // If we find a '<' before the last '>', it means this is not a complete vector type
                handleError();
                vector_text = "";
                BEGIN(INITIAL);
                return 0;
            }
        }
        // Check if this closes all the angle brackets
        int open_count = 0;
        int close_count = 0;
        for (char c : vector_text) {
            if (c == '<') open_count++;
            if (c == '>') close_count++;
        }

        if (open_count == close_count) {
            handleTokenLexeme("VECTOR_TYPE", vector_text);
            vector_text = "";
            BEGIN(INITIAL);
        }
    }

    {KEYWORD}       {
        vector_text += yytext;
    }

    {NEWLINE}       {
        lineCount++;
        handleError();
        vector_text = "";
        BEGIN(INITIAL);
    }

    <<EOF>>       {
        handleError();
        vector_text = "";
        BEGIN(INITIAL);
    }

    .               {
        vector_text += yytext;
        handleError();
        vector_text = "";
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
