#include <iostream>
#include "Scanner.h"
#include "fstream"
using namespace std;
using namespace C_1;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Faltan argumentos" << endl;
        return EXIT_FAILURE;
    }

    filebuf fb;
    fb.open(string(argv[1]), ios::in);
    istream in(&fb);
    Scanner lexer(&in);
    int token = lexer.yylex();

    while (token != 0) {
        cout << "Token: " << token << endl << "Lexema: " << lexer.YYText() << endl;
        token = lexer.yylex();
    }

    fb.close();
    return 0;
}