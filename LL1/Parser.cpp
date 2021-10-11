#include "Parser.h"
#include <iostream>

void Parser::loadSymbols(){
    syms[0] = Symbol("expresion",noterminal,0);
    syms[1] = Symbol("expresion_",noterminal,1);
    syms[2] = Symbol("termino",noterminal,2);
    syms[3] = Symbol("termino_",noterminal,3);
    syms[4] = Symbol("factor",noterminal,4);

    syms[5] = Symbol("MAS",terminal,1);
    syms[6] = Symbol("MUL",terminal,2);
    syms[7] = Symbol("LPAR",terminal,3);
    syms[8] = Symbol("RPAR",terminal,4);
    syms[9] = Symbol("ID",terminal,5);
    syms[10] = Symbol("$",terminal,0);
    syms[11] = Symbol("EPS",cadena,0);
}

// E -> T E'
// E' -> + T E' | ε
// T -> F T'
// T' -> * F T' | ε
// F -> (E) | id

void Parser::loadProds(){
    vector<int> s = {2,1}; // E -> T E'
    prods[0] = Production(0,s);
    s.clear();

    s = {5,2,1};  // E -> + T E'
    prods[1] = Production(1,s);
    s.clear();

    s = {11};  // ε
    prods[2] = Production(1,s);
    s.clear();

    s = {4,3};  // T -> F T'
    prods[3] = Production(2,s);
    s.clear();

    s = {5,4,3};  // T -> * F T'
    prods[4] = Production(3,s);
    s.clear();

    s = {11};  // ε
    prods[5] = Production(3,s);
    s.clear();

    s = {7,0,8};  // F -> (E)
    prods[6] = Production(4,s);
    s.clear();

    s = {9};  // F -> id
    prods[7] = Production(4,s);
    s.clear();
}

void Parser::loadTable(){
    table[0][3] = 0;
    table[0][5] = 0;
    
    table[1][1] = 1;
    table[1][0] = 2;
    table[1][4] = 2;

    table[2][3] = 3;
    table[2][5] = 3;

    table[3][2] = 4;
    table[3][1] = 5;
    table[3][3] = 5;
    table[3][5] = 5;

    table[4][3] = 6;
    table[4][5] = 7;
}

int Parser::parse(){
    stack<Symbol> pila;
    token = lexer->yylex();
    pila.push(syms[10]);
    pila.push(syms[0]);
    while (pila.top().getName()!="$"){
        if(pila.top().getType()==noterminal){

        }else if(pila.top().getType()==terminal){

        }
}
