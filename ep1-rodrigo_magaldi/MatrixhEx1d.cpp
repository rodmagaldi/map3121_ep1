#include "MatrixhEx1d.h"

MatrixhEx1d::MatrixhEx1d(int precisao): Matrix(17, 3, precisao) {
    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            temp.push_back(0);
        }
        this->matriz.push_back(temp);
    }
}

MatrixhEx1d::~MatrixhEx1d()
{
    //dtor
}
