#ifndef LEXER_H
#define LEXER_H
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

/* Programa que hace el análisis léxico: LEXER */
namespace C_1{
    class Lexer{
    private:
        const int ERROR = -1;
        //const int ACEPTAR = 0;
        ifstream yyin; // Objeto para el archivo de entrada
        int **tabla_transiciones; // Tabla de transiciones
        bool *aceptacion; // Arreglo que contiene los estados de aceptación
        string yytext; // Buffer donde vamos almacenando lo que se va leyendo
        int yyline; //Contador de líneas
        char c; // Apuntador para el caracter de entrada
        int num_estados, num_simbolos; // Número de estados y número de símbolos
        map<char, int> simbolos; // Mapa que asocia los símbolos con el número de columna en la tabla de transiciones
    
    public:
        Lexer(); //Constructor 
        Lexer(string file); //Constructor que lee un archivo con la información del automata
        ~Lexer(); //Destructor

        bool readAFD(string file);
        void getChar(); 
        bool openFile(string file); //Abre el archivo
        void closeFile(); //Cierra el archivo
        int yylex(); // Función que retorna los tokens
        void printTable(); //Imprime la tabla de transiciones
        int token(int estado); //Retorna el token correspondiente a un estado
        string getYytext(); //Retorna el lexema
    };

}

#endif