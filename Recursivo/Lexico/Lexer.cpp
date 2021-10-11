#include "Lexer.h"
#include "tokens.h"
#include <iostream>

namespace C_1{
    Lexer::Lexer(/* args */){
    }

    Lexer::Lexer(string file){
        ifstream afd(file); //abre el archivo que contiene el automata
        string line, aceptar; 
        stringstream s; 
        int ren=0, col=0, estado;  //es el estado actual, ren es la fila, col es la columna
        getline(afd, line); //obtiene la primera linea del automata
        s = stringstream(line); //convierte la linea en un stringstream
        s >> num_estados; //obtiene el numero de estados del automata
        s >> num_simbolos; //obtiene el numero de simbolos del automata

        tabla_transiciones = new int*[num_estados];
        for (int i = 0; i < num_estados; i++){
            tabla_transiciones[i] = new int[num_simbolos];
        }
        aceptacion = new bool[num_estados]; //crea un arreglo de booleanos para saber si estado de aceptacion o no

        while(ren < num_estados){
            getline(afd, line); //obtiene la linea del automata
            s = stringstream(line); //convierte la linea en un stringstream
            while (col < num_simbolos){ //mientras no se llegue al final de la linea
                s >> estado; //obtiene el estado actual 
                tabla_transiciones[ren][col++] = estado; //guarda el estado actual en la tabla de transiciones
            }
            s >> aceptar; //obtiene si es estado de aceptacion o no
            aceptar == "true" ? aceptacion[ren] = true : aceptacion[ren] = false; 
            ren++; //incrementa la fila
            col = 0; 
        }
        afd.close();
        simbolos['+'] = 0;
        simbolos['-'] = 1;
        simbolos['*'] = 2;
        simbolos['/'] = 3; 
        simbolos['='] = 4;
        simbolos['('] = 5;
        simbolos[')'] = 6;
        simbolos[';'] = 7;
        simbolos[','] = 8;
        simbolos['0'] = 9;
        simbolos['1'] = 9;
        simbolos['2'] = 9;
        simbolos['3'] = 9;
        simbolos['4'] = 9;
        simbolos['5'] = 9;
        simbolos['6'] = 9;
        simbolos['7'] = 9;
        simbolos['8'] = 9;
        simbolos['9'] = 9;
        simbolos['e'] = 10;
        simbolos['w'] = 11;
        simbolos['l'] = 12; 
        simbolos['s'] = 13;
        simbolos['h'] = 14;
        simbolos['n'] = 15;
        simbolos['t'] = 16;
        simbolos['o'] = 17;
        simbolos['a'] = 18;
        simbolos['i'] = 19;
        simbolos['f'] = 20;

        simbolos['b'] = 21;
        simbolos['c'] = 21;
        simbolos['d'] = 21;
        simbolos['g'] = 21;
        simbolos['j'] = 21;
        simbolos['k'] = 21;
        simbolos['m'] = 21;
        simbolos['p'] = 21;
        simbolos['q'] = 21;
        simbolos['r'] = 21;
        simbolos['u'] = 21;
        simbolos['v'] = 21;
        simbolos['x'] = 21;
        simbolos['y'] = 21;
        simbolos['z'] = 21;
        simbolos['_'] = 21;
        simbolos['A'] = 21;
        simbolos['B'] = 21;
        simbolos['C'] = 21;
        simbolos['D'] = 21;
        simbolos['F'] = 21;
        simbolos['G'] = 21;
        simbolos['H'] = 21;
        simbolos['I'] = 21;
        simbolos['J'] = 21;
        simbolos['K'] = 21;
        simbolos['L'] = 21;
        simbolos['M'] = 21;
        simbolos['N'] = 21;
        simbolos['O'] = 21;
        simbolos['P'] = 21;
        simbolos['Q'] = 21;
        simbolos['R'] = 21;
        simbolos['S'] = 21;
        simbolos['T'] = 21;
        simbolos['U'] = 21;
        simbolos['V'] = 21;
        simbolos['W'] = 21;
        simbolos['X'] = 21;
        simbolos['Y'] = 21;
        simbolos['Z'] = 21;

        simbolos['.'] = 22;
        simbolos['\n'] = 23;
        simbolos[' '] = 23;
        simbolos['\t'] = 23;
        simbolos['\r'] = 23;
        simbolos['E'] = 24;

    }

    Lexer::~Lexer(){ //destructor: libera la memoria que se le asignó pero en forma inversa
        for (int i = 0; i < num_estados; i++){
            delete tabla_transiciones[i]; //libera la memoria de cada fila
        }
        delete tabla_transiciones; //libera la memoria de la tabla de transiciones
        delete aceptacion;  //libera la memoria del arreglo de estados de aceptacion
    }

    void Lexer::getChar(){
        yyin.get(c); //obtiene el siguiente caracter del archivo
    }

    bool Lexer::openFile(string file){
        yyin.open(file, ios::in);
        if(!yyin.is_open()){
            cerr << "Error al abrir el archivo" << file << " " << endl;
            return EXIT_FAILURE;
        }
        getChar(); //obtiene el primer caracter del archivo
    }

    void Lexer::closeFile(){
        yyin.close(); //cierra el archivo
    }

    int Lexer::yylex(){ //funcion que obtiene el token
        int q = 0; //estado actual del automata
        int cc;
        yytext = ""; //inicializa el string que almacena el token
        if (yyin.eof()) return 0; //si es el final del archivo
        while(true){
            cc = simbolos[c]; //obtiene el codigo del caracter actual
            if (tabla_transiciones[q][cc] != -1){ //si no hay transicion
                q = tabla_transiciones[q][cc]; //obtiene el codigo del caracter actual
                yytext += c; //agrega el caracter al string que almacena el token
                getChar(); //obtiene el siguiente carácter
                if (yyin.eof()) return token(q);

            }else{ //si hay transicion
                if (aceptacion[q]){ //si el estado actual es de aceptacion
                    if (q == 17){ //si el estado actual es 17 (espacios en blanco)
                        q = 0; //se vuelve al estado inicial
                        yytext = ""; //se reinicia el string que almacena el token
                    }else return token(q); //retorna el token
                }else{ //si no es de aceptacion
                    return ERROR; //retorna el token de error
                }
            }
        }
    }

    int Lexer::token (int q){ //funcion que retorna el token
        switch (q){
            case 1:
                return MAS;
            case 2: 
                return MENOS;
            case 3: 
                return MUL;
            case 4: 
                return DIV;
            case 5: 
                return ASIG;
            case 6: 
                return LPAR;
            case 7: 
                return RPAR;
            case 8: 
                return PYC;
            case 9: 
                return COMA;
            case 10: case 19: case 30: 
                return NUMERO;
            case 12: case 13: case 14: case 15: case 16: case 20: case 21: case 22: case 23: case 26: case 27: case 28: case 31: case 33: 
                return ID;
            case 18: 
                return IF;
            case 17: 
                return ESP;
            case 25: 
                return INT;
            case 32: 
                return ELSE;
            case 34: 
                return FLOAT;
            case 35: 
                return WHILE;
            default: 
                return -1;
        }
    }

    string Lexer::getYytext(){
        return yytext;
    }

    void Lexer::printTable(){ //funcion que imprime la tabla de transiciones
        for (int i = 0; i < num_estados; i++){
            for (int j = 0; j < num_simbolos; j++){
                cout << tabla_transiciones[i][j] << "\t";
            }
            cout << endl;
        }
        
        // Imprime los estados de aceptacion
        for (int i = 0; i < num_estados; i++){
            cout << aceptacion[i] << "\t";
        }
        cout << endl;
    }

}

