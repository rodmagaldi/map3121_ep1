#include <iostream>

#include "MatrixEx1b.h"
#include "Matrix.h"
#include "math.h"

using namespace std;

MatrixEx1b::MatrixEx1b(int precisao): Matrix(20, 17, precisao) {

    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            double ntemp;
            if (fabs(i-j) <= 4) {
                ntemp = 1.0/(i+1+j);
            } else if(fabs(i-j) > 4){
                ntemp = 0;
            }
            temp.push_back(ntemp);
        }

        this->matriz.push_back(temp);
    }
}

MatrixEx1b::~MatrixEx1b() {
    //dtor
}
