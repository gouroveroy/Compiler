%option noyywrap

%x STRING_TOKENIZER
%x CONST_CHAR_TOKENIZER
%x SLASH_COMMENT_TOKENIZER
%x STAR_COMMENT_TOKENIZER

%{

#include <bits/stdc++.h>
#include "SymbolTable/2105017_symbol_table.cpp"

using namespace std;

int lineCount = 1;
int errorCount = 0;

string currentCharacter = "";
string currentConvertedCharacter = "";

string currentString = "";
string currentConvertedString = "";

string currentSlashComment = "";

string currentStarComment = "";

ofstream tokenFile("2105017_token.txt");
ofstream logFile("2105017_log.txt");

int numberOfBuckets = 7;

SymbolTable symbolTable(numberOfBuckets, Hash::SDBMHash, logFile);

class LexicalAnalyzer
{
    string token;
    string lexeme;

public:
    LexicalAnalyzer(string token, string lexeme)
    {
        this->token = token;
        this->lexeme = lexeme;
    }

    string getToken()
    {
        return token;
    }

    string getLexeme()
    {
        return lexeme;
    }

    void setToken(string token)
    {
        this->token = token;
    }

    void setLexeme(string lexeme)
    {
        this->lexeme = lexeme;
    }

    string toString()
    {
        return "<" + token + ", " + lexeme + "> ";
    }
};

void writeToTokenFile(LexicalAnalyzer &lexicalAnalyzer)
{
    tokenFile << lexicalAnalyzer.toString();
}

void writeToLogFile(LexicalAnalyzer &lexicalAnalyzer)
{
    string token = lexicalAnalyzer.getToken();
    string lexeme = lexicalAnalyzer.getLexeme();
    logFile << "Line no " << lineCount << ": Token <" << token << "> Lexeme " << lexeme << " found" << endl
            << endl;
}

void handleKeywordLexeme(string text)
{
    string token = text;
    transform(token.begin(), token.end(), token.begin(), ::toupper);

    tokenFile << "<" << token << "> ";
    logFile << "Line no " << lineCount << ": Token <" << token << "> Lexeme " << text << " found" << endl
            << endl;
}

void handleTokenLexeme(LexicalAnalyzer &lexicalAnalyzer)
{
    string token = lexicalAnalyzer.getToken();
    string lexeme = lexicalAnalyzer.getLexeme();

    writeToTokenFile(lexicalAnalyzer);
    writeToLogFile(lexicalAnalyzer);

    if (token == "LCURL")
    {
        symbolTable.enterScope();
    }
    else if (token == "RCURL")
    {
        symbolTable.exitScope();
    }
    else if (token == "ID" or token == "CONST_INT" or token == "CONST_FLOAT")
    {
        bool inserted = symbolTable.Insert(lexeme, token);
        if (inserted)
        {
            symbolTable.PrintAllScopeTable();
        }
    }
}

void handleError(string errorMessage)
{
    errorCount++;

    int newlineCount = 0;

    if (errorMessage.find("string") != string::npos)
    {
        newlineCount += count(errorMessage.begin(), errorMessage.end(), '\n');
    }
    else if (errorMessage.find("comment") != string::npos)
    {
        newlineCount += count(errorMessage.begin(), errorMessage.end(), '\n');
    }

    logFile << "Error at line no " << lineCount - newlineCount << ": " << errorMessage << endl
            << endl;
}

char getSpecialCharAscii(string text)
{
    char ascii;
    char specialChar = text[2];

    switch (specialChar)
    {
        case '0':
        ascii = '\0';
        break;
        case 'v':
        ascii = '\v';
        break;
        case 'b':
        ascii = '\b';
        break;
        case 'r':
        ascii = '\r';
        break;
        case 'f':
        ascii = '\f';
        break;
        case 'a':
        ascii = '\a';
        break;
        case '\'':
        ascii = '\'';
        break;
        case '\\':
        ascii = '\\';
        break;
        case 't':
        ascii = '\t';
        break;
        case 'n':
        ascii = '\n';
        break;
        case '\"':
        ascii = '\"';
        break;
        default:
        ascii = text[1];
        break;
    }
    return ascii;
}

void handleCharLexeme()
{
    string token = "CONST_CHAR";
    string lexeme = currentCharacter;

    char ascii;
    if (currentCharacter.length() >= 4 && currentCharacter[1] == '\\')
    {
        ascii = getSpecialCharAscii(currentCharacter);
    }
    else if (currentCharacter.length() >= 3)
    {
        ascii = currentCharacter[1];
    }
    else
    {
        handleError("Empty character constant error " + currentCharacter + "\n");
        return;
    }

    tokenFile << "<" << token << ", " << ascii << "> ";

    logFile << "Line no " << lineCount << ": Token <" << token
            << "> Lexeme " << lexeme << " found --> <"
            << token << ", " << ascii << ">" << endl
            << endl;

    bool inserted = symbolTable.Insert(lexeme, token);
    if (inserted)
    {
        symbolTable.PrintAllScopeTable();
    }
}

void handleStringLexeme()
{
    string token = "STRING";

    tokenFile << "<" << token << ", " << currentConvertedString << "> ";
    logFile << "Line no " << lineCount << ": Token <" << token << "> Lexeme " << currentString << " found --> <" << token << ", " << currentConvertedString << ">" << endl
            << endl;
}

void handleCurrentSlashComment()
{
    string token = "COMMENT";
    string lexeme = currentSlashComment;

    logFile << "Line no " << lineCount << ": Token <" << token << "> Lexeme " << lexeme << " found" << endl
            << endl;
}

void handleCurrentStarComment()
{
    string token = "COMMENT";
    string lexeme = currentStarComment;

    logFile << "Line no " << lineCount << ": Token <" << token << "> Lexeme " << lexeme << " found" << endl
            << endl;
}

%}

KEYWORD                     "if"|"for"|"do"|"int"|"float"|"void"|"switch"|"default"|"else"|"while"|"break"|"char"|"double"|"return"|"case"|"continue"|"goto"|"long"|"short"|"static"|"unsigned"
ADDOP                       "+"|"-"
MULOP                       "*"|"/"|"%"
INCOP                       "++"|"--"
RELOP                       "<"|"<="|">"|">="|"!="|"=="
ASSIGNOP                    "="
LOGICOP                     "&&"|"||"
BITOP                       "&"|"|"|"^"
NOT                         "!"
LPAREN                      "("
RPAREN                      ")"
LCURL                       "{"
RCURL                       "}"
LTHIRD                      "["
RTHIRD                      "]"
COMMA                       ","
SEMICOLON                   ";"

WHITESPACE                  [ \t\v\r\f]
ALPHABET                    [A-Za-z]
DIGIT                       [0-9]
ALPHANUMERIC                ({ALPHABET}|{DIGIT})
CONST_INT                   {DIGIT}+
DECIMAL_POINT               \.{DIGIT}+
EXPONENT                    [Ee]{ADDOP}?{DIGIT}+
CONST_FLOAT                 ({DIGIT}+|{DIGIT}*{DECIMAL_POINT}){EXPONENT}?
MULTI_DECIMAL               {DIGIT}*(\.{DIGIT}*){2,}{EXPONENT}?
FRACTIONAL_EXPONENT         [E]{ADDOP}?{DIGIT}*{DECIMAL_POINT}
ILL_FORM                    ({DIGIT}+|{DIGIT}*{DECIMAL_POINT}){FRACTIONAL_EXPONENT}?
IDENTIFIER                  ({ALPHABET}|"_")({ALPHANUMERIC}|"_")*
INVALID_SUFFIX_NUMERIC      ({DIGIT}+|{DIGIT}*{DECIMAL_POINT}){EXPONENT}?{IDENTIFIER}
BACKSLASH                   "\\"
SINGLE_QUOTE                "\'"
DOUBLE_QUOTE                "\""
SPECIAL_CHAR                "\\n|\\t|\\\\|\\'|\\a|\\f|\\r|\\b|\\v|\\0"
NON_BACKSLASH               [^\\\n\"]
NEWLINE                     (\r\n|\n)
MULTI_CHAR_LITERAL          \'({NON_BACKSLASH}|{SPECIAL_CHAR}){2,}\'

%%
{WHITESPACE}               {
                                // Ignore whitespace
                           }

{NEWLINE}                  {
                                lineCount++;
                           }

{KEYWORD}                  {
                                handleKeywordLexeme(yytext);
                           }

{ADDOP}                    {
                                LexicalAnalyzer lexicalAnalyzer("ADDOP", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{MULOP}                    {
                                LexicalAnalyzer lexicalAnalyzer("MULOP", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{INCOP}                    {
                                LexicalAnalyzer lexicalAnalyzer("INCOP", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{RELOP}                    {
                                LexicalAnalyzer lexicalAnalyzer("RELOP", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{ASSIGNOP}                 {
                                LexicalAnalyzer lexicalAnalyzer("ASSIGNOP", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{LOGICOP}                  {
                                LexicalAnalyzer lexicalAnalyzer("LOGICOP", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{BITOP}                    {
                                LexicalAnalyzer lexicalAnalyzer("BITOP", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{NOT}                      {
                                LexicalAnalyzer lexicalAnalyzer("NOT", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{LPAREN}                   {
                                LexicalAnalyzer lexicalAnalyzer("LPAREN", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{RPAREN}                   {
                                LexicalAnalyzer lexicalAnalyzer("RPAREN", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{LCURL}                    {
                                LexicalAnalyzer lexicalAnalyzer("LCURL", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{RCURL}                    {
                                LexicalAnalyzer lexicalAnalyzer("RCURL", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{LTHIRD}                   {
                                LexicalAnalyzer lexicalAnalyzer("LTHIRD", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{RTHIRD}                   {
                                LexicalAnalyzer lexicalAnalyzer("RTHIRD", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{COMMA}                    {
                                LexicalAnalyzer lexicalAnalyzer("COMMA", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{SEMICOLON}                {
                                LexicalAnalyzer lexicalAnalyzer("SEMICOLON", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{CONST_INT}                {
                                LexicalAnalyzer lexicalAnalyzer("CONST_INT", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{CONST_FLOAT}              {
                                LexicalAnalyzer lexicalAnalyzer("CONST_FLOAT", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{MULTI_DECIMAL}            {
                                handleError("Too many decimal points " + string(yytext) + "\n");
                           }

{ILL_FORM}                 {
                                handleError("Ill formed number " + string(yytext) + "\n");
                           }

{IDENTIFIER}               {
                                LexicalAnalyzer lexicalAnalyzer("ID", yytext);
                                handleTokenLexeme(lexicalAnalyzer);
                           }

{INVALID_SUFFIX_NUMERIC}   {
                                handleError("Invalid prefix on ID or invalid suffix on Number " + string(yytext));
                           }

{MULTI_CHAR_LITERAL}       {
                                handleError("Multi character constant error " + string(yytext) + "\n");
                           }

{SINGLE_QUOTE}             {
                                BEGIN(CONST_CHAR_TOKENIZER);
                                currentCharacter = yytext;
                                currentConvertedCharacter = "";
                           }

<CONST_CHAR_TOKENIZER>{
    {SINGLE_QUOTE}          {
                                currentCharacter += yytext;
                                handleCharLexeme();
                                BEGIN(INITIAL);
                            }

    {NEWLINE}               {
                                handleError("Unterminated character " + currentCharacter + "\n");
                                lineCount++;
                                BEGIN(INITIAL);
                            }

    <<EOF>>                 {
                                handleError("Unterminated character " + currentCharacter);
                                BEGIN(INITIAL);
                            }

    \\[nrt0'"\\]            {
                                currentCharacter += yytext;
                                currentConvertedCharacter += getSpecialCharAscii(yytext);
                            }

    \\[^nrt0'"\\]           {
                                currentCharacter += yytext;
                                currentConvertedCharacter += getSpecialCharAscii(yytext);
                            }

    .                       {
                                currentCharacter += yytext;
                                currentConvertedCharacter += yytext;
                            }
}

{DOUBLE_QUOTE}             {
                                BEGIN(STRING_TOKENIZER);
                                currentString = yytext;
                                currentConvertedString = "";
                           }

<STRING_TOKENIZER>{
    {BACKSLASH}{DOUBLE_QUOTE} {
                                currentString += yytext;
                                currentConvertedString += getSpecialCharAscii(yytext);
                           }

    {DOUBLE_QUOTE}         {
                                currentString += yytext;
                                handleStringLexeme();
                                BEGIN(INITIAL);
                           }

    {BACKSLASH}{NEWLINE}   {
                                lineCount++;
                                currentString += yytext;
                           }

    {NEWLINE}              {
                                handleError("Unterminated string " + currentString);
                                lineCount++;
                                BEGIN(INITIAL);
                           }

    <<EOF>>                {
                                handleError("Unterminated string " + currentString);
                                BEGIN(INITIAL);
                           }

    .                      {
                                currentString += yytext;
                                currentConvertedString += yytext;
                           }
}

\/\/                       {
                                BEGIN(SLASH_COMMENT_TOKENIZER);
                                currentSlashComment = yytext;
                           }

<SLASH_COMMENT_TOKENIZER>{
    {BACKSLASH}{NEWLINE}   {
                                currentSlashComment += yytext;
                                lineCount++;
                           }

    {NEWLINE}              {
                                handleCurrentSlashComment();
                                lineCount++;
                                BEGIN(INITIAL);
                           }

    <<EOF>>                {
                                handleCurrentSlashComment();
                                BEGIN(INITIAL);
                           }

    .                      {
                                currentSlashComment += yytext;
                           }
}

\/\*                       {
                                BEGIN(STAR_COMMENT_TOKENIZER);
                                currentStarComment = yytext;
                           }

<STAR_COMMENT_TOKENIZER>{
    \*\/                   {
                                currentStarComment += yytext;
                                handleCurrentStarComment();
                                BEGIN(INITIAL);
                           }

    {NEWLINE}              {
                                currentStarComment += yytext;
                                lineCount++;
                           }

    <<EOF>>                {
                                handleError("Unterminated comment " + currentStarComment);
                                BEGIN(INITIAL);
                           }

    .                      {
                                currentStarComment += yytext;
                           }
}

.                          {
                                handleError("Unrecognized character " + string(yytext));
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

    symbolTable.PrintAllScopeTable();
    logFile << "Total lines: " << lineCount << endl;
    logFile << "Total errors: " << errorCount << endl;

    fclose(file);
    tokenFile.close();
    logFile.close();

    cout << "Lexical analysis completed. Check 2105017_token.txt and 2105017_log.txt for results." << endl;

    return 0;
}
