#include "Parser.h"
#include <iostream>

/* Este programa va a estar derivando por la izquierda */
/* ESTE PROGRAMA ES ITERATIVO */
namespace C_1{
    Parser::Parser(){
    }

    Parser::Parser(Lexer *lexer){
        this->lexer= lexer;
    }
    
    Parser::~Parser(){
    }

    void Parser::programa(){
        declaraciones(); // Se manda llamar la función del símbolo NO terminal
        sentencias(); 
    }

    void Parser::declaraciones(){
        declaracion();
        declaraciones_();
    }

    void Parser::declaraciones_(){
        while(token == INT || token == FLOAT){ // Lo que hay en el conjunto FIRST de declaración (int, float)
            declaracion();
        }
    }

    void Parser::declaracion(){
        tipo();
        lista_var();
        eat(PYC); // Como es un símbolo terminal, se debe consumir
    }

    void Parser::tipo(){
        switch (token){
            case INT:
                eat(INT); // Como es un símbolo terminal, se debe consumir           
                break;
            case FLOAT:
                eat(FLOAT); // Como es un símbolo terminal, se debe consumir
                break;
            default:
                error("El token debe ser INT o FLOAT"); 
                break;
        }
    }
    void Parser::lista_var(){
        eat(ID); // Como es un símbolo terminal, se debe consumir
        lista_var_();
    }

    void Parser::lista_var_(){
        while(token==COMA){
            eat(COMA);
            eat(ID);
        }
    }

    void Parser::sentencias(){
        sentencia();
        sentencias_();
    } 

    //En este caso se utiliza el FIRST del símbolo no terminal para saber qué debo de hacer con el token que 
    //estoy recibiendo 
    void Parser::sentencias_(){
        while(token == ID || token == IF || token == WHILE){ // Lo que hay en el conjunto FIRST de sentencia
            sentencia();
        }
    }

    void Parser::sentencia(){
        switch (token){
            case ID:
                eat(ID);
                eat(ASIG);
                expresion();
                eat(PYC);
                break;

            case IF:
                eat(IF);
                eat(LPAR);
                expresion();
                eat(RPAR);
                sentencias();
                eat(ELSE);
                sentencias();
                break;

            case WHILE:
                eat(WHILE);
                eat(LPAR);
                expresion();
                eat(RPAR);
                sentencias();
                break;
        
            default:
                error("Se esperaba un ID o un IF o un WHILE");
                break;
        }
    }

    void Parser::expresion(){
        termino();
        expresion_();
    }

    void Parser::expresion_(){
        while (token == MAS || token == MENOS){
            if(token == MAS) eat(MAS); //token = lexer->yylex();
            else if(token == MENOS) eat(MENOS); //token = lexer->yylex(); 
            termino();
        }
    }

    void Parser::termino(){
        factor();
        termino_();
    }

    void Parser::termino_(){
        while (token == MUL || token == DIV){
            if(token == DIV) eat(DIV); //token = lexer->yylex();
            else if(token == MUL) eat(MUL); //token = lexer->yylex(); 
            factor();
        }
    }

    void Parser::factor(){
        switch(token){
            case ID:
                eat(ID);
                break;
            case NUMERO:
                eat(NUMERO);
                break;
            case LPAR:
                eat(LPAR);
                expresion();
                eat(RPAR);
            default:
                error("Se esperaba ID o NUMERO o LPAR");
        }
    }

    void Parser::eat(int t){
        if(token == t){
            token = lexer->yylex(); // Se consume el token
        }else
            error("Se esperaba otro token");
    }

    void Parser::error(string msg){
        /* cout<<"ERROR DE SINTAXIS "<<msg<< " en la línea "<< lexer->getLine()<<endl; */
        cout<<"ERROR DE SINTAXIS ";
        exit(-1);
    }

    void Parser::parse(){ 
        token = lexer->yylex(); 
        programa(); // Se manda llamar la función del símbolo inicial
        if(token == 0){
            cout<<"La cadena es aceptada"<<endl;
        }else{
            cout<<"La cadena no pertenece al lenguaje generado por la gramática"<<endl;
        }
    }
}