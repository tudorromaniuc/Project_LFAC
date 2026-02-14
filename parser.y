%{
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
%}

%code requires {
    #include "SymbolTable.h"
    #include "AST.h"
}

%union {
    char* strVal;              
    ASTNode* node;             
    vector<string>* paramList; 
}

%token <strVal> ID TYPE CLASS IF WHILE PRINT MAIN_ENTRY RETURN
%token <strVal> INT_VAL FLOAT_VAL STRING_VAL BOOL_VAL
%token <strVal> RELOP LOGOP

%type <node> expr fn_call stmt assignment built_in_stmt control_stmt
%type <paramList> arg_list args 

%left LOGOP
%left RELOP
%left '+' '-'
%left '*' '/'
%left '.'

%start program

%%

program: { manager.initGlobalScope(); } global_decls main_block {
    cout << "Parsarea a fost facuta complet." << endl;
    cout << "Generam tables.txt:" << endl;
    
   
    cout << "\n Executam block-ul principal" << endl;
    for (ASTNode* node : mainStatements) {
        if (node != nullptr) {
            node->evaluate();
        }
    }
    
}
;

global_decls: 
            | global_decls class_decl
            | global_decls fn_decl
            | global_decls var_decl
            ;


start_class_scope: CLASS ID {
    if (manager.currentScope->lookupCurrentScope($2)) manager.semanticError("Class exists", yylineno);
    manager.currentScope->addSymbol($2, "class", "class");
    manager.enterScope("Class " + string($2));
    manager.classScopes[string($2)] = manager.currentScope;
};
class_decl: start_class_scope '{' class_body '}' ';' { manager.exitScope(); };
class_body: | class_body var_decl | class_body fn_decl;

// def func
start_fn_scope: TYPE ID '(' {
    if (manager.currentScope->lookupCurrentScope($2)) manager.semanticError("Func exists", yylineno);
    manager.currentScope->addSymbol($2, $1, "function");
    manager.currentFuncName = string($2);
    manager.currentFuncParamsStr = "";
    manager.currentFuncParamTypes.clear();
    manager.enterScope("Function " + string($2));
};
fn_decl: start_fn_scope param_list ')' {
    if (manager.currentScope->parent) {
        string pStr = (manager.currentFuncParamsStr.empty()) ? "-" : manager.currentFuncParamsStr;
        manager.currentScope->parent->updateFuncParams(manager.currentFuncName, pStr, manager.currentFuncParamTypes);
    }
} '{' local_vars statement_list_fn '}' { 
    manager.exitScope();
};

param_list: | params;
params: TYPE ID { 
    manager.currentScope->addSymbol($2, $1, "parameter"); 
    manager.currentFuncParamsStr += (manager.currentFuncParamsStr.empty() ? "" : ", ") + string($1);
    manager.currentFuncParamTypes.push_back(string($1));
} | params ',' TYPE ID { 
    manager.currentScope->addSymbol($4, $3, "parameter"); 
    manager.currentFuncParamsStr += ", " + string($3);
    manager.currentFuncParamTypes.push_back(string($3));
};

// def var
var_decl: TYPE ID ';' { manager.currentScope->addSymbol($2, $1, "variable"); }
        | TYPE ID '=' expr ';' {
            if (manager.currentScope->lookupCurrentScope($2)) manager.semanticError("Redefined", yylineno);
            if (string($1) != $4->type) manager.semanticError("Init type mismatch", yylineno);
            
            
            string initVal = ($4->kind == "literal") ? $4->value : "initialized";
            manager.currentScope->addSymbol($2, $1, "variable", initVal);
        }
        | CLASS ID ID ';' { manager.currentScope->addSymbol($3, $2, "object"); };

local_vars: | local_vars var_decl;

main_block: MAIN_ENTRY { manager.enterScope("Main Block"); } '{' statement_list_main '}' {
    manager.exitScope();
};

statement_list_main:
                   | statement_list_main stmt {
                       if ($2 != nullptr) mainStatements.push_back($2);
                   }
                   ;


statement_list_fn:
                 | statement_list_fn stmt
                 ;

stmt: assignment ';' { $$ = $1; }
    | control_stmt   { $$ = nullptr; } 
    | built_in_stmt ';' { $$ = $1; }
    | fn_call ';' { $$ = new ASTNode("other", "call", $1->type); }
    | RETURN expr ';' { $$ = nullptr; }
    ;

assignment: ID '=' expr {
    Symbol* s = manager.findSymbol($1);
    if (!s) manager.semanticError("Var undefined", yylineno);
    if (s->type != $3->type) manager.semanticError("Assign type mismatch", yylineno);
    
    // car.nr = 21;
    $$ = new ASTNode("assignment", string($1), s->type, nullptr, $3);
}
          | ID '.' ID '=' expr {
              Symbol* obj = manager.findSymbol($1);
              SymbolTable* cls = manager.classScopes[obj->type];
              Symbol* field = cls->lookupCurrentScope($3);
              if (field->type != $5->type) manager.semanticError("Field assign mismatch", yylineno);
              $$ = nullptr; 
          }
          ;

built_in_stmt: PRINT '(' expr ')' {
    $$ = new ASTNode("print", "print", $3->type, $3, nullptr);
}
;

control_stmt: IF '(' expr ')' '{' statement_list_fn '}' { $$ = nullptr; }
            | WHILE '(' expr ')' '{' statement_list_fn '}' { $$ = nullptr; }
            ;

fn_call: ID '(' arg_list ')' {
    Symbol* s = manager.findSymbol($1);
    
    $$ = new ASTNode("other", string($1), s->type);
}
       | ID '.' ID '(' arg_list ')' {
           Symbol* obj = manager.findSymbol($1);
           SymbolTable* c = manager.classScopes[obj->type];
           Symbol* m = c->lookupCurrentScope($3);
           $$ = new ASTNode("other", string($3), m->type);
       }
       ;

arg_list: { $$ = new vector<string>(); } | args { $$ = $1; };
args: expr { $$ = new vector<string>(); } | args ',' expr { $$ = $1; };

// exp pt ast
expr: INT_VAL    { $$ = new ASTNode("literal", string($1), "int"); }
    | FLOAT_VAL  { $$ = new ASTNode("literal", string($1), "float"); }
    | STRING_VAL { $$ = new ASTNode("literal", string($1), "string"); }
    | BOOL_VAL   { $$ = new ASTNode("literal", string($1), "bool"); }
    | ID {
        Symbol* s = manager.findSymbol($1);
        if (!s) manager.semanticError("Undefined var", yylineno);
        $$ = new ASTNode("identifier", string($1), s->type);
    }
    | fn_call { $$ = $1; }
    | expr '+' expr { 
        if ($1->type != $3->type) manager.semanticError("Type mismatch +", yylineno);
        $$ = new ASTNode("operator", "+", $1->type, $1, $3);
    }
    | expr '-' expr { 
        if ($1->type != $3->type) manager.semanticError("Type mismatch -", yylineno);
        $$ = new ASTNode("operator", "-", $1->type, $1, $3);
    }
    | expr '*' expr { 
        if ($1->type != $3->type) manager.semanticError("Type mismatch *", yylineno);
        $$ = new ASTNode("operator", "*", $1->type, $1, $3);
    }
    | expr '/' expr { 
        if ($1->type != $3->type) manager.semanticError("Type mismatch /", yylineno);
        $$ = new ASTNode("operator", "/", $1->type, $1, $3);
    }
    | expr RELOP expr {
        if ($1->type != $3->type) manager.semanticError("Type mismatch RELOP", yylineno);
        $$ = new ASTNode("operator", string($2), "bool", $1, $3);
    }
    | expr LOGOP expr {
        if ($1->type != "bool" || $3->type != "bool") manager.semanticError("Type mismatch LOGOP", yylineno);
        $$ = new ASTNode("operator", string($2), "bool", $1, $3);
    }
    | '(' expr ')' { $$ = $2; }
    ;

%%
void yyerror(const char *s) { fprintf(stderr, "Syntax Error line %d: %s\n", yylineno, s); }
int main() {
    yyparse();
    ofstream outFile("tables.txt");
    for (auto t : manager.allTables) t->print(outFile);
    outFile.close();
    return 0;
}