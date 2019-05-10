#include "Matrix.h"
#include <iostream>
#include <string>

//utilizado para operacoes de radiciacao e potenciacao
#include <math.h>

//utilizado para definir a precisao nos prints, para as matrizes
//ficarem mais legiveis
#include <bits/stdc++.h>

using namespace std;

//construtor a partir de numero de linhas e colunas predefinidos
Matrix::Matrix(int linhas, int colunas, int precisao){

    //guarda as informacoes de numero de linhas e colunas
    //para terem facil acesso
    this->nLinhas = linhas;
    this->nColunas = colunas;
    this->precisao = precisao;

//    cout << "Matriz com " << this->nLinhas << " linhas e " << this->nColunas << " colunas: " << endl;
//    cout << endl;

//    loop que coloca os valores em this->matriz
//    for (int i=0; i<nLinhas; i++) {
//
//        inicializa vetores dentro do vetor principal
//        vector<double> temp;
//
//        loop que  adiciona valores ao vetor interno
//        for (int j=0; j<nColunas; j++) {
//
//            inicializa cada valor a ser colocado no vetor interno
//            int ntemp;
//            cout << "Elemento da linha " << i << " e coluna " << j << ": ";
//            cin >> ntemp;
//
//            coloca o valor obtido no vetor interno
//            temp.push_back(ntemp);
//        }
//
//        coloca o vetor interno dentro do vetor externo (adiciona linhas a matriz)
//        matriz.push_back(temp);
//    }
}

//destrutor
Matrix::~Matrix() {
    cout << "===== Matriz destruida ======" << endl;
}

//getter de nLinhas
int Matrix::getNLinhas() {
    return this->nLinhas;
}

//getter de nColunas
int Matrix::getNColunas() {
    return this->nColunas;
}

//imprime this->matriz de forma legivel
void Matrix::print() {
    cout << "Matriz: " << endl;

    //loop que realiza a impressao
    for (int i = 0; i < this->nLinhas; i++) {
        cout << "| ";
        for (int j = 0; j < this->nColunas; j++) {
            //imprime cada elemento da matriz com a precisao desejada
            if (matriz[i][j] >= 0) {
                cout << " " << fixed << setprecision(this->precisao) << this->matriz[i][j] << " ";
            } else {
                cout << fixed << setprecision(this->precisao) << this->matriz[i][j] << " ";
            }
        }
        cout << " |" << endl;
    }
    cout << endl;
}

//metodo que realiza a fatoracao QR de this->matriz, segundo o
//algoritmo sugerido pelo enunciado
void Matrix::fatoracaoQR(Matrix* b) {

    for (int k=0; k<this->getNColunas(); k++) {
        for (int j=this->getNLinhas()-1; j>k; j--) {

            //define a linha i a ser utilizada em cada rotacao de givens
            int i = j-1;

            //efetua a rotacao apenas se necessario
            if (this->matriz[j][k] != 0){

                //inicializa alguns valores necessarios para os calculos das rotacoes
                double tau;
                double c;
                double s;

                //primeiro caso (elemento de i > elemento de j, em modulo)
                if (fabs(this->matriz[i][k]) > fabs(this->matriz[j][k])) {

                    //ajusta os valores de c e s para este caso
                    tau = -matriz[j][k]/matriz[i][k];
                    c = 1/sqrt(1+pow(tau, 2));
                    s = c*tau;

                //segundo caso (elemento de j >= elemento de i, em modulo)
                } else {

                    //ajusta os valores de c e s para este case
                    tau = -matriz[i][k]/matriz[j][k];
                    s = 1/sqrt(1+pow(tau, 2));
                    c = s*tau;
                }

                //efetua a rotacao de givens com os parametros ajustados
                this->rotGivens(i, j, c, s);
                b->rotGivens(i, j, c, s);

            }

        }
    }
}

//metodo que realiza a rotacao de givens para os parametros
//especificados c, s, i e j
void Matrix::rotGivens(int i, int j, double c, double s) {

    //loop principal do metodo
    for (int r=0; r<this->matriz[0].size(); r++) {

        //define um valor auxiliar para usar o valor antigo de matriz[j][r]
        double aux = c * this->matriz[i][r] - s * this->matriz[j][r];

        //define os novos valores dos elementos das linhas i e j da matriz
        this->matriz[j][r] = s * this->matriz[i][r] + c * this->matriz[j][r];
        this->matriz[i][r] = aux;
    }
}

void Matrix::resolveSistema(Matrix* b, Matrix* x) {
    for (int k=this->nColunas-1; k>=0; k--) {
        x->matriz[k][0] = b->matriz[k][0];
        for (int j=k; j<this->getNColunas(); j++) {
            x->matriz[k][0] -= this->matriz[k][j] * x->matriz[j][0];
        }
        x->matriz[k][0] /= this->matriz[k][k];
    }
}
