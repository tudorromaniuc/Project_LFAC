#include "AST.h"
#include <cmath>

ASTNode::ASTNode(string k, string v, string t, ASTNode* l, ASTNode* r) {
    kind = k;
    value = v;
    type = t;
    left = l;
    right = r;
}

EvalResult ASTNode::evaluate() {
    EvalResult res;
    res.type = type;
    res.value = "0";

    if (kind == "literal") {
        res.value = value;
        return res;
    }

    if (kind == "identifier") {
        Symbol* s = manager.findSymbol(value);
        if (s) {
            res.value = (s->value == "-" || s->value == "") ? "0" : s->value;
        }
        return res;
    }

    if (kind == "other") {
        if (type == "int") res.value = "0";
        else if (type == "float") res.value = "0.0";
        else if (type == "bool") res.value = "false";
        else res.value = "";
        return res;
    }

    if (kind == "print") {
        EvalResult val = left->evaluate();
        cout << "[PROGRAM OUTPUT]: " << val.value << endl;
        return val;
    }

    if (kind == "assignment") {
        EvalResult rVal = right->evaluate();
        manager.currentScope->updateSymbolValue(value, rVal.value);
        return rVal;
    }


    if (kind == "operator") {
        EvalResult lRes = left->evaluate();
        EvalResult rRes = right->evaluate();

        
        if (type == "int") {
            int v1 = lRes.getInt();
            int v2 = rRes.getInt();
            int finalVal = 0;

            if (value == "+") finalVal = v1 + v2;
            else if (value == "-") finalVal = v1 - v2;
            else if (value == "*") finalVal = v1 * v2;
            else if (value == "/") finalVal = (v2 != 0) ? v1 / v2 : 0;
            
            res.value = to_string(finalVal);
        }
      
        else if (type == "float") {
            float v1 = lRes.getFloat();
            float v2 = rRes.getFloat();
            float finalVal = 0.0;

            if (value == "+") finalVal = v1 + v2;
            else if (value == "-") finalVal = v1 - v2;
            else if (value == "*") finalVal = v1 * v2;
            else if (value == "/") finalVal = (v2 != 0.0) ? v1 / v2 : 0.0;

            res.value = to_string(finalVal);
        }
       
        else if (type == "bool") {
            float v1 = atof(lRes.value.c_str());
            float v2 = atof(rRes.value.c_str());
            bool finalVal = false;

            if (value == "<") finalVal = v1 < v2;
            else if (value == ">") finalVal = v1 > v2;
            else if (value == "<=") finalVal = v1 <= v2;
            else if (value == ">=") finalVal = v1 >= v2;
            else if (value == "==") finalVal = v1 == v2;
            else if (value == "!=") finalVal = v1 != v2;
            else if (value == "&&") finalVal = (lRes.getBool() && rRes.getBool());
            else if (value == "||") finalVal = (lRes.getBool() || rRes.getBool());

            res.value = finalVal ? "true" : "false";
        }
    }

    return res;
}