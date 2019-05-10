#include <iostream>

#include "MatrixEx1a.h"
#include "Matrix.h"
#include "math.h"

using namespace std;

MatrixEx1a::MatrixEx1a(int precisao): Matrix (64, 64, precisao) {

    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            int ntemp;
            if (i == j) {
                ntemp = 2;
            } else if (fabs(i-j) == 1) {
                ntemp = 1;
            } else if (fabs(i-j) > 1) {
                ntemp = 0;
            }
            temp.push_back(ntemp);
        }
        this->matriz.push_back(temp);
    }
}

MatrixEx1a::~MatrixEx1a() {
    //dtor
}
