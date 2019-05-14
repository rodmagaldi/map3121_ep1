#include "MatrixaEx1d.h"

#include <iostream>
#include "math.h"

using namespace std;

MatrixaEx1d::MatrixaEx1d(int precisao): Matrix (20, 3, precisao) {
    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            int ntemp;
            if (j == 0) {
                ntemp = 1;
            } else if (j == 1) {
                ntemp = i+1;
            } else if (j == 2) {
                ntemp = 2*(i+1) - 1;
            }
            temp.push_back(ntemp);
        }
        this->matriz.push_back(temp);
    }
}

MatrixaEx1d::~MatrixaEx1d()
{
    //dtor
}
