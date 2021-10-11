#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <vector>
using namespace std;

class Production{
    private:
        int head;
        vector<int> body;

    public:
        Production();
        Production(int head, vector<int> body);
        ~Production();
};

Production::Production(){
}

Production::~Production(){
}

#endif