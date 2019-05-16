#include "RandomPositiveMatrix.h"

#include <iostream>
#include "math.h"
#include <ctime>
#include <cstdlib>

using namespace std;

RandomPositiveMatrix::RandomPositiveMatrix(int nl, int nc, int p): Matrix (nl, nc, p) {
    srand(time(0));
    for (int i=0; i<nLinhas; i++) {
        vector<double> temp;
        for (int j=0; j<nColunas; j++) {
            temp.push_back((rand() % 10) + 1);
        }
        this->matriz.push_back(temp);
   }
}

RandomPositiveMatrix::~RandomPositiveMatrix()
{
    //dtor
}
