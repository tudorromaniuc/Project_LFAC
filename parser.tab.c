#define YYBISON 30802

#define YYBISON_VERSION "3.8.2"

#define YYSKELETON_NAME "yacc.c"

#define YYPURE 0

#define YYPUSH 0

#define YYPULL 1

#line 1 "parser.y"

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include "SymbolTable.h"
#include "AST.h"

using namespace std;

extern int yylineno;
int yylex();
void yyerror(const char *s);

vector<ASTNode*> mainStatements;

#line 89 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"

enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      
  YYSYMBOL_YYerror = 1,                    
  YYSYMBOL_YYUNDEF = 2,                    
  YYSYMBOL_ID = 3,                         
  YYSYMBOL_TYPE = 4,                       
  YYSYMBOL_CLASS = 5,                      
  YYSYMBOL_IF = 6,                         
  YYSYMBOL_WHILE = 7,                      
  YYSYMBOL_PRINT = 8,                      
  YYSYMBOL_MAIN_ENTRY = 9,                 
  YYSYMBOL_RETURN = 10,                    
  YYSYMBOL_INT_VAL = 11,                   
  YYSYMBOL_FLOAT_VAL = 12,                 
  YYSYMBOL_STRING_VAL = 13,                
  YYSYMBOL_BOOL_VAL = 14,                  
  YYSYMBOL_RELOP = 15,                     
  YYSYMBOL_LOGOP = 16,                     
  YYSYMBOL_17_ = 17,                       
  YYSYMBOL_18_ = 18,                       
  YYSYMBOL_19_ = 19,                       
  YYSYMBOL_20_ = 20,                       
  YYSYMBOL_21_ = 21,                       
  YYSYMBOL_22_ = 22,                       
  YYSYMBOL_23_ = 23,                       
  YYSYMBOL_24_ = 24,                       
  YYSYMBOL_25_ = 25,                       
  YYSYMBOL_26_ = 26,                       
  YYSYMBOL_27_ = 27,                       
  YYSYMBOL_28_ = 28,                       
  YYSYMBOL_YYACCEPT = 29,                  
  YYSYMBOL_program = 30,                   
  YYSYMBOL_31_1 = 31,                      
  YYSYMBOL_global_decls = 32,              
  YYSYMBOL_start_class_scope = 33,         
  YYSYMBOL_class_decl = 34,                
  YYSYMBOL_class_body = 35,                
  YYSYMBOL_start_fn_scope = 36,            
  YYSYMBOL_fn_decl = 37,                   
  YYSYMBOL_38_2 = 38,                      
  YYSYMBOL_param_list = 39,                
  YYSYMBOL_params = 40,                    
  YYSYMBOL_var_decl = 41,                  
  YYSYMBOL_local_vars = 42,                
  YYSYMBOL_main_block = 43,                
  YYSYMBOL_44_3 = 44,                      
  YYSYMBOL_statement_list_main = 45,       
  YYSYMBOL_statement_list_fn = 46,         
  YYSYMBOL_stmt = 47,                      
  YYSYMBOL_assignment = 48,                
  YYSYMBOL_built_in_stmt = 49,             
  YYSYMBOL_control_stmt = 50,              
  YYSYMBOL_fn_call = 51,                   
  YYSYMBOL_arg_list = 52,                  
  YYSYMBOL_args = 53,                      
  YYSYMBOL_expr = 54                       
};
typedef enum yysymbol_kind_t yysymbol_kind_t;

#ifdef short
# undef short
#endif

#ifndef __PTRDIFF_MAX__
# include <limits.h> 
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> 
#  define YY_STDINT_H
# endif
#endif

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> 
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> 
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

typedef yytype_int8 yy_state_t;

typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> 
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) 
#endif

#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) 
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                           \
    _Pragma ("GCC diagnostic push")                             \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END             \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> 
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> 
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> 
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
#  define YYSTACK_FREE(Ptr) do {  } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM 4032 
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> 
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); 
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); 
#   endif
#  endif
# endif
#endif 

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif 

#define YYFINAL  3
#define YYLAST   166

#define YYNTOKENS  29
#define YYNNTS  26
#define YYNRULES  59
#define YYNSTATES  121

#define YYMAXUTOK   271

#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,    26,    19,    17,    27,    18,    21,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
       2,    28,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16
};

#if YYDEBUG
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    47,    62,    63,    64,    65,    69,    75,
      76,    76,    76,    79,    87,    87,    96,    96,    97,   101,
     108,   109,   117,   119,   119,   121,   121,   125,   126,   132,
     133,   136,   137,   138,   139,   140,   143,   151,   160,   165,
     166,   169,   174,   182,   182,   183,   183,   186,   187,   188,
     189,   190,   195,   196,   200,   204,   208,   212,   216,   220
};
#endif

#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "TYPE", "CLASS",
  "IF", "WHILE", "PRINT", "MAIN_ENTRY", "RETURN", "INT_VAL", "FLOAT_VAL",
  "STRING_VAL", "BOOL_VAL", "RELOP", "LOGOP", "'+'", "'-'", "'*'", "'/'",
  "'.'", "'{'", "'}'", "';'", "'('", "')'", "','", "'='", "$accept",
  "program", "$@1", "global_decls", "start_class_scope", "class_decl",
  "class_body", "start_fn_scope", "fn_decl", "$@2", "param_list", "params",
  "var_decl", "local_vars", "main_block", "$@3", "statement_list_main",
  "statement_list_fn", "stmt", "assignment", "built_in_stmt",
  "control_stmt", "fn_call", "arg_list", "args", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

static const yytype_int16 yypact[] =
{
     -39,      5,    -39,    -39,     73,     13,     22,    -39,     12,    -39,
      48,    -39,    -39,    -39,     60,     33,     21,    -39,     63,     42,
      43,    -39,    -39,      7,     51,    -39,     10,    -39,    -39,     77,
      -8,    -39,    -39,    -39,    -39,      7,    -39,    123,    -39,      1,
      97,     86,    -39,    -39,     89,    109,    117,      7,     75,      7,
       7,      7,      7,      7,      7,    -39,     25,     96,     98,    107,
       7,    -39,    -39,    100,    110,    -39,    112,     33,    -39,    -39,
     -39,    108,    118,     95,    143,    -39,     79,     39,      3,      3,
     -39,    -39,    132,      7,      7,      7,      7,    133,    -39,    -39,
     -39,     82,      7,    -39,      7,    -22,    143,     87,     99,    111,
     -39,    142,    -39,     32,    120,    143,      7,    134,    144,    -39,
      17,    -39,    -39,    -39,    143,    -39,    -39,     41,     66,    -39,
     -39
};

static const yytype_int8 yydefact[] =
{
       2,      0,      4,      1,      0,      0,      0,     25,      0,      5,
      16,      6,      7,      3,      0,      8,      0,     10,      0,      0,
      17,     20,     13,      0,      0,     27,      0,     18,     14,      0,
      51,     47,     48,     49,     50,      0,     52,      0,     22,      0,
       0,      0,     12,     11,      0,      0,      0,     43,      0,      0,
       0,      0,      0,      0,      0,     21,      0,      0,      0,      0,
       0,     26,     28,      0,      0,     32,      0,      0,      9,     23,
      19,      0,      0,     44,     45,     59,     57,     58,     53,     54,
      55,     56,      0,      0,      0,      0,      0,      0,     31,     33,
      34,     29,     43,     41,      0,      0,     36,      0,      0,      0,
      35,      0,     24,      0,      0,     46,      0,      0,      0,     38,
       0,     15,     30,     42,     37,     29,     29,      0,      0,     39,
      40
};

static const yytype_int16 yypgoto[] =
{
     -39,    -39,    -39,    -39,    -39,    -39,    -39,    -39,    128,    -39,
     -39,    -39,    -24,    -39,    -39,    -39,    -39,     -7,    116,    -39,
     -39,    -39,    -38,     72,    -39,    -23
};

static const yytype_int8 yydefgoto[] =
{
       0,      1,      2,      4,      8,      9,     26,     10,     11,     44,
      19,     20,     12,     91,     13,     16,     39,    103,    112,     63,
      64,     65,     36,     72,     73,     74
};

static const yytype_int8 yytable[] =
{
      37,     66,     43,     92,     56,      3,    106,     57,     58,     59,
      30,     60,     48,     46,      5,     40,     14,     47,     31,     32,
      33,     34,     53,     54,     61,     15,     76,     77,     78,     79,
      80,     81,     35,     41,     17,     56,     24,     87,     57,     58,
      59,     21,     60,     25,     56,     23,     82,     57,     58,     59,
      47,     60,     18,     83,     49,    111,     51,     52,     53,     54,
      96,     97,     98,     99,    119,     66,     27,    102,     28,     56,
      29,    105,     57,     58,     59,     38,     60,      5,      6,     66,
      66,     45,      7,    114,     21,     22,    101,     40,     23,    120,
      49,     50,     51,     52,     53,     54,     51,     52,     53,     54,
      67,     75,     49,     50,     51,     52,     53,     54,    117,    118,
      68,     69,     70,    107,     49,     50,     51,     52,     53,     54,
      71,     84,     94,     85,     88,    108,     49,     50,     51,     52,
      53,     54,     86,     92,     89,     95,     90,    109,     49,     50,
      51,     52,     53,     54,     93,    110,    113,     55,     49,     50,
      51,     52,     53,     54,     42,     62,    115,    100,     49,     50,
      51,     52,     53,     54,    104,      0,    116
};

static const yytype_int8 yycheck[] =
{
      23,     39,     26,     25,      3,      0,     28,      6,      7,      8,
       3,     10,     35,     21,      4,      5,      3,     25,     11,     12,
      13,     14,     19,     20,     23,      3,     49,     50,     51,     52,
      53,     54,     25,     23,     22,      3,      3,     60,      6,      7,
       8,     24,     10,     22,      3,     28,     21,      6,      7,      8,
      25,     10,      4,     28,     15,     23,     17,     18,     19,     20,
      83,     84,     85,     86,     23,    103,      3,     91,     26,      3,
      27,     94,      6,      7,      8,     24,     10,      4,      5,    117,
     118,      4,      9,    106,     24,     25,      4,      5,     28,     23,
      15,     16,     17,     18,     19,     20,     17,     18,     19,     20,
       3,     26,     15,     16,     17,     18,     19,     20,    115,    116,
      24,     22,      3,     26,     15,     16,     17,     18,     19,     20,
       3,     25,     27,     25,     24,     26,     15,     16,     17,     18,
      19,     20,     25,     25,     24,      3,     24,     26,     15,     16,
      17,     18,     19,     20,     26,      3,     26,     24,     15,     16,
      17,     18,     19,     20,     26,     39,     22,     24,     15,     16,
      17,     18,     19,     20,     92,     -1,     22
};

static const yytype_int8 yystos[] =
{
       0,     30,     31,      0,     32,      4,      5,      9,     33,     34,
      36,     37,     41,     43,      3,      3,     44,     22,      4,     39,
      40,     24,     25,     28,      3,     22,     35,      3,     26,     27,
       3,     11,     12,     13,     14,     25,     51,     54,     24,     45,
       5,     23,     37,     41,     38,      4,     21,     25,     54,     15,
      16,     17,     18,     19,     20,     24,      3,      6,      7,      8,
      10,     23,     47,     48,     49,     50,     51,      3,     24,     22,
       3,      3,     52,     53,     54,     26,     54,     54,     54,     54,
      54,     54,     21,     28,     25,     25,     25,     54,     24,     24,
      24,     42,     25,     26,     27,      3,     54,     54,     54,     54,
      24,      4,     41,     46,     52,     54,     28,     26,     26,     26,
       3,     23,     47,     26,     54,     22,     22,     46,     46,     23,
      23
};

static const yytype_int8 yyr1[] =
{
       0,     29,     31,     30,     32,     32,     32,     32,     33,     34,
      35,     35,     35,     36,     38,     37,     39,     39,     40,     40,
      41,     41,     41,     42,     42,     44,     43,     45,     45,     46,
      46,     47,     47,     47,     47,     47,     48,     48,     49,     50,
      50,     51,     51,     52,     52,     53,     53,     54,     54,     54,
      54,     54,     54,     54,     54,     54,     54,     54,     54,     54
};

static const yytype_int8 yyr2[] =
{
       0,      2,      0,      3,      0,      2,      2,      2,      2,      5,
       0,      2,      2,      3,      0,      8,      0,      1,      2,      4,
       3,      5,      4,      0,      2,      0,      5,      0,      2,      0,
       2,      2,      1,      2,      2,      3,      3,      5,      4,      7,
       7,      4,      6,      0,      1,      1,      3,      1,      1,      1,
       1,      1,      1,      3,      3,      3,      3,      3,      3,      3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

#define YYERRCODE YYUNDEF


#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> 
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

int yydebug;
#else 
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif 


#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


int yychar;

YYSTYPE yylval;
int yynerrs;

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    int yyerrstatus = 0;

    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  int yyresult;
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; 

  goto yysetstate;


yynewstate:
  yyssp++;


yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else 
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif 


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


yybackup:

  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyerrstatus)
    yyerrstatus--;

  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yychar = YYEMPTY;
  goto yynewstate;


yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


yyreduce:
  yylen = yyr2[yyn];

  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: 
#line 47 "parser.y"
         { manager.initGlobalScope(); }
#line 1212 "parser.tab.c"
    break;

  case 3: 
#line 47 "parser.y"
                                                                {
    cout << "Parsarea a fost facuta complet." << endl;
    cout << "Generam tables.txt:" << endl;
    
    
    cout << "\n Executam block-ul principal" << endl;
    for (ASTNode* node : mainStatements) {
        if (node != nullptr) {
            node->evaluate();
        }
    }
    
}
#line 1230 "parser.tab.c"
    break;

  case 8: 
#line 69 "parser.y"
                            {
    if (manager.currentScope->lookupCurrentScope((yyvsp[0].strVal))) manager.semanticError("Class exists", yylineno);
    manager.currentScope->addSymbol((yyvsp[0].strVal), "class", "class");
    manager.enterScope("Class " + string((yyvsp[0].strVal)));
    manager.classScopes[string((yyvsp[0].strVal))] = manager.currentScope;
}
#line 1241 "parser.tab.c"
    break;

  case 9: 
#line 75 "parser.y"
                                                     { manager.exitScope(); }
#line 1247 "parser.tab.c"
    break;

  case 13: 
#line 79 "parser.y"
                            {
    if (manager.currentScope->lookupCurrentScope((yyvsp[-1].strVal))) manager.semanticError("Func exists", yylineno);
    manager.currentScope->addSymbol((yyvsp[-1].strVal), (yyvsp[-2].strVal), "function");
    manager.currentFuncName = string((yyvsp[-1].strVal));
    manager.currentFuncParamsStr = "";
    manager.currentFuncParamTypes.clear();
    manager.enterScope("Function " + string((yyvsp[-1].strVal)));
}
#line 1260 "parser.tab.c"
    break;

  case 14: 
#line 87 "parser.y"
                                     {
    if (manager.currentScope->parent) {
        string pStr = (manager.currentFuncParamsStr.empty()) ? "-" : manager.currentFuncParamsStr;
        manager.currentScope->parent->updateFuncParams(manager.currentFuncName, pStr, manager.currentFuncParamTypes);
    }
}
#line 1271 "parser.tab.c"
    break;

  case 15: 
#line 92 "parser.y"
                                       { 
    manager.exitScope();
}
#line 1279 "parser.tab.c"
    break;

  case 18: 
#line 97 "parser.y"
                { 
    manager.currentScope->addSymbol((yyvsp[0].strVal), (yyvsp[-1].strVal), "parameter"); 
    manager.currentFuncParamsStr += (manager.currentFuncParamsStr.empty() ? "" : ", ") + string((yyvsp[-1].strVal));
    manager.currentFuncParamTypes.push_back(string((yyvsp[-1].strVal)));
}
#line 1289 "parser.tab.c"
    break;

  case 19: 
#line 101 "parser.y"
                        { 
    manager.currentScope->addSymbol((yyvsp[0].strVal), (yyvsp[-1].strVal), "parameter"); 
    manager.currentFuncParamsStr += ", " + string((yyvsp[-1].strVal));
    manager.currentFuncParamTypes.push_back(string((yyvsp[-1].strVal)));
}
#line 1299 "parser.tab.c"
    break;

  case 20: 
#line 108 "parser.y"
                      { manager.currentScope->addSymbol((yyvsp[-1].strVal), (yyvsp[-2].strVal), "variable"); }
#line 1305 "parser.tab.c"
    break;

  case 21: 
#line 109 "parser.y"
                                {
            if (manager.currentScope->lookupCurrentScope((yyvsp[-3].strVal))) manager.semanticError("Redefined", yylineno);
            if (string((yyvsp[-4].strVal)) != (yyvsp[-1].node)->type) manager.semanticError("Init type mismatch", yylineno);
            
            
            string initVal = ((yyvsp[-1].node)->kind == "literal") ? (yyvsp[-1].node)->value : "initialized";
            manager.currentScope->addSymbol((yyvsp[-3].strVal), (yyvsp[-4].strVal), "variable", initVal);
        }
#line 1318 "parser.tab.c"
    break;

  case 22: 
#line 117 "parser.y"
                           { manager.currentScope->addSymbol((yyvsp[-1].strVal), (yyvsp[-2].strVal), "object"); }
#line 1324 "parser.tab.c"
    break;

  case 25: 
#line 121 "parser.y"
                        { manager.enterScope("Main Block"); }
#line 1330 "parser.tab.c"
    break;

  case 26: 
#line 121 "parser.y"
                                                                         {
    manager.exitScope();
}
#line 1338 "parser.tab.c"
    break;

  case 28: 
#line 126 "parser.y"
                                      {
                       if ((yyvsp[0].node) != nullptr) mainStatements.push_back((yyvsp[0].node));
                   }
#line 1346 "parser.tab.c"
    break;

  case 31: 
#line 136 "parser.y"
                     { (yyval.node) = (yyvsp[-1].node); }
#line 1352 "parser.tab.c"
    break;

  case 32: 
#line 137 "parser.y"
                     { (yyval.node) = nullptr; }
#line 1358 "parser.tab.c"
    break;

  case 33: 
#line 138 "parser.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1364 "parser.tab.c"
    break;

  case 34: 
#line 139 "parser.y"
                  { (yyval.node) = new ASTNode("other", "call", (yyvsp[-1].node)->type); }
#line 1370 "parser.tab.c"
    break;

  case 35: 
#line 140 "parser.y"
                      { (yyval.node) = nullptr; }
#line 1376 "parser.tab.c"
    break;

  case 36: 
#line 143 "parser.y"
                         {
    Symbol* s = manager.findSymbol((yyvsp[-2].strVal));
    if (!s) manager.semanticError("Var undefined", yylineno);
    if (s->type != (yyvsp[0].node)->type) manager.semanticError("Assign type mismatch", yylineno);
    
    (yyval.node) = new ASTNode("assignment", string((yyvsp[-2].strVal)), s->type, nullptr, (yyvsp[0].node));
}
#line 1389 "parser.tab.c"
    break;

  case 37: 
#line 151 "parser.y"
                               {
             Symbol* obj = manager.findSymbol((yyvsp[-4].strVal));
             SymbolTable* cls = manager.classScopes[obj->type];
             Symbol* field = cls->lookupCurrentScope((yyvsp[-2].strVal));
             if (field->type != (yyvsp[0].node)->type) manager.semanticError("Field assign mismatch", yylineno);
             (yyval.node) = nullptr; 
          }
#line 1401 "parser.tab.c"
    break;

  case 38: 
#line 160 "parser.y"
                                  {
    (yyval.node) = new ASTNode("print", "print", (yyvsp[-1].node)->type, (yyvsp[-1].node), nullptr);
}
#line 1409 "parser.tab.c"
    break;

  case 39: 
#line 165 "parser.y"
                                                        { (yyval.node) = nullptr; }
#line 1415 "parser.tab.c"
    break;

  case 40: 
#line 166 "parser.y"
                                                           { (yyval.node) = nullptr; }
#line 1421 "parser.tab.c"
    break;

  case 41: 
#line 169 "parser.y"
                             {
    Symbol* s = manager.findSymbol((yyvsp[-3].strVal));
    
    (yyval.node) = new ASTNode("other", string((yyvsp[-3].strVal)), s->type);
}
#line 1431 "parser.tab.c"
    break;

  case 42: 
#line 174 "parser.y"
                                    {
           Symbol* obj = manager.findSymbol((yyvsp[-5].strVal));
           SymbolTable* c = manager.classScopes[obj->type];
           Symbol* m = c->lookupCurrentScope((yyvsp[-3].strVal));
           (yyval.node) = new ASTNode("other", string((yyvsp[-3].strVal)), m->type);
       }
#line 1442 "parser.tab.c"
    break;

  case 43: 
#line 182 "parser.y"
          { (yyval.paramList) = new vector<string>(); }
#line 1448 "parser.tab.c"
    break;

  case 44: 
#line 182 "parser.y"
                                                { (yyval.paramList) = (yyvsp[0].paramList); }
#line 1454 "parser.tab.c"
    break;

  case 45: 
#line 183 "parser.y"
           { (yyval.paramList) = new vector<string>(); }
#line 1460 "parser.tab.c"
    break;

  case 46: 
#line 183 "parser.y"
                                          { (yyval.paramList) = (yyvsp[-2].paramList); }
#line 1466 "parser.tab.c"
    break;

  case 47: 
#line 186 "parser.y"
                 { (yyval.node) = new ASTNode("literal", string((yyvsp[0].strVal)), "int"); }
#line 1472 "parser.tab.c"
    break;

  case 48: 
#line 187 "parser.y"
                 { (yyval.node) = new ASTNode("literal", string((yyvsp[0].strVal)), "float"); }
#line 1478 "parser.tab.c"
    break;

  case 49: 
#line 188 "parser.y"
                 { (yyval.node) = new ASTNode("literal", string((yyvsp[0].strVal)), "string"); }
#line 1484 "parser.tab.c"
    break;

  case 50: 
#line 189 "parser.y"
                 { (yyval.node) = new ASTNode("literal", string((yyvsp[0].strVal)), "bool"); }
#line 1490 "parser.tab.c"
    break;

  case 51: 
#line 190 "parser.y"
         {
        Symbol* s = manager.findSymbol((yyvsp[0].strVal));
        if (!s) manager.semanticError("Undefined var", yylineno);
        (yyval.node) = new ASTNode("identifier", string((yyvsp[0].strVal)), s->type);
    }
#line 1500 "parser.tab.c"
    break;

  case 52: 
#line 195 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1506 "parser.tab.c"
    break;

  case 53: 
#line 196 "parser.y"
                    { 
        if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) manager.semanticError("Type mismatch +", yylineno);
        (yyval.node) = new ASTNode("operator", "+", (yyvsp[-2].node)->type, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1515 "parser.tab.c"
    break;

  case 54: 
#line 200 "parser.y"
                    { 
        if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) manager.semanticError("Type mismatch -", yylineno);
        (yyval.node) = new ASTNode("operator", "-", (yyvsp[-2].node)->type, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1524 "parser.tab.c"
    break;

  case 55: 
#line 204 "parser.y"
                    { 
        if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) manager.semanticError("Type mismatch *", yylineno);
        (yyval.node) = new ASTNode("operator", "*", (yyvsp[-2].node)->type, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1533 "parser.tab.c"
    break;

  case 56: 
#line 208 "parser.y"
                    { 
        if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) manager.semanticError("Type mismatch /", yylineno);
        (yyval.node) = new ASTNode("operator", "/", (yyvsp[-2].node)->type, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1542 "parser.tab.c"
    break;

  case 57: 
#line 212 "parser.y"
                      {
        if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) manager.semanticError("Type mismatch RELOP", yylineno);
        (yyval.node) = new ASTNode("operator", string((yyvsp[-1].strVal)), "bool", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1551 "parser.tab.c"
    break;

  case 58: 
#line 216 "parser.y"
                      {
        if ((yyvsp[-2].node)->type != "bool" || (yyvsp[0].node)->type != "bool") manager.semanticError("Type mismatch LOGOP", yylineno);
        (yyval.node) = new ASTNode("operator", string((yyvsp[-1].strVal)), "bool", (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1560 "parser.tab.c"
    break;

  case 59: 
#line 220 "parser.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 1566 "parser.tab.c"
    break;


#line 1570 "parser.tab.c"

      default: break;
    }

  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


yyerrlab:
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {

      if (yychar <= YYEOF)
        {
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  goto yyerrlab1;


yyerrorlab:
  if (0)
    YYERROR;
  ++yynerrs;

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


yyerrlab1:
  yyerrstatus = 3;      

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


yyreturnlab:
  if (yychar != YYEMPTY)
    {
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 223 "parser.y"

void yyerror(const char *s) { fprintf(stderr, "Syntax Error line %d: %s\n", yylineno, s); }
int main() {
    yyparse();
    ofstream outFile("tables.txt");
    for (auto t : manager.allTables) t->print(outFile);
    outFile.close();
    return 0;
}
