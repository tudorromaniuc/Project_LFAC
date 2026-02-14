#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>

using namespace std;

struct Symbol {
    string name;
    string type;    
    string kind;        
    string value;       
    string paramInfo;   
    vector<string> paramTypes; 
};


class SymbolTable {
public:
    string name;
    SymbolTable* parent;
    vector<Symbol> symbols;

    SymbolTable(string n, SymbolTable* p = nullptr);
    
    bool addSymbol(string name, string type, string kind, string value = "-", string paramInfo = "-");
    Symbol* lookup(string name);
    Symbol* lookupCurrentScope(string name);
    
    void updateFuncParams(string funcName, string paramsStr, vector<string> types);
    void updateSymbolValue(string name, string newVal); 
    
    void print(ofstream& out);
};


class AnalysisManager {
public:
    SymbolTable* currentScope;
    vector<SymbolTable*> allTables;
    map<string, SymbolTable*> classScopes;

    string currentFuncName;
    string currentFuncParamsStr;
    vector<string> currentFuncParamTypes;

    AnalysisManager();
    void initGlobalScope();
    void enterScope(string scopeName);
    void exitScope();
    
    bool isClassDefined(string className);
    Symbol* findSymbol(string name);
    void semanticError(string msg, int lineIdx);
};

extern AnalysisManager manager;

#endif