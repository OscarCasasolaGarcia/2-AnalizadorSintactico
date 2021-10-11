%{
#include <iostream>
#include <string>
using namespace std;

#include "tokens.h"
#include "Scanner.h"

%}

%option c++
%option outfile="Scanner.cpp"
%option yyclass = "C_1::Scanner"
%option case-insensitive


INTEGER [0-9]
FLOTANTE [0-9]*.[0-9]+([Ee][+-]?[0-9]+)?
ID [a-zA-Z_][A-Za-z0-9_]*
ESP [ \t\n\r]

%% 
"+" { return MAS; }
"-" { return MENOS; }
"*" { return MUL; }
"/" { return DIV; }
"=" { return ASIG; }
"(" { return LPAR; }
")" { return RPAR; }
"," { return COMA; }
";" { return PYC; }

"if" { return IF; }
"else" { return ELSE; }
"while" { return WHILE;}
"int" { return INT; }
"float" { return FLOAT; }


{ID} { return ID; }
{ESP} { }
{INTEGER} { return NUMERO; }
{FLOTANTE} { return NUMERO; }

. { cout<<"ERROR LEXICO"<<yytext<<endl;}

%%

int yyFlexLexer::yywrap(){
    return 1;
}