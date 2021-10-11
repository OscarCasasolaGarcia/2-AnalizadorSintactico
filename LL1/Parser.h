#ifndef PARSER_H
#define PARSER_H
#include <map>
#include <stack>
#include <vector>
#include <string>
#include "Symbol.h"
#include "Production.h"
#include "Lexico/Lexer.h"
#include "Lexico/tokens.h"
using namespace std;


class Parser{
private:
    map<int, map<int,int>> table;
    map<int, Symbol> syms;
    vector<Production> prods;
    //table[i][j] = k;
    C_1::Lexer *lexer;
    int token;
public: 
    Parser();
    ~Parser();

    void loadSymbols();
    void loadProds();
    void loadTable();
    int parse();
};

#endif // PARSER_H