#ifndef METODOSORDENACAO_H
#define METODOSORDENACAO_H


#include <fstream>
#include <iostream>
#include "Dados.h"

class MetodosOrdenacao {
    public:
        MetodosOrdenacao(int n);
        ~MetodosOrdenacao();
        void Particao(Dados dados[], int Esq, int Dir, int *i, int *j);
        void Ordena(Dados dados[],int Esq, int Dir);
        void QuickSort(Dados dados[]);

    private:
        int tamanhoPreenchido;
        int MAXTAM;
};

#endif