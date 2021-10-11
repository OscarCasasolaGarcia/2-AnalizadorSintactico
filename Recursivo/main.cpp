#include <iostream>
#include "Lexico/Lexer.h"
#include "Parser.h"
#include "Lexico/tokens.h"
using namespace std;
using namespace C_1;

int main(int argc, char *argv[]){
    if(argc <2){
        cout<<"Faltan argumentos"<<endl;
        return EXIT_FAILURE;
    }
    Lexer lexer("Lexico/afd");
    lexer.openFile(string(argv[1]));
    Parser parser(&lexer);
    parser.parse();
    lexer.closeFile();
    //lexer.printTable();
    return 0;
}

/* PARA COMPILAR: g++ main.cpp Parser.cpp Lexico/Lexer.cpp -o parser */
/* PARA EJECUTAR: ./parser prueba */
/* PARA EJECUTAR EL PROGRAMA ITERATIVO: g++ main.cpp Parser2.cpp Lexico/Lexer.cpp -o parser */
/* PARA EJECUTAR EL PROGRAMA RECURSIVO: ./parser prueba */

