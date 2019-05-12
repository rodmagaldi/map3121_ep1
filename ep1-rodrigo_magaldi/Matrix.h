#ifndef MATRIX_H
#define MATRIX_H

//incluimos vector para inicializacao da matriz
#include <vector>

//precisamos usar o std para trabalhar com o vector
using namespace std;

//para facilitar as operacoes matriciais e reduzir o tamanho do codigo no main,
//foi criada a classe Matrix
class Matrix
{
    public:
        //construtor a partir de nlinhas e ncolunas
        Matrix(int nLinhas, int nColunas, int precisao);

        //destrutor da classe
        virtual ~Matrix();

        //getters
        int getNLinhas();
        int getNColunas();

        //metodo que realiza a fatoracao QR em this->matriz
        void fatoracaoQR(Matrix* b);

        //metodo usado para resolver o sistema Wx = b
        void resolveSistema(Matrix* b, Matrix* x);

        Matrix* multiplica(Matrix* m);

        //metodo para printar this->matriz
        void print();

    protected:
        //numero de linhas e colunas do objeto matrix
        int nLinhas, nColunas;

        //numero de casas decimais a serem utilizadas
        int precisao;

        //a matriz de fato, inicializada como vector
        vector< vector<double> > matriz;

        //metodo aplicado apenas dentro de fatoracaoQR, nao precisa ser publico
        void rotGivens(int, int, double, double);
};

#endif // MATRIX_H
