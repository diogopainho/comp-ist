%{
// $Id: pwn_parser.y,v 1.20 2015/05/18 19:41:24 ist173245 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
  int                   i;	/* integer value */
  double                d;      /* number value */
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  pwn::block_node      *block;
  pwn::vardec_node     *var;
  pwn::lvalue_node     *lvalue;
  basic_type           *exprtype; /* basic types of expressions */
};

%token <i> tINTEGER
%token <d> tREAL
%token <s> tIDENTIFIER tSTRING
%token tREPEAT tIF tPRINT tPRINTLN tINTEGERSYMB tREALSYMB tSTRINGSYMB tREAD tNL tNEXT tSTOP tBL tTAB tLOCAL tIMPORT tRETURN tSPACE  tNOOB
%token tLOCAL tIMPORT
%token tGE tLE tEQ tNE
%nonassoc tIFX
%nonassoc tELSE


%right '='
%left '|' '&'
%nonassoc '~'
%left tEQ tNE
%left tGE tLE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%left tPRINT tPRINTLN
%nonassoc tUNARY '?'
%nonassoc '(' ')' '[' ']'



%type <node> decl stmt func declblock arg
%type <block> block inblock
%type <var> var 
%type <sequence> file declrs list args exprs identifiers declrsblock
%type <expression> expr lit litint funccall
%type <exprtype> type gen_type
%type <s> str
%type <lvalue> lval


%start file
%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file : declrs           {compiler->ast($1);}
    // | decl file        {compiler->ast(new cdk::sequence_node(LINE, $1, $2)); }
     ;

declrs : decl           { $$ = new cdk::sequence_node(LINE, $1); }
     | declrs decl      { $$ = new cdk::sequence_node(LINE, $2, $1); }
     ;

list : stmt             { $$ = new cdk::sequence_node(LINE, $1); }
     | list stmt        { $$ = new cdk::sequence_node(LINE, $2, $1); }
     ;

decl : var ';'                  { $$ = $1; }
     | var '=' expr ';'         { $$ = new pwn::vardec_node(LINE, $1, $3); } //Isto deve estar mal
     | func                     { $$ = $1; }
     
     ;
     
declrsblock : declblock                 { $$ = new cdk::sequence_node(LINE, $1); }
	    | declrsblock declblock     { $$ = new cdk::sequence_node(LINE, $2, $1); }
	    ;

declblock : var ';'                     { $$ = $1; }
	  | var '=' expr ';'            { $$ = new pwn::vardec_node(LINE, $1, $3); }
	  ;


func : gen_type tIDENTIFIER '(' args ')'                        { $$ = new pwn::funcdec_node(LINE, true, false, $1, $2, $4); }
     | gen_type tIDENTIFIER '(' args ')' block                  { $$ = new pwn::funcdef_node(LINE, true, false, $1, $2, $4, nullptr, $6); }
     | gen_type tIDENTIFIER '(' args ')' '=' lit block          { $$ = new pwn::funcdef_node(LINE, true, false, $1, $2, $4, $7, $8); }
     | gen_type tIDENTIFIER '(' args ')' '=' lit ';'            { $$ = new pwn::funcdef_node(LINE, true, false, $1, $2, $4, $7, nullptr); }
     | gen_type tIDENTIFIER '(' ')'                             { $$ = new pwn::funcdec_node(LINE, true, false, $1, $2, nullptr); }
     | gen_type tIDENTIFIER '(' ')' block                       { $$ = new pwn::funcdef_node(LINE, true, false, $1, $2, nullptr, nullptr, $5); }
     | gen_type tIDENTIFIER '(' ')' '=' lit block               { $$ = new pwn::funcdef_node(LINE, true, false, $1, $2, nullptr, $6, $7); }
     | gen_type tIDENTIFIER '(' ')' '=' lit ';'                 { $$ = new pwn::funcdef_node(LINE, true, false, $1, $2, nullptr, $6, nullptr); }
     | tLOCAL gen_type tIDENTIFIER '(' args ')'                 { $$ = new pwn::funcdec_node(LINE, false, true, $2, $3, $5); }
     | tIMPORT gen_type tIDENTIFIER '(' args ')'                { $$ = new pwn::funcdec_node(LINE, true, false, $2, $3, $5); }
     | tLOCAL gen_type tIDENTIFIER '(' args ')' block           { $$ = new pwn::funcdef_node(LINE, false, true, $2, $3, $5, nullptr, $7); }
     | tIMPORT gen_type tIDENTIFIER '(' args ')' block          { $$ = new pwn::funcdef_node(LINE, true, false, $2, $3, $5, nullptr, $7); }
     | tLOCAL gen_type tIDENTIFIER '(' args ')' '=' lit block   { $$ = new pwn::funcdef_node(LINE, false, true, $2, $3, $5, $8, $9); }
     | tIMPORT gen_type tIDENTIFIER '(' args ')' '=' lit block  { $$ = new pwn::funcdef_node(LINE, true, false, $2, $3, $5, $8, $9); }
     | tLOCAL gen_type tIDENTIFIER '(' args ')' '=' lit ';'     { $$ = new pwn::funcdef_node(LINE, false, true, $2, $3, $5, $8, nullptr); }
     | tIMPORT gen_type tIDENTIFIER '(' args ')' '=' lit ';'    { $$ = new pwn::funcdef_node(LINE, true, false, $2, $3, $5, $8, nullptr); }
     | tLOCAL gen_type tIDENTIFIER '(' ')'                      { $$ = new pwn::funcdec_node(LINE, false, true, $2, $3, nullptr); }
     | tIMPORT gen_type tIDENTIFIER '(' ')'                     { $$ = new pwn::funcdec_node(LINE, true, false, $2, $3, nullptr); }
     | tLOCAL gen_type tIDENTIFIER '(' ')' block                { $$ = new pwn::funcdef_node(LINE, false, true, $2, $3, nullptr, nullptr, $6); }
     | tIMPORT gen_type tIDENTIFIER '(' ')' block               { $$ = new pwn::funcdef_node(LINE, true, false, $2, $3, nullptr, nullptr, $6); }
     | tLOCAL gen_type tIDENTIFIER '(' ')' '=' lit block        { $$ = new pwn::funcdef_node(LINE, false, true, $2, $3, nullptr, $7, $8); }
     | tIMPORT gen_type tIDENTIFIER '(' ')' '=' lit block       { $$ = new pwn::funcdef_node(LINE, true, false, $2, $3, nullptr, $7, $8); }
     | tLOCAL gen_type tIDENTIFIER '(' ')' '=' lit ';'          { $$ = new pwn::funcdef_node(LINE, false, true, $2, $3, nullptr, $7, nullptr); }
     | tIMPORT gen_type tIDENTIFIER '(' ')' '=' lit ';'         { $$ = new pwn::funcdef_node(LINE, true, false, $2, $3, nullptr, $7, nullptr); }
     ;   
     

     
block : '{' inblock '}'         { $$ = $2; }
      | '{' '}'                 { $$ = nullptr; }
      ;
     
inblock : declrsblock           { $$ = new pwn::block_node(LINE, $1, nullptr); }
	| list                  { $$ = new pwn::block_node(LINE, nullptr, $1); }
	| declrsblock list      { $$ = new pwn::block_node(LINE, $1, $2); }
	;
     
stmt : ';'                              { $$ = new cdk::nil_node(LINE); }
     | expr ';'                         { $$ = new pwn::evaluation_node(LINE, $1); }
     | expr tPRINTLN                    { $$ = new pwn::print_node(LINE, $1, true); }
     | expr tPRINT                      { $$ = new pwn::print_node(LINE, $1, false); }
     | tNEXT tINTEGER ';'               { $$ = new pwn::next_node(LINE, new cdk::integer_node(LINE, $2)); }
     | tNEXT ';'                        { $$ = new pwn::next_node(LINE, new cdk::integer_node(LINE, 1)); }
     | tSTOP tINTEGER ';'               { $$ = new pwn::stop_node(LINE, new cdk::integer_node(LINE, $2)); }
     | tSTOP ';'                        { $$ = new pwn::stop_node(LINE, new cdk::integer_node(LINE, 1)); }
     | tREAD lval ';'                   { $$ = new pwn::read_node(LINE, $2); }
     | tREPEAT '(' exprs ';' exprs ';' exprs ')' stmt         { $$ = new pwn::repeat_node(LINE, $3, $5, $7, $9); }
     | tIF '(' expr ')' stmt %prec tIFX                           { $$ = new cdk::if_node(LINE, $3, $5); }
     | tIF '(' expr ')' stmt tELSE stmt                           { $$ = new cdk::if_else_node(LINE, $3, $5, $7); }
     | tRETURN                                                    { $$ = new pwn::return_node(LINE); }
     | block                                                      { $$ = $1; }
     
     ;

lit : litint            { $$ = $1; }
    | tREAL             { $$ = new cdk::double_node(LINE, $1); }
    | str               { $$ = new cdk::string_node(LINE, $1); }
    ;
    
litint : tINTEGER              { $$ = new cdk::integer_node(LINE, $1); }
       ;
     
expr : lit                     { $$ = $1; }
     | lval '=' expr           { $$ = new pwn::assignment_node(LINE, $1, $3); }
     | lval '?'                { $$ = new pwn::adressmemory_node(LINE, $1); }
     | '-' expr %prec tUNARY   { $$ = new cdk::neg_node(LINE, $2); }
     | '+' tINTEGER 	       { $$ = new cdk::integer_node(LINE, $2); }
     | expr '+' expr           { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr           { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr           { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr           { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr           { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr           { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr           { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tGE expr           { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr           { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr           { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr           { $$ = new cdk::eq_node(LINE, $1, $3); }
     | '~' expr                { $$ = new pwn::not_node(LINE, $2); }
     | expr '&' expr           { $$ = new pwn::and_node(LINE, $1, $3); }
     | expr '|' expr           { $$ = new pwn::or_node(LINE, $1, $3); }
     | '(' expr ')'            { $$ = $2; }
     | lval                    { $$ = new pwn::rvalue_node(LINE, $1); }  //FIXME
     | funccall                { $$ = $1; }
     | '[' litint ']'          { $$ = new pwn::reservememory_node(LINE, $2); }
     | '*' lval           { $$ = new pwn::adressmemory_node(LINE, $2); }
     | '<*>' lval           { $$ = new pwn::adressmemory_node(LINE, $2); }
     ;

exprs : expr                   { $$ = new cdk::sequence_node(LINE, $1); }
      | exprs ',' expr         { $$ = new cdk::sequence_node(LINE, $3, $1); }
      ;
      
str : tSTRING                 		{ $$ = $1; }
    | str tSTRING	{ *$1 += *$2; $$ = $1; delete($2); }
    ;
    
args : arg              { $$ = new cdk::sequence_node(LINE, $1); }
     | args ',' arg     { $$ = new cdk::sequence_node(LINE, $3, $1); }
     ;
     
arg : type tIDENTIFIER  { $$ = new pwn::vardec_node(LINE, false, false, false, $1, $2, nullptr); }
 // E preciso adiconar aqui alguma por causa da constante?
    ;
    
lval : tIDENTIFIER                      { $$ = new pwn::lvalue_node(LINE, $1); }
     | tIDENTIFIER '[' expr ']'         { $$ = new pwn::index_node(LINE, $1, $3); }
     ;
     
funccall : tIDENTIFIER '(' identifiers ')'      { $$ = new pwn::funccall_node(LINE, $1, $3); }
	 | tIDENTIFIER '(' ')'                  { $$ = new pwn::funccall_node(LINE, $1, nullptr); }
	 ;

identifiers : expr                      { $$ = new cdk::sequence_node(LINE, $1); }
	    | identifiers ',' expr      { $$ = new cdk::sequence_node(LINE, $3, $1); }
	    ;
	    
var : gen_type tIDENTIFIER                      { $$ = new pwn::vardec_node(LINE, false, false, false, $1, $2, nullptr); }
    | '<' gen_type '>' tIDENTIFIER              { $$ = new pwn::vardec_node(LINE, false, false, true, $2, $4, nullptr); }
    | tLOCAL gen_type tIDENTIFIER               { $$ = new pwn::vardec_node(LINE, false, true, false, $2, $3, nullptr); }
    | tLOCAL '<' gen_type '>' tIDENTIFIER       { $$ = new pwn::vardec_node(LINE, false, true, true, $3, $5, nullptr); }
    | tIMPORT gen_type tIDENTIFIER              { $$ = new pwn::vardec_node(LINE, true, false, false, $2, $3, nullptr); } 
    | tIMPORT '<' gen_type '>' tIDENTIFIER      { $$ = new pwn::vardec_node(LINE, true, false, true, $3, $5, nullptr); }
    ;
    
gen_type : type         { $$ = $1; }
	 ;
	 
type : tINTEGERSYMB         { $$ = new basic_type(4, basic_type::TYPE_INT); }
     | tREALSYMB            { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
     | tSTRINGSYMB          { $$ = new basic_type(4, basic_type::TYPE_STRING); }
     | tPRINT               { $$ = new basic_type(0, basic_type::TYPE_VOID); }
     ;


%%
