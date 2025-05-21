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
        return "<" + token + ", " + lexeme + ">";
    }
};

void writeToTokenFile(LexicalAnalyzer &lexicalAnalyzer)
{
    tokenFile << lexicalAnalyzer.toString() << endl;
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

    tokenFile << "<" << token << ">" << endl;
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

    tokenFile << "<" << token << ", " << ascii << ">" << endl;

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

    tokenFile << "<" << token << ", " << currentConvertedString << ">" << endl;
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

void handleCurrentCharacter(string text)
{
    string token = "CONST_CHAR";
    char ascii;
    string lexeme = text;

    if (text.length() >= 4 && text[1] == '\\')
    {
        ascii = getSpecialCharAscii(text);
    }
    else if (text.length() >= 3)
    {
        ascii = text[1];
    }
    else
    {
        handleError("INVALID CHAR LITERAL " + text);
        return;
    }

    tokenFile << "<" << token << ", " << ascii << ">" << endl;

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

void handleSingleLineString(string text)
{
    string token = "STRING";
    string lexeme = text;

    tokenFile << "<" << token << ", " << lexeme << ">" << endl;
    logFile << "Line no " << lineCount << ": Token <" << token
            << "> Lexeme " << lexeme << " found --> <"
            << token << ", " << lexeme.substr(1, lexeme.size() - 2) << ">" << endl
            << endl;
}

void handleMultiLineString(string text)
{
    string token = "STRING";
    string lexeme = text;
    string temp = lexeme.substr(1, lexeme.size() - 2);

    temp.erase(remove(temp.begin(), temp.end(), '\\'), temp.end());
    temp.erase(remove_if(temp.begin(), temp.end(), [](char c)
                         { return c == '\n' || c == '\r'; }),
               temp.end());

    int newlines = count(lexeme.begin(), lexeme.end(), '\n');

    tokenFile << "<" << token << ", " << lexeme << ">" << endl;
    logFile << "Line no " << lineCount + newlines << ": Token <" << token
            << "> Lexeme " << lexeme << " found --> <"
            << token << ", " << temp << ">" << endl
            << endl;

    lineCount += newlines;
}

void handleSingleLineComment(string text)
{
    string token = "COMMENT";
    string lexeme = text;
    string temp = lexeme;

    temp.erase(remove(temp.begin(), temp.end(), '\\'), temp.end());
    temp.erase(remove_if(temp.begin(), temp.end(), [](char c)
                         { return c == '\n' || c == '\r'; }),
               temp.end());

    int newlines = count(lexeme.begin(), lexeme.end(), '\n');

    logFile << "Line no " << lineCount << ": Token <" << token << "> Lexeme " << lexeme << " found" << endl
            << endl;

    lineCount += newlines;
}

void handleMultiLineComment(string text)
{
    string token = "COMMENT";
    string lexeme = text;

    lineCount += count(lexeme.begin(), lexeme.end(), '\n');

    logFile << "Line no " << lineCount << ": Token <" << token << "> Lexeme " << lexeme << " found" << endl
            << endl;
}

// CONST_CHAR                  "'"({NON_BACKSLASH}|{SPECIAL_CHAR})"'"
// SINGLE_LINE_STRING          \"({NON_BACKSLASH}|{SPECIAL_CHAR})*\"
// MULTI_LINE_STRING           \"([^"\\]|\\.|\\\n)*\"
// SINGLE_LINE_COMMENT         "//"([^\\\n]|\\.)*(\\\n([^\\\n]|\\.)*)*
// MULTI_LINE_COMMENT          "/*"([^*]|[*][^*/\n]|[\\][\n])*[*]+"/"

/*
{CONST_CHAR}               {
    handleCharLexeme(yytext);
    }

    {SINGLE_LINE_STRING}       {
        handleSingleLineString(yytext);
        }

        {MULTI_LINE_STRING}        {
            handleMultiLineString(yytext);
            }

            {SINGLE_LINE_COMMENT}      {
                handleSingleLineComment(yytext);
                }

                {MULTI_LINE_COMMENT}       {
                    handleMultiLineComment(yytext);
                    }
                    */