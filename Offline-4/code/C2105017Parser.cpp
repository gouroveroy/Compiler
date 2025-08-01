
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


#include "C2105017ParserListener.h"

#include "C2105017Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C2105017ParserStaticData final {
  C2105017ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105017ParserStaticData(const C2105017ParserStaticData&) = delete;
  C2105017ParserStaticData(C2105017ParserStaticData&&) = delete;
  C2105017ParserStaticData& operator=(const C2105017ParserStaticData&) = delete;
  C2105017ParserStaticData& operator=(C2105017ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105017parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105017ParserStaticData> c2105017parserParserStaticData = nullptr;

void c2105017parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105017parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c2105017parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105017ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "type_specifier", 
      "declaration_list", "declaration_list_tail", "declaration_item", "statements", 
      "statement", "expression_statement", "variable", "expression", "logic_expression", 
      "rel_expression", "simple_expression", "term", "unary_expression", 
      "factor", "argument_list", "arguments"
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
  	4,1,55,432,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,5,1,62,8,1,10,1,12,1,65,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,3,2,76,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,3,3,94,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,3,4,114,8,4,1,5,1,5,1,5,1,5,1,5,1,5,3,5,122,8,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,5,5,130,8,5,10,5,12,5,133,9,5,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,3,6,145,8,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,
  	8,1,8,1,8,3,8,158,8,8,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,
  	10,1,10,3,10,172,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,3,11,186,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,5,
  	12,196,8,12,10,12,12,12,199,9,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,275,8,13,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,286,8,14,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,297,8,15,1,16,1,16,1,16,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,3,16,309,8,16,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,3,17,320,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,3,18,331,8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,5,19,343,8,19,10,19,12,19,346,9,19,1,20,1,20,1,20,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,20,5,20,358,8,20,10,20,12,20,361,9,20,1,21,1,21,1,21,1,
  	21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,3,21,382,8,21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,
  	22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,
  	22,1,22,1,22,3,22,410,8,22,1,23,1,23,1,23,1,23,3,23,416,8,23,1,24,1,24,
  	1,24,1,24,1,24,1,24,1,24,1,24,1,24,5,24,427,8,24,10,24,12,24,430,9,24,
  	1,24,0,6,2,10,24,38,40,48,25,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,46,48,0,0,450,0,50,1,0,0,0,2,53,1,0,0,0,4,75,
  	1,0,0,0,6,93,1,0,0,0,8,113,1,0,0,0,10,121,1,0,0,0,12,144,1,0,0,0,14,146,
  	1,0,0,0,16,157,1,0,0,0,18,159,1,0,0,0,20,171,1,0,0,0,22,185,1,0,0,0,24,
  	187,1,0,0,0,26,274,1,0,0,0,28,285,1,0,0,0,30,296,1,0,0,0,32,308,1,0,0,
  	0,34,319,1,0,0,0,36,330,1,0,0,0,38,332,1,0,0,0,40,347,1,0,0,0,42,381,
  	1,0,0,0,44,409,1,0,0,0,46,415,1,0,0,0,48,417,1,0,0,0,50,51,3,2,1,0,51,
  	52,6,0,-1,0,52,1,1,0,0,0,53,54,6,1,-1,0,54,55,3,4,2,0,55,56,6,1,-1,0,
  	56,63,1,0,0,0,57,58,10,1,0,0,58,59,3,4,2,0,59,60,6,1,-1,0,60,62,1,0,0,
  	0,61,57,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,3,1,0,0,
  	0,65,63,1,0,0,0,66,67,3,14,7,0,67,68,6,2,-1,0,68,76,1,0,0,0,69,70,3,6,
  	3,0,70,71,6,2,-1,0,71,76,1,0,0,0,72,73,3,8,4,0,73,74,6,2,-1,0,74,76,1,
  	0,0,0,75,66,1,0,0,0,75,69,1,0,0,0,75,72,1,0,0,0,76,5,1,0,0,0,77,78,3,
  	16,8,0,78,79,5,40,0,0,79,80,5,32,0,0,80,81,5,33,0,0,81,82,5,39,0,0,82,
  	83,6,3,-1,0,83,94,1,0,0,0,84,85,3,16,8,0,85,86,5,40,0,0,86,87,5,32,0,
  	0,87,88,6,3,-1,0,88,89,3,10,5,0,89,90,5,33,0,0,90,91,5,39,0,0,91,92,6,
  	3,-1,0,92,94,1,0,0,0,93,77,1,0,0,0,93,84,1,0,0,0,94,7,1,0,0,0,95,96,3,
  	16,8,0,96,97,5,40,0,0,97,98,5,32,0,0,98,99,5,33,0,0,99,100,6,4,-1,0,100,
  	101,3,12,6,0,101,102,6,4,-1,0,102,114,1,0,0,0,103,104,3,16,8,0,104,105,
  	5,40,0,0,105,106,5,32,0,0,106,107,6,4,-1,0,107,108,3,10,5,0,108,109,5,
  	33,0,0,109,110,6,4,-1,0,110,111,3,12,6,0,111,112,6,4,-1,0,112,114,1,0,
  	0,0,113,95,1,0,0,0,113,103,1,0,0,0,114,9,1,0,0,0,115,116,6,5,-1,0,116,
  	117,3,16,8,0,117,118,5,40,0,0,118,119,6,5,-1,0,119,122,1,0,0,0,120,122,
  	6,5,-1,0,121,115,1,0,0,0,121,120,1,0,0,0,122,131,1,0,0,0,123,124,10,2,
  	0,0,124,125,5,38,0,0,125,126,3,16,8,0,126,127,5,40,0,0,127,128,6,5,-1,
  	0,128,130,1,0,0,0,129,123,1,0,0,0,130,133,1,0,0,0,131,129,1,0,0,0,131,
  	132,1,0,0,0,132,11,1,0,0,0,133,131,1,0,0,0,134,135,5,34,0,0,135,136,6,
  	6,-1,0,136,137,5,35,0,0,137,145,6,6,-1,0,138,139,5,34,0,0,139,140,6,6,
  	-1,0,140,141,3,24,12,0,141,142,5,35,0,0,142,143,6,6,-1,0,143,145,1,0,
  	0,0,144,134,1,0,0,0,144,138,1,0,0,0,145,13,1,0,0,0,146,147,3,16,8,0,147,
  	148,3,18,9,0,148,149,5,39,0,0,149,150,6,7,-1,0,150,15,1,0,0,0,151,152,
  	5,13,0,0,152,158,6,8,-1,0,153,154,5,14,0,0,154,158,6,8,-1,0,155,156,5,
  	17,0,0,156,158,6,8,-1,0,157,151,1,0,0,0,157,153,1,0,0,0,157,155,1,0,0,
  	0,158,17,1,0,0,0,159,160,3,22,11,0,160,161,6,9,-1,0,161,162,3,20,10,0,
  	162,163,6,9,-1,0,163,19,1,0,0,0,164,165,5,38,0,0,165,166,3,22,11,0,166,
  	167,6,10,-1,0,167,168,3,20,10,0,168,169,6,10,-1,0,169,172,1,0,0,0,170,
  	172,6,10,-1,0,171,164,1,0,0,0,171,170,1,0,0,0,172,21,1,0,0,0,173,174,
  	5,40,0,0,174,186,6,11,-1,0,175,176,5,40,0,0,176,177,5,36,0,0,177,178,
  	5,41,0,0,178,179,5,37,0,0,179,186,6,11,-1,0,180,181,5,40,0,0,181,182,
  	5,29,0,0,182,183,3,34,17,0,183,184,6,11,-1,0,184,186,1,0,0,0,185,173,
  	1,0,0,0,185,175,1,0,0,0,185,180,1,0,0,0,186,23,1,0,0,0,187,188,6,12,-1,
  	0,188,189,3,26,13,0,189,190,6,12,-1,0,190,197,1,0,0,0,191,192,10,1,0,
  	0,192,193,3,26,13,0,193,194,6,12,-1,0,194,196,1,0,0,0,195,191,1,0,0,0,
  	196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,25,1,0,0,0,199,197,
  	1,0,0,0,200,201,3,14,7,0,201,202,6,13,-1,0,202,275,1,0,0,0,203,204,3,
  	28,14,0,204,205,6,13,-1,0,205,275,1,0,0,0,206,207,3,12,6,0,207,208,6,
  	13,-1,0,208,275,1,0,0,0,209,210,5,3,0,0,210,211,5,32,0,0,211,212,6,13,
  	-1,0,212,213,3,28,14,0,213,214,6,13,-1,0,214,215,3,28,14,0,215,216,6,
  	13,-1,0,216,217,3,32,16,0,217,218,5,33,0,0,218,219,6,13,-1,0,219,220,
  	3,26,13,0,220,221,6,13,-1,0,221,275,1,0,0,0,222,223,5,1,0,0,223,224,5,
  	32,0,0,224,225,3,32,16,0,225,226,5,33,0,0,226,227,6,13,-1,0,227,228,3,
  	26,13,0,228,229,6,13,-1,0,229,275,1,0,0,0,230,231,5,1,0,0,231,232,5,32,
  	0,0,232,233,3,32,16,0,233,234,5,33,0,0,234,235,6,13,-1,0,235,236,3,26,
  	13,0,236,237,5,2,0,0,237,238,6,13,-1,0,238,239,3,26,13,0,239,240,6,13,
  	-1,0,240,275,1,0,0,0,241,242,5,4,0,0,242,243,5,32,0,0,243,244,6,13,-1,
  	0,244,245,3,32,16,0,245,246,5,33,0,0,246,247,6,13,-1,0,247,248,3,26,13,
  	0,248,249,6,13,-1,0,249,275,1,0,0,0,250,251,5,12,0,0,251,252,5,32,0,0,
  	252,253,5,40,0,0,253,254,5,33,0,0,254,255,5,39,0,0,255,275,6,13,-1,0,
  	256,257,5,12,0,0,257,258,5,32,0,0,258,259,5,40,0,0,259,260,5,36,0,0,260,
  	261,3,32,16,0,261,262,5,37,0,0,262,263,5,33,0,0,263,264,5,39,0,0,264,
  	265,6,13,-1,0,265,275,1,0,0,0,266,267,5,11,0,0,267,268,3,32,16,0,268,
  	269,5,39,0,0,269,270,6,13,-1,0,270,275,1,0,0,0,271,272,5,11,0,0,272,273,
  	5,39,0,0,273,275,6,13,-1,0,274,200,1,0,0,0,274,203,1,0,0,0,274,206,1,
  	0,0,0,274,209,1,0,0,0,274,222,1,0,0,0,274,230,1,0,0,0,274,241,1,0,0,0,
  	274,250,1,0,0,0,274,256,1,0,0,0,274,266,1,0,0,0,274,271,1,0,0,0,275,27,
  	1,0,0,0,276,277,5,39,0,0,277,286,6,14,-1,0,278,279,3,32,16,0,279,280,
  	5,39,0,0,280,281,6,14,-1,0,281,286,1,0,0,0,282,283,3,32,16,0,283,284,
  	6,14,-1,0,284,286,1,0,0,0,285,276,1,0,0,0,285,278,1,0,0,0,285,282,1,0,
  	0,0,286,29,1,0,0,0,287,288,5,40,0,0,288,297,6,15,-1,0,289,290,5,40,0,
  	0,290,291,5,36,0,0,291,292,6,15,-1,0,292,293,3,32,16,0,293,294,5,37,0,
  	0,294,295,6,15,-1,0,295,297,1,0,0,0,296,287,1,0,0,0,296,289,1,0,0,0,297,
  	31,1,0,0,0,298,299,3,34,17,0,299,300,6,16,-1,0,300,309,1,0,0,0,301,302,
  	6,16,-1,0,302,303,3,30,15,0,303,304,6,16,-1,0,304,305,5,29,0,0,305,306,
  	3,34,17,0,306,307,6,16,-1,0,307,309,1,0,0,0,308,298,1,0,0,0,308,301,1,
  	0,0,0,309,33,1,0,0,0,310,311,3,36,18,0,311,312,6,17,-1,0,312,320,1,0,
  	0,0,313,314,3,36,18,0,314,315,5,28,0,0,315,316,6,17,-1,0,316,317,3,36,
  	18,0,317,318,6,17,-1,0,318,320,1,0,0,0,319,310,1,0,0,0,319,313,1,0,0,
  	0,320,35,1,0,0,0,321,322,3,38,19,0,322,323,6,18,-1,0,323,331,1,0,0,0,
  	324,325,3,38,19,0,325,326,6,18,-1,0,326,327,5,27,0,0,327,328,3,38,19,
  	0,328,329,6,18,-1,0,329,331,1,0,0,0,330,321,1,0,0,0,330,324,1,0,0,0,331,
  	37,1,0,0,0,332,333,6,19,-1,0,333,334,3,40,20,0,334,335,6,19,-1,0,335,
  	344,1,0,0,0,336,337,10,1,0,0,337,338,6,19,-1,0,338,339,5,23,0,0,339,340,
  	3,40,20,0,340,341,6,19,-1,0,341,343,1,0,0,0,342,336,1,0,0,0,343,346,1,
  	0,0,0,344,342,1,0,0,0,344,345,1,0,0,0,345,39,1,0,0,0,346,344,1,0,0,0,
  	347,348,6,20,-1,0,348,349,3,42,21,0,349,350,6,20,-1,0,350,359,1,0,0,0,
  	351,352,10,1,0,0,352,353,6,20,-1,0,353,354,5,24,0,0,354,355,3,42,21,0,
  	355,356,6,20,-1,0,356,358,1,0,0,0,357,351,1,0,0,0,358,361,1,0,0,0,359,
  	357,1,0,0,0,359,360,1,0,0,0,360,41,1,0,0,0,361,359,1,0,0,0,362,363,5,
  	23,0,0,363,364,3,42,21,0,364,365,6,21,-1,0,365,382,1,0,0,0,366,367,5,
  	31,0,0,367,368,3,42,21,0,368,369,6,21,-1,0,369,382,1,0,0,0,370,371,5,
  	25,0,0,371,372,3,30,15,0,372,373,6,21,-1,0,373,382,1,0,0,0,374,375,5,
  	26,0,0,375,376,3,30,15,0,376,377,6,21,-1,0,377,382,1,0,0,0,378,379,3,
  	44,22,0,379,380,6,21,-1,0,380,382,1,0,0,0,381,362,1,0,0,0,381,366,1,0,
  	0,0,381,370,1,0,0,0,381,374,1,0,0,0,381,378,1,0,0,0,382,43,1,0,0,0,383,
  	384,3,30,15,0,384,385,6,22,-1,0,385,410,1,0,0,0,386,387,5,40,0,0,387,
  	388,5,32,0,0,388,389,3,46,23,0,389,390,5,33,0,0,390,391,6,22,-1,0,391,
  	410,1,0,0,0,392,393,5,32,0,0,393,394,3,32,16,0,394,395,5,33,0,0,395,396,
  	6,22,-1,0,396,410,1,0,0,0,397,398,5,41,0,0,398,410,6,22,-1,0,399,400,
  	5,42,0,0,400,410,6,22,-1,0,401,402,3,30,15,0,402,403,5,25,0,0,403,404,
  	6,22,-1,0,404,410,1,0,0,0,405,406,3,30,15,0,406,407,5,26,0,0,407,408,
  	6,22,-1,0,408,410,1,0,0,0,409,383,1,0,0,0,409,386,1,0,0,0,409,392,1,0,
  	0,0,409,397,1,0,0,0,409,399,1,0,0,0,409,401,1,0,0,0,409,405,1,0,0,0,410,
  	45,1,0,0,0,411,412,3,48,24,0,412,413,6,23,-1,0,413,416,1,0,0,0,414,416,
  	6,23,-1,0,415,411,1,0,0,0,415,414,1,0,0,0,416,47,1,0,0,0,417,418,6,24,
  	-1,0,418,419,3,34,17,0,419,420,6,24,-1,0,420,428,1,0,0,0,421,422,10,1,
  	0,0,422,423,5,38,0,0,423,424,3,34,17,0,424,425,6,24,-1,0,425,427,1,0,
  	0,0,426,421,1,0,0,0,427,430,1,0,0,0,428,426,1,0,0,0,428,429,1,0,0,0,429,
  	49,1,0,0,0,430,428,1,0,0,0,23,63,75,93,113,121,131,144,157,171,185,197,
  	274,285,296,308,319,330,344,359,381,409,415,428
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105017parserParserStaticData = std::move(staticData);
}

}

C2105017Parser::C2105017Parser(TokenStream *input) : C2105017Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C2105017Parser::C2105017Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C2105017Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c2105017parserParserStaticData->atn, c2105017parserParserStaticData->decisionToDFA, c2105017parserParserStaticData->sharedContextCache, options);
}

C2105017Parser::~C2105017Parser() {
  delete _interpreter;
}

const atn::ATN& C2105017Parser::getATN() const {
  return *c2105017parserParserStaticData->atn;
}

std::string C2105017Parser::getGrammarFileName() const {
  return "C2105017Parser.g4";
}

const std::vector<std::string>& C2105017Parser::getRuleNames() const {
  return c2105017parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C2105017Parser::getVocabulary() const {
  return c2105017parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105017Parser::getSerializedATN() const {
  return c2105017parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C2105017Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::ProgramContext* C2105017Parser::StartContext::program() {
  return getRuleContext<C2105017Parser::ProgramContext>(0);
}


size_t C2105017Parser::StartContext::getRuleIndex() const {
  return C2105017Parser::RuleStart;
}

void C2105017Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C2105017Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C2105017Parser::StartContext* C2105017Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C2105017Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    program(0);

            // Only update dataSegment if println is used
            if (hasPrintln) {
                dataSegment += "NUMBER DB \"00000$\"\n\n";
            }

            antlr4::Token* lastToken = _input->get(_input->size() - 1);
            int totalLines = lastToken->getLine();
            writeIntoParserLogFile("Line " + to_string(totalLines) + ": start : program\n");
            symbolTable->PrintAllScopeTable();
            writeIntoParserLogFile("Total number of lines: " + to_string(totalLines));
            writeIntoParserLogFile("Total number of errors: " + to_string(syntaxErrorCount));
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C2105017Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::UnitContext* C2105017Parser::ProgramContext::unit() {
  return getRuleContext<C2105017Parser::UnitContext>(0);
}

C2105017Parser::ProgramContext* C2105017Parser::ProgramContext::program() {
  return getRuleContext<C2105017Parser::ProgramContext>(0);
}


size_t C2105017Parser::ProgramContext::getRuleIndex() const {
  return C2105017Parser::RuleProgram;
}

void C2105017Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C2105017Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C2105017Parser::ProgramContext* C2105017Parser::program() {
   return program(0);
}

C2105017Parser::ProgramContext* C2105017Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105017Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C2105017Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C2105017Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(54);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

            antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
            writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) + ": program : unit\n\n" + _localctx->text + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(63);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->p = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(57);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(58);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                          antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->p->text + "\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
                          writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) + ": program : program unit\n\n" + _localctx->text + "\n");
                       
      }
      setState(65);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C2105017Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Var_declarationContext* C2105017Parser::UnitContext::var_declaration() {
  return getRuleContext<C2105017Parser::Var_declarationContext>(0);
}

C2105017Parser::Func_declarationContext* C2105017Parser::UnitContext::func_declaration() {
  return getRuleContext<C2105017Parser::Func_declarationContext>(0);
}

C2105017Parser::Func_definitionContext* C2105017Parser::UnitContext::func_definition() {
  return getRuleContext<C2105017Parser::Func_definitionContext>(0);
}


size_t C2105017Parser::UnitContext::getRuleIndex() const {
  return C2105017Parser::RuleUnit;
}

void C2105017Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C2105017Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C2105017Parser::UnitContext* C2105017Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C2105017Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(66);
      antlrcpp::downCast<UnitContext *>(_localctx)->v = var_declaration();

              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->v->text;
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<UnitContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": unit : var_declaration\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(69);
      antlrcpp::downCast<UnitContext *>(_localctx)->f = func_declaration();

              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->f->text;
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<UnitContext *>(_localctx)->f != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->f->stop) : nullptr)->getLine()) + ": unit : func_declaration\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(72);
      antlrcpp::downCast<UnitContext *>(_localctx)->fd = func_definition();

              antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fd->text;
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<UnitContext *>(_localctx)->fd != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->fd->stop) : nullptr)->getLine()) + ": unit : func_definition\n\n" + _localctx->text + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C2105017Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105017Parser::Func_declarationContext::LPAREN() {
  return getToken(C2105017Parser::LPAREN, 0);
}

tree::TerminalNode* C2105017Parser::Func_declarationContext::RPAREN() {
  return getToken(C2105017Parser::RPAREN, 0);
}

C2105017Parser::Type_specifierContext* C2105017Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C2105017Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105017Parser::Func_declarationContext::ID() {
  return getToken(C2105017Parser::ID, 0);
}

tree::TerminalNode* C2105017Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C2105017Parser::SEMICOLON, 0);
}

C2105017Parser::Parameter_listContext* C2105017Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C2105017Parser::Parameter_listContext>(0);
}


size_t C2105017Parser::Func_declarationContext::getRuleIndex() const {
  return C2105017Parser::RuleFunc_declaration;
}

void C2105017Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C2105017Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C2105017Parser::Func_declarationContext* C2105017Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C2105017Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(77);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(78);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(79);
      match(C2105017Parser::LPAREN);
      setState(80);
      match(C2105017Parser::RPAREN);
      setState(81);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm = match(C2105017Parser::SEMICOLON);

              // Insert function with no parameters
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() + "();";
              if (symbolTable->Insert(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText(), "ID")) {
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText());
                  if (sym) {
                      sym->setDataType("function");
                      sym->setFunctionInfo(make_shared<FunctionInfo>(antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text, nullptr, 0));
                  }
              } else {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() + "\n");
              }
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(84);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(85);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(86);
      match(C2105017Parser::LPAREN);

              insertParams = false;
              clearCurrentParamTypes();
            
      setState(88);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl = parameter_list(0);
      setState(89);
      match(C2105017Parser::RPAREN);
      setState(90);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm = match(C2105017Parser::SEMICOLON);

              // Insert function with parameters after parameter list is parsed
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() + "(" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->pl->text + ");";
              if (symbolTable->Insert(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText(), "ID")) {
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText());
                  if (sym) {
                      sym->setDataType("function");
                      sym->setFunctionInfo(make_shared<FunctionInfo>(
                          antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text,
                          currentParamTypes.empty() ? nullptr : currentParamTypes.data(),
                          currentParamTypes.size()
                      ));
                  }
              } else {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText() + "\n");
              }
              // Store parameter types for this function name
              functionParamTypes[antlrcpp::downCast<Func_declarationContext *>(_localctx)->id->getText()] = currentParamTypes;
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->sm->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n" + _localctx->text + "\n");
            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C2105017Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Type_specifierContext* C2105017Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C2105017Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105017Parser::Func_definitionContext::ID() {
  return getToken(C2105017Parser::ID, 0);
}

tree::TerminalNode* C2105017Parser::Func_definitionContext::LPAREN() {
  return getToken(C2105017Parser::LPAREN, 0);
}

tree::TerminalNode* C2105017Parser::Func_definitionContext::RPAREN() {
  return getToken(C2105017Parser::RPAREN, 0);
}

C2105017Parser::Compound_statementContext* C2105017Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C2105017Parser::Compound_statementContext>(0);
}

C2105017Parser::Parameter_listContext* C2105017Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C2105017Parser::Parameter_listContext>(0);
}


size_t C2105017Parser::Func_definitionContext::getRuleIndex() const {
  return C2105017Parser::RuleFunc_definition;
}

void C2105017Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C2105017Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C2105017Parser::Func_definitionContext* C2105017Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C2105017Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(95);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(96);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(97);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp = match(C2105017Parser::LPAREN);
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp = match(C2105017Parser::RPAREN);

              // Insert function with no parameters
              if (symbolTable->Insert(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText(), "ID")) {
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
                  if (sym) {
                      sym->setDataType("function");
                      sym->setFunctionInfo(make_shared<FunctionInfo>(antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text, nullptr, 0));
                  }
              } else {
                  // Check for redeclaration or return type mismatch
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
                  if (sym) {
                      auto funcInfo = sym->getFunctionInfo();
                      if (funcInfo) {
                          if (funcInfo->getReturnType() != antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text) {
                              writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                          }
                      } else {
                          writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                      }
                  }
              }
              symbolTable->enterScope();
              isFunctionBlock = true;
              insertParams = true;
              currentFunctionReturnType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text;
              currentFunctionName = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText();
              currentLocalOffset = 2;
              localVariableSpace = 0;  // Reset local variable space counter
              parameterCount = 0;

              // Write function prologue to tempCodeFile
              if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() == "main") {
                  tempCodeFile << "MAIN PROC\n    MOV AX, @DATA\n    MOV DS, AX\n";
              } else {
                  tempCodeFile << antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() << " PROC\n";
              }
              tempCodeFile << "    PUSH BP\n    MOV BP, SP\n";
            
      setState(100);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "()" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              // Write function epilogue to tempCodeFile
              if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() == "main") {
                  tempCodeFile << "MAIN ENDP\n";
              } else {
                  if (localVariableSpace > 0) {
                      tempCodeFile << "    ADD SP, " << localVariableSpace << "\n";  // Clean up local variable space
                  }
                  tempCodeFile << "    POP BP\n";
                  tempCodeFile << "    RET " << parameterCount * 2 << "\n";
                  tempCodeFile << antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() << " ENDP\n";
              }
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->stop) : nullptr)->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" + _localctx->text + "\n");
              symbolTable->exitScope();
              isFunctionBlock = false;
              insertParams = false;
            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(104);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(105);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp = match(C2105017Parser::LPAREN);

              // Insert function with parameters (parameters handled after parameter_list)
              if (symbolTable->Insert(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText(), "ID")) {
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
                  if (sym) {
                      sym->setDataType("function");
                      clearCurrentParamTypes();
                  }
              } else {
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
                  if (sym) {
                      if (sym->getDataType() == "variable") {
                          writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                      }
                  }
              }
              symbolTable->enterScope();
              isFunctionBlock = true;
              insertParams = true;
              currentParamTypes.clear();
              currentFunctionReturnType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text;
              currentFunctionName = antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText();
              currentLocalOffset = 2;
              localVariableSpace = 0;  // Reset local variable space counter

              // Write function prologue to tempCodeFile
              if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() == "main") {
                  tempCodeFile << "MAIN PROC\n    MOV AX, @DATA\n    MOV DS, AX\n";
              } else {
                  tempCodeFile << antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() << " PROC\n";
              }
              tempCodeFile << "    PUSH BP\n    MOV BP, SP\n";
            
      setState(107);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl = parameter_list(0);
      setState(108);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp = match(C2105017Parser::RPAREN);

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

              auto sym = symbolTable->LookUp(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
              if (sym) {
                  // Compare with previously declared parameter types for this function
                  auto it = functionParamTypes.find(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText());
                  if (it != functionParamTypes.end()) {
                      const auto& declaredParams = it->second;
                      if (declaredParams.size() != currentParamTypes.size()) {
                          writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                      } else {
                          for (int i = 0; i < declaredParams.size(); ++i) {
                              if (declaredParams[i] != currentParamTypes[i]) {
                                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": " + to_string(i+1) + "th argument mismatch in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                                  break;
                              }
                          }
                      }
                  }
                  auto prevFuncInfo = sym->getFunctionInfo();
                  if (prevFuncInfo) {
                      if (prevFuncInfo->getReturnType() != antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text) {
                          writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "\n");
                      }
                  }
                  sym->setFunctionInfo(make_shared<FunctionInfo>(
                      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text,
                      currentParamTypes.empty() ? nullptr : currentParamTypes.data(),
                      currentParamTypes.size()
                  ));
              }
              // Update the function's parameter types in the map (for definition)
              functionParamTypes[antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText()] = currentParamTypes;
          
      setState(110);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs = compound_statement();

              isFunctionBlock = false;
              antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() + "(" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->text + ")" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->text;
              // Write function epilogue to tempCodeFile
              if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() == "main") {
                  tempCodeFile << "MAIN ENDP\n";
              } else {
                  if (localVariableSpace > 0) {
                      tempCodeFile << "    ADD SP, " << localVariableSpace << "\n";  // Clean up local variable space
                  }
                  tempCodeFile << "    POP BP\n";
                  tempCodeFile << "    RET " << parameterCount * 2 << "\n";
                  tempCodeFile << antlrcpp::downCast<Func_definitionContext *>(_localctx)->id->getText() << " ENDP\n";
              }
              if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->pl->text.find(' ') != string::npos) {
                  writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->stop) : nullptr)->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" + _localctx->text + "\n");
              } else {
                  writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->cs->stop) : nullptr)->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" + _localctx->text + "\n");
              }
              symbolTable->exitScope();
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C2105017Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Type_specifierContext* C2105017Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C2105017Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105017Parser::Parameter_listContext::ID() {
  return getToken(C2105017Parser::ID, 0);
}

tree::TerminalNode* C2105017Parser::Parameter_listContext::COMMA() {
  return getToken(C2105017Parser::COMMA, 0);
}

C2105017Parser::Parameter_listContext* C2105017Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C2105017Parser::Parameter_listContext>(0);
}


size_t C2105017Parser::Parameter_listContext::getRuleIndex() const {
  return C2105017Parser::RuleParameter_list;
}

void C2105017Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C2105017Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C2105017Parser::Parameter_listContext* C2105017Parser::parameter_list() {
   return parameter_list(0);
}

C2105017Parser::Parameter_listContext* C2105017Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105017Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C2105017Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C2105017Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(116);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(117);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105017Parser::ID);

              // Single parameter handling - insert into symbol table for function signature
              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
              if (insertParams) {
                  // Insert parameter into current function's local scope
                  if (!symbolTable->Insert(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText(), "ID")) {
                      writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + " in parameter\n");
                  } else {
                      auto sym = symbolTable->LookUp(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText());
                      sym->setIsParameter(true);  // Mark as parameter for offset calculation
                      // Don't set offset here - will be set in a post-processing step
                      parameterCount = 1;  // Track parameter count for stack cleanup
                  }
              }
              // Add parameter type to function signature tracking
              addParamType(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text);
              addParamName(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText());
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getLine()) + ": parameter_list : type_specifier ID\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 2: {

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  "";
          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(131);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
        _localctx->pl = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleParameter_list);
        setState(123);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(124);
        match(C2105017Parser::COMMA);
        setState(125);
        antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
        setState(126);
        antlrcpp::downCast<Parameter_listContext *>(_localctx)->id = match(C2105017Parser::ID);

                          // Multiple parameters - handle recursively and accumulate parameter info
                          antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->pl->text + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText();
                          if (insertParams) {
                              // Insert additional parameter into function's local scope
                              if (!symbolTable->Insert(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText(), "ID")) {
                                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText() + " in parameter\n");
                              } else {
                                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText());
                                  sym->setIsParameter(true);  // Mark as parameter for offset calculation
                                  parameterCount++;  // Increment parameter count for stack management
                                  // Don't set offset here - will be set in a post-processing step
                              }
                          }
                          // Add parameter type to function signature tracking
                          addParamType(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text);
                          addParamName(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getText());
                          writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->id->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n" + _localctx->text + "\n");
                       
      }
      setState(133);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C2105017Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105017Parser::Compound_statementContext::LCURL() {
  return getToken(C2105017Parser::LCURL, 0);
}

tree::TerminalNode* C2105017Parser::Compound_statementContext::RCURL() {
  return getToken(C2105017Parser::RCURL, 0);
}

C2105017Parser::StatementsContext* C2105017Parser::Compound_statementContext::statements() {
  return getRuleContext<C2105017Parser::StatementsContext>(0);
}


size_t C2105017Parser::Compound_statementContext::getRuleIndex() const {
  return C2105017Parser::RuleCompound_statement;
}

void C2105017Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C2105017Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C2105017Parser::Compound_statementContext* C2105017Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, C2105017Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(134);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lc = match(C2105017Parser::LCURL);

              // Enter new scope for block unless this is a function block
              if (!isFunctionBlock) {
                  symbolTable->enterScope();
              }
            
      setState(136);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rc = match(C2105017Parser::RCURL);

              // Empty block - no statements inside
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  "{}";
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rc->getLine()) + ": compound_statement : LCURL RCURL\n\n" + _localctx->text + "\n");
              symbolTable->PrintAllScopeTable();
              if (!isFunctionBlock) {
                  symbolTable->exitScope();  // Exit scope for empty block
              }
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(138);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->lc = match(C2105017Parser::LCURL);

              // Block with statements - manage scope transition
              bool wasFunctionBlock = isFunctionBlock;
              if (!isFunctionBlock) {
                  symbolTable->enterScope();  // Enter new scope for block
              }
              isFunctionBlock = false;  // Reset function block flag
            
      setState(140);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->s = statements(0);
      setState(141);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rc = match(C2105017Parser::RCURL);

              // Block with statements - format text
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  "{\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->s->text + "\n}";
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rc->getLine()) + ": compound_statement : LCURL statements RCURL\n\n" + _localctx->text + "\n");
              symbolTable->PrintAllScopeTable();
              if (!wasFunctionBlock) {
                  symbolTable->exitScope();  // Exit scope for statement block
              }
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C2105017Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Type_specifierContext* C2105017Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C2105017Parser::Type_specifierContext>(0);
}

C2105017Parser::Declaration_listContext* C2105017Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C2105017Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105017Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C2105017Parser::SEMICOLON, 0);
}


size_t C2105017Parser::Var_declarationContext::getRuleIndex() const {
  return C2105017Parser::RuleVar_declaration;
}

void C2105017Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C2105017Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C2105017Parser::Var_declarationContext* C2105017Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, C2105017Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
    setState(147);
    antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text);
    setState(148);
    antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105017Parser::SEMICOLON);

            // Variable declaration with type checking
            antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->text + ";";
            if (antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text == "void") {
                // Void variables are not allowed
                writeIntoErrorFile("Error at line " + to_string((antlrcpp::downCast<Var_declarationContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": Variable type cannot be void\n");
            }
            writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n\n" + _localctx->text + "\n");
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C2105017Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105017Parser::Type_specifierContext::INT() {
  return getToken(C2105017Parser::INT, 0);
}

tree::TerminalNode* C2105017Parser::Type_specifierContext::FLOAT() {
  return getToken(C2105017Parser::FLOAT, 0);
}

tree::TerminalNode* C2105017Parser::Type_specifierContext::VOID() {
  return getToken(C2105017Parser::VOID, 0);
}


size_t C2105017Parser::Type_specifierContext::getRuleIndex() const {
  return C2105017Parser::RuleType_specifier;
}

void C2105017Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C2105017Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C2105017Parser::Type_specifierContext* C2105017Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 16, C2105017Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(157);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105017Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(151);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C2105017Parser::INT);

                // Integer type specifier
                antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  "int";
                writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT\n\nint\n");
            
        break;
      }

      case C2105017Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(153);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C2105017Parser::FLOAT);

                // Floating point type specifier
                antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  "float";
                writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT\n\nfloat\n");
            
        break;
      }

      case C2105017Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(155);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C2105017Parser::VOID);

                // Void type specifier (for functions only)
                antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  "void";
                writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine()) + ": type_specifier : VOID\n\nvoid\n");
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C2105017Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState, string type)
  : ParserRuleContext(parent, invokingState) {
  this->type = type;
}

C2105017Parser::Declaration_itemContext* C2105017Parser::Declaration_listContext::declaration_item() {
  return getRuleContext<C2105017Parser::Declaration_itemContext>(0);
}

C2105017Parser::Declaration_list_tailContext* C2105017Parser::Declaration_listContext::declaration_list_tail() {
  return getRuleContext<C2105017Parser::Declaration_list_tailContext>(0);
}


size_t C2105017Parser::Declaration_listContext::getRuleIndex() const {
  return C2105017Parser::RuleDeclaration_list;
}

void C2105017Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C2105017Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}

C2105017Parser::Declaration_listContext* C2105017Parser::declaration_list(string type) {
  Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, getState(), type);
  enterRule(_localctx, 18, C2105017Parser::RuleDeclaration_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    antlrcpp::downCast<Declaration_listContext *>(_localctx)->first = declaration_item(_localctx->type);

            // Parse first declaration item and log the rule
            writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->first->line) + ": declaration_list : " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->first->ruleName + "\n\n" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->first->text + "\n");
          
    setState(161);
    antlrcpp::downCast<Declaration_listContext *>(_localctx)->rest = declaration_list_tail(_localctx->type, antlrcpp::downCast<Declaration_listContext *>(_localctx)->first->text);

            // Combine first item with remaining items
            antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->first->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rest->text;
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_list_tailContext ------------------------------------------------------------------

C2105017Parser::Declaration_list_tailContext::Declaration_list_tailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Declaration_list_tailContext::Declaration_list_tailContext(ParserRuleContext *parent, size_t invokingState, string type, string builtSoFar)
  : ParserRuleContext(parent, invokingState) {
  this->type = type;
  this->builtSoFar = builtSoFar;
}

tree::TerminalNode* C2105017Parser::Declaration_list_tailContext::COMMA() {
  return getToken(C2105017Parser::COMMA, 0);
}

C2105017Parser::Declaration_itemContext* C2105017Parser::Declaration_list_tailContext::declaration_item() {
  return getRuleContext<C2105017Parser::Declaration_itemContext>(0);
}

C2105017Parser::Declaration_list_tailContext* C2105017Parser::Declaration_list_tailContext::declaration_list_tail() {
  return getRuleContext<C2105017Parser::Declaration_list_tailContext>(0);
}


size_t C2105017Parser::Declaration_list_tailContext::getRuleIndex() const {
  return C2105017Parser::RuleDeclaration_list_tail;
}

void C2105017Parser::Declaration_list_tailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_tail(this);
}

void C2105017Parser::Declaration_list_tailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_tail(this);
}

C2105017Parser::Declaration_list_tailContext* C2105017Parser::declaration_list_tail(string type,string builtSoFar) {
  Declaration_list_tailContext *_localctx = _tracker.createInstance<Declaration_list_tailContext>(_ctx, getState(), type, builtSoFar);
  enterRule(_localctx, 20, C2105017Parser::RuleDeclaration_list_tail);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105017Parser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(164);
        match(C2105017Parser::COMMA);
        setState(165);
        antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->next = declaration_item(_localctx->type);

                // Handle additional declaration items in the list
                string newList = builtSoFar + "," + antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->next->text;
                writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->next->line) + ": declaration_list : declaration_list COMMA " + antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->next->ruleName + "\n\n" + newList + "\n");
              
        setState(167);
        antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->rest = declaration_list_tail(_localctx->type, builtSoFar + "," + antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->next->text);

                // Recursively build the comma-separated list
                antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->text =  "," + antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->next->text + antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->rest->text;
            
        break;
      }

      case C2105017Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);

                // Empty tail - end of declaration list
                antlrcpp::downCast<Declaration_list_tailContext *>(_localctx)->text =  "";
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_itemContext ------------------------------------------------------------------

C2105017Parser::Declaration_itemContext::Declaration_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Declaration_itemContext::Declaration_itemContext(ParserRuleContext *parent, size_t invokingState, string type)
  : ParserRuleContext(parent, invokingState) {
  this->type = type;
}

tree::TerminalNode* C2105017Parser::Declaration_itemContext::ID() {
  return getToken(C2105017Parser::ID, 0);
}

tree::TerminalNode* C2105017Parser::Declaration_itemContext::LTHIRD() {
  return getToken(C2105017Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105017Parser::Declaration_itemContext::RTHIRD() {
  return getToken(C2105017Parser::RTHIRD, 0);
}

tree::TerminalNode* C2105017Parser::Declaration_itemContext::CONST_INT() {
  return getToken(C2105017Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105017Parser::Declaration_itemContext::ASSIGNOP() {
  return getToken(C2105017Parser::ASSIGNOP, 0);
}

C2105017Parser::Logic_expressionContext* C2105017Parser::Declaration_itemContext::logic_expression() {
  return getRuleContext<C2105017Parser::Logic_expressionContext>(0);
}


size_t C2105017Parser::Declaration_itemContext::getRuleIndex() const {
  return C2105017Parser::RuleDeclaration_item;
}

void C2105017Parser::Declaration_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_item(this);
}

void C2105017Parser::Declaration_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_item(this);
}

C2105017Parser::Declaration_itemContext* C2105017Parser::declaration_item(string type) {
  Declaration_itemContext *_localctx = _tracker.createInstance<Declaration_itemContext>(_ctx, getState(), type);
  enterRule(_localctx, 22, C2105017Parser::RuleDeclaration_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(173);
      antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id = match(C2105017Parser::ID);

              // Simple variable declaration
              antlrcpp::downCast<Declaration_itemContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText();
              antlrcpp::downCast<Declaration_itemContext *>(_localctx)->ruleName =  "ID";
              antlrcpp::downCast<Declaration_itemContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine();
              // Insert variable into symbol table with type information
              if (!symbolTable->Insert(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText(), "ID")) {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText() + "\n");
              } else {
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText());
                  if (sym) {
                      sym->setDeclaredType(_localctx->type);  // Set the declared type (int, float, etc.)
                      sym->setDataType("variable");  // Mark as variable (not array/function)
                      // Check if this is a global variable by examining current scope
                      if (symbolTable->getCurrentScope()->getParentScope() == nullptr) {
                          // Global variable - add to data segment
                          dataSegment += antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText() + " DW 1 DUP (0000H)\n";
                      } else {
                          // Local variable - allocate stack space and write to tempCodeFile
                          sym->setOffset(-currentLocalOffset);  // Negative offset for local variables
                          currentLocalOffset += 2;  // 2 bytes for each variable
                          localVariableSpace += 2;  // Track space allocated for local variables
                          tempCodeFile << "    SUB SP, 2\t; Line " << antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine() << "\n";
                      }
                  }
              }
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(175);
      antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(176);
      match(C2105017Parser::LTHIRD);
      setState(177);
      antlrcpp::downCast<Declaration_itemContext *>(_localctx)->ci = match(C2105017Parser::CONST_INT);
      setState(178);
      match(C2105017Parser::RTHIRD);

              // Array declaration with specified size
              antlrcpp::downCast<Declaration_itemContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText() + "[" + antlrcpp::downCast<Declaration_itemContext *>(_localctx)->ci->getText() + "]";
              antlrcpp::downCast<Declaration_itemContext *>(_localctx)->ruleName =  "ID LTHIRD CONST_INT RTHIRD";
              antlrcpp::downCast<Declaration_itemContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine();
              // Insert array into symbol table with size information
              if (!symbolTable->Insert(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText(), "ID")) {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText() + "\n");
              } else {
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText());
                  if (sym) {
                      sym->setDeclaredType(_localctx->type);  // Set the declared type (int, float, etc.)
                      sym->setDataType("array");    // Mark as array type
                      int size = stoi(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->ci->getText());  // Parse array size
                      // Check if this is a global array by examining current scope
                      if (symbolTable->getCurrentScope()->getParentScope() == nullptr) {
                          // Global array - add to data segment with specified size
                          dataSegment += antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText() + " DW " + to_string(size) + " DUP(0)\n";
                      } else {
                          // Local array - allocate stack space based on size and write to tempCodeFile
                          sym->setOffset(-currentLocalOffset);  // Negative offset for local arrays
                          currentLocalOffset += size * 2;  // 2 bytes per element
                          localVariableSpace += size * 2;  // Track space allocated for local arrays
                          tempCodeFile << "    SUB SP, " << size * 2 << "\t; Line " << antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine() << "\n";
                      }
                  }
              }
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(180);
      antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(181);
      match(C2105017Parser::ASSIGNOP);
      setState(182);
      antlrcpp::downCast<Declaration_itemContext *>(_localctx)->init = logic_expression();

              antlrcpp::downCast<Declaration_itemContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText() + " = " + antlrcpp::downCast<Declaration_itemContext *>(_localctx)->init->text;
              antlrcpp::downCast<Declaration_itemContext *>(_localctx)->ruleName =  "ID ASSIGNOP logic_expression";
              antlrcpp::downCast<Declaration_itemContext *>(_localctx)->line =  antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine();
              // Insert variable into symbol table
              if (!symbolTable->Insert(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText(), "ID")) {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText() + "\n");
              } else {
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText());
                  if (sym) {
                      sym->setDeclaredType(_localctx->type);
                      sym->setDataType("variable");
                  }
                  // Check if this is a global variable by examining current scope
                  if (symbolTable->getCurrentScope()->getParentScope() == nullptr) {
                      // Global variable - add to data segment
                      dataSegment += antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText() + " DW 1 DUP (0000H)\n";
                      // Global variables with initialization: generate code to store the value
                      // The logic_expression result is already in AX
                      tempCodeFile << "    MOV " + getVarAccess(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText()) + ", AX\t; Line " << antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine() << "\n";
                  } else {
                      // Local variable - allocate stack space and write to tempCodeFile
                      sym->setOffset(-currentLocalOffset);  // Negative offset for local variables
                      currentLocalOffset += 2;  // 2 bytes for each variable
                      localVariableSpace += 2;  // Track space allocated for local variables
                      tempCodeFile << "    SUB SP, 2\t; Line " << antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine() << "\n";
                      // Generate code for initialization - the logic_expression result is already in AX
                      tempCodeFile << "    MOV " + getVarAccess(antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getText()) + ", AX\t; Line " << antlrcpp::downCast<Declaration_itemContext *>(_localctx)->id->getLine() << "\n";
                  }
              }
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C2105017Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::StatementContext* C2105017Parser::StatementsContext::statement() {
  return getRuleContext<C2105017Parser::StatementContext>(0);
}

C2105017Parser::StatementsContext* C2105017Parser::StatementsContext::statements() {
  return getRuleContext<C2105017Parser::StatementsContext>(0);
}


size_t C2105017Parser::StatementsContext::getRuleIndex() const {
  return C2105017Parser::RuleStatements;
}

void C2105017Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C2105017Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C2105017Parser::StatementsContext* C2105017Parser::statements() {
   return statements(0);
}

C2105017Parser::StatementsContext* C2105017Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105017Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C2105017Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, C2105017Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(188);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

            // Single statement
            antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
            if (!_localctx->text.empty()) {
                writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statements : statement\n\n" + _localctx->text + "\n");
            }
        
    _ctx->stop = _input->LT(-1);
    setState(197);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->sl = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(191);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(192);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                          // Multiple statements - accumulate text
                          antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->sl->text + "\n" + antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
                          if (!antlrcpp::downCast<StatementsContext *>(_localctx)->s->text.empty()) {
                              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statements : statements statement\n\n" + _localctx->text + "\n");
                          }
                       
      }
      setState(199);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C2105017Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Var_declarationContext* C2105017Parser::StatementContext::var_declaration() {
  return getRuleContext<C2105017Parser::Var_declarationContext>(0);
}

std::vector<C2105017Parser::Expression_statementContext *> C2105017Parser::StatementContext::expression_statement() {
  return getRuleContexts<C2105017Parser::Expression_statementContext>();
}

C2105017Parser::Expression_statementContext* C2105017Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C2105017Parser::Expression_statementContext>(i);
}

C2105017Parser::Compound_statementContext* C2105017Parser::StatementContext::compound_statement() {
  return getRuleContext<C2105017Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C2105017Parser::StatementContext::FOR() {
  return getToken(C2105017Parser::FOR, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::LPAREN() {
  return getToken(C2105017Parser::LPAREN, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::RPAREN() {
  return getToken(C2105017Parser::RPAREN, 0);
}

C2105017Parser::ExpressionContext* C2105017Parser::StatementContext::expression() {
  return getRuleContext<C2105017Parser::ExpressionContext>(0);
}

std::vector<C2105017Parser::StatementContext *> C2105017Parser::StatementContext::statement() {
  return getRuleContexts<C2105017Parser::StatementContext>();
}

C2105017Parser::StatementContext* C2105017Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C2105017Parser::StatementContext>(i);
}

tree::TerminalNode* C2105017Parser::StatementContext::IF() {
  return getToken(C2105017Parser::IF, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::ELSE() {
  return getToken(C2105017Parser::ELSE, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::WHILE() {
  return getToken(C2105017Parser::WHILE, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::PRINTLN() {
  return getToken(C2105017Parser::PRINTLN, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::SEMICOLON() {
  return getToken(C2105017Parser::SEMICOLON, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::ID() {
  return getToken(C2105017Parser::ID, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::LTHIRD() {
  return getToken(C2105017Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::RTHIRD() {
  return getToken(C2105017Parser::RTHIRD, 0);
}

tree::TerminalNode* C2105017Parser::StatementContext::RETURN() {
  return getToken(C2105017Parser::RETURN, 0);
}


size_t C2105017Parser::StatementContext::getRuleIndex() const {
  return C2105017Parser::RuleStatement;
}

void C2105017Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C2105017Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C2105017Parser::StatementContext* C2105017Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 26, C2105017Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(274);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(200);
      antlrcpp::downCast<StatementContext *>(_localctx)->v = var_declaration();

              // Variable declaration statement
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->v->text;
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": statement : var_declaration\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(203);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

              // Expression statement (assignments, function calls, etc.)
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->text;
              if (!_localctx->text.empty()) {
                  writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->es != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->es->stop) : nullptr)->getLine()) + ": statement : expression_statement\n\n" + _localctx->text + "\n");
              }
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(206);
      antlrcpp::downCast<StatementContext *>(_localctx)->cs = compound_statement();

              // Compound statement (block of statements)
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->cs->text;
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->cs != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->cs->stop) : nullptr)->getLine()) + ": statement : compound_statement\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(209);
      match(C2105017Parser::FOR);
      setState(210);
      match(C2105017Parser::LPAREN);

              string startLabel = newLabel();  // Label for loop start
              string updateLabel = newLabel();  // Label for loop start
              string bodyLabel = newLabel();  // Label for loop body
              string endLabel = newLabel();    // Label for loop exit
          
      setState(212);
      antlrcpp::downCast<StatementContext *>(_localctx)->forInit = expression_statement();

              tempCodeFile << startLabel << ":\n";     // Loop start label
          
      setState(214);
      antlrcpp::downCast<StatementContext *>(_localctx)->forCond = expression_statement();

              tempCodeFile << "    CMP AX, 0\n    JE " << endLabel << "\n";  // Exit if condition false
              tempCodeFile << "    JMP " << bodyLabel << "\n";  // Jump to loop body
              tempCodeFile << updateLabel << ":\n";  // Update label for increment
          
      setState(216);
      antlrcpp::downCast<StatementContext *>(_localctx)->forInc = expression();
      setState(217);
      match(C2105017Parser::RPAREN);

              tempCodeFile << "    JMP " << startLabel << "\n";  // Jump back to condition check
              tempCodeFile << bodyLabel << ":\n";      // Loop body label
          
      setState(219);
      antlrcpp::downCast<StatementContext *>(_localctx)->forBody = statement();

              // For loop with initialization, condition, increment, and body
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "for(" + antlrcpp::downCast<StatementContext *>(_localctx)->forInit->text + antlrcpp::downCast<StatementContext *>(_localctx)->forCond->text + antlrcpp::downCast<StatementContext *>(_localctx)->forInc->text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->forBody->text;
              // forBody code written when parsing forBody
              tempCodeFile << "    JMP " << updateLabel << "\n";  // Jump back to condition check
              tempCodeFile << endLabel << ":\n";        // Loop exit label
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->forBody != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->forBody->stop) : nullptr)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(222);
      match(C2105017Parser::IF);
      setState(223);
      match(C2105017Parser::LPAREN);
      setState(224);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifCond = expression();
      setState(225);
      match(C2105017Parser::RPAREN);

              string endLabel = newLabel();    // Label for end of if statement
              tempCodeFile << "    CMP AX, 0\n    JE " << endLabel << "\n";  // Skip if condition false
          
      setState(227);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifThen = statement();

              // If statement without else clause
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "if(" + antlrcpp::downCast<StatementContext *>(_localctx)->ifCond->text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->ifThen->text;
              // ifCond code written when parsing ifCond
              // ifThen code written when parsing ifThen
              tempCodeFile << endLabel << ":\n";        // End of if statement
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->ifThen != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->ifThen->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(230);
      match(C2105017Parser::IF);
      setState(231);
      match(C2105017Parser::LPAREN);
      setState(232);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifCond = expression();
      setState(233);
      match(C2105017Parser::RPAREN);

              string startLabel = newLabel();   // Label for else clause
              tempCodeFile << "    CMP AX, 0\n    JE " << startLabel << "\n";  // Jump to else if condition false
          
      setState(235);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifThen = statement();
      setState(236);
      match(C2105017Parser::ELSE);

              string endLabel = newLabel();    // Label for end of if-else
              tempCodeFile << "    JMP " << endLabel << "\n";  // Skip else clause
              tempCodeFile << startLabel << ":\n";      // Else clause label
          
      setState(238);
      antlrcpp::downCast<StatementContext *>(_localctx)->ifElse = statement();

              // If statement with else clause
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "if(" + antlrcpp::downCast<StatementContext *>(_localctx)->ifCond->text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->ifThen->text + "else " + antlrcpp::downCast<StatementContext *>(_localctx)->ifElse->text;
              // ifCond code written when parsing ifCond
              // ifThen code written when parsing ifThen
              // ifElse code written when parsing ifElse
              tempCodeFile << endLabel << ":\n";        // End of if-else statement
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->ifElse != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->ifElse->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(241);
      match(C2105017Parser::WHILE);
      setState(242);
      match(C2105017Parser::LPAREN);

              string startLabel = newLabel();  // Label for loop start
              string endLabel = newLabel();    // Label for loop exit
              tempCodeFile << startLabel << ":\n";     // Loop start label
          
      setState(244);
      antlrcpp::downCast<StatementContext *>(_localctx)->whileCond = expression();
      setState(245);
      match(C2105017Parser::RPAREN);

              tempCodeFile << "    CMP AX, 0\n    JE " << endLabel << "\n";  // Exit if condition false
          
      setState(247);
      antlrcpp::downCast<StatementContext *>(_localctx)->whileBody = statement();

              // While loop with condition and body
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "while(" + antlrcpp::downCast<StatementContext *>(_localctx)->whileCond->text + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->whileBody->text;
              // whileCond code written when parsing whileCond
              // whileBody code written when parsing whileBody
              tempCodeFile << "    JMP " << startLabel << "\n";  // Jump back to condition check
              tempCodeFile << endLabel << ":\n";        // Loop exit label
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<StatementContext *>(_localctx)->whileBody != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->whileBody->stop) : nullptr)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(250);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C2105017Parser::PRINTLN);
      setState(251);
      match(C2105017Parser::LPAREN);
      setState(252);
      antlrcpp::downCast<StatementContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(253);
      match(C2105017Parser::RPAREN);
      setState(254);
      match(C2105017Parser::SEMICOLON);

              // Print statement for variable output
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "printf(" + antlrcpp::downCast<StatementContext *>(_localctx)->id->getText() + ");";
              string varAccess = getVarAccess(antlrcpp::downCast<StatementContext *>(_localctx)->id->getText());  // Get variable access method
              hasPrintln = true;  // Mark that println is used (for procedure inclusion)
              tempCodeFile << "    MOV AX, " << varAccess << "\t; Line " << antlrcpp::downCast<StatementContext *>(_localctx)->id->getLine() << "\n";
              tempCodeFile << "    CALL PRINT_OUTPUT\n";
              tempCodeFile << "    CALL NEW_LINE\n";
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" + _localctx->text + "\n");
              // Check if variable is declared and is printable
              auto sym = symbolTable->LookUp(antlrcpp::downCast<StatementContext *>(_localctx)->id->getText());
              if (!sym) {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->id->getText() + "\n");
              } else if (sym->getDataType() != "variable" && sym->getDataType() != "array") {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()) + ": Cannot print non-variable type " + sym->getDeclaredType() + "\n");
              }
          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(256);
      antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken = match(C2105017Parser::PRINTLN);
      setState(257);
      match(C2105017Parser::LPAREN);
      setState(258);
      antlrcpp::downCast<StatementContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(259);
      match(C2105017Parser::LTHIRD);
      setState(260);
      antlrcpp::downCast<StatementContext *>(_localctx)->index = expression();
      setState(261);
      match(C2105017Parser::RTHIRD);
      setState(262);
      match(C2105017Parser::RPAREN);
      setState(263);
      match(C2105017Parser::SEMICOLON);

              // Print statement for array element output
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "printf(" + antlrcpp::downCast<StatementContext *>(_localctx)->id->getText() + "[" + antlrcpp::downCast<StatementContext *>(_localctx)->index->text + "]);";
              hasPrintln = true;  // Mark that println is used (for procedure inclusion)
              auto sym = symbolTable->LookUp(antlrcpp::downCast<StatementContext *>(_localctx)->id->getText());
              int offset = sym->getOffset();
              tempCodeFile << "    MOV SI, AX\n    SHL SI, 1\n";  // Multiply index by 2 (word size) in SI
              // Local array - calculate absolute address (negative offset)
              tempCodeFile << "    MOV BX, BP\n";  // Copy BP to BX
              tempCodeFile << "    ADD BX, SI\n";  // Add index to BP
              tempCodeFile << "    SUB BX, " + to_string(abs(offset)) + "\n";  // Subtract absolute offset
              tempCodeFile << "    MOV AX, [BX]\n";  // Load using calculated address
              tempCodeFile << "    CALL PRINT_OUTPUT\n";
              tempCodeFile << "    CALL NEW_LINE\n";
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()) + ": statement : PRINTLN LPAREN ID LTHIRD expression RTHIRD RPAREN SEMICOLON\n\n" + _localctx->text + "\n");
              // Check if variable is declared and is printable
              if (!sym) {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->id->getText() + "\n");
              } else if (sym->getDataType() != "array") {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->printlnToken->getLine()) + ": Cannot print non-array type " + sym->getDeclaredType() + "\n");
              }
          
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(266);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105017Parser::RETURN);
      setState(267);
      antlrcpp::downCast<StatementContext *>(_localctx)->expr = expression();
      setState(268);
      match(C2105017Parser::SEMICOLON);

              // Return statement with value - check return type compatibility
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "return " + antlrcpp::downCast<StatementContext *>(_localctx)->expr->text + ";";
              // expr code written when parsing expr
              if (currentFunctionName == "main") {
                  if (localVariableSpace > 0) {
                      tempCodeFile << "    ADD SP, " << localVariableSpace << "\n";  // Clean up local variable space
                  }
                  tempCodeFile << "    POP BP\n";
                  tempCodeFile << "    MOV AX, 4CH\n    INT 21H\n";
              } else {
                  if (localVariableSpace > 0) {
                      tempCodeFile << "    ADD SP, " << localVariableSpace << "\n";  // Clean up local variable space
                  }
                  tempCodeFile << "    POP BP\n";
                  tempCodeFile << "    RET " << parameterCount * 2 << "\n";
              }
              if (currentFunctionReturnType == "void") {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine() + 1) + ": Cannot return value from function " + currentFunctionName + " with void return type\n");
              }
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(271);
      antlrcpp::downCast<StatementContext *>(_localctx)->returnToken = match(C2105017Parser::RETURN);
      setState(272);
      match(C2105017Parser::SEMICOLON);

              // Return statement without value - valid for void functions
              antlrcpp::downCast<StatementContext *>(_localctx)->text =  "return;";
              if (currentFunctionName == "main") {
                  if (localVariableSpace > 0) {
                      tempCodeFile << "    ADD SP, " << localVariableSpace << "\n";  // Clean up local variable space
                  }
                  tempCodeFile << "    POP BP\n";
                  tempCodeFile << "    MOV AX, 4CH\n    INT 21H\n";
              } else {
                  if (localVariableSpace > 0) {
                      tempCodeFile << "    ADD SP, " << localVariableSpace << "\n";  // Clean up local variable space
                  }
                  tempCodeFile << "    POP BP\n";
                  tempCodeFile << "    RET " << parameterCount * 2 << "\n";
              }
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<StatementContext *>(_localctx)->returnToken->getLine()) + ": statement : RETURN SEMICOLON\n\n" + _localctx->text + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C2105017Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105017Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C2105017Parser::SEMICOLON, 0);
}

C2105017Parser::ExpressionContext* C2105017Parser::Expression_statementContext::expression() {
  return getRuleContext<C2105017Parser::ExpressionContext>(0);
}


size_t C2105017Parser::Expression_statementContext::getRuleIndex() const {
  return C2105017Parser::RuleExpression_statement;
}

void C2105017Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C2105017Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C2105017Parser::Expression_statementContext* C2105017Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 28, C2105017Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(276);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->sm = match(C2105017Parser::SEMICOLON);

              // Empty statement - just a semicolon
              antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  ";";
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->sm->getLine()) + ": expression_statement : SEMICOLON\n\n;\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(278);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
      setState(279);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->sm = match(C2105017Parser::SEMICOLON);

              // Expression followed by semicolon
              antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->text + ";";
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->sm->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(282);
      antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();

              // Expression without semicolon (used in for loops)
              antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  "";
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C2105017Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105017Parser::VariableContext::ID() {
  return getToken(C2105017Parser::ID, 0);
}

tree::TerminalNode* C2105017Parser::VariableContext::LTHIRD() {
  return getToken(C2105017Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105017Parser::VariableContext::RTHIRD() {
  return getToken(C2105017Parser::RTHIRD, 0);
}

C2105017Parser::ExpressionContext* C2105017Parser::VariableContext::expression() {
  return getRuleContext<C2105017Parser::ExpressionContext>(0);
}


size_t C2105017Parser::VariableContext::getRuleIndex() const {
  return C2105017Parser::RuleVariable;
}

void C2105017Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C2105017Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C2105017Parser::VariableContext* C2105017Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 30, C2105017Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(296);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(287);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C2105017Parser::ID);

              // Simple variable access
              antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->id->getText();
              _localctx->argTypes.clear();
              antlrcpp::downCast<VariableContext *>(_localctx)->arrayName =  "";

              if (isAssignmentContext) {
                  tempCodeFile << "    MOV " + getVarAccess(antlrcpp::downCast<VariableContext *>(_localctx)->id->getText()) + ", AX\t; Line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + "\n";
              } else {
                  // Load variable value into AX for use in expressions
                  tempCodeFile << "    MOV AX, " + getVarAccess(antlrcpp::downCast<VariableContext *>(_localctx)->id->getText()) + "\t; Line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + "\n";
              }

              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": variable : ID\n\n" + _localctx->text + "\n");
              // Check if variable is declared and get its type
              auto sym = symbolTable->LookUp(antlrcpp::downCast<VariableContext *>(_localctx)->id->getText());
              if (sym) {
                  if (sym->getDataType() == "array") {
                      _localctx->argTypes.push_back("array");
                  } else {
                      _localctx->argTypes.push_back(sym->getDeclaredType());
                  }
              } else {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + "\n");
              }
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(289);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(290);
      match(C2105017Parser::LTHIRD);

              bool wasAssignmentContext = isAssignmentContext;  // Save current context
              if (isAssignmentContext) {
                  tempCodeFile << "    PUSH AX\n";  // Save index expression result
                  isAssignmentContext = false;  // Reset assignment context for index expression
              }
          
      setState(292);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(293);
      match(C2105017Parser::RTHIRD);

              // Array element access with index expression
              antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->e->text + "]";
              _localctx->argTypes.clear();
              antlrcpp::downCast<VariableContext *>(_localctx)->arrayName =  antlrcpp::downCast<VariableContext *>(_localctx)->id->getText();

              isAssignmentContext = wasAssignmentContext;  // Restore assignment context

              auto sym = symbolTable->LookUp(antlrcpp::downCast<VariableContext *>(_localctx)->id->getText());
              if (sym) {
                  // Check if this is a global or local array using helper function
                  bool isGlobal = isGlobalArray(antlrcpp::downCast<VariableContext *>(_localctx)->id->getText());

                  if (isGlobal) {
                      // Global array - use direct addressing with array name
                      // e code written when parsing e
                      tempCodeFile << "    MOV BX, AX\n    SHL BX, 1\n";  // Multiply index by 2 (word size)
                      if (isAssignmentContext) {
                          tempCodeFile << "    POP AX\n";  // Restore assignment value
                          tempCodeFile << "    MOV [" + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + " + BX], AX\n";  // Store to array element
                      } else {
                          tempCodeFile << "    MOV AX, [" + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + " + BX]\n";  // Load array element into AX
                      }
                  } else {
                      // Local array - use BP-relative addressing with valid 8086 addressing modes
                      int offset = sym->getOffset();
                      tempCodeFile << "    MOV SI, AX\n    SHL SI, 1\n";  // Multiply index by 2 (word size) in SI
                      // Local array - calculate absolute address (negative offset)
                      tempCodeFile << "    MOV BX, BP\n";  // Copy BP to BX
                      tempCodeFile << "    ADD BX, SI\n";  // Add index to BP
                      tempCodeFile << "    SUB BX, " + to_string(abs(offset)) + "\n";  // Subtract absolute offset
                      if (isAssignmentContext) {
                          tempCodeFile << "    POP AX\n";  // Restore assignment value
                          tempCodeFile << "    MOV [BX], AX\n";  // Store using calculated address
                      } else {
                          tempCodeFile << "    MOV AX, [BX]\n";  // Load using calculated address
                      }
                  }
              }
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + _localctx->text + "\n");
              // Validate that identifier is actually an array
              auto symCheck = symbolTable->LookUp(antlrcpp::downCast<VariableContext *>(_localctx)->id->getText());
              if (symCheck) {
                  if (symCheck->getDataType() != "array") {
                      writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": " + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + " not an array\n");
                  }
                  _localctx->argTypes.push_back(symCheck->getDeclaredType());
              } else {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Undeclared array " + antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + "\n");
              }
              // Check that index expression is integer (not float)
              bool isFloat = antlrcpp::downCast<VariableContext *>(_localctx)->e->text.find('.') != string::npos;
              bool isNumeric = !antlrcpp::downCast<VariableContext *>(_localctx)->e->text.empty() && antlrcpp::downCast<VariableContext *>(_localctx)->e->text.find_first_not_of("0123456789.") == string::npos;
              if (isFloat && isNumeric) {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": Expression inside third brackets not an integer\n");
              }
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C2105017Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Logic_expressionContext* C2105017Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C2105017Parser::Logic_expressionContext>(0);
}

C2105017Parser::VariableContext* C2105017Parser::ExpressionContext::variable() {
  return getRuleContext<C2105017Parser::VariableContext>(0);
}

tree::TerminalNode* C2105017Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C2105017Parser::ASSIGNOP, 0);
}


size_t C2105017Parser::ExpressionContext::getRuleIndex() const {
  return C2105017Parser::RuleExpression;
}

void C2105017Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C2105017Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C2105017Parser::ExpressionContext* C2105017Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C2105017Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(298);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

              // Simple logic expression without assignment
              antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
              antlrcpp::downCast<ExpressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<ExpressionContext *>(_localctx)->le->argTypes;
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->le != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->le->stop) : nullptr)->getLine()) + ": expression : logic_expression\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

              isAssignmentContext = true;  // Mark context as assignment
              string startLabel = newLabel();  // Label for assignment start
              string exprLabel = newLabel();  // Label for expression evaluation
              string endLabel = newLabel();    // Label for assignment end
              tempCodeFile << "    JMP " << exprLabel << "\n";  // Jump to assignment start
              tempCodeFile << startLabel << ":\n";  // Start label for assignment
          
      setState(302);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();

              isAssignmentContext = false;  // Reset assignment context
              isExpressionStatement = true;  // Mark as expression statement for assignment
              tempCodeFile << "    JMP " << endLabel << "\n";  // Jump to end of assignment
              tempCodeFile << exprLabel << ":\n";  // Label for expression evaluation
          
      setState(304);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->ao = match(C2105017Parser::ASSIGNOP);
      setState(305);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->le = logic_expression();

              isExpressionStatement = false;  // Reset expression statement flag
              // Complete assignment operation
              antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text + "=" + antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
              _localctx->argTypes.clear();

              tempCodeFile << "    JMP " << startLabel << "\n";  // Jump to assignment start
              tempCodeFile << endLabel << ":\n";

              if (antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text.find(' ') == std::string::npos) {
                  writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->ao->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + _localctx->text + "\n");
              } else {
                  string trimmedText = antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text;
                  if (!trimmedText.empty() && trimmedText.back() == ' ') trimmedText.pop_back();
                  writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->le != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->le->stop) : nullptr)->getLine() + 1) + ": expression : logic_expression\n\n" + trimmedText + "\n");
              }

              // Type checking for assignment compatibility
              auto sym = symbolTable->LookUp(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text);
              if (!sym && !antlrcpp::downCast<ExpressionContext *>(_localctx)->v->arrayName.empty()) {
                  sym = symbolTable->LookUp(antlrcpp::downCast<ExpressionContext *>(_localctx)->v->arrayName);
              }
              if (sym) {
                  if (sym->getDataType() == "array" && !antlrcpp::downCast<ExpressionContext *>(_localctx)->v->arrayName.empty()) {
                      // Assignment to array element - check type compatibility
                      string varType = sym->getDeclaredType();
                      bool isFloatLiteral = antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text.find('.') != string::npos;
                      if (varType == "int" && isFloatLiteral && antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text.find('%') == string::npos) {
                          writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->ao->getLine()) + ": Type Mismatch\n");
                      }
                  } else if (sym->getDataType() == "array") {
                      writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->ao->getLine()) + ": Type mismatch, " + antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text + " is an array\n");
                  } else {
                      // Assignment to simple variable - check type compatibility
                      string varType = sym->getDeclaredType();
                      bool isFloatLiteral = antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text.find('.') != string::npos;
                      if (varType == "int" && isFloatLiteral && antlrcpp::downCast<ExpressionContext *>(_localctx)->le->text.find('%') == string::npos) {
                          writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<ExpressionContext *>(_localctx)->ao->getLine()) + ": Type Mismatch\n");
                      }
                  }
              }
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C2105017Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105017Parser::Rel_expressionContext *> C2105017Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C2105017Parser::Rel_expressionContext>();
}

C2105017Parser::Rel_expressionContext* C2105017Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C2105017Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C2105017Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C2105017Parser::LOGICOP, 0);
}


size_t C2105017Parser::Logic_expressionContext::getRuleIndex() const {
  return C2105017Parser::RuleLogic_expression;
}

void C2105017Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C2105017Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C2105017Parser::Logic_expressionContext* C2105017Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C2105017Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(319);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(310);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re = rel_expression();

              // Simple relational expression
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->text;
              string trimmedText = _localctx->text;
              if (!trimmedText.empty() && trimmedText.back() == ' ') {
                  trimmedText.pop_back();
                  writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re != nullptr ? (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->stop) : nullptr)->getLine() + 1) + ": logic_expression : rel_expression\n\n" + trimmedText + "\n");
              } else {
                  writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re != nullptr ? (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->stop) : nullptr)->getLine()) + ": logic_expression : rel_expression\n\n" + _localctx->text + "\n");
              }
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->re->argTypes;
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(313);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->l = rel_expression();
      setState(314);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lo = match(C2105017Parser::LOGICOP);

              string startLabel = newLabel();
              string endLabel = newLabel();
              if (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lo->getText() == "&&") {
                  tempCodeFile << "    CMP AX, 0\n    JE " << startLabel << "\n";
              } else { // ||
                  tempCodeFile << "    CMP AX, 0\n    JNE " << startLabel << "\n";
              }
          
      setState(316);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r = rel_expression();

              // Binary logical operation (AND/OR)
              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->l->text + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lo->getText() + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->text;
              _localctx->argTypes.clear();
              if (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lo->getText() == "&&") {
                  // Logical AND - both operands must be true
                  // l code written when parsing l
                  // r code written when parsing r
                  tempCodeFile << "    CMP AX, 0\n    JE " << startLabel << "\n";
                  tempCodeFile << "    MOV AX, 1\n    JMP " << endLabel << "\n";
                  tempCodeFile << startLabel << ":\n    MOV AX, 0\n";
                  tempCodeFile << endLabel << ":\n";
              } else { // ||
                  // Logical OR - either operand can be true
                  // l code written when parsing l
                  // r code written when parsing r
                  tempCodeFile << "    CMP AX, 0\n    JNE " << startLabel << "\n";
                  tempCodeFile << "    MOV AX, 0\n    JMP " << endLabel << "\n";
                  tempCodeFile << startLabel << ":\n    MOV AX, 1\n";
                  tempCodeFile << endLabel << ":\n";
              }
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->lo->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" + _localctx->text + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C2105017Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105017Parser::Simple_expressionContext *> C2105017Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C2105017Parser::Simple_expressionContext>();
}

C2105017Parser::Simple_expressionContext* C2105017Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C2105017Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C2105017Parser::Rel_expressionContext::RELOP() {
  return getToken(C2105017Parser::RELOP, 0);
}


size_t C2105017Parser::Rel_expressionContext::getRuleIndex() const {
  return C2105017Parser::RuleRel_expression;
}

void C2105017Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C2105017Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C2105017Parser::Rel_expressionContext* C2105017Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, C2105017Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(330);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(321);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se = simple_expression(0);

              // Simple arithmetic expression
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->text;
              string trimmedText = _localctx->text;
              if (!trimmedText.empty() && trimmedText.back() == ' ') {
                  trimmedText.pop_back();
                  writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se != nullptr ? (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->stop) : nullptr)->getLine() + 1) + ": rel_expression : simple_expression\n\n" + trimmedText + "\n");
              } else {
                  writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se != nullptr ? (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->stop) : nullptr)->getLine()) + ": rel_expression : simple_expression\n\n" + _localctx->text + "\n");
              }
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->se->argTypes;
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(324);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->l = simple_expression(0);
       tempCodeFile << "    PUSH AX\n"; 
      setState(326);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro = match(C2105017Parser::RELOP);
      setState(327);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->r = simple_expression(0);

              // Binary relational comparison operation
              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->l->text + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->r->text;
              _localctx->argTypes.clear();
              string trueLabel = newLabel();   // Label for true result
              string endLabel = newLabel();    // Label for end of comparison
              // r code written when parsing r
              tempCodeFile << "    POP BX\n    CMP BX, AX\n";  // Compare left (BX) with right (AX)

              // Generate appropriate jump instruction based on comparison operator
              if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro->getText() == "<") tempCodeFile << "    JL ";
              else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro->getText() == ">") tempCodeFile << "    JG ";
              else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro->getText() == "==") tempCodeFile << "    JE ";
              else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro->getText() == "!=") tempCodeFile << "    JNE ";
              else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro->getText() == "<=") tempCodeFile << "    JLE ";
              else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro->getText() == ">=") tempCodeFile << "    JGE ";

              tempCodeFile << trueLabel << "\n    MOV AX, 0\n    JMP " << endLabel << "\n";  // False case
              tempCodeFile << trueLabel << ":\n    MOV AX, 1\n";                           // True case
              tempCodeFile << endLabel << ":\n";
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->ro->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" + _localctx->text + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C2105017Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::TermContext* C2105017Parser::Simple_expressionContext::term() {
  return getRuleContext<C2105017Parser::TermContext>(0);
}

C2105017Parser::Simple_expressionContext* C2105017Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C2105017Parser::Simple_expressionContext>(0);
}

tree::TerminalNode* C2105017Parser::Simple_expressionContext::ADDOP() {
  return getToken(C2105017Parser::ADDOP, 0);
}


size_t C2105017Parser::Simple_expressionContext::getRuleIndex() const {
  return C2105017Parser::RuleSimple_expression;
}

void C2105017Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C2105017Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C2105017Parser::Simple_expressionContext* C2105017Parser::simple_expression() {
   return simple_expression(0);
}

C2105017Parser::Simple_expressionContext* C2105017Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105017Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C2105017Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C2105017Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(333);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

            // Single term (no addition/subtraction)
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->argTypes;
            writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->stop) : nullptr)->getLine()) + ": simple_expression : term\n\n" + _localctx->text + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(344);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->se = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(336);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
         tempCodeFile << "    PUSH AX\n"; 
        setState(338);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao = match(C2105017Parser::ADDOP);
        setState(339);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                          // Binary addition or subtraction operation
                          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->se->text + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao->getText() + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->argTypes;
                          // se code written, then PUSH AX above, t code written when parsing t
                          tempCodeFile << "    POP BX\n";
                          tempCodeFile << (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao->getText() == "+" ? "    ADD" : "    SUB") << " BX, AX\n";
                          tempCodeFile << "    MOV AX, BX\n";
                          writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->ao->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" + _localctx->text + "\n");
                       
      }
      setState(346);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C2105017Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Unary_expressionContext* C2105017Parser::TermContext::unary_expression() {
  return getRuleContext<C2105017Parser::Unary_expressionContext>(0);
}

C2105017Parser::TermContext* C2105017Parser::TermContext::term() {
  return getRuleContext<C2105017Parser::TermContext>(0);
}

tree::TerminalNode* C2105017Parser::TermContext::MULOP() {
  return getToken(C2105017Parser::MULOP, 0);
}


size_t C2105017Parser::TermContext::getRuleIndex() const {
  return C2105017Parser::RuleTerm;
}

void C2105017Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C2105017Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C2105017Parser::TermContext* C2105017Parser::term() {
   return term(0);
}

C2105017Parser::TermContext* C2105017Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105017Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C2105017Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, C2105017Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(348);
    antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

            // Single unary expression (no multiplication/division/modulus)
            antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->ue->text;
            antlrcpp::downCast<TermContext *>(_localctx)->argTypes =  antlrcpp::downCast<TermContext *>(_localctx)->ue->argTypes;
            writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<TermContext *>(_localctx)->ue != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->ue->stop) : nullptr)->getLine()) + ": term : unary_expression\n\n" + _localctx->text + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(359);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->t = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(351);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
         tempCodeFile << "    PUSH AX\n"; 
        setState(353);
        antlrcpp::downCast<TermContext *>(_localctx)->mo = match(C2105017Parser::MULOP);
        setState(354);
        antlrcpp::downCast<TermContext *>(_localctx)->ue = unary_expression();

                          // Binary multiplication, division, or modulus operation
                          antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->t->text + antlrcpp::downCast<TermContext *>(_localctx)->mo->getText() + antlrcpp::downCast<TermContext *>(_localctx)->ue->text;
                          _localctx->argTypes.clear();
                          // t code written, then PUSH AX above, ue code written when parsing ue
                          tempCodeFile << "    MOV BX, AX\n";
                          tempCodeFile << "    POP AX\n";

                          // Generate appropriate assembly instruction based on operator
                          if (antlrcpp::downCast<TermContext *>(_localctx)->mo->getText() == "*") {
                              tempCodeFile << "    XOR DX, DX\n    MUL BX\n";  // Unsigned multiplication
                          } else if (antlrcpp::downCast<TermContext *>(_localctx)->mo->getText() == "/") {
                              tempCodeFile << "    XOR DX, DX\n    DIV BX\n";  // Unsigned division (quotient in AX)
                          } else { // %
                              tempCodeFile << "    XOR DX, DX\n    DIV BX\n    MOV AX, DX\n";  // Modulus (remainder in DX)
                          }
                          writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<TermContext *>(_localctx)->mo->getLine()) + ": term : term MULOP unary_expression\n\n" + _localctx->text + "\n");

                          // Error checking for division/modulus by zero and type compatibility
                          if (antlrcpp::downCast<TermContext *>(_localctx)->mo->getText() == "%" && antlrcpp::downCast<TermContext *>(_localctx)->ue->text == "0") {
                              writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<TermContext *>(_localctx)->mo->getLine()) + ": Modulus by Zero\n");
                          }
                          if (antlrcpp::downCast<TermContext *>(_localctx)->mo->getText() == "%" && (
                                  antlrcpp::downCast<TermContext *>(_localctx)->t->text.find('.') != string::npos ||
                                  antlrcpp::downCast<TermContext *>(_localctx)->ue->text.find('.') != string::npos)) {
                              writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<TermContext *>(_localctx)->mo->getLine()) + ": Non-Integer operand on modulus operator\n");
                          }
                          if (antlrcpp::downCast<TermContext *>(_localctx)->mo->getText() == "/" && (antlrcpp::downCast<TermContext *>(_localctx)->ue->text == "0" || antlrcpp::downCast<TermContext *>(_localctx)->ue->text == "0.0")) {
                              writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<TermContext *>(_localctx)->mo->getLine()) + ": Division by Zero\n");
                          }
                       
      }
      setState(361);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C2105017Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105017Parser::Unary_expressionContext::ADDOP() {
  return getToken(C2105017Parser::ADDOP, 0);
}

C2105017Parser::Unary_expressionContext* C2105017Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C2105017Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105017Parser::Unary_expressionContext::NOT() {
  return getToken(C2105017Parser::NOT, 0);
}

tree::TerminalNode* C2105017Parser::Unary_expressionContext::INCOP() {
  return getToken(C2105017Parser::INCOP, 0);
}

C2105017Parser::VariableContext* C2105017Parser::Unary_expressionContext::variable() {
  return getRuleContext<C2105017Parser::VariableContext>(0);
}

tree::TerminalNode* C2105017Parser::Unary_expressionContext::DECOP() {
  return getToken(C2105017Parser::DECOP, 0);
}

C2105017Parser::FactorContext* C2105017Parser::Unary_expressionContext::factor() {
  return getRuleContext<C2105017Parser::FactorContext>(0);
}


size_t C2105017Parser::Unary_expressionContext::getRuleIndex() const {
  return C2105017Parser::RuleUnary_expression;
}

void C2105017Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C2105017Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C2105017Parser::Unary_expressionContext* C2105017Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 42, C2105017Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(381);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105017Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(362);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ao = match(C2105017Parser::ADDOP);
        setState(363);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

                // Unary plus or minus operation
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ao->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->argTypes;
                // ue code written when parsing ue
                if (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ao->getText() == "-") tempCodeFile << "    NEG AX\n";  // Negate for unary minus
                // Note: Unary plus does nothing, so no additional assembly needed
                writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ao->getLine()) + ": unary_expression : ADDOP unary_expression\n\n" + _localctx->text + "\n");
            
        break;
      }

      case C2105017Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(366);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->n = match(C2105017Parser::NOT);
        setState(367);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue = unary_expression();

                // Logical NOT operation
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  "!" + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->text;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->ue->argTypes;
                // ue code written when parsing ue
                tempCodeFile << "    CMP AX, 0\n    MOV AX, 0\n    SETZ AL\n";  // Set AL to 1 if AX was 0
                writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->n->getLine()) + ": unary_expression : NOT unary_expression\n\n" + _localctx->text + "\n");
            
        break;
      }

      case C2105017Parser::INCOP: {
        enterOuterAlt(_localctx, 3);
        setState(370);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->io = match(C2105017Parser::INCOP);
        setState(371);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v = variable();

                // Pre-increment operation (++var)
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  "++" + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->text;
                if (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName.empty()) {
                    // Simple variable pre-increment
                    string varAccess = getVarAccess(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->text);
                    tempCodeFile << "    INC WORD PTR " << varAccess << "\n    MOV AX, " << varAccess << "\n";
                } else {
                    // Array element pre-increment - need special handling for global vs local arrays
                    auto sym = symbolTable->LookUp(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName);
                    if (sym) {
                        // Check if this is a global or local array using helper function
                        bool isGlobal = isGlobalArray(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName);

                        if (isGlobal) {
                            // Global array pre-increment
                            // v code written when parsing v, ends with load into AX
                            tempCodeFile << "    INC WORD PTR [" << antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName << " + BX]\n";
                            tempCodeFile << "    MOV AX, [" << antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName << " + BX]\n";
                        } else {
                            // Local array pre-increment
                            // v code written when parsing v, ends with load into AX
                            tempCodeFile << "    INC WORD PTR [BP + SI]\n";
                            tempCodeFile << "    MOV AX, [BP + SI]\n";
                        }
                    } else {
                        tempCodeFile << "    ; Error: Array not found\n";
                    }
                }
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->argTypes;
                writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->io->getLine()) + ": unary_expression : INCOP variable\n\n" + _localctx->text + "\n");
            
        break;
      }

      case C2105017Parser::DECOP: {
        enterOuterAlt(_localctx, 4);
        setState(374);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->doo = match(C2105017Parser::DECOP);
        setState(375);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v = variable();

                // Pre-decrement operation (--var)
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  "--" + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->text;
                if (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName.empty()) {
                    // Simple variable pre-decrement
                    string varAccess = getVarAccess(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->text);
                    tempCodeFile << "    DEC WORD PTR " << varAccess << "\n    MOV AX, " << varAccess << "\n";
                } else {
                    // Array element pre-decrement - need special handling for global vs local arrays
                    auto sym = symbolTable->LookUp(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName);
                    if (sym) {
                        // Check if this is a global or local array using helper function
                        bool isGlobal = isGlobalArray(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName);

                        if (isGlobal) {
                            // Global array pre-decrement
                            // v code written when parsing v, ends with load into AX
                            tempCodeFile << "    DEC WORD PTR [" << antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName << " + BX]\n";
                            tempCodeFile << "    MOV AX, [" << antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->arrayName << " + BX]\n";
                        } else {
                            // Local array pre-decrement
                            // v code written when parsing v, ends with load into AX
                            tempCodeFile << "    DEC WORD PTR [BP + SI]\n";
                            tempCodeFile << "    MOV AX, [BP + SI]\n";
                        }
                    } else {
                        tempCodeFile << "    ; Error: Array not found\n";
                    }
                }
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->v->argTypes;
                writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->doo->getLine()) + ": unary_expression : DECOP variable\n\n" + _localctx->text + "\n");
            
        break;
      }

      case C2105017Parser::LPAREN:
      case C2105017Parser::ID:
      case C2105017Parser::CONST_INT:
      case C2105017Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 5);
        setState(378);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();

                // Factor expression (highest precedence)
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->text;
                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->argTypes =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->argTypes;
                writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f != nullptr ? (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->stop) : nullptr)->getLine()) + ": unary_expression : factor\n\n" + _localctx->text + "\n");
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C2105017Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::VariableContext* C2105017Parser::FactorContext::variable() {
  return getRuleContext<C2105017Parser::VariableContext>(0);
}

tree::TerminalNode* C2105017Parser::FactorContext::LPAREN() {
  return getToken(C2105017Parser::LPAREN, 0);
}

tree::TerminalNode* C2105017Parser::FactorContext::RPAREN() {
  return getToken(C2105017Parser::RPAREN, 0);
}

tree::TerminalNode* C2105017Parser::FactorContext::ID() {
  return getToken(C2105017Parser::ID, 0);
}

C2105017Parser::Argument_listContext* C2105017Parser::FactorContext::argument_list() {
  return getRuleContext<C2105017Parser::Argument_listContext>(0);
}

C2105017Parser::ExpressionContext* C2105017Parser::FactorContext::expression() {
  return getRuleContext<C2105017Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105017Parser::FactorContext::CONST_INT() {
  return getToken(C2105017Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105017Parser::FactorContext::CONST_FLOAT() {
  return getToken(C2105017Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C2105017Parser::FactorContext::INCOP() {
  return getToken(C2105017Parser::INCOP, 0);
}

tree::TerminalNode* C2105017Parser::FactorContext::DECOP() {
  return getToken(C2105017Parser::DECOP, 0);
}


size_t C2105017Parser::FactorContext::getRuleIndex() const {
  return C2105017Parser::RuleFactor;
}

void C2105017Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C2105017Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C2105017Parser::FactorContext* C2105017Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 44, C2105017Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(409);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(383);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

              // Variable or array element access
              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text;
              _localctx->argTypes.clear();
              writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<FactorContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<FactorContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": factor : variable\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(386);
      antlrcpp::downCast<FactorContext *>(_localctx)->id = match(C2105017Parser::ID);
      setState(387);
      match(C2105017Parser::LPAREN);
      setState(388);
      antlrcpp::downCast<FactorContext *>(_localctx)->al = argument_list();
      setState(389);
      match(C2105017Parser::RPAREN);

              // Function call: check for declaration, argument count/type, void-in-expression
              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "(" + antlrcpp::downCast<FactorContext *>(_localctx)->al->text + ")";
              // al code written when parsing al
              tempCodeFile << "    CALL " << antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() << "\n";
              auto funcSym = symbolTable->LookUp(antlrcpp::downCast<FactorContext *>(_localctx)->id->getText());
              if (!funcSym) {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Undefined function " + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "\n");
              } else if (funcSym->getDataType() != "function") {
                  writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": " + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + " is not a function\n");
              } else {
                  auto funcInfo = funcSym->getFunctionInfo();
                  int expected = funcInfo->getParameterCount();
                  int given = antlrcpp::downCast<FactorContext *>(_localctx)->al->argTypes.size();
                  if (expected != given) {
                      writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "\n");
                  } else {
                      for (int i = 0; i < expected; ++i) {
                          if (antlrcpp::downCast<FactorContext *>(_localctx)->al->argTypes[i] == "array") {
                              writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Type mismatch, " + antlrcpp::downCast<FactorContext *>(_localctx)->al->argNames[i] + " is an array\n");
                          } else if (antlrcpp::downCast<FactorContext *>(_localctx)->al->argTypes[i] != funcInfo->getParameterType(i)) {
                              writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": " + to_string(i+1) + "th argument mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + "\n");
                              break;
                          }
                      }
                  }
                  _localctx->argTypes.clear();
                  _localctx->argTypes.push_back(funcInfo->getReturnType());
                  if (funcInfo->getReturnType() == "void" && isExpressionStatement) {
                      writeIntoErrorFile("Error at line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": Void function used in expression\n");
                  }
              }
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(392);
      antlrcpp::downCast<FactorContext *>(_localctx)->lp = match(C2105017Parser::LPAREN);
      setState(393);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(394);
      antlrcpp::downCast<FactorContext *>(_localctx)->rp = match(C2105017Parser::RPAREN);

              antlrcpp::downCast<FactorContext *>(_localctx)->text =  "(" + antlrcpp::downCast<FactorContext *>(_localctx)->e->text + ")";
              antlrcpp::downCast<FactorContext *>(_localctx)->argTypes =  antlrcpp::downCast<FactorContext *>(_localctx)->e->argTypes;
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->lp->getLine()) + ": factor : LPAREN expression RPAREN\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(397);
      antlrcpp::downCast<FactorContext *>(_localctx)->ci = match(C2105017Parser::CONST_INT);

              // Integer literal constant
              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->ci->getText();
              tempCodeFile << "    MOV AX, " << antlrcpp::downCast<FactorContext *>(_localctx)->ci->getText() << "\n";  // Load integer constant directly into AX register
              _localctx->argTypes.clear();
              _localctx->argTypes.push_back("int");
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->ci->getLine()) + ": factor : CONST_INT\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(399);
      antlrcpp::downCast<FactorContext *>(_localctx)->cf = match(C2105017Parser::CONST_FLOAT);

              // Float literal constant (simplified assembly generation)
              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->cf->getText();
              tempCodeFile << "    MOV AX, " << antlrcpp::downCast<FactorContext *>(_localctx)->cf->getText() << "\n";  // Basic assembly for float (simplified for this implementation)
              _localctx->argTypes.clear();
              _localctx->argTypes.push_back("float");
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->cf->getLine()) + ": factor : CONST_FLOAT\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(401);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(402);
      antlrcpp::downCast<FactorContext *>(_localctx)->io = match(C2105017Parser::INCOP);

              // Post-increment operation (variable++)
              // Returns the original value before incrementing
              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text + "++";
              if (antlrcpp::downCast<FactorContext *>(_localctx)->v->arrayName.empty()) {
                  // Simple variable post-increment
                  string varAccess = getVarAccess(antlrcpp::downCast<FactorContext *>(_localctx)->v->text);
                  // Post-increment: load original value, then increment variable, then load new value
                  // Variable rule already loaded original value into AX
                  tempCodeFile << "    INC WORD PTR " << varAccess << "\n";     // Increment the variable
              } else {
                  // Array element post-increment - need special handling for global vs local arrays
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<FactorContext *>(_localctx)->v->arrayName);
                  if (sym) {
                      // Check if this is a global or local array using helper function
                      bool isGlobal = isGlobalArray(antlrcpp::downCast<FactorContext *>(_localctx)->v->arrayName);

                      if (isGlobal) {
                          // Global array post-increment using direct memory addressing
                          // v code written when parsing v, ends with load into AX
                          tempCodeFile << "    INC WORD PTR [" << antlrcpp::downCast<FactorContext *>(_localctx)->v->arrayName << " + BX]\n"; // Increment array element
                      } else {
                          // Local array post-increment using stack-based addressing
                          // v code written when parsing v, ends with load into AX
                          tempCodeFile << "    INC WORD PTR [BP + SI]\n";   // Increment array element
                      }
                  } else {
                      tempCodeFile << "    ; Error: Array not found\n";
                  }
              }
              antlrcpp::downCast<FactorContext *>(_localctx)->argTypes =  antlrcpp::downCast<FactorContext *>(_localctx)->v->argTypes;
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->io->getLine()) + ": factor : variable INCOP\n\n" + _localctx->text + "\n");
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(405);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(406);
      antlrcpp::downCast<FactorContext *>(_localctx)->doo = match(C2105017Parser::DECOP);

              // Post-decrement operation (variable--)
              // Returns the original value before decrementing
              antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text + "--";
              if (antlrcpp::downCast<FactorContext *>(_localctx)->v->arrayName.empty()) {
                  // Simple variable post-decrement
                  string varAccess = getVarAccess(antlrcpp::downCast<FactorContext *>(_localctx)->v->text);
                  tempCodeFile << "    DEC WORD PTR " << varAccess << "\n";
              } else {
                  // Array element post-decrement - need special handling for global vs local arrays
                  auto sym = symbolTable->LookUp(antlrcpp::downCast<FactorContext *>(_localctx)->v->arrayName);
                  if (sym) {
                      // Check if this is a global or local array using helper function
                      bool isGlobal = isGlobalArray(antlrcpp::downCast<FactorContext *>(_localctx)->v->arrayName);

                      if (isGlobal) {
                          // Global array post-decrement using direct memory addressing
                          // v code written when parsing v, ends with load into AX
                          tempCodeFile << "    MOV AX, [" << antlrcpp::downCast<FactorContext *>(_localctx)->v->arrayName << " + BX]\n";
                          tempCodeFile << "    DEC WORD PTR [" << antlrcpp::downCast<FactorContext *>(_localctx)->v->arrayName << " + BX]\n";
                      } else {
                          // Local array post-decrement using stack-based addressing
                          // v code written when parsing v, ends with load into AX
                          tempCodeFile << "    MOV AX, [BP + SI]\n";
                          tempCodeFile << "    DEC WORD PTR [BP + SI]\n";
                      }
                  } else {
                      tempCodeFile << "    ; Error: Array not found\n";
                  }
              }
              antlrcpp::downCast<FactorContext *>(_localctx)->argTypes =  antlrcpp::downCast<FactorContext *>(_localctx)->v->argTypes;
              writeIntoParserLogFile("Line " + to_string(antlrcpp::downCast<FactorContext *>(_localctx)->doo->getLine()) + ": factor : variable DECOP\n\n" + _localctx->text + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C2105017Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::ArgumentsContext* C2105017Parser::Argument_listContext::arguments() {
  return getRuleContext<C2105017Parser::ArgumentsContext>(0);
}


size_t C2105017Parser::Argument_listContext::getRuleIndex() const {
  return C2105017Parser::RuleArgument_list;
}

void C2105017Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C2105017Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C2105017Parser::Argument_listContext* C2105017Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 46, C2105017Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(415);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105017Parser::ADDOP:
      case C2105017Parser::INCOP:
      case C2105017Parser::DECOP:
      case C2105017Parser::NOT:
      case C2105017Parser::LPAREN:
      case C2105017Parser::ID:
      case C2105017Parser::CONST_INT:
      case C2105017Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(411);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);

                // Non-empty argument list - delegate to arguments rule
                antlrcpp::downCast<Argument_listContext *>(_localctx)->text =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->text;
                antlrcpp::downCast<Argument_listContext *>(_localctx)->argTypes =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->argTypes;
                antlrcpp::downCast<Argument_listContext *>(_localctx)->argNames =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->argNames;
                writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<Argument_listContext *>(_localctx)->a != nullptr ? (antlrcpp::downCast<Argument_listContext *>(_localctx)->a->stop) : nullptr)->getLine()) + ": argument_list : arguments\n\n" + _localctx->text + "\n");
            
        break;
      }

      case C2105017Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

                // Empty argument list (function called with no parameters)
                antlrcpp::downCast<Argument_listContext *>(_localctx)->text =  "";
                _localctx->argTypes.clear();
                _localctx->argNames.clear();
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C2105017Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105017Parser::Logic_expressionContext* C2105017Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C2105017Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C2105017Parser::ArgumentsContext::COMMA() {
  return getToken(C2105017Parser::COMMA, 0);
}

C2105017Parser::ArgumentsContext* C2105017Parser::ArgumentsContext::arguments() {
  return getRuleContext<C2105017Parser::ArgumentsContext>(0);
}


size_t C2105017Parser::ArgumentsContext::getRuleIndex() const {
  return C2105017Parser::RuleArguments;
}

void C2105017Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C2105017Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105017ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C2105017Parser::ArgumentsContext* C2105017Parser::arguments() {
   return arguments(0);
}

C2105017Parser::ArgumentsContext* C2105017Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105017Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C2105017Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, C2105017Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(418);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();

            // Single argument - evaluate expression and push to stack
            antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
            // le code written when parsing le
            tempCodeFile << "    PUSH AX\n";  // Push evaluated expression result onto stack for function call

            // Determine argument type and name for semantic checking
            string argType = "int";  // Default type
            string argName = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
            auto sym = symbolTable->LookUp(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text);
            if (sym) {
                // Symbol found - use its declared type, but check for arrays
                argType = sym->getDataType() == "array" ? "array" : sym->getDeclaredType();
            } else if (antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text.find('.') != string::npos) {
                // Float literal detection (simple heuristic)
                argType = "float";
            }

            _localctx->argTypes.clear();
            _localctx->argTypes.push_back(argType);
            _localctx->argNames.clear();
            _localctx->argNames.push_back(argName);
            writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->le != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->stop) : nullptr)->getLine()) + ": arguments : logic_expression\n\n" + _localctx->text + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(428);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->a = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(421);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(422);
        match(C2105017Parser::COMMA);
        setState(423);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->le = logic_expression();

                          // Multiple arguments - recursive case for comma-separated arguments
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->text + "," + antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                          // a code written when parsing a, le code written when parsing le
                          tempCodeFile << "    PUSH AX\n";  // Push each argument in order

                          // Determine type and name for this additional argument
                          string argType = "int";  // Default type
                          string argName = antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text;
                          auto sym = symbolTable->LookUp(antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text);
                          if (sym) {
                              // Symbol found - use its declared type, but check for arrays
                              argType = sym->getDataType() == "array" ? "array" : sym->getDeclaredType();
                          } else if (antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->text.find('.') != string::npos) {
                              // Float literal detection (simple heuristic)
                              argType = "float";
                          }

                          // Append to existing argument lists (accumulated from previous arguments)
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->argTypes =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->argTypes;
                          _localctx->argTypes.push_back(argType);
                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->argNames =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->argNames;
                          _localctx->argNames.push_back(argName);
                          writeIntoParserLogFile("Line " + to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->le != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->le->stop) : nullptr)->getLine()) + ": arguments : arguments COMMA logic_expression\n\n" + _localctx->text + "\n");
                       
      }
      setState(430);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C2105017Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 12: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 19: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 20: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 24: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C2105017Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105017Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105017Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105017Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105017Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105017Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void C2105017Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105017parserParserInitialize();
#else
  ::antlr4::internal::call_once(c2105017parserParserOnceFlag, c2105017parserParserInitialize);
#endif
}
