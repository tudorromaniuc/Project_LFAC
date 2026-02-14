%{
#include <iostream>
#include <cstring>
#include <vector>
#include "SymbolTable.h"
#include "AST.h"
#include "parser.tab.h"
using namespace std;
%}

%option noyywrap
%option yylineno

%%

"int"|"float"|"string"|"bool"|"void" { yylval.strVal = strdup(yytext); return TYPE; }
"class"         { return CLASS; }
"if"            { return IF; }
"while"         { return WHILE; }
"Print"         { return PRINT; }
"main_entry"    { return MAIN_ENTRY; }
"return"        { return RETURN; }
"true"|"false"  { yylval.strVal = strdup(yytext); return BOOL_VAL; }

"=="|"!="|"<"|">"|"<="|">=" { yylval.strVal = strdup(yytext); return RELOP; }
"&&"|"||"       { yylval.strVal = strdup(yytext); return LOGOP; }
"="             { return '='; }
"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"."             { return '.'; }
","             { return ','; }
";"             { return ';'; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }

[a-zA-Z][a-zA-Z0-9]* { yylval.strVal = strdup(yytext); return ID; }

[0-9]+          { yylval.strVal = strdup(yytext); return INT_VAL; }
[0-9]*\.[0-9]+  { yylval.strVal = strdup(yytext); return FLOAT_VAL; }
\"[^"]*\"       { yylval.strVal = strdup(yytext); return STRING_VAL; }

[ \t\n\r]       ; 
.               { return yytext[0]; }

%%