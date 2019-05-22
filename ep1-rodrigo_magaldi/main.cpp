/*
Este exercicio programa foi desenvolvido com base numa classe Matrix que centraliza algumas
operacoes realizadas com matrizes. Essa classe e' utilizada como classe pai para as classes
que inicializam as matrizes relativas 'a primeira tarefa, as quais tem um algoritmo especifico
para preenchimento de seus valores. Alem disso, ha' as classes NullMatrix, que gera uma matriz
nula, RandomPositiveMatrix, que gera uma matriz aleatoria com valores positivos, e
UserGeneratedMatrix, que inicializa uma matriz com valores digitados pelo usuario, todas subclasses
de Matrix.

Dessa forma, este EP possui os seguintes 33 arquivos:

main.cpp
Matrix.h
Matrix.cpp

Para o exercicio 1a:
    MatrixEx1a.h
    MatrixEx1a.cpp
    MatrixbEx1a.h
    MatrixbEx1a.cpp
    MatrixxEx1a.h
    MatrixxEx1a.cpp

Para o exercicio 1b:
    MatrixEx1b.h
    MatrixEx1b.cpp
    MatrixbEx1b.h
    MatrixbEx1b.cpp
    MatrixxEx1b.h
    MatrixxEx1b.cpp

Para o exercicio 1c:
    MatrixEx1c.h
    MatrixEx1c.cpp
    MatrixbEx1c.h
    MatrixbEx1c.cpp
    MatrixxEx1c.h
    MatrixxEx1c.cpp

Para o exercicio 1d:
    MatrixEx1d.h
    MatrixEx1d.cpp
    MatrixbEx1d.h
    MatrixbEx1d.cpp
    MatrixxEx1d.h
    MatrixxEx1d.cpp

Para os exercicios seguintes:
    NullMatrix.h
    NullMatrix.cpp
    RandomPositiveMatrix.h
    RandomPositiveMatrix.cpp
    UserGeneratedMatrix.h
    UserGeneratedMatrix.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Matrix.h"

//inclui as classes utilizadas no exercicio 1a
#include "MatrixEx1a.h"
#include "MatrixbEx1a.h"
#include "MatrixxEx1a.h"

//inclui as classes utilizadas no exercicio 1a
#include "MatrixEx1b.h"
#include "MatrixbEx1b.h"
#include "MatrixxEx1b.h"

//inclui as classes utilizadas no exercicio 1a
#include "MatrixwEx1c.h"
#include "MatrixaEx1c.h"
#include "MatrixhEx1c.h"

//inclui as classes utilizadas no exercicio 1a
#include "MatrixwEx1d.h"
#include "MatrixaEx1d.h"
#include "MatrixhEx1d.h"

//inclui as classes utilizadas no exercicio 1a
#include "RandomPositiveMatrix.h"
#include "UserGeneratedMatrix.h"
#include "NullMatrix.h"

//define alguns parametros a serem utilizados na segunda tarefa
//CASAS_DECIMAIS define o numero de casas decimais mostradas quando as matrizes sao impressas no consoles
#define CASAS_DECIMAIS 3
//epsilon define a condicao de para do loop principal
#define EPSILON 0.00001
//itmax define o numero de iteracoes maximo do loop principal
#define ITMAX 100


//faz alguns passos necessario para o terceiro exercicio
//possibilita a leitura de arquivos
#include <fstream>
#include <sstream>
//define o numero de imagens usadas no treino: este parametro deve ser modificado para uso na tarefa principal
#define NDIG_TREINO 4000
//define o numero de componentes usadas no treino: este parametro deve ser modificado para uso na tarefa principal
#define COMPONENTES_DESEJADOS 15
//define o numero de imagens testadas: nao modificar este parametro, pois todas as imagens deve ser testadas
#define N_TEST 10000

using namespace std;

//funcao que executa o exercicio 1a
void exercicioUmA() {

    cout << "===== Bem vindo ao exercicio 1a =====" << endl << endl;
    cout << endl;

    MatrixEx1a* w = new MatrixEx1a(CASAS_DECIMAIS);
    Matrix* wCopia = w->geraCopia();

    MatrixbEx1a* b = new MatrixbEx1a(CASAS_DECIMAIS);

    MatrixxEx1a* x = new MatrixxEx1a(CASAS_DECIMAIS);

    cout << "Matrizes iniciais:" << endl << endl;
    cout << "W:" << endl;
    w->print();

    cout << "b:" << endl;
    b->print();

    cout << "x:" << endl;
    x->print();

    cout << "Realizando fatoracao..." << endl;
    w->fatoracaoQR(b);

    cout << "Resolvendo o sistema..." << endl;
    w->resolveSistema(b, x);

    cout << "Resultado obtido x:" << endl;
    x->print();

    cout << "Resultado da multiplicacao Wx (deveria ser igual a b)" << endl;
    Matrix* mult = wCopia->multiplica(x);

    mult->print();

    delete w;
    delete x;
    delete b;
    delete mult;

    cout << "===== Fim do exercicio 1a! =====" << endl;
}

//funcao que executa o exercicio 1b
void exercicioUmB() {

    cout << "===== Bem vindo ao exercicio 1b =====" << endl << endl;
    cout << endl;

    MatrixEx1b* w = new MatrixEx1b(CASAS_DECIMAIS);
    Matrix* wCopia = w->geraCopia();

    MatrixbEx1b* b = new MatrixbEx1b(CASAS_DECIMAIS);

    MatrixxEx1b* x = new MatrixxEx1b(CASAS_DECIMAIS);

    cout << "Matrizes iniciais:" << endl << endl;
    cout << "W:" << endl;
    w->print();

    cout << "b:" << endl;
    b->print();

    cout << "x:" << endl;
    x->print();

    cout << "Realizando fatoracao..." << endl;
    w->fatoracaoQR(b);

    cout << "Resolvendo o sistema..." << endl;
    w->resolveSistema(b, x);

    cout << "Resultado obtido x:" << endl;
    x->print();

    cout << "Resultado da multiplicacao Wx (deveria se aproximar de b)" << endl;
    Matrix* mult = wCopia->multiplica(x);

    mult->print();

    delete w;
    delete x;
    delete b;
    delete mult;

    cout << "===== Fim do exercicio 1b! =====" << endl;
}

//funcao que executa o exercicio 1a
void exercicioUmC() {

    cout << "===== Bem vindo ao exercicio 1c =====" << endl << endl;
    cout << endl;

    MatrixwEx1c* w = new MatrixwEx1c(CASAS_DECIMAIS);
    Matrix* wCopia = w->geraCopia();

    MatrixaEx1c* a = new MatrixaEx1c(CASAS_DECIMAIS);
    MatrixhEx1c* h = new MatrixhEx1c(CASAS_DECIMAIS);

    cout << "Matrizes iniciais:" << endl << endl;
    cout << "W:" << endl;
    w->print();

    cout << "A:" << endl;
    a->print();

    cout << "H:" << endl;
    h->print();

    cout << "Realizando fatoracao..." << endl;
    w->fatoracaoQR(a);

    cout << "Resolvendo o sistema..." << endl;
    w->resolveMultiplosSistemas(a, h);

    cout << "Resultado obtido H:" << endl;
    h->print();

    cout << "Resultado da multiplicacao WH (deveria ser igual a A)" << endl;
    Matrix* mult = wCopia->multiplica(h);

    mult->print();

    delete w;
    delete h;
    delete a;
    delete mult;

    cout << "===== Fim do exercicio 1c! =====" << endl;

}

//funcao que executa o exercicio 1a
void exercicioUmD() {

    cout << "===== Bem vindo ao exercicio 1d =====" << endl << endl;
    cout << endl;

    MatrixwEx1d* w = new MatrixwEx1d(CASAS_DECIMAIS);
    Matrix* wCopia = w->geraCopia();

    MatrixaEx1d* a = new MatrixaEx1d(CASAS_DECIMAIS);
    MatrixhEx1d* h = new MatrixhEx1d(CASAS_DECIMAIS);

    cout << "Matrizes iniciais:" << endl << endl;
    cout << "W:" << endl;
    w->print();

    cout << "A:" << endl;
    a->print();

    cout << "H:" << endl;
    h->print();

    cout << "Realizando fatoracao..." << endl;
    w->fatoracaoQR(a);

    cout << "Resolvendo o sistema..." << endl;
    w->resolveMultiplosSistemas(a, h);

    cout << "Resultado obtido H:" << endl;
    h->print();

    cout << "Resultado da multiplicacao WH (deveria ser igual a A)" << endl;
    Matrix* mult = wCopia->multiplica(h);

    mult->print();

    delete w;
    delete h;
    delete a;
    delete mult;

    cout << "===== Fim do exercicio 1d! =====" << endl;
}

//funcao auxiliar que normaliza as colunas de uma matriz passada como parametro
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

//funcao auxiliar que modifica os numeros negativos de uma matriz para 0
void auxiliarTornaPositivo(Matrix* m) {
    for (int i=0; i<m->getNLinhas(); i++) {
        for (int j=0; j<m->getNColunas(); j++) {
            if (m->matriz[i][j] < 0) {
                m->matriz[i][j] = 0;
            }
        }
    }
}

//funcao que executa o exercicio 2
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

    Matrix* multAnterior = w->multiplica(h);

    for(int contador = 0; contador < ITMAX && fabs(aCopia->calculaDiferenca(mult) - aCopia->calculaDiferenca(multAnterior)) > EPSILON; contador++) {

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
        delete wTransposta;

        delete multAnterior;

        multAnterior = mult->geraCopia();

        delete mult;

        mult = w->multiplica(h);
    }

    w->print();
    h->print();

    mult->print();

    double erro = fabs(aCopia->calculaDiferenca(mult) - aCopia->calculaDiferenca(multAnterior));

    cout << "Erro: " << erro << endl;
}

//funcao auxiliar que le os arquivos de treino
Matrix* auxiliarLeArquivoTreino(int digito, int quant) {
    ifstream file;
    string dir = "dados_mnist/train_dig" + to_string(digito) + ".txt";
    file.open(dir);

    cout << "Lendo arquivo " << digito << "..." << endl;

    NullMatrix* matrizArquivoNula = new NullMatrix(784, quant, CASAS_DECIMAIS);
    Matrix* matrizArquivo = dynamic_cast<Matrix*>(matrizArquivoNula);

    double temp;
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

//funcao auxiliar que le o arquivo de teste
Matrix* auxiliarLeArquivoTeste(string path, int quant) {
    ifstream file;
    string dir = path;
    file.open(dir);

    cout << "Lendo arquivo de testes..." << endl;

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

    cout << "Arquivo lido!" << endl << endl;

    file.close();
    return matrizArquivo;
}

//funcao auxiliar que le o arquivo de respostas reais dos testes
vector<int> auxiliarLeArquivoRespostas(string path) {
    ifstream file;
    string dir = path;
    file.open(dir);

    cout << "Lendo arquivo de respostas..." << endl;

    vector<int> respostas;

    int temp;
    string linha;

    for (int i = 0; i < N_TEST; i++) {
        getline(file, linha);
        stringstream in(linha);
        in >> temp;
        respostas.push_back(temp);
    }

    cout << "Arquivo lido!" << endl << endl;

    file.close();
    return respostas;
}

//funcao auxiliar que realiza o treino de cada digito na tarefa principal
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

    RandomPositiveMatrix* multAux = new RandomPositiveMatrix(n, m, CASAS_DECIMAIS);
    Matrix* mult = dynamic_cast<Matrix*>(multAux);

    Matrix* multAnterior = w->multiplica(h);

    cout << "Treinando digito " << digito << "..." << endl;

    cout << "Iteracao ";

    for(int contador = 0; contador<ITMAX &&
                        fabs(treinoACopia->calculaDiferenca(mult) - treinoACopia->calculaDiferenca(multAnterior))/treinoACopia->calculaDiferenca(mult) > EPSILON; contador++) {

        cout << contador << " ";

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
        delete wTransposta;

        delete multAnterior;

        multAnterior = mult->geraCopia();

        delete mult;

        mult = w->multiplica(h);
    }

    double erro = fabs(treinoACopia->calculaDiferenca(mult) - treinoACopia->calculaDiferenca(multAnterior))/treinoACopia->calculaDiferenca(mult);

    delete treinoACopia;
    delete hAux;

    cout << endl << "Digito " << digito << " treinado! Erro: " << erro << endl << endl;

    return w;
}

//funcao auxiliar que calculo o erro da matriz diferenca passada na tarefa principal
vector<double> auxiliarCalculaErro(Matrix* m) {
    vector<double> erros;
    double soma;
    for (int j=0; j<m->getNColunas(); j++) {
        soma = 0;
        for (int i=0; i<m->getNLinhas(); i++) {
            soma += pow(m->matriz[i][j], 2);
        }
        double erro = sqrt(soma);
        erros.push_back(erro);
    }
    return erros;
}

//funcao que executa a tarefa principal do EP
void exercicioTres() {

    //define as matrix Wd para cada digito
    Matrix* w0 = auxiliarTreino(0);
    Matrix* w0Original = w0->geraCopia();

    Matrix* w1 = auxiliarTreino(1);
    Matrix* w1Original = w1->geraCopia();

    Matrix* w2 = auxiliarTreino(2);
    Matrix* w2Original = w2->geraCopia();

    Matrix* w3 = auxiliarTreino(3);
    Matrix* w3Original = w3->geraCopia();

    Matrix* w4 = auxiliarTreino(4);
    Matrix* w4Original = w4->geraCopia();

    Matrix* w5 = auxiliarTreino(5);
    Matrix* w5Original = w5->geraCopia();

    Matrix* w6 = auxiliarTreino(6);
    Matrix* w6Original = w6->geraCopia();

    Matrix* w7 = auxiliarTreino(7);
    Matrix* w7Original = w7->geraCopia();

    Matrix* w8 = auxiliarTreino(8);
    Matrix* w8Original = w8->geraCopia();

    Matrix* w9 = auxiliarTreino(9);
    Matrix* w9Original = w9->geraCopia();


    //inicializa as matrizes Hd correspondentes a cada Wd
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


    //inicializa as matrizes Ad para cada Wd
    Matrix* aOriginal = auxiliarLeArquivoTeste("dados_mnist/test_images.txt", N_TEST);
    Matrix* a0 = aOriginal->geraCopia();
    Matrix* a1 = aOriginal->geraCopia();
    Matrix* a2 = aOriginal->geraCopia();
    Matrix* a3 = aOriginal->geraCopia();
    Matrix* a4 = aOriginal->geraCopia();
    Matrix* a5 = aOriginal->geraCopia();
    Matrix* a6 = aOriginal->geraCopia();
    Matrix* a7 = aOriginal->geraCopia();
    Matrix* a8 = aOriginal->geraCopia();
    Matrix* a9 = aOriginal->geraCopia();


    cout << "Iniciando classificacao..." << endl << endl;

    //resolve as fatoracoes Wd*Hd = Ad
    w0->fatoracaoQR(a0);
    w0->resolveMultiplosSistemas(a0, h0);
    delete a0;

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

    //cria as matrizes diferenca A - Wd*Hd
    Matrix* mult0 = w0Original->multiplica(h0);
    Matrix* diff0 = aOriginal->subtrai(mult0);
    delete mult0;

    Matrix* mult1 = w1Original->multiplica(h1);
    Matrix* diff1 = aOriginal->subtrai(mult1);
    delete mult1;

    Matrix* mult2 = w2Original->multiplica(h2);
    Matrix* diff2 = aOriginal->subtrai(mult2);
    delete mult2;

    Matrix* mult3 = w3Original->multiplica(h3);
    Matrix* diff3 = aOriginal->subtrai(mult3);
    delete mult3;

    Matrix* mult4 = w4Original->multiplica(h4);
    Matrix* diff4 = aOriginal->subtrai(mult4);
    delete mult4;

    Matrix* mult5 = w5Original->multiplica(h5);
    Matrix* diff5 = aOriginal->subtrai(mult5);
    delete mult5;

    Matrix* mult6 = w6Original->multiplica(h6);
    Matrix* diff6 = aOriginal->subtrai(mult6);
    delete mult6;

    Matrix* mult7 = w7Original->multiplica(h7);
    Matrix* diff7 = aOriginal->subtrai(mult7);
    delete mult7;

    Matrix* mult8 = w8Original->multiplica(h8);
    Matrix* diff8 = aOriginal->subtrai(mult8);
    delete mult8;

    Matrix* mult9 = w9Original->multiplica(h9);
    Matrix* diff9 = aOriginal->subtrai(mult9);
    delete mult9;


    //armazena os vetores erro de cada digito numa matriz
    vector<double> erro0 = auxiliarCalculaErro(diff0);
    vector<double> erro1 = auxiliarCalculaErro(diff1);
    vector<double> erro2 = auxiliarCalculaErro(diff2);
    vector<double> erro3 = auxiliarCalculaErro(diff3);
    vector<double> erro4 = auxiliarCalculaErro(diff4);
    vector<double> erro5 = auxiliarCalculaErro(diff5);
    vector<double> erro6 = auxiliarCalculaErro(diff6);
    vector<double> erro7 = auxiliarCalculaErro(diff7);
    vector<double> erro8 = auxiliarCalculaErro(diff8);
    vector<double> erro9 = auxiliarCalculaErro(diff9);

    vector< vector<double> > matrizErros;
    matrizErros.push_back(erro0);
    matrizErros.push_back(erro1);
    matrizErros.push_back(erro2);
    matrizErros.push_back(erro3);
    matrizErros.push_back(erro4);
    matrizErros.push_back(erro5);
    matrizErros.push_back(erro6);
    matrizErros.push_back(erro7);
    matrizErros.push_back(erro8);
    matrizErros.push_back(erro9);


    //vetor de respostas do teste
    vector<int> respostas;

    //preenche o vetor respostas
    for (unsigned j=0; j<matrizErros[0].size(); j++) {

        int nTemp = 0;
        double temp = matrizErros[0][j];

        for (unsigned i=0; i<matrizErros.size(); i++) {
            if (matrizErros[i][j] < temp) {
                temp = matrizErros[i][j];
                nTemp = i;
            }
        }

        respostas.push_back(nTemp);
    }



    //le o arquivo de valores reais e armazena num outro vetor
    vector<int> valoresReais = auxiliarLeArquivoRespostas("dados_mnist/respostas.txt");

    //inicializa os valores de acertos totais, para cada digito e numero total de aparicoes de cada digito
    int certos = 0;

    int n0 = 0;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;
    int n5 = 0;
    int n6 = 0;
    int n7 = 0;
    int n8 = 0;
    int n9 = 0;

    int certos0 = 0;
    int certos1 = 0;
    int certos2 = 0;
    int certos3 = 0;
    int certos4 = 0;
    int certos5 = 0;
    int certos6 = 0;
    int certos7 = 0;
    int certos8 = 0;
    int certos9 = 0;

    //loop que checa as taxas de acertos totais e para cada digito
    for (unsigned i=1; i<valoresReais.size(); i++) {
        if (valoresReais[i] == 0) {
            n0++;
            if (respostas[i] == 0) {
                certos0++;
                certos++;
            }
        }
        if (valoresReais[i] == 1) {
            n1++;
            if (respostas[i] == 1) {
                certos1++;
                certos++;
            }
        }
        if (valoresReais[i] == 2) {
            n2++;
            if (respostas[i] == 2) {
                certos2++;
                certos++;
            }
        }
        if (valoresReais[i] == 3) {
            n3++;
            if (respostas[i] == 3) {
                certos3++;
                certos++;
            }
        }
        if (valoresReais[i] == 4) {
            n4++;
            if (respostas[i] == 4) {
                certos4++;
                certos++;
            }
        }
        if (valoresReais[i] == 5) {
            n5++;
            if (respostas[i] == 5) {
                certos5++;
                certos++;
            }
        }
        if (valoresReais[i] == 6) {
            n6++;
            if (respostas[i] == 6) {
                certos6++;
                certos++;
            }
        }
        if (valoresReais[i] == 7) {
            n7++;
            if (respostas[i] == 7) {
                certos7++;
                certos++;
            }
        }
        if (valoresReais[i] == 8) {
            n8++;
            if (respostas[i] == 8) {
                certos8++;
                certos++;
            }
        }
        if (valoresReais[i] == 9) {
            n9++;
            if (respostas[i] == 9) {
                certos9++;
                certos++;
            }
        }
    }

    //imprime no console os valores obtidos de taxas de acerto
    cout << "Acertos: " << certos << endl << "Total: " << valoresReais.size() << endl << "Porcentagem de acertos: " << (double)100*certos/valoresReais.size() << "%" << endl << endl;
    cout << "Acertos 0: " << certos0 << endl << "Total: " << n0 << endl << "Porcentagem de acertos: " << (double)100*certos0/n0 << "%" << endl << endl;
    cout << "Acertos 1: " << certos1 << endl << "Total: " << n1 << endl << "Porcentagem de acertos: " << (double)100*certos1/n1 << "%" << endl << endl;
    cout << "Acertos 2: " << certos2 << endl << "Total: " << n2 << endl << "Porcentagem de acertos: " << (double)100*certos2/n2 << "%" << endl << endl;
    cout << "Acertos 3: " << certos3 << endl << "Total: " << n3 << endl << "Porcentagem de acertos: " << (double)100*certos3/n3 << "%" << endl << endl;
    cout << "Acertos 4: " << certos4 << endl << "Total: " << n4 << endl << "Porcentagem de acertos: " << (double)100*certos4/n4 << "%" << endl << endl;
    cout << "Acertos 5: " << certos5 << endl << "Total: " << n5 << endl << "Porcentagem de acertos: " << (double)100*certos5/n5 << "%" << endl << endl;
    cout << "Acertos 6: " << certos6 << endl << "Total: " << n6 << endl << "Porcentagem de acertos: " << (double)100*certos6/n6 << "%" << endl << endl;
    cout << "Acertos 7: " << certos7 << endl << "Total: " << n7 << endl << "Porcentagem de acertos: " << (double)100*certos7/n7 << "%" << endl << endl;
    cout << "Acertos 8: " << certos8 << endl << "Total: " << n8 << endl << "Porcentagem de acertos: " << (double)100*certos8/n8 << "%" << endl << endl;
    cout << "Acertos 9: " << certos9 << endl << "Total: " << n9 << endl << "Porcentagem de acertos: " << (double)100*certos9/n9 << "%" << endl << endl;

    }

//no main, o exercicio desejado deve ser descomentado para ser executado
int main() {

    //exercicioUmA();
    //exercicioUmB();
    //exercicioUmC();
    //exercicioUmD();

    //exercicioDois();

    exercicioTres();

    return 0;
}
