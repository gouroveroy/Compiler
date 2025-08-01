parser grammar C8086Parser;

options {
    tokenVocab = C8086Lexer;
}

@parser::header {
    #include <iostream>
    #include <iomanip>
    #include <sstream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include "C8086Lexer.h"
    #include "SymbolTable/2105017_symbol_table.h"

    using namespace std;

    extern ofstream parserLogFile;
    extern ofstream errorFile;

    extern int syntaxErrorCount;
    extern SymbolTable *symbolTable;
}

@parser::members {
    // Flags and helpers for function/parameter context
    bool insertParams = false;
    bool isFunctionBlock = false;
    string currentDeclListText;
    string currentFunctionReturnType;
    string currentFunctionName;
    bool isExpressionStatement = false;

    // Logging helpers
    void writeIntoParserLogFile(const string message) {
        if (!parserLogFile) {
            cout << "Error opening parserLogFile.txt" << endl;
            return;
        }
        parserLogFile << message << endl;
        parserLogFile.flush();
    }

    void writeIntoErrorFile(const string message) {
        if (!errorFile) {
            cout << "Error opening errorFile.txt" << endl;
            return;
        }
        errorFile << message << endl;
        errorFile.flush();
        // Also write the same message to the parser log file
        if (parserLogFile) {
            parserLogFile << message << endl;
            parserLogFile.flush();
        }
        syntaxErrorCount++;
    }

    // Parameter type tracking for function info
    vector<string> currentParamTypes;
    void clearCurrentParamTypes() { currentParamTypes.clear(); }
    void addParamType(const string& type) { currentParamTypes.push_back(type); }
    // Map to track parameter types for each function by name (for signature checks)
    map<string, vector<string>> functionParamTypes;

    // Struct member tracking
    map<string, vector<pair<string, string>>> structMemberTable; // struct name -> vector of (type, name)
    string currentStructName;
}

// Entry point: parse the whole program
start : program
    {
        antlr4::Token* lastToken = _input->get(_input->size() - 1);
        int totalLines = lastToken->getLine();
        writeIntoParserLogFile("Line " + to_string(totalLines) + ": start : program\n");
        symbolTable->PrintAllScopeTable();
        writeIntoParserLogFile("Total number of lines: " + to_string(totalLines));
        writeIntoParserLogFile("Total number of errors: " + to_string(syntaxErrorCount));
    }
    ;

program returns [string text]
    : u=unit
    {
        $text = $u.text;
        writeIntoParserLogFile("Line " + to_string($u.stop->getLine()) + ": program : unit\n\n" + $text + "\n");
    }
    | p=program u=unit
    {
        $text = $p.text + "\n" + $u.text;
        writeIntoParserLogFile("Line " + to_string($u.stop->getLine()) + ": program : program unit\n\n" + $text + "\n");
    }
    ;


// Top-level units: variable declarations, function declarations, or function definitions
unit returns [string text, bool isStruct]
    : v=var_declaration
    {
        $text = $v.text;
        $isStruct = false;
        writeIntoParserLogFile("Line " + to_string($v.stop->getLine()) + ": unit : var_declaration\n\n" + $text + "\n");
    }
    | f=func_declaration
    {
        $text = $f.text;
        $isStruct = false;
        writeIntoParserLogFile("Line " + to_string($f.stop->getLine()) + ": unit : func_declaration\n\n" + $text + "\n");
    }
    | fd=func_definition
    {
        $text = $fd.text;
        $isStruct = false;
        writeIntoParserLogFile("Line " + to_string($fd.stop->getLine()) + ": unit : func_definition\n\n" + $text + "\n");
    }
    | s=struct_definition
    {
        $text = "struct " + $s.text;
        $isStruct = true;
        writeIntoParserLogFile("Line " + to_string($s.stop->getLine()) + ": unit : struct_definition\n\n" + $text + "\n");
    }
    ;


// Function declaration (with or without parameters)
func_declaration returns [string text]
    : t=type_specifier id=ID LPAREN RPAREN sm=SEMICOLON
    {
        // Insert function with no parameters
        $text = $t.text + " " + $id->getText() + "();";
        if (symbolTable->Insert($id->getText(), "ID")) {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDataType("function");
                sym->setFunctionInfo(make_shared<FunctionInfo>($t.text, nullptr, 0));
            }
        } else {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
        }
        writeIntoParserLogFile("Line " + to_string($sm->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n" + $text + "\n");
    }

    | t=type_specifier id=ID LPAREN
      {
        insertParams = false;
        clearCurrentParamTypes();
      }
      pl=parameter_list RPAREN sm=SEMICOLON
      {
        // Insert function with parameters after parameter list is parsed
        $text = $t.text + " " + $id->getText() + "(" + $pl.text + ");";
        if (symbolTable->Insert($id->getText(), "ID")) {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDataType("function");
                sym->setFunctionInfo(make_shared<FunctionInfo>(
                    $t.text,
                    currentParamTypes.empty() ? nullptr : currentParamTypes.data(),
                    currentParamTypes.size()
                ));
            }
        } else {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
        }
        // Store parameter types for this function name
        functionParamTypes[$id->getText()] = currentParamTypes;
        writeIntoParserLogFile("Line " + to_string($sm->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n" + $text + "\n");
      }
    ;


// Function definition (with or without parameters)
func_definition returns [string text]
    : t=type_specifier id=ID lp=LPAREN rp=RPAREN
      {
        // Insert function with no parameters
        if (symbolTable->Insert($id->getText(), "ID")) {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDataType("function");
                sym->setFunctionInfo(make_shared<FunctionInfo>($t.text, nullptr, 0));
            }
        } else {
            // Check for redeclaration or return type mismatch
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                auto funcInfo = sym->getFunctionInfo();
                if (funcInfo) {
                    if (funcInfo->getReturnType() != $t.text) {
                        writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Return type mismatch of " + $id->getText() + "\n");
                    }
                } else {
                    writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
                }
            }
        }
        symbolTable->enterScope();
        isFunctionBlock = true;
        insertParams = true;
        currentFunctionReturnType = $t.text;
        currentFunctionName = $id->getText();
      }
      cs=compound_statement
      {
        $text = $t.text + " " + $id->getText() + "()" + $cs.text;
        writeIntoParserLogFile("Line " + to_string($cs.stop->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" + $text + "\n");
        symbolTable->exitScope();
        isFunctionBlock = false;
        insertParams = false;
      }

    | t=type_specifier id=ID lp=LPAREN
      {
        // Insert function with parameters (parameters handled after parameter_list)
        if (symbolTable->Insert($id->getText(), "ID")) {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDataType("function");
                clearCurrentParamTypes();
            }
        } else {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                if (sym->getDataType() == "variable") {
                    writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
                }
            }
        }
        symbolTable->enterScope();
        isFunctionBlock = true;
        insertParams = true;
        currentParamTypes.clear();
        currentFunctionReturnType = $t.text;
        currentFunctionName = $id->getText();
      }
      pl=parameter_list rp=RPAREN
    {
        // After parameter list, check for redeclaration/type mismatch and set function info
        insertParams = false;
        auto sym = symbolTable->LookUp($id->getText());
        if (sym) {
            // Compare with previously declared parameter types for this function
            auto it = functionParamTypes.find($id->getText());
            if (it != functionParamTypes.end()) {
                const auto& declaredParams = it->second;
                if (declaredParams.size() != currentParamTypes.size()) {
                    writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Total number of arguments mismatch with declaration in function " + $id->getText() + "\n");
                } else {
                    for (int i = 0; i < declaredParams.size(); ++i) {
                        if (declaredParams[i] != currentParamTypes[i]) {
                            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": " + to_string(i+1) + "th argument mismatch in function " + $id->getText() + "\n");
                            break;
                        }
                    }
                }
            }
            auto prevFuncInfo = sym->getFunctionInfo();
            if (prevFuncInfo) {
                if (prevFuncInfo->getReturnType() != $t.text) {
                    writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Return type mismatch of " + $id->getText() + "\n");
                }
            }
            sym->setFunctionInfo(make_shared<FunctionInfo>(
                $t.text,
                currentParamTypes.empty() ? nullptr : currentParamTypes.data(),
                currentParamTypes.size()
            ));
        }
        // Update the function's parameter types in the map (for definition)
        functionParamTypes[$id->getText()] = currentParamTypes;
    }
    cs=compound_statement
    {
        isFunctionBlock = false;
        $text = $t.text + " " + $id->getText() + "(" + $pl.text + ")" + $cs.text;
        if ($pl.text.find(' ') != string::npos) {
            writeIntoParserLogFile("Line " + to_string($cs.stop->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" + $text + "\n");
        } else {
            writeIntoParserLogFile("Line " + to_string($cs.stop->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" + $text + "\n");
        }
        symbolTable->exitScope();
    }
    ;


// Parameter list for functions
parameter_list returns [string text]
    : t=type_specifier id=ID
    {
        // Insert parameter into symbol table and add its type for function info
        $text = $t.text + " " + $id->getText();
        if (insertParams) {
            if (!symbolTable->Insert($id->getText(), "ID")) {
                writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + " in parameter\n");
            }
        }
        addParamType($t.text);
        writeIntoParserLogFile("Line " + to_string($id->getLine()) + ": parameter_list : type_specifier ID\n\n" + $text + "\n");
    }

    | pl=parameter_list COMMA t=type_specifier id=ID
    {
        // Handle multiple parameters recursively
        $text = $pl.text + "," + $t.text + " " + $id->getText();
        if (insertParams) {
            if (!symbolTable->Insert($id->getText(), "ID")) {
                writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + " in parameter\n");
            }
        }
        addParamType($t.text);
        writeIntoParserLogFile("Line " + to_string($id->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n" + $text + "\n");
    }

    | // empty parameter list
    {
        $text = "";
    }

    | t=type_specifier invalid=.
    {
        $text = $t.text;
        writeIntoParserLogFile("Line " + to_string($invalid->getLine()) + ": parameter_list : type_specifier\n\n" + $text + "\n");
        writeIntoErrorFile("Error at line " + to_string($invalid->getLine()) + ": syntax error, unexpected " + "ADDOP" + ", expecting RPAREN or COMMA\n");
    }
    ;


// Compound statement (block), manages scope
compound_statement returns [string text]
    : lc=LCURL
      {
        if (!isFunctionBlock) {
            symbolTable->enterScope();
        }
      }
      rc=RCURL
    {
        $text = "{}";
        writeIntoParserLogFile("Line " + to_string($rc->getLine()) + ": compound_statement : LCURL RCURL\n\n" + $text + "\n");
        symbolTable->PrintAllScopeTable();
        if (!isFunctionBlock) {
            symbolTable->exitScope();
        }
    }

    | lc=LCURL
      {
        bool wasFunctionBlock = isFunctionBlock;
        if (!isFunctionBlock) {
            symbolTable->enterScope();
        }
        isFunctionBlock = false;
      }
      s=statements rc=RCURL
    {
        $text = "{\n" + $s.text + "\n}";
        writeIntoParserLogFile("Line " + to_string($rc->getLine()) + ": compound_statement : LCURL statements RCURL\n\n" + $text + "\n");
        symbolTable->PrintAllScopeTable();
        if (!wasFunctionBlock) {
            symbolTable->exitScope();
        }
    }
    ;


// Variable declaration (single or list)
var_declaration returns [string text]
    : t=type_specifier dl=declaration_list[$t.text] sm=SEMICOLON
    {
        $text = $t.text + " " + $dl.text + ";";
        if ($t.text == "void") {
            writeIntoErrorFile("Error at line " + to_string($t.start->getLine()) + ": Variable type cannot be void\n");
        }
        writeIntoParserLogFile("Line " + to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n\n" + $text + "\n");
    }
    ;


// Type specifier for variables and functions
type_specifier returns [string text]
    : INT
    {
        $text = "int";
        writeIntoParserLogFile("Line " + to_string($INT->getLine()) + ": type_specifier : INT\n\nint\n");
    }
    | FLOAT
    {
        $text = "float";
        writeIntoParserLogFile("Line " + to_string($FLOAT->getLine()) + ": type_specifier : FLOAT\n\nfloat\n");
    }
    | VOID
    {
        $text = "void";
        writeIntoParserLogFile("Line " + to_string($VOID->getLine()) + ": type_specifier : VOID\n\nvoid\n");
    }
    | STRUCT id=ID
    {
        $text = "struct " + $id->getText();
        writeIntoParserLogFile("Line " + to_string($STRUCT->getLine()) + ": type_specifier : STRUCT ID\n\nstruct " + $id->getText() + "\n");
    }
    ;


// List of variable/array declarations
declaration_list [string type] returns [string text]
    : first=declaration_item[$type]
      {
        writeIntoParserLogFile("Line " + to_string($first.line) + ": declaration_list : " + $first.ruleName + "\n\n" + $first.text + "\n");
      }
      rest=declaration_list_tail[$type, $first.text]
    {
        $text = $first.text + $rest.text;
    }
    ;

declaration_list_tail [string type, string builtSoFar] returns [string text]
    : COMMA next=declaration_item[$type]
      {
        string newList = builtSoFar + "," + $next.text;
        writeIntoParserLogFile("Line " + to_string($next.line) + ": declaration_list : declaration_list COMMA " + $next.ruleName + "\n\n" + newList + "\n");
      }
      rest=declaration_list_tail[$type, builtSoFar + "," + $next.text]
    {
        $text = "," + $next.text + $rest.text;
    }
    |
    {
        $text = "";
    }
    ;


// Single variable or array declaration
declaration_item [string type] returns [string text, string ruleName, int line]
    : id=ID ASSIGNOP init=logic_expression
    {
        $text = $id->getText() + " = " + $init.text;
        $ruleName = "ID";
        $line = $id->getLine();
        // Insert variable into symbol table
        if (!symbolTable->Insert($id->getText(), "ID")) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
        } else {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDeclaredType($type);
                sym->setDataType("variable");
            }
        }
    }
    | id=ID
    {
        $text = $id->getText();
        $ruleName = "ID";
        $line = $id->getLine();
        // Insert variable into symbol table
        if (!symbolTable->Insert($id->getText(), "ID")) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
        } else {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDeclaredType($type);
                sym->setDataType("variable");
            }
        }
    }
    | id=ID ap=ADDOP ID
    {
        $text = $id->getText();
        $ruleName = "ID";
        $line = $id->getLine();
        if (!symbolTable->Insert($id->getText(), "ID")) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
        } else {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDeclaredType($type);
                sym->setDataType("variable");
            }
        }
        writeIntoErrorFile("Error at line " + to_string($ap->getLine()) + ": syntax error, unexpected " + "ADDOP" + ", expecting COMMA or SEMICOLON\n");
    }
    | id=ID LTHIRD ci=CONST_INT RTHIRD
    {
        $text = $id->getText() + "[" + $ci->getText() + "]";
        $ruleName = "ID LTHIRD CONST_INT RTHIRD";
        $line = $id->getLine();
        // Insert array into symbol table
        if (!symbolTable->Insert($id->getText(), "ID")) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
        } else {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDeclaredType($type);
                sym->setDataType("array");
            }
        }
    }
    ;


// Struct definition at global scope
struct_definition returns [string text]
    : STRUCT id=ID LCURL
      {
        currentStructName = $id->getText();
        structMemberTable[currentStructName].clear();
        // Insert struct name into symbol table
        if (!symbolTable->Insert(currentStructName, "STRUCT")) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of struct " + currentStructName + "\n");
        } else {
            auto sym = symbolTable->LookUp(currentStructName);
            if (sym) {
                sym->setDataType("struct");
            }
        }
      }
      sm=struct_members RCURL SEMICOLON
    {
        $text = $id->getText() + " {\n" + $sm.text + "}\n";
        writeIntoParserLogFile("Line " + to_string($STRUCT->getLine()) + ": struct_definition : STRUCT ID LCURL struct_members RCURL SEMICOLON\n\nstruct " + $text + ";\n");
    }
    ;

struct_members returns [string text]
    : first=struct_member
      {
        $text = $first.text;
      }
      rest=struct_members_tail[$first.text]
    {
        $text = $first.text + $rest.text;
    }
    ;

struct_members_tail [string builtSoFar] returns [string text]
    : next=struct_member
      {
        $text = $next.text;
      }
      rest=struct_members_tail[builtSoFar + $next.text]
    {
        $text = $next.text + $rest.text;
    }
    |
    {
        $text = "";
    }
    ;

struct_member returns [string text]
    : t=type_specifier dl=declaration_list[$t.text] sm=SEMICOLON
    {
        // Track struct member types/names
        // Split $dl.text by ',' to get all member names
        string decl = $dl.text;
        string type = $t.text;
        size_t start = 0, end;
        set<string> memberNames;
        while ((end = decl.find(',', start)) != string::npos) {
            string name = decl.substr(start, end - start);
            // Check for duplicate member name in this struct
            if (memberNames.count(name)) {
                writeIntoErrorFile("Error at line " + to_string($t.start->getLine()) + ": Multiple declaration of member '" + name + "' in struct '" + currentStructName + "'\n");
            } else {
                memberNames.insert(name);
                structMemberTable[currentStructName].push_back({type, name});
            }
            start = end + 1;
        }
        // Last member
        string lastName = decl.substr(start);
        if (!lastName.empty()) {
            if (memberNames.count(lastName)) {
                writeIntoErrorFile("Error at line " + to_string($t.start->getLine()) + ": Multiple declaration of member '" + lastName + "' in struct '" + currentStructName + "'\n");
            } else {
                memberNames.insert(lastName);
                structMemberTable[currentStructName].push_back({type, lastName});
            }
        }
        $text = $t.text + " " + $dl.text + ";\n";
    }
    ;


// Sequence of statements in a block
statements returns [string text]
    : s=statement
    {
        $text = $s.text;
        if (!$text.empty()) {
            writeIntoParserLogFile("Line " + to_string($s.stop->getLine()) + ": statements : statement\n\n" + $text + "\n");
        }
    }
    | sl=statements s=statement
    {
        $text = $sl.text + "\n" + $s.text;
        if (!$s.text.empty()) {
            writeIntoParserLogFile("Line " + to_string($s.stop->getLine()) + ": statements : statements statement\n\n" + $text + "\n");
        }
    }
    ;


// All statement types: declarations, expressions, control flow, print, return
statement returns [string text]
    : v=var_declaration
    {
        $text = $v.text;
        writeIntoParserLogFile("Line " + to_string($v.stop->getLine()) + ": statement : var_declaration\n\n" + $text + "\n");
    }

    | es=expression_statement
    {
        $text = $es.text;
        if (!$text.empty()) {
            writeIntoParserLogFile("Line " + to_string($es.stop->getLine()) + ": statement : expression_statement\n\n" + $text + "\n");
        }
    }

    | cs=compound_statement
    {
        $text = $cs.text;
        writeIntoParserLogFile("Line " + to_string($cs.stop->getLine()) + ": statement : compound_statement\n\n" + $text + "\n");
    }

    | FOR LPAREN forInit=expression_statement forCond=expression_statement forInc=expression RPAREN forBody=statement
    {
        $text = "for(" + $forInit.text + $forCond.text + $forInc.text + ")" + $forBody.text;
        writeIntoParserLogFile("Line " + to_string($forBody.stop->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + $text + "\n");
    }

    | IF LPAREN ifCond=expression RPAREN ifThen=statement
    {
        $text = "if(" + $ifCond.text + ")" + $ifThen.text;
        writeIntoParserLogFile("Line " + to_string($ifThen.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" + $text + "\n");
    }

    | IF LPAREN ifCond=expression RPAREN ifThen=statement ELSE ifElse=statement
    {
        $text = "if(" + $ifCond.text + ")" + $ifThen.text + "else " + $ifElse.text;
        writeIntoParserLogFile("Line " + to_string($ifElse.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + $text + "\n");
    }

    | WHILE LPAREN whileCond=expression RPAREN whileBody=statement
    {
        $text = "while(" + $whileCond.text + ")" + $whileBody.text;
        writeIntoParserLogFile("Line " + to_string($whileBody.stop->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + $text + "\n");
    }

    | FORIN LPAREN e1=variable IN e2=expression TO e3=expression RPAREN forinBody=statement
    {
        $text = "forin(" + $e1.text + " in " + $e2.text + " to " + $e3.text + ")" + $forinBody.text;
        auto sym = symbolTable->LookUp($e1.text);
        if (!sym || sym->getDataType() != "int") {
            writeIntoErrorFile("Error at line " + to_string($e1.start->getLine()) + ": Loop variable '" + $e1.text + "' is not int in forin loop\n");
        }
        writeIntoParserLogFile("Line " + to_string($forinBody.stop->getLine()) + ": statement : FORIN LPAREN expression in expression to expression RPAREN statement\n\n" + $text + "\n");
    }

    | FOREACH LPAREN e1=variable IN e2=variable RPAREN forinBody=statement
    {
        $text = "foreach(" + $e1.text + " in " + $e2.text + ")" + $forinBody.text;
        auto sym = symbolTable->LookUp($e2.text);
        if (!sym || sym->getDeclaredType() != "array") {
            writeIntoErrorFile("Error at line " + to_string($e2.start->getLine()) + ": '" + $e2.text + "' is not an array in foreach loop\n");
        }
        writeIntoParserLogFile("Line " + to_string($forinBody.stop->getLine()) + ": statement : FOREACH LPAREN expression in expression RPAREN statement\n\n" + $text + "\n");
    }

    | DO whileBody=statement WHILE LPAREN whileCond=expression RPAREN SEMICOLON
    {
        $text = "do " + $whileBody.text + "while(" + $whileCond.text + ");";
        writeIntoParserLogFile("Line " + to_string($whileCond.stop->getLine()) + ": statement : DO statement WHILE LPAREN expression RPAREN SEMICOLON\n\n" + $text + "\n");
    }

    | PRINTLN LPAREN id=ID RPAREN SEMICOLON
    {
        // Print statement, check if variable is declared
        $text = "printf(" + $id->getText() + ");";
        writeIntoParserLogFile("Line " + to_string($PRINTLN->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" + $text + "\n");
        auto sym = symbolTable->LookUp($id->getText());
        if (!sym) {
            writeIntoErrorFile("Error at line " + to_string($PRINTLN->getLine()) + ": Undeclared variable " + $id->getText() + "\n");
        } else if (sym->getDataType() != "variable" && sym->getDataType() != "array") {
            writeIntoErrorFile("Error at line " + to_string($PRINTLN->getLine()) + ": Cannot print non-variable type " + sym->getDeclaredType() + "\n");
        }
    }

    | RETURN expr=expression SEMICOLON
    {
        // Return with value, check for void function
        $text = "return " + $expr.text + ";";
        if (currentFunctionReturnType == "void") {
            writeIntoErrorFile("Error at line " + to_string($RETURN->getLine() + 1) + ": Cannot return value from function " + currentFunctionName + " with void return type\n");
        }
        writeIntoParserLogFile("Line " + to_string($RETURN->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + $text + "\n");
    }

    | RETURN SEMICOLON
    {
        $text = "return;";
        writeIntoParserLogFile("Line " + to_string($RETURN->getLine()) + ": statement : RETURN SEMICOLON\n\n" + $text + "\n");
    }

    | BREAK SEMICOLON
    {
        $text = "break;";
        writeIntoParserLogFile("Line " + to_string($BREAK->getLine()) + ": statement : BREAK SEMICOLON\n\n" + $text + "\n");
    }

    | CONTINUE SEMICOLON
    {
        $text = "continue;";
        writeIntoParserLogFile("Line " + to_string($CONTINUE->getLine()) + ": statement : CONTINUE SEMICOLON\n\n" + $text + "\n");
    }
    | sw=switch_statement
    {
        $text = $sw.text;
        writeIntoParserLogFile("Line " + to_string($sw.stop->getLine()) + ": statement : switch_statement\n\n" + $text + "\n");
    }
    ;


// Switch-case statement
switch_statement returns [string text]
    : SWITCH LPAREN expr=expression RPAREN LCURL cases=case_list def=default_case? RCURL
    {
        $text = "switch(" + $expr.text + ") {\n" + $cases.text + ($def.text.empty() ? "" : $def.text) + "}\n";
        writeIntoParserLogFile("Line " + to_string($SWITCH->getLine()) + ": switch_statement : SWITCH LPAREN expression RPAREN LCURL case_list default_case? RCURL\n\n" + $text + "\n");
    }
    ;

case_list returns [string text]
    : c=case_label
    {
        $text = $c.text;
    }
    | cl=case_list c=case_label
    {
        $text = $cl.text + $c.text;
    }
    | // empty
    {
        $text = "";
    }
    ;

case_label returns [string text]
    : CASE ci=CONST_INT COLON stmts=statements
    {
        $text = "case " + $ci->getText() + ":\n" + $stmts.text;
        writeIntoParserLogFile("Line " + to_string($CASE->getLine()) + ": case_label : CASE CONST_INT COLON statements\n\n" + $text + "\n");
    }
    ;

default_case returns [string text]
    : DEFAULT COLON stmts=statements
    {
        $text = "default:\n" + $stmts.text;
        writeIntoParserLogFile("Line " + to_string($DEFAULT->getLine()) + ": default_case : DEFAULT COLON statements\n\n" + $text + "\n");
    }
    ;


// Expression statement (expression or just semicolon)
expression_statement returns [string text]
    : sm=SEMICOLON
    {
        $text = ";";
        writeIntoParserLogFile("Line " + to_string($sm->getLine()) + ": expression_statement : SEMICOLON\n\n;\n");
    }
    | e=expression sm=SEMICOLON
    {
        $text = $e.text + ";";
        writeIntoParserLogFile("Line " + to_string($sm->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + $text + "\n");
    }
    | e=expression
    {
        $text = "";
    }
    ;


// Variable usage (with or without array indexing)
variable returns [string text, vector<string> argTypes, string arrayName]
    : id=ID
    {
        $text = $id->getText();
        $argTypes.clear();
        $arrayName = "";
        writeIntoParserLogFile("Line " + to_string($id->getLine()) + ": variable : ID\n\n" + $text + "\n");
        auto sym = symbolTable->LookUp($id->getText());
        if (sym) {
            if (sym->getDataType() == "array") {
                $argTypes.push_back("array");
            } else {
                $argTypes.push_back(sym->getDeclaredType());
            }
        } else {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Undeclared variable " + $id->getText() + "\n");
        }
    }

    | id=ID LTHIRD e=expression RTHIRD
    {
        // Array element access, check for valid array and index type
        $text = $id->getText() + "[" + $e.text + "]";
        $argTypes.clear();
        $arrayName = $id->getText();
        writeIntoParserLogFile("Line " + to_string($id->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + $text + "\n");
        auto sym = symbolTable->LookUp($id->getText());
        if (sym) {
            if (sym->getDataType() != "array") {
                writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": " + $id->getText() + " not an array\n");
            }
            $argTypes.push_back(sym->getDeclaredType());
        } else {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Undeclared array " + $id->getText() + "\n");
        }
        bool isFloat = $e.text.find('.') != string::npos;
        bool isNumeric = !$e.text.empty() && $e.text.find_first_not_of("0123456789.") == string::npos;
        if (isFloat && isNumeric) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Expression inside third brackets not an integer\n");
        }
    }
    ;


// Assignment and logic expressions
expression returns [string text, vector<string> argTypes]
    : le=logic_expression
    {
        $text = $le.text;
        $argTypes = $le.argTypes;
        writeIntoParserLogFile("Line " + to_string($le.stop->getLine()) + ": expression : logic_expression\n\n" + $text + "\n");
    }

    | v=variable ao=ASSIGNOP
    {
        isExpressionStatement = true;
    }
      le=logic_expression
    {
        isExpressionStatement = false;
        $text = $v.text + "=" + $le.text;
        $argTypes.clear();
        if ($le.text.find(' ') == std::string::npos) {
            writeIntoParserLogFile("Line " + to_string($ao->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + $text + "\n");
        } else {
            string trimmedText = $le.text;
            if (!trimmedText.empty() && trimmedText.back() == ' ') trimmedText.pop_back();
            writeIntoParserLogFile("Line " + to_string($le.stop->getLine() + 1) + ": expression : logic_expression\n\n" + trimmedText + "\n");
        }
        // Type checking for assignment to variable or array element
        auto sym = symbolTable->LookUp($v.text);
        if (!sym && !$v.arrayName.empty()) {
            sym = symbolTable->LookUp($v.arrayName);
        }
        if (sym) {
            if (sym->getDataType() == "array" && !$v.arrayName.empty()) {
                // Assignment to array element
                string varType = sym->getDeclaredType();
                bool isFloatLiteral = $le.text.find('.') != string::npos;
                if (varType == "int" && isFloatLiteral && $le.text.find('%') == string::npos) {
                    writeIntoErrorFile("Error at line " + to_string($ao->getLine()) + ": Type Mismatch\n");
                }
            } else if (sym->getDataType() == "array") {
                writeIntoErrorFile("Error at line " + to_string($ao->getLine()) + ": Type mismatch, " + $v.text + " is an array\n");
            } else {
                string varType = sym->getDeclaredType();
                bool isFloatLiteral = $le.text.find('.') != string::npos;
                if (varType == "int" && isFloatLiteral && $le.text.find('%') == string::npos) {
                    writeIntoErrorFile("Error at line " + to_string($ao->getLine()) + ": Type Mismatch\n");
                }
            }
        }
    }
    ;


// Logical, relational, arithmetic expressions
logic_expression returns [string text, vector<string> argTypes]
    : re=rel_expression
    {
        $text = $re.text;
        string trimmedText = $text;
        if (!trimmedText.empty() && trimmedText.back() == ' ') {
            trimmedText.pop_back();
            writeIntoParserLogFile("Line " + to_string($re.stop->getLine() + 1) + ": logic_expression : rel_expression\n\n" + trimmedText + "\n");
        } else {
            writeIntoParserLogFile("Line " + to_string($re.stop->getLine()) + ": logic_expression : rel_expression\n\n" + $text + "\n");
        }
        $argTypes = $re.argTypes;
    }

    | l=rel_expression lo=LOGICOP r=rel_expression
    {
        $text = $l.text + $lo->getText() + $r.text;
        $argTypes.clear();
        writeIntoParserLogFile("Line " + to_string($lo->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" + $text + "\n");
    }
    ;

rel_expression returns [string text, vector<string> argTypes]
    : se=simple_expression
    {
        $text = $se.text;
        string trimmedText = $text;
        if (!trimmedText.empty() && trimmedText.back() == ' ') {
            trimmedText.pop_back();
            writeIntoParserLogFile("Line " + to_string($se.stop->getLine() + 1) + ": rel_expression : simple_expression\n\n" + trimmedText + "\n");
        } else {
            writeIntoParserLogFile("Line " + to_string($se.stop->getLine()) + ": rel_expression : simple_expression\n\n" + $text + "\n");
        }
        $argTypes = $se.argTypes;
    }

    | l=simple_expression ro=RELOP r=simple_expression
    {
        $text = $l.text + $ro->getText() + $r.text;
        $argTypes.clear();
        writeIntoParserLogFile("Line " + to_string($ro->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" + $text + "\n");
    }
    ;

simple_expression returns [string text, vector<string> argTypes]
    : t=term
    {
        $text = $t.text;
        $argTypes = $t.argTypes;
        writeIntoParserLogFile("Line " + to_string($t.stop->getLine()) + ": simple_expression : term\n\n" + $text + "\n");
    }

    | se=simple_expression ao=ADDOP t=term
    {
        $text = $se.text + $ao->getText() + $t.text;
        $argTypes = $t.argTypes;
        writeIntoParserLogFile("Line " + to_string($ao->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" + $text + "\n");
    }

    | se=simple_expression ao=ADDOP as=ASSIGNOP
    {
        writeIntoErrorFile("Error at line " + to_string($as->getLine()) + ": syntax error, unexpected " + "ASSIGNOP" + "\n");
    }
      t=term h=HASH
    {
        $text = $t.text + " ";
        writeIntoErrorFile("Error at line " + to_string($h->getLine()) + ": Unrecognized character " + $h->getText() + "\n");
        writeIntoParserLogFile("Line " + to_string($h->getLine() + 1) + ": simple_expression : term\n\n" + $t.text + "\n");
    }
    ;

term returns [string text, vector<string> argTypes]
    : ue=unary_expression
    {
        $text = $ue.text;
        $argTypes = $ue.argTypes;
        writeIntoParserLogFile("Line " + to_string($ue.stop->getLine()) + ": term : unary_expression\n\n" + $text + "\n");
    }

    | t=term mo=MULOP ue=unary_expression
    {
        $text = $t.text + $mo->getText() + $ue.text;
        $argTypes.clear();
        writeIntoParserLogFile("Line " + to_string($mo->getLine()) + ": term : term MULOP unary_expression\n\n" + $text + "\n");
        // Modulus/division by zero and type checks
        if ($mo->getText() == "%" && $ue.text == "0") {
            writeIntoErrorFile("Error at line " + to_string($mo->getLine()) + ": Modulus by Zero\n");
        }
        if ($mo->getText() == "%" && (
                $t.text.find('.') != string::npos ||
                $ue.text.find('.') != string::npos)) {
            writeIntoErrorFile("Error at line " + to_string($mo->getLine()) + ": Non-Integer operand on modulus operator\n");
        }
        if ($mo->getText() == "/" && ($ue.text == "0" || $ue.text == "0.0")) {
            writeIntoErrorFile("Error at line " + to_string($mo->getLine()) + ": Division by Zero\n");
        }
    }
    ;

unary_expression returns [string text, vector<string> argTypes]
    : ao=ADDOP ue=unary_expression
    {
        $text = $ao->getText() + $ue.text;
        $argTypes = $ue.argTypes;
        writeIntoParserLogFile("Line " + to_string($ao->getLine()) + ": unary_expression : ADDOP unary_expression\n\n" + $text + "\n");
    }

    | n=NOT ue=unary_expression
    {
        $text = "!" + $ue.text;
        $argTypes = $ue.argTypes;
        writeIntoParserLogFile("Line " + to_string($n->getLine()) + ": unary_expression : NOT unary_expression\n\n" + $text + "\n");
    }

    | f=factor
    {
        $text = $f.text;
        $argTypes = $f.argTypes;
        writeIntoParserLogFile("Line " + to_string($f.stop->getLine()) + ": unary_expression : factor\n\n" + $text + "\n");
    }
    ;


// Factor: variable, function call, literal, or parenthesized expression
factor returns [string text, vector<string> argTypes]
    : v=variable
    {
        $text = $v.text;
        $argTypes.clear();
        writeIntoParserLogFile("Line " + to_string($v.stop->getLine()) + ": factor : variable\n\n" + $text + "\n");
    }

    | id=ID LPAREN al=argument_list RPAREN
    {
        // Function call: check for declaration, argument count/type, void-in-expression
        $text = $id->getText() + "(" + $al.text + ")";
        auto funcSym = symbolTable->LookUp($id->getText());
        if (!funcSym) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Undefined function " + $id->getText() + "\n");
        } else if (funcSym->getDataType() != "function") {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": " + $id->getText() + " is not a function\n");
        } else {
            auto funcInfo = funcSym->getFunctionInfo();
            int expected = funcInfo->getParameterCount();
            int given = $al.argTypes.size();
            if (expected != given) {
                writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Total number of arguments mismatch with declaration in function " + $id->getText() + "\n");
            } else {
                for (int i = 0; i < expected; ++i) {
                    if ($al.argTypes[i] == "array") {
                        writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Type mismatch, " + $al.argNames[i] + " is an array\n");
                    } else if ($al.argTypes[i] != funcInfo->getParameterType(i)) {
                        writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": " + to_string(i+1) + "th argument mismatch in function " + $id->getText() + "\n");
                        break;
                    }
                }
            }
            $argTypes.clear();
            $argTypes.push_back(funcInfo->getReturnType());
            if (funcInfo->getReturnType() == "void" && isExpressionStatement) {
                writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Void function used in expression\n");
            }
        }
        writeIntoParserLogFile("Line " + to_string($id->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n\n" + $text + "\n");
    }

    | lp=LPAREN e=expression rp=RPAREN
    {
        $text = "(" + $e.text + ")";
        $argTypes = $e.argTypes;
        writeIntoParserLogFile("Line " + to_string($lp->getLine()) + ": factor : LPAREN expression RPAREN\n\n" + $text + "\n");
    }

    | ci=CONST_INT
    {
        $text = $ci->getText();
        $argTypes.clear();
        $argTypes.push_back("int");
        writeIntoParserLogFile("Line " + to_string($ci->getLine()) + ": factor : CONST_INT\n\n" + $text + "\n");
    }

    | cf=CONST_FLOAT
    {
        $text = $cf->getText();
        $argTypes.clear();
        $argTypes.push_back("float");
        writeIntoParserLogFile("Line " + to_string($cf->getLine()) + ": factor : CONST_FLOAT\n\n" + $text + "\n");
    }

    | v=variable io=INCOP
    {
        $text = $v.text + "++";
        $argTypes = $v.argTypes;
        writeIntoParserLogFile("Line " + to_string($io->getLine()) + ": factor : variable INCOP\n\n" + $text + "\n");
    }

    | v=variable doo=DECOP
    {
        $text = $v.text + "--";
        $argTypes = $v.argTypes;
        writeIntoParserLogFile("Line " + to_string($doo->getLine()) + ": factor : variable DECOP\n\n" + $text + "\n");
    }
    ;


// Argument list for function calls
argument_list returns [string text, vector<string> argTypes, vector<string> argNames]
    : a=arguments
    {
        $text = $a.text;
        $argTypes = $a.argTypes;
        $argNames = $a.argNames;
        writeIntoParserLogFile("Line " + to_string($a.stop->getLine()) + ": argument_list : arguments\n\n" + $text + "\n");
    }
    |
    {
        $text = "";
        $argTypes.clear();
        $argNames.clear();
    }
    ;


// Arguments for function calls (recursive for multiple arguments)
arguments returns [string text, vector<string> argTypes, vector<string> argNames]
    : le=logic_expression
    {
        // Determine argument type and name for checking
        $text = $le.text;
        string argType = "int";
        string argName = $le.text;
        auto sym = symbolTable->LookUp($le.text);
        if (sym) {
            argType = sym->getDataType() == "array" ? "array" : sym->getDeclaredType();
        } else if ($le.text.find('.') != string::npos) {
            argType = "float";
        }
        $argTypes.clear();
        $argTypes.push_back(argType);
        $argNames.clear();
        $argNames.push_back(argName);
        writeIntoParserLogFile("Line " + to_string($le.stop->getLine()) + ": arguments : logic_expression\n\n" + $text + "\n");
    }

    | a=arguments COMMA le=logic_expression
    {
        $text = $a.text + "," + $le.text;
        string argType = "int";
        string argName = $le.text;
        auto sym = symbolTable->LookUp($le.text);
        if (sym) {
            argType = sym->getDataType() == "array" ? "array" : sym->getDeclaredType();
        } else if ($le.text.find('.') != string::npos) {
            argType = "float";
        }
        $argTypes = $a.argTypes;
        $argTypes.push_back(argType);
        $argNames = $a.argNames;
        $argNames.push_back(argName);
        writeIntoParserLogFile("Line " + to_string($le.stop->getLine()) + ": arguments : arguments COMMA logic_expression\n\n" + $text + "\n");
    }
    ;
