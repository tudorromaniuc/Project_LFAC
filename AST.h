#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>
#include <vector>
#include "SymbolTable.h"

using namespace std;

struct EvalResult {
    string type; 
    string value; 
    
    int getInt() { return atoi(value.c_str()); }
    float getFloat() { return atof(value.c_str()); }
    bool getBool() { return value == "true"; }
};

class ASTNode {
public:
    string kind;      // "operator", "literal", "identifier", "assignment", "print", "other"
    string value;    
    string type;      
    
    ASTNode* left;
    ASTNode* right;

    ASTNode(string k, string v, string t, ASTNode* l = nullptr, ASTNode* r = nullptr);
    
    EvalResult evaluate();
};

#endif