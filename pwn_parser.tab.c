/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "pwn_parser.y"
/* $Id: pwn_parser.y,v 1.20 2015/05/18 19:41:24 ist173245 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "pwn_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 62 "pwn_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 54 "pwn_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tREAL 258
#define tIDENTIFIER 259
#define tSTRING 260
#define tREPEAT 261
#define tIF 262
#define tPRINT 263
#define tPRINTLN 264
#define tINTEGERSYMB 265
#define tREALSYMB 266
#define tSTRINGSYMB 267
#define tREAD 268
#define tNL 269
#define tNEXT 270
#define tSTOP 271
#define tBL 272
#define tTAB 273
#define tLOCAL 274
#define tIMPORT 275
#define tRETURN 276
#define tSPACE 277
#define tNOOB 278
#define tGE 279
#define tLE 280
#define tEQ 281
#define tNE 282
#define tIFX 283
#define tELSE 284
#define tUNARY 285
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    9,    9,   10,   10,    1,    1,    1,   14,   14,
    4,    4,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    6,    6,    7,    7,
    7,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,   16,   16,   16,   17,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   12,   12,   21,   21,   11,   11,
    5,   22,   22,   18,   18,   13,   13,    8,    8,    8,
    8,    8,    8,   20,   19,   19,   19,   19,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    2,    2,    4,    1,    1,    2,
    2,    4,    5,    6,    8,    8,    4,    5,    7,    7,
    6,    6,    7,    7,    9,    9,    9,    9,    5,    5,
    6,    6,    8,    8,    8,    8,    3,    2,    1,    1,
    2,    1,    2,    2,    2,    3,    2,    3,    2,    3,
    9,    5,    7,    1,    1,    1,    1,    1,    1,    1,
    3,    2,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    3,    3,    3,    1,
    1,    3,    2,    2,    1,    3,    1,    2,    1,    3,
    2,    1,    4,    4,    3,    1,    3,    2,    4,    3,
    5,    3,    5,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
  108,  105,  106,  107,    0,    0,    0,    0,    2,    8,
    0,    0,  104,    0,    0,    0,    0,    0,    0,    0,
    6,    3,    0,    0,    0,    0,    0,    0,   59,   57,
    0,   87,    0,    0,    0,    0,    0,    0,    0,    0,
   60,   56,   81,    0,    0,    0,    0,    0,    0,    0,
   99,    0,    0,    0,   64,   63,    0,   83,    0,    0,
   84,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    7,   88,    0,   62,    0,   89,
    0,    0,  101,    0,    0,  103,    0,    0,   95,    0,
    0,    0,   79,   82,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   67,   68,   69,    0,    0,    0,
   18,    0,    0,   91,    0,   31,    0,    0,   32,    0,
   94,    0,   93,    0,    0,    0,    0,    0,    0,    0,
    0,   54,   42,   38,    4,    9,   55,    0,    0,    0,
    0,    0,    0,    0,   14,   90,    0,    0,   23,    0,
    0,   24,    0,   20,   19,    0,    0,    0,    0,   47,
    0,   49,    0,    0,   37,    0,   11,    5,   10,    0,
   45,   44,   43,   98,    0,   35,   33,    0,   36,   34,
    0,    0,    0,    0,   50,   46,   48,  100,  102,    0,
   16,   15,   27,   25,   28,   26,    0,    0,    0,   12,
    0,    0,    0,    0,    0,    0,   53,    0,   51,
};
static const YYINT yydgoto[] = {                          8,
    9,  135,   10,  136,   80,  137,  138,   11,   12,  140,
   81,  182,   90,  141,  142,   41,   42,   43,   13,   14,
   44,   45,
};
static const YYINT yysindex[] = {                       515,
    0,    0,    0,    0,  146,  180,  -95,    0,    0,    0,
  133,  515,    0, -213,  -95, -208,  -95, -194,   21,  124,
    0,    0,   28,   38,   76,   66,   77, -181,    0,    0,
   -9,    0,  124, -134,  124, -130,  124, -120, -130,  478,
    0,    0,    0, -117,  134,   -7, -106,   94, -103,  140,
    0,  105,  124,  -27,    0,    0,   83,    0,  489,   85,
    0,  124,  124,  124,  124,  124,  124,  124,  124,  124,
  124,  124,  124,  124,    0,    0,  124,    0,  -25,    0,
   -1,  -55,    0,   -4,  121,    0,    3,  135,    0,  139,
  649,  505,    0,    0,  112,  112,  -34,  -34,  -27,  -27,
  112,  112,   44,   44,    0,    0,    0,  649, -118,  -38,
    0,    8,  -95,    0, -118,    0,    9, -118,    0,   11,
    0,  124,    0,  -30,  160,  178, -130,  -59,  -47,  146,
  180,    0,    0,    0,    0,    0,    0,   57,  142,  118,
   61,  450,  -33, -118,    0,    0,  -29, -118,    0,  -15,
 -118,    0,  649,    0,    0,  124,  124,  175,  176,    0,
  183,    0,  -20,  -16,    0,  124,    0,    0,    0,  118,
    0,    0,    0,    0,  -12,    0,    0,  -11,    0,    0,
  -10,   -5,  649,  516,    0,    0,    0,    0,    0,  544,
    0,    0,    0,    0,    0,    0,  124,  124,  118,    0,
   16,  649,  -19,  124,  118,  145,    0,  118,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  257,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  152,    0,  153,    0,  188,    0,    0,    0,
  355,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  382,  393,    0,    0,    0,    0,    0,
    0,    0,    0,   51,    0,    0,  421,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    0,    0,    6,    0,    0,   19,    0,    0,    0,
  147,    0,    0,    0,  555,  800,   14,   92,  584,  707,
  808,  812,  679,  768,    0,    0,    0,  158,    0,    0,
    0,   24,    0,    0,    0,    0,   37,    0,    0,   42,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  137,
  154,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  149,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  163,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   18,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   55,   82,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  258,  -90,    0,  151,  161,  797,    0,  -65,    0,  156,
  213, -141,    0,    0,  929,  -77,  245,    0,  -23,  747,
    0,  -22,
};
#define YYTABLESIZE 1133
static const YYINT yytable[] = {                        160,
   17,   37,   74,   36,   34,   29,   35,   72,   70,   74,
   71,  162,   73,   58,   72,   70,   61,   71,   30,   73,
  133,    7,   82,   13,   82,   69,   82,   68,  154,  176,
   52,  124,   69,   79,   68,  109,   21,  147,  198,  112,
  150,   22,  113,  179,  139,   23,  191,  193,  195,  168,
   25,   75,   38,  197,   75,  201,  115,   75,   85,  198,
   17,   85,  206,  118,   27,   29,  175,   46,  144,  148,
  178,  151,   75,  181,  204,  139,   85,   51,   30,  168,
   74,   53,   28,   13,  110,   72,  134,   33,   76,   82,
   73,   76,  110,  110,   76,   86,   21,  110,   86,   47,
   37,   22,   36,   34,  158,   35,   75,  110,  203,   76,
  110,  110,  110,   86,  207,   48,   50,  209,  110,  133,
    7,   52,   55,   52,   52,  110,   52,   49,   57,   74,
  110,  110,   74,  110,   84,   74,   29,   75,   29,   30,
   52,   32,   76,   76,   37,   89,   36,   34,   74,   35,
   74,   38,   83,   72,   70,   86,   71,   37,   73,   36,
   34,  117,   35,   37,  113,   36,   34,    1,   35,    2,
    3,    4,   52,   53,   76,  120,  133,   94,  113,  121,
   87,  165,  122,  110,   74,  208,   33,   96,  198,   97,
   96,   21,   97,   20,   77,   38,   78,  159,   61,  156,
  167,   61,  166,  114,   52,   15,   52,   52,   38,  161,
   98,  100,   98,  100,   38,   74,   61,  157,   29,   30,
   31,   32,  125,  126,    1,  174,    2,    3,    4,  127,
   33,  128,  129,  185,  186,  130,  131,  132,  188,   17,
  110,  187,  189,   33,   62,   63,  102,   39,  102,   33,
   61,   62,   63,   64,   65,    1,    1,    2,    3,    4,
   85,   40,   88,   17,  205,   17,   17,   17,   29,   22,
   29,   29,   29,  146,   17,   17,   75,   75,   39,   29,
   29,   30,   60,   30,   30,   30,   13,   41,   13,   13,
   13,  169,   30,   30,   75,   75,  170,   13,   13,   21,
    0,   21,   21,   21,   22,    0,   22,   22,   22,    0,
   21,   21,    0,   76,   76,   22,   22,   29,   30,   31,
   32,  125,  126,    1,    0,    2,    3,    4,  127,    0,
  128,  129,    0,    0,  130,  131,  132,    0,   52,   52,
   52,   52,   52,   52,    0,    0,   39,    0,    0,   52,
    0,   52,   52,    0,   74,   74,    1,   52,    2,    3,
    4,   29,   30,   31,   32,    0,    0,   52,    0,    0,
    0,    0,   74,   74,   29,   30,   31,   32,  125,  126,
   29,   30,   31,   32,    0,  127,    0,  128,  129,    0,
   39,   92,   92,  132,    0,   92,   92,   92,   92,   92,
    0,   92,    1,   39,    2,    3,    4,    0,    1,   39,
    2,    3,    4,   92,   92,   92,   92,   92,   58,   58,
   61,   61,   58,   58,   58,   58,   58,    0,   58,   80,
   80,    0,    0,   80,   80,   80,   80,   80,    0,   80,
   58,   58,    1,   58,    2,    3,    4,   92,    0,    0,
    0,   80,   80,    0,   80,    0,    0,   92,   92,    0,
    0,   92,   92,   92,   92,   92,    0,   92,    0,    0,
    0,    0,    0,    0,   58,    0,    0,    0,   92,   92,
   92,    0,   92,    0,    0,   80,   74,   67,    0,    0,
    0,   72,   70,    0,   71,    0,   73,    0,    0,    0,
    0,    0,    0,    0,   58,   58,    0,    0,  173,   69,
    0,   68,    0,   92,   74,   67,   80,    0,    0,   72,
   70,    0,   71,    0,   73,   74,   67,    0,    0,   93,
   72,   70,    0,   71,    0,   73,   75,   69,    0,   68,
    0,   74,   67,    0,   92,    0,   72,   70,   69,   71,
   68,   73,   74,   67,    0,    0,  199,   72,   70,    0,
   71,    0,   73,    0,   69,    0,   68,    0,    0,    0,
    0,    0,    0,   66,    7,   69,    0,   68,    0,    0,
   74,   67,    0,    0,    0,   72,   70,    0,   71,    0,
   73,    0,   72,    0,    0,   72,    0,  123,   72,    0,
    0,   66,  200,   69,    0,   68,    0,    0,    0,    0,
    0,    0,   66,   72,   72,    0,   72,   92,   92,    0,
    0,   78,    0,    0,   78,    0,    0,   78,   66,    0,
    0,    0,    0,   92,   92,   92,   92,    0,    0,   66,
    0,    0,   78,    0,   58,   58,    0,   72,    0,    0,
    0,    0,    0,    0,    0,   80,   80,    0,    0,    0,
   58,   58,   58,   58,    0,    0,    0,   66,    0,    0,
    0,   80,   80,   80,   80,    0,   78,    0,   72,    0,
    0,    0,    0,   92,   92,   74,   67,    0,    0,    0,
   72,   70,    0,   71,    0,   73,    0,    0,    0,   92,
   92,   92,   92,    0,    0,    0,    0,   78,   69,    0,
   68,    0,  171,  172,    0,    0,   65,    0,    0,   65,
    0,   65,   65,   65,    0,    0,    0,    0,   62,   63,
   64,   65,    0,    0,    0,    0,    0,   65,   65,    0,
   65,    0,    0,    0,   77,    0,    0,   77,    0,    0,
   77,   16,   18,   19,    0,    0,   62,   63,   64,   65,
    0,   24,    0,   26,    0,   77,    0,   62,   63,   64,
   65,   65,   66,    0,    0,    0,    0,    1,    0,    2,
    3,    4,    0,   62,   63,   64,   65,    0,    5,    6,
    0,    0,    0,    0,   62,   63,   64,   65,    0,   77,
    0,    0,   65,    0,    0,   66,    0,    0,   66,    0,
   66,   66,   66,    0,    0,    0,    0,   72,   72,    0,
    0,    0,   62,   63,   64,   65,   66,   66,    0,   66,
   77,    0,    0,   72,   72,   72,   72,   73,    0,    0,
   73,    0,    0,   73,    0,   71,   78,   78,   71,   70,
    0,   71,   70,    0,    0,   70,  143,    0,   73,   73,
   66,   73,    0,    0,    0,    0,   71,   71,    0,   71,
   70,   70,    0,   70,    0,  111,  163,  164,    0,    0,
  116,    0,    0,  119,    0,    0,    0,  143,    0,    0,
    0,   66,   73,    0,    0,    0,    0,    0,    0,    0,
   71,    0,    0,    0,   70,    0,    0,    0,  145,    0,
    0,    0,    0,  149,    0,    0,  152,    0,    0,    0,
  155,    0,    0,   73,    0,    0,    0,   62,   63,   64,
   65,   71,    0,    0,    0,   70,    0,    0,    0,    0,
    0,   65,   65,  177,    0,    0,  180,    0,   40,    0,
    0,    0,    0,    0,    0,    0,    0,   65,   65,   65,
   65,   54,    0,   56,    0,   59,    0,    0,    0,   77,
   77,  192,    0,    0,  194,    0,    0,  196,    0,    0,
   91,   92,    0,    0,    0,    0,    0,    0,    0,    0,
   95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
  105,  106,  107,    0,    0,  108,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   66,   66,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   66,   66,   66,   66,
  153,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   73,   73,    0,    0,    0,    0,    0,    0,
   71,   71,    0,    0,   70,   70,    0,    0,   73,   73,
   73,   73,    0,    0,  183,  184,   71,   71,   71,   71,
   70,   70,   70,   70,  190,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  183,  202,    0,    0,    0,
    0,    0,  183,
};
static const YYINT yycheck[] = {                         59,
    0,   40,   37,   42,   43,    0,   45,   42,   43,   37,
   45,   59,   47,   36,   42,   43,   39,   45,    0,   47,
   59,   60,   46,    0,   48,   60,   50,   62,   59,   59,
   40,  109,   60,   41,   62,   61,    0,  115,   44,   41,
  118,    0,   44,   59,  110,  259,   59,   59,   59,  140,
  259,   38,   91,   59,   41,  197,   61,   44,   41,   44,
   60,   44,  204,   61,  259,   60,  144,   40,   61,   61,
  148,   61,   59,  151,   59,  141,   59,  259,   60,  170,
   37,   91,   62,   60,  123,   42,  125,  126,   38,  113,
   47,   41,  123,  123,   44,   41,   60,  123,   44,   62,
   40,   60,   42,   43,  127,   45,   93,  123,  199,   59,
  123,  123,  123,   59,  205,   40,   40,  208,  123,   59,
   60,   40,  257,   42,   43,  123,   45,   62,  259,   38,
  123,  123,   41,  123,   41,   44,  257,  124,  257,  258,
   59,  260,  260,   93,   40,   41,   42,   43,   37,   45,
   59,   91,  259,   42,   43,  259,   45,   40,   47,   42,
   43,   41,   45,   40,   44,   42,   43,  263,   45,  265,
  266,  267,   91,   91,  124,   41,   59,   93,   44,   41,
   41,  125,   44,  123,   93,   41,  126,   41,   44,   41,
   44,   59,   44,   61,   61,   91,   63,  257,   41,   40,
   59,   44,   61,  259,  123,   60,  125,  126,   91,  257,
   59,   59,   61,   61,   91,  124,   59,   40,  257,  258,
  259,  260,  261,  262,  263,  259,  265,  266,  267,  268,
  126,  270,  271,   59,   59,  274,  275,  276,  259,   60,
  123,   59,  259,  126,  279,  280,   59,  286,   61,  126,
   93,  279,  280,  281,  282,  263,    0,  265,  266,  267,
   48,  125,   50,  263,  284,  265,  266,  267,  263,   12,
  265,  266,  267,  113,  274,  275,  263,  264,  125,  274,
  275,  263,   38,  265,  266,  267,  263,  125,  265,  266,
  267,  141,  274,  275,  281,  282,  141,  274,  275,  263,
   -1,  265,  266,  267,  263,   -1,  265,  266,  267,   -1,
  274,  275,   -1,  263,  264,  274,  275,  257,  258,  259,
  260,  261,  262,  263,   -1,  265,  266,  267,  268,   -1,
  270,  271,   -1,   -1,  274,  275,  276,   -1,  257,  258,
  259,  260,  261,  262,   -1,   -1,  286,   -1,   -1,  268,
   -1,  270,  271,   -1,  263,  264,  263,  276,  265,  266,
  267,  257,  258,  259,  260,   -1,   -1,  286,   -1,   -1,
   -1,   -1,  281,  282,  257,  258,  259,  260,  261,  262,
  257,  258,  259,  260,   -1,  268,   -1,  270,  271,   -1,
  286,   37,   38,  276,   -1,   41,   42,   43,   44,   45,
   -1,   47,  263,  286,  265,  266,  267,   -1,  263,  286,
  265,  266,  267,   59,   60,   61,   62,   63,   37,   38,
  263,  264,   41,   42,   43,   44,   45,   -1,   47,   37,
   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,
   59,   60,  263,   62,  265,  266,  267,   93,   -1,   -1,
   -1,   59,   60,   -1,   62,   -1,   -1,   37,   38,   -1,
   -1,   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,  124,   59,
   60,   -1,   62,   -1,   -1,   93,   37,   38,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,  124,   -1,   -1,   59,   60,
   -1,   62,   -1,   93,   37,   38,  124,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   37,   38,   -1,   -1,   41,
   42,   43,   -1,   45,   -1,   47,   59,   60,   -1,   62,
   -1,   37,   38,   -1,  124,   -1,   42,   43,   60,   45,
   62,   47,   37,   38,   -1,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   60,   -1,   62,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   60,   60,   -1,   62,   -1,   -1,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   38,   -1,   -1,   41,   -1,   93,   44,   -1,
   -1,  124,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   59,   60,   -1,   62,  263,  264,   -1,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,  124,   -1,
   -1,   -1,   -1,  279,  280,  281,  282,   -1,   -1,  124,
   -1,   -1,   59,   -1,  263,  264,   -1,   93,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,
  279,  280,  281,  282,   -1,   -1,   -1,  124,   -1,   -1,
   -1,  279,  280,  281,  282,   -1,   93,   -1,  124,   -1,
   -1,   -1,   -1,  263,  264,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  279,
  280,  281,  282,   -1,   -1,   -1,   -1,  124,   60,   -1,
   62,   -1,  263,  264,   -1,   -1,   38,   -1,   -1,   41,
   -1,   43,   44,   45,   -1,   -1,   -1,   -1,  279,  280,
  281,  282,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,
   44,    5,    6,    7,   -1,   -1,  279,  280,  281,  282,
   -1,   15,   -1,   17,   -1,   59,   -1,  279,  280,  281,
  282,   93,  124,   -1,   -1,   -1,   -1,  263,   -1,  265,
  266,  267,   -1,  279,  280,  281,  282,   -1,  274,  275,
   -1,   -1,   -1,   -1,  279,  280,  281,  282,   -1,   93,
   -1,   -1,  124,   -1,   -1,   38,   -1,   -1,   41,   -1,
   43,   44,   45,   -1,   -1,   -1,   -1,  263,  264,   -1,
   -1,   -1,  279,  280,  281,  282,   59,   60,   -1,   62,
  124,   -1,   -1,  279,  280,  281,  282,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   38,  263,  264,   41,   38,
   -1,   44,   41,   -1,   -1,   44,  110,   -1,   59,   60,
   93,   62,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,
   59,   60,   -1,   62,   -1,   79,  130,  131,   -1,   -1,
   84,   -1,   -1,   87,   -1,   -1,   -1,  141,   -1,   -1,
   -1,  124,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   93,   -1,   -1,   -1,   93,   -1,   -1,   -1,  112,   -1,
   -1,   -1,   -1,  117,   -1,   -1,  120,   -1,   -1,   -1,
  124,   -1,   -1,  124,   -1,   -1,   -1,  279,  280,  281,
  282,  124,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,
   -1,  263,  264,  147,   -1,   -1,  150,   -1,   20,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  279,  280,  281,
  282,   33,   -1,   35,   -1,   37,   -1,   -1,   -1,  263,
  264,  175,   -1,   -1,  178,   -1,   -1,  181,   -1,   -1,
   52,   53,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   73,   74,   -1,   -1,   77,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  279,  280,  281,  282,
  122,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,
  263,  264,   -1,   -1,  263,  264,   -1,   -1,  279,  280,
  281,  282,   -1,   -1,  156,  157,  279,  280,  281,  282,
  279,  280,  281,  282,  166,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  197,  198,   -1,   -1,   -1,
   -1,   -1,  204,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 286
#define YYUNDFTOKEN 311
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,
0,0,0,"';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tINTEGER","tREAL","tIDENTIFIER",
"tSTRING","tREPEAT","tIF","tPRINT","tPRINTLN","tINTEGERSYMB","tREALSYMB",
"tSTRINGSYMB","tREAD","tNL","tNEXT","tSTOP","tBL","tTAB","tLOCAL","tIMPORT",
"tRETURN","tSPACE","tNOOB","tGE","tLE","tEQ","tNE","tIFX","tELSE","tUNARY",
"\"<*>\"",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : declrs",
"declrs : decl",
"declrs : declrs decl",
"list : stmt",
"list : list stmt",
"decl : var ';'",
"decl : var '=' expr ';'",
"decl : func",
"declrsblock : declblock",
"declrsblock : declrsblock declblock",
"declblock : var ';'",
"declblock : var '=' expr ';'",
"func : gen_type tIDENTIFIER '(' args ')'",
"func : gen_type tIDENTIFIER '(' args ')' block",
"func : gen_type tIDENTIFIER '(' args ')' '=' lit block",
"func : gen_type tIDENTIFIER '(' args ')' '=' lit ';'",
"func : gen_type tIDENTIFIER '(' ')'",
"func : gen_type tIDENTIFIER '(' ')' block",
"func : gen_type tIDENTIFIER '(' ')' '=' lit block",
"func : gen_type tIDENTIFIER '(' ')' '=' lit ';'",
"func : tLOCAL gen_type tIDENTIFIER '(' args ')'",
"func : tIMPORT gen_type tIDENTIFIER '(' args ')'",
"func : tLOCAL gen_type tIDENTIFIER '(' args ')' block",
"func : tIMPORT gen_type tIDENTIFIER '(' args ')' block",
"func : tLOCAL gen_type tIDENTIFIER '(' args ')' '=' lit block",
"func : tIMPORT gen_type tIDENTIFIER '(' args ')' '=' lit block",
"func : tLOCAL gen_type tIDENTIFIER '(' args ')' '=' lit ';'",
"func : tIMPORT gen_type tIDENTIFIER '(' args ')' '=' lit ';'",
"func : tLOCAL gen_type tIDENTIFIER '(' ')'",
"func : tIMPORT gen_type tIDENTIFIER '(' ')'",
"func : tLOCAL gen_type tIDENTIFIER '(' ')' block",
"func : tIMPORT gen_type tIDENTIFIER '(' ')' block",
"func : tLOCAL gen_type tIDENTIFIER '(' ')' '=' lit block",
"func : tIMPORT gen_type tIDENTIFIER '(' ')' '=' lit block",
"func : tLOCAL gen_type tIDENTIFIER '(' ')' '=' lit ';'",
"func : tIMPORT gen_type tIDENTIFIER '(' ')' '=' lit ';'",
"block : '{' inblock '}'",
"block : '{' '}'",
"inblock : declrsblock",
"inblock : list",
"inblock : declrsblock list",
"stmt : ';'",
"stmt : expr ';'",
"stmt : expr tPRINTLN",
"stmt : expr tPRINT",
"stmt : tNEXT tINTEGER ';'",
"stmt : tNEXT ';'",
"stmt : tSTOP tINTEGER ';'",
"stmt : tSTOP ';'",
"stmt : tREAD lval ';'",
"stmt : tREPEAT '(' exprs ';' exprs ';' exprs ')' stmt",
"stmt : tIF '(' expr ')' stmt",
"stmt : tIF '(' expr ')' stmt tELSE stmt",
"stmt : tRETURN",
"stmt : block",
"lit : litint",
"lit : tREAL",
"lit : str",
"litint : tINTEGER",
"expr : lit",
"expr : lval '=' expr",
"expr : lval '?'",
"expr : '-' expr",
"expr : '+' tINTEGER",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : '~' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '(' expr ')'",
"expr : lval",
"expr : funccall",
"expr : '[' litint ']'",
"expr : '*' lval",
"expr : \"<*>\" lval",
"exprs : expr",
"exprs : exprs ',' expr",
"str : tSTRING",
"str : str tSTRING",
"args : arg",
"args : args ',' arg",
"arg : type tIDENTIFIER",
"lval : tIDENTIFIER",
"lval : tIDENTIFIER '[' expr ']'",
"funccall : tIDENTIFIER '(' identifiers ')'",
"funccall : tIDENTIFIER '(' ')'",
"identifiers : expr",
"identifiers : identifiers ',' expr",
"var : gen_type tIDENTIFIER",
"var : '<' gen_type '>' tIDENTIFIER",
"var : tLOCAL gen_type tIDENTIFIER",
"var : tLOCAL '<' gen_type '>' tIDENTIFIER",
"var : tIMPORT gen_type tIDENTIFIER",
"var : tIMPORT '<' gen_type '>' tIDENTIFIER",
"gen_type : type",
"type : tINTEGERSYMB",
"type : tREALSYMB",
"type : tSTRINGSYMB",
"type : tPRINT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 66 "pwn_parser.y"
	{compiler->ast(yystack.l_mark[0].sequence);}
break;
case 2:
#line 70 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 3:
#line 71 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 4:
#line 74 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 5:
#line 75 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 6:
#line 78 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[-1].var; }
break;
case 7:
#line 79 "pwn_parser.y"
	{ yyval.node = new pwn::vardec_node(LINE, yystack.l_mark[-3].var, yystack.l_mark[-1].expression); }
break;
case 8:
#line 80 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 84 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 10:
#line 85 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 11:
#line 88 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[-1].var; }
break;
case 12:
#line 89 "pwn_parser.y"
	{ yyval.node = new pwn::vardec_node(LINE, yystack.l_mark[-3].var, yystack.l_mark[-1].expression); }
break;
case 13:
#line 93 "pwn_parser.y"
	{ yyval.node = new pwn::funcdec_node(LINE, true, false, yystack.l_mark[-4].exprtype, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 14:
#line 94 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-5].exprtype, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].block); }
break;
case 15:
#line 95 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-7].exprtype, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].block); }
break;
case 16:
#line 96 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-7].exprtype, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, nullptr); }
break;
case 17:
#line 97 "pwn_parser.y"
	{ yyval.node = new pwn::funcdec_node(LINE, true, false, yystack.l_mark[-3].exprtype, yystack.l_mark[-2].s, nullptr); }
break;
case 18:
#line 98 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-4].exprtype, yystack.l_mark[-3].s, nullptr, nullptr, yystack.l_mark[0].block); }
break;
case 19:
#line 99 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-6].exprtype, yystack.l_mark[-5].s, nullptr, yystack.l_mark[-1].expression, yystack.l_mark[0].block); }
break;
case 20:
#line 100 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-6].exprtype, yystack.l_mark[-5].s, nullptr, yystack.l_mark[-1].expression, nullptr); }
break;
case 21:
#line 101 "pwn_parser.y"
	{ yyval.node = new pwn::funcdec_node(LINE, false, true, yystack.l_mark[-4].exprtype, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 22:
#line 102 "pwn_parser.y"
	{ yyval.node = new pwn::funcdec_node(LINE, true, false, yystack.l_mark[-4].exprtype, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 23:
#line 103 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, false, true, yystack.l_mark[-5].exprtype, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].block); }
break;
case 24:
#line 104 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-5].exprtype, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].block); }
break;
case 25:
#line 105 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, false, true, yystack.l_mark[-7].exprtype, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].block); }
break;
case 26:
#line 106 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-7].exprtype, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].block); }
break;
case 27:
#line 107 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, false, true, yystack.l_mark[-7].exprtype, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, nullptr); }
break;
case 28:
#line 108 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-7].exprtype, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, nullptr); }
break;
case 29:
#line 109 "pwn_parser.y"
	{ yyval.node = new pwn::funcdec_node(LINE, false, true, yystack.l_mark[-3].exprtype, yystack.l_mark[-2].s, nullptr); }
break;
case 30:
#line 110 "pwn_parser.y"
	{ yyval.node = new pwn::funcdec_node(LINE, true, false, yystack.l_mark[-3].exprtype, yystack.l_mark[-2].s, nullptr); }
break;
case 31:
#line 111 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, false, true, yystack.l_mark[-4].exprtype, yystack.l_mark[-3].s, nullptr, nullptr, yystack.l_mark[0].block); }
break;
case 32:
#line 112 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-4].exprtype, yystack.l_mark[-3].s, nullptr, nullptr, yystack.l_mark[0].block); }
break;
case 33:
#line 113 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, false, true, yystack.l_mark[-6].exprtype, yystack.l_mark[-5].s, nullptr, yystack.l_mark[-1].expression, yystack.l_mark[0].block); }
break;
case 34:
#line 114 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-6].exprtype, yystack.l_mark[-5].s, nullptr, yystack.l_mark[-1].expression, yystack.l_mark[0].block); }
break;
case 35:
#line 115 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, false, true, yystack.l_mark[-6].exprtype, yystack.l_mark[-5].s, nullptr, yystack.l_mark[-1].expression, nullptr); }
break;
case 36:
#line 116 "pwn_parser.y"
	{ yyval.node = new pwn::funcdef_node(LINE, true, false, yystack.l_mark[-6].exprtype, yystack.l_mark[-5].s, nullptr, yystack.l_mark[-1].expression, nullptr); }
break;
case 37:
#line 121 "pwn_parser.y"
	{ yyval.block = yystack.l_mark[-1].block; }
break;
case 38:
#line 122 "pwn_parser.y"
	{ yyval.block = nullptr; }
break;
case 39:
#line 125 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, yystack.l_mark[0].sequence, nullptr); }
break;
case 40:
#line 126 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, nullptr, yystack.l_mark[0].sequence); }
break;
case 41:
#line 127 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, yystack.l_mark[-1].sequence, yystack.l_mark[0].sequence); }
break;
case 42:
#line 130 "pwn_parser.y"
	{ yyval.node = new cdk::nil_node(LINE); }
break;
case 43:
#line 131 "pwn_parser.y"
	{ yyval.node = new pwn::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 44:
#line 132 "pwn_parser.y"
	{ yyval.node = new pwn::print_node(LINE, yystack.l_mark[-1].expression, true); }
break;
case 45:
#line 133 "pwn_parser.y"
	{ yyval.node = new pwn::print_node(LINE, yystack.l_mark[-1].expression, false); }
break;
case 46:
#line 134 "pwn_parser.y"
	{ yyval.node = new pwn::next_node(LINE, new cdk::integer_node(LINE, yystack.l_mark[-1].i)); }
break;
case 47:
#line 135 "pwn_parser.y"
	{ yyval.node = new pwn::next_node(LINE, new cdk::integer_node(LINE, 1)); }
break;
case 48:
#line 136 "pwn_parser.y"
	{ yyval.node = new pwn::stop_node(LINE, new cdk::integer_node(LINE, yystack.l_mark[-1].i)); }
break;
case 49:
#line 137 "pwn_parser.y"
	{ yyval.node = new pwn::stop_node(LINE, new cdk::integer_node(LINE, 1)); }
break;
case 50:
#line 138 "pwn_parser.y"
	{ yyval.node = new pwn::read_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 51:
#line 139 "pwn_parser.y"
	{ yyval.node = new pwn::repeat_node(LINE, yystack.l_mark[-6].sequence, yystack.l_mark[-4].sequence, yystack.l_mark[-2].sequence, yystack.l_mark[0].node); }
break;
case 52:
#line 140 "pwn_parser.y"
	{ yyval.node = new cdk::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 53:
#line 141 "pwn_parser.y"
	{ yyval.node = new cdk::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 54:
#line 142 "pwn_parser.y"
	{ yyval.node = new pwn::return_node(LINE); }
break;
case 55:
#line 143 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[0].block; }
break;
case 56:
#line 147 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 57:
#line 148 "pwn_parser.y"
	{ yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 58:
#line 149 "pwn_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 59:
#line 152 "pwn_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 60:
#line 155 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 61:
#line 156 "pwn_parser.y"
	{ yyval.expression = new pwn::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 62:
#line 157 "pwn_parser.y"
	{ yyval.expression = new pwn::adressmemory_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 63:
#line 158 "pwn_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 64:
#line 159 "pwn_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 65:
#line 160 "pwn_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 66:
#line 161 "pwn_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 67:
#line 162 "pwn_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 68:
#line 163 "pwn_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 69:
#line 164 "pwn_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 70:
#line 165 "pwn_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 71:
#line 166 "pwn_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 72:
#line 167 "pwn_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 73:
#line 168 "pwn_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 74:
#line 169 "pwn_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 75:
#line 170 "pwn_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 76:
#line 171 "pwn_parser.y"
	{ yyval.expression = new pwn::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 77:
#line 172 "pwn_parser.y"
	{ yyval.expression = new pwn::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 78:
#line 173 "pwn_parser.y"
	{ yyval.expression = new pwn::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 79:
#line 174 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 80:
#line 175 "pwn_parser.y"
	{ yyval.expression = new pwn::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 81:
#line 176 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 82:
#line 177 "pwn_parser.y"
	{ yyval.expression = new pwn::reservememory_node(LINE, yystack.l_mark[-1].expression); }
break;
case 83:
#line 178 "pwn_parser.y"
	{ yyval.expression = new pwn::adressmemory_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 84:
#line 179 "pwn_parser.y"
	{ yyval.expression = new pwn::adressmemory_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 85:
#line 182 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 86:
#line 183 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 87:
#line 186 "pwn_parser.y"
	{ yyval.s = yystack.l_mark[0].s; }
break;
case 88:
#line 187 "pwn_parser.y"
	{ *yystack.l_mark[-1].s += *yystack.l_mark[0].s; yyval.s = yystack.l_mark[-1].s; delete(yystack.l_mark[0].s); }
break;
case 89:
#line 190 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 90:
#line 191 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-2].sequence); }
break;
case 91:
#line 194 "pwn_parser.y"
	{ yyval.node = new pwn::vardec_node(LINE, false, false, false, yystack.l_mark[-1].exprtype, yystack.l_mark[0].s, nullptr); }
break;
case 92:
#line 198 "pwn_parser.y"
	{ yyval.lvalue = new pwn::lvalue_node(LINE, yystack.l_mark[0].s); }
break;
case 93:
#line 199 "pwn_parser.y"
	{ yyval.lvalue = new pwn::index_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].expression); }
break;
case 94:
#line 202 "pwn_parser.y"
	{ yyval.expression = new pwn::funccall_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 95:
#line 203 "pwn_parser.y"
	{ yyval.expression = new pwn::funccall_node(LINE, yystack.l_mark[-2].s, nullptr); }
break;
case 96:
#line 206 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 97:
#line 207 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 98:
#line 210 "pwn_parser.y"
	{ yyval.var = new pwn::vardec_node(LINE, false, false, false, yystack.l_mark[-1].exprtype, yystack.l_mark[0].s, nullptr); }
break;
case 99:
#line 211 "pwn_parser.y"
	{ yyval.var = new pwn::vardec_node(LINE, false, false, true, yystack.l_mark[-2].exprtype, yystack.l_mark[0].s, nullptr); }
break;
case 100:
#line 212 "pwn_parser.y"
	{ yyval.var = new pwn::vardec_node(LINE, false, true, false, yystack.l_mark[-1].exprtype, yystack.l_mark[0].s, nullptr); }
break;
case 101:
#line 213 "pwn_parser.y"
	{ yyval.var = new pwn::vardec_node(LINE, false, true, true, yystack.l_mark[-2].exprtype, yystack.l_mark[0].s, nullptr); }
break;
case 102:
#line 214 "pwn_parser.y"
	{ yyval.var = new pwn::vardec_node(LINE, true, false, false, yystack.l_mark[-1].exprtype, yystack.l_mark[0].s, nullptr); }
break;
case 103:
#line 215 "pwn_parser.y"
	{ yyval.var = new pwn::vardec_node(LINE, true, false, true, yystack.l_mark[-2].exprtype, yystack.l_mark[0].s, nullptr); }
break;
case 104:
#line 218 "pwn_parser.y"
	{ yyval.exprtype = yystack.l_mark[0].exprtype; }
break;
case 105:
#line 221 "pwn_parser.y"
	{ yyval.exprtype = new basic_type(4, basic_type::TYPE_INT); }
break;
case 106:
#line 222 "pwn_parser.y"
	{ yyval.exprtype = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 107:
#line 223 "pwn_parser.y"
	{ yyval.exprtype = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 108:
#line 224 "pwn_parser.y"
	{ yyval.exprtype = new basic_type(0, basic_type::TYPE_VOID); }
break;
#line 1259 "pwn_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
