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

#define CASAS_DECIMAIS 6

using namespace std;

void exercicioUmA() {

    cout << "===== Bem vindo ao exercicio 1a =====" << endl;
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

    cout << "===== Bem vindo ao exercicio 1b =====" << endl;
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

    Matrix* a = w->multiplica(x);

    a->print();

    delete w;
    delete x;
    delete b;
}

void exercicioUmC() {



}

int main() {

    //exercicioUmA();
    //exercicioUmB();

    exercicioUmC();

    return 0;
}
