
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
    extern ofstream tempCodeFile; // Temporary file stream for on-the-fly code generation

    extern int syntaxErrorCount;
    extern SymbolTable *symbolTable;


// Generated from C2105017Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C2105017Parser : public antlr4::Parser {
public:
  enum {
    IF = 1, ELSE = 2, FOR = 3, WHILE = 4, DO = 5, SWITCH = 6, CASE = 7, 
    DEFAULT = 8, BREAK = 9, CONTINUE = 10, RETURN = 11, PRINTLN = 12, INT = 13, 
    FLOAT = 14, CHAR = 15, DOUBLE = 16, VOID = 17, LONG = 18, SHORT = 19, 
    STATIC = 20, UNSIGNED = 21, GOTO = 22, ADDOP = 23, MULOP = 24, INCOP = 25, 
    DECOP = 26, RELOP = 27, LOGICOP = 28, ASSIGNOP = 29, BITOP = 30, NOT = 31, 
    LPAREN = 32, RPAREN = 33, LCURL = 34, RCURL = 35, LTHIRD = 36, RTHIRD = 37, 
    COMMA = 38, SEMICOLON = 39, ID = 40, CONST_INT = 41, CONST_FLOAT = 42, 
    HASH = 43, SINGLE_QUOTE = 44, CHAR_EMPTY = 45, CHAR_CLOSE = 46, CHAR_ERROR_NL = 47, 
    DOUBLE_QUOTE = 48, STR_CLOSE = 49, STR_NL_ERROR = 50, LINE_COMMENT = 51, 
    BLOCK_COMMENT = 52, WS = 53, NL = 54, UNRECOGNIZED = 55
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleFunc_declaration = 3, 
    RuleFunc_definition = 4, RuleParameter_list = 5, RuleCompound_statement = 6, 
    RuleVar_declaration = 7, RuleType_specifier = 8, RuleDeclaration_list = 9, 
    RuleDeclaration_list_tail = 10, RuleDeclaration_item = 11, RuleStatements = 12, 
    RuleStatement = 13, RuleExpression_statement = 14, RuleVariable = 15, 
    RuleExpression = 16, RuleLogic_expression = 17, RuleRel_expression = 18, 
    RuleSimple_expression = 19, RuleTerm = 20, RuleUnary_expression = 21, 
    RuleFactor = 22, RuleArgument_list = 23, RuleArguments = 24
  };

  explicit C2105017Parser(antlr4::TokenStream *input);

  C2105017Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C2105017Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


      // =============================================================================
      // ASSEMBLY CODE GENERATION - Core assembly output management
      // Generates 8086 assembly code from parsed C-like input
      // =============================================================================
      string assemblyCode = ".MODEL SMALL\n\n.STACK 1000H\n\n";
      string dataSegment = ".DATA\n\n";
      int labelCount = 0;
      int currentLocalOffset = 2;
      int localVariableSpace = 0;
      int parameterCount = 0;
      bool hasPrintln = false;

      string newLabel() { return "L" + to_string(labelCount++); }

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
                      return string("[BP ") + (sym->getIsParameter() ? "+ " : "- ") + to_string(abs(sym->getOffset())) + "]";
                  }
              }
              tempScope = tempScope->getParentScope();
          }

          // Fallback (should not reach here)
          return "[" + name + "]";
      }

      // =============================================================================
      // ARRAY SCOPE CHECKING - Determines if array is global or local
      // Checks if an array is declared in global or local scope
      // =============================================================================
      bool isGlobalArray(string arrayName) {
          auto currentScope = symbolTable->getCurrentScope();
          auto globalScope = currentScope;
          while (globalScope->getParentScope() != nullptr) {
              globalScope = globalScope->getParentScope();
          }

          // Check if the symbol is found in the current scope or a parent scope
          auto tempScope = currentScope;
          while (tempScope != nullptr) {
              auto result = tempScope->LookUp(arrayName);
              if (result.first != nullptr) {
                  if (tempScope == globalScope) {
                      return true;  // Found in global scope
                  }
                  break;
              }
              tempScope = tempScope->getParentScope();
          }
          return false;  // Not found in global scope
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
      bool isAssignmentContext = false;

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
      map<string, vector<string>> functionParamTypes;


  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Parameter_listContext;
  class Compound_statementContext;
  class Var_declarationContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class Declaration_list_tailContext;
  class Declaration_itemContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105017Parser::ProgramContext *p = nullptr;
    C2105017Parser::UnitContext *u = nullptr;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105017Parser::Var_declarationContext *v = nullptr;
    C2105017Parser::Func_declarationContext *f = nullptr;
    C2105017Parser::Func_definitionContext *fd = nullptr;
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnitContext* unit();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105017Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *sm = nullptr;
    C2105017Parser::Parameter_listContext *pl = nullptr;
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105017Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *lp = nullptr;
    antlr4::Token *rp = nullptr;
    C2105017Parser::Compound_statementContext *cs = nullptr;
    C2105017Parser::Parameter_listContext *pl = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_definitionContext* func_definition();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105017Parser::Parameter_listContext *pl = nullptr;
    C2105017Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *id = nullptr;
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COMMA();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    string text;
    antlr4::Token *lc = nullptr;
    antlr4::Token *rc = nullptr;
    C2105017Parser::StatementsContext *s = nullptr;
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105017Parser::Type_specifierContext *t = nullptr;
    C2105017Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *sm = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    string text;
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *voidToken = nullptr;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    string type;
    string text;
    C2105017Parser::Declaration_itemContext *first = nullptr;
    C2105017Parser::Declaration_list_tailContext *rest = nullptr;
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState, string type);
    virtual size_t getRuleIndex() const override;
    Declaration_itemContext *declaration_item();
    Declaration_list_tailContext *declaration_list_tail();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_listContext* declaration_list(string type);

  class  Declaration_list_tailContext : public antlr4::ParserRuleContext {
  public:
    string type;
    string builtSoFar;
    string text;
    C2105017Parser::Declaration_itemContext *next = nullptr;
    C2105017Parser::Declaration_list_tailContext *rest = nullptr;
    Declaration_list_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    Declaration_list_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState, string type, string builtSoFar);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    Declaration_itemContext *declaration_item();
    Declaration_list_tailContext *declaration_list_tail();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_list_tailContext* declaration_list_tail(string type,string builtSoFar);

  class  Declaration_itemContext : public antlr4::ParserRuleContext {
  public:
    string type;
    string text;
    string ruleName;
    int line;
    antlr4::Token *id = nullptr;
    antlr4::Token *ci = nullptr;
    C2105017Parser::Logic_expressionContext *init = nullptr;
    Declaration_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    Declaration_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState, string type);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *RTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *ASSIGNOP();
    Logic_expressionContext *logic_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_itemContext* declaration_item(string type);

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105017Parser::StatementsContext *sl = nullptr;
    C2105017Parser::StatementContext *s = nullptr;
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    string text;
    C2105017Parser::Var_declarationContext *v = nullptr;
    C2105017Parser::Expression_statementContext *es = nullptr;
    C2105017Parser::Compound_statementContext *cs = nullptr;
    C2105017Parser::Expression_statementContext *forInit = nullptr;
    C2105017Parser::Expression_statementContext *forCond = nullptr;
    C2105017Parser::ExpressionContext *forInc = nullptr;
    C2105017Parser::StatementContext *forBody = nullptr;
    C2105017Parser::ExpressionContext *ifCond = nullptr;
    C2105017Parser::StatementContext *ifThen = nullptr;
    C2105017Parser::StatementContext *ifElse = nullptr;
    C2105017Parser::ExpressionContext *whileCond = nullptr;
    C2105017Parser::StatementContext *whileBody = nullptr;
    antlr4::Token *printlnToken = nullptr;
    antlr4::Token *id = nullptr;
    C2105017Parser::ExpressionContext *index = nullptr;
    antlr4::Token *returnToken = nullptr;
    C2105017Parser::ExpressionContext *expr = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *RTHIRD();
    antlr4::tree::TerminalNode *RETURN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    string text;
    antlr4::Token *sm = nullptr;
    C2105017Parser::ExpressionContext *e = nullptr;
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    string arrayName;
    antlr4::Token *id = nullptr;
    C2105017Parser::ExpressionContext *e = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *RTHIRD();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    C2105017Parser::Logic_expressionContext *le = nullptr;
    C2105017Parser::VariableContext *v = nullptr;
    antlr4::Token *ao = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGNOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    C2105017Parser::Rel_expressionContext *re = nullptr;
    C2105017Parser::Rel_expressionContext *l = nullptr;
    antlr4::Token *lo = nullptr;
    C2105017Parser::Rel_expressionContext *r = nullptr;
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    C2105017Parser::Simple_expressionContext *se = nullptr;
    C2105017Parser::Simple_expressionContext *l = nullptr;
    antlr4::Token *ro = nullptr;
    C2105017Parser::Simple_expressionContext *r = nullptr;
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    C2105017Parser::Simple_expressionContext *se = nullptr;
    C2105017Parser::TermContext *t = nullptr;
    antlr4::Token *ao = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    Simple_expressionContext *simple_expression();
    antlr4::tree::TerminalNode *ADDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    C2105017Parser::TermContext *t = nullptr;
    C2105017Parser::Unary_expressionContext *ue = nullptr;
    antlr4::Token *mo = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    TermContext *term();
    antlr4::tree::TerminalNode *MULOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    antlr4::Token *ao = nullptr;
    C2105017Parser::Unary_expressionContext *ue = nullptr;
    antlr4::Token *n = nullptr;
    antlr4::Token *io = nullptr;
    C2105017Parser::VariableContext *v = nullptr;
    antlr4::Token *doo = nullptr;
    C2105017Parser::FactorContext *f = nullptr;
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *INCOP();
    VariableContext *variable();
    antlr4::tree::TerminalNode *DECOP();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    C2105017Parser::VariableContext *v = nullptr;
    antlr4::Token *id = nullptr;
    C2105017Parser::Argument_listContext *al = nullptr;
    antlr4::Token *lp = nullptr;
    C2105017Parser::ExpressionContext *e = nullptr;
    antlr4::Token *rp = nullptr;
    antlr4::Token *ci = nullptr;
    antlr4::Token *cf = nullptr;
    antlr4::Token *io = nullptr;
    antlr4::Token *doo = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *ID();
    Argument_listContext *argument_list();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *CONST_FLOAT();
    antlr4::tree::TerminalNode *INCOP();
    antlr4::tree::TerminalNode *DECOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    vector<string> argNames;
    C2105017Parser::ArgumentsContext *a = nullptr;
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    string text;
    vector<string> argTypes;
    vector<string> argNames;
    C2105017Parser::ArgumentsContext *a = nullptr;
    C2105017Parser::Logic_expressionContext *le = nullptr;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *COMMA();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

