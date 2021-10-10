#ifndef PARSER_H
#define PARSER_H
#include "C:/Users/johnc/OneDrive - UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO/INGENIERIA EN COMPUTACIÓN/7°SEMESTRE/Compiladores/Proyectos/Proyecto1/1AL/Lexer.h"
#include <string>
using namespace std;
#include "C:/Users/johnc/OneDrive - UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO/INGENIERIA EN COMPUTACIÓN/7°SEMESTRE/Compiladores/Proyectos/Proyecto1/1AL/tokens.h"

namespace C_1{
    class Parser{
    private:
        Lexer *lexer; // pointer to lexer
        int token; // token actual
    public:
        Parser(); // constructor
        Parser(Lexer *lexer); // constructor
        ~Parser(); // destructor
        void programa(); // programa -> declaraciones sentencias
        void declaraciones(); // declaraciones -> declaracion declaraciones'
        void declaraciones_(); 
        void declaracion();
        void tipo();
        void lista_var();
        void lista_var_();
        void sentencias();
        void sentencias_();
        void sentencia();
        void expresion();
        void expresion_();
        void termino();
        void termino_();
        void factor();

        void eat(int t); //eat a token
        void error(string msg); //report an error
        void parse(); // función para iniciar el análisis sintáctico
    };
} // namespace C_1

#endif

