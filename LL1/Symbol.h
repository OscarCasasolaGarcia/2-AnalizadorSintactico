#ifndef SYMBOL_
#define SYMBOL_
#include <string>
using namespace std;

enum TYPESYM {terminal, noterminal, cadena};
class Symbol{
    private:
        string name;
        TYPESYM type;
        int id;

    public:
        Symbol();
        ~Symbol();
        Symbol(string name, TYPESYM type, int id);

        void setName(string name);
        void setType(TYPESYM type);
        void setId(int id);

        string getName();
        TYPESYM getType();
        int getId();
};

#endif 