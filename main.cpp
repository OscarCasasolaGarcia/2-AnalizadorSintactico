#include <iostream>
#include "C:/Users/johnc/OneDrive - UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO/INGENIERIA EN COMPUTACIÓN/7°SEMESTRE/Compiladores/Proyectos/Proyecto1/1AL/Lexer.h"
#include "Parser.h"
#include "C:/Users/johnc/OneDrive - UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO/INGENIERIA EN COMPUTACIÓN/7°SEMESTRE/Compiladores/Proyectos/Proyecto1/1AL/tokens.h"
using namespace std;
using namespace C_1;

int main(int argc, char *argv[]){
    if(argc <2){
        cout<<"Faltan argumentos"<<endl;
        return EXIT_FAILURE;
    }
    Lexer lexer("afd");
    lexer.openFile(string(argv[1]));
    Parser parser(&lexer);
    parser.parse();
    lexer.closeFile();
    //lexer.printTable();
    return 0;
}
