#include <iostream>
#include <vector>
#include <math.h>
#include "Matrix.h"

#include "MatrixEx1a.h"
#include "MatrixbEx1a.h"
#include "MatrixxEx1a.h"

#include "MatrixEx1b.h"
#include "MatrixbEx1b.h"
#include "MatrixxEx1b.h"

#include "MatrixwEx1c.h"
#include "MatrixaEx1c.h"
#include "MatrixhEx1c.h"

#include "MatrixwEx1d.h"
#include "MatrixaEx1d.h"
#include "MatrixhEx1d.h"

#include "RandomPositiveMatrix.h"
#include "UserGeneratedMatrix.h"
#include "NullMatrix.h"

#define CASAS_DECIMAIS 3
#define EPSILON 0.00001
#define ITMAX 100

#include <fstream>

using namespace std;

void exercicioUmA() {

    cout << "===== Bem vindo ao exercicio 1a =====" << endl << endl;
    cout << endl;

    MatrixEx1a* w = new MatrixEx1a(CASAS_DECIMAIS);
    MatrixbEx1a* b = new MatrixbEx1a(CASAS_DECIMAIS);
    MatrixxEx1a* x = new MatrixxEx1a(CASAS_DECIMAIS);

    w->fatoracaoQR(b);
    w->resolveSistema(b, x);

    w->print();
    b->print();
    x->print();

    Matrix* a = w->multiplica(x);

    a->print();

    delete w;
    delete x;
    delete b;
}

void exercicioUmB() {

    cout << "===== Bem vindo ao exercicio 1b =====" << endl << endl;
    cout << endl;

    MatrixEx1b* w = new MatrixEx1b(CASAS_DECIMAIS);
    MatrixbEx1b* b = new MatrixbEx1b(CASAS_DECIMAIS);
    MatrixxEx1b* x = new MatrixxEx1b(CASAS_DECIMAIS);

    w->print();
    b->print();
    x->print();

    w->fatoracaoQR(b);
    w->resolveSistema(b, x);

    w->print();
    b->print();
    x->print();

    Matrix* mult = w->multiplica(x);
    mult->print();

    delete w;
    delete x;
    delete b;
    delete mult;
}

void exercicioUmC() {

    cout << "===== Bem vindo ao exercicio 1c =====" << endl << endl;
    cout << endl;

    MatrixwEx1c* w = new MatrixwEx1c(CASAS_DECIMAIS);
    MatrixaEx1c* a = new MatrixaEx1c(CASAS_DECIMAIS);
    MatrixhEx1c* h = new MatrixhEx1c(CASAS_DECIMAIS);

    w->print();
    a->print();
    h->print();

    w->fatoracaoQR(a);
    w->resolveMultiplosSistemas(a, h);

    w->print();
    a->print();
    h->print();

    Matrix* mult = w->multiplica(h);
    mult->print();

    delete w;
    delete a;
    delete h;
    delete mult;

}

void exercicioUmD() {

    cout << "===== Bem vindo ao exercicio 1d =====" << endl << endl;
    cout << endl;

    MatrixwEx1d* w = new MatrixwEx1d(CASAS_DECIMAIS);
    MatrixaEx1d* a = new MatrixaEx1d(CASAS_DECIMAIS);
    MatrixhEx1d* h = new MatrixhEx1d(CASAS_DECIMAIS);

    w->print();
    a->print();
    h->print();

    w->fatoracaoQR(a);
    w->resolveMultiplosSistemas(a, h);

    w->print();
    a->print();
    h->print();

    Matrix* mult = w->multiplica(h);
    mult->print();

    delete w;
    delete a;
    delete h;
    delete mult;

}

void auxiliarNormalizaColunas(Matrix* m) {

    for (int j=0; j<m->getNColunas(); j++) {

        double soma = 0;

        for (int i=0; i<m->getNLinhas(); i++) {
            soma += pow(m->matriz[i][j], 2);
        }
        soma = sqrt(soma);

        for (int i=0; i<m->getNLinhas(); i++) {
            m->matriz[i][j] = m->matriz[i][j]/soma;
        }

    }

}

void auxiliarTornaPositivo(Matrix* m) {
    for (int i=0; i<m->getNLinhas(); i++) {
        for (int j=0; j<m->getNColunas(); j++) {
            if (m->matriz[i][j] < 0) {
                m->matriz[i][j] = 0;
            }
        }
    }
}

void exercicioDois() {
    cout << "===== Bem vindo ao exercicio 2 =====" << endl << endl;

    int n, m, p;

    //escolhe n
    cout << "Numero de linhas da sua matriz: ";
    cin >> n;
    cout << endl;

    //escolhe m
    cout << "Numero de colunas da sua matriz: ";
    cin >> m;
    cout << endl;

    //escolhe um p valido
    do {
        cout << "Escolha um valor de p valido (menor que numero de linhas e colunas): ";
        cin >> p;
        cout << endl;
    } while (p>=m || p>=n || p<=0);

    //gera matriz a
    UserGeneratedMatrix* aAux = new UserGeneratedMatrix(n, m, CASAS_DECIMAIS);
    Matrix* a = dynamic_cast<Matrix*>(aAux);
    cout << "A" << endl;
    a->print();

    //copia matriz a
    Matrix* aCopia = a->geraCopia();
    cout << "A COPIA" << endl;
    aCopia->print();

    //gera matriz aleatoria positiva w
    RandomPositiveMatrix* wAux = new RandomPositiveMatrix(n, p, CASAS_DECIMAIS);
    Matrix* w = dynamic_cast<Matrix*>(wAux);
    cout << "W" << endl;
    w->print();

    //gera matriz nula h que sera resolvida
    NullMatrix* hAux = new NullMatrix(p, m, CASAS_DECIMAIS);
    Matrix* h = dynamic_cast<Matrix*>(hAux);
    cout << "H" << endl;
    h->print();

    //inicializa o contador de iteracoes

    for(int contador = 0; contador<ITMAX && aCopia->calculaDiferenca(w->multiplica(h)) > EPSILON; contador++) {

        a = aCopia->geraCopia();

        //normaliza as colunas de w
        auxiliarNormalizaColunas(w);

        //resolve o sistema wh = a
        w->fatoracaoQR(a);
        w->resolveMultiplosSistemas(a, h);

//        cout << "A DEPOIS" << endl;
//        a->print();
//
//        cout << "W DEPOIS" << endl;
//        w->print();
//
//        cout << "H DEPOIS" << endl;
//        h->print();

        auxiliarTornaPositivo(h);
//        cout << "H DEPOIS POSITIVADO" << endl;
//        h->print();

        a = aCopia->geraCopia();
        Matrix* aTransposta = a->transpoe();

        Matrix* hTransposta = h->transpoe();

        NullMatrix* wTranspostaAux = new NullMatrix(p, n, CASAS_DECIMAIS);
        Matrix* wTransposta = dynamic_cast<Matrix*>(wTranspostaAux);

//        cout << "A DEPOIS TRANSPOSTA" << endl;
//        aTransposta->print();

//        cout << "H DEPOIS POSITIVADO TRANSPOSTA" << endl;
//        hTransposta->print();

        hTransposta->fatoracaoQR(aTransposta);
        hTransposta->resolveMultiplosSistemas(aTransposta, wTransposta);

//        cout << "A DEPOIS TRANSPOSTA DEPOIS" << endl;
//        aTransposta->print();
//
//        cout << "W DEPOIS TRANSPOSTA DEPOIS" << endl;
//        wTransposta->print();
//
//        cout << "A DEPOIS POSITIVADO TRANSPOSTA DEPOIS" << endl;
//        hTransposta->print();

        w = wTransposta->transpoe();

//        cout << "W NOVA (W TRANSPOSTA)" << endl;
//        w->print();

        auxiliarTornaPositivo(w);

//        cout << "W NOVA POSITIVADA" << endl;
//        w->print();
    }

    w->print();
    h->print();

    w->multiplica(h)->print();
}

void exercicioTres() {
    ifstream file("dados_mnist/train_dig0.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            printf("%s", line.c_str());
        }
        file.close();
    }
}

int main() {

    //exercicioUmA();
    //exercicioUmB();
    //exercicioUmC();
    //exercicioUmD();

    exercicioDois();

    //exercicioTres();

    return 0;
}
