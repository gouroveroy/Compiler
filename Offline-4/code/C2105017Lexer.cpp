
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    extern ofstream lexLogFile;
    extern ofstream errorFile;


// Generated from C2105017Lexer.g4 by ANTLR 4.13.2


#include "C2105017Lexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct C2105017LexerStaticData final {
  C2105017LexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105017LexerStaticData(const C2105017LexerStaticData&) = delete;
  C2105017LexerStaticData(C2105017LexerStaticData&&) = delete;
  C2105017LexerStaticData& operator=(const C2105017LexerStaticData&) = delete;
  C2105017LexerStaticData& operator=(C2105017LexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105017lexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105017LexerStaticData> c2105017lexerLexerStaticData = nullptr;

void c2105017lexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105017lexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(c2105017lexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105017LexerStaticData>(
    std::vector<std::string>{
      "IF", "ELSE", "FOR", "WHILE", "DO", "SWITCH", "CASE", "DEFAULT", "BREAK", 
      "CONTINUE", "RETURN", "PRINTLN", "INT", "FLOAT", "CHAR", "DOUBLE", 
      "VOID", "LONG", "SHORT", "STATIC", "UNSIGNED", "GOTO", "ADDOP", "MULOP", 
      "INCOP", "DECOP", "RELOP", "LOGICOP", "ASSIGNOP", "BITOP", "NOT", 
      "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", 
      "SEMICOLON", "ID", "CONST_INT", "CONST_FLOAT", "HASH", "SINGLE_QUOTE", 
      "CHAR_EMPTY", "CHAR_CLOSE", "CHAR_ESCAPE", "CHAR_ESC_NL", "CHAR_ERROR_NL", 
      "CHAR_ANY", "DOUBLE_QUOTE", "STR_CLOSE", "STR_ESCAPE", "STR_ESC_NL", 
      "STR_NL_ERROR", "STR_ANY", "LINE_COMMENT", "BLOCK_COMMENT", "WS", 
      "NL", "UNRECOGNIZED"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "CHAR_MODE", "STRING_MODE"
    },
    std::vector<std::string>{
      "", "'if'", "'else'", "'for'", "'while'", "'do'", "'switch'", "'case'", 
      "'default'", "'break'", "'continue'", "'return'", "'println'", "'int'", 
      "'float'", "'char'", "'double'", "'void'", "'long'", "'short'", "'static'", 
      "'unsigned'", "'goto'", "", "", "'++'", "'--'", "", "", "'='", "", 
      "'!'", "'('", "')'", "'{'", "'}'", "'['", "']'", "','", "';'", "", 
      "", "", "'#'", "'''", "", "", "", "'\"'"
    },
    std::vector<std::string>{
      "", "IF", "ELSE", "FOR", "WHILE", "DO", "SWITCH", "CASE", "DEFAULT", 
      "BREAK", "CONTINUE", "RETURN", "PRINTLN", "INT", "FLOAT", "CHAR", 
      "DOUBLE", "VOID", "LONG", "SHORT", "STATIC", "UNSIGNED", "GOTO", "ADDOP", 
      "MULOP", "INCOP", "DECOP", "RELOP", "LOGICOP", "ASSIGNOP", "BITOP", 
      "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", 
      "SEMICOLON", "ID", "CONST_INT", "CONST_FLOAT", "HASH", "SINGLE_QUOTE", 
      "CHAR_EMPTY", "CHAR_CLOSE", "CHAR_ERROR_NL", "DOUBLE_QUOTE", "STR_CLOSE", 
      "STR_NL_ERROR", "LINE_COMMENT", "BLOCK_COMMENT", "WS", "NL", "UNRECOGNIZED"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,55,558,6,-1,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,
  	7,5,2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,
  	7,13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,
  	7,20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,
  	7,27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,
  	7,34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,
  	7,41,2,42,7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,
  	7,48,2,49,7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,
  	7,55,2,56,7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,1,0,1,0,1,0,1,
  	0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,22,1,22,1,22,3,22,303,8,22,1,23,1,23,1,23,3,23,308,8,23,1,
  	24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,26,1,
  	26,1,26,1,26,1,26,1,26,1,26,1,26,3,26,331,8,26,1,27,1,27,1,27,1,27,1,
  	27,1,27,3,27,339,8,27,1,28,1,28,1,28,1,29,1,29,1,29,3,29,347,8,29,1,30,
  	1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,33,1,34,1,34,1,34,
  	1,35,1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,1,39,1,39,
  	5,39,378,8,39,10,39,12,39,381,9,39,1,39,1,39,1,40,4,40,386,8,40,11,40,
  	12,40,387,1,40,1,40,1,41,5,41,393,8,41,10,41,12,41,396,9,41,1,41,1,41,
  	4,41,400,8,41,11,41,12,41,401,1,41,1,41,3,41,406,8,41,1,41,4,41,409,8,
  	41,11,41,12,41,410,3,41,413,8,41,1,41,4,41,416,8,41,11,41,12,41,417,1,
  	41,1,41,3,41,422,8,41,1,41,4,41,425,8,41,11,41,12,41,426,1,41,3,41,430,
  	8,41,1,42,1,42,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,44,1,45,1,45,
  	1,45,1,45,1,45,1,46,1,46,1,46,1,46,1,46,1,47,1,47,3,47,455,8,47,1,47,
  	1,47,1,47,1,47,1,47,1,48,1,48,1,48,1,48,1,48,1,49,1,49,1,49,1,49,1,50,
  	1,50,1,50,1,50,1,51,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,1,53,
  	1,53,3,53,487,8,53,1,53,1,53,1,53,1,53,1,53,1,54,1,54,1,54,1,54,1,54,
  	1,55,4,55,500,8,55,11,55,12,55,501,1,55,1,55,1,56,1,56,1,56,1,56,1,56,
  	3,56,511,8,56,1,56,1,56,1,56,5,56,516,8,56,10,56,12,56,519,9,56,1,56,
  	1,56,1,56,1,56,1,57,1,57,1,57,1,57,1,57,5,57,530,8,57,10,57,12,57,533,
  	9,57,1,57,1,57,1,57,1,57,1,57,1,57,1,57,1,58,4,58,543,8,58,11,58,12,58,
  	544,1,58,1,58,1,59,3,59,550,8,59,1,59,1,59,1,59,1,59,1,59,1,60,1,60,1,
  	531,0,61,3,1,5,2,7,3,9,4,11,5,13,6,15,7,17,8,19,9,21,10,23,11,25,12,27,
  	13,29,14,31,15,33,16,35,17,37,18,39,19,41,20,43,21,45,22,47,23,49,24,
  	51,25,53,26,55,27,57,28,59,29,61,30,63,31,65,32,67,33,69,34,71,35,73,
  	36,75,37,77,38,79,39,81,40,83,41,85,42,87,43,89,44,91,45,93,46,95,0,97,
  	0,99,47,101,0,103,48,105,49,107,0,109,0,111,50,113,0,115,51,117,52,119,
  	53,121,54,123,55,3,0,1,2,11,2,0,42,42,47,47,2,0,38,38,124,124,3,0,65,
  	90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,2,0,69,69,101,
  	101,2,0,43,43,45,45,10,0,34,34,39,39,48,48,92,92,97,98,102,102,110,110,
  	114,114,116,116,118,118,4,0,10,10,13,13,34,34,92,92,2,0,10,10,13,13,3,
  	0,9,9,12,13,32,32,585,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,
  	0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,
  	1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,
  	0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,
  	0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,
  	1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,
  	0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,
  	0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,
  	1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,1,91,1,0,0,0,1,93,1,0,0,0,1,95,1,0,
  	0,0,1,97,1,0,0,0,1,99,1,0,0,0,1,101,1,0,0,0,1,103,1,0,0,0,2,105,1,0,0,
  	0,2,107,1,0,0,0,2,109,1,0,0,0,2,111,1,0,0,0,2,113,1,0,0,0,2,115,1,0,0,
  	0,2,117,1,0,0,0,2,119,1,0,0,0,2,121,1,0,0,0,2,123,1,0,0,0,3,125,1,0,0,
  	0,5,130,1,0,0,0,7,137,1,0,0,0,9,143,1,0,0,0,11,151,1,0,0,0,13,156,1,0,
  	0,0,15,165,1,0,0,0,17,172,1,0,0,0,19,182,1,0,0,0,21,190,1,0,0,0,23,201,
  	1,0,0,0,25,210,1,0,0,0,27,220,1,0,0,0,29,226,1,0,0,0,31,234,1,0,0,0,33,
  	241,1,0,0,0,35,250,1,0,0,0,37,257,1,0,0,0,39,264,1,0,0,0,41,272,1,0,0,
  	0,43,281,1,0,0,0,45,292,1,0,0,0,47,302,1,0,0,0,49,307,1,0,0,0,51,309,
  	1,0,0,0,53,314,1,0,0,0,55,330,1,0,0,0,57,338,1,0,0,0,59,340,1,0,0,0,61,
  	346,1,0,0,0,63,348,1,0,0,0,65,351,1,0,0,0,67,354,1,0,0,0,69,357,1,0,0,
  	0,71,360,1,0,0,0,73,363,1,0,0,0,75,366,1,0,0,0,77,369,1,0,0,0,79,372,
  	1,0,0,0,81,375,1,0,0,0,83,385,1,0,0,0,85,429,1,0,0,0,87,431,1,0,0,0,89,
  	433,1,0,0,0,91,437,1,0,0,0,93,442,1,0,0,0,95,447,1,0,0,0,97,452,1,0,0,
  	0,99,461,1,0,0,0,101,466,1,0,0,0,103,470,1,0,0,0,105,474,1,0,0,0,107,
  	479,1,0,0,0,109,484,1,0,0,0,111,493,1,0,0,0,113,499,1,0,0,0,115,505,1,
  	0,0,0,117,524,1,0,0,0,119,542,1,0,0,0,121,549,1,0,0,0,123,556,1,0,0,0,
  	125,126,5,105,0,0,126,127,5,102,0,0,127,128,1,0,0,0,128,129,6,0,0,0,129,
  	4,1,0,0,0,130,131,5,101,0,0,131,132,5,108,0,0,132,133,5,115,0,0,133,134,
  	5,101,0,0,134,135,1,0,0,0,135,136,6,1,1,0,136,6,1,0,0,0,137,138,5,102,
  	0,0,138,139,5,111,0,0,139,140,5,114,0,0,140,141,1,0,0,0,141,142,6,2,2,
  	0,142,8,1,0,0,0,143,144,5,119,0,0,144,145,5,104,0,0,145,146,5,105,0,0,
  	146,147,5,108,0,0,147,148,5,101,0,0,148,149,1,0,0,0,149,150,6,3,3,0,150,
  	10,1,0,0,0,151,152,5,100,0,0,152,153,5,111,0,0,153,154,1,0,0,0,154,155,
  	6,4,4,0,155,12,1,0,0,0,156,157,5,115,0,0,157,158,5,119,0,0,158,159,5,
  	105,0,0,159,160,5,116,0,0,160,161,5,99,0,0,161,162,5,104,0,0,162,163,
  	1,0,0,0,163,164,6,5,5,0,164,14,1,0,0,0,165,166,5,99,0,0,166,167,5,97,
  	0,0,167,168,5,115,0,0,168,169,5,101,0,0,169,170,1,0,0,0,170,171,6,6,6,
  	0,171,16,1,0,0,0,172,173,5,100,0,0,173,174,5,101,0,0,174,175,5,102,0,
  	0,175,176,5,97,0,0,176,177,5,117,0,0,177,178,5,108,0,0,178,179,5,116,
  	0,0,179,180,1,0,0,0,180,181,6,7,7,0,181,18,1,0,0,0,182,183,5,98,0,0,183,
  	184,5,114,0,0,184,185,5,101,0,0,185,186,5,97,0,0,186,187,5,107,0,0,187,
  	188,1,0,0,0,188,189,6,8,8,0,189,20,1,0,0,0,190,191,5,99,0,0,191,192,5,
  	111,0,0,192,193,5,110,0,0,193,194,5,116,0,0,194,195,5,105,0,0,195,196,
  	5,110,0,0,196,197,5,117,0,0,197,198,5,101,0,0,198,199,1,0,0,0,199,200,
  	6,9,9,0,200,22,1,0,0,0,201,202,5,114,0,0,202,203,5,101,0,0,203,204,5,
  	116,0,0,204,205,5,117,0,0,205,206,5,114,0,0,206,207,5,110,0,0,207,208,
  	1,0,0,0,208,209,6,10,10,0,209,24,1,0,0,0,210,211,5,112,0,0,211,212,5,
  	114,0,0,212,213,5,105,0,0,213,214,5,110,0,0,214,215,5,116,0,0,215,216,
  	5,108,0,0,216,217,5,110,0,0,217,218,1,0,0,0,218,219,6,11,11,0,219,26,
  	1,0,0,0,220,221,5,105,0,0,221,222,5,110,0,0,222,223,5,116,0,0,223,224,
  	1,0,0,0,224,225,6,12,12,0,225,28,1,0,0,0,226,227,5,102,0,0,227,228,5,
  	108,0,0,228,229,5,111,0,0,229,230,5,97,0,0,230,231,5,116,0,0,231,232,
  	1,0,0,0,232,233,6,13,13,0,233,30,1,0,0,0,234,235,5,99,0,0,235,236,5,104,
  	0,0,236,237,5,97,0,0,237,238,5,114,0,0,238,239,1,0,0,0,239,240,6,14,14,
  	0,240,32,1,0,0,0,241,242,5,100,0,0,242,243,5,111,0,0,243,244,5,117,0,
  	0,244,245,5,98,0,0,245,246,5,108,0,0,246,247,5,101,0,0,247,248,1,0,0,
  	0,248,249,6,15,15,0,249,34,1,0,0,0,250,251,5,118,0,0,251,252,5,111,0,
  	0,252,253,5,105,0,0,253,254,5,100,0,0,254,255,1,0,0,0,255,256,6,16,16,
  	0,256,36,1,0,0,0,257,258,5,108,0,0,258,259,5,111,0,0,259,260,5,110,0,
  	0,260,261,5,103,0,0,261,262,1,0,0,0,262,263,6,17,17,0,263,38,1,0,0,0,
  	264,265,5,115,0,0,265,266,5,104,0,0,266,267,5,111,0,0,267,268,5,114,0,
  	0,268,269,5,116,0,0,269,270,1,0,0,0,270,271,6,18,18,0,271,40,1,0,0,0,
  	272,273,5,115,0,0,273,274,5,116,0,0,274,275,5,97,0,0,275,276,5,116,0,
  	0,276,277,5,105,0,0,277,278,5,99,0,0,278,279,1,0,0,0,279,280,6,19,19,
  	0,280,42,1,0,0,0,281,282,5,117,0,0,282,283,5,110,0,0,283,284,5,115,0,
  	0,284,285,5,105,0,0,285,286,5,103,0,0,286,287,5,110,0,0,287,288,5,101,
  	0,0,288,289,5,100,0,0,289,290,1,0,0,0,290,291,6,20,20,0,291,44,1,0,0,
  	0,292,293,5,103,0,0,293,294,5,111,0,0,294,295,5,116,0,0,295,296,5,111,
  	0,0,296,297,1,0,0,0,297,298,6,21,21,0,298,46,1,0,0,0,299,303,5,43,0,0,
  	300,301,5,45,0,0,301,303,6,22,22,0,302,299,1,0,0,0,302,300,1,0,0,0,303,
  	48,1,0,0,0,304,308,7,0,0,0,305,306,5,37,0,0,306,308,6,23,23,0,307,304,
  	1,0,0,0,307,305,1,0,0,0,308,50,1,0,0,0,309,310,5,43,0,0,310,311,5,43,
  	0,0,311,312,1,0,0,0,312,313,6,24,24,0,313,52,1,0,0,0,314,315,5,45,0,0,
  	315,316,5,45,0,0,316,317,1,0,0,0,317,318,6,25,25,0,318,54,1,0,0,0,319,
  	320,5,60,0,0,320,331,5,61,0,0,321,322,5,62,0,0,322,331,5,61,0,0,323,324,
  	5,61,0,0,324,331,5,61,0,0,325,326,5,33,0,0,326,331,5,61,0,0,327,331,5,
  	60,0,0,328,329,5,62,0,0,329,331,6,26,26,0,330,319,1,0,0,0,330,321,1,0,
  	0,0,330,323,1,0,0,0,330,325,1,0,0,0,330,327,1,0,0,0,330,328,1,0,0,0,331,
  	56,1,0,0,0,332,333,5,38,0,0,333,339,5,38,0,0,334,335,5,124,0,0,335,336,
  	5,124,0,0,336,337,1,0,0,0,337,339,6,27,27,0,338,332,1,0,0,0,338,334,1,
  	0,0,0,339,58,1,0,0,0,340,341,5,61,0,0,341,342,6,28,28,0,342,60,1,0,0,
  	0,343,347,7,1,0,0,344,345,5,94,0,0,345,347,6,29,29,0,346,343,1,0,0,0,
  	346,344,1,0,0,0,347,62,1,0,0,0,348,349,5,33,0,0,349,350,6,30,30,0,350,
  	64,1,0,0,0,351,352,5,40,0,0,352,353,6,31,31,0,353,66,1,0,0,0,354,355,
  	5,41,0,0,355,356,6,32,32,0,356,68,1,0,0,0,357,358,5,123,0,0,358,359,6,
  	33,33,0,359,70,1,0,0,0,360,361,5,125,0,0,361,362,6,34,34,0,362,72,1,0,
  	0,0,363,364,5,91,0,0,364,365,6,35,35,0,365,74,1,0,0,0,366,367,5,93,0,
  	0,367,368,6,36,36,0,368,76,1,0,0,0,369,370,5,44,0,0,370,371,6,37,37,0,
  	371,78,1,0,0,0,372,373,5,59,0,0,373,374,6,38,38,0,374,80,1,0,0,0,375,
  	379,7,2,0,0,376,378,7,3,0,0,377,376,1,0,0,0,378,381,1,0,0,0,379,377,1,
  	0,0,0,379,380,1,0,0,0,380,382,1,0,0,0,381,379,1,0,0,0,382,383,6,39,39,
  	0,383,82,1,0,0,0,384,386,7,4,0,0,385,384,1,0,0,0,386,387,1,0,0,0,387,
  	385,1,0,0,0,387,388,1,0,0,0,388,389,1,0,0,0,389,390,6,40,40,0,390,84,
  	1,0,0,0,391,393,7,4,0,0,392,391,1,0,0,0,393,396,1,0,0,0,394,392,1,0,0,
  	0,394,395,1,0,0,0,395,397,1,0,0,0,396,394,1,0,0,0,397,399,5,46,0,0,398,
  	400,7,4,0,0,399,398,1,0,0,0,400,401,1,0,0,0,401,399,1,0,0,0,401,402,1,
  	0,0,0,402,412,1,0,0,0,403,405,7,5,0,0,404,406,7,6,0,0,405,404,1,0,0,0,
  	405,406,1,0,0,0,406,408,1,0,0,0,407,409,7,4,0,0,408,407,1,0,0,0,409,410,
  	1,0,0,0,410,408,1,0,0,0,410,411,1,0,0,0,411,413,1,0,0,0,412,403,1,0,0,
  	0,412,413,1,0,0,0,413,430,1,0,0,0,414,416,7,4,0,0,415,414,1,0,0,0,416,
  	417,1,0,0,0,417,415,1,0,0,0,417,418,1,0,0,0,418,419,1,0,0,0,419,421,7,
  	5,0,0,420,422,7,6,0,0,421,420,1,0,0,0,421,422,1,0,0,0,422,424,1,0,0,0,
  	423,425,7,4,0,0,424,423,1,0,0,0,425,426,1,0,0,0,426,424,1,0,0,0,426,427,
  	1,0,0,0,427,428,1,0,0,0,428,430,6,41,41,0,429,394,1,0,0,0,429,415,1,0,
  	0,0,430,86,1,0,0,0,431,432,5,35,0,0,432,88,1,0,0,0,433,434,5,39,0,0,434,
  	435,1,0,0,0,435,436,6,43,42,0,436,90,1,0,0,0,437,438,5,39,0,0,438,439,
  	6,44,43,0,439,440,1,0,0,0,440,441,6,44,44,0,441,92,1,0,0,0,442,443,5,
  	39,0,0,443,444,6,45,45,0,444,445,1,0,0,0,445,446,6,45,44,0,446,94,1,0,
  	0,0,447,448,5,92,0,0,448,449,7,7,0,0,449,450,1,0,0,0,450,451,6,46,46,
  	0,451,96,1,0,0,0,452,454,5,92,0,0,453,455,5,13,0,0,454,453,1,0,0,0,454,
  	455,1,0,0,0,455,456,1,0,0,0,456,457,5,10,0,0,457,458,6,47,47,0,458,459,
  	1,0,0,0,459,460,6,47,46,0,460,98,1,0,0,0,461,462,5,10,0,0,462,463,6,48,
  	48,0,463,464,1,0,0,0,464,465,6,48,44,0,465,100,1,0,0,0,466,467,9,0,0,
  	0,467,468,1,0,0,0,468,469,6,49,46,0,469,102,1,0,0,0,470,471,5,34,0,0,
  	471,472,1,0,0,0,472,473,6,50,49,0,473,104,1,0,0,0,474,475,5,34,0,0,475,
  	476,6,51,50,0,476,477,1,0,0,0,477,478,6,51,44,0,478,106,1,0,0,0,479,480,
  	5,92,0,0,480,481,7,7,0,0,481,482,1,0,0,0,482,483,6,52,46,0,483,108,1,
  	0,0,0,484,486,5,92,0,0,485,487,5,13,0,0,486,485,1,0,0,0,486,487,1,0,0,
  	0,487,488,1,0,0,0,488,489,5,10,0,0,489,490,6,53,51,0,490,491,1,0,0,0,
  	491,492,6,53,46,0,492,110,1,0,0,0,493,494,5,10,0,0,494,495,6,54,52,0,
  	495,496,1,0,0,0,496,497,6,54,44,0,497,112,1,0,0,0,498,500,8,8,0,0,499,
  	498,1,0,0,0,500,501,1,0,0,0,501,499,1,0,0,0,501,502,1,0,0,0,502,503,1,
  	0,0,0,503,504,6,55,46,0,504,114,1,0,0,0,505,506,5,47,0,0,506,507,5,47,
  	0,0,507,517,1,0,0,0,508,510,5,92,0,0,509,511,5,13,0,0,510,509,1,0,0,0,
  	510,511,1,0,0,0,511,512,1,0,0,0,512,513,5,10,0,0,513,516,6,56,53,0,514,
  	516,8,9,0,0,515,508,1,0,0,0,515,514,1,0,0,0,516,519,1,0,0,0,517,515,1,
  	0,0,0,517,518,1,0,0,0,518,520,1,0,0,0,519,517,1,0,0,0,520,521,6,56,54,
  	0,521,522,1,0,0,0,522,523,6,56,55,0,523,116,1,0,0,0,524,525,5,47,0,0,
  	525,526,5,42,0,0,526,531,1,0,0,0,527,530,9,0,0,0,528,530,7,9,0,0,529,
  	527,1,0,0,0,529,528,1,0,0,0,530,533,1,0,0,0,531,532,1,0,0,0,531,529,1,
  	0,0,0,532,534,1,0,0,0,533,531,1,0,0,0,534,535,5,42,0,0,535,536,5,47,0,
  	0,536,537,1,0,0,0,537,538,6,57,56,0,538,539,1,0,0,0,539,540,6,57,55,0,
  	540,118,1,0,0,0,541,543,7,10,0,0,542,541,1,0,0,0,543,544,1,0,0,0,544,
  	542,1,0,0,0,544,545,1,0,0,0,545,546,1,0,0,0,546,547,6,58,55,0,547,120,
  	1,0,0,0,548,550,5,13,0,0,549,548,1,0,0,0,549,550,1,0,0,0,550,551,1,0,
  	0,0,551,552,5,10,0,0,552,553,6,59,57,0,553,554,1,0,0,0,554,555,6,59,55,
  	0,555,122,1,0,0,0,556,557,9,0,0,0,557,124,1,0,0,0,29,0,1,2,302,307,330,
  	338,346,379,387,394,401,405,410,412,417,421,426,429,454,486,501,510,515,
  	517,529,531,544,549,58,1,0,0,1,1,1,1,2,2,1,3,3,1,4,4,1,5,5,1,6,6,1,7,
  	7,1,8,8,1,9,9,1,10,10,1,11,11,1,12,12,1,13,13,1,14,14,1,15,15,1,16,16,
  	1,17,17,1,18,18,1,19,19,1,20,20,1,21,21,1,22,22,1,23,23,1,24,24,1,25,
  	25,1,26,26,1,27,27,1,28,28,1,29,29,1,30,30,1,31,31,1,32,32,1,33,33,1,
  	34,34,1,35,35,1,36,36,1,37,37,1,38,38,1,39,39,1,40,40,1,41,41,5,1,0,1,
  	44,42,4,0,0,1,45,43,3,0,0,1,47,44,1,48,45,5,2,0,1,51,46,1,53,47,1,54,
  	48,1,56,49,1,56,50,6,0,0,1,57,51,1,59,52
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105017lexerLexerStaticData = std::move(staticData);
}

}

C2105017Lexer::C2105017Lexer(CharStream *input) : Lexer(input) {
  C2105017Lexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *c2105017lexerLexerStaticData->atn, c2105017lexerLexerStaticData->decisionToDFA, c2105017lexerLexerStaticData->sharedContextCache);
}

C2105017Lexer::~C2105017Lexer() {
  delete _interpreter;
}

std::string C2105017Lexer::getGrammarFileName() const {
  return "C2105017Lexer.g4";
}

const std::vector<std::string>& C2105017Lexer::getRuleNames() const {
  return c2105017lexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& C2105017Lexer::getChannelNames() const {
  return c2105017lexerLexerStaticData->channelNames;
}

const std::vector<std::string>& C2105017Lexer::getModeNames() const {
  return c2105017lexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& C2105017Lexer::getVocabulary() const {
  return c2105017lexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105017Lexer::getSerializedATN() const {
  return c2105017lexerLexerStaticData->serializedATN;
}

const atn::ATN& C2105017Lexer::getATN() const {
  return *c2105017lexerLexerStaticData->atn;
}


void C2105017Lexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 0: IFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 1: ELSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 2: FORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 3: WHILEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 4: DOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 5: SWITCHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 6: CASEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 7: DEFAULTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 8: BREAKAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 9: CONTINUEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 10: RETURNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 11: PRINTLNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: CHARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: DOUBLEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: VOIDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: LONGAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 18: SHORTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 19: STATICAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 20: UNSIGNEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: GOTOAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 22: ADDOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 23: MULOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 24: INCOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 25: DECOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 26: RELOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 27: LOGICOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 28: ASSIGNOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 29: BITOPAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 30: NOTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 31: LPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 32: RPARENAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 33: LCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 34: RCURLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 35: LTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 36: RTHIRDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 37: COMMAAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 38: SEMICOLONAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 39: IDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 40: CONST_INTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 41: CONST_FLOATAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 44: CHAR_EMPTYAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 45: CHAR_CLOSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 47: CHAR_ESC_NLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 48: CHAR_ERROR_NLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 51: STR_CLOSEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 53: STR_ESC_NLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 54: STR_NL_ERRORAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 56: LINE_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 57: BLOCK_COMMENTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 59: NLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void C2105017Lexer::IFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <IF> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::ELSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ELSE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::FORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <FOR> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::WHILEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <WHILE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::DOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DO> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::SWITCHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <SWITCH> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::CASEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CASE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::DEFAULTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DEFAULT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::BREAKAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <BREAK> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::CONTINUEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONTINUE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::RETURNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RETURN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::PRINTLNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <PRINTLN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <FLOAT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::CHARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CHAR> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::DOUBLEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DOUBLE> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::VOIDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <VOID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::LONGAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LONG> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::SHORTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 18:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <SHORT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::STATICAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 19:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <STATIC> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::UNSIGNEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 20:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <UNSIGNED> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::GOTOAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 21:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <GOTO> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::ADDOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 22:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ADDOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::MULOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 23:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <MULOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::INCOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 24:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <INCOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::DECOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 25:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DECOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::RELOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 26:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RELOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::LOGICOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 27:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LOGICOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::ASSIGNOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 28:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ASSIGNOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::BITOPAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 29:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <BITOP> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::NOTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 30:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <NOT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::LPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 31:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::RPARENAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 32:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RPAREN> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::LCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 33:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::RCURLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 34:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RCURL> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::LTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 35:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::RTHIRDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 36:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RTHIRD> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::COMMAAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 37:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <COMMA> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::SEMICOLONAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 38:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <SEMICOLON> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::IDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 39:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ID> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::CONST_INTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 40:  writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONST_INT> Lexeme " + getText());  break;

  default:
    break;
  }
}

void C2105017Lexer::CONST_FLOATAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 41: 
            writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONST_FLOAT> Lexeme " + getText());
         break;

  default:
    break;
  }
}

void C2105017Lexer::CHAR_EMPTYAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 42: 
                // notifyErrorListeners("Empty character constant");
               break;

  default:
    break;
  }
}

void C2105017Lexer::CHAR_CLOSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 43: 
                writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONST_CHAR> Lexeme " + getText());
               break;

  default:
    break;
  }
}

void C2105017Lexer::CHAR_ESC_NLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 44:  lineCount++;  break;

  default:
    break;
  }
}

void C2105017Lexer::CHAR_ERROR_NLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 45: 
                // notifyErrorListeners("Unterminated character");
                lineCount++;
               break;

  default:
    break;
  }
}

void C2105017Lexer::STR_CLOSEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 46: 
                writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <STRING> Lexeme " + getText());
               break;

  default:
    break;
  }
}

void C2105017Lexer::STR_ESC_NLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 47:  lineCount++;  break;

  default:
    break;
  }
}

void C2105017Lexer::STR_NL_ERRORAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 48: 
                // notifyErrorListeners("Unterminated string");
                lineCount++;
               break;

  default:
    break;
  }
}

void C2105017Lexer::LINE_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 49:  lineCount++;  break;
    case 50: 
            writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LINE_COMMENT> Lexeme " + getText());
           break;

  default:
    break;
  }
}

void C2105017Lexer::BLOCK_COMMENTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 51: 
            {
              // strip /* and */
              string body = getText().substr(2, getText().size()-4);
              writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <BLOCK_COMMENT> Lexeme /*" + body + "*/");
            }
           break;

  default:
    break;
  }
}

void C2105017Lexer::NLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 52:  lineCount++;  break;

  default:
    break;
  }
}



void C2105017Lexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105017lexerLexerInitialize();
#else
  ::antlr4::internal::call_once(c2105017lexerLexerOnceFlag, c2105017lexerLexerInitialize);
#endif
}
