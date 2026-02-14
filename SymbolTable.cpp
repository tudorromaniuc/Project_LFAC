#include "SymbolTable.h"

SymbolTable::SymbolTable(string n, SymbolTable *p) : name(n), parent(p) {}

bool SymbolTable::addSymbol(string name, string type, string kind, string value, string paramInfo)
{
    if (lookupCurrentScope(name) != nullptr)
        return false;
    Symbol s;
    s.name = name;
    s.type = type;
    s.kind = kind;
    s.value = value;
    s.paramInfo = paramInfo;
    symbols.push_back(s);
    return true;
}

Symbol *SymbolTable::lookup(string name)
{
    for (auto &s : symbols)
    {
        if (s.name == name)
            return &s;
    }
    if (parent != nullptr)
        return parent->lookup(name);
    return nullptr;
}

Symbol *SymbolTable::lookupCurrentScope(string name)
{
    for (auto &s : symbols)
    {
        if (s.name == name)
            return &s;
    }
    return nullptr;
}

void SymbolTable::updateFuncParams(string name, string paramsStr, vector<string> types)
{
    for (auto &s : symbols)
    {
        if (s.name == name && s.kind == "function")
        {
            s.paramInfo = paramsStr;
            s.paramTypes = types;
            return;
        }
    }
}

void SymbolTable::updateSymbolValue(string name, string newVal)
{
    Symbol *s = lookup(name);
    if (s)
    {
        s->value = newVal;
    }
}

void SymbolTable::print(ofstream &out)
{
    out << "=== Symbol Table: " << name << " ===" << endl;
    out << (parent ? "Parent Scope: " + parent->name : "Parent Scope: NULL") << endl;
    out << "---------------------------------------------------------------------------------------" << endl;
    out << "Name\t\tType\t\tKind\t\tValue\t\tParams Info" << endl;
    out << "---------------------------------------------------------------------------------------" << endl;
    for (const auto &s : symbols)
    {
        out << s.name << "\t\t" << s.type << "\t\t" << s.kind << "\t\t"
            << s.value << "\t\t" << s.paramInfo << endl;
    }
    out << endl;
}

AnalysisManager manager;

AnalysisManager::AnalysisManager() : currentScope(nullptr) {}

void AnalysisManager::initGlobalScope()
{
    currentScope = new SymbolTable("Global Scope");
    allTables.push_back(currentScope);
}

void AnalysisManager::enterScope(string scopeName)
{
    SymbolTable *newScope = new SymbolTable(scopeName, currentScope);
    allTables.push_back(newScope);
    currentScope = newScope;
}

void AnalysisManager::exitScope()
{
    if (currentScope->parent)
        currentScope = currentScope->parent;
}

bool AnalysisManager::isClassDefined(string className)
{
    return classScopes.find(className) != classScopes.end();
}

Symbol *AnalysisManager::findSymbol(string name)
{
    return currentScope ? currentScope->lookup(name) : nullptr;
}

void AnalysisManager::semanticError(string msg, int lineIdx)
{
    //fprintf(stderr, "Syntax Error line %d\n", lineIdx);
    cerr << "Semantic Error (Line " << lineIdx << "): " << msg << endl;
    exit(1);
}