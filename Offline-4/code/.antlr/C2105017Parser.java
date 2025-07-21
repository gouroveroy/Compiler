// Generated from c:/Users/User/OneDrive - BUET/BOOKS 3-1/CSE 309/Offline-Online/Offline-4/code/C2105017Parser.g4 by ANTLR 4.13.1

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

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class C2105017Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		IF=1, ELSE=2, FOR=3, WHILE=4, DO=5, SWITCH=6, CASE=7, DEFAULT=8, BREAK=9, 
		CONTINUE=10, RETURN=11, PRINTLN=12, INT=13, FLOAT=14, CHAR=15, DOUBLE=16, 
		VOID=17, LONG=18, SHORT=19, STATIC=20, UNSIGNED=21, GOTO=22, ADDOP=23, 
		MULOP=24, INCOP=25, DECOP=26, RELOP=27, LOGICOP=28, ASSIGNOP=29, BITOP=30, 
		NOT=31, LPAREN=32, RPAREN=33, LCURL=34, RCURL=35, LTHIRD=36, RTHIRD=37, 
		COMMA=38, SEMICOLON=39, ID=40, CONST_INT=41, CONST_FLOAT=42, HASH=43, 
		SINGLE_QUOTE=44, CHAR_EMPTY=45, CHAR_CLOSE=46, CHAR_ERROR_NL=47, DOUBLE_QUOTE=48, 
		STR_CLOSE=49, STR_NL_ERROR=50, LINE_COMMENT=51, BLOCK_COMMENT=52, WS=53, 
		NL=54, UNRECOGNIZED=55;
	public static final int
		RULE_start = 0, RULE_program = 1, RULE_unit = 2, RULE_func_declaration = 3, 
		RULE_func_definition = 4, RULE_parameter_list = 5, RULE_compound_statement = 6, 
		RULE_var_declaration = 7, RULE_type_specifier = 8, RULE_declaration_list = 9, 
		RULE_declaration_list_tail = 10, RULE_declaration_item = 11, RULE_statements = 12, 
		RULE_statement = 13, RULE_expression_statement = 14, RULE_variable = 15, 
		RULE_expression = 16, RULE_logic_expression = 17, RULE_rel_expression = 18, 
		RULE_simple_expression = 19, RULE_term = 20, RULE_unary_expression = 21, 
		RULE_factor = 22, RULE_argument_list = 23, RULE_arguments = 24;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "program", "unit", "func_declaration", "func_definition", "parameter_list", 
			"compound_statement", "var_declaration", "type_specifier", "declaration_list", 
			"declaration_list_tail", "declaration_item", "statements", "statement", 
			"expression_statement", "variable", "expression", "logic_expression", 
			"rel_expression", "simple_expression", "term", "unary_expression", "factor", 
			"argument_list", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'if'", "'else'", "'for'", "'while'", "'do'", "'switch'", "'case'", 
			"'default'", "'break'", "'continue'", "'return'", "'println'", "'int'", 
			"'float'", "'char'", "'double'", "'void'", "'long'", "'short'", "'static'", 
			"'unsigned'", "'goto'", null, null, "'++'", "'--'", null, null, "'='", 
			null, "'!'", "'('", "')'", "'{'", "'}'", "'['", "']'", "','", "';'", 
			null, null, null, "'#'", "'''", null, null, null, "'\"'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "IF", "ELSE", "FOR", "WHILE", "DO", "SWITCH", "CASE", "DEFAULT", 
			"BREAK", "CONTINUE", "RETURN", "PRINTLN", "INT", "FLOAT", "CHAR", "DOUBLE", 
			"VOID", "LONG", "SHORT", "STATIC", "UNSIGNED", "GOTO", "ADDOP", "MULOP", 
			"INCOP", "DECOP", "RELOP", "LOGICOP", "ASSIGNOP", "BITOP", "NOT", "LPAREN", 
			"RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", 
			"ID", "CONST_INT", "CONST_FLOAT", "HASH", "SINGLE_QUOTE", "CHAR_EMPTY", 
			"CHAR_CLOSE", "CHAR_ERROR_NL", "DOUBLE_QUOTE", "STR_CLOSE", "STR_NL_ERROR", 
			"LINE_COMMENT", "BLOCK_COMMENT", "WS", "NL", "UNRECOGNIZED"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C2105017Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


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

	public C2105017Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
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
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public string text;
		public ProgramContext p;
		public UnitContext u;
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		return program(0);
	}

	private ProgramContext program(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ProgramContext _localctx = new ProgramContext(_ctx, _parentState);
		ProgramContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_program, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(54);
			((ProgramContext)_localctx).u = unit();

			        ((ProgramContext)_localctx).text =  ((ProgramContext)_localctx).u.text;
			        writeIntoParserLogFile("Line " + to_string((((ProgramContext)_localctx).u!=null?(((ProgramContext)_localctx).u.stop):null)->getLine()) + ": program : unit\n\n" + _localctx.text + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(63);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramContext(_parentctx, _parentState);
					_localctx.p = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(57);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(58);
					((ProgramContext)_localctx).u = unit();

					                  ((ProgramContext)_localctx).text =  ((ProgramContext)_localctx).p.text + "\n" + ((ProgramContext)_localctx).u.text;
					                  writeIntoParserLogFile("Line " + to_string((((ProgramContext)_localctx).u!=null?(((ProgramContext)_localctx).u.stop):null)->getLine()) + ": program : program unit\n\n" + _localctx.text + "\n");
					              
					}
					} 
				}
				setState(65);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnitContext extends ParserRuleContext {
		public string text;
		public Var_declarationContext v;
		public Func_declarationContext f;
		public Func_definitionContext fd;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public Func_definitionContext func_definition() {
			return getRuleContext(Func_definitionContext.class,0);
		}
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_unit);
		try {
			setState(75);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(66);
				((UnitContext)_localctx).v = var_declaration();

				        ((UnitContext)_localctx).text =  ((UnitContext)_localctx).v.text;
				        writeIntoParserLogFile("Line " + to_string((((UnitContext)_localctx).v!=null?(((UnitContext)_localctx).v.stop):null)->getLine()) + ": unit : var_declaration\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(69);
				((UnitContext)_localctx).f = func_declaration();

				        ((UnitContext)_localctx).text =  ((UnitContext)_localctx).f.text;
				        writeIntoParserLogFile("Line " + to_string((((UnitContext)_localctx).f!=null?(((UnitContext)_localctx).f.stop):null)->getLine()) + ": unit : func_declaration\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(72);
				((UnitContext)_localctx).fd = func_definition();

				        ((UnitContext)_localctx).text =  ((UnitContext)_localctx).fd.text;
				        writeIntoParserLogFile("Line " + to_string((((UnitContext)_localctx).fd!=null?(((UnitContext)_localctx).fd.stop):null)->getLine()) + ": unit : func_definition\n\n" + _localctx.text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_declarationContext extends ParserRuleContext {
		public string text;
		public Type_specifierContext t;
		public Token id;
		public Token sm;
		public Parameter_listContext pl;
		public TerminalNode LPAREN() { return getToken(C2105017Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105017Parser.RPAREN, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105017Parser.ID, 0); }
		public TerminalNode SEMICOLON() { return getToken(C2105017Parser.SEMICOLON, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(93);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(77);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(78);
				((Func_declarationContext)_localctx).id = match(ID);
				setState(79);
				match(LPAREN);
				setState(80);
				match(RPAREN);
				setState(81);
				((Func_declarationContext)_localctx).sm = match(SEMICOLON);

				        // Insert function with no parameters
				        ((Func_declarationContext)_localctx).text =  ((Func_declarationContext)_localctx).t.text + " " + ((Func_declarationContext)_localctx).id->getText() + "();";
				        if (symbolTable->Insert(((Func_declarationContext)_localctx).id->getText(), "ID")) {
				            auto sym = symbolTable->LookUp(((Func_declarationContext)_localctx).id->getText());
				            if (sym) {
				                sym->setDataType("function");
				                sym->setFunctionInfo(make_shared<FunctionInfo>(((Func_declarationContext)_localctx).t.text, nullptr, 0));
				            }
				        } else {
				            writeIntoErrorFile("Error at line " + to_string(((Func_declarationContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Func_declarationContext)_localctx).id->getText() + "\n");
				        }
				        writeIntoParserLogFile("Line " + to_string(((Func_declarationContext)_localctx).sm->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(84);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(85);
				((Func_declarationContext)_localctx).id = match(ID);
				setState(86);
				match(LPAREN);

				        insertParams = false;
				        clearCurrentParamTypes();
				      
				setState(88);
				((Func_declarationContext)_localctx).pl = parameter_list(0);
				setState(89);
				match(RPAREN);
				setState(90);
				((Func_declarationContext)_localctx).sm = match(SEMICOLON);

				        // Insert function with parameters after parameter list is parsed
				        ((Func_declarationContext)_localctx).text =  ((Func_declarationContext)_localctx).t.text + " " + ((Func_declarationContext)_localctx).id->getText() + "(" + ((Func_declarationContext)_localctx).pl.text + ");";
				        if (symbolTable->Insert(((Func_declarationContext)_localctx).id->getText(), "ID")) {
				            auto sym = symbolTable->LookUp(((Func_declarationContext)_localctx).id->getText());
				            if (sym) {
				                sym->setDataType("function");
				                sym->setFunctionInfo(make_shared<FunctionInfo>(
				                    ((Func_declarationContext)_localctx).t.text,
				                    currentParamTypes.empty() ? nullptr : currentParamTypes.data(),
				                    currentParamTypes.size()
				                ));
				            }
				        } else {
				            writeIntoErrorFile("Error at line " + to_string(((Func_declarationContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Func_declarationContext)_localctx).id->getText() + "\n");
				        }
				        // Store parameter types for this function name
				        functionParamTypes[((Func_declarationContext)_localctx).id->getText()] = currentParamTypes;
				        writeIntoParserLogFile("Line " + to_string(((Func_declarationContext)_localctx).sm->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n" + _localctx.text + "\n");
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_definitionContext extends ParserRuleContext {
		public string text;
		public Type_specifierContext t;
		public Token id;
		public Token lp;
		public Token rp;
		public Compound_statementContext cs;
		public Parameter_listContext pl;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105017Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C2105017Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105017Parser.RPAREN, 0); }
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Func_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_definition; }
	}

	public final Func_definitionContext func_definition() throws RecognitionException {
		Func_definitionContext _localctx = new Func_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_definition);
		try {
			setState(113);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(95);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(96);
				((Func_definitionContext)_localctx).id = match(ID);
				setState(97);
				((Func_definitionContext)_localctx).lp = match(LPAREN);
				setState(98);
				((Func_definitionContext)_localctx).rp = match(RPAREN);

				        // Insert function with no parameters
				        if (symbolTable->Insert(((Func_definitionContext)_localctx).id->getText(), "ID")) {
				            auto sym = symbolTable->LookUp(((Func_definitionContext)_localctx).id->getText());
				            if (sym) {
				                sym->setDataType("function");
				                sym->setFunctionInfo(make_shared<FunctionInfo>(((Func_definitionContext)_localctx).t.text, nullptr, 0));
				            }
				        } else {
				            // Check for redeclaration or return type mismatch
				            auto sym = symbolTable->LookUp(((Func_definitionContext)_localctx).id->getText());
				            if (sym) {
				                auto funcInfo = sym->getFunctionInfo();
				                if (funcInfo) {
				                    if (funcInfo->getReturnType() != ((Func_definitionContext)_localctx).t.text) {
				                        writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Return type mismatch of " + ((Func_definitionContext)_localctx).id->getText() + "\n");
				                    }
				                } else {
				                    writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).id->getText() + "\n");
				                }
				            }
				        }
				        symbolTable->enterScope();
				        isFunctionBlock = true;
				        insertParams = true;
				        currentFunctionReturnType = ((Func_definitionContext)_localctx).t.text;
				        currentFunctionName = ((Func_definitionContext)_localctx).id->getText();
				        currentLocalOffset = 2;
				        localVariableSpace = 0;  // Reset local variable space counter
				        parameterCount = 0;

				        // Write function prologue to tempCodeFile
				        if (((Func_definitionContext)_localctx).id->getText() == "main") {
				            tempCodeFile << "MAIN PROC\n    MOV AX, @DATA\n    MOV DS, AX\n";
				        } else {
				            tempCodeFile << ((Func_definitionContext)_localctx).id->getText() << " PROC\n";
				        }
				        tempCodeFile << "    PUSH BP\n    MOV BP, SP\n";
				      
				setState(100);
				((Func_definitionContext)_localctx).cs = compound_statement();

				        ((Func_definitionContext)_localctx).text =  ((Func_definitionContext)_localctx).t.text + " " + ((Func_definitionContext)_localctx).id->getText() + "()" + ((Func_definitionContext)_localctx).cs.text;
				        // Write function epilogue to tempCodeFile
				        if (((Func_definitionContext)_localctx).id->getText() == "main") {
				            tempCodeFile << "MAIN ENDP\n";
				        } else {
				            if (localVariableSpace > 0) {
				                tempCodeFile << "    ADD SP, " << localVariableSpace << "\n";  // Clean up local variable space
				            }
				            tempCodeFile << "    POP BP\n";
				            tempCodeFile << "    RET " << parameterCount * 2 << "\n";
				            tempCodeFile << ((Func_definitionContext)_localctx).id->getText() << " ENDP\n";
				        }
				        writeIntoParserLogFile("Line " + to_string((((Func_definitionContext)_localctx).cs!=null?(((Func_definitionContext)_localctx).cs.stop):null)->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" + _localctx.text + "\n");
				        symbolTable->exitScope();
				        isFunctionBlock = false;
				        insertParams = false;
				      
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(103);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(104);
				((Func_definitionContext)_localctx).id = match(ID);
				setState(105);
				((Func_definitionContext)_localctx).lp = match(LPAREN);

				        // Insert function with parameters (parameters handled after parameter_list)
				        if (symbolTable->Insert(((Func_definitionContext)_localctx).id->getText(), "ID")) {
				            auto sym = symbolTable->LookUp(((Func_definitionContext)_localctx).id->getText());
				            if (sym) {
				                sym->setDataType("function");
				                clearCurrentParamTypes();
				            }
				        } else {
				            auto sym = symbolTable->LookUp(((Func_definitionContext)_localctx).id->getText());
				            if (sym) {
				                if (sym->getDataType() == "variable") {
				                    writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).id->getText() + "\n");
				                }
				            }
				        }
				        symbolTable->enterScope();
				        isFunctionBlock = true;
				        insertParams = true;
				        currentParamTypes.clear();
				        currentFunctionReturnType = ((Func_definitionContext)_localctx).t.text;
				        currentFunctionName = ((Func_definitionContext)_localctx).id->getText();
				        currentLocalOffset = 2;
				        localVariableSpace = 0;  // Reset local variable space counter

				        // Write function prologue to tempCodeFile
				        if (((Func_definitionContext)_localctx).id->getText() == "main") {
				            tempCodeFile << "MAIN PROC\n    MOV AX, @DATA\n    MOV DS, AX\n";
				        } else {
				            tempCodeFile << ((Func_definitionContext)_localctx).id->getText() << " PROC\n";
				        }
				        tempCodeFile << "    PUSH BP\n    MOV BP, SP\n";
				      
				setState(107);
				((Func_definitionContext)_localctx).pl = parameter_list(0);
				setState(108);
				((Func_definitionContext)_localctx).rp = match(RPAREN);

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

				        auto sym = symbolTable->LookUp(((Func_definitionContext)_localctx).id->getText());
				        if (sym) {
				            // Compare with previously declared parameter types for this function
				            auto it = functionParamTypes.find(((Func_definitionContext)_localctx).id->getText());
				            if (it != functionParamTypes.end()) {
				                const auto& declaredParams = it->second;
				                if (declaredParams.size() != currentParamTypes.size()) {
				                    writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((Func_definitionContext)_localctx).id->getText() + "\n");
				                } else {
				                    for (int i = 0; i < declaredParams.size(); ++i) {
				                        if (declaredParams[i] != currentParamTypes[i]) {
				                            writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).id->getLine()) + ": " + to_string(i+1) + "th argument mismatch in function " + ((Func_definitionContext)_localctx).id->getText() + "\n");
				                            break;
				                        }
				                    }
				                }
				            }
				            auto prevFuncInfo = sym->getFunctionInfo();
				            if (prevFuncInfo) {
				                if (prevFuncInfo->getReturnType() != ((Func_definitionContext)_localctx).t.text) {
				                    writeIntoErrorFile("Error at line " + to_string(((Func_definitionContext)_localctx).id->getLine()) + ": Return type mismatch of " + ((Func_definitionContext)_localctx).id->getText() + "\n");
				                }
				            }
				            sym->setFunctionInfo(make_shared<FunctionInfo>(
				                ((Func_definitionContext)_localctx).t.text,
				                currentParamTypes.empty() ? nullptr : currentParamTypes.data(),
				                currentParamTypes.size()
				            ));
				        }
				        // Update the function's parameter types in the map (for definition)
				        functionParamTypes[((Func_definitionContext)_localctx).id->getText()] = currentParamTypes;
				    
				setState(110);
				((Func_definitionContext)_localctx).cs = compound_statement();

				        isFunctionBlock = false;
				        ((Func_definitionContext)_localctx).text =  ((Func_definitionContext)_localctx).t.text + " " + ((Func_definitionContext)_localctx).id->getText() + "(" + ((Func_definitionContext)_localctx).pl.text + ")" + ((Func_definitionContext)_localctx).cs.text;
				        // Write function epilogue to tempCodeFile
				        if (((Func_definitionContext)_localctx).id->getText() == "main") {
				            tempCodeFile << "MAIN ENDP\n";
				        } else {
				            if (localVariableSpace > 0) {
				                tempCodeFile << "    ADD SP, " << localVariableSpace << "\n";  // Clean up local variable space
				            }
				            tempCodeFile << "    POP BP\n";
				            tempCodeFile << "    RET " << parameterCount * 2 << "\n";
				            tempCodeFile << ((Func_definitionContext)_localctx).id->getText() << " ENDP\n";
				        }
				        if (((Func_definitionContext)_localctx).pl.text.find(' ') != string::npos) {
				            writeIntoParserLogFile("Line " + to_string((((Func_definitionContext)_localctx).cs!=null?(((Func_definitionContext)_localctx).cs.stop):null)->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n" + _localctx.text + "\n");
				        } else {
				            writeIntoParserLogFile("Line " + to_string((((Func_definitionContext)_localctx).cs!=null?(((Func_definitionContext)_localctx).cs.stop):null)->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n" + _localctx.text + "\n");
				        }
				        symbolTable->exitScope();
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_listContext extends ParserRuleContext {
		public string text;
		public Parameter_listContext pl;
		public Type_specifierContext t;
		public Token id;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ID() { return getToken(C2105017Parser.ID, 0); }
		public TerminalNode COMMA() { return getToken(C2105017Parser.COMMA, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		return parameter_list(0);
	}

	private Parameter_listContext parameter_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, _parentState);
		Parameter_listContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_parameter_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(121);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(116);
				((Parameter_listContext)_localctx).t = type_specifier();
				setState(117);
				((Parameter_listContext)_localctx).id = match(ID);

				        // Single parameter handling - insert into symbol table for function signature
				        ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).t.text + " " + ((Parameter_listContext)_localctx).id->getText();
				        if (insertParams) {
				            // Insert parameter into current function's local scope
				            if (!symbolTable->Insert(((Parameter_listContext)_localctx).id->getText(), "ID")) {
				                writeIntoErrorFile("Error at line " + to_string(((Parameter_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Parameter_listContext)_localctx).id->getText() + " in parameter\n");
				            } else {
				                auto sym = symbolTable->LookUp(((Parameter_listContext)_localctx).id->getText());
				                sym->setIsParameter(true);  // Mark as parameter for offset calculation
				                // Don't set offset here - will be set in a post-processing step
				                parameterCount = 1;  // Track parameter count for stack cleanup
				            }
				        }
				        // Add parameter type to function signature tracking
				        addParamType(((Parameter_listContext)_localctx).t.text);
				        addParamName(((Parameter_listContext)_localctx).id->getText());
				        writeIntoParserLogFile("Line " + to_string(((Parameter_listContext)_localctx).id->getLine()) + ": parameter_list : type_specifier ID\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 2:
				{

				        ((Parameter_listContext)_localctx).text =  "";
				    
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(131);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Parameter_listContext(_parentctx, _parentState);
					_localctx.pl = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
					setState(123);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(124);
					match(COMMA);
					setState(125);
					((Parameter_listContext)_localctx).t = type_specifier();
					setState(126);
					((Parameter_listContext)_localctx).id = match(ID);

					                  // Multiple parameters - handle recursively and accumulate parameter info
					                  ((Parameter_listContext)_localctx).text =  ((Parameter_listContext)_localctx).pl.text + "," + ((Parameter_listContext)_localctx).t.text + " " + ((Parameter_listContext)_localctx).id->getText();
					                  if (insertParams) {
					                      // Insert additional parameter into function's local scope
					                      if (!symbolTable->Insert(((Parameter_listContext)_localctx).id->getText(), "ID")) {
					                          writeIntoErrorFile("Error at line " + to_string(((Parameter_listContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Parameter_listContext)_localctx).id->getText() + " in parameter\n");
					                      } else {
					                          auto sym = symbolTable->LookUp(((Parameter_listContext)_localctx).id->getText());
					                          sym->setIsParameter(true);  // Mark as parameter for offset calculation
					                          parameterCount++;  // Increment parameter count for stack management
					                          // Don't set offset here - will be set in a post-processing step
					                      }
					                  }
					                  // Add parameter type to function signature tracking
					                  addParamType(((Parameter_listContext)_localctx).t.text);
					                  addParamName(((Parameter_listContext)_localctx).id->getText());
					                  writeIntoParserLogFile("Line " + to_string(((Parameter_listContext)_localctx).id->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n\n" + _localctx.text + "\n");
					              
					}
					} 
				}
				setState(133);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compound_statementContext extends ParserRuleContext {
		public string text;
		public Token lc;
		public Token rc;
		public StatementsContext s;
		public TerminalNode LCURL() { return getToken(C2105017Parser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(C2105017Parser.RCURL, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public Compound_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound_statement; }
	}

	public final Compound_statementContext compound_statement() throws RecognitionException {
		Compound_statementContext _localctx = new Compound_statementContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_compound_statement);
		try {
			setState(144);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(134);
				((Compound_statementContext)_localctx).lc = match(LCURL);

				        // Enter new scope for block unless this is a function block
				        if (!isFunctionBlock) {
				            symbolTable->enterScope();
				        }
				      
				setState(136);
				((Compound_statementContext)_localctx).rc = match(RCURL);

				        // Empty block - no statements inside
				        ((Compound_statementContext)_localctx).text =  "{}";
				        writeIntoParserLogFile("Line " + to_string(((Compound_statementContext)_localctx).rc->getLine()) + ": compound_statement : LCURL RCURL\n\n" + _localctx.text + "\n");
				        symbolTable->PrintAllScopeTable();
				        if (!isFunctionBlock) {
				            symbolTable->exitScope();  // Exit scope for empty block
				        }
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(138);
				((Compound_statementContext)_localctx).lc = match(LCURL);

				        // Block with statements - manage scope transition
				        bool wasFunctionBlock = isFunctionBlock;
				        if (!isFunctionBlock) {
				            symbolTable->enterScope();  // Enter new scope for block
				        }
				        isFunctionBlock = false;  // Reset function block flag
				      
				setState(140);
				((Compound_statementContext)_localctx).s = statements(0);
				setState(141);
				((Compound_statementContext)_localctx).rc = match(RCURL);

				        // Block with statements - format text
				        ((Compound_statementContext)_localctx).text =  "{\n" + ((Compound_statementContext)_localctx).s.text + "\n}";
				        writeIntoParserLogFile("Line " + to_string(((Compound_statementContext)_localctx).rc->getLine()) + ": compound_statement : LCURL statements RCURL\n\n" + _localctx.text + "\n");
				        symbolTable->PrintAllScopeTable();
				        if (!wasFunctionBlock) {
				            symbolTable->exitScope();  // Exit scope for statement block
				        }
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_declarationContext extends ParserRuleContext {
		public string text;
		public Type_specifierContext t;
		public Declaration_listContext dl;
		public Token sm;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(C2105017Parser.SEMICOLON, 0); }
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_var_declaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(146);
			((Var_declarationContext)_localctx).t = type_specifier();
			setState(147);
			((Var_declarationContext)_localctx).dl = declaration_list(((Var_declarationContext)_localctx).t.text);
			setState(148);
			((Var_declarationContext)_localctx).sm = match(SEMICOLON);

			        // Variable declaration with type checking
			        ((Var_declarationContext)_localctx).text =  ((Var_declarationContext)_localctx).t.text + " " + ((Var_declarationContext)_localctx).dl.text + ";";
			        if (((Var_declarationContext)_localctx).t.text == "void") {
			            // Void variables are not allowed
			            writeIntoErrorFile("Error at line " + to_string((((Var_declarationContext)_localctx).t!=null?(((Var_declarationContext)_localctx).t.start):null)->getLine()) + ": Variable type cannot be void\n");
			        }
			        writeIntoParserLogFile("Line " + to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n\n" + _localctx.text + "\n");
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_specifierContext extends ParserRuleContext {
		public string text;
		public Token INT;
		public Token FLOAT;
		public Token VOID;
		public TerminalNode INT() { return getToken(C2105017Parser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(C2105017Parser.FLOAT, 0); }
		public TerminalNode VOID() { return getToken(C2105017Parser.VOID, 0); }
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_type_specifier);
		try {
			setState(157);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(151);
				((Type_specifierContext)_localctx).INT = match(INT);

				        // Integer type specifier
				        ((Type_specifierContext)_localctx).text =  "int";
				        writeIntoParserLogFile("Line " + to_string(((Type_specifierContext)_localctx).INT->getLine()) + ": type_specifier : INT\n\nint\n");
				    
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(153);
				((Type_specifierContext)_localctx).FLOAT = match(FLOAT);

				        // Floating point type specifier
				        ((Type_specifierContext)_localctx).text =  "float";
				        writeIntoParserLogFile("Line " + to_string(((Type_specifierContext)_localctx).FLOAT->getLine()) + ": type_specifier : FLOAT\n\nfloat\n");
				    
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(155);
				((Type_specifierContext)_localctx).VOID = match(VOID);

				        // Void type specifier (for functions only)
				        ((Type_specifierContext)_localctx).text =  "void";
				        writeIntoParserLogFile("Line " + to_string(((Type_specifierContext)_localctx).VOID->getLine()) + ": type_specifier : VOID\n\nvoid\n");
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_listContext extends ParserRuleContext {
		public string type;
		public string text;
		public Declaration_itemContext first;
		public Declaration_list_tailContext rest;
		public Declaration_itemContext declaration_item() {
			return getRuleContext(Declaration_itemContext.class,0);
		}
		public Declaration_list_tailContext declaration_list_tail() {
			return getRuleContext(Declaration_list_tailContext.class,0);
		}
		public Declaration_listContext(ParserRuleContext parent, int invokingState) { super(parent, invokingState); }
		public Declaration_listContext(ParserRuleContext parent, int invokingState, string type) {
			super(parent, invokingState);
			this.type = type;
		}
		@Override public int getRuleIndex() { return RULE_declaration_list; }
	}

	public final Declaration_listContext declaration_list(string type) throws RecognitionException {
		Declaration_listContext _localctx = new Declaration_listContext(_ctx, getState(), type);
		enterRule(_localctx, 18, RULE_declaration_list);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(159);
			((Declaration_listContext)_localctx).first = declaration_item(_localctx.type);

			        // Parse first declaration item and log the rule
			        writeIntoParserLogFile("Line " + to_string(((Declaration_listContext)_localctx).first.line) + ": declaration_list : " + ((Declaration_listContext)_localctx).first.ruleName + "\n\n" + ((Declaration_listContext)_localctx).first.text + "\n");
			      
			setState(161);
			((Declaration_listContext)_localctx).rest = declaration_list_tail(_localctx.type, ((Declaration_listContext)_localctx).first.text);

			        // Combine first item with remaining items
			        ((Declaration_listContext)_localctx).text =  ((Declaration_listContext)_localctx).first.text + ((Declaration_listContext)_localctx).rest.text;
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_list_tailContext extends ParserRuleContext {
		public string type;
		public string builtSoFar;
		public string text;
		public Declaration_itemContext next;
		public Declaration_list_tailContext rest;
		public TerminalNode COMMA() { return getToken(C2105017Parser.COMMA, 0); }
		public Declaration_itemContext declaration_item() {
			return getRuleContext(Declaration_itemContext.class,0);
		}
		public Declaration_list_tailContext declaration_list_tail() {
			return getRuleContext(Declaration_list_tailContext.class,0);
		}
		public Declaration_list_tailContext(ParserRuleContext parent, int invokingState) { super(parent, invokingState); }
		public Declaration_list_tailContext(ParserRuleContext parent, int invokingState, string type, string builtSoFar) {
			super(parent, invokingState);
			this.type = type;
			this.builtSoFar = builtSoFar;
		}
		@Override public int getRuleIndex() { return RULE_declaration_list_tail; }
	}

	public final Declaration_list_tailContext declaration_list_tail(string type,string builtSoFar) throws RecognitionException {
		Declaration_list_tailContext _localctx = new Declaration_list_tailContext(_ctx, getState(), type, builtSoFar);
		enterRule(_localctx, 20, RULE_declaration_list_tail);
		try {
			setState(171);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case COMMA:
				enterOuterAlt(_localctx, 1);
				{
				setState(164);
				match(COMMA);
				setState(165);
				((Declaration_list_tailContext)_localctx).next = declaration_item(_localctx.type);

				        // Handle additional declaration items in the list
				        string newList = builtSoFar + "," + ((Declaration_list_tailContext)_localctx).next.text;
				        writeIntoParserLogFile("Line " + to_string(((Declaration_list_tailContext)_localctx).next.line) + ": declaration_list : declaration_list COMMA " + ((Declaration_list_tailContext)_localctx).next.ruleName + "\n\n" + newList + "\n");
				      
				setState(167);
				((Declaration_list_tailContext)_localctx).rest = declaration_list_tail(_localctx.type, builtSoFar + "," + ((Declaration_list_tailContext)_localctx).next.text);

				        // Recursively build the comma-separated list
				        ((Declaration_list_tailContext)_localctx).text =  "," + ((Declaration_list_tailContext)_localctx).next.text + ((Declaration_list_tailContext)_localctx).rest.text;
				    
				}
				break;
			case SEMICOLON:
				enterOuterAlt(_localctx, 2);
				{

				        // Empty tail - end of declaration list
				        ((Declaration_list_tailContext)_localctx).text =  "";
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_itemContext extends ParserRuleContext {
		public string type;
		public string text;
		public string ruleName;
		public int line;
		public Token id;
		public Token ci;
		public Logic_expressionContext init;
		public TerminalNode ID() { return getToken(C2105017Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105017Parser.LTHIRD, 0); }
		public TerminalNode RTHIRD() { return getToken(C2105017Parser.RTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(C2105017Parser.CONST_INT, 0); }
		public TerminalNode ASSIGNOP() { return getToken(C2105017Parser.ASSIGNOP, 0); }
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public Declaration_itemContext(ParserRuleContext parent, int invokingState) { super(parent, invokingState); }
		public Declaration_itemContext(ParserRuleContext parent, int invokingState, string type) {
			super(parent, invokingState);
			this.type = type;
		}
		@Override public int getRuleIndex() { return RULE_declaration_item; }
	}

	public final Declaration_itemContext declaration_item(string type) throws RecognitionException {
		Declaration_itemContext _localctx = new Declaration_itemContext(_ctx, getState(), type);
		enterRule(_localctx, 22, RULE_declaration_item);
		try {
			setState(185);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(173);
				((Declaration_itemContext)_localctx).id = match(ID);

				        // Simple variable declaration
				        ((Declaration_itemContext)_localctx).text =  ((Declaration_itemContext)_localctx).id->getText();
				        ((Declaration_itemContext)_localctx).ruleName =  "ID";
				        ((Declaration_itemContext)_localctx).line =  ((Declaration_itemContext)_localctx).id->getLine();
				        // Insert variable into symbol table with type information
				        if (!symbolTable->Insert(((Declaration_itemContext)_localctx).id->getText(), "ID")) {
				            writeIntoErrorFile("Error at line " + to_string(((Declaration_itemContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Declaration_itemContext)_localctx).id->getText() + "\n");
				        } else {
				            auto sym = symbolTable->LookUp(((Declaration_itemContext)_localctx).id->getText());
				            if (sym) {
				                sym->setDeclaredType(_localctx.type);  // Set the declared type (int, float, etc.)
				                sym->setDataType("variable");  // Mark as variable (not array/function)
				                // Check if this is a global variable by examining current scope
				                if (symbolTable->getCurrentScope()->getParentScope() == nullptr) {
				                    // Global variable - add to data segment
				                    dataSegment += ((Declaration_itemContext)_localctx).id->getText() + " DW 1 DUP (0000H)\n";
				                } else {
				                    // Local variable - allocate stack space and write to tempCodeFile
				                    sym->setOffset(-currentLocalOffset);  // Negative offset for local variables
				                    currentLocalOffset += 2;  // 2 bytes for each variable
				                    localVariableSpace += 2;  // Track space allocated for local variables
				                    tempCodeFile << "    SUB SP, 2\t; Line " << ((Declaration_itemContext)_localctx).id->getLine() << "\n";
				                }
				            }
				        }
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(175);
				((Declaration_itemContext)_localctx).id = match(ID);
				setState(176);
				match(LTHIRD);
				setState(177);
				((Declaration_itemContext)_localctx).ci = match(CONST_INT);
				setState(178);
				match(RTHIRD);

				        // Array declaration with specified size
				        ((Declaration_itemContext)_localctx).text =  ((Declaration_itemContext)_localctx).id->getText() + "[" + ((Declaration_itemContext)_localctx).ci->getText() + "]";
				        ((Declaration_itemContext)_localctx).ruleName =  "ID LTHIRD CONST_INT RTHIRD";
				        ((Declaration_itemContext)_localctx).line =  ((Declaration_itemContext)_localctx).id->getLine();
				        // Insert array into symbol table with size information
				        if (!symbolTable->Insert(((Declaration_itemContext)_localctx).id->getText(), "ID")) {
				            writeIntoErrorFile("Error at line " + to_string(((Declaration_itemContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Declaration_itemContext)_localctx).id->getText() + "\n");
				        } else {
				            auto sym = symbolTable->LookUp(((Declaration_itemContext)_localctx).id->getText());
				            if (sym) {
				                sym->setDeclaredType(_localctx.type);  // Set the declared type (int, float, etc.)
				                sym->setDataType("array");    // Mark as array type
				                int size = stoi(((Declaration_itemContext)_localctx).ci->getText());  // Parse array size
				                // Check if this is a global array by examining current scope
				                if (symbolTable->getCurrentScope()->getParentScope() == nullptr) {
				                    // Global array - add to data segment with specified size
				                    dataSegment += ((Declaration_itemContext)_localctx).id->getText() + " DW " + to_string(size) + " DUP(0)\n";
				                } else {
				                    // Local array - allocate stack space based on size and write to tempCodeFile
				                    sym->setOffset(-currentLocalOffset);  // Negative offset for local arrays
				                    currentLocalOffset += size * 2;  // 2 bytes per element
				                    localVariableSpace += size * 2;  // Track space allocated for local arrays
				                    tempCodeFile << "    SUB SP, " << size * 2 << "\t; Line " << ((Declaration_itemContext)_localctx).id->getLine() << "\n";
				                }
				            }
				        }
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(180);
				((Declaration_itemContext)_localctx).id = match(ID);
				setState(181);
				match(ASSIGNOP);
				setState(182);
				((Declaration_itemContext)_localctx).init = logic_expression();

				        ((Declaration_itemContext)_localctx).text =  ((Declaration_itemContext)_localctx).id->getText() + " = " + ((Declaration_itemContext)_localctx).init.text;
				        ((Declaration_itemContext)_localctx).ruleName =  "ID ASSIGNOP logic_expression";
				        ((Declaration_itemContext)_localctx).line =  ((Declaration_itemContext)_localctx).id->getLine();
				        // Insert variable into symbol table
				        if (!symbolTable->Insert(((Declaration_itemContext)_localctx).id->getText(), "ID")) {
				            writeIntoErrorFile("Error at line " + to_string(((Declaration_itemContext)_localctx).id->getLine()) + ": Multiple declaration of " + ((Declaration_itemContext)_localctx).id->getText() + "\n");
				        } else {
				            auto sym = symbolTable->LookUp(((Declaration_itemContext)_localctx).id->getText());
				            if (sym) {
				                sym->setDeclaredType(_localctx.type);
				                sym->setDataType("variable");
				            }
				            // Check if this is a global variable by examining current scope
				            if (symbolTable->getCurrentScope()->getParentScope() == nullptr) {
				                // Global variable - add to data segment
				                dataSegment += ((Declaration_itemContext)_localctx).id->getText() + " DW 1 DUP (0000H)\n";
				                // Global variables with initialization: generate code to store the value
				                // The logic_expression result is already in AX
				                tempCodeFile << "    MOV " + getVarAccess(((Declaration_itemContext)_localctx).id->getText()) + ", AX\t; Line " << ((Declaration_itemContext)_localctx).id->getLine() << "\n";
				            } else {
				                // Local variable - allocate stack space and write to tempCodeFile
				                sym->setOffset(-currentLocalOffset);  // Negative offset for local variables
				                currentLocalOffset += 2;  // 2 bytes for each variable
				                localVariableSpace += 2;  // Track space allocated for local variables
				                tempCodeFile << "    SUB SP, 2\t; Line " << ((Declaration_itemContext)_localctx).id->getLine() << "\n";
				                // Generate code for initialization - the logic_expression result is already in AX
				                tempCodeFile << "    MOV " + getVarAccess(((Declaration_itemContext)_localctx).id->getText()) + ", AX\t; Line " << ((Declaration_itemContext)_localctx).id->getLine() << "\n";
				            }
				        }
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public string text;
		public StatementsContext sl;
		public StatementContext s;
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		return statements(0);
	}

	private StatementsContext statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementsContext _localctx = new StatementsContext(_ctx, _parentState);
		StatementsContext _prevctx = _localctx;
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(188);
			((StatementsContext)_localctx).s = statement();

			        // Single statement
			        ((StatementsContext)_localctx).text =  ((StatementsContext)_localctx).s.text;
			        if (!_localctx.text.empty()) {
			            writeIntoParserLogFile("Line " + to_string((((StatementsContext)_localctx).s!=null?(((StatementsContext)_localctx).s.stop):null)->getLine()) + ": statements : statement\n\n" + _localctx.text + "\n");
			        }
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(197);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new StatementsContext(_parentctx, _parentState);
					_localctx.sl = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_statements);
					setState(191);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(192);
					((StatementsContext)_localctx).s = statement();

					                  // Multiple statements - accumulate text
					                  ((StatementsContext)_localctx).text =  ((StatementsContext)_localctx).sl.text + "\n" + ((StatementsContext)_localctx).s.text;
					                  if (!((StatementsContext)_localctx).s.text.empty()) {
					                      writeIntoParserLogFile("Line " + to_string((((StatementsContext)_localctx).s!=null?(((StatementsContext)_localctx).s.stop):null)->getLine()) + ": statements : statements statement\n\n" + _localctx.text + "\n");
					                  }
					              
					}
					} 
				}
				setState(199);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public string text;
		public Var_declarationContext v;
		public Expression_statementContext es;
		public Compound_statementContext cs;
		public Expression_statementContext forInit;
		public Expression_statementContext forCond;
		public ExpressionContext forInc;
		public StatementContext forBody;
		public ExpressionContext ifCond;
		public StatementContext ifThen;
		public StatementContext ifElse;
		public ExpressionContext whileCond;
		public StatementContext whileBody;
		public Token PRINTLN;
		public Token id;
		public ExpressionContext index;
		public Token RETURN;
		public ExpressionContext expr;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public List<Expression_statementContext> expression_statement() {
			return getRuleContexts(Expression_statementContext.class);
		}
		public Expression_statementContext expression_statement(int i) {
			return getRuleContext(Expression_statementContext.class,i);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public TerminalNode FOR() { return getToken(C2105017Parser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(C2105017Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105017Parser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode IF() { return getToken(C2105017Parser.IF, 0); }
		public TerminalNode ELSE() { return getToken(C2105017Parser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(C2105017Parser.WHILE, 0); }
		public TerminalNode PRINTLN() { return getToken(C2105017Parser.PRINTLN, 0); }
		public TerminalNode SEMICOLON() { return getToken(C2105017Parser.SEMICOLON, 0); }
		public TerminalNode ID() { return getToken(C2105017Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105017Parser.LTHIRD, 0); }
		public TerminalNode RTHIRD() { return getToken(C2105017Parser.RTHIRD, 0); }
		public TerminalNode RETURN() { return getToken(C2105017Parser.RETURN, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_statement);
		try {
			setState(274);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(200);
				((StatementContext)_localctx).v = var_declaration();

				        // Variable declaration statement
				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).v.text;
				        writeIntoParserLogFile("Line " + to_string((((StatementContext)_localctx).v!=null?(((StatementContext)_localctx).v.stop):null)->getLine()) + ": statement : var_declaration\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(203);
				((StatementContext)_localctx).es = expression_statement();

				        // Expression statement (assignments, function calls, etc.)
				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).es.text;
				        if (!_localctx.text.empty()) {
				            writeIntoParserLogFile("Line " + to_string((((StatementContext)_localctx).es!=null?(((StatementContext)_localctx).es.stop):null)->getLine()) + ": statement : expression_statement\n\n" + _localctx.text + "\n");
				        }
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(206);
				((StatementContext)_localctx).cs = compound_statement();

				        // Compound statement (block of statements)
				        ((StatementContext)_localctx).text =  ((StatementContext)_localctx).cs.text;
				        writeIntoParserLogFile("Line " + to_string((((StatementContext)_localctx).cs!=null?(((StatementContext)_localctx).cs.stop):null)->getLine()) + ": statement : compound_statement\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(209);
				match(FOR);
				setState(210);
				match(LPAREN);

				        string startLabel = newLabel();  // Label for loop start
				        string updateLabel = newLabel();  // Label for loop start
				        string bodyLabel = newLabel();  // Label for loop body
				        string endLabel = newLabel();    // Label for loop exit
				    
				setState(212);
				((StatementContext)_localctx).forInit = expression_statement();

				        tempCodeFile << startLabel << ":\n";     // Loop start label
				    
				setState(214);
				((StatementContext)_localctx).forCond = expression_statement();

				        tempCodeFile << "    CMP AX, 0\n    JE " << endLabel << "\n";  // Exit if condition false
				        tempCodeFile << "    JMP " << bodyLabel << "\n";  // Jump to loop body
				        tempCodeFile << updateLabel << ":\n";  // Update label for increment
				    
				setState(216);
				((StatementContext)_localctx).forInc = expression();
				setState(217);
				match(RPAREN);

				        tempCodeFile << "    JMP " << startLabel << "\n";  // Jump back to condition check
				        tempCodeFile << bodyLabel << ":\n";      // Loop body label
				    
				setState(219);
				((StatementContext)_localctx).forBody = statement();

				        // For loop with initialization, condition, increment, and body
				        ((StatementContext)_localctx).text =  "for(" + ((StatementContext)_localctx).forInit.text + ((StatementContext)_localctx).forCond.text + ((StatementContext)_localctx).forInc.text + ")" + ((StatementContext)_localctx).forBody.text;
				        // forBody code written when parsing forBody
				        tempCodeFile << "    JMP " << updateLabel << "\n";  // Jump back to condition check
				        tempCodeFile << endLabel << ":\n";        // Loop exit label
				        writeIntoParserLogFile("Line " + to_string((((StatementContext)_localctx).forBody!=null?(((StatementContext)_localctx).forBody.stop):null)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(222);
				match(IF);
				setState(223);
				match(LPAREN);
				setState(224);
				((StatementContext)_localctx).ifCond = expression();
				setState(225);
				match(RPAREN);

				        string endLabel = newLabel();    // Label for end of if statement
				        tempCodeFile << "    CMP AX, 0\n    JE " << endLabel << "\n";  // Skip if condition false
				    
				setState(227);
				((StatementContext)_localctx).ifThen = statement();

				        // If statement without else clause
				        ((StatementContext)_localctx).text =  "if(" + ((StatementContext)_localctx).ifCond.text + ")" + ((StatementContext)_localctx).ifThen.text;
				        // ifCond code written when parsing ifCond
				        // ifThen code written when parsing ifThen
				        tempCodeFile << endLabel << ":\n";        // End of if statement
				        writeIntoParserLogFile("Line " + to_string((((StatementContext)_localctx).ifThen!=null?(((StatementContext)_localctx).ifThen.stop):null)->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(230);
				match(IF);
				setState(231);
				match(LPAREN);
				setState(232);
				((StatementContext)_localctx).ifCond = expression();
				setState(233);
				match(RPAREN);

				        string startLabel = newLabel();   // Label for else clause
				        tempCodeFile << "    CMP AX, 0\n    JE " << startLabel << "\n";  // Jump to else if condition false
				    
				setState(235);
				((StatementContext)_localctx).ifThen = statement();
				setState(236);
				match(ELSE);

				        string endLabel = newLabel();    // Label for end of if-else
				        tempCodeFile << "    JMP " << endLabel << "\n";  // Skip else clause
				        tempCodeFile << startLabel << ":\n";      // Else clause label
				    
				setState(238);
				((StatementContext)_localctx).ifElse = statement();

				        // If statement with else clause
				        ((StatementContext)_localctx).text =  "if(" + ((StatementContext)_localctx).ifCond.text + ")" + ((StatementContext)_localctx).ifThen.text + "else " + ((StatementContext)_localctx).ifElse.text;
				        // ifCond code written when parsing ifCond
				        // ifThen code written when parsing ifThen
				        // ifElse code written when parsing ifElse
				        tempCodeFile << endLabel << ":\n";        // End of if-else statement
				        writeIntoParserLogFile("Line " + to_string((((StatementContext)_localctx).ifElse!=null?(((StatementContext)_localctx).ifElse.stop):null)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(241);
				match(WHILE);
				setState(242);
				match(LPAREN);

				        string startLabel = newLabel();  // Label for loop start
				        string endLabel = newLabel();    // Label for loop exit
				        tempCodeFile << startLabel << ":\n";     // Loop start label
				    
				setState(244);
				((StatementContext)_localctx).whileCond = expression();
				setState(245);
				match(RPAREN);

				        tempCodeFile << "    CMP AX, 0\n    JE " << endLabel << "\n";  // Exit if condition false
				    
				setState(247);
				((StatementContext)_localctx).whileBody = statement();

				        // While loop with condition and body
				        ((StatementContext)_localctx).text =  "while(" + ((StatementContext)_localctx).whileCond.text + ")" + ((StatementContext)_localctx).whileBody.text;
				        // whileCond code written when parsing whileCond
				        // whileBody code written when parsing whileBody
				        tempCodeFile << "    JMP " << startLabel << "\n";  // Jump back to condition check
				        tempCodeFile << endLabel << ":\n";        // Loop exit label
				        writeIntoParserLogFile("Line " + to_string((((StatementContext)_localctx).whileBody!=null?(((StatementContext)_localctx).whileBody.stop):null)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(250);
				((StatementContext)_localctx).PRINTLN = match(PRINTLN);
				setState(251);
				match(LPAREN);
				setState(252);
				((StatementContext)_localctx).id = match(ID);
				setState(253);
				match(RPAREN);
				setState(254);
				match(SEMICOLON);

				        // Print statement for variable output
				        ((StatementContext)_localctx).text =  "printf(" + ((StatementContext)_localctx).id->getText() + ");";
				        string varAccess = getVarAccess(((StatementContext)_localctx).id->getText());  // Get variable access method
				        hasPrintln = true;  // Mark that println is used (for procedure inclusion)
				        tempCodeFile << "    MOV AX, " << varAccess << "\t; Line " << ((StatementContext)_localctx).id->getLine() << "\n";
				        tempCodeFile << "    CALL PRINT_OUTPUT\n";
				        tempCodeFile << "    CALL NEW_LINE\n";
				        writeIntoParserLogFile("Line " + to_string(((StatementContext)_localctx).PRINTLN->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n" + _localctx.text + "\n");
				        // Check if variable is declared and is printable
				        auto sym = symbolTable->LookUp(((StatementContext)_localctx).id->getText());
				        if (!sym) {
				            writeIntoErrorFile("Error at line " + to_string(((StatementContext)_localctx).PRINTLN->getLine()) + ": Undeclared variable " + ((StatementContext)_localctx).id->getText() + "\n");
				        } else if (sym->getDataType() != "variable" && sym->getDataType() != "array") {
				            writeIntoErrorFile("Error at line " + to_string(((StatementContext)_localctx).PRINTLN->getLine()) + ": Cannot print non-variable type " + sym->getDeclaredType() + "\n");
				        }
				    
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(256);
				((StatementContext)_localctx).PRINTLN = match(PRINTLN);
				setState(257);
				match(LPAREN);
				setState(258);
				((StatementContext)_localctx).id = match(ID);
				setState(259);
				match(LTHIRD);
				setState(260);
				((StatementContext)_localctx).index = expression();
				setState(261);
				match(RTHIRD);
				setState(262);
				match(RPAREN);
				setState(263);
				match(SEMICOLON);

				        // Print statement for array element output
				        ((StatementContext)_localctx).text =  "printf(" + ((StatementContext)_localctx).id->getText() + "[" + ((StatementContext)_localctx).index.text + "]);";
				        hasPrintln = true;  // Mark that println is used (for procedure inclusion)
				        auto sym = symbolTable->LookUp(((StatementContext)_localctx).id->getText());
				        int offset = sym->getOffset();
				        tempCodeFile << "    MOV SI, AX\n    SHL SI, 1\n";  // Multiply index by 2 (word size) in SI
				        // Local array - calculate absolute address (negative offset)
				        tempCodeFile << "    MOV BX, BP\n";  // Copy BP to BX
				        tempCodeFile << "    ADD BX, SI\n";  // Add index to BP
				        tempCodeFile << "    SUB BX, " + to_string(abs(offset)) + "\n";  // Subtract absolute offset
				        tempCodeFile << "    MOV AX, [BX]\n";  // Load using calculated address
				        tempCodeFile << "    CALL PRINT_OUTPUT\n";
				        tempCodeFile << "    CALL NEW_LINE\n";
				        writeIntoParserLogFile("Line " + to_string(((StatementContext)_localctx).PRINTLN->getLine()) + ": statement : PRINTLN LPAREN ID LTHIRD expression RTHIRD RPAREN SEMICOLON\n\n" + _localctx.text + "\n");
				        // Check if variable is declared and is printable
				        if (!sym) {
				            writeIntoErrorFile("Error at line " + to_string(((StatementContext)_localctx).PRINTLN->getLine()) + ": Undeclared variable " + ((StatementContext)_localctx).id->getText() + "\n");
				        } else if (sym->getDataType() != "array") {
				            writeIntoErrorFile("Error at line " + to_string(((StatementContext)_localctx).PRINTLN->getLine()) + ": Cannot print non-array type " + sym->getDeclaredType() + "\n");
				        }
				    
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(266);
				((StatementContext)_localctx).RETURN = match(RETURN);
				setState(267);
				((StatementContext)_localctx).expr = expression();
				setState(268);
				match(SEMICOLON);

				        // Return statement with value - check return type compatibility
				        ((StatementContext)_localctx).text =  "return " + ((StatementContext)_localctx).expr.text + ";";
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
				            writeIntoErrorFile("Error at line " + to_string(((StatementContext)_localctx).RETURN->getLine() + 1) + ": Cannot return value from function " + currentFunctionName + " with void return type\n");
				        }
				        writeIntoParserLogFile("Line " + to_string(((StatementContext)_localctx).RETURN->getLine()) + ": statement : RETURN expression SEMICOLON\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(271);
				((StatementContext)_localctx).RETURN = match(RETURN);
				setState(272);
				match(SEMICOLON);

				        // Return statement without value - valid for void functions
				        ((StatementContext)_localctx).text =  "return;";
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
				        writeIntoParserLogFile("Line " + to_string(((StatementContext)_localctx).RETURN->getLine()) + ": statement : RETURN SEMICOLON\n\n" + _localctx.text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expression_statementContext extends ParserRuleContext {
		public string text;
		public Token sm;
		public ExpressionContext e;
		public TerminalNode SEMICOLON() { return getToken(C2105017Parser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Expression_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_statement; }
	}

	public final Expression_statementContext expression_statement() throws RecognitionException {
		Expression_statementContext _localctx = new Expression_statementContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_expression_statement);
		try {
			setState(285);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(276);
				((Expression_statementContext)_localctx).sm = match(SEMICOLON);

				        // Empty statement - just a semicolon
				        ((Expression_statementContext)_localctx).text =  ";";
				        writeIntoParserLogFile("Line " + to_string(((Expression_statementContext)_localctx).sm->getLine()) + ": expression_statement : SEMICOLON\n\n;\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(278);
				((Expression_statementContext)_localctx).e = expression();
				setState(279);
				((Expression_statementContext)_localctx).sm = match(SEMICOLON);

				        // Expression followed by semicolon
				        ((Expression_statementContext)_localctx).text =  ((Expression_statementContext)_localctx).e.text + ";";
				        writeIntoParserLogFile("Line " + to_string(((Expression_statementContext)_localctx).sm->getLine()) + ": expression_statement : expression SEMICOLON\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(282);
				((Expression_statementContext)_localctx).e = expression();

				        // Expression without semicolon (used in for loops)
				        ((Expression_statementContext)_localctx).text =  "";
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public string arrayName;
		public Token id;
		public ExpressionContext e;
		public TerminalNode ID() { return getToken(C2105017Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C2105017Parser.LTHIRD, 0); }
		public TerminalNode RTHIRD() { return getToken(C2105017Parser.RTHIRD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_variable);
		try {
			setState(296);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(287);
				((VariableContext)_localctx).id = match(ID);

				        // Simple variable access
				        ((VariableContext)_localctx).text =  ((VariableContext)_localctx).id->getText();
				        _localctx.argTypes.clear();
				        ((VariableContext)_localctx).arrayName =  "";

				        if (isAssignmentContext) {
				            tempCodeFile << "    MOV " + getVarAccess(((VariableContext)_localctx).id->getText()) + ", AX\t; Line " + to_string(((VariableContext)_localctx).id->getLine()) + "\n";
				        } else {
				            // Load variable value into AX for use in expressions
				            tempCodeFile << "    MOV AX, " + getVarAccess(((VariableContext)_localctx).id->getText()) + "\t; Line " + to_string(((VariableContext)_localctx).id->getLine()) + "\n";
				        }

				        writeIntoParserLogFile("Line " + to_string(((VariableContext)_localctx).id->getLine()) + ": variable : ID\n\n" + _localctx.text + "\n");
				        // Check if variable is declared and get its type
				        auto sym = symbolTable->LookUp(((VariableContext)_localctx).id->getText());
				        if (sym) {
				            if (sym->getDataType() == "array") {
				                _localctx.argTypes.push_back("array");
				            } else {
				                _localctx.argTypes.push_back(sym->getDeclaredType());
				            }
				        } else {
				            writeIntoErrorFile("Error at line " + to_string(((VariableContext)_localctx).id->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).id->getText() + "\n");
				        }
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(289);
				((VariableContext)_localctx).id = match(ID);
				setState(290);
				match(LTHIRD);

				        bool wasAssignmentContext = isAssignmentContext;  // Save current context
				        if (isAssignmentContext) {
				            tempCodeFile << "    PUSH AX\n";  // Save index expression result
				            isAssignmentContext = false;  // Reset assignment context for index expression
				        }
				    
				setState(292);
				((VariableContext)_localctx).e = expression();
				setState(293);
				match(RTHIRD);

				        // Array element access with index expression
				        ((VariableContext)_localctx).text =  ((VariableContext)_localctx).id->getText() + "[" + ((VariableContext)_localctx).e.text + "]";
				        _localctx.argTypes.clear();
				        ((VariableContext)_localctx).arrayName =  ((VariableContext)_localctx).id->getText();

				        isAssignmentContext = wasAssignmentContext;  // Restore assignment context

				        auto sym = symbolTable->LookUp(((VariableContext)_localctx).id->getText());
				        if (sym) {
				            // Check if this is a global or local array using helper function
				            bool isGlobal = isGlobalArray(((VariableContext)_localctx).id->getText());

				            if (isGlobal) {
				                // Global array - use direct addressing with array name
				                // e code written when parsing e
				                tempCodeFile << "    MOV BX, AX\n    SHL BX, 1\n";  // Multiply index by 2 (word size)
				                if (isAssignmentContext) {
				                    tempCodeFile << "    POP AX\n";  // Restore assignment value
				                    tempCodeFile << "    MOV [" + ((VariableContext)_localctx).id->getText() + " + BX], AX\n";  // Store to array element
				                } else {
				                    tempCodeFile << "    MOV AX, [" + ((VariableContext)_localctx).id->getText() + " + BX]\n";  // Load array element into AX
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
				        writeIntoParserLogFile("Line " + to_string(((VariableContext)_localctx).id->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n\n" + _localctx.text + "\n");
				        // Validate that identifier is actually an array
				        auto symCheck = symbolTable->LookUp(((VariableContext)_localctx).id->getText());
				        if (symCheck) {
				            if (symCheck->getDataType() != "array") {
				                writeIntoErrorFile("Error at line " + to_string(((VariableContext)_localctx).id->getLine()) + ": " + ((VariableContext)_localctx).id->getText() + " not an array\n");
				            }
				            _localctx.argTypes.push_back(symCheck->getDeclaredType());
				        } else {
				            writeIntoErrorFile("Error at line " + to_string(((VariableContext)_localctx).id->getLine()) + ": Undeclared array " + ((VariableContext)_localctx).id->getText() + "\n");
				        }
				        // Check that index expression is integer (not float)
				        bool isFloat = ((VariableContext)_localctx).e.text.find('.') != string::npos;
				        bool isNumeric = !((VariableContext)_localctx).e.text.empty() && ((VariableContext)_localctx).e.text.find_first_not_of("0123456789.") == string::npos;
				        if (isFloat && isNumeric) {
				            writeIntoErrorFile("Error at line " + to_string(((VariableContext)_localctx).id->getLine()) + ": Expression inside third brackets not an integer\n");
				        }
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public Logic_expressionContext le;
		public VariableContext v;
		public Token ao;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C2105017Parser.ASSIGNOP, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_expression);
		try {
			setState(308);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(298);
				((ExpressionContext)_localctx).le = logic_expression();

				        // Simple logic expression without assignment
				        ((ExpressionContext)_localctx).text =  ((ExpressionContext)_localctx).le.text;
				        ((ExpressionContext)_localctx).argTypes =  ((ExpressionContext)_localctx).le.argTypes;
				        writeIntoParserLogFile("Line " + to_string((((ExpressionContext)_localctx).le!=null?(((ExpressionContext)_localctx).le.stop):null)->getLine()) + ": expression : logic_expression\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{

				        isAssignmentContext = true;  // Mark context as assignment
				        string startLabel = newLabel();  // Label for assignment start
				        string exprLabel = newLabel();  // Label for expression evaluation
				        string endLabel = newLabel();    // Label for assignment end
				        tempCodeFile << "    JMP " << exprLabel << "\n";  // Jump to assignment start
				        tempCodeFile << startLabel << ":\n";  // Start label for assignment
				    
				setState(302);
				((ExpressionContext)_localctx).v = variable();

				        isAssignmentContext = false;  // Reset assignment context
				        isExpressionStatement = true;  // Mark as expression statement for assignment
				        tempCodeFile << "    JMP " << endLabel << "\n";  // Jump to end of assignment
				        tempCodeFile << exprLabel << ":\n";  // Label for expression evaluation
				    
				setState(304);
				((ExpressionContext)_localctx).ao = match(ASSIGNOP);
				setState(305);
				((ExpressionContext)_localctx).le = logic_expression();

				        isExpressionStatement = false;  // Reset expression statement flag
				        // Complete assignment operation
				        ((ExpressionContext)_localctx).text =  ((ExpressionContext)_localctx).v.text + "=" + ((ExpressionContext)_localctx).le.text;
				        _localctx.argTypes.clear();

				        tempCodeFile << "    JMP " << startLabel << "\n";  // Jump to assignment start
				        tempCodeFile << endLabel << ":\n";

				        if (((ExpressionContext)_localctx).le.text.find(' ') == std::string::npos) {
				            writeIntoParserLogFile("Line " + to_string(((ExpressionContext)_localctx).ao->getLine()) + ": expression : variable ASSIGNOP logic_expression\n\n" + _localctx.text + "\n");
				        } else {
				            string trimmedText = ((ExpressionContext)_localctx).le.text;
				            if (!trimmedText.empty() && trimmedText.back() == ' ') trimmedText.pop_back();
				            writeIntoParserLogFile("Line " + to_string((((ExpressionContext)_localctx).le!=null?(((ExpressionContext)_localctx).le.stop):null)->getLine() + 1) + ": expression : logic_expression\n\n" + trimmedText + "\n");
				        }

				        // Type checking for assignment compatibility
				        auto sym = symbolTable->LookUp(((ExpressionContext)_localctx).v.text);
				        if (!sym && !((ExpressionContext)_localctx).v.arrayName.empty()) {
				            sym = symbolTable->LookUp(((ExpressionContext)_localctx).v.arrayName);
				        }
				        if (sym) {
				            if (sym->getDataType() == "array" && !((ExpressionContext)_localctx).v.arrayName.empty()) {
				                // Assignment to array element - check type compatibility
				                string varType = sym->getDeclaredType();
				                bool isFloatLiteral = ((ExpressionContext)_localctx).le.text.find('.') != string::npos;
				                if (varType == "int" && isFloatLiteral && ((ExpressionContext)_localctx).le.text.find('%') == string::npos) {
				                    writeIntoErrorFile("Error at line " + to_string(((ExpressionContext)_localctx).ao->getLine()) + ": Type Mismatch\n");
				                }
				            } else if (sym->getDataType() == "array") {
				                writeIntoErrorFile("Error at line " + to_string(((ExpressionContext)_localctx).ao->getLine()) + ": Type mismatch, " + ((ExpressionContext)_localctx).v.text + " is an array\n");
				            } else {
				                // Assignment to simple variable - check type compatibility
				                string varType = sym->getDeclaredType();
				                bool isFloatLiteral = ((ExpressionContext)_localctx).le.text.find('.') != string::npos;
				                if (varType == "int" && isFloatLiteral && ((ExpressionContext)_localctx).le.text.find('%') == string::npos) {
				                    writeIntoErrorFile("Error at line " + to_string(((ExpressionContext)_localctx).ao->getLine()) + ": Type Mismatch\n");
				                }
				            }
				        }
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logic_expressionContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public Rel_expressionContext re;
		public Rel_expressionContext l;
		public Token lo;
		public Rel_expressionContext r;
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public TerminalNode LOGICOP() { return getToken(C2105017Parser.LOGICOP, 0); }
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_logic_expression);
		try {
			setState(319);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(310);
				((Logic_expressionContext)_localctx).re = rel_expression();

				        // Simple relational expression
				        ((Logic_expressionContext)_localctx).text =  ((Logic_expressionContext)_localctx).re.text;
				        string trimmedText = _localctx.text;
				        if (!trimmedText.empty() && trimmedText.back() == ' ') {
				            trimmedText.pop_back();
				            writeIntoParserLogFile("Line " + to_string((((Logic_expressionContext)_localctx).re!=null?(((Logic_expressionContext)_localctx).re.stop):null)->getLine() + 1) + ": logic_expression : rel_expression\n\n" + trimmedText + "\n");
				        } else {
				            writeIntoParserLogFile("Line " + to_string((((Logic_expressionContext)_localctx).re!=null?(((Logic_expressionContext)_localctx).re.stop):null)->getLine()) + ": logic_expression : rel_expression\n\n" + _localctx.text + "\n");
				        }
				        ((Logic_expressionContext)_localctx).argTypes =  ((Logic_expressionContext)_localctx).re.argTypes;
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(313);
				((Logic_expressionContext)_localctx).l = rel_expression();
				setState(314);
				((Logic_expressionContext)_localctx).lo = match(LOGICOP);

				        string startLabel = newLabel();
				        string endLabel = newLabel();
				        if (((Logic_expressionContext)_localctx).lo->getText() == "&&") {
				            tempCodeFile << "    CMP AX, 0\n    JE " << startLabel << "\n";
				        } else { // ||
				            tempCodeFile << "    CMP AX, 0\n    JNE " << startLabel << "\n";
				        }
				    
				setState(316);
				((Logic_expressionContext)_localctx).r = rel_expression();

				        // Binary logical operation (AND/OR)
				        ((Logic_expressionContext)_localctx).text =  ((Logic_expressionContext)_localctx).l.text + ((Logic_expressionContext)_localctx).lo->getText() + ((Logic_expressionContext)_localctx).r.text;
				        _localctx.argTypes.clear();
				        if (((Logic_expressionContext)_localctx).lo->getText() == "&&") {
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
				        writeIntoParserLogFile("Line " + to_string(((Logic_expressionContext)_localctx).lo->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n\n" + _localctx.text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rel_expressionContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public Simple_expressionContext se;
		public Simple_expressionContext l;
		public Token ro;
		public Simple_expressionContext r;
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode RELOP() { return getToken(C2105017Parser.RELOP, 0); }
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_rel_expression);
		try {
			setState(330);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(321);
				((Rel_expressionContext)_localctx).se = simple_expression(0);

				        // Simple arithmetic expression
				        ((Rel_expressionContext)_localctx).text =  ((Rel_expressionContext)_localctx).se.text;
				        string trimmedText = _localctx.text;
				        if (!trimmedText.empty() && trimmedText.back() == ' ') {
				            trimmedText.pop_back();
				            writeIntoParserLogFile("Line " + to_string((((Rel_expressionContext)_localctx).se!=null?(((Rel_expressionContext)_localctx).se.stop):null)->getLine() + 1) + ": rel_expression : simple_expression\n\n" + trimmedText + "\n");
				        } else {
				            writeIntoParserLogFile("Line " + to_string((((Rel_expressionContext)_localctx).se!=null?(((Rel_expressionContext)_localctx).se.stop):null)->getLine()) + ": rel_expression : simple_expression\n\n" + _localctx.text + "\n");
				        }
				        ((Rel_expressionContext)_localctx).argTypes =  ((Rel_expressionContext)_localctx).se.argTypes;
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(324);
				((Rel_expressionContext)_localctx).l = simple_expression(0);
				 tempCodeFile << "    PUSH AX\n"; 
				setState(326);
				((Rel_expressionContext)_localctx).ro = match(RELOP);
				setState(327);
				((Rel_expressionContext)_localctx).r = simple_expression(0);

				        // Binary relational comparison operation
				        ((Rel_expressionContext)_localctx).text =  ((Rel_expressionContext)_localctx).l.text + ((Rel_expressionContext)_localctx).ro->getText() + ((Rel_expressionContext)_localctx).r.text;
				        _localctx.argTypes.clear();
				        string trueLabel = newLabel();   // Label for true result
				        string endLabel = newLabel();    // Label for end of comparison
				        // r code written when parsing r
				        tempCodeFile << "    POP BX\n    CMP BX, AX\n";  // Compare left (BX) with right (AX)

				        // Generate appropriate jump instruction based on comparison operator
				        if (((Rel_expressionContext)_localctx).ro->getText() == "<") tempCodeFile << "    JL ";
				        else if (((Rel_expressionContext)_localctx).ro->getText() == ">") tempCodeFile << "    JG ";
				        else if (((Rel_expressionContext)_localctx).ro->getText() == "==") tempCodeFile << "    JE ";
				        else if (((Rel_expressionContext)_localctx).ro->getText() == "!=") tempCodeFile << "    JNE ";
				        else if (((Rel_expressionContext)_localctx).ro->getText() == "<=") tempCodeFile << "    JLE ";
				        else if (((Rel_expressionContext)_localctx).ro->getText() == ">=") tempCodeFile << "    JGE ";

				        tempCodeFile << trueLabel << "\n    MOV AX, 0\n    JMP " << endLabel << "\n";  // False case
				        tempCodeFile << trueLabel << ":\n    MOV AX, 1\n";                           // True case
				        tempCodeFile << endLabel << ":\n";
				        writeIntoParserLogFile("Line " + to_string(((Rel_expressionContext)_localctx).ro->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n\n" + _localctx.text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expressionContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public Simple_expressionContext se;
		public TermContext t;
		public Token ao;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C2105017Parser.ADDOP, 0); }
		public Simple_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression; }
	}

	public final Simple_expressionContext simple_expression() throws RecognitionException {
		return simple_expression(0);
	}

	private Simple_expressionContext simple_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_expressionContext _localctx = new Simple_expressionContext(_ctx, _parentState);
		Simple_expressionContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_simple_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(333);
			((Simple_expressionContext)_localctx).t = term(0);

			        // Single term (no addition/subtraction)
			        ((Simple_expressionContext)_localctx).text =  ((Simple_expressionContext)_localctx).t.text;
			        ((Simple_expressionContext)_localctx).argTypes =  ((Simple_expressionContext)_localctx).t.argTypes;
			        writeIntoParserLogFile("Line " + to_string((((Simple_expressionContext)_localctx).t!=null?(((Simple_expressionContext)_localctx).t.stop):null)->getLine()) + ": simple_expression : term\n\n" + _localctx.text + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(344);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Simple_expressionContext(_parentctx, _parentState);
					_localctx.se = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
					setState(336);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					 tempCodeFile << "    PUSH AX\n"; 
					setState(338);
					((Simple_expressionContext)_localctx).ao = match(ADDOP);
					setState(339);
					((Simple_expressionContext)_localctx).t = term(0);

					                  // Binary addition or subtraction operation
					                  ((Simple_expressionContext)_localctx).text =  ((Simple_expressionContext)_localctx).se.text + ((Simple_expressionContext)_localctx).ao->getText() + ((Simple_expressionContext)_localctx).t.text;
					                  ((Simple_expressionContext)_localctx).argTypes =  ((Simple_expressionContext)_localctx).t.argTypes;
					                  // se code written, then PUSH AX above, t code written when parsing t
					                  tempCodeFile << "    POP BX\n";
					                  tempCodeFile << (((Simple_expressionContext)_localctx).ao->getText() == "+" ? "    ADD" : "    SUB") << " BX, AX\n";
					                  tempCodeFile << "    MOV AX, BX\n";
					                  writeIntoParserLogFile("Line " + to_string(((Simple_expressionContext)_localctx).ao->getLine()) + ": simple_expression : simple_expression ADDOP term\n\n" + _localctx.text + "\n");
					              
					}
					} 
				}
				setState(346);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public TermContext t;
		public Unary_expressionContext ue;
		public Token mo;
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode MULOP() { return getToken(C2105017Parser.MULOP, 0); }
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		return term(0);
	}

	private TermContext term(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermContext _localctx = new TermContext(_ctx, _parentState);
		TermContext _prevctx = _localctx;
		int _startState = 40;
		enterRecursionRule(_localctx, 40, RULE_term, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(348);
			((TermContext)_localctx).ue = unary_expression();

			        // Single unary expression (no multiplication/division/modulus)
			        ((TermContext)_localctx).text =  ((TermContext)_localctx).ue.text;
			        ((TermContext)_localctx).argTypes =  ((TermContext)_localctx).ue.argTypes;
			        writeIntoParserLogFile("Line " + to_string((((TermContext)_localctx).ue!=null?(((TermContext)_localctx).ue.stop):null)->getLine()) + ": term : unary_expression\n\n" + _localctx.text + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(359);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TermContext(_parentctx, _parentState);
					_localctx.t = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_term);
					setState(351);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					 tempCodeFile << "    PUSH AX\n"; 
					setState(353);
					((TermContext)_localctx).mo = match(MULOP);
					setState(354);
					((TermContext)_localctx).ue = unary_expression();

					                  // Binary multiplication, division, or modulus operation
					                  ((TermContext)_localctx).text =  ((TermContext)_localctx).t.text + ((TermContext)_localctx).mo->getText() + ((TermContext)_localctx).ue.text;
					                  _localctx.argTypes.clear();
					                  // t code written, then PUSH AX above, ue code written when parsing ue
					                  tempCodeFile << "    MOV BX, AX\n";
					                  tempCodeFile << "    POP AX\n";

					                  // Generate appropriate assembly instruction based on operator
					                  if (((TermContext)_localctx).mo->getText() == "*") {
					                      tempCodeFile << "    XOR DX, DX\n    MUL BX\n";  // Unsigned multiplication
					                  } else if (((TermContext)_localctx).mo->getText() == "/") {
					                      tempCodeFile << "    XOR DX, DX\n    DIV BX\n";  // Unsigned division (quotient in AX)
					                  } else { // %
					                      tempCodeFile << "    XOR DX, DX\n    DIV BX\n    MOV AX, DX\n";  // Modulus (remainder in DX)
					                  }
					                  writeIntoParserLogFile("Line " + to_string(((TermContext)_localctx).mo->getLine()) + ": term : term MULOP unary_expression\n\n" + _localctx.text + "\n");

					                  // Error checking for division/modulus by zero and type compatibility
					                  if (((TermContext)_localctx).mo->getText() == "%" && ((TermContext)_localctx).ue.text == "0") {
					                      writeIntoErrorFile("Error at line " + to_string(((TermContext)_localctx).mo->getLine()) + ": Modulus by Zero\n");
					                  }
					                  if (((TermContext)_localctx).mo->getText() == "%" && (
					                          ((TermContext)_localctx).t.text.find('.') != string::npos ||
					                          ((TermContext)_localctx).ue.text.find('.') != string::npos)) {
					                      writeIntoErrorFile("Error at line " + to_string(((TermContext)_localctx).mo->getLine()) + ": Non-Integer operand on modulus operator\n");
					                  }
					                  if (((TermContext)_localctx).mo->getText() == "/" && (((TermContext)_localctx).ue.text == "0" || ((TermContext)_localctx).ue.text == "0.0")) {
					                      writeIntoErrorFile("Error at line " + to_string(((TermContext)_localctx).mo->getLine()) + ": Division by Zero\n");
					                  }
					              
					}
					} 
				}
				setState(361);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public Token ao;
		public Unary_expressionContext ue;
		public Token n;
		public Token io;
		public VariableContext v;
		public Token doo;
		public FactorContext f;
		public TerminalNode ADDOP() { return getToken(C2105017Parser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode NOT() { return getToken(C2105017Parser.NOT, 0); }
		public TerminalNode INCOP() { return getToken(C2105017Parser.INCOP, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode DECOP() { return getToken(C2105017Parser.DECOP, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_unary_expression);
		try {
			setState(381);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(362);
				((Unary_expressionContext)_localctx).ao = match(ADDOP);
				setState(363);
				((Unary_expressionContext)_localctx).ue = unary_expression();

				        // Unary plus or minus operation
				        ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).ao->getText() + ((Unary_expressionContext)_localctx).ue.text;
				        ((Unary_expressionContext)_localctx).argTypes =  ((Unary_expressionContext)_localctx).ue.argTypes;
				        // ue code written when parsing ue
				        if (((Unary_expressionContext)_localctx).ao->getText() == "-") tempCodeFile << "    NEG AX\n";  // Negate for unary minus
				        // Note: Unary plus does nothing, so no additional assembly needed
				        writeIntoParserLogFile("Line " + to_string(((Unary_expressionContext)_localctx).ao->getLine()) + ": unary_expression : ADDOP unary_expression\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(366);
				((Unary_expressionContext)_localctx).n = match(NOT);
				setState(367);
				((Unary_expressionContext)_localctx).ue = unary_expression();

				        // Logical NOT operation
				        ((Unary_expressionContext)_localctx).text =  "!" + ((Unary_expressionContext)_localctx).ue.text;
				        ((Unary_expressionContext)_localctx).argTypes =  ((Unary_expressionContext)_localctx).ue.argTypes;
				        // ue code written when parsing ue
				        tempCodeFile << "    CMP AX, 0\n    MOV AX, 0\n    SETZ AL\n";  // Set AL to 1 if AX was 0
				        writeIntoParserLogFile("Line " + to_string(((Unary_expressionContext)_localctx).n->getLine()) + ": unary_expression : NOT unary_expression\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case INCOP:
				enterOuterAlt(_localctx, 3);
				{
				setState(370);
				((Unary_expressionContext)_localctx).io = match(INCOP);
				setState(371);
				((Unary_expressionContext)_localctx).v = variable();

				        // Pre-increment operation (++var)
				        ((Unary_expressionContext)_localctx).text =  "++" + ((Unary_expressionContext)_localctx).v.text;
				        if (((Unary_expressionContext)_localctx).v.arrayName.empty()) {
				            // Simple variable pre-increment
				            string varAccess = getVarAccess(((Unary_expressionContext)_localctx).v.text);
				            tempCodeFile << "    INC WORD PTR " << varAccess << "\n    MOV AX, " << varAccess << "\n";
				        } else {
				            // Array element pre-increment - need special handling for global vs local arrays
				            auto sym = symbolTable->LookUp(((Unary_expressionContext)_localctx).v.arrayName);
				            if (sym) {
				                // Check if this is a global or local array using helper function
				                bool isGlobal = isGlobalArray(((Unary_expressionContext)_localctx).v.arrayName);

				                if (isGlobal) {
				                    // Global array pre-increment
				                    // v code written when parsing v, ends with load into AX
				                    tempCodeFile << "    INC WORD PTR [" << ((Unary_expressionContext)_localctx).v.arrayName << " + BX]\n";
				                    tempCodeFile << "    MOV AX, [" << ((Unary_expressionContext)_localctx).v.arrayName << " + BX]\n";
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
				        ((Unary_expressionContext)_localctx).argTypes =  ((Unary_expressionContext)_localctx).v.argTypes;
				        writeIntoParserLogFile("Line " + to_string(((Unary_expressionContext)_localctx).io->getLine()) + ": unary_expression : INCOP variable\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case DECOP:
				enterOuterAlt(_localctx, 4);
				{
				setState(374);
				((Unary_expressionContext)_localctx).doo = match(DECOP);
				setState(375);
				((Unary_expressionContext)_localctx).v = variable();

				        // Pre-decrement operation (--var)
				        ((Unary_expressionContext)_localctx).text =  "--" + ((Unary_expressionContext)_localctx).v.text;
				        if (((Unary_expressionContext)_localctx).v.arrayName.empty()) {
				            // Simple variable pre-decrement
				            string varAccess = getVarAccess(((Unary_expressionContext)_localctx).v.text);
				            tempCodeFile << "    DEC WORD PTR " << varAccess << "\n    MOV AX, " << varAccess << "\n";
				        } else {
				            // Array element pre-decrement - need special handling for global vs local arrays
				            auto sym = symbolTable->LookUp(((Unary_expressionContext)_localctx).v.arrayName);
				            if (sym) {
				                // Check if this is a global or local array using helper function
				                bool isGlobal = isGlobalArray(((Unary_expressionContext)_localctx).v.arrayName);

				                if (isGlobal) {
				                    // Global array pre-decrement
				                    // v code written when parsing v, ends with load into AX
				                    tempCodeFile << "    DEC WORD PTR [" << ((Unary_expressionContext)_localctx).v.arrayName << " + BX]\n";
				                    tempCodeFile << "    MOV AX, [" << ((Unary_expressionContext)_localctx).v.arrayName << " + BX]\n";
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
				        ((Unary_expressionContext)_localctx).argTypes =  ((Unary_expressionContext)_localctx).v.argTypes;
				        writeIntoParserLogFile("Line " + to_string(((Unary_expressionContext)_localctx).doo->getLine()) + ": unary_expression : DECOP variable\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 5);
				{
				setState(378);
				((Unary_expressionContext)_localctx).f = factor();

				        // Factor expression (highest precedence)
				        ((Unary_expressionContext)_localctx).text =  ((Unary_expressionContext)_localctx).f.text;
				        ((Unary_expressionContext)_localctx).argTypes =  ((Unary_expressionContext)_localctx).f.argTypes;
				        writeIntoParserLogFile("Line " + to_string((((Unary_expressionContext)_localctx).f!=null?(((Unary_expressionContext)_localctx).f.stop):null)->getLine()) + ": unary_expression : factor\n\n" + _localctx.text + "\n");
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FactorContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public VariableContext v;
		public Token id;
		public Argument_listContext al;
		public Token lp;
		public ExpressionContext e;
		public Token rp;
		public Token ci;
		public Token cf;
		public Token io;
		public Token doo;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(C2105017Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C2105017Parser.RPAREN, 0); }
		public TerminalNode ID() { return getToken(C2105017Parser.ID, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CONST_INT() { return getToken(C2105017Parser.CONST_INT, 0); }
		public TerminalNode CONST_FLOAT() { return getToken(C2105017Parser.CONST_FLOAT, 0); }
		public TerminalNode INCOP() { return getToken(C2105017Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C2105017Parser.DECOP, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_factor);
		try {
			setState(409);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(383);
				((FactorContext)_localctx).v = variable();

				        // Variable or array element access
				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text;
				        _localctx.argTypes.clear();
				        writeIntoParserLogFile("Line " + to_string((((FactorContext)_localctx).v!=null?(((FactorContext)_localctx).v.stop):null)->getLine()) + ": factor : variable\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(386);
				((FactorContext)_localctx).id = match(ID);
				setState(387);
				match(LPAREN);
				setState(388);
				((FactorContext)_localctx).al = argument_list();
				setState(389);
				match(RPAREN);

				        // Function call: check for declaration, argument count/type, void-in-expression
				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).id->getText() + "(" + ((FactorContext)_localctx).al.text + ")";
				        // al code written when parsing al
				        tempCodeFile << "    CALL " << ((FactorContext)_localctx).id->getText() << "\n";
				        auto funcSym = symbolTable->LookUp(((FactorContext)_localctx).id->getText());
				        if (!funcSym) {
				            writeIntoErrorFile("Error at line " + to_string(((FactorContext)_localctx).id->getLine()) + ": Undefined function " + ((FactorContext)_localctx).id->getText() + "\n");
				        } else if (funcSym->getDataType() != "function") {
				            writeIntoErrorFile("Error at line " + to_string(((FactorContext)_localctx).id->getLine()) + ": " + ((FactorContext)_localctx).id->getText() + " is not a function\n");
				        } else {
				            auto funcInfo = funcSym->getFunctionInfo();
				            int expected = funcInfo->getParameterCount();
				            int given = ((FactorContext)_localctx).al.argTypes.size();
				            if (expected != given) {
				                writeIntoErrorFile("Error at line " + to_string(((FactorContext)_localctx).id->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((FactorContext)_localctx).id->getText() + "\n");
				            } else {
				                for (int i = 0; i < expected; ++i) {
				                    if (((FactorContext)_localctx).al.argTypes[i] == "array") {
				                        writeIntoErrorFile("Error at line " + to_string(((FactorContext)_localctx).id->getLine()) + ": Type mismatch, " + ((FactorContext)_localctx).al.argNames[i] + " is an array\n");
				                    } else if (((FactorContext)_localctx).al.argTypes[i] != funcInfo->getParameterType(i)) {
				                        writeIntoErrorFile("Error at line " + to_string(((FactorContext)_localctx).id->getLine()) + ": " + to_string(i+1) + "th argument mismatch in function " + ((FactorContext)_localctx).id->getText() + "\n");
				                        break;
				                    }
				                }
				            }
				            _localctx.argTypes.clear();
				            _localctx.argTypes.push_back(funcInfo->getReturnType());
				            if (funcInfo->getReturnType() == "void" && isExpressionStatement) {
				                writeIntoErrorFile("Error at line " + to_string(((FactorContext)_localctx).id->getLine()) + ": Void function used in expression\n");
				            }
				        }
				        writeIntoParserLogFile("Line " + to_string(((FactorContext)_localctx).id->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(392);
				((FactorContext)_localctx).lp = match(LPAREN);
				setState(393);
				((FactorContext)_localctx).e = expression();
				setState(394);
				((FactorContext)_localctx).rp = match(RPAREN);

				        ((FactorContext)_localctx).text =  "(" + ((FactorContext)_localctx).e.text + ")";
				        ((FactorContext)_localctx).argTypes =  ((FactorContext)_localctx).e.argTypes;
				        writeIntoParserLogFile("Line " + to_string(((FactorContext)_localctx).lp->getLine()) + ": factor : LPAREN expression RPAREN\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(397);
				((FactorContext)_localctx).ci = match(CONST_INT);

				        // Integer literal constant
				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).ci->getText();
				        tempCodeFile << "    MOV AX, " << ((FactorContext)_localctx).ci->getText() << "\n";  // Load integer constant directly into AX register
				        _localctx.argTypes.clear();
				        _localctx.argTypes.push_back("int");
				        writeIntoParserLogFile("Line " + to_string(((FactorContext)_localctx).ci->getLine()) + ": factor : CONST_INT\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(399);
				((FactorContext)_localctx).cf = match(CONST_FLOAT);

				        // Float literal constant (simplified assembly generation)
				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).cf->getText();
				        tempCodeFile << "    MOV AX, " << ((FactorContext)_localctx).cf->getText() << "\n";  // Basic assembly for float (simplified for this implementation)
				        _localctx.argTypes.clear();
				        _localctx.argTypes.push_back("float");
				        writeIntoParserLogFile("Line " + to_string(((FactorContext)_localctx).cf->getLine()) + ": factor : CONST_FLOAT\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(401);
				((FactorContext)_localctx).v = variable();
				setState(402);
				((FactorContext)_localctx).io = match(INCOP);

				        // Post-increment operation (variable++)
				        // Returns the original value before incrementing
				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text + "++";
				        if (((FactorContext)_localctx).v.arrayName.empty()) {
				            // Simple variable post-increment
				            string varAccess = getVarAccess(((FactorContext)_localctx).v.text);
				            // Post-increment: load original value, then increment variable, then load new value
				            // Variable rule already loaded original value into AX
				            tempCodeFile << "    INC WORD PTR " << varAccess << "\n";     // Increment the variable
				        } else {
				            // Array element post-increment - need special handling for global vs local arrays
				            auto sym = symbolTable->LookUp(((FactorContext)_localctx).v.arrayName);
				            if (sym) {
				                // Check if this is a global or local array using helper function
				                bool isGlobal = isGlobalArray(((FactorContext)_localctx).v.arrayName);

				                if (isGlobal) {
				                    // Global array post-increment using direct memory addressing
				                    // v code written when parsing v, ends with load into AX
				                    tempCodeFile << "    INC WORD PTR [" << ((FactorContext)_localctx).v.arrayName << " + BX]\n"; // Increment array element
				                } else {
				                    // Local array post-increment using stack-based addressing
				                    // v code written when parsing v, ends with load into AX
				                    tempCodeFile << "    INC WORD PTR [BP + SI]\n";   // Increment array element
				                }
				            } else {
				                tempCodeFile << "    ; Error: Array not found\n";
				            }
				        }
				        ((FactorContext)_localctx).argTypes =  ((FactorContext)_localctx).v.argTypes;
				        writeIntoParserLogFile("Line " + to_string(((FactorContext)_localctx).io->getLine()) + ": factor : variable INCOP\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(405);
				((FactorContext)_localctx).v = variable();
				setState(406);
				((FactorContext)_localctx).doo = match(DECOP);

				        // Post-decrement operation (variable--)
				        // Returns the original value before decrementing
				        ((FactorContext)_localctx).text =  ((FactorContext)_localctx).v.text + "--";
				        if (((FactorContext)_localctx).v.arrayName.empty()) {
				            // Simple variable post-decrement
				            string varAccess = getVarAccess(((FactorContext)_localctx).v.text);
				            tempCodeFile << "    DEC WORD PTR " << varAccess << "\n";
				        } else {
				            // Array element post-decrement - need special handling for global vs local arrays
				            auto sym = symbolTable->LookUp(((FactorContext)_localctx).v.arrayName);
				            if (sym) {
				                // Check if this is a global or local array using helper function
				                bool isGlobal = isGlobalArray(((FactorContext)_localctx).v.arrayName);

				                if (isGlobal) {
				                    // Global array post-decrement using direct memory addressing
				                    // v code written when parsing v, ends with load into AX
				                    tempCodeFile << "    MOV AX, [" << ((FactorContext)_localctx).v.arrayName << " + BX]\n";
				                    tempCodeFile << "    DEC WORD PTR [" << ((FactorContext)_localctx).v.arrayName << " + BX]\n";
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
				        ((FactorContext)_localctx).argTypes =  ((FactorContext)_localctx).v.argTypes;
				        writeIntoParserLogFile("Line " + to_string(((FactorContext)_localctx).doo->getLine()) + ": factor : variable DECOP\n\n" + _localctx.text + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public vector<string> argNames;
		public ArgumentsContext a;
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_argument_list);
		try {
			setState(415);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
			case INCOP:
			case DECOP:
			case NOT:
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 1);
				{
				setState(411);
				((Argument_listContext)_localctx).a = arguments(0);

				        // Non-empty argument list - delegate to arguments rule
				        ((Argument_listContext)_localctx).text =  ((Argument_listContext)_localctx).a.text;
				        ((Argument_listContext)_localctx).argTypes =  ((Argument_listContext)_localctx).a.argTypes;
				        ((Argument_listContext)_localctx).argNames =  ((Argument_listContext)_localctx).a.argNames;
				        writeIntoParserLogFile("Line " + to_string((((Argument_listContext)_localctx).a!=null?(((Argument_listContext)_localctx).a.stop):null)->getLine()) + ": argument_list : arguments\n\n" + _localctx.text + "\n");
				    
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{

				        // Empty argument list (function called with no parameters)
				        ((Argument_listContext)_localctx).text =  "";
				        _localctx.argTypes.clear();
				        _localctx.argNames.clear();
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public string text;
		public vector<string> argTypes;
		public vector<string> argNames;
		public ArgumentsContext a;
		public Logic_expressionContext le;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C2105017Parser.COMMA, 0); }
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		return arguments(0);
	}

	private ArgumentsContext arguments(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, _parentState);
		ArgumentsContext _prevctx = _localctx;
		int _startState = 48;
		enterRecursionRule(_localctx, 48, RULE_arguments, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(418);
			((ArgumentsContext)_localctx).le = logic_expression();

			        // Single argument - evaluate expression and push to stack
			        ((ArgumentsContext)_localctx).text =  ((ArgumentsContext)_localctx).le.text;
			        // le code written when parsing le
			        tempCodeFile << "    PUSH AX\n";  // Push evaluated expression result onto stack for function call

			        // Determine argument type and name for semantic checking
			        string argType = "int";  // Default type
			        string argName = ((ArgumentsContext)_localctx).le.text;
			        auto sym = symbolTable->LookUp(((ArgumentsContext)_localctx).le.text);
			        if (sym) {
			            // Symbol found - use its declared type, but check for arrays
			            argType = sym->getDataType() == "array" ? "array" : sym->getDeclaredType();
			        } else if (((ArgumentsContext)_localctx).le.text.find('.') != string::npos) {
			            // Float literal detection (simple heuristic)
			            argType = "float";
			        }

			        _localctx.argTypes.clear();
			        _localctx.argTypes.push_back(argType);
			        _localctx.argNames.clear();
			        _localctx.argNames.push_back(argName);
			        writeIntoParserLogFile("Line " + to_string((((ArgumentsContext)_localctx).le!=null?(((ArgumentsContext)_localctx).le.stop):null)->getLine()) + ": arguments : logic_expression\n\n" + _localctx.text + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(428);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsContext(_parentctx, _parentState);
					_localctx.a = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(421);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(422);
					match(COMMA);
					setState(423);
					((ArgumentsContext)_localctx).le = logic_expression();

					                  // Multiple arguments - recursive case for comma-separated arguments
					                  ((ArgumentsContext)_localctx).text =  ((ArgumentsContext)_localctx).a.text + "," + ((ArgumentsContext)_localctx).le.text;
					                  // a code written when parsing a, le code written when parsing le
					                  tempCodeFile << "    PUSH AX\n";  // Push each argument in order

					                  // Determine type and name for this additional argument
					                  string argType = "int";  // Default type
					                  string argName = ((ArgumentsContext)_localctx).le.text;
					                  auto sym = symbolTable->LookUp(((ArgumentsContext)_localctx).le.text);
					                  if (sym) {
					                      // Symbol found - use its declared type, but check for arrays
					                      argType = sym->getDataType() == "array" ? "array" : sym->getDeclaredType();
					                  } else if (((ArgumentsContext)_localctx).le.text.find('.') != string::npos) {
					                      // Float literal detection (simple heuristic)
					                      argType = "float";
					                  }

					                  // Append to existing argument lists (accumulated from previous arguments)
					                  ((ArgumentsContext)_localctx).argTypes =  ((ArgumentsContext)_localctx).a.argTypes;
					                  _localctx.argTypes.push_back(argType);
					                  ((ArgumentsContext)_localctx).argNames =  ((ArgumentsContext)_localctx).a.argNames;
					                  _localctx.argNames.push_back(argName);
					                  writeIntoParserLogFile("Line " + to_string((((ArgumentsContext)_localctx).le!=null?(((ArgumentsContext)_localctx).le.stop):null)->getLine()) + ": arguments : arguments COMMA logic_expression\n\n" + _localctx.text + "\n");
					              
					}
					} 
				}
				setState(430);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return program_sempred((ProgramContext)_localctx, predIndex);
		case 5:
			return parameter_list_sempred((Parameter_listContext)_localctx, predIndex);
		case 12:
			return statements_sempred((StatementsContext)_localctx, predIndex);
		case 19:
			return simple_expression_sempred((Simple_expressionContext)_localctx, predIndex);
		case 20:
			return term_sempred((TermContext)_localctx, predIndex);
		case 24:
			return arguments_sempred((ArgumentsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean program_sempred(ProgramContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean parameter_list_sempred(Parameter_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 5:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u00017\u01b0\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001"+
		">\b\u0001\n\u0001\f\u0001A\t\u0001\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0003\u0002L\b\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0003\u0003^\b\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0003\u0004r\b\u0004\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005z\b\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0005\u0005\u0082\b\u0005\n\u0005\f\u0005\u0085\t\u0005\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0003\u0006\u0091\b\u0006\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0003\b\u009e\b\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0003\n\u00ac"+
		"\b\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0003\u000b\u00ba\b\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0005\f\u00c4\b\f\n\f\f\f\u00c7\t\f\u0001\r"+
		"\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0003\r\u0113\b\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003"+
		"\u000e\u011e\b\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u0129"+
		"\b\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u0135"+
		"\b\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u0140\b\u0011\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0003\u0012\u014b\b\u0012\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0005\u0013\u0157\b\u0013\n\u0013\f\u0013"+
		"\u015a\t\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0005\u0014"+
		"\u0166\b\u0014\n\u0014\f\u0014\u0169\t\u0014\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0003\u0015\u017e"+
		"\b\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0001\u0016\u0001\u0016\u0003\u0016\u019a\b\u0016\u0001\u0017\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0003\u0017\u01a0\b\u0017\u0001\u0018\u0001"+
		"\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001"+
		"\u0018\u0001\u0018\u0005\u0018\u01ab\b\u0018\n\u0018\f\u0018\u01ae\t\u0018"+
		"\u0001\u0018\u0000\u0006\u0002\n\u0018&(0\u0019\u0000\u0002\u0004\u0006"+
		"\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,."+
		"0\u0000\u0000\u01c2\u00002\u0001\u0000\u0000\u0000\u00025\u0001\u0000"+
		"\u0000\u0000\u0004K\u0001\u0000\u0000\u0000\u0006]\u0001\u0000\u0000\u0000"+
		"\bq\u0001\u0000\u0000\u0000\ny\u0001\u0000\u0000\u0000\f\u0090\u0001\u0000"+
		"\u0000\u0000\u000e\u0092\u0001\u0000\u0000\u0000\u0010\u009d\u0001\u0000"+
		"\u0000\u0000\u0012\u009f\u0001\u0000\u0000\u0000\u0014\u00ab\u0001\u0000"+
		"\u0000\u0000\u0016\u00b9\u0001\u0000\u0000\u0000\u0018\u00bb\u0001\u0000"+
		"\u0000\u0000\u001a\u0112\u0001\u0000\u0000\u0000\u001c\u011d\u0001\u0000"+
		"\u0000\u0000\u001e\u0128\u0001\u0000\u0000\u0000 \u0134\u0001\u0000\u0000"+
		"\u0000\"\u013f\u0001\u0000\u0000\u0000$\u014a\u0001\u0000\u0000\u0000"+
		"&\u014c\u0001\u0000\u0000\u0000(\u015b\u0001\u0000\u0000\u0000*\u017d"+
		"\u0001\u0000\u0000\u0000,\u0199\u0001\u0000\u0000\u0000.\u019f\u0001\u0000"+
		"\u0000\u00000\u01a1\u0001\u0000\u0000\u000023\u0003\u0002\u0001\u0000"+
		"34\u0006\u0000\uffff\uffff\u00004\u0001\u0001\u0000\u0000\u000056\u0006"+
		"\u0001\uffff\uffff\u000067\u0003\u0004\u0002\u000078\u0006\u0001\uffff"+
		"\uffff\u00008?\u0001\u0000\u0000\u00009:\n\u0001\u0000\u0000:;\u0003\u0004"+
		"\u0002\u0000;<\u0006\u0001\uffff\uffff\u0000<>\u0001\u0000\u0000\u0000"+
		"=9\u0001\u0000\u0000\u0000>A\u0001\u0000\u0000\u0000?=\u0001\u0000\u0000"+
		"\u0000?@\u0001\u0000\u0000\u0000@\u0003\u0001\u0000\u0000\u0000A?\u0001"+
		"\u0000\u0000\u0000BC\u0003\u000e\u0007\u0000CD\u0006\u0002\uffff\uffff"+
		"\u0000DL\u0001\u0000\u0000\u0000EF\u0003\u0006\u0003\u0000FG\u0006\u0002"+
		"\uffff\uffff\u0000GL\u0001\u0000\u0000\u0000HI\u0003\b\u0004\u0000IJ\u0006"+
		"\u0002\uffff\uffff\u0000JL\u0001\u0000\u0000\u0000KB\u0001\u0000\u0000"+
		"\u0000KE\u0001\u0000\u0000\u0000KH\u0001\u0000\u0000\u0000L\u0005\u0001"+
		"\u0000\u0000\u0000MN\u0003\u0010\b\u0000NO\u0005(\u0000\u0000OP\u0005"+
		" \u0000\u0000PQ\u0005!\u0000\u0000QR\u0005\'\u0000\u0000RS\u0006\u0003"+
		"\uffff\uffff\u0000S^\u0001\u0000\u0000\u0000TU\u0003\u0010\b\u0000UV\u0005"+
		"(\u0000\u0000VW\u0005 \u0000\u0000WX\u0006\u0003\uffff\uffff\u0000XY\u0003"+
		"\n\u0005\u0000YZ\u0005!\u0000\u0000Z[\u0005\'\u0000\u0000[\\\u0006\u0003"+
		"\uffff\uffff\u0000\\^\u0001\u0000\u0000\u0000]M\u0001\u0000\u0000\u0000"+
		"]T\u0001\u0000\u0000\u0000^\u0007\u0001\u0000\u0000\u0000_`\u0003\u0010"+
		"\b\u0000`a\u0005(\u0000\u0000ab\u0005 \u0000\u0000bc\u0005!\u0000\u0000"+
		"cd\u0006\u0004\uffff\uffff\u0000de\u0003\f\u0006\u0000ef\u0006\u0004\uffff"+
		"\uffff\u0000fr\u0001\u0000\u0000\u0000gh\u0003\u0010\b\u0000hi\u0005("+
		"\u0000\u0000ij\u0005 \u0000\u0000jk\u0006\u0004\uffff\uffff\u0000kl\u0003"+
		"\n\u0005\u0000lm\u0005!\u0000\u0000mn\u0006\u0004\uffff\uffff\u0000no"+
		"\u0003\f\u0006\u0000op\u0006\u0004\uffff\uffff\u0000pr\u0001\u0000\u0000"+
		"\u0000q_\u0001\u0000\u0000\u0000qg\u0001\u0000\u0000\u0000r\t\u0001\u0000"+
		"\u0000\u0000st\u0006\u0005\uffff\uffff\u0000tu\u0003\u0010\b\u0000uv\u0005"+
		"(\u0000\u0000vw\u0006\u0005\uffff\uffff\u0000wz\u0001\u0000\u0000\u0000"+
		"xz\u0006\u0005\uffff\uffff\u0000ys\u0001\u0000\u0000\u0000yx\u0001\u0000"+
		"\u0000\u0000z\u0083\u0001\u0000\u0000\u0000{|\n\u0002\u0000\u0000|}\u0005"+
		"&\u0000\u0000}~\u0003\u0010\b\u0000~\u007f\u0005(\u0000\u0000\u007f\u0080"+
		"\u0006\u0005\uffff\uffff\u0000\u0080\u0082\u0001\u0000\u0000\u0000\u0081"+
		"{\u0001\u0000\u0000\u0000\u0082\u0085\u0001\u0000\u0000\u0000\u0083\u0081"+
		"\u0001\u0000\u0000\u0000\u0083\u0084\u0001\u0000\u0000\u0000\u0084\u000b"+
		"\u0001\u0000\u0000\u0000\u0085\u0083\u0001\u0000\u0000\u0000\u0086\u0087"+
		"\u0005\"\u0000\u0000\u0087\u0088\u0006\u0006\uffff\uffff\u0000\u0088\u0089"+
		"\u0005#\u0000\u0000\u0089\u0091\u0006\u0006\uffff\uffff\u0000\u008a\u008b"+
		"\u0005\"\u0000\u0000\u008b\u008c\u0006\u0006\uffff\uffff\u0000\u008c\u008d"+
		"\u0003\u0018\f\u0000\u008d\u008e\u0005#\u0000\u0000\u008e\u008f\u0006"+
		"\u0006\uffff\uffff\u0000\u008f\u0091\u0001\u0000\u0000\u0000\u0090\u0086"+
		"\u0001\u0000\u0000\u0000\u0090\u008a\u0001\u0000\u0000\u0000\u0091\r\u0001"+
		"\u0000\u0000\u0000\u0092\u0093\u0003\u0010\b\u0000\u0093\u0094\u0003\u0012"+
		"\t\u0000\u0094\u0095\u0005\'\u0000\u0000\u0095\u0096\u0006\u0007\uffff"+
		"\uffff\u0000\u0096\u000f\u0001\u0000\u0000\u0000\u0097\u0098\u0005\r\u0000"+
		"\u0000\u0098\u009e\u0006\b\uffff\uffff\u0000\u0099\u009a\u0005\u000e\u0000"+
		"\u0000\u009a\u009e\u0006\b\uffff\uffff\u0000\u009b\u009c\u0005\u0011\u0000"+
		"\u0000\u009c\u009e\u0006\b\uffff\uffff\u0000\u009d\u0097\u0001\u0000\u0000"+
		"\u0000\u009d\u0099\u0001\u0000\u0000\u0000\u009d\u009b\u0001\u0000\u0000"+
		"\u0000\u009e\u0011\u0001\u0000\u0000\u0000\u009f\u00a0\u0003\u0016\u000b"+
		"\u0000\u00a0\u00a1\u0006\t\uffff\uffff\u0000\u00a1\u00a2\u0003\u0014\n"+
		"\u0000\u00a2\u00a3\u0006\t\uffff\uffff\u0000\u00a3\u0013\u0001\u0000\u0000"+
		"\u0000\u00a4\u00a5\u0005&\u0000\u0000\u00a5\u00a6\u0003\u0016\u000b\u0000"+
		"\u00a6\u00a7\u0006\n\uffff\uffff\u0000\u00a7\u00a8\u0003\u0014\n\u0000"+
		"\u00a8\u00a9\u0006\n\uffff\uffff\u0000\u00a9\u00ac\u0001\u0000\u0000\u0000"+
		"\u00aa\u00ac\u0006\n\uffff\uffff\u0000\u00ab\u00a4\u0001\u0000\u0000\u0000"+
		"\u00ab\u00aa\u0001\u0000\u0000\u0000\u00ac\u0015\u0001\u0000\u0000\u0000"+
		"\u00ad\u00ae\u0005(\u0000\u0000\u00ae\u00ba\u0006\u000b\uffff\uffff\u0000"+
		"\u00af\u00b0\u0005(\u0000\u0000\u00b0\u00b1\u0005$\u0000\u0000\u00b1\u00b2"+
		"\u0005)\u0000\u0000\u00b2\u00b3\u0005%\u0000\u0000\u00b3\u00ba\u0006\u000b"+
		"\uffff\uffff\u0000\u00b4\u00b5\u0005(\u0000\u0000\u00b5\u00b6\u0005\u001d"+
		"\u0000\u0000\u00b6\u00b7\u0003\"\u0011\u0000\u00b7\u00b8\u0006\u000b\uffff"+
		"\uffff\u0000\u00b8\u00ba\u0001\u0000\u0000\u0000\u00b9\u00ad\u0001\u0000"+
		"\u0000\u0000\u00b9\u00af\u0001\u0000\u0000\u0000\u00b9\u00b4\u0001\u0000"+
		"\u0000\u0000\u00ba\u0017\u0001\u0000\u0000\u0000\u00bb\u00bc\u0006\f\uffff"+
		"\uffff\u0000\u00bc\u00bd\u0003\u001a\r\u0000\u00bd\u00be\u0006\f\uffff"+
		"\uffff\u0000\u00be\u00c5\u0001\u0000\u0000\u0000\u00bf\u00c0\n\u0001\u0000"+
		"\u0000\u00c0\u00c1\u0003\u001a\r\u0000\u00c1\u00c2\u0006\f\uffff\uffff"+
		"\u0000\u00c2\u00c4\u0001\u0000\u0000\u0000\u00c3\u00bf\u0001\u0000\u0000"+
		"\u0000\u00c4\u00c7\u0001\u0000\u0000\u0000\u00c5\u00c3\u0001\u0000\u0000"+
		"\u0000\u00c5\u00c6\u0001\u0000\u0000\u0000\u00c6\u0019\u0001\u0000\u0000"+
		"\u0000\u00c7\u00c5\u0001\u0000\u0000\u0000\u00c8\u00c9\u0003\u000e\u0007"+
		"\u0000\u00c9\u00ca\u0006\r\uffff\uffff\u0000\u00ca\u0113\u0001\u0000\u0000"+
		"\u0000\u00cb\u00cc\u0003\u001c\u000e\u0000\u00cc\u00cd\u0006\r\uffff\uffff"+
		"\u0000\u00cd\u0113\u0001\u0000\u0000\u0000\u00ce\u00cf\u0003\f\u0006\u0000"+
		"\u00cf\u00d0\u0006\r\uffff\uffff\u0000\u00d0\u0113\u0001\u0000\u0000\u0000"+
		"\u00d1\u00d2\u0005\u0003\u0000\u0000\u00d2\u00d3\u0005 \u0000\u0000\u00d3"+
		"\u00d4\u0006\r\uffff\uffff\u0000\u00d4\u00d5\u0003\u001c\u000e\u0000\u00d5"+
		"\u00d6\u0006\r\uffff\uffff\u0000\u00d6\u00d7\u0003\u001c\u000e\u0000\u00d7"+
		"\u00d8\u0006\r\uffff\uffff\u0000\u00d8\u00d9\u0003 \u0010\u0000\u00d9"+
		"\u00da\u0005!\u0000\u0000\u00da\u00db\u0006\r\uffff\uffff\u0000\u00db"+
		"\u00dc\u0003\u001a\r\u0000\u00dc\u00dd\u0006\r\uffff\uffff\u0000\u00dd"+
		"\u0113\u0001\u0000\u0000\u0000\u00de\u00df\u0005\u0001\u0000\u0000\u00df"+
		"\u00e0\u0005 \u0000\u0000\u00e0\u00e1\u0003 \u0010\u0000\u00e1\u00e2\u0005"+
		"!\u0000\u0000\u00e2\u00e3\u0006\r\uffff\uffff\u0000\u00e3\u00e4\u0003"+
		"\u001a\r\u0000\u00e4\u00e5\u0006\r\uffff\uffff\u0000\u00e5\u0113\u0001"+
		"\u0000\u0000\u0000\u00e6\u00e7\u0005\u0001\u0000\u0000\u00e7\u00e8\u0005"+
		" \u0000\u0000\u00e8\u00e9\u0003 \u0010\u0000\u00e9\u00ea\u0005!\u0000"+
		"\u0000\u00ea\u00eb\u0006\r\uffff\uffff\u0000\u00eb\u00ec\u0003\u001a\r"+
		"\u0000\u00ec\u00ed\u0005\u0002\u0000\u0000\u00ed\u00ee\u0006\r\uffff\uffff"+
		"\u0000\u00ee\u00ef\u0003\u001a\r\u0000\u00ef\u00f0\u0006\r\uffff\uffff"+
		"\u0000\u00f0\u0113\u0001\u0000\u0000\u0000\u00f1\u00f2\u0005\u0004\u0000"+
		"\u0000\u00f2\u00f3\u0005 \u0000\u0000\u00f3\u00f4\u0006\r\uffff\uffff"+
		"\u0000\u00f4\u00f5\u0003 \u0010\u0000\u00f5\u00f6\u0005!\u0000\u0000\u00f6"+
		"\u00f7\u0006\r\uffff\uffff\u0000\u00f7\u00f8\u0003\u001a\r\u0000\u00f8"+
		"\u00f9\u0006\r\uffff\uffff\u0000\u00f9\u0113\u0001\u0000\u0000\u0000\u00fa"+
		"\u00fb\u0005\f\u0000\u0000\u00fb\u00fc\u0005 \u0000\u0000\u00fc\u00fd"+
		"\u0005(\u0000\u0000\u00fd\u00fe\u0005!\u0000\u0000\u00fe\u00ff\u0005\'"+
		"\u0000\u0000\u00ff\u0113\u0006\r\uffff\uffff\u0000\u0100\u0101\u0005\f"+
		"\u0000\u0000\u0101\u0102\u0005 \u0000\u0000\u0102\u0103\u0005(\u0000\u0000"+
		"\u0103\u0104\u0005$\u0000\u0000\u0104\u0105\u0003 \u0010\u0000\u0105\u0106"+
		"\u0005%\u0000\u0000\u0106\u0107\u0005!\u0000\u0000\u0107\u0108\u0005\'"+
		"\u0000\u0000\u0108\u0109\u0006\r\uffff\uffff\u0000\u0109\u0113\u0001\u0000"+
		"\u0000\u0000\u010a\u010b\u0005\u000b\u0000\u0000\u010b\u010c\u0003 \u0010"+
		"\u0000\u010c\u010d\u0005\'\u0000\u0000\u010d\u010e\u0006\r\uffff\uffff"+
		"\u0000\u010e\u0113\u0001\u0000\u0000\u0000\u010f\u0110\u0005\u000b\u0000"+
		"\u0000\u0110\u0111\u0005\'\u0000\u0000\u0111\u0113\u0006\r\uffff\uffff"+
		"\u0000\u0112\u00c8\u0001\u0000\u0000\u0000\u0112\u00cb\u0001\u0000\u0000"+
		"\u0000\u0112\u00ce\u0001\u0000\u0000\u0000\u0112\u00d1\u0001\u0000\u0000"+
		"\u0000\u0112\u00de\u0001\u0000\u0000\u0000\u0112\u00e6\u0001\u0000\u0000"+
		"\u0000\u0112\u00f1\u0001\u0000\u0000\u0000\u0112\u00fa\u0001\u0000\u0000"+
		"\u0000\u0112\u0100\u0001\u0000\u0000\u0000\u0112\u010a\u0001\u0000\u0000"+
		"\u0000\u0112\u010f\u0001\u0000\u0000\u0000\u0113\u001b\u0001\u0000\u0000"+
		"\u0000\u0114\u0115\u0005\'\u0000\u0000\u0115\u011e\u0006\u000e\uffff\uffff"+
		"\u0000\u0116\u0117\u0003 \u0010\u0000\u0117\u0118\u0005\'\u0000\u0000"+
		"\u0118\u0119\u0006\u000e\uffff\uffff\u0000\u0119\u011e\u0001\u0000\u0000"+
		"\u0000\u011a\u011b\u0003 \u0010\u0000\u011b\u011c\u0006\u000e\uffff\uffff"+
		"\u0000\u011c\u011e\u0001\u0000\u0000\u0000\u011d\u0114\u0001\u0000\u0000"+
		"\u0000\u011d\u0116\u0001\u0000\u0000\u0000\u011d\u011a\u0001\u0000\u0000"+
		"\u0000\u011e\u001d\u0001\u0000\u0000\u0000\u011f\u0120\u0005(\u0000\u0000"+
		"\u0120\u0129\u0006\u000f\uffff\uffff\u0000\u0121\u0122\u0005(\u0000\u0000"+
		"\u0122\u0123\u0005$\u0000\u0000\u0123\u0124\u0006\u000f\uffff\uffff\u0000"+
		"\u0124\u0125\u0003 \u0010\u0000\u0125\u0126\u0005%\u0000\u0000\u0126\u0127"+
		"\u0006\u000f\uffff\uffff\u0000\u0127\u0129\u0001\u0000\u0000\u0000\u0128"+
		"\u011f\u0001\u0000\u0000\u0000\u0128\u0121\u0001\u0000\u0000\u0000\u0129"+
		"\u001f\u0001\u0000\u0000\u0000\u012a\u012b\u0003\"\u0011\u0000\u012b\u012c"+
		"\u0006\u0010\uffff\uffff\u0000\u012c\u0135\u0001\u0000\u0000\u0000\u012d"+
		"\u012e\u0006\u0010\uffff\uffff\u0000\u012e\u012f\u0003\u001e\u000f\u0000"+
		"\u012f\u0130\u0006\u0010\uffff\uffff\u0000\u0130\u0131\u0005\u001d\u0000"+
		"\u0000\u0131\u0132\u0003\"\u0011\u0000\u0132\u0133\u0006\u0010\uffff\uffff"+
		"\u0000\u0133\u0135\u0001\u0000\u0000\u0000\u0134\u012a\u0001\u0000\u0000"+
		"\u0000\u0134\u012d\u0001\u0000\u0000\u0000\u0135!\u0001\u0000\u0000\u0000"+
		"\u0136\u0137\u0003$\u0012\u0000\u0137\u0138\u0006\u0011\uffff\uffff\u0000"+
		"\u0138\u0140\u0001\u0000\u0000\u0000\u0139\u013a\u0003$\u0012\u0000\u013a"+
		"\u013b\u0005\u001c\u0000\u0000\u013b\u013c\u0006\u0011\uffff\uffff\u0000"+
		"\u013c\u013d\u0003$\u0012\u0000\u013d\u013e\u0006\u0011\uffff\uffff\u0000"+
		"\u013e\u0140\u0001\u0000\u0000\u0000\u013f\u0136\u0001\u0000\u0000\u0000"+
		"\u013f\u0139\u0001\u0000\u0000\u0000\u0140#\u0001\u0000\u0000\u0000\u0141"+
		"\u0142\u0003&\u0013\u0000\u0142\u0143\u0006\u0012\uffff\uffff\u0000\u0143"+
		"\u014b\u0001\u0000\u0000\u0000\u0144\u0145\u0003&\u0013\u0000\u0145\u0146"+
		"\u0006\u0012\uffff\uffff\u0000\u0146\u0147\u0005\u001b\u0000\u0000\u0147"+
		"\u0148\u0003&\u0013\u0000\u0148\u0149\u0006\u0012\uffff\uffff\u0000\u0149"+
		"\u014b\u0001\u0000\u0000\u0000\u014a\u0141\u0001\u0000\u0000\u0000\u014a"+
		"\u0144\u0001\u0000\u0000\u0000\u014b%\u0001\u0000\u0000\u0000\u014c\u014d"+
		"\u0006\u0013\uffff\uffff\u0000\u014d\u014e\u0003(\u0014\u0000\u014e\u014f"+
		"\u0006\u0013\uffff\uffff\u0000\u014f\u0158\u0001\u0000\u0000\u0000\u0150"+
		"\u0151\n\u0001\u0000\u0000\u0151\u0152\u0006\u0013\uffff\uffff\u0000\u0152"+
		"\u0153\u0005\u0017\u0000\u0000\u0153\u0154\u0003(\u0014\u0000\u0154\u0155"+
		"\u0006\u0013\uffff\uffff\u0000\u0155\u0157\u0001\u0000\u0000\u0000\u0156"+
		"\u0150\u0001\u0000\u0000\u0000\u0157\u015a\u0001\u0000\u0000\u0000\u0158"+
		"\u0156\u0001\u0000\u0000\u0000\u0158\u0159\u0001\u0000\u0000\u0000\u0159"+
		"\'\u0001\u0000\u0000\u0000\u015a\u0158\u0001\u0000\u0000\u0000\u015b\u015c"+
		"\u0006\u0014\uffff\uffff\u0000\u015c\u015d\u0003*\u0015\u0000\u015d\u015e"+
		"\u0006\u0014\uffff\uffff\u0000\u015e\u0167\u0001\u0000\u0000\u0000\u015f"+
		"\u0160\n\u0001\u0000\u0000\u0160\u0161\u0006\u0014\uffff\uffff\u0000\u0161"+
		"\u0162\u0005\u0018\u0000\u0000\u0162\u0163\u0003*\u0015\u0000\u0163\u0164"+
		"\u0006\u0014\uffff\uffff\u0000\u0164\u0166\u0001\u0000\u0000\u0000\u0165"+
		"\u015f\u0001\u0000\u0000\u0000\u0166\u0169\u0001\u0000\u0000\u0000\u0167"+
		"\u0165\u0001\u0000\u0000\u0000\u0167\u0168\u0001\u0000\u0000\u0000\u0168"+
		")\u0001\u0000\u0000\u0000\u0169\u0167\u0001\u0000\u0000\u0000\u016a\u016b"+
		"\u0005\u0017\u0000\u0000\u016b\u016c\u0003*\u0015\u0000\u016c\u016d\u0006"+
		"\u0015\uffff\uffff\u0000\u016d\u017e\u0001\u0000\u0000\u0000\u016e\u016f"+
		"\u0005\u001f\u0000\u0000\u016f\u0170\u0003*\u0015\u0000\u0170\u0171\u0006"+
		"\u0015\uffff\uffff\u0000\u0171\u017e\u0001\u0000\u0000\u0000\u0172\u0173"+
		"\u0005\u0019\u0000\u0000\u0173\u0174\u0003\u001e\u000f\u0000\u0174\u0175"+
		"\u0006\u0015\uffff\uffff\u0000\u0175\u017e\u0001\u0000\u0000\u0000\u0176"+
		"\u0177\u0005\u001a\u0000\u0000\u0177\u0178\u0003\u001e\u000f\u0000\u0178"+
		"\u0179\u0006\u0015\uffff\uffff\u0000\u0179\u017e\u0001\u0000\u0000\u0000"+
		"\u017a\u017b\u0003,\u0016\u0000\u017b\u017c\u0006\u0015\uffff\uffff\u0000"+
		"\u017c\u017e\u0001\u0000\u0000\u0000\u017d\u016a\u0001\u0000\u0000\u0000"+
		"\u017d\u016e\u0001\u0000\u0000\u0000\u017d\u0172\u0001\u0000\u0000\u0000"+
		"\u017d\u0176\u0001\u0000\u0000\u0000\u017d\u017a\u0001\u0000\u0000\u0000"+
		"\u017e+\u0001\u0000\u0000\u0000\u017f\u0180\u0003\u001e\u000f\u0000\u0180"+
		"\u0181\u0006\u0016\uffff\uffff\u0000\u0181\u019a\u0001\u0000\u0000\u0000"+
		"\u0182\u0183\u0005(\u0000\u0000\u0183\u0184\u0005 \u0000\u0000\u0184\u0185"+
		"\u0003.\u0017\u0000\u0185\u0186\u0005!\u0000\u0000\u0186\u0187\u0006\u0016"+
		"\uffff\uffff\u0000\u0187\u019a\u0001\u0000\u0000\u0000\u0188\u0189\u0005"+
		" \u0000\u0000\u0189\u018a\u0003 \u0010\u0000\u018a\u018b\u0005!\u0000"+
		"\u0000\u018b\u018c\u0006\u0016\uffff\uffff\u0000\u018c\u019a\u0001\u0000"+
		"\u0000\u0000\u018d\u018e\u0005)\u0000\u0000\u018e\u019a\u0006\u0016\uffff"+
		"\uffff\u0000\u018f\u0190\u0005*\u0000\u0000\u0190\u019a\u0006\u0016\uffff"+
		"\uffff\u0000\u0191\u0192\u0003\u001e\u000f\u0000\u0192\u0193\u0005\u0019"+
		"\u0000\u0000\u0193\u0194\u0006\u0016\uffff\uffff\u0000\u0194\u019a\u0001"+
		"\u0000\u0000\u0000\u0195\u0196\u0003\u001e\u000f\u0000\u0196\u0197\u0005"+
		"\u001a\u0000\u0000\u0197\u0198\u0006\u0016\uffff\uffff\u0000\u0198\u019a"+
		"\u0001\u0000\u0000\u0000\u0199\u017f\u0001\u0000\u0000\u0000\u0199\u0182"+
		"\u0001\u0000\u0000\u0000\u0199\u0188\u0001\u0000\u0000\u0000\u0199\u018d"+
		"\u0001\u0000\u0000\u0000\u0199\u018f\u0001\u0000\u0000\u0000\u0199\u0191"+
		"\u0001\u0000\u0000\u0000\u0199\u0195\u0001\u0000\u0000\u0000\u019a-\u0001"+
		"\u0000\u0000\u0000\u019b\u019c\u00030\u0018\u0000\u019c\u019d\u0006\u0017"+
		"\uffff\uffff\u0000\u019d\u01a0\u0001\u0000\u0000\u0000\u019e\u01a0\u0006"+
		"\u0017\uffff\uffff\u0000\u019f\u019b\u0001\u0000\u0000\u0000\u019f\u019e"+
		"\u0001\u0000\u0000\u0000\u01a0/\u0001\u0000\u0000\u0000\u01a1\u01a2\u0006"+
		"\u0018\uffff\uffff\u0000\u01a2\u01a3\u0003\"\u0011\u0000\u01a3\u01a4\u0006"+
		"\u0018\uffff\uffff\u0000\u01a4\u01ac\u0001\u0000\u0000\u0000\u01a5\u01a6"+
		"\n\u0001\u0000\u0000\u01a6\u01a7\u0005&\u0000\u0000\u01a7\u01a8\u0003"+
		"\"\u0011\u0000\u01a8\u01a9\u0006\u0018\uffff\uffff\u0000\u01a9\u01ab\u0001"+
		"\u0000\u0000\u0000\u01aa\u01a5\u0001\u0000\u0000\u0000\u01ab\u01ae\u0001"+
		"\u0000\u0000\u0000\u01ac\u01aa\u0001\u0000\u0000\u0000\u01ac\u01ad\u0001"+
		"\u0000\u0000\u0000\u01ad1\u0001\u0000\u0000\u0000\u01ae\u01ac\u0001\u0000"+
		"\u0000\u0000\u0017?K]qy\u0083\u0090\u009d\u00ab\u00b9\u00c5\u0112\u011d"+
		"\u0128\u0134\u013f\u014a\u0158\u0167\u017d\u0199\u019f\u01ac";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}