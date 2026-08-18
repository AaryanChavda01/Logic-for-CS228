#include "prop.h"

// atomic proposition functions
atom_prop::atom_prop(){
    name = "TOP";
    value = true;
}
atom_prop::atom_prop(string s){
    s == "" ? name = "TOP" : name = s;
    value = true;
}
atom_prop::atom_prop(string s, bool v){
    s == "" ? name = "EMPTY" : name = s;
    value = v;
}

// logical connectives for atomic propositions
prop atom_prop::operator~(){
    prop neg_p;
    neg_p.formula = "(~"+name+")";
    neg_p.valid = true;
    neg_p.variables.insert(name);
    return neg_p;
}
prop atom_prop::operator+(atom_prop q){
    prop pORq;
    pORq.formula = "("+name+"+"+q.name+")";
    pORq.valid = true;
    pORq.variables.insert(name);
    pORq.variables.insert(q.name);
    return pORq;
}
prop atom_prop::operator*(atom_prop q){
    prop pANDq;
    pANDq.formula = "("+name+"*"+q.name+")";
    pANDq.valid = true;
    pANDq.variables.insert(name);
    pANDq.variables.insert(q.name);
    return pANDq;
}
prop atom_prop::operator>(atom_prop q){
    prop pIMPq;
    pIMPq.formula = "("+name+"->"+q.name+")";
    pIMPq.valid = true;
    pIMPq.variables.insert(name);
    pIMPq.variables.insert(q.name);
    return pIMPq;
}
prop atom_prop::operator^(atom_prop q){
    prop pXORq;
    pXORq.formula = "("+name+"^"+q.name+")";
    pXORq.valid = true;
    pXORq.variables.insert(name);
    pXORq.variables.insert(q.name);
    return pXORq;
}
prop atom_prop::operator-(atom_prop q){
    prop pIFFq;
    pIFFq.formula = "("+name+"<->"+q.name+")";
    pIFFq.valid = true;
    pIFFq.variables.insert(name);
    pIFFq.variables.insert(q.name);
    return pIFFq;
}

// functions for propositional formulae
prop::prop(){
    formula = "";
    valid = false;
}
prop::prop(atom_prop p){
    formula = p.name;
    variables.insert(p.name);
    valid = true;
}
prop::prop(string s){
    formula = s;
    valid = validate();
}
bool prop::validate(){
    // Determines valid iff formula belongs to Prop
    // Also adds propositions to set "variables"
    int f_sz = formula.size();
    if(f_sz == 0){
        // "" not allowed
        return false;
    }
    if(formula[0] == '('){
        if(formula[f_sz-1] == ')'){
            // logic part (connective)
            int brackets = 0;
            for(int i=1; i<f_sz-1; i++){
                char c = formula[i];
                if(c == '('){
                    brackets++;
                }
                else if(c == ')'){
                    brackets--;
                }
                else if(brackets == 0){
                    if(c == '~'){
                        if(i == 1){
                            // check inner prop
                            prop p(formula.substr(2, f_sz-3));
                            if(p.valid){
                                variables.insert(p.variables.begin(),p.variables.end());
                            }
                            return p.valid;
                        }
                        else{
                            return false;
                        }
                    }
                    else if(c == '^' || c == '+' || c == '*'){
                        // check inner props
                        prop p(formula.substr(1, i-1));
                        prop q(formula.substr(i+1, f_sz-i-2));
                        if(p.valid && q.valid){
                            variables.insert(p.variables.begin(),p.variables.end());
                            variables.insert(q.variables.begin(),q.variables.end());
                        }
                        return p.valid && q.valid;
                    }
                    else if(c == '-' && i < f_sz-2 && formula[i+1] == '>'){
                        // check inner props
                        prop p(formula.substr(1, i-1));
                        prop q(formula.substr(i+2, f_sz-i-3));
                        if(p.valid && q.valid){
                            variables.insert(p.variables.begin(),p.variables.end());
                            variables.insert(q.variables.begin(),q.variables.end());
                        }
                        return p.valid && q.valid;
                    }
                    else if(
                        c == '<' && i < f_sz-3 &&
                        formula[i+1] == '-' && formula[i+2] == '>'
                    ){
                        // check inner props
                        prop p(formula.substr(1, i-1));
                        prop q(formula.substr(i+3, f_sz-i-4));
                        if(p.valid && q.valid){
                            variables.insert(p.variables.begin(),p.variables.end());
                            variables.insert(q.variables.begin(),q.variables.end());
                        }
                        return p.valid && q.valid;
                    }
                }
                else if(brackets < 0){
                    return false;
                }
            }
            if(brackets != 0){
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        // check no connectives
        for(int i=0; i<f_sz; i++){
            char c = formula[i];
            if(
                c == ')' || c == '(' || c == '~' ||
                c == '+' || c == '*' || c == '^' ||
                (c == '-' && i < f_sz - 1 && formula[i+1] == '>') ||
                (c == '<' && i < f_sz - 2 && formula[i+1] == '-' && formula[i+2] == '>')
            ){
                return false;
            }
        }
        variables.insert(formula);
        return true;
    }
    return false;
}

// logical connectives for propositional formulae
prop prop::operator~(){
    prop neg_F;
    neg_F.formula = "(~"+formula+")";
    neg_F.valid = valid;
    neg_F.variables = variables;
    return neg_F;
}
prop prop::operator+(atom_prop q){
    prop pORq;
    pORq.formula = "("+formula+"+"+q.name+")";
    pORq.valid = valid;
    pORq.variables = variables;
    pORq.variables.insert(q.name);
    return pORq;
}
prop prop::operator*(atom_prop q){
    prop pANDq;
    pANDq.formula = "("+formula+"*"+q.name+")";
    pANDq.valid = valid;
    pANDq.variables = variables;
    pANDq.variables.insert(q.name);
    return pANDq;
}
prop prop::operator>(atom_prop q){
    prop pIMPq;
    pIMPq.formula = "("+formula+"->"+q.name+")";
    pIMPq.valid = valid;
    pIMPq.variables = variables;
    pIMPq.variables.insert(q.name);
    return pIMPq;
}
prop prop::operator^(atom_prop q){
    prop pXORq;
    pXORq.formula = "("+formula+"^"+q.name+")";
    pXORq.valid = valid;
    pXORq.variables = variables;
    pXORq.variables.insert(q.name);
    return pXORq;
}
prop prop::operator-(atom_prop q){
    prop pIFFq;
    pIFFq.formula = "("+formula+"<->"+q.name+")";
    pIFFq.valid = valid;
    pIFFq.variables = variables;
    pIFFq.variables.insert(q.name);
    return pIFFq;
}
prop prop::operator+(prop q){
    prop pORq;
    pORq.formula = "("+formula+"+"+q.formula+")";
    pORq.valid = valid && q.valid;
    pORq.variables = variables;
    pORq.variables.insert(variables.begin(), variables.end());
    return pORq;
}
prop prop::operator*(prop q){
    prop pANDq;
    pANDq.formula = "("+formula+"*"+q.formula+")";
    pANDq.valid = valid && q.valid;
    pANDq.variables = variables;
    pANDq.variables.insert(variables.begin(), variables.end());
    return pANDq;
}
prop prop::operator>(prop q){
    prop pIMPq;
    pIMPq.formula = "("+formula+"->"+q.formula+")";
    pIMPq.valid = valid && q.valid;
    pIMPq.variables = variables;
    pIMPq.variables.insert(variables.begin(), variables.end());
    return pIMPq;
}
prop prop::operator^(prop q){
    prop pXORq;
    pXORq.formula = "("+formula+"^"+q.formula+")";
    pXORq.valid = valid && q.valid;
    pXORq.variables = variables;
    pXORq.variables.insert(variables.begin(), variables.end());
    return pXORq;
}
prop prop::operator-(prop q){
    prop pIFFq;
    pIFFq.formula = "("+formula+"<->"+q.formula+")";
    pIFFq.valid = true;
    pIFFq.variables = variables;
    pIFFq.variables.insert(variables.begin(), variables.end());
    return pIFFq;
}