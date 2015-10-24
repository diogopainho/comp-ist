%option c++ yyclass="pwn_scanner" outfile="pwn_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
/* $Id: pwn_scanner.l,v 1.15 2015/05/16 18:32:12 ist173245 Exp $ */
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "pwn_scanner.h"
#include "pwn_parser.tab.h"

// don't change this
#define yyerror LexerError

%}

INTEGER 0|[1-9][0-9]* 
HEXADECIMAL [0-9a-fA-F]
E [eE]

%x X_STRING X_COM 
%%

 /* { set_debug(1); } */

"/*"                yy_push_state(X_COM);     /* comentario operacional*/
<X_COM>"/*"         yy_push_state(X_COM);
<X_COM>"*/"         yy_pop_state();
<X_COM>.|\n         ; /* nao deve acontecer */

"//".*$             ;/* comentario explicativo */

\"                                      yy_push_state(X_STRING); yylval.s = new std::string(""); 
<X_STRING>\\\\                          *yylval.s += '\\';
<X_STRING>\\'                           *yylval.s += '\'';
<X_STRING>\\n                           *yylval.s += '\n'; 
<X_STRING>\\r                           *yylval.s += '\r'; 
<X_STRING>\\t                           *yylval.s += '\t';
<X_STRING>\\\"                          *yylval.s += '\"';
<X_STRING>\\0                           *yylval.s += '\0';
<X_STRING>\\{HEXADECIMAL}{HEXADECIMAL}? *yylval.s += strtol(yytext+1, NULL, 16); //Deve ser [0-7][0-9] para ler "ASCI"
<X_STRING>\"                            yy_pop_state(); return tSTRING;
<X_STRING>.                             *yylval.s += yytext;
<X_STRING>\n                            yyerror("newline in string");

"#"                     return tINTEGERSYMB;
"$"                     return tSTRINGSYMB;
"@"                     return tREAD;

"!!"                    return tPRINTLN;
"!"                     return tPRINT;

  
">="                    return tGE; 
"<="                    return tLE; 
"=="                    return tEQ; 
"<>"                    return tNE;


"local"                 return tLOCAL;
"import"                return tIMPORT; 
"if"                    return tIF; 
"else"                  return tELSE; 
"repeat"                return tREPEAT;
"next"                  return tNEXT;
"stop"                  return tSTOP;
"noob"                  return tNOOB;
"return"                return tRETURN; 

[A-Za-z_][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tIDENTIFIER;
             

0|"0x"{HEXADECIMAL}+                    { yylval.i = strtol(yytext, nullptr, 16); return tINTEGER; }
{INTEGER}                               { yylval.i = strtol(yytext, nullptr, 10); return tINTEGER; }

[0-9]*"."[0-9]+{E}[+-]?[0-9]+           { yylval.d = strtod(yytext, nullptr); return tREAL; } 
[0-9]+"."[0-9]*{E}[+-]?[0-9]+           { yylval.d = strtod(yytext, nullptr); return tREAL; } 
[0-9]*"."[0-9]+                         { yylval.d = strtod(yytext, nullptr); return tREAL; }
[0-9]+"."[0-9]*                         { yylval.d = strtod(yytext, nullptr); return tREAL; }
[0-9]+{E}[+-]?[0-9]+                    { yylval.d = strtod(yytext, nullptr); return tREAL; }


[-#%$*()[\]+?/<>~&|=,;!{}@]       return *yytext;

[ \t\n]+               ; /* ignore whitespace */

.                      yyerror("Unknown character");
%%
// Very, very dirty hack: flex is a mess generating C++ scanners.
int pwn_scanner::yywrap() { return 1; }