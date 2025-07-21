// Generated from c:/Users/User/OneDrive - BUET/BOOKS 3-1/CSE 309/Offline-Online/Offline-4/code/C2105017Parser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link C2105017Parser}.
 */
public interface C2105017ParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#start}.
	 * @param ctx the parse tree
	 */
	void enterStart(C2105017Parser.StartContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#start}.
	 * @param ctx the parse tree
	 */
	void exitStart(C2105017Parser.StartContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(C2105017Parser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(C2105017Parser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#unit}.
	 * @param ctx the parse tree
	 */
	void enterUnit(C2105017Parser.UnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#unit}.
	 * @param ctx the parse tree
	 */
	void exitUnit(C2105017Parser.UnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void enterFunc_declaration(C2105017Parser.Func_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#func_declaration}.
	 * @param ctx the parse tree
	 */
	void exitFunc_declaration(C2105017Parser.Func_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void enterFunc_definition(C2105017Parser.Func_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#func_definition}.
	 * @param ctx the parse tree
	 */
	void exitFunc_definition(C2105017Parser.Func_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameter_list(C2105017Parser.Parameter_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameter_list(C2105017Parser.Parameter_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void enterCompound_statement(C2105017Parser.Compound_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#compound_statement}.
	 * @param ctx the parse tree
	 */
	void exitCompound_statement(C2105017Parser.Compound_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void enterVar_declaration(C2105017Parser.Var_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#var_declaration}.
	 * @param ctx the parse tree
	 */
	void exitVar_declaration(C2105017Parser.Var_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void enterType_specifier(C2105017Parser.Type_specifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#type_specifier}.
	 * @param ctx the parse tree
	 */
	void exitType_specifier(C2105017Parser.Type_specifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list(C2105017Parser.Declaration_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#declaration_list}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list(C2105017Parser.Declaration_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#declaration_list_tail}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_list_tail(C2105017Parser.Declaration_list_tailContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#declaration_list_tail}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_list_tail(C2105017Parser.Declaration_list_tailContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#declaration_item}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration_item(C2105017Parser.Declaration_itemContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#declaration_item}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration_item(C2105017Parser.Declaration_itemContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#statements}.
	 * @param ctx the parse tree
	 */
	void enterStatements(C2105017Parser.StatementsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#statements}.
	 * @param ctx the parse tree
	 */
	void exitStatements(C2105017Parser.StatementsContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(C2105017Parser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(C2105017Parser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void enterExpression_statement(C2105017Parser.Expression_statementContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#expression_statement}.
	 * @param ctx the parse tree
	 */
	void exitExpression_statement(C2105017Parser.Expression_statementContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(C2105017Parser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(C2105017Parser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(C2105017Parser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(C2105017Parser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void enterLogic_expression(C2105017Parser.Logic_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#logic_expression}.
	 * @param ctx the parse tree
	 */
	void exitLogic_expression(C2105017Parser.Logic_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void enterRel_expression(C2105017Parser.Rel_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#rel_expression}.
	 * @param ctx the parse tree
	 */
	void exitRel_expression(C2105017Parser.Rel_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void enterSimple_expression(C2105017Parser.Simple_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#simple_expression}.
	 * @param ctx the parse tree
	 */
	void exitSimple_expression(C2105017Parser.Simple_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#term}.
	 * @param ctx the parse tree
	 */
	void enterTerm(C2105017Parser.TermContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#term}.
	 * @param ctx the parse tree
	 */
	void exitTerm(C2105017Parser.TermContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnary_expression(C2105017Parser.Unary_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnary_expression(C2105017Parser.Unary_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#factor}.
	 * @param ctx the parse tree
	 */
	void enterFactor(C2105017Parser.FactorContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#factor}.
	 * @param ctx the parse tree
	 */
	void exitFactor(C2105017Parser.FactorContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void enterArgument_list(C2105017Parser.Argument_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#argument_list}.
	 * @param ctx the parse tree
	 */
	void exitArgument_list(C2105017Parser.Argument_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link C2105017Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArguments(C2105017Parser.ArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link C2105017Parser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArguments(C2105017Parser.ArgumentsContext ctx);
}