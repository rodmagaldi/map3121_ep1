#include <iostream>

#include "MatrixbEx1a.h"
#include "math.h"
#include "Matrix.h"

using namespace std;

MatrixbEx1a::MatrixbEx1a(int precisao): Matrix(64, 1, precisao) {
    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            temp.push_back(1);
        }
        this->matriz.push_back(temp);
    }
}

MatrixbEx1a::~MatrixbEx1a() {
    //dtor
}
