#include <iostream>
#include <fstream>
#include <string>
#include "Dados.h"
#include "MetodosOrdenacao.h"
#include "Combinacoes.h"


void Combinacoes::GetCombo(Dados dados[],int obtemCombo, int obtemDigitado)
{
    switch (obtemCombo)
    {
    case 1:
        MetodosOrdenacao(obtemDigitado).HeapSort(dados, obtemDigitado);
        MetodosOrdenacao(obtemDigitado).QuickSort(dados);
        break;
    case 2:
        MetodosOrdenacao(obtemDigitado).RadixSort(dados, obtemDigitado);
        MetodosOrdenacao(obtemDigitado).QuickSort(dados);
        break;
    case 3:
        MetodosOrdenacao(obtemDigitado).HeapSort(dados, obtemDigitado);
        MetodosOrdenacao(obtemDigitado).MergeSort(dados, 0 , obtemDigitado -1);
        break;
    case 4:
        MetodosOrdenacao(obtemDigitado).RadixSort(dados, obtemDigitado);
        MetodosOrdenacao(obtemDigitado).MergeSort(dados, 0 , obtemDigitado -1);
        break;
    default:
        break;
    }
}
