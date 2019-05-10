#include <iostream>

#include "MatrixbEx1b.h"
#include "math.h"

MatrixbEx1b::MatrixbEx1b(int precisao): Matrix(20, 1, precisao) {
    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            temp.push_back(i+1);
        }
        this->matriz.push_back(temp);
    }
}

MatrixbEx1b::~MatrixbEx1b()
{
    //dtor
}
