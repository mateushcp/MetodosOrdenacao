#ifndef METODOSORDENACAO_H
#define METODOSORDENACAO_H

#include <fstream>
#include <iostream>
#include "Dados.h"

class MetodosOrdenacao
{
public:
    MetodosOrdenacao(int n);
    ~MetodosOrdenacao();
    void Particao(Dados dados[], int Esq, int Dir, int *i, int *j);
    void Ordena(Dados dados[], int Esq, int Dir);
    void QuickSort(Dados dados[]);
    void MergeSort(Dados dados[], int esq, int dir);
    void Merge(Dados dados[], int e, int m, int d);
    void Heapify(Dados dados[], int n, int i);
    void HeapSort(Dados dados[], int n);
    void RadixSort(Dados dados[], int tam);

private:
    int tamanhoPreenchido;
    int MAXTAM;
};

bool taAntesZe(string primeiraStr, string segundaStr);

#endif