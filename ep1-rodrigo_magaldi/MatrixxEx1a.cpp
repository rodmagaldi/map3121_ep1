#include <iostream>

#include "MatrixxEx1a.h"
#include "math.h"
#include "Matrix.h"

using namespace std;


MatrixxEx1a::MatrixxEx1a(int precisao): Matrix(64, 1, precisao) {
    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            temp.push_back(0);
        }
        this->matriz.push_back(temp);
    }
}

MatrixxEx1a::~MatrixxEx1a()
{
    //dtor
}
