#include <iostream>

#include "MatrixxEx1b.h"
#include "math.h"

using namespace std;

MatrixxEx1b::MatrixxEx1b(int precisao): Matrix (17, 1, precisao) {
    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            temp.push_back(0.0);
        }
        this->matriz.push_back(temp);
    }
}

MatrixxEx1b::~MatrixxEx1b()
{
    //dtor
}
