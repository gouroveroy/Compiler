parser grammar C2105017Parser;

options {
    tokenVocab = C2105017Lexer;
}

// =============================================================================
// PARSER HEADER SECTION
// Includes necessary C++ headers and symbol table for semantic analysis
// =============================================================================
@parser::header {
    #include <iostream>
    #include <iomanip>
    #include <sstream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include "C2105017Lexer.h"
    #include "SymbolTable/2105017_symbol_table.h"

    using namespace std;

    extern ofstream parserLogFile;
    extern ofstream errorFile;

    extern int syntaxErrorCount;
    extern SymbolTable *symbolTable;
}

// =============================================================================
// PARSER MEMBERS SECTION
// Contains assembly code generation logic and helper functions
// =============================================================================
@parser::members {
    // =============================================================================
    // ASSEMBLY CODE GENERATION - Core assembly output management
    // Generates 8086 assembly code from parsed C-like input
    // =============================================================================
    string assemblyCode = ".MODEL SMALL\n\n.STACK 1000H\n\n";
    string dataSegment = ".DATA\n\n";
    string procSegment = ".CODE\n\nMAIN PROC\n    MOV AX, @DATA\n    MOV DS, AX\n";
    string functionSegment = "";
    int labelCount = 0;
    int currentLocalOffset = 2;
    int localVariableSpace = 0;  // Track total space allocated for local variables
    int parameterCount = 0;
    bool hasPrintln = false;

    string newLabel() { return "L" + to_string(labelCount++); }

    // =============================================================================
    // SCOPE MANAGEMENT - Global vs Local variable identification
    // Determines if a variable is declared in global or local scope
    // =============================================================================
    bool isGlobal(string name) {
        auto sym = symbolTable->LookUp(name);
        if (!sym) return false;

        // Get the global scope (root scope)
        auto currentScope = symbolTable->getCurrentScope();
        while (currentScope->getParentScope() != nullptr) {
            currentScope = currentScope->getParentScope();
        }

        // Check if variable is declared in the global (root) scope
        auto globalResult = currentScope->LookUp(name);
        return globalResult.first != nullptr;
    }

    // =============================================================================
    // VARIABLE ACCESS RESOLUTION - Memory addressing for variables
    // Generates appropriate 8086 addressing modes for global/local variables
    // Global: [varName], Local: [BP +/- offset]
    // =============================================================================
    string getVarAccess(string name) {
        auto sym = symbolTable->LookUp(name);
        if (!sym) return name; // Should not happen with error-free input

        // Check if this symbol is in the global scope by checking its scope
        auto currentScope = symbolTable->getCurrentScope();
        auto globalScope = currentScope;
        while (globalScope->getParentScope() != nullptr) {
            globalScope = globalScope->getParentScope();
        }

        // Check if the symbol is found in the current scope or a parent scope
        auto tempScope = currentScope;
        while (tempScope != nullptr) {
            auto result = tempScope->LookUp(name);
            if (result.first != nullptr) {
                // Found the symbol in this scope
                if (tempScope == globalScope) {
                    // It's a global variable
                    return "[" + name + "]";
                } else {
                    // It's a local variable or parameter
                    return string("[BP ") + (sym->getIsParameter() ? "+ " : "- ") + to_string(sym->getOffset()) + "]";
                }
            }
            tempScope = tempScope->getParentScope();
        }

        // Fallback (should not reach here)
        return "[" + name + "]";
    }

    // =============================================================================
    // PARSER STATE MANAGEMENT - Context tracking during parsing
    // Tracks current parsing context (function parameters, blocks, etc.)
    // =============================================================================
    bool insertParams = false;
    bool isFunctionBlock = false;
    string currentDeclListText;
    string currentFunctionReturnType;
    string currentFunctionName;
    bool isExpressionStatement = false;

    // =============================================================================
    // LOGGING SYSTEM - Error reporting and parse tree logging
    // Handles output to parser log file and error file
    // =============================================================================
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

    // =============================================================================
    // FUNCTION SIGNATURE TRACKING - Parameter type validation
    // Tracks parameter types for function declarations and definitions
    // =============================================================================
    vector<string> currentParamTypes;
    vector<string> currentParamNames;  // Track parameter names in order
    void clearCurrentParamTypes() { currentParamTypes.clear(); currentParamNames.clear(); }
    void addParamType(const string& type) { currentParamTypes.push_back(type); }
    void addParamName(const string& name) { currentParamNames.push_back(name); }
    // Map to track parameter types for each function by name (for signature checks)
    map<string, vector<string>> functionParamTypes;
}

// =============================================================================
// GRAMMAR RULES SECTION
// =============================================================================

// =============================================================================
// PROGRAM ENTRY POINT - Main parser entry and assembly finalization
// Handles final assembly code generation and print procedure insertion
// =============================================================================
start : program
    {
        // Finalize assembly code for main
        procSegment += "MOV AX, 4CH\n    INT 21H\nMAIN ENDP\n";

        // Add NUMBER buffer at the end of data segment if println is used
        if (hasPrintln) {
            dataSegment += "NUMBER DB \"00000$\"\n\n";
        }

        assemblyCode += dataSegment + procSegment + functionSegment;

        // Add print procedures only if println is used
        if (hasPrintln) {
            assemblyCode += "\n; Print procedures\n" + string(
                "NEW_LINE PROC\n"
                "    PUSH AX\n"
                "    PUSH DX\n"
                "    MOV AH,2\n"
                "    MOV DL,0DH\n"
                "    INT 21H\n"
                "    MOV AH,2\n"
                "    MOV DL,0AH\n"
                "    INT 21H\n"
                "    POP DX\n"
                "    POP AX\n"
                "    RET\n"
                "NEW_LINE ENDP\n\n"
                "PRINT_OUTPUT PROC\n"
                "    PUSH AX\n"
                "    PUSH BX\n"
                "    PUSH CX\n"
                "    PUSH DX\n"
                "    PUSH SI\n"
                "    LEA SI,NUMBER\n"
                "    MOV BX,10\n"
                "    ADD SI,4\n"
                "    CMP AX,0\n"
                "    JNGE NEGATE\n"
                "PRINT:\n"
                "    XOR DX,DX\n"
                "    DIV BX\n"
                "    MOV [SI],DL\n"
                "    ADD [SI],'0'\n"
                "    DEC SI\n"
                "    CMP AX,0\n"
                "    JNE PRINT\n"
                "    INC SI\n"
                "    MOV BYTE PTR [SI+6], '$'\n"
                "    LEA DX,SI\n"
                "    MOV AH,9\n"
                "    INT 21H\n"
                "    POP SI\n"
                "    POP DX\n"
                "    POP CX\n"
                "    POP BX\n"
                "    POP AX\n"
                "    RET\n"
                "NEGATE:\n"
                "    PUSH AX\n"
                "    MOV AH,2\n"
                "    MOV DL,'-'\n"
                "    INT 21H\n"
                "    POP AX\n"
                "    NEG AX\n"
                "    JMP PRINT\n"
                "PRINT_OUTPUT ENDP\n"
            );
        }
        assemblyCode += "END MAIN\n";

        antlr4::Token* lastToken = _input->get(_input->size() - 1);
        int totalLines = lastToken->getLine();
        writeIntoParserLogFile("Line " + to_string(totalLines) + ": start : program\n");
        symbolTable->PrintAllScopeTable();
        writeIntoParserLogFile("Total number of lines: " + to_string(totalLines));
        writeIntoParserLogFile("Total number of errors: " + to_string(syntaxErrorCount));
    }
    ;

// =============================================================================
// PROGRAM STRUCTURE - Recursive program unit parsing
// Handles sequential parsing of units (declarations, functions)
// =============================================================================
program returns [string text, string code]
    : u=unit
    {
        $text = $u.text;
        $code = $u.code;
        writeIntoParserLogFile("Line " + to_string($u.stop->getLine()) + ": program : unit\n\n" + $text + "\n");
    }
    | p=program u=unit
    {
        $text = $p.text + "\n" + $u.text;
        $code = $p.code + $u.code;
        writeIntoParserLogFile("Line " + to_string($u.stop->getLine()) + ": program : program unit\n\n" + $text + "\n");
    }
    ;

// =============================================================================
// PROGRAM UNITS - Top-level constructs in the program
// Handles variable declarations, function declarations, and function definitions
// =============================================================================
unit returns [string text, string code]
    : v=var_declaration
    {
        $text = $v.text;
        $code = $v.code;
        writeIntoParserLogFile("Line " + to_string($v.stop->getLine()) + ": unit : var_declaration\n\n" + $text + "\n");
    }
    | f=func_declaration
    {
        $text = $f.text;
        $code = $f.code;
        writeIntoParserLogFile("Line " + to_string($f.stop->getLine()) + ": unit : func_declaration\n\n" + $text + "\n");
    }
    | fd=func_definition
    {
        $text = $fd.text;
        $code = $fd.code;
        writeIntoParserLogFile("Line " + to_string($fd.stop->getLine()) + ": unit : func_definition\n\n" + $text + "\n");
    }
    ;

// =============================================================================
// FUNCTION DECLARATIONS - Function prototypes without implementation
// Handles function signature registration in symbol table
// =============================================================================
func_declaration returns [string text, string code]
    : t=type_specifier id=ID LPAREN RPAREN sm=SEMICOLON
    {
        // Insert function with no parameters
        $text = $t.text + " " + $id->getText() + "();";
        $code = "";
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
        $code = "";
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

// =============================================================================
// FUNCTION DEFINITIONS - Function implementations with assembly generation
// Handles function body parsing and assembly code generation for 8086
// =============================================================================
func_definition returns [string text, string code]
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
        currentLocalOffset = 2;
        localVariableSpace = 0;  // Reset local variable space counter
        parameterCount = 0;
      }
      cs=compound_statement
      {
        $text = $t.text + " " + $id->getText() + "()" + $cs.text;
        if ($id->getText() == "main") {
            // For main, add function prologue and code to procSegment
            procSegment += "    PUSH BP\n    MOV BP, SP\n";
            $code = $cs.code;
            // Add stack cleanup before return if local variables were allocated
            if (localVariableSpace > 0) {
                // $code += "    ADD SP, " + to_string(localVariableSpace) + "\n";
            }
            $code += "    POP BP\n";
            size_t retPos = $code.rfind("RET");
            if (retPos != string::npos) {
                // Remove RET and any trailing characters (e.g. comment)
                $code = $code.substr(0, retPos);
            }
            procSegment += $code;
        } else {
            // For other functions, add to functionSegment
            string prologue = "\n" + $id->getText() + " PROC\n    PUSH BP\n    MOV BP, SP\n";
            string stackCleanup = "";
            if (localVariableSpace > 0) {
                // stackCleanup = "    ADD SP, " + to_string(localVariableSpace) + "\n";
            }
            string epilogue = stackCleanup + "    POP BP\n    RET 0\n" + $id->getText() + " ENDP\n";
            $code = prologue + $cs.code + epilogue;
            functionSegment += $code;
        }
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
        currentLocalOffset = 2;
        localVariableSpace = 0;  // Reset local variable space counter
      }
      pl=parameter_list rp=RPAREN    {
        // After parameter list, check for redeclaration/type mismatch and set function info
        insertParams = false;

        // Set parameter offsets in reverse order (last parameter at BP+4, first at highest offset)
        for (int i = 0; i < currentParamNames.size(); i++) {
            auto sym = symbolTable->LookUp(currentParamNames[i]);
            if (sym) {
                // Last parameter gets BP+4, second-to-last gets BP+6, etc.
                int offset = 4 + (currentParamNames.size() - 1 - i) * 2;
                sym->setOffset(offset);
            }
        }

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
        if ($id->getText() == "main") {
            // For main, add function prologue and code to procSegment
            procSegment += "    PUSH BP\n    MOV BP, SP\n";
            $code = $pl.code + $cs.code;
            // Add stack cleanup before return if local variables were allocated
            if (localVariableSpace > 0) {
                // $code += "    ADD SP, " + to_string(localVariableSpace) + "\n";
            }
            size_t retPos = $code.rfind("RET");
            if (retPos != string::npos) {
                // Remove RET and any trailing characters (e.g. comment)
                $code = $code.substr(0, retPos);
            }
            procSegment += $code;
        } else {
            // For other functions, add to functionSegment
            string prologue = "\n" + $id->getText() + " PROC\n    PUSH BP\n    MOV BP, SP\n";
            string functionBody = $pl.code + $cs.code;

            // Check if function body already contains a RET instruction
            string epilogue = "";
            size_t retPos = functionBody.rfind("RET");
            if (retPos == string::npos) {
                // No RET found, add default epilogue
                string stackCleanup = "";
                if (localVariableSpace > 0) {
                    stackCleanup = "    ADD SP, " + to_string(localVariableSpace) + "\n";
                }
                epilogue = stackCleanup + "    POP BP\n    RET " + to_string(parameterCount * 2) + "\n";
            }
            epilogue += $id->getText() + " ENDP\n";
            $code = prologue + functionBody + epilogue;
            functionSegment += $code;
        }
        if ($pl.text.find(' ') != string::npos) {
            writeIntoParserLogFile("Line " + to_string($cs.stop->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" + $text + "\n");
        } else {
            writeIntoParserLogFile("Line " + to_string($cs.stop->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" + $text + "\n");
        }
        symbolTable->exitScope();
    }
    ;

// =============================================================================
// FUNCTION PARAMETERS - Parameter list handling for function signatures
// Manages parameter insertion into symbol table and type validation
// =============================================================================
parameter_list returns [string text, string code]
    : t=type_specifier id=ID
    {
        // Single parameter handling - insert into symbol table for function signature
        $text = $t.text + " " + $id->getText();
        $code = "";
        if (insertParams) {
            // Insert parameter into current function's local scope
            if (!symbolTable->Insert($id->getText(), "ID")) {
                writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + " in parameter\n");
            } else {
                auto sym = symbolTable->LookUp($id->getText());
                sym->setIsParameter(true);  // Mark as parameter for offset calculation
                // Don't set offset here - will be set in a post-processing step
                parameterCount = 1;  // Track parameter count for stack cleanup
            }
        }
        // Add parameter type to function signature tracking
        addParamType($t.text);
        addParamName($id->getText());
        writeIntoParserLogFile("Line " + to_string($id->getLine()) + ": parameter_list : type_specifier ID\n\n" + $text + "\n");
    }

    | pl=parameter_list COMMA t=type_specifier id=ID
    {
        // Multiple parameters - handle recursively and accumulate parameter info
        $text = $pl.text + "," + $t.text + " " + $id->getText();
        $code = $pl.code;
        if (insertParams) {
            // Insert additional parameter into function's local scope
            if (!symbolTable->Insert($id->getText(), "ID")) {
                writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + " in parameter\n");
            } else {
                auto sym = symbolTable->LookUp($id->getText());
                sym->setIsParameter(true);  // Mark as parameter for offset calculation
                parameterCount++;  // Increment parameter count for stack management
                // Don't set offset here - will be set in a post-processing step
            }
        }
        // Add parameter type to function signature tracking
        addParamType($t.text);
        addParamName($id->getText());
        writeIntoParserLogFile("Line " + to_string($id->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n" + $text + "\n");
    }

    | // Empty parameter list - function takes no parameters
    {
        $text = "";
        $code = "";
    }

    | t=type_specifier invalid=.
    {
        // Error handling for malformed parameter list
        $text = $t.text;
        $code = "";
        writeIntoParserLogFile("Line " + to_string($invalid->getLine()) + ": parameter_list : type_specifier\n\n" + $text + "\n");
        writeIntoErrorFile("Error at line " + to_string($invalid->getLine()) + ": syntax error, unexpected " + "ADDOP" + ", expecting RPAREN or COMMA\n");
    }
    ;

// =============================================================================
// COMPOUND STATEMENTS - Code block handling with scope management
// Manages lexical scoping and nested block structures
// =============================================================================
compound_statement returns [string text, string code]
    : lc=LCURL
      {
        // Enter new scope for block unless this is a function block
        if (!isFunctionBlock) {
            symbolTable->enterScope();
        }
      }
      rc=RCURL
    {
        // Empty block - no statements inside
        $text = "{}";
        $code = "";
        writeIntoParserLogFile("Line " + to_string($rc->getLine()) + ": compound_statement : LCURL RCURL\n\n" + $text + "\n");
        symbolTable->PrintAllScopeTable();
        if (!isFunctionBlock) {
            symbolTable->exitScope();  // Exit scope for empty block
        }
    }

    | lc=LCURL
      {
        // Block with statements - manage scope transition
        bool wasFunctionBlock = isFunctionBlock;
        if (!isFunctionBlock) {
            symbolTable->enterScope();  // Enter new scope for block
        }
        isFunctionBlock = false;  // Reset function block flag
      }
      s=statements rc=RCURL
    {
        // Block with statements - format and generate code
        $text = "{\n" + $s.text + "\n}";
        $code = $s.code;
        writeIntoParserLogFile("Line " + to_string($rc->getLine()) + ": compound_statement : LCURL statements RCURL\n\n" + $text + "\n");
        symbolTable->PrintAllScopeTable();
        if (!wasFunctionBlock) {
            symbolTable->exitScope();  // Exit scope for statement block
        }
    }
    ;

// =============================================================================
// VARIABLE DECLARATIONS - Variable and array declaration handling
// Manages type checking and symbol table insertion
// =============================================================================
var_declaration returns [string text, string code]
    : t=type_specifier dl=declaration_list[$t.text] sm=SEMICOLON
    {
        // Variable declaration with type checking
        $text = $t.text + " " + $dl.text + ";";
        $code = $dl.code;
        if ($t.text == "void") {
            // Void variables are not allowed
            writeIntoErrorFile("Error at line " + to_string($t.start->getLine()) + ": Variable type cannot be void\n");
        }
        writeIntoParserLogFile("Line " + to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n\n" + $text + "\n");
    }
    ;

// =============================================================================
// TYPE SPECIFIERS - Basic data type recognition
// Handles int, float, and void type specifiers
// =============================================================================
type_specifier returns [string text]
    : INT
    {
        // Integer type specifier
        $text = "int";
        writeIntoParserLogFile("Line " + to_string($INT->getLine()) + ": type_specifier : INT\n\nint\n");
    }
    | FLOAT
    {
        // Floating point type specifier
        $text = "float";
        writeIntoParserLogFile("Line " + to_string($FLOAT->getLine()) + ": type_specifier : FLOAT\n\nfloat\n");
    }
    | VOID
    {
        // Void type specifier (for functions only)
        $text = "void";
        writeIntoParserLogFile("Line " + to_string($VOID->getLine()) + ": type_specifier : VOID\n\nvoid\n");
    }
    ;

// =============================================================================
// DECLARATION LISTS - Multiple variable/array declarations
// Handles comma-separated lists of variable declarations
// =============================================================================
declaration_list [string type] returns [string text, string code]
    : first=declaration_item[$type]
      {
        // Parse first declaration item and log the rule
        writeIntoParserLogFile("Line " + to_string($first.line) + ": declaration_list : " + $first.ruleName + "\n\n" + $first.text + "\n");
      }
      rest=declaration_list_tail[$type, $first.text]
    {
        // Combine first item with remaining items
        $text = $first.text + $rest.text;
        $code = $first.code + $rest.code;
    }
    ;

declaration_list_tail [string type, string builtSoFar] returns [string text, string code]
    : COMMA next=declaration_item[$type]
      {
        // Handle additional declaration items in the list
        string newList = builtSoFar + "," + $next.text;
        writeIntoParserLogFile("Line " + to_string($next.line) + ": declaration_list : declaration_list COMMA " + $next.ruleName + "\n\n" + newList + "\n");
      }
      rest=declaration_list_tail[$type, builtSoFar + "," + $next.text]
    {
        // Recursively build the comma-separated list
        $text = "," + $next.text + $rest.text;
        $code = $next.code + $rest.code;
    }
    |
    {
        // Empty tail - end of declaration list
        $text = "";
        $code = "";
    }
    ;

// =============================================================================
// DECLARATION ITEMS - Individual variable and array declarations
// Handles single variables, arrays, and error cases
// =============================================================================
declaration_item [string type] returns [string text, string ruleName, int line, string code]
    : id=ID
    {
        // Simple variable declaration
        $text = $id->getText();
        $ruleName = "ID";
        $line = $id->getLine();
        // Insert variable into symbol table with type information
        if (!symbolTable->Insert($id->getText(), "ID")) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
            $code = "";
        } else {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDeclaredType($type);  // Set the declared type (int, float, etc.)
                sym->setDataType("variable");  // Mark as variable (not array/function)
                // Check if this is a global variable by examining current scope
                if (symbolTable->getCurrentScope()->getParentScope() == nullptr) {
                    // Global variable - add to data segment
                    dataSegment += $id->getText() + " DW 1 DUP (0000H)\n";
                    $code = "";
                } else {
                    // Local variable - allocate stack space
                    sym->setOffset(currentLocalOffset);
                    currentLocalOffset += 2;  // 2 bytes for each variable
                    localVariableSpace += 2;  // Track space allocated for local variables
                    $code = "    SUB SP, 2\t; Line " + to_string($id->getLine()) + "\n";
                }
            } else {
                $code = "";
            }
        }
    }
    | id=ID ap=ADDOP ID
    {
        // Error case - malformed variable declaration with unexpected ADDOP
        $text = $id->getText();
        $ruleName = "ID";
        $line = $id->getLine();
        if (!symbolTable->Insert($id->getText(), "ID")) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
            $code = "";
        } else {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDeclaredType($type);
                sym->setDataType("variable");
                // Check if this is a global variable by examining current scope
                if (symbolTable->getCurrentScope()->getParentScope() == nullptr) {
                    // Global variable - add to data segment
                    dataSegment += $id->getText() + " DW 0\n";
                    $code = "";
                } else {
                    // Local variable - allocate stack space
                    sym->setOffset(currentLocalOffset);
                    currentLocalOffset += 2;
                    localVariableSpace += 2;  // Track space allocated for local variables
                    $code = "    SUB SP, 2\t; Line " + to_string($id->getLine()) + "\n";
                }
            } else {
                $code = "";
            }
        }
        // Report syntax error for unexpected ADDOP
        writeIntoErrorFile("Error at line " + to_string($ap->getLine()) + ": syntax error, unexpected " + "ADDOP" + ", expecting COMMA or SEMICOLON\n");
    }
    | id=ID LTHIRD ci=CONST_INT RTHIRD
    {
        // Array declaration with specified size
        $text = $id->getText() + "[" + $ci->getText() + "]";
        $ruleName = "ID LTHIRD CONST_INT RTHIRD";
        $line = $id->getLine();
        // Insert array into symbol table with size information
        if (!symbolTable->Insert($id->getText(), "ID")) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Multiple declaration of " + $id->getText() + "\n");
            $code = "";
        } else {
            auto sym = symbolTable->LookUp($id->getText());
            if (sym) {
                sym->setDeclaredType($type);  // Set the declared type (int, float, etc.)
                sym->setDataType("array");    // Mark as array type
                int size = stoi($ci->getText());  // Parse array size
                // Check if this is a global array by examining current scope
                if (symbolTable->getCurrentScope()->getParentScope() == nullptr) {
                    // Global array - add to data segment with specified size
                    dataSegment += $id->getText() + " DW " + to_string(size) + " DUP(0)\n";
                    $code = "";
                } else {
                    // Local array - allocate stack space based on size
                    sym->setOffset(currentLocalOffset);
                    currentLocalOffset += size * 2;  // 2 bytes per element
                    localVariableSpace += size * 2;  // Track space allocated for local arrays
                    $code = "    SUB SP, " + to_string(size * 2) + "\t; Line " + to_string($id->getLine()) + "\n";
                }
            } else {
                $code = "";
            }
        }
    }
    ;

// =============================================================================
// STATEMENT SEQUENCES - Multiple statements in sequence
// Handles sequential execution of statements within blocks
// =============================================================================
statements returns [string text, string code]
    : s=statement
    {
        // Single statement
        $text = $s.text;
        $code = $s.code;
        if (!$text.empty()) {
            writeIntoParserLogFile("Line " + to_string($s.stop->getLine()) + ": statements : statement\n\n" + $text + "\n");
        }
    }
    | sl=statements s=statement
    {
        // Multiple statements - accumulate text and code
        $text = $sl.text + "\n" + $s.text;
        $code = $sl.code + $s.code;
        if (!$s.text.empty()) {
            writeIntoParserLogFile("Line " + to_string($s.stop->getLine()) + ": statements : statements statement\n\n" + $text + "\n");
        }
    }
    ;

// =============================================================================
// STATEMENT TYPES - All possible statement constructs
// Handles variable declarations, expressions, control flow, I/O, and returns
// =============================================================================
statement returns [string text, string code]
    : v=var_declaration
    {
        // Variable declaration statement
        $text = $v.text;
        $code = $v.code;
        writeIntoParserLogFile("Line " + to_string($v.stop->getLine()) + ": statement : var_declaration\n\n" + $text + "\n");
    }

    | es=expression_statement
    {
        // Expression statement (assignments, function calls, etc.)
        $text = $es.text;
        $code = $es.code;
        if (!$text.empty()) {
            writeIntoParserLogFile("Line " + to_string($es.stop->getLine()) + ": statement : expression_statement\n\n" + $text + "\n");
        }
    }

    | cs=compound_statement
    {
        // Compound statement (block of statements)
        $text = $cs.text;
        $code = $cs.code;
        writeIntoParserLogFile("Line " + to_string($cs.stop->getLine()) + ": statement : compound_statement\n\n" + $text + "\n");
    }

    | FOR LPAREN forInit=expression_statement forCond=expression_statement forInc=expression RPAREN forBody=statement
    {
        // For loop with initialization, condition, increment, and body
        $text = "for(" + $forInit.text + $forCond.text + $forInc.text + ")" + $forBody.text;
        string startLabel = newLabel();  // Label for loop start
        string endLabel = newLabel();    // Label for loop exit
        $code = $forInit.code +          // Execute initialization
                startLabel + ":\n" +     // Loop start label
                $forCond.code +          // Evaluate condition
                "    CMP AX, 0\n    JE " + endLabel + "\n" +  // Exit if condition false
                $forBody.code +          // Execute loop body
                $forInc.code +           // Execute increment
                "    JMP " + startLabel + "\n" +  // Jump back to condition check
                endLabel + ":\n";        // Loop exit label
        writeIntoParserLogFile("Line " + to_string($forBody.stop->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + $text + "\n");
    }

    | IF LPAREN ifCond=expression RPAREN ifThen=statement
    {
        // If statement without else clause
        $text = "if(" + $ifCond.text + ")" + $ifThen.text;
        string endLabel = newLabel();    // Label for end of if statement
        $code = "; Line " + to_string($ifCond.start->getLine()) + "\n" +
                $ifCond.code +           // Evaluate condition
                "    CMP AX, 0\n    JE " + endLabel + "\n" +  // Skip if condition false
                $ifThen.code +           // Execute then clause
                endLabel + ":\n";        // End of if statement
        writeIntoParserLogFile("Line " + to_string($ifThen.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" + $text + "\n");
    }

    | IF LPAREN ifCond=expression RPAREN ifThen=statement ELSE ifElse=statement
    {
        // If statement with else clause
        $text = "if(" + $ifCond.text + ")" + $ifThen.text + "else " + $ifElse.text;
        string elseLabel = newLabel();   // Label for else clause
        string endLabel = newLabel();    // Label for end of if-else
        $code = "; Line " + to_string($ifCond.start->getLine()) + "\n" +
                $ifCond.code +           // Evaluate condition
                "    CMP AX, 0\n    JE " + elseLabel + "\n" +  // Jump to else if condition false
                $ifThen.code +           // Execute then clause
                "    JMP " + endLabel + "\n" +  // Skip else clause
                elseLabel + ":\n" +      // Else clause label
                $ifElse.code +           // Execute else clause
                endLabel + ":\n";        // End of if-else statement
        writeIntoParserLogFile("Line " + to_string($ifElse.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + $text + "\n");
    }

    | WHILE LPAREN whileCond=expression RPAREN whileBody=statement
    {
        // While loop with condition and body
        $text = "while(" + $whileCond.text + ")" + $whileBody.text;
        string startLabel = newLabel();  // Label for loop start
        string endLabel = newLabel();    // Label for loop exit
        $code = startLabel + ":\n" +     // Loop start label
                $whileCond.code +        // Evaluate condition
                "    CMP AX, 0\n    JE " + endLabel + "\n" +  // Exit if condition false
                $whileBody.code +        // Execute loop body
                "    JMP " + startLabel + "\n" +  // Jump back to condition check
                endLabel + ":\n";        // Loop exit label
        writeIntoParserLogFile("Line " + to_string($whileBody.stop->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + $text + "\n");
    }

    | PRINTLN LPAREN id=ID RPAREN SEMICOLON
    {
        // Print statement for variable output
        $text = "printf(" + $id->getText() + ");";
        string varAccess = getVarAccess($id->getText());  // Get variable access method
        hasPrintln = true;  // Mark that println is used (for procedure inclusion)
        $code = "    MOV AX, " + varAccess + "\t; Line " + to_string($id->getLine()) + "\n    CALL PRINT_OUTPUT\n    CALL NEW_LINE\n";
        writeIntoParserLogFile("Line " + to_string($PRINTLN->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" + $text + "\n");
        // Check if variable is declared and is printable
        auto sym = symbolTable->LookUp($id->getText());
        if (!sym) {
            writeIntoErrorFile("Error at line " + to_string($PRINTLN->getLine()) + ": Undeclared variable " + $id->getText() + "\n");
        } else if (sym->getDataType() != "variable" && sym->getDataType() != "array") {
            writeIntoErrorFile("Error at line " + to_string($PRINTLN->getLine()) + ": Cannot print non-variable type " + sym->getDeclaredType() + "\n");
        }
    }

    | RETURN expr=expression SEMICOLON
    {
        // Return statement with value - check return type compatibility
        $text = "return " + $expr.text + ";";
        string stackCleanup = "";
        if (localVariableSpace > 0) {
            stackCleanup = "    ADD SP, " + to_string(localVariableSpace) + "\n";  // Clean up local variables
        }
        $code = $expr.code + stackCleanup + "    POP BP\n    RET " + to_string(parameterCount * 2) + "\n";
        if (currentFunctionReturnType == "void") {
            writeIntoErrorFile("Error at line " + to_string($RETURN->getLine() + 1) + ": Cannot return value from function " + currentFunctionName + " with void return type\n");
        }
        writeIntoParserLogFile("Line " + to_string($RETURN->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + $text + "\n");
    }

    | RETURN SEMICOLON
    {
        // Return statement without value - valid for void functions
        $text = "return;";
        string stackCleanup = "";
        if (localVariableSpace > 0) {
            stackCleanup = "    ADD SP, " + to_string(localVariableSpace) + "\n";  // Clean up local variables
        }
        $code = stackCleanup + "    POP BP\n    RET " + to_string(parameterCount * 2) + "\n";
        writeIntoParserLogFile("Line " + to_string($RETURN->getLine()) + ": statement : RETURN SEMICOLON\n\n" + $text + "\n");
    }
    ;

// =============================================================================
// EXPRESSION STATEMENTS - Expressions terminated by semicolons
// Handles standalone expressions and empty statements
// =============================================================================
expression_statement returns [string text, string code]
    : sm=SEMICOLON
    {
        // Empty statement - just a semicolon
        $text = ";";
        $code = "";
        writeIntoParserLogFile("Line " + to_string($sm->getLine()) + ": expression_statement : SEMICOLON\n\n;\n");
    }
    | e=expression sm=SEMICOLON
    {
        // Expression followed by semicolon
        $text = $e.text + ";";
        $code = $e.code;
        writeIntoParserLogFile("Line " + to_string($sm->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + $text + "\n");
    }
    | e=expression
    {
        // Expression without semicolon (used in for loops)
        $text = "";
        $code = "";
    }
    ;

// =============================================================================
// VARIABLE USAGE - Variable and array element access
// Handles both simple variables and array indexing with type checking
// =============================================================================
variable returns [string text, vector<string> argTypes, string arrayName, string code]
    : id=ID
    {
        // Simple variable access
        $text = $id->getText();
        $argTypes.clear();
        $arrayName = "";
        $code = "    MOV AX, " + getVarAccess($id->getText()) + "\n";
        writeIntoParserLogFile("Line " + to_string($id->getLine()) + ": variable : ID\n\n" + $text + "\n");
        // Check if variable is declared and get its type
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
        // Array element access with index expression
        $text = $id->getText() + "[" + $e.text + "]";
        $argTypes.clear();
        $arrayName = $id->getText();

        auto sym = symbolTable->LookUp($id->getText());
        if (sym) {
            // Determine if this is a global or local array for proper addressing
            auto currentScope = symbolTable->getCurrentScope();
            auto globalScope = currentScope;
            while (globalScope->getParentScope() != nullptr) {
                globalScope = globalScope->getParentScope();
            }

            // Check if the symbol is found in the current scope or a parent scope
            auto tempScope = currentScope;
            bool isGlobalArray = false;
            while (tempScope != nullptr) {
                auto result = tempScope->LookUp($id->getText());
                if (result.first != nullptr) {
                    if (tempScope == globalScope) {
                        isGlobalArray = true;  // Found in global scope
                    }
                    break;
                }
                tempScope = tempScope->getParentScope();
            }

            if (isGlobalArray) {
                // Global array - use direct addressing with array name
                $code = $e.code +                    // Calculate index expression
                        "    MOV BX, AX\n    SHL BX, 1\n" +  // Convert to word offset
                        "    MOV AX, [" + $id->getText() + " + BX]\n";  // Load array element
            } else {
                // Local array - calculate address using 8086-compatible addressing
                int offset = sym->getOffset();
                if (offset > 0) {
                    // Positive offset (parameters)
                    $code = $e.code +                // Calculate index expression
                            "    MOV BX, AX\n    SHL BX, 1\n" +  // Convert to word offset
                            "    MOV SI, " + to_string(offset) + "\n" +  // Base offset
                            "    ADD SI, BX\n" +         // Add index offset
                            "    MOV AX, [BP + SI]\n";  // Load from [BP + SI]
                } else {
                    // Negative offset (local variables)
                    $code = $e.code +                // Calculate index expression
                            "    MOV BX, AX\n    SHL BX, 1\n" +  // Convert to word offset
                            "    MOV SI, " + to_string(abs(offset)) + "\n" +  // Base offset
                            "    SUB SI, BX\n" +         // Subtract index offset
                            "    NEG SI\n" +             // Make negative for [BP - SI]
                            "    MOV AX, [BP + SI]\n";  // Load from [BP + SI]
                }
            }
        } else {
            $code = $e.code + "    ; Error: Array not found\n";
        }
        writeIntoParserLogFile("Line " + to_string($id->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + $text + "\n");
        // Validate that identifier is actually an array
        auto symCheck = symbolTable->LookUp($id->getText());
        if (symCheck) {
            if (symCheck->getDataType() != "array") {
                writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": " + $id->getText() + " not an array\n");
            }
            $argTypes.push_back(symCheck->getDeclaredType());
        } else {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Undeclared array " + $id->getText() + "\n");
        }
        // Check that index expression is integer (not float)
        bool isFloat = $e.text.find('.') != string::npos;
        bool isNumeric = !$e.text.empty() && $e.text.find_first_not_of("0123456789.") == string::npos;
        if (isFloat && isNumeric) {
            writeIntoErrorFile("Error at line " + to_string($id->getLine()) + ": Expression inside third brackets not an integer\n");
        }
    }
    ;

// =============================================================================
// EXPRESSIONS - Assignment and logic expressions
// Handles variable assignments and logical operations
// =============================================================================
expression returns [string text, vector<string> argTypes, string code]
    : le=logic_expression
    {
        // Simple logic expression without assignment
        $text = $le.text;
        $argTypes = $le.argTypes;
        $code = $le.code;
        writeIntoParserLogFile("Line " + to_string($le.stop->getLine()) + ": expression : logic_expression\n\n" + $text + "\n");
    }

    | v=variable ao=ASSIGNOP
    {
        // Assignment expression - set flag for expression statement context
        isExpressionStatement = true;
    }
      le=logic_expression
    {
        // Complete assignment operation
        isExpressionStatement = false;
        $text = $v.text + "=" + $le.text;
        $argTypes.clear();

        string assignmentCode;
        if ($v.arrayName.empty()) {
            // Simple variable assignment
            string varAccess = getVarAccess($v.text);
            assignmentCode = "    MOV " + varAccess + ", AX\t; Line " + to_string($v.start->getLine()) + "\n";
        } else {
            // Array element assignment - need to generate store operation
            // The array access code is already in $v.code, but it loads the value
            // We need to modify it to store instead of load
            auto sym = symbolTable->LookUp($v.arrayName);
            if (sym) {
                // Determine if this is a global or local array for proper addressing
                auto currentScope = symbolTable->getCurrentScope();
                auto globalScope = currentScope;
                while (globalScope->getParentScope() != nullptr) {
                    globalScope = globalScope->getParentScope();
                }

                // Check if the symbol is found in the current scope or a parent scope
                auto tempScope = currentScope;
                bool isGlobalArray = false;
                while (tempScope != nullptr) {
                    auto result = tempScope->LookUp($v.arrayName);
                    if (result.first != nullptr) {
                        if (tempScope == globalScope) {
                            isGlobalArray = true;
                        }
                        break;
                    }
                    tempScope = tempScope->getParentScope();
                }

                string baseAddr;
                if (isGlobalArray) {
                    baseAddr = $v.arrayName;
                    // For array assignment, preserve the value while calculating index
                    // Extract index calculation code (remove the final MOV AX load)
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);
                    }
                    assignmentCode = "    PUSH AX\t; Save value to assign\n" +
                                   indexCode +                      // Calculate index in BX
                                   "    POP AX\t; Restore value to assign\n" +
                                   "    MOV [" + baseAddr + " + BX], AX\t; Line " + to_string($v.start->getLine()) + "\n";
                } else {
                    // Local array - calculate address using 8086-compatible addressing
                    int offset = sym->getOffset();
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);
                    }

                    assignmentCode = "    PUSH AX\t; Save value to assign\n" +
                                   indexCode +                      // Calculate address in SI
                                   "    POP AX\t; Restore value to assign\n" +
                                   "    MOV [BP + SI], AX\t; Line " + to_string($v.start->getLine()) + "\n";
                }
            } else {
                assignmentCode = "    ; Error: Array not found\n";
            }
        }

        $code = $le.code + assignmentCode;
        if ($le.text.find(' ') == std::string::npos) {
            writeIntoParserLogFile("Line " + to_string($ao->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + $text + "\n");
        } else {
            string trimmedText = $le.text;
            if (!trimmedText.empty() && trimmedText.back() == ' ') trimmedText.pop_back();
            writeIntoParserLogFile("Line " + to_string($le.stop->getLine() + 1) + ": expression : logic_expression\n\n" + trimmedText + "\n");
        }
        // Type checking for assignment compatibility
        auto sym = symbolTable->LookUp($v.text);
        if (!sym && !$v.arrayName.empty()) {
            sym = symbolTable->LookUp($v.arrayName);
        }
        if (sym) {
            if (sym->getDataType() == "array" && !$v.arrayName.empty()) {
                // Assignment to array element - check type compatibility
                string varType = sym->getDeclaredType();
                bool isFloatLiteral = $le.text.find('.') != string::npos;
                if (varType == "int" && isFloatLiteral && $le.text.find('%') == string::npos) {
                    writeIntoErrorFile("Error at line " + to_string($ao->getLine()) + ": Type Mismatch\n");
                }
            } else if (sym->getDataType() == "array") {
                writeIntoErrorFile("Error at line " + to_string($ao->getLine()) + ": Type mismatch, " + $v.text + " is an array\n");
            } else {
                // Assignment to simple variable - check type compatibility
                string varType = sym->getDeclaredType();
                bool isFloatLiteral = $le.text.find('.') != string::npos;
                if (varType == "int" && isFloatLiteral && $le.text.find('%') == string::npos) {
                    writeIntoErrorFile("Error at line " + to_string($ao->getLine()) + ": Type Mismatch\n");
                }
            }
        }
    }
    ;

// =============================================================================
// LOGICAL EXPRESSIONS - Logical AND/OR operations
// Handles && and || operators with short-circuit evaluation
// =============================================================================
logic_expression returns [string text, vector<string> argTypes, string code]
    : re=rel_expression
    {
        // Simple relational expression
        $text = $re.text;
        $code = $re.code;
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
        // Binary logical operation (AND/OR)
        $text = $l.text + $lo->getText() + $r.text;
        $argTypes.clear();
        if ($lo->getText() == "&&") {
            // Logical AND with short-circuit evaluation
            string falseLabel = newLabel();
            string endLabel = newLabel();
            $code = $l.code +                        // Evaluate left operand
                    "    CMP AX, 0\n    JE " + falseLabel + "\n" +  // If false, skip right operand
                    $r.code +                        // Evaluate right operand
                    "    CMP AX, 0\n    JE " + falseLabel + "\n" +  // If false, result is false
                    "    MOV AX, 1\n    JMP " + endLabel + "\n" +   // Both true, result is true
                    falseLabel + ":\n    MOV AX, 0\n" +             // Result is false
                    endLabel + ":\n";
        } else { // ||
            // Logical OR with short-circuit evaluation
            string trueLabel = newLabel();
            string endLabel = newLabel();
            $code = $l.code +                        // Evaluate left operand
                    "    CMP AX, 0\n    JNE " + trueLabel + "\n" +  // If true, skip right operand
                    $r.code +                        // Evaluate right operand
                    "    CMP AX, 0\n    JNE " + trueLabel + "\n" +  // If true, result is true
                    "    MOV AX, 0\n    JMP " + endLabel + "\n" +   // Both false, result is false
                    trueLabel + ":\n    MOV AX, 1\n" +              // Result is true
                    endLabel + ":\n";
        }
        writeIntoParserLogFile("Line " + to_string($lo->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" + $text + "\n");
    }
    ;

// =============================================================================
// RELATIONAL EXPRESSIONS - Comparison operations
// Handles <, >, <=, >=, ==, != operators
// =============================================================================
rel_expression returns [string text, vector<string> argTypes, string code]
    : se=simple_expression
    {
        // Simple arithmetic expression
        $text = $se.text;
        $code = $se.code;
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
        // Binary relational comparison operation
        $text = $l.text + $ro->getText() + $r.text;
        $argTypes.clear();
        string trueLabel = newLabel();   // Label for true result
        string endLabel = newLabel();    // Label for end of comparison
        $code = $l.code +                // Evaluate left operand
                "    PUSH AX\n" +         // Save left operand
                $r.code +                // Evaluate right operand
                "    POP BX\n    CMP BX, AX\n";  // Compare left (BX) with right (AX)

        // Generate appropriate jump instruction based on comparison operator
        if ($ro->getText() == "<") $code += "    JL ";
        else if ($ro->getText() == ">") $code += "    JG ";
        else if ($ro->getText() == "==") $code += "    JE ";
        else if ($ro->getText() == "!=") $code += "    JNE ";
        else if ($ro->getText() == "<=") $code += "    JLE ";
        else if ($ro->getText() == ">=") $code += "    JGE ";

        $code += trueLabel + "\n    MOV AX, 0\n    JMP " + endLabel + "\n" +  // False case
                 trueLabel + ":\n    MOV AX, 1\n" +                           // True case
                 endLabel + ":\n";
        writeIntoParserLogFile("Line " + to_string($ro->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" + $text + "\n");
    }
    ;

// =============================================================================
// SIMPLE EXPRESSIONS - Addition and subtraction operations
// Handles + and - operators with left-associativity
// =============================================================================
simple_expression returns [string text, vector<string> argTypes, string code]
    : t=term
    {
        // Single term (no addition/subtraction)
        $text = $t.text;
        $code = $t.code;
        $argTypes = $t.argTypes;
        writeIntoParserLogFile("Line " + to_string($t.stop->getLine()) + ": simple_expression : term\n\n" + $text + "\n");
    }

    | se=simple_expression ao=ADDOP t=term
    {
        // Binary addition or subtraction operation
        $text = $se.text + $ao->getText() + $t.text;
        $argTypes = $t.argTypes;
        $code = $se.code +               // Evaluate left operand
                "    PUSH AX\n" +         // Save left operand
                $t.code +                // Evaluate right operand
                "    POP BX\n" +          // Restore left operand to BX
                ($ao->getText() == "+" ? "    ADD" : "    SUB") + " BX, AX\n    MOV AX, BX\n";  // Perform operation
        writeIntoParserLogFile("Line " + to_string($ao->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" + $text + "\n");
    }

    | se=simple_expression ao=ADDOP as=ASSIGNOP
    {
        // Error case - unexpected ASSIGNOP after ADDOP
        writeIntoErrorFile("Error at line " + to_string($as->getLine()) + ": syntax error, unexpected " + "ASSIGNOP" + "\n");
    }
      t=term h=HASH
    {
        // Error recovery with unrecognized character
        $text = $t.text + " ";
        $code = $t.code;
        writeIntoErrorFile("Error at line " + to_string($h->getLine()) + ": Unrecognized character " + $h->getText() + "\n");
        writeIntoParserLogFile("Line " + to_string($h->getLine() + 1) + ": simple_expression : term\n\n" + $t.text + "\n");
    }
    ;

// =============================================================================
// TERMS - Multiplication, division, and modulus operations
// Handles *, /, and % operators with left-associativity and higher precedence
// =============================================================================
term returns [string text, vector<string> argTypes, string code]
    : ue=unary_expression
    {
        // Single unary expression (no multiplication/division/modulus)
        $text = $ue.text;
        $code = $ue.code;
        $argTypes = $ue.argTypes;
        writeIntoParserLogFile("Line " + to_string($ue.stop->getLine()) + ": term : unary_expression\n\n" + $text + "\n");
    }

    | t=term mo=MULOP ue=unary_expression
    {
        // Binary multiplication, division, or modulus operation
        $text = $t.text + $mo->getText() + $ue.text;
        $argTypes.clear();
        $code = $t.code +                // Evaluate left operand
                "    PUSH AX\n" +         // Save left operand
                $ue.code +               // Evaluate right operand
                "    MOV BX, AX\n" +      // Move right operand to BX
                "    POP AX\n";           // Restore left operand to AX

        // Generate appropriate assembly instruction based on operator
        if ($mo->getText() == "*") {
            $code += "    XOR DX, DX\n    MUL BX\n";  // Unsigned multiplication
        } else if ($mo->getText() == "/") {
            $code += "    XOR DX, DX\n    DIV BX\n";  // Unsigned division (quotient in AX)
        } else { // %
            $code += "    XOR DX, DX\n    DIV BX\n    MOV AX, DX\n";  // Modulus (remainder in DX)
        }
        writeIntoParserLogFile("Line " + to_string($mo->getLine()) + ": term : term MULOP unary_expression\n\n" + $text + "\n");

        // Error checking for division/modulus by zero and type compatibility
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

// =============================================================================
// UNARY EXPRESSIONS - Unary operators and prefix increment/decrement
// Handles +, -, !, ++var, --var, and factor expressions
// =============================================================================
unary_expression returns [string text, vector<string> argTypes, string code]
    : ao=ADDOP ue=unary_expression
    {
        // Unary plus or minus operation
        $text = $ao->getText() + $ue.text;
        $argTypes = $ue.argTypes;
        $code = $ue.code;
        if ($ao->getText() == "-") $code += "    NEG AX\n";  // Negate for unary minus
        // Note: Unary plus does nothing, so no additional assembly needed
        writeIntoParserLogFile("Line " + to_string($ao->getLine()) + ": unary_expression : ADDOP unary_expression\n\n" + $text + "\n");
    }

    | n=NOT ue=unary_expression
    {
        // Logical NOT operation
        $text = "!" + $ue.text;
        $argTypes = $ue.argTypes;
        $code = $ue.code + "    CMP AX, 0\n    MOV AX, 0\n    SETZ AL\n";  // Set AL to 1 if AX was 0
        writeIntoParserLogFile("Line " + to_string($n->getLine()) + ": unary_expression : NOT unary_expression\n\n" + $text + "\n");
    }

    | io=INCOP v=variable
    {
        // Pre-increment operation (++var)
        $text = "++" + $v.text;
        if ($v.arrayName.empty()) {
            // Simple variable pre-increment
            string varAccess = getVarAccess($v.text);
            $code = "    INC " + varAccess + "\n    MOV AX, " + varAccess + "\n";
        } else {
            // Array element pre-increment - need special handling for global vs local arrays
            auto sym = symbolTable->LookUp($v.arrayName);
            if (sym) {
                // Determine if this is a global or local array
                auto currentScope = symbolTable->getCurrentScope();
                auto globalScope = currentScope;
                while (globalScope->getParentScope() != nullptr) {
                    globalScope = globalScope->getParentScope();
                }

                auto tempScope = currentScope;
                bool isGlobalArray = false;
                while (tempScope != nullptr) {
                    auto result = tempScope->LookUp($v.arrayName);
                    if (result.first != nullptr) {
                        if (tempScope == globalScope) {
                            isGlobalArray = true;
                        }
                        break;
                    }
                    tempScope = tempScope->getParentScope();
                }

                if (isGlobalArray) {
                    // Global array pre-increment
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);  // Remove the load instruction
                    }
                    $code = indexCode +                              // Calculate index in BX
                            "    INC WORD PTR [" + $v.arrayName + " + BX]\n" +  // Increment array element
                            "    MOV AX, [" + $v.arrayName + " + BX]\n";        // Load incremented value
                } else {
                    // Local array pre-increment
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);  // Remove the load instruction
                    }
                    $code = indexCode +                              // Calculate address in SI
                            "    INC WORD PTR [BP + SI]\n" +         // Increment array element
                            "    MOV AX, [BP + SI]\n";               // Load incremented value
                }
            } else {
                $code = "    ; Error: Array not found\n";
            }
        }
        $argTypes = $v.argTypes;
        writeIntoParserLogFile("Line " + to_string($io->getLine()) + ": unary_expression : INCOP variable\n\n" + $text + "\n");
    }

    | doo=DECOP v=variable
    {
        // Pre-decrement operation (--var)
        $text = "--" + $v.text;
        if ($v.arrayName.empty()) {
            // Simple variable pre-decrement
            string varAccess = getVarAccess($v.text);
            $code = "    DEC " + varAccess + "\n    MOV AX, " + varAccess + "\n";
        } else {
            // Array element pre-decrement - need special handling for global vs local arrays
            auto sym = symbolTable->LookUp($v.arrayName);
            if (sym) {
                // Determine if this is a global or local array
                auto currentScope = symbolTable->getCurrentScope();
                auto globalScope = currentScope;
                while (globalScope->getParentScope() != nullptr) {
                    globalScope = globalScope->getParentScope();
                }

                auto tempScope = currentScope;
                bool isGlobalArray = false;
                while (tempScope != nullptr) {
                    auto result = tempScope->LookUp($v.arrayName);
                    if (result.first != nullptr) {
                        if (tempScope == globalScope) {
                            isGlobalArray = true;
                        }
                        break;
                    }
                    tempScope = tempScope->getParentScope();
                }

                if (isGlobalArray) {
                    // Global array pre-decrement
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);  // Remove the load instruction
                    }
                    $code = indexCode +                              // Calculate index in BX
                            "    DEC WORD PTR [" + $v.arrayName + " + BX]\n" +  // Decrement array element
                            "    MOV AX, [" + $v.arrayName + " + BX]\n";        // Load decremented value
                } else {
                    // Local array pre-decrement
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);  // Remove the load instruction
                    }
                    $code = indexCode +                              // Calculate address in SI
                            "    DEC WORD PTR [BP + SI]\n" +         // Decrement array element
                            "    MOV AX, [BP + SI]\n";               // Load decremented value
                }
            } else {
                $code = "    ; Error: Array not found\n";
            }
        }
        $argTypes = $v.argTypes;
        writeIntoParserLogFile("Line " + to_string($doo->getLine()) + ": unary_expression : DECOP variable\n\n" + $text + "\n");
    }

    | f=factor
    {
        // Factor expression (highest precedence)
        $text = $f.text;
        $code = $f.code;
        $argTypes = $f.argTypes;
        writeIntoParserLogFile("Line " + to_string($f.stop->getLine()) + ": unary_expression : factor\n\n" + $text + "\n");
    }
    ;

// =============================================================================
// FACTORS - Primary expressions and postfix operations
// Handles variables, function calls, literals, parenthesized expressions, and postfix increment/decrement
// =============================================================================
factor returns [string text, vector<string> argTypes, string code]
    : v=variable
    {
        // Variable or array element access
        $text = $v.text;
        $code = $v.code;
        $argTypes.clear();
        writeIntoParserLogFile("Line " + to_string($v.stop->getLine()) + ": factor : variable\n\n" + $text + "\n");
    }

    | id=ID LPAREN al=argument_list RPAREN
    {
        // Function call: check for declaration, argument count/type, void-in-expression
        $text = $id->getText() + "(" + $al.text + ")";
        $code = $al.code + "    CALL " + $id->getText() + "\n";
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
        $code = $e.code;
        $argTypes = $e.argTypes;
        writeIntoParserLogFile("Line " + to_string($lp->getLine()) + ": factor : LPAREN expression RPAREN\n\n" + $text + "\n");
    }

    | ci=CONST_INT
    {
        // Integer literal constant
        $text = $ci->getText();
        $code = "    MOV AX, " + $ci->getText() + "\n";  // Load integer constant directly into AX register
        $argTypes.clear();
        $argTypes.push_back("int");
        writeIntoParserLogFile("Line " + to_string($ci->getLine()) + ": factor : CONST_INT\n\n" + $text + "\n");
    }

    | cf=CONST_FLOAT
    {
        // Float literal constant (simplified assembly generation)
        $text = $cf->getText();
        $code = "    MOV AX, " + $cf->getText() + "\n";  // Basic assembly for float (simplified for this implementation)
        $argTypes.clear();
        $argTypes.push_back("float");
        writeIntoParserLogFile("Line " + to_string($cf->getLine()) + ": factor : CONST_FLOAT\n\n" + $text + "\n");
    }

    | v=variable io=INCOP
    {
        // Post-increment operation (variable++)
        // Returns the original value before incrementing
        $text = $v.text + "++";
        if ($v.arrayName.empty()) {
            // Simple variable post-increment
            string varAccess = getVarAccess($v.text);
            $code = "    MOV AX, " + varAccess + "\n    INC " + varAccess + "\n";
        } else {
            // Array element post-increment - need special handling for global vs local arrays
            auto sym = symbolTable->LookUp($v.arrayName);
            if (sym) {
                // Determine if this is a global or local array by traversing scope hierarchy
                auto currentScope = symbolTable->getCurrentScope();
                auto globalScope = currentScope;
                while (globalScope->getParentScope() != nullptr) {
                    globalScope = globalScope->getParentScope();
                }

                auto tempScope = currentScope;
                bool isGlobalArray = false;
                while (tempScope != nullptr) {
                    auto result = tempScope->LookUp($v.arrayName);
                    if (result.first != nullptr) {
                        if (tempScope == globalScope) {
                            isGlobalArray = true;
                        }
                        break;
                    }
                    tempScope = tempScope->getParentScope();
                }

                if (isGlobalArray) {
                    // Global array post-increment using direct memory addressing
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);  // Remove the load instruction
                    }
                    $code = indexCode +
                            "    MOV AX, [" + $v.arrayName + " + BX]\n" +      // Load original value
                            "    INC WORD PTR [" + $v.arrayName + " + BX]\n";  // Increment array element
                } else {
                    // Local array post-increment using stack-based addressing
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);  // Remove the load instruction
                    }
                    $code = indexCode +
                            "    MOV AX, [BP + SI]\n" +                       // Load original value
                            "    INC WORD PTR [BP + SI]\n";                   // Increment array element
                }
            } else {
                $code = "    ; Error: Array not found\n";
            }
        }
        $argTypes = $v.argTypes;
        writeIntoParserLogFile("Line " + to_string($io->getLine()) + ": factor : variable INCOP\n\n" + $text + "\n");
    }

    | v=variable doo=DECOP
    {
        // Post-decrement operation (variable--)
        // Returns the original value before decrementing
        $text = $v.text + "--";
        if ($v.arrayName.empty()) {
            // Simple variable post-decrement
            string varAccess = getVarAccess($v.text);
            $code = "    MOV AX, " + varAccess + "\n    DEC " + varAccess + "\n";
        } else {
            // Array element post-decrement - need special handling for global vs local arrays
            auto sym = symbolTable->LookUp($v.arrayName);
            if (sym) {
                // Determine if this is a global or local array by traversing scope hierarchy
                auto currentScope = symbolTable->getCurrentScope();
                auto globalScope = currentScope;
                while (globalScope->getParentScope() != nullptr) {
                    globalScope = globalScope->getParentScope();
                }

                auto tempScope = currentScope;
                bool isGlobalArray = false;
                while (tempScope != nullptr) {
                    auto result = tempScope->LookUp($v.arrayName);
                    if (result.first != nullptr) {
                        if (tempScope == globalScope) {
                            isGlobalArray = true;
                        }
                        break;
                    }
                    tempScope = tempScope->getParentScope();
                }

                if (isGlobalArray) {
                    // Global array post-decrement using direct memory addressing
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);  // Remove the load instruction
                    }
                    $code = indexCode +
                            "    MOV AX, [" + $v.arrayName + " + BX]\n" +      // Load original value
                            "    DEC WORD PTR [" + $v.arrayName + " + BX]\n";  // Decrement array element
                } else {
                    // Local array post-decrement using stack-based addressing
                    string indexCode = $v.code;
                    size_t lastMovPos = indexCode.rfind("MOV AX, [");
                    if (lastMovPos != string::npos) {
                        indexCode = indexCode.substr(0, lastMovPos);  // Remove the load instruction
                    }
                    $code = indexCode +
                            "    MOV AX, [BP + SI]\n" +                       // Load original value
                            "    DEC WORD PTR [BP + SI]\n";                   // Decrement array element
                }
            } else {
                $code = "    ; Error: Array not found\n";
            }
        }
        $argTypes = $v.argTypes;
        writeIntoParserLogFile("Line " + to_string($doo->getLine()) + ": factor : variable DECOP\n\n" + $text + "\n");
    }
    ;


/*
 * ============================================================================
 * FUNCTION CALL SUPPORT RULES
 * ============================================================================
 * These rules handle function call argument parsing and validation
 */

// Argument list for function calls
// Handles both empty argument lists and those with actual arguments
argument_list returns [string text, vector<string> argTypes, vector<string> argNames, string code]
    : a=arguments
    {
        // Non-empty argument list - delegate to arguments rule
        $text = $a.text;
        $code = $a.code;
        $argTypes = $a.argTypes;
        $argNames = $a.argNames;
        writeIntoParserLogFile("Line " + to_string($a.stop->getLine()) + ": argument_list : arguments\n\n" + $text + "\n");
    }
    |
    {
        // Empty argument list (function called with no parameters)
        $text = "";
        $code = "";
        $argTypes.clear();
        $argNames.clear();
    }
    ;


// Arguments for function calls (recursive for multiple arguments)
// Handles comma-separated list of expressions passed as function parameters
arguments returns [string text, vector<string> argTypes, vector<string> argNames, string code]
    : le=logic_expression
    {
        // Single argument - evaluate expression and push to stack
        $text = $le.text;
        $code = $le.code + "    PUSH AX\n";  // Push evaluated expression result onto stack for function call

        // Determine argument type and name for semantic checking
        string argType = "int";  // Default type
        string argName = $le.text;
        auto sym = symbolTable->LookUp($le.text);
        if (sym) {
            // Symbol found - use its declared type, but check for arrays
            argType = sym->getDataType() == "array" ? "array" : sym->getDeclaredType();
        } else if ($le.text.find('.') != string::npos) {
            // Float literal detection (simple heuristic)
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
        // Multiple arguments - recursive case for comma-separated arguments
        $text = $a.text + "," + $le.text;
        $code = $a.code + $le.code + "    PUSH AX\n";  // Evaluate and push each argument in order

        // Determine type and name for this additional argument
        string argType = "int";  // Default type
        string argName = $le.text;
        auto sym = symbolTable->LookUp($le.text);
        if (sym) {
            // Symbol found - use its declared type, but check for arrays
            argType = sym->getDataType() == "array" ? "array" : sym->getDeclaredType();
        } else if ($le.text.find('.') != string::npos) {
            // Float literal detection (simple heuristic)
            argType = "float";
        }

        // Append to existing argument lists (accumulated from previous arguments)
        $argTypes = $a.argTypes;
        $argTypes.push_back(argType);
        $argNames = $a.argNames;
        $argNames.push_back(argName);
        writeIntoParserLogFile("Line " + to_string($le.stop->getLine()) + ": arguments : arguments COMMA logic_expression\n\n" + $text + "\n");
    }
    ;
