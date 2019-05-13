#include "MatrixhEx1c.h"

MatrixhEx1c::MatrixhEx1c(int precisao): Matrix(64, 3, precisao) {
    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            temp.push_back(0);
        }
        this->matriz.push_back(temp);
    }
}

MatrixhEx1c::~MatrixhEx1c()
{
    //dtor
}
