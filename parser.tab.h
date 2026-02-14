#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED

#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

#line 19 "parser.y"

    #include "SymbolTable.h"
    #include "AST.h"

#line 54 "parser.tab.h"

#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,
    YYerror = 256,
    YYUNDEF = 257,
    ID = 258,
    TYPE = 259,
    CLASS = 260,
    IF = 261,
    WHILE = 262,
    PRINT = 263,
    MAIN_ENTRY = 264,
    RETURN = 265,
    INT_VAL = 266,
    FLOAT_VAL = 267,
    STRING_VAL = 268,
    BOOL_VAL = 269,
    RELOP = 270,
    LOGOP = 271
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

    char* strVal;
    ASTNode* node;
    vector<string>* paramList;

#line 93 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif
