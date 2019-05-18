#include <iostream>
#include <string>
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
#include <sstream>
#define NDIG_TREINO 100
#define COMPONENTES_DESEJADOS 5
#define N_TEST 10000

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
    cout << "Matriz A:" << endl;
    a->print();

    //copia matriz a
    Matrix* aCopia = a->geraCopia();
    aCopia->print();

    //gera matriz aleatoria positiva w
    RandomPositiveMatrix* wAux = new RandomPositiveMatrix(n, p, CASAS_DECIMAIS);
    Matrix* w = dynamic_cast<Matrix*>(wAux);
    cout << "Matriz W:" << endl;
    w->print();

    //gera matriz nula h que sera resolvida
    NullMatrix* hAux = new NullMatrix(p, m, CASAS_DECIMAIS);
    Matrix* h = dynamic_cast<Matrix*>(hAux);
    cout << "Matriz H:" << endl;
    h->print();

    RandomPositiveMatrix* multAux = new RandomPositiveMatrix(n, m, CASAS_DECIMAIS);
    Matrix* mult = dynamic_cast<Matrix*>(multAux);

    for(int contador = 0; contador < ITMAX && aCopia->calculaDiferenca(mult) > EPSILON; contador++) {

        cout << contador << "a" << endl;

        delete mult;

        cout << contador << "b" << endl;

        a = aCopia->geraCopia();

        auxiliarNormalizaColunas(w);

        w->fatoracaoQR(a);
        w->resolveMultiplosSistemas(a, h);

        auxiliarTornaPositivo(h);

        delete a;

        a = aCopia->geraCopia();
        Matrix* aTransposta = a->transpoe();

        Matrix* hTransposta = h->transpoe();

        NullMatrix* wTranspostaAux = new NullMatrix(p, n, CASAS_DECIMAIS);
        Matrix* wTransposta = dynamic_cast<Matrix*>(wTranspostaAux);

        hTransposta->fatoracaoQR(aTransposta);
        hTransposta->resolveMultiplosSistemas(aTransposta, wTransposta);

        w = wTransposta->transpoe();

        auxiliarTornaPositivo(w);

        delete a;

        delete aTransposta;
        delete hTransposta;
        delete wTranspostaAux;
        delete wTransposta;

        mult = w->multiplica(h);
    }

    w->print();
    h->print();

    w->multiplica(h)->print();
}

Matrix* auxiliarLeArquivoTreino(int digito, int quant) {
    ifstream file;
    string dir = "dados_mnist/train_dig" + to_string(digito) + ".txt";
    file.open(dir);

    cout << "Lendo arquivo " << digito << "..." << endl;

    NullMatrix* matrizArquivoNula = new NullMatrix(784, quant, CASAS_DECIMAIS);
    Matrix* matrizArquivo = dynamic_cast<Matrix*>(matrizArquivoNula);

    int temp;
    string linha;

    for (int i = 0; i < 784; i++) {
        getline(file, linha);
        stringstream in(linha);
        for (int j = 0; j < quant; j++) {
            in >> temp;
            matrizArquivo->matriz[i][j] = (double)temp / 255;
        }
    }

    cout << "Arquivo " << digito << " lido!" << endl;

    file.close();
    return matrizArquivo;
}

Matrix* auxiliarLeArquivo(string path, int quant) {
    ifstream file;
    string dir = path;
    file.open(dir);

    cout << "Lendo arquivo..." << endl;

    NullMatrix* matrizArquivoNula = new NullMatrix(784, quant, CASAS_DECIMAIS);
    Matrix* matrizArquivo = dynamic_cast<Matrix*>(matrizArquivoNula);

    int temp;
    string linha;

    for (int i = 0; i < 784; i++) {
        getline(file, linha);
        stringstream in(linha);
        for (int j = 0; j < quant; j++) {
            in >> temp;
            matrizArquivo->matriz[i][j] = (double)temp / 255;
        }
    }

    cout << "Arquivo lido!" << endl;

    file.close();
    return matrizArquivo;
}

Matrix* auxiliarTreino(int digito) {

    Matrix* treinoA = auxiliarLeArquivoTreino(digito, NDIG_TREINO);
    Matrix* treinoACopia = treinoA->geraCopia();

    RandomPositiveMatrix* wAux = new RandomPositiveMatrix(784, COMPONENTES_DESEJADOS, CASAS_DECIMAIS);
    Matrix* w = dynamic_cast<Matrix*>(wAux);

    NullMatrix* hAux = new NullMatrix(COMPONENTES_DESEJADOS, NDIG_TREINO, CASAS_DECIMAIS);
    Matrix* h = dynamic_cast<Matrix*>(hAux);

    int n = treinoA->getNLinhas();
    int m = NDIG_TREINO;
    int p = COMPONENTES_DESEJADOS;

    //RandomPositiveMatrix* multAux = new RandomPositiveMatrix(n, m, CASAS_DECIMAIS);
    //Matrix* mult = dynamic_cast<Matrix*>(multAux);

    cout << "Treinando digito " << digito << "..." << endl << endl;

    for(int contador = 0; contador<ITMAX && treinoACopia->calculaDiferenca(w->multiplica(h)) > EPSILON; contador++) {

        //delete mult;

        treinoA = treinoACopia->geraCopia();

        auxiliarNormalizaColunas(w);

        w->fatoracaoQR(treinoA);
        w->resolveMultiplosSistemas(treinoA, h);

        auxiliarTornaPositivo(h);

        delete treinoA;

        treinoA = treinoACopia->geraCopia();
        Matrix* aTransposta = treinoA->transpoe();

        Matrix* hTransposta = h->transpoe();

        NullMatrix* wTranspostaAux = new NullMatrix(p, n, CASAS_DECIMAIS);
        Matrix* wTransposta = dynamic_cast<Matrix*>(wTranspostaAux);

        hTransposta->fatoracaoQR(aTransposta);
        hTransposta->resolveMultiplosSistemas(aTransposta, wTransposta);

        w = wTransposta->transpoe();

        auxiliarTornaPositivo(w);

        delete treinoA;

        delete aTransposta;
        delete hTransposta;
        delete wTranspostaAux;
        delete wTransposta;

        //mult = w->multiplica(h);
    }

    delete h;
    return w;
}

void exercicioTres() {
    Matrix* w0 = auxiliarTreino(0);
    Matrix* w1 = auxiliarTreino(1);
    Matrix* w2 = auxiliarTreino(2);
    Matrix* w3 = auxiliarTreino(3);
    Matrix* w4 = auxiliarTreino(4);
    Matrix* w5 = auxiliarTreino(5);
    Matrix* w6 = auxiliarTreino(6);
    Matrix* w7 = auxiliarTreino(7);
    Matrix* w8 = auxiliarTreino(8);
    Matrix* w9 = auxiliarTreino(9);

    NullMatrix* h0 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);
    NullMatrix* h1 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);
    NullMatrix* h2 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);
    NullMatrix* h3 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);
    NullMatrix* h4 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);
    NullMatrix* h5 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);
    NullMatrix* h6 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);
    NullMatrix* h7 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);
    NullMatrix* h8 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);
    NullMatrix* h9 = new NullMatrix(COMPONENTES_DESEJADOS, N_TEST, CASAS_DECIMAIS);

    Matrix* a0 = auxiliarLeArquivo("dados_mnist/test_images.txt", N_TEST);
    Matrix* a1 = a0->geraCopia();
    Matrix* a2 = a0->geraCopia();
    Matrix* a3 = a0->geraCopia();
    Matrix* a4 = a0->geraCopia();
    Matrix* a5 = a0->geraCopia();
    Matrix* a6 = a0->geraCopia();
    Matrix* a7 = a0->geraCopia();
    Matrix* a8 = a0->geraCopia();
    Matrix* a9 = a0->geraCopia();

    w0->fatoracaoQR(a0);
    w0->resolveMultiplosSistemas(a0, h0);

    w1->fatoracaoQR(a1);
    w1->resolveMultiplosSistemas(a1, h1);
    delete a1;

    w2->fatoracaoQR(a2);
    w2->resolveMultiplosSistemas(a2, h2);
    delete a2;

    w3->fatoracaoQR(a3);
    w3->resolveMultiplosSistemas(a3, h3);
    delete a3;

    w4->fatoracaoQR(a4);
    w4->resolveMultiplosSistemas(a4, h4);
    delete a4;

    w5->fatoracaoQR(a5);
    w5->resolveMultiplosSistemas(a5, h5);
    delete a5;

    w6->fatoracaoQR(a6);
    w6->resolveMultiplosSistemas(a6, h6);
    delete a6;

    w7->fatoracaoQR(a7);
    w7->resolveMultiplosSistemas(a7, h7);
    delete a7;

    w8->fatoracaoQR(a8);
    w8->resolveMultiplosSistemas(a8, h8);
    delete a8;

    w9->fatoracaoQR(a9);
    w9->resolveMultiplosSistemas(a9, h9);
    delete a9;
}
int main() {

    //exercicioUmA();
    //exercicioUmB();
    //exercicioUmC();
    //exercicioUmD();

    //exercicioDois();

    exercicioTres();

    return 0;
}
