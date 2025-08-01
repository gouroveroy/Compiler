
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    extern ofstream lexLogFile;
    extern ofstream errorFile;


// Generated from C2105017Lexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C2105017Lexer : public antlr4::Lexer {
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
    CHAR_MODE = 1, STRING_MODE = 2
  };

  explicit C2105017Lexer(antlr4::CharStream *input);

  ~C2105017Lexer() override;


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


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void IFAction(antlr4::RuleContext *context, size_t actionIndex);
  void ELSEAction(antlr4::RuleContext *context, size_t actionIndex);
  void FORAction(antlr4::RuleContext *context, size_t actionIndex);
  void WHILEAction(antlr4::RuleContext *context, size_t actionIndex);
  void DOAction(antlr4::RuleContext *context, size_t actionIndex);
  void SWITCHAction(antlr4::RuleContext *context, size_t actionIndex);
  void CASEAction(antlr4::RuleContext *context, size_t actionIndex);
  void DEFAULTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BREAKAction(antlr4::RuleContext *context, size_t actionIndex);
  void CONTINUEAction(antlr4::RuleContext *context, size_t actionIndex);
  void RETURNAction(antlr4::RuleContext *context, size_t actionIndex);
  void PRINTLNAction(antlr4::RuleContext *context, size_t actionIndex);
  void INTAction(antlr4::RuleContext *context, size_t actionIndex);
  void FLOATAction(antlr4::RuleContext *context, size_t actionIndex);
  void CHARAction(antlr4::RuleContext *context, size_t actionIndex);
  void DOUBLEAction(antlr4::RuleContext *context, size_t actionIndex);
  void VOIDAction(antlr4::RuleContext *context, size_t actionIndex);
  void LONGAction(antlr4::RuleContext *context, size_t actionIndex);
  void SHORTAction(antlr4::RuleContext *context, size_t actionIndex);
  void STATICAction(antlr4::RuleContext *context, size_t actionIndex);
  void UNSIGNEDAction(antlr4::RuleContext *context, size_t actionIndex);
  void GOTOAction(antlr4::RuleContext *context, size_t actionIndex);
  void ADDOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void MULOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void INCOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void DECOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void RELOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void LOGICOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void ASSIGNOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void BITOPAction(antlr4::RuleContext *context, size_t actionIndex);
  void NOTAction(antlr4::RuleContext *context, size_t actionIndex);
  void LPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void RPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void LCURLAction(antlr4::RuleContext *context, size_t actionIndex);
  void RCURLAction(antlr4::RuleContext *context, size_t actionIndex);
  void LTHIRDAction(antlr4::RuleContext *context, size_t actionIndex);
  void RTHIRDAction(antlr4::RuleContext *context, size_t actionIndex);
  void COMMAAction(antlr4::RuleContext *context, size_t actionIndex);
  void SEMICOLONAction(antlr4::RuleContext *context, size_t actionIndex);
  void IDAction(antlr4::RuleContext *context, size_t actionIndex);
  void CONST_INTAction(antlr4::RuleContext *context, size_t actionIndex);
  void CONST_FLOATAction(antlr4::RuleContext *context, size_t actionIndex);
  void CHAR_EMPTYAction(antlr4::RuleContext *context, size_t actionIndex);
  void CHAR_CLOSEAction(antlr4::RuleContext *context, size_t actionIndex);
  void CHAR_ESC_NLAction(antlr4::RuleContext *context, size_t actionIndex);
  void CHAR_ERROR_NLAction(antlr4::RuleContext *context, size_t actionIndex);
  void STR_CLOSEAction(antlr4::RuleContext *context, size_t actionIndex);
  void STR_ESC_NLAction(antlr4::RuleContext *context, size_t actionIndex);
  void STR_NL_ERRORAction(antlr4::RuleContext *context, size_t actionIndex);
  void LINE_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex);
  void BLOCK_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex);
  void NLAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

