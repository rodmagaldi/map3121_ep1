#include "UserGeneratedMatrix.h"

#include <iostream>
#include "math.h"

using namespace std;

UserGeneratedMatrix::UserGeneratedMatrix(int linhas, int colunas, int precisao): Matrix(linhas, colunas, precisao) {
    cout << "Matriz com " << this->nLinhas << " linhas e " << this->nColunas << " colunas: " << endl;
    cout << endl;

//  loop que coloca os valores em this->matriz
    for (int i=0; i<nLinhas; i++) {

//      inicializa vetores dentro do vetor principal
        vector<double> temp;
//
//      loop que  adiciona valores ao vetor interno
        for (int j=0; j<nColunas; j++) {
//
//          inicializa cada valor a ser colocado no vetor interno
            double ntemp;
            cout << "Elemento da linha " << i << " e coluna " << j << ": ";
            cin >> ntemp;

//          coloca o valor obtido no vetor interno
            temp.push_back(ntemp);
        }

//      coloca o vetor interno dentro do vetor externo (adiciona linhas a matriz)
        matriz.push_back(temp);
   }

}

UserGeneratedMatrix::~UserGeneratedMatrix()
{
    //dtor
}
