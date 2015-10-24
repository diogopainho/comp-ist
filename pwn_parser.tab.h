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
extern YYSTYPE yylval;
