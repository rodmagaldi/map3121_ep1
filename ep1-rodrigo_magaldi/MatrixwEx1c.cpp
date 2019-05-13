#include "MatrixwEx1c.h"

#include <iostream>
#include "math.h"

using namespace std;


MatrixwEx1c::MatrixwEx1c(int precisao) : Matrix (64, 64, precisao) {
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

MatrixwEx1c::~MatrixwEx1c()
{
    //dtor
}
