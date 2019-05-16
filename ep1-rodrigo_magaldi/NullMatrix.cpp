#include "NullMatrix.h"

#include <iostream>
#include "math.h"

using namespace std;

NullMatrix::NullMatrix(int linhas, int colunas, int precisao): Matrix(linhas, colunas, precisao) {
    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            temp.push_back(0.0);
        }
        this->matriz.push_back(temp);
   }
}

NullMatrix::~NullMatrix()
{
    //dtor
}
