lexer grammar C2105017Lexer;

@lexer::header {
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    extern ofstream lexLogFile;
    extern ofstream errorFile;
}

@lexer::members {
    void writeIntoLexLogFile(const string &message) {
        if (!lexLogFile.is_open()) {
            lexLogFile.open("lexLogFile.txt", ios::app);
            if (!lexLogFile) {
                cerr << "Error opening lexLogFile.txt" << endl;
                return;
            }
        }
        lexLogFile << message << endl;
    }
    int lineCount = 1;
}

// ------------------------------
// 1) Keywords
// ------------------------------

IF       : 'if'       { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <IF> Lexeme " + getText()); }
         ;

ELSE     : 'else'     { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ELSE> Lexeme " + getText()); }
         ;

FOR      : 'for'      { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <FOR> Lexeme " + getText()); }
         ;

WHILE    : 'while'    { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <WHILE> Lexeme " + getText()); }
         ;

DO       : 'do'       { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DO> Lexeme " + getText()); }
         ;

SWITCH   : 'switch'   { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <SWITCH> Lexeme " + getText()); }
         ;

CASE     : 'case'     { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CASE> Lexeme " + getText()); }
         ;

DEFAULT  : 'default'  { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DEFAULT> Lexeme " + getText()); }
         ;

BREAK    : 'break'    { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <BREAK> Lexeme " + getText()); }
         ;

CONTINUE : 'continue' { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONTINUE> Lexeme " + getText()); }
         ;

RETURN   : 'return'   { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RETURN> Lexeme " + getText()); }
         ;

PRINTLN  : 'println'  { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <PRINTLN> Lexeme " + getText()); }
         ;

INT      : 'int'      { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <INT> Lexeme " + getText()); }
         ;

FLOAT    : 'float'    { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <FLOAT> Lexeme " + getText()); }
         ;

CHAR     : 'char'     { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CHAR> Lexeme " + getText()); }
         ;

DOUBLE   : 'double'   { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DOUBLE> Lexeme " + getText()); }
         ;

VOID     : 'void'     { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <VOID> Lexeme " + getText()); }
         ;

LONG     : 'long'     { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LONG> Lexeme " + getText()); }
         ;

SHORT    : 'short'    { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <SHORT> Lexeme " + getText()); }
         ;

STATIC   : 'static'   { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <STATIC> Lexeme " + getText()); }
         ;

UNSIGNED : 'unsigned' { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <UNSIGNED> Lexeme " + getText()); }
         ;

GOTO     : 'goto'     { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <GOTO> Lexeme " + getText()); }
         ;

// ------------------------------
// 2) Operators & Punctuation
// ------------------------------

ADDOP     : '+' | '-'  { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ADDOP> Lexeme " + getText()); }
          ;

MULOP     : '*' | '/' | '%'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <MULOP> Lexeme " + getText()); }
          ;

INCOP     : '++'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <INCOP> Lexeme " + getText()); }
          ;

DECOP     : '--'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DECOP> Lexeme " + getText()); }
          ;

RELOP     : '<=' | '>=' | '==' | '!=' | '<' | '>'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RELOP> Lexeme " + getText()); }
          ;

LOGICOP   : '&&' | '||'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LOGICOP> Lexeme " + getText()); }
          ;

ASSIGNOP  : '='
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ASSIGNOP> Lexeme " + getText()); }
          ;

BITOP     : '&' | '|' | '^'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <BITOP> Lexeme " + getText()); }
          ;

NOT       : '!'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <NOT> Lexeme " + getText()); }
          ;

LPAREN    : '('
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LPAREN> Lexeme " + getText()); }
          ;

RPAREN    : ')'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RPAREN> Lexeme " + getText()); }
          ;

LCURL     : '{'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LCURL> Lexeme " + getText()); }
          ;

RCURL     : '}'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RCURL> Lexeme " + getText()); }
          ;

LTHIRD    : '['
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LTHIRD> Lexeme " + getText()); }
          ;

RTHIRD    : ']'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RTHIRD> Lexeme " + getText()); }
          ;

COMMA     : ','
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <COMMA> Lexeme " + getText()); }
          ;

SEMICOLON : ';'
          { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <SEMICOLON> Lexeme " + getText()); }
          ;

// ------------------------------
// 3) Identifiers & Numbers
// ------------------------------

ID
    : [A-Za-z_] [A-Za-z0-9_]*
      { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ID> Lexeme " + getText()); }
    ;

// well‐formed integer
CONST_INT
    : [0-9]+
      { writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONST_INT> Lexeme " + getText()); }
    ;

// well‐formed float
CONST_FLOAT
    : [0-9]* '.' [0-9]+ ([Ee][+\-]?[0-9]+)?
    | [0-9]+ ([Ee][+\-]?[0-9]+)
    {
        writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONST_FLOAT> Lexeme " + getText());
    }
    ;

HASH
    : '#'
    ;

// errors on malformed numerics
// MULTI_DECIMAL
//     : [0-9]* ('.' [0-9]*){2,} ([Ee][+\-]?[0-9]+)?
//     {
//         notifyErrorListeners("Too many decimal points");
//     }
//     ;

// ILL_FORM
//     : [0-9]* '.' [0-9]* [Ee][+\-]? [0-9]* '.' [0-9]*
//     {
//         notifyErrorListeners("Ill formed number");
//     }
//     ;

// INVALID_SUFFIX_NUMERIC
//     : [0-9]+ [A-Za-z_] [A-Za-z0-9_]*
//     {
//         notifyErrorListeners("Invalid suffix on number");
//     }
//     ;

// MULTI_CHAR_LITERAL
//     : '\'' .+? '\''
//     {
//         notifyErrorListeners("Multi character constant error");
//     }
//     ;

// ------------------------------
// 4) Character constants & strings
// ------------------------------

SINGLE_QUOTE
    : '\'' -> pushMode(CHAR_MODE)
    ;

mode CHAR_MODE;
// empty char literal: ''
    CHAR_EMPTY
        : '\''
          {
            // notifyErrorListeners("Empty character constant");
          }
        -> popMode
        ;
    // closing properly
    CHAR_CLOSE
        : '\''
          {
            writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONST_CHAR> Lexeme " + getText());
          }
        -> popMode
        ;
    // escape sequences
    CHAR_ESCAPE
        : '\\' [nrt0'"\\abfv] -> more
        ;
    // backslash + newline
    CHAR_ESC_NL
        : '\\' '\r'? '\n'
          { lineCount++; }
        -> more
        ;
    // unterminated or stray newline
    CHAR_ERROR_NL
        : '\n'
          {
            // notifyErrorListeners("Unterminated character");
            lineCount++;
          }
        -> popMode
        ;
    // any other char
    CHAR_ANY
        : . -> more
        ;

// string literals (allow backslash‐newline continuation)
DOUBLE_QUOTE
    : '"' -> pushMode(STRING_MODE)
    ;

mode STRING_MODE;
    STR_CLOSE
        : '"'
          {
            writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <STRING> Lexeme " + getText());
          }
        -> popMode
        ;
    STR_ESCAPE
        : '\\' [nrt0'"\\abfv] -> more
        ;
    STR_ESC_NL
        : '\\' '\r'? '\n'
          { lineCount++; }
        -> more
        ;
    STR_NL_ERROR
        : '\n'
          {
            // notifyErrorListeners("Unterminated string");
            lineCount++;
          }
        -> popMode
        ;
    STR_ANY
        : ~["\\\r\n]+ -> more
        ;

// ------------------------------
// 5) Comments (single‐line can continue with backslash)
// ------------------------------

LINE_COMMENT
    : '//' ( '\\' '\r'? '\n' { lineCount++; } | ~[\r\n] )*
      {
        writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LINE_COMMENT> Lexeme " + getText());
      }
      -> skip
    ;

BLOCK_COMMENT
    : '/*' ( . | '\r' | '\n' )*? '*/'
      {
        {
          // strip /* and */
          string body = getText().substr(2, getText().size()-4);
          writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <BLOCK_COMMENT> Lexeme /*" + body + "*/");
        }
      }
      -> skip
    ;

// ------------------------------
// 6) Whitespace & Newlines
// ------------------------------

WS
    : [ \t\f\r]+
      -> skip
    ;

NL
    : '\r'? '\n'
      { lineCount++; }
      -> skip
    ;

// ------------------------------
// 7) Anything else is an error
// ------------------------------

UNRECOGNIZED
    : .
    ;
