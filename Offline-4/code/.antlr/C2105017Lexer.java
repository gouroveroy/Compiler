// Generated from c:/Users/User/OneDrive - BUET/BOOKS 3-1/CSE 309/Offline-Online/Offline-4/code/C2105017Lexer.g4 by ANTLR 4.13.1

    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    extern ofstream lexLogFile;
    extern ofstream errorFile;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class C2105017Lexer extends Lexer {
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
		CHAR_MODE=1, STRING_MODE=2;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE", "CHAR_MODE", "STRING_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"IF", "ELSE", "FOR", "WHILE", "DO", "SWITCH", "CASE", "DEFAULT", "BREAK", 
			"CONTINUE", "RETURN", "PRINTLN", "INT", "FLOAT", "CHAR", "DOUBLE", "VOID", 
			"LONG", "SHORT", "STATIC", "UNSIGNED", "GOTO", "ADDOP", "MULOP", "INCOP", 
			"DECOP", "RELOP", "LOGICOP", "ASSIGNOP", "BITOP", "NOT", "LPAREN", "RPAREN", 
			"LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "ID", "CONST_INT", 
			"CONST_FLOAT", "HASH", "SINGLE_QUOTE", "CHAR_EMPTY", "CHAR_CLOSE", "CHAR_ESCAPE", 
			"CHAR_ESC_NL", "CHAR_ERROR_NL", "CHAR_ANY", "DOUBLE_QUOTE", "STR_CLOSE", 
			"STR_ESCAPE", "STR_ESC_NL", "STR_NL_ERROR", "STR_ANY", "LINE_COMMENT", 
			"BLOCK_COMMENT", "WS", "NL", "UNRECOGNIZED"
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


	public C2105017Lexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "C2105017Lexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 0:
			IF_action((RuleContext)_localctx, actionIndex);
			break;
		case 1:
			ELSE_action((RuleContext)_localctx, actionIndex);
			break;
		case 2:
			FOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 3:
			WHILE_action((RuleContext)_localctx, actionIndex);
			break;
		case 4:
			DO_action((RuleContext)_localctx, actionIndex);
			break;
		case 5:
			SWITCH_action((RuleContext)_localctx, actionIndex);
			break;
		case 6:
			CASE_action((RuleContext)_localctx, actionIndex);
			break;
		case 7:
			DEFAULT_action((RuleContext)_localctx, actionIndex);
			break;
		case 8:
			BREAK_action((RuleContext)_localctx, actionIndex);
			break;
		case 9:
			CONTINUE_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			RETURN_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			PRINTLN_action((RuleContext)_localctx, actionIndex);
			break;
		case 12:
			INT_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			FLOAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			CHAR_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			DOUBLE_action((RuleContext)_localctx, actionIndex);
			break;
		case 16:
			VOID_action((RuleContext)_localctx, actionIndex);
			break;
		case 17:
			LONG_action((RuleContext)_localctx, actionIndex);
			break;
		case 18:
			SHORT_action((RuleContext)_localctx, actionIndex);
			break;
		case 19:
			STATIC_action((RuleContext)_localctx, actionIndex);
			break;
		case 20:
			UNSIGNED_action((RuleContext)_localctx, actionIndex);
			break;
		case 21:
			GOTO_action((RuleContext)_localctx, actionIndex);
			break;
		case 22:
			ADDOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 23:
			MULOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			INCOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 25:
			DECOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 26:
			RELOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 27:
			LOGICOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 28:
			ASSIGNOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 29:
			BITOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 30:
			NOT_action((RuleContext)_localctx, actionIndex);
			break;
		case 31:
			LPAREN_action((RuleContext)_localctx, actionIndex);
			break;
		case 32:
			RPAREN_action((RuleContext)_localctx, actionIndex);
			break;
		case 33:
			LCURL_action((RuleContext)_localctx, actionIndex);
			break;
		case 34:
			RCURL_action((RuleContext)_localctx, actionIndex);
			break;
		case 35:
			LTHIRD_action((RuleContext)_localctx, actionIndex);
			break;
		case 36:
			RTHIRD_action((RuleContext)_localctx, actionIndex);
			break;
		case 37:
			COMMA_action((RuleContext)_localctx, actionIndex);
			break;
		case 38:
			SEMICOLON_action((RuleContext)_localctx, actionIndex);
			break;
		case 39:
			ID_action((RuleContext)_localctx, actionIndex);
			break;
		case 40:
			CONST_INT_action((RuleContext)_localctx, actionIndex);
			break;
		case 41:
			CONST_FLOAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 44:
			CHAR_EMPTY_action((RuleContext)_localctx, actionIndex);
			break;
		case 45:
			CHAR_CLOSE_action((RuleContext)_localctx, actionIndex);
			break;
		case 47:
			CHAR_ESC_NL_action((RuleContext)_localctx, actionIndex);
			break;
		case 48:
			CHAR_ERROR_NL_action((RuleContext)_localctx, actionIndex);
			break;
		case 51:
			STR_CLOSE_action((RuleContext)_localctx, actionIndex);
			break;
		case 53:
			STR_ESC_NL_action((RuleContext)_localctx, actionIndex);
			break;
		case 54:
			STR_NL_ERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 56:
			LINE_COMMENT_action((RuleContext)_localctx, actionIndex);
			break;
		case 57:
			BLOCK_COMMENT_action((RuleContext)_localctx, actionIndex);
			break;
		case 59:
			NL_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void IF_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <IF> Lexeme " + getText()); 
			break;
		}
	}
	private void ELSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ELSE> Lexeme " + getText()); 
			break;
		}
	}
	private void FOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <FOR> Lexeme " + getText()); 
			break;
		}
	}
	private void WHILE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <WHILE> Lexeme " + getText()); 
			break;
		}
	}
	private void DO_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DO> Lexeme " + getText()); 
			break;
		}
	}
	private void SWITCH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <SWITCH> Lexeme " + getText()); 
			break;
		}
	}
	private void CASE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CASE> Lexeme " + getText()); 
			break;
		}
	}
	private void DEFAULT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DEFAULT> Lexeme " + getText()); 
			break;
		}
	}
	private void BREAK_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <BREAK> Lexeme " + getText()); 
			break;
		}
	}
	private void CONTINUE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONTINUE> Lexeme " + getText()); 
			break;
		}
	}
	private void RETURN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RETURN> Lexeme " + getText()); 
			break;
		}
	}
	private void PRINTLN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <PRINTLN> Lexeme " + getText()); 
			break;
		}
	}
	private void INT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <INT> Lexeme " + getText()); 
			break;
		}
	}
	private void FLOAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <FLOAT> Lexeme " + getText()); 
			break;
		}
	}
	private void CHAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CHAR> Lexeme " + getText()); 
			break;
		}
	}
	private void DOUBLE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DOUBLE> Lexeme " + getText()); 
			break;
		}
	}
	private void VOID_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <VOID> Lexeme " + getText()); 
			break;
		}
	}
	private void LONG_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LONG> Lexeme " + getText()); 
			break;
		}
	}
	private void SHORT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <SHORT> Lexeme " + getText()); 
			break;
		}
	}
	private void STATIC_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 19:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <STATIC> Lexeme " + getText()); 
			break;
		}
	}
	private void UNSIGNED_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 20:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <UNSIGNED> Lexeme " + getText()); 
			break;
		}
	}
	private void GOTO_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 21:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <GOTO> Lexeme " + getText()); 
			break;
		}
	}
	private void ADDOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 22:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ADDOP> Lexeme " + getText()); 
			break;
		}
	}
	private void MULOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 23:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <MULOP> Lexeme " + getText()); 
			break;
		}
	}
	private void INCOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 24:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <INCOP> Lexeme " + getText()); 
			break;
		}
	}
	private void DECOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 25:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <DECOP> Lexeme " + getText()); 
			break;
		}
	}
	private void RELOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 26:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RELOP> Lexeme " + getText()); 
			break;
		}
	}
	private void LOGICOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 27:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LOGICOP> Lexeme " + getText()); 
			break;
		}
	}
	private void ASSIGNOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 28:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ASSIGNOP> Lexeme " + getText()); 
			break;
		}
	}
	private void BITOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 29:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <BITOP> Lexeme " + getText()); 
			break;
		}
	}
	private void NOT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 30:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <NOT> Lexeme " + getText()); 
			break;
		}
	}
	private void LPAREN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 31:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LPAREN> Lexeme " + getText()); 
			break;
		}
	}
	private void RPAREN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 32:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RPAREN> Lexeme " + getText()); 
			break;
		}
	}
	private void LCURL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 33:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LCURL> Lexeme " + getText()); 
			break;
		}
	}
	private void RCURL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 34:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RCURL> Lexeme " + getText()); 
			break;
		}
	}
	private void LTHIRD_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 35:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LTHIRD> Lexeme " + getText()); 
			break;
		}
	}
	private void RTHIRD_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 36:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <RTHIRD> Lexeme " + getText()); 
			break;
		}
	}
	private void COMMA_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 37:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <COMMA> Lexeme " + getText()); 
			break;
		}
	}
	private void SEMICOLON_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 38:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <SEMICOLON> Lexeme " + getText()); 
			break;
		}
	}
	private void ID_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 39:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <ID> Lexeme " + getText()); 
			break;
		}
	}
	private void CONST_INT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 40:
			 writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONST_INT> Lexeme " + getText()); 
			break;
		}
	}
	private void CONST_FLOAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 41:

			        writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONST_FLOAT> Lexeme " + getText());
			    
			break;
		}
	}
	private void CHAR_EMPTY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 42:

			            // notifyErrorListeners("Empty character constant");
			          
			break;
		}
	}
	private void CHAR_CLOSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 43:

			            writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <CONST_CHAR> Lexeme " + getText());
			          
			break;
		}
	}
	private void CHAR_ESC_NL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 44:
			 lineCount++; 
			break;
		}
	}
	private void CHAR_ERROR_NL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 45:

			            // notifyErrorListeners("Unterminated character");
			            lineCount++;
			          
			break;
		}
	}
	private void STR_CLOSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 46:

			            writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <STRING> Lexeme " + getText());
			          
			break;
		}
	}
	private void STR_ESC_NL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 47:
			 lineCount++; 
			break;
		}
	}
	private void STR_NL_ERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 48:

			            // notifyErrorListeners("Unterminated string");
			            lineCount++;
			          
			break;
		}
	}
	private void LINE_COMMENT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 49:
			 lineCount++; 
			break;
		case 50:

			        writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <LINE_COMMENT> Lexeme " + getText());
			      
			break;
		}
	}
	private void BLOCK_COMMENT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 51:

			        {
			          // strip /* and */
			          string body = getText().substr(2, getText().size()-4);
			          writeIntoLexLogFile("Line# " + to_string(getLine()) + ": Token <BLOCK_COMMENT> Lexeme /*" + body + "*/");
			        }
			      
			break;
		}
	}
	private void NL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 52:
			 lineCount++; 
			break;
		}
	}

	public static final String _serializedATN =
		"\u0004\u00007\u022e\u0006\uffff\uffff\u0006\uffff\uffff\u0006\uffff\uffff"+
		"\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002\u0002\u0007\u0002"+
		"\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002\u0005\u0007\u0005"+
		"\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002\b\u0007\b\u0002"+
		"\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002\f\u0007\f\u0002"+
		"\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f\u0002\u0010"+
		"\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012\u0002\u0013"+
		"\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015\u0002\u0016"+
		"\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018\u0002\u0019"+
		"\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b\u0002\u001c"+
		"\u0007\u001c\u0002\u001d\u0007\u001d\u0002\u001e\u0007\u001e\u0002\u001f"+
		"\u0007\u001f\u0002 \u0007 \u0002!\u0007!\u0002\"\u0007\"\u0002#\u0007"+
		"#\u0002$\u0007$\u0002%\u0007%\u0002&\u0007&\u0002\'\u0007\'\u0002(\u0007"+
		"(\u0002)\u0007)\u0002*\u0007*\u0002+\u0007+\u0002,\u0007,\u0002-\u0007"+
		"-\u0002.\u0007.\u0002/\u0007/\u00020\u00070\u00021\u00071\u00022\u0007"+
		"2\u00023\u00073\u00024\u00074\u00025\u00075\u00026\u00076\u00027\u0007"+
		"7\u00028\u00078\u00029\u00079\u0002:\u0007:\u0002;\u0007;\u0002<\u0007"+
		"<\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0011\u0001\u0011"+
		"\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0003\u0016\u012f\b\u0016\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0003\u0017\u0134\b\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0003\u001a"+
		"\u014b\b\u001a\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0003\u001b\u0153\b\u001b\u0001\u001c\u0001\u001c\u0001\u001c"+
		"\u0001\u001d\u0001\u001d\u0001\u001d\u0003\u001d\u015b\b\u001d\u0001\u001e"+
		"\u0001\u001e\u0001\u001e\u0001\u001f\u0001\u001f\u0001\u001f\u0001 \u0001"+
		" \u0001 \u0001!\u0001!\u0001!\u0001\"\u0001\"\u0001\"\u0001#\u0001#\u0001"+
		"#\u0001$\u0001$\u0001$\u0001%\u0001%\u0001%\u0001&\u0001&\u0001&\u0001"+
		"\'\u0001\'\u0005\'\u017a\b\'\n\'\f\'\u017d\t\'\u0001\'\u0001\'\u0001("+
		"\u0004(\u0182\b(\u000b(\f(\u0183\u0001(\u0001(\u0001)\u0005)\u0189\b)"+
		"\n)\f)\u018c\t)\u0001)\u0001)\u0004)\u0190\b)\u000b)\f)\u0191\u0001)\u0001"+
		")\u0003)\u0196\b)\u0001)\u0004)\u0199\b)\u000b)\f)\u019a\u0003)\u019d"+
		"\b)\u0001)\u0004)\u01a0\b)\u000b)\f)\u01a1\u0001)\u0001)\u0003)\u01a6"+
		"\b)\u0001)\u0004)\u01a9\b)\u000b)\f)\u01aa\u0001)\u0003)\u01ae\b)\u0001"+
		"*\u0001*\u0001+\u0001+\u0001+\u0001+\u0001,\u0001,\u0001,\u0001,\u0001"+
		",\u0001-\u0001-\u0001-\u0001-\u0001-\u0001.\u0001.\u0001.\u0001.\u0001"+
		".\u0001/\u0001/\u0003/\u01c7\b/\u0001/\u0001/\u0001/\u0001/\u0001/\u0001"+
		"0\u00010\u00010\u00010\u00010\u00011\u00011\u00011\u00011\u00012\u0001"+
		"2\u00012\u00012\u00013\u00013\u00013\u00013\u00013\u00014\u00014\u0001"+
		"4\u00014\u00014\u00015\u00015\u00035\u01e7\b5\u00015\u00015\u00015\u0001"+
		"5\u00015\u00016\u00016\u00016\u00016\u00016\u00017\u00047\u01f4\b7\u000b"+
		"7\f7\u01f5\u00017\u00017\u00018\u00018\u00018\u00018\u00018\u00038\u01ff"+
		"\b8\u00018\u00018\u00018\u00058\u0204\b8\n8\f8\u0207\t8\u00018\u00018"+
		"\u00018\u00018\u00019\u00019\u00019\u00019\u00019\u00059\u0212\b9\n9\f"+
		"9\u0215\t9\u00019\u00019\u00019\u00019\u00019\u00019\u00019\u0001:\u0004"+
		":\u021f\b:\u000b:\f:\u0220\u0001:\u0001:\u0001;\u0003;\u0226\b;\u0001"+
		";\u0001;\u0001;\u0001;\u0001;\u0001<\u0001<\u0001\u0213\u0000=\u0003\u0001"+
		"\u0005\u0002\u0007\u0003\t\u0004\u000b\u0005\r\u0006\u000f\u0007\u0011"+
		"\b\u0013\t\u0015\n\u0017\u000b\u0019\f\u001b\r\u001d\u000e\u001f\u000f"+
		"!\u0010#\u0011%\u0012\'\u0013)\u0014+\u0015-\u0016/\u00171\u00183\u0019"+
		"5\u001a7\u001b9\u001c;\u001d=\u001e?\u001fA C!E\"G#I$K%M&O\'Q(S)U*W+Y"+
		",[-]._\u0000a\u0000c/e\u0000g0i1k\u0000m\u0000o2q\u0000s3u4w5y6{7\u0003"+
		"\u0000\u0001\u0002\u000b\u0002\u0000**//\u0002\u0000&&||\u0003\u0000A"+
		"Z__az\u0004\u000009AZ__az\u0001\u000009\u0002\u0000EEee\u0002\u0000++"+
		"--\n\u0000\"\"\'\'00\\\\abffnnrrttvv\u0004\u0000\n\n\r\r\"\"\\\\\u0002"+
		"\u0000\n\n\r\r\u0003\u0000\t\t\f\r  \u0249\u0000\u0003\u0001\u0000\u0000"+
		"\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000"+
		"\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000"+
		"\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000"+
		"\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000"+
		"\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000"+
		"\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000"+
		"\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0000"+
		"!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000%\u0001"+
		"\u0000\u0000\u0000\u0000\'\u0001\u0000\u0000\u0000\u0000)\u0001\u0000"+
		"\u0000\u0000\u0000+\u0001\u0000\u0000\u0000\u0000-\u0001\u0000\u0000\u0000"+
		"\u0000/\u0001\u0000\u0000\u0000\u00001\u0001\u0000\u0000\u0000\u00003"+
		"\u0001\u0000\u0000\u0000\u00005\u0001\u0000\u0000\u0000\u00007\u0001\u0000"+
		"\u0000\u0000\u00009\u0001\u0000\u0000\u0000\u0000;\u0001\u0000\u0000\u0000"+
		"\u0000=\u0001\u0000\u0000\u0000\u0000?\u0001\u0000\u0000\u0000\u0000A"+
		"\u0001\u0000\u0000\u0000\u0000C\u0001\u0000\u0000\u0000\u0000E\u0001\u0000"+
		"\u0000\u0000\u0000G\u0001\u0000\u0000\u0000\u0000I\u0001\u0000\u0000\u0000"+
		"\u0000K\u0001\u0000\u0000\u0000\u0000M\u0001\u0000\u0000\u0000\u0000O"+
		"\u0001\u0000\u0000\u0000\u0000Q\u0001\u0000\u0000\u0000\u0000S\u0001\u0000"+
		"\u0000\u0000\u0000U\u0001\u0000\u0000\u0000\u0000W\u0001\u0000\u0000\u0000"+
		"\u0000Y\u0001\u0000\u0000\u0000\u0001[\u0001\u0000\u0000\u0000\u0001]"+
		"\u0001\u0000\u0000\u0000\u0001_\u0001\u0000\u0000\u0000\u0001a\u0001\u0000"+
		"\u0000\u0000\u0001c\u0001\u0000\u0000\u0000\u0001e\u0001\u0000\u0000\u0000"+
		"\u0001g\u0001\u0000\u0000\u0000\u0002i\u0001\u0000\u0000\u0000\u0002k"+
		"\u0001\u0000\u0000\u0000\u0002m\u0001\u0000\u0000\u0000\u0002o\u0001\u0000"+
		"\u0000\u0000\u0002q\u0001\u0000\u0000\u0000\u0002s\u0001\u0000\u0000\u0000"+
		"\u0002u\u0001\u0000\u0000\u0000\u0002w\u0001\u0000\u0000\u0000\u0002y"+
		"\u0001\u0000\u0000\u0000\u0002{\u0001\u0000\u0000\u0000\u0003}\u0001\u0000"+
		"\u0000\u0000\u0005\u0082\u0001\u0000\u0000\u0000\u0007\u0089\u0001\u0000"+
		"\u0000\u0000\t\u008f\u0001\u0000\u0000\u0000\u000b\u0097\u0001\u0000\u0000"+
		"\u0000\r\u009c\u0001\u0000\u0000\u0000\u000f\u00a5\u0001\u0000\u0000\u0000"+
		"\u0011\u00ac\u0001\u0000\u0000\u0000\u0013\u00b6\u0001\u0000\u0000\u0000"+
		"\u0015\u00be\u0001\u0000\u0000\u0000\u0017\u00c9\u0001\u0000\u0000\u0000"+
		"\u0019\u00d2\u0001\u0000\u0000\u0000\u001b\u00dc\u0001\u0000\u0000\u0000"+
		"\u001d\u00e2\u0001\u0000\u0000\u0000\u001f\u00ea\u0001\u0000\u0000\u0000"+
		"!\u00f1\u0001\u0000\u0000\u0000#\u00fa\u0001\u0000\u0000\u0000%\u0101"+
		"\u0001\u0000\u0000\u0000\'\u0108\u0001\u0000\u0000\u0000)\u0110\u0001"+
		"\u0000\u0000\u0000+\u0119\u0001\u0000\u0000\u0000-\u0124\u0001\u0000\u0000"+
		"\u0000/\u012e\u0001\u0000\u0000\u00001\u0133\u0001\u0000\u0000\u00003"+
		"\u0135\u0001\u0000\u0000\u00005\u013a\u0001\u0000\u0000\u00007\u014a\u0001"+
		"\u0000\u0000\u00009\u0152\u0001\u0000\u0000\u0000;\u0154\u0001\u0000\u0000"+
		"\u0000=\u015a\u0001\u0000\u0000\u0000?\u015c\u0001\u0000\u0000\u0000A"+
		"\u015f\u0001\u0000\u0000\u0000C\u0162\u0001\u0000\u0000\u0000E\u0165\u0001"+
		"\u0000\u0000\u0000G\u0168\u0001\u0000\u0000\u0000I\u016b\u0001\u0000\u0000"+
		"\u0000K\u016e\u0001\u0000\u0000\u0000M\u0171\u0001\u0000\u0000\u0000O"+
		"\u0174\u0001\u0000\u0000\u0000Q\u0177\u0001\u0000\u0000\u0000S\u0181\u0001"+
		"\u0000\u0000\u0000U\u01ad\u0001\u0000\u0000\u0000W\u01af\u0001\u0000\u0000"+
		"\u0000Y\u01b1\u0001\u0000\u0000\u0000[\u01b5\u0001\u0000\u0000\u0000]"+
		"\u01ba\u0001\u0000\u0000\u0000_\u01bf\u0001\u0000\u0000\u0000a\u01c4\u0001"+
		"\u0000\u0000\u0000c\u01cd\u0001\u0000\u0000\u0000e\u01d2\u0001\u0000\u0000"+
		"\u0000g\u01d6\u0001\u0000\u0000\u0000i\u01da\u0001\u0000\u0000\u0000k"+
		"\u01df\u0001\u0000\u0000\u0000m\u01e4\u0001\u0000\u0000\u0000o\u01ed\u0001"+
		"\u0000\u0000\u0000q\u01f3\u0001\u0000\u0000\u0000s\u01f9\u0001\u0000\u0000"+
		"\u0000u\u020c\u0001\u0000\u0000\u0000w\u021e\u0001\u0000\u0000\u0000y"+
		"\u0225\u0001\u0000\u0000\u0000{\u022c\u0001\u0000\u0000\u0000}~\u0005"+
		"i\u0000\u0000~\u007f\u0005f\u0000\u0000\u007f\u0080\u0001\u0000\u0000"+
		"\u0000\u0080\u0081\u0006\u0000\u0000\u0000\u0081\u0004\u0001\u0000\u0000"+
		"\u0000\u0082\u0083\u0005e\u0000\u0000\u0083\u0084\u0005l\u0000\u0000\u0084"+
		"\u0085\u0005s\u0000\u0000\u0085\u0086\u0005e\u0000\u0000\u0086\u0087\u0001"+
		"\u0000\u0000\u0000\u0087\u0088\u0006\u0001\u0001\u0000\u0088\u0006\u0001"+
		"\u0000\u0000\u0000\u0089\u008a\u0005f\u0000\u0000\u008a\u008b\u0005o\u0000"+
		"\u0000\u008b\u008c\u0005r\u0000\u0000\u008c\u008d\u0001\u0000\u0000\u0000"+
		"\u008d\u008e\u0006\u0002\u0002\u0000\u008e\b\u0001\u0000\u0000\u0000\u008f"+
		"\u0090\u0005w\u0000\u0000\u0090\u0091\u0005h\u0000\u0000\u0091\u0092\u0005"+
		"i\u0000\u0000\u0092\u0093\u0005l\u0000\u0000\u0093\u0094\u0005e\u0000"+
		"\u0000\u0094\u0095\u0001\u0000\u0000\u0000\u0095\u0096\u0006\u0003\u0003"+
		"\u0000\u0096\n\u0001\u0000\u0000\u0000\u0097\u0098\u0005d\u0000\u0000"+
		"\u0098\u0099\u0005o\u0000\u0000\u0099\u009a\u0001\u0000\u0000\u0000\u009a"+
		"\u009b\u0006\u0004\u0004\u0000\u009b\f\u0001\u0000\u0000\u0000\u009c\u009d"+
		"\u0005s\u0000\u0000\u009d\u009e\u0005w\u0000\u0000\u009e\u009f\u0005i"+
		"\u0000\u0000\u009f\u00a0\u0005t\u0000\u0000\u00a0\u00a1\u0005c\u0000\u0000"+
		"\u00a1\u00a2\u0005h\u0000\u0000\u00a2\u00a3\u0001\u0000\u0000\u0000\u00a3"+
		"\u00a4\u0006\u0005\u0005\u0000\u00a4\u000e\u0001\u0000\u0000\u0000\u00a5"+
		"\u00a6\u0005c\u0000\u0000\u00a6\u00a7\u0005a\u0000\u0000\u00a7\u00a8\u0005"+
		"s\u0000\u0000\u00a8\u00a9\u0005e\u0000\u0000\u00a9\u00aa\u0001\u0000\u0000"+
		"\u0000\u00aa\u00ab\u0006\u0006\u0006\u0000\u00ab\u0010\u0001\u0000\u0000"+
		"\u0000\u00ac\u00ad\u0005d\u0000\u0000\u00ad\u00ae\u0005e\u0000\u0000\u00ae"+
		"\u00af\u0005f\u0000\u0000\u00af\u00b0\u0005a\u0000\u0000\u00b0\u00b1\u0005"+
		"u\u0000\u0000\u00b1\u00b2\u0005l\u0000\u0000\u00b2\u00b3\u0005t\u0000"+
		"\u0000\u00b3\u00b4\u0001\u0000\u0000\u0000\u00b4\u00b5\u0006\u0007\u0007"+
		"\u0000\u00b5\u0012\u0001\u0000\u0000\u0000\u00b6\u00b7\u0005b\u0000\u0000"+
		"\u00b7\u00b8\u0005r\u0000\u0000\u00b8\u00b9\u0005e\u0000\u0000\u00b9\u00ba"+
		"\u0005a\u0000\u0000\u00ba\u00bb\u0005k\u0000\u0000\u00bb\u00bc\u0001\u0000"+
		"\u0000\u0000\u00bc\u00bd\u0006\b\b\u0000\u00bd\u0014\u0001\u0000\u0000"+
		"\u0000\u00be\u00bf\u0005c\u0000\u0000\u00bf\u00c0\u0005o\u0000\u0000\u00c0"+
		"\u00c1\u0005n\u0000\u0000\u00c1\u00c2\u0005t\u0000\u0000\u00c2\u00c3\u0005"+
		"i\u0000\u0000\u00c3\u00c4\u0005n\u0000\u0000\u00c4\u00c5\u0005u\u0000"+
		"\u0000\u00c5\u00c6\u0005e\u0000\u0000\u00c6\u00c7\u0001\u0000\u0000\u0000"+
		"\u00c7\u00c8\u0006\t\t\u0000\u00c8\u0016\u0001\u0000\u0000\u0000\u00c9"+
		"\u00ca\u0005r\u0000\u0000\u00ca\u00cb\u0005e\u0000\u0000\u00cb\u00cc\u0005"+
		"t\u0000\u0000\u00cc\u00cd\u0005u\u0000\u0000\u00cd\u00ce\u0005r\u0000"+
		"\u0000\u00ce\u00cf\u0005n\u0000\u0000\u00cf\u00d0\u0001\u0000\u0000\u0000"+
		"\u00d0\u00d1\u0006\n\n\u0000\u00d1\u0018\u0001\u0000\u0000\u0000\u00d2"+
		"\u00d3\u0005p\u0000\u0000\u00d3\u00d4\u0005r\u0000\u0000\u00d4\u00d5\u0005"+
		"i\u0000\u0000\u00d5\u00d6\u0005n\u0000\u0000\u00d6\u00d7\u0005t\u0000"+
		"\u0000\u00d7\u00d8\u0005l\u0000\u0000\u00d8\u00d9\u0005n\u0000\u0000\u00d9"+
		"\u00da\u0001\u0000\u0000\u0000\u00da\u00db\u0006\u000b\u000b\u0000\u00db"+
		"\u001a\u0001\u0000\u0000\u0000\u00dc\u00dd\u0005i\u0000\u0000\u00dd\u00de"+
		"\u0005n\u0000\u0000\u00de\u00df\u0005t\u0000\u0000\u00df\u00e0\u0001\u0000"+
		"\u0000\u0000\u00e0\u00e1\u0006\f\f\u0000\u00e1\u001c\u0001\u0000\u0000"+
		"\u0000\u00e2\u00e3\u0005f\u0000\u0000\u00e3\u00e4\u0005l\u0000\u0000\u00e4"+
		"\u00e5\u0005o\u0000\u0000\u00e5\u00e6\u0005a\u0000\u0000\u00e6\u00e7\u0005"+
		"t\u0000\u0000\u00e7\u00e8\u0001\u0000\u0000\u0000\u00e8\u00e9\u0006\r"+
		"\r\u0000\u00e9\u001e\u0001\u0000\u0000\u0000\u00ea\u00eb\u0005c\u0000"+
		"\u0000\u00eb\u00ec\u0005h\u0000\u0000\u00ec\u00ed\u0005a\u0000\u0000\u00ed"+
		"\u00ee\u0005r\u0000\u0000\u00ee\u00ef\u0001\u0000\u0000\u0000\u00ef\u00f0"+
		"\u0006\u000e\u000e\u0000\u00f0 \u0001\u0000\u0000\u0000\u00f1\u00f2\u0005"+
		"d\u0000\u0000\u00f2\u00f3\u0005o\u0000\u0000\u00f3\u00f4\u0005u\u0000"+
		"\u0000\u00f4\u00f5\u0005b\u0000\u0000\u00f5\u00f6\u0005l\u0000\u0000\u00f6"+
		"\u00f7\u0005e\u0000\u0000\u00f7\u00f8\u0001\u0000\u0000\u0000\u00f8\u00f9"+
		"\u0006\u000f\u000f\u0000\u00f9\"\u0001\u0000\u0000\u0000\u00fa\u00fb\u0005"+
		"v\u0000\u0000\u00fb\u00fc\u0005o\u0000\u0000\u00fc\u00fd\u0005i\u0000"+
		"\u0000\u00fd\u00fe\u0005d\u0000\u0000\u00fe\u00ff\u0001\u0000\u0000\u0000"+
		"\u00ff\u0100\u0006\u0010\u0010\u0000\u0100$\u0001\u0000\u0000\u0000\u0101"+
		"\u0102\u0005l\u0000\u0000\u0102\u0103\u0005o\u0000\u0000\u0103\u0104\u0005"+
		"n\u0000\u0000\u0104\u0105\u0005g\u0000\u0000\u0105\u0106\u0001\u0000\u0000"+
		"\u0000\u0106\u0107\u0006\u0011\u0011\u0000\u0107&\u0001\u0000\u0000\u0000"+
		"\u0108\u0109\u0005s\u0000\u0000\u0109\u010a\u0005h\u0000\u0000\u010a\u010b"+
		"\u0005o\u0000\u0000\u010b\u010c\u0005r\u0000\u0000\u010c\u010d\u0005t"+
		"\u0000\u0000\u010d\u010e\u0001\u0000\u0000\u0000\u010e\u010f\u0006\u0012"+
		"\u0012\u0000\u010f(\u0001\u0000\u0000\u0000\u0110\u0111\u0005s\u0000\u0000"+
		"\u0111\u0112\u0005t\u0000\u0000\u0112\u0113\u0005a\u0000\u0000\u0113\u0114"+
		"\u0005t\u0000\u0000\u0114\u0115\u0005i\u0000\u0000\u0115\u0116\u0005c"+
		"\u0000\u0000\u0116\u0117\u0001\u0000\u0000\u0000\u0117\u0118\u0006\u0013"+
		"\u0013\u0000\u0118*\u0001\u0000\u0000\u0000\u0119\u011a\u0005u\u0000\u0000"+
		"\u011a\u011b\u0005n\u0000\u0000\u011b\u011c\u0005s\u0000\u0000\u011c\u011d"+
		"\u0005i\u0000\u0000\u011d\u011e\u0005g\u0000\u0000\u011e\u011f\u0005n"+
		"\u0000\u0000\u011f\u0120\u0005e\u0000\u0000\u0120\u0121\u0005d\u0000\u0000"+
		"\u0121\u0122\u0001\u0000\u0000\u0000\u0122\u0123\u0006\u0014\u0014\u0000"+
		"\u0123,\u0001\u0000\u0000\u0000\u0124\u0125\u0005g\u0000\u0000\u0125\u0126"+
		"\u0005o\u0000\u0000\u0126\u0127\u0005t\u0000\u0000\u0127\u0128\u0005o"+
		"\u0000\u0000\u0128\u0129\u0001\u0000\u0000\u0000\u0129\u012a\u0006\u0015"+
		"\u0015\u0000\u012a.\u0001\u0000\u0000\u0000\u012b\u012f\u0005+\u0000\u0000"+
		"\u012c\u012d\u0005-\u0000\u0000\u012d\u012f\u0006\u0016\u0016\u0000\u012e"+
		"\u012b\u0001\u0000\u0000\u0000\u012e\u012c\u0001\u0000\u0000\u0000\u012f"+
		"0\u0001\u0000\u0000\u0000\u0130\u0134\u0007\u0000\u0000\u0000\u0131\u0132"+
		"\u0005%\u0000\u0000\u0132\u0134\u0006\u0017\u0017\u0000\u0133\u0130\u0001"+
		"\u0000\u0000\u0000\u0133\u0131\u0001\u0000\u0000\u0000\u01342\u0001\u0000"+
		"\u0000\u0000\u0135\u0136\u0005+\u0000\u0000\u0136\u0137\u0005+\u0000\u0000"+
		"\u0137\u0138\u0001\u0000\u0000\u0000\u0138\u0139\u0006\u0018\u0018\u0000"+
		"\u01394\u0001\u0000\u0000\u0000\u013a\u013b\u0005-\u0000\u0000\u013b\u013c"+
		"\u0005-\u0000\u0000\u013c\u013d\u0001\u0000\u0000\u0000\u013d\u013e\u0006"+
		"\u0019\u0019\u0000\u013e6\u0001\u0000\u0000\u0000\u013f\u0140\u0005<\u0000"+
		"\u0000\u0140\u014b\u0005=\u0000\u0000\u0141\u0142\u0005>\u0000\u0000\u0142"+
		"\u014b\u0005=\u0000\u0000\u0143\u0144\u0005=\u0000\u0000\u0144\u014b\u0005"+
		"=\u0000\u0000\u0145\u0146\u0005!\u0000\u0000\u0146\u014b\u0005=\u0000"+
		"\u0000\u0147\u014b\u0005<\u0000\u0000\u0148\u0149\u0005>\u0000\u0000\u0149"+
		"\u014b\u0006\u001a\u001a\u0000\u014a\u013f\u0001\u0000\u0000\u0000\u014a"+
		"\u0141\u0001\u0000\u0000\u0000\u014a\u0143\u0001\u0000\u0000\u0000\u014a"+
		"\u0145\u0001\u0000\u0000\u0000\u014a\u0147\u0001\u0000\u0000\u0000\u014a"+
		"\u0148\u0001\u0000\u0000\u0000\u014b8\u0001\u0000\u0000\u0000\u014c\u014d"+
		"\u0005&\u0000\u0000\u014d\u0153\u0005&\u0000\u0000\u014e\u014f\u0005|"+
		"\u0000\u0000\u014f\u0150\u0005|\u0000\u0000\u0150\u0151\u0001\u0000\u0000"+
		"\u0000\u0151\u0153\u0006\u001b\u001b\u0000\u0152\u014c\u0001\u0000\u0000"+
		"\u0000\u0152\u014e\u0001\u0000\u0000\u0000\u0153:\u0001\u0000\u0000\u0000"+
		"\u0154\u0155\u0005=\u0000\u0000\u0155\u0156\u0006\u001c\u001c\u0000\u0156"+
		"<\u0001\u0000\u0000\u0000\u0157\u015b\u0007\u0001\u0000\u0000\u0158\u0159"+
		"\u0005^\u0000\u0000\u0159\u015b\u0006\u001d\u001d\u0000\u015a\u0157\u0001"+
		"\u0000\u0000\u0000\u015a\u0158\u0001\u0000\u0000\u0000\u015b>\u0001\u0000"+
		"\u0000\u0000\u015c\u015d\u0005!\u0000\u0000\u015d\u015e\u0006\u001e\u001e"+
		"\u0000\u015e@\u0001\u0000\u0000\u0000\u015f\u0160\u0005(\u0000\u0000\u0160"+
		"\u0161\u0006\u001f\u001f\u0000\u0161B\u0001\u0000\u0000\u0000\u0162\u0163"+
		"\u0005)\u0000\u0000\u0163\u0164\u0006  \u0000\u0164D\u0001\u0000\u0000"+
		"\u0000\u0165\u0166\u0005{\u0000\u0000\u0166\u0167\u0006!!\u0000\u0167"+
		"F\u0001\u0000\u0000\u0000\u0168\u0169\u0005}\u0000\u0000\u0169\u016a\u0006"+
		"\"\"\u0000\u016aH\u0001\u0000\u0000\u0000\u016b\u016c\u0005[\u0000\u0000"+
		"\u016c\u016d\u0006##\u0000\u016dJ\u0001\u0000\u0000\u0000\u016e\u016f"+
		"\u0005]\u0000\u0000\u016f\u0170\u0006$$\u0000\u0170L\u0001\u0000\u0000"+
		"\u0000\u0171\u0172\u0005,\u0000\u0000\u0172\u0173\u0006%%\u0000\u0173"+
		"N\u0001\u0000\u0000\u0000\u0174\u0175\u0005;\u0000\u0000\u0175\u0176\u0006"+
		"&&\u0000\u0176P\u0001\u0000\u0000\u0000\u0177\u017b\u0007\u0002\u0000"+
		"\u0000\u0178\u017a\u0007\u0003\u0000\u0000\u0179\u0178\u0001\u0000\u0000"+
		"\u0000\u017a\u017d\u0001\u0000\u0000\u0000\u017b\u0179\u0001\u0000\u0000"+
		"\u0000\u017b\u017c\u0001\u0000\u0000\u0000\u017c\u017e\u0001\u0000\u0000"+
		"\u0000\u017d\u017b\u0001\u0000\u0000\u0000\u017e\u017f\u0006\'\'\u0000"+
		"\u017fR\u0001\u0000\u0000\u0000\u0180\u0182\u0007\u0004\u0000\u0000\u0181"+
		"\u0180\u0001\u0000\u0000\u0000\u0182\u0183\u0001\u0000\u0000\u0000\u0183"+
		"\u0181\u0001\u0000\u0000\u0000\u0183\u0184\u0001\u0000\u0000\u0000\u0184"+
		"\u0185\u0001\u0000\u0000\u0000\u0185\u0186\u0006((\u0000\u0186T\u0001"+
		"\u0000\u0000\u0000\u0187\u0189\u0007\u0004\u0000\u0000\u0188\u0187\u0001"+
		"\u0000\u0000\u0000\u0189\u018c\u0001\u0000\u0000\u0000\u018a\u0188\u0001"+
		"\u0000\u0000\u0000\u018a\u018b\u0001\u0000\u0000\u0000\u018b\u018d\u0001"+
		"\u0000\u0000\u0000\u018c\u018a\u0001\u0000\u0000\u0000\u018d\u018f\u0005"+
		".\u0000\u0000\u018e\u0190\u0007\u0004\u0000\u0000\u018f\u018e\u0001\u0000"+
		"\u0000\u0000\u0190\u0191\u0001\u0000\u0000\u0000\u0191\u018f\u0001\u0000"+
		"\u0000\u0000\u0191\u0192\u0001\u0000\u0000\u0000\u0192\u019c\u0001\u0000"+
		"\u0000\u0000\u0193\u0195\u0007\u0005\u0000\u0000\u0194\u0196\u0007\u0006"+
		"\u0000\u0000\u0195\u0194\u0001\u0000\u0000\u0000\u0195\u0196\u0001\u0000"+
		"\u0000\u0000\u0196\u0198\u0001\u0000\u0000\u0000\u0197\u0199\u0007\u0004"+
		"\u0000\u0000\u0198\u0197\u0001\u0000\u0000\u0000\u0199\u019a\u0001\u0000"+
		"\u0000\u0000\u019a\u0198\u0001\u0000\u0000\u0000\u019a\u019b\u0001\u0000"+
		"\u0000\u0000\u019b\u019d\u0001\u0000\u0000\u0000\u019c\u0193\u0001\u0000"+
		"\u0000\u0000\u019c\u019d\u0001\u0000\u0000\u0000\u019d\u01ae\u0001\u0000"+
		"\u0000\u0000\u019e\u01a0\u0007\u0004\u0000\u0000\u019f\u019e\u0001\u0000"+
		"\u0000\u0000\u01a0\u01a1\u0001\u0000\u0000\u0000\u01a1\u019f\u0001\u0000"+
		"\u0000\u0000\u01a1\u01a2\u0001\u0000\u0000\u0000\u01a2\u01a3\u0001\u0000"+
		"\u0000\u0000\u01a3\u01a5\u0007\u0005\u0000\u0000\u01a4\u01a6\u0007\u0006"+
		"\u0000\u0000\u01a5\u01a4\u0001\u0000\u0000\u0000\u01a5\u01a6\u0001\u0000"+
		"\u0000\u0000\u01a6\u01a8\u0001\u0000\u0000\u0000\u01a7\u01a9\u0007\u0004"+
		"\u0000\u0000\u01a8\u01a7\u0001\u0000\u0000\u0000\u01a9\u01aa\u0001\u0000"+
		"\u0000\u0000\u01aa\u01a8\u0001\u0000\u0000\u0000\u01aa\u01ab\u0001\u0000"+
		"\u0000\u0000\u01ab\u01ac\u0001\u0000\u0000\u0000\u01ac\u01ae\u0006))\u0000"+
		"\u01ad\u018a\u0001\u0000\u0000\u0000\u01ad\u019f\u0001\u0000\u0000\u0000"+
		"\u01aeV\u0001\u0000\u0000\u0000\u01af\u01b0\u0005#\u0000\u0000\u01b0X"+
		"\u0001\u0000\u0000\u0000\u01b1\u01b2\u0005\'\u0000\u0000\u01b2\u01b3\u0001"+
		"\u0000\u0000\u0000\u01b3\u01b4\u0006+*\u0000\u01b4Z\u0001\u0000\u0000"+
		"\u0000\u01b5\u01b6\u0005\'\u0000\u0000\u01b6\u01b7\u0006,+\u0000\u01b7"+
		"\u01b8\u0001\u0000\u0000\u0000\u01b8\u01b9\u0006,,\u0000\u01b9\\\u0001"+
		"\u0000\u0000\u0000\u01ba\u01bb\u0005\'\u0000\u0000\u01bb\u01bc\u0006-"+
		"-\u0000\u01bc\u01bd\u0001\u0000\u0000\u0000\u01bd\u01be\u0006-,\u0000"+
		"\u01be^\u0001\u0000\u0000\u0000\u01bf\u01c0\u0005\\\u0000\u0000\u01c0"+
		"\u01c1\u0007\u0007\u0000\u0000\u01c1\u01c2\u0001\u0000\u0000\u0000\u01c2"+
		"\u01c3\u0006..\u0000\u01c3`\u0001\u0000\u0000\u0000\u01c4\u01c6\u0005"+
		"\\\u0000\u0000\u01c5\u01c7\u0005\r\u0000\u0000\u01c6\u01c5\u0001\u0000"+
		"\u0000\u0000\u01c6\u01c7\u0001\u0000\u0000\u0000\u01c7\u01c8\u0001\u0000"+
		"\u0000\u0000\u01c8\u01c9\u0005\n\u0000\u0000\u01c9\u01ca\u0006//\u0000"+
		"\u01ca\u01cb\u0001\u0000\u0000\u0000\u01cb\u01cc\u0006/.\u0000\u01ccb"+
		"\u0001\u0000\u0000\u0000\u01cd\u01ce\u0005\n\u0000\u0000\u01ce\u01cf\u0006"+
		"00\u0000\u01cf\u01d0\u0001\u0000\u0000\u0000\u01d0\u01d1\u00060,\u0000"+
		"\u01d1d\u0001\u0000\u0000\u0000\u01d2\u01d3\t\u0000\u0000\u0000\u01d3"+
		"\u01d4\u0001\u0000\u0000\u0000\u01d4\u01d5\u00061.\u0000\u01d5f\u0001"+
		"\u0000\u0000\u0000\u01d6\u01d7\u0005\"\u0000\u0000\u01d7\u01d8\u0001\u0000"+
		"\u0000\u0000\u01d8\u01d9\u000621\u0000\u01d9h\u0001\u0000\u0000\u0000"+
		"\u01da\u01db\u0005\"\u0000\u0000\u01db\u01dc\u000632\u0000\u01dc\u01dd"+
		"\u0001\u0000\u0000\u0000\u01dd\u01de\u00063,\u0000\u01dej\u0001\u0000"+
		"\u0000\u0000\u01df\u01e0\u0005\\\u0000\u0000\u01e0\u01e1\u0007\u0007\u0000"+
		"\u0000\u01e1\u01e2\u0001\u0000\u0000\u0000\u01e2\u01e3\u00064.\u0000\u01e3"+
		"l\u0001\u0000\u0000\u0000\u01e4\u01e6\u0005\\\u0000\u0000\u01e5\u01e7"+
		"\u0005\r\u0000\u0000\u01e6\u01e5\u0001\u0000\u0000\u0000\u01e6\u01e7\u0001"+
		"\u0000\u0000\u0000\u01e7\u01e8\u0001\u0000\u0000\u0000\u01e8\u01e9\u0005"+
		"\n\u0000\u0000\u01e9\u01ea\u000653\u0000\u01ea\u01eb\u0001\u0000\u0000"+
		"\u0000\u01eb\u01ec\u00065.\u0000\u01ecn\u0001\u0000\u0000\u0000\u01ed"+
		"\u01ee\u0005\n\u0000\u0000\u01ee\u01ef\u000664\u0000\u01ef\u01f0\u0001"+
		"\u0000\u0000\u0000\u01f0\u01f1\u00066,\u0000\u01f1p\u0001\u0000\u0000"+
		"\u0000\u01f2\u01f4\b\b\u0000\u0000\u01f3\u01f2\u0001\u0000\u0000\u0000"+
		"\u01f4\u01f5\u0001\u0000\u0000\u0000\u01f5\u01f3\u0001\u0000\u0000\u0000"+
		"\u01f5\u01f6\u0001\u0000\u0000\u0000\u01f6\u01f7\u0001\u0000\u0000\u0000"+
		"\u01f7\u01f8\u00067.\u0000\u01f8r\u0001\u0000\u0000\u0000\u01f9\u01fa"+
		"\u0005/\u0000\u0000\u01fa\u01fb\u0005/\u0000\u0000\u01fb\u0205\u0001\u0000"+
		"\u0000\u0000\u01fc\u01fe\u0005\\\u0000\u0000\u01fd\u01ff\u0005\r\u0000"+
		"\u0000\u01fe\u01fd\u0001\u0000\u0000\u0000\u01fe\u01ff\u0001\u0000\u0000"+
		"\u0000\u01ff\u0200\u0001\u0000\u0000\u0000\u0200\u0201\u0005\n\u0000\u0000"+
		"\u0201\u0204\u000685\u0000\u0202\u0204\b\t\u0000\u0000\u0203\u01fc\u0001"+
		"\u0000\u0000\u0000\u0203\u0202\u0001\u0000\u0000\u0000\u0204\u0207\u0001"+
		"\u0000\u0000\u0000\u0205\u0203\u0001\u0000\u0000\u0000\u0205\u0206\u0001"+
		"\u0000\u0000\u0000\u0206\u0208\u0001\u0000\u0000\u0000\u0207\u0205\u0001"+
		"\u0000\u0000\u0000\u0208\u0209\u000686\u0000\u0209\u020a\u0001\u0000\u0000"+
		"\u0000\u020a\u020b\u000687\u0000\u020bt\u0001\u0000\u0000\u0000\u020c"+
		"\u020d\u0005/\u0000\u0000\u020d\u020e\u0005*\u0000\u0000\u020e\u0213\u0001"+
		"\u0000\u0000\u0000\u020f\u0212\t\u0000\u0000\u0000\u0210\u0212\u0007\t"+
		"\u0000\u0000\u0211\u020f\u0001\u0000\u0000\u0000\u0211\u0210\u0001\u0000"+
		"\u0000\u0000\u0212\u0215\u0001\u0000\u0000\u0000\u0213\u0214\u0001\u0000"+
		"\u0000\u0000\u0213\u0211\u0001\u0000\u0000\u0000\u0214\u0216\u0001\u0000"+
		"\u0000\u0000\u0215\u0213\u0001\u0000\u0000\u0000\u0216\u0217\u0005*\u0000"+
		"\u0000\u0217\u0218\u0005/\u0000\u0000\u0218\u0219\u0001\u0000\u0000\u0000"+
		"\u0219\u021a\u000698\u0000\u021a\u021b\u0001\u0000\u0000\u0000\u021b\u021c"+
		"\u000697\u0000\u021cv\u0001\u0000\u0000\u0000\u021d\u021f\u0007\n\u0000"+
		"\u0000\u021e\u021d\u0001\u0000\u0000\u0000\u021f\u0220\u0001\u0000\u0000"+
		"\u0000\u0220\u021e\u0001\u0000\u0000\u0000\u0220\u0221\u0001\u0000\u0000"+
		"\u0000\u0221\u0222\u0001\u0000\u0000\u0000\u0222\u0223\u0006:7\u0000\u0223"+
		"x\u0001\u0000\u0000\u0000\u0224\u0226\u0005\r\u0000\u0000\u0225\u0224"+
		"\u0001\u0000\u0000\u0000\u0225\u0226\u0001\u0000\u0000\u0000\u0226\u0227"+
		"\u0001\u0000\u0000\u0000\u0227\u0228\u0005\n\u0000\u0000\u0228\u0229\u0006"+
		";9\u0000\u0229\u022a\u0001\u0000\u0000\u0000\u022a\u022b\u0006;7\u0000"+
		"\u022bz\u0001\u0000\u0000\u0000\u022c\u022d\t\u0000\u0000\u0000\u022d"+
		"|\u0001\u0000\u0000\u0000\u001d\u0000\u0001\u0002\u012e\u0133\u014a\u0152"+
		"\u015a\u017b\u0183\u018a\u0191\u0195\u019a\u019c\u01a1\u01a5\u01aa\u01ad"+
		"\u01c6\u01e6\u01f5\u01fe\u0203\u0205\u0211\u0213\u0220\u0225:\u0001\u0000"+
		"\u0000\u0001\u0001\u0001\u0001\u0002\u0002\u0001\u0003\u0003\u0001\u0004"+
		"\u0004\u0001\u0005\u0005\u0001\u0006\u0006\u0001\u0007\u0007\u0001\b\b"+
		"\u0001\t\t\u0001\n\n\u0001\u000b\u000b\u0001\f\f\u0001\r\r\u0001\u000e"+
		"\u000e\u0001\u000f\u000f\u0001\u0010\u0010\u0001\u0011\u0011\u0001\u0012"+
		"\u0012\u0001\u0013\u0013\u0001\u0014\u0014\u0001\u0015\u0015\u0001\u0016"+
		"\u0016\u0001\u0017\u0017\u0001\u0018\u0018\u0001\u0019\u0019\u0001\u001a"+
		"\u001a\u0001\u001b\u001b\u0001\u001c\u001c\u0001\u001d\u001d\u0001\u001e"+
		"\u001e\u0001\u001f\u001f\u0001  \u0001!!\u0001\"\"\u0001##\u0001$$\u0001"+
		"%%\u0001&&\u0001\'\'\u0001((\u0001))\u0005\u0001\u0000\u0001,*\u0004\u0000"+
		"\u0000\u0001-+\u0003\u0000\u0000\u0001/,\u00010-\u0005\u0002\u0000\u0001"+
		"3.\u00015/\u000160\u000181\u000182\u0006\u0000\u0000\u000193\u0001;4";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}