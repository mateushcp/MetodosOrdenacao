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
        for (int i = 0; i < obtemDigitado; i++)
        {
            cout << dados[i].Nome << " " << dados[i].Numero <<endl;
        }
        break;
    case 2:
        MetodosOrdenacao(obtemDigitado).RadixSort(dados, obtemDigitado);
        MetodosOrdenacao(obtemDigitado).QuickSort(dados);
        for (int i = 0; i < obtemDigitado; i++)
        {
            cout << dados[i].Nome << " " << dados[i].Numero <<endl;
        }
        break;
    case 3:
        MetodosOrdenacao(obtemDigitado).HeapSort(dados, obtemDigitado);
        MetodosOrdenacao(obtemDigitado).MergeSort(dados, 0 , obtemDigitado -1);
        for (int i = 0; i < obtemDigitado; i++)
        {
            cout << dados[i].Nome << " " << dados[i].Numero <<endl;
        }
        break;
    case 4:
        MetodosOrdenacao(obtemDigitado).RadixSort(dados, obtemDigitado);
        MetodosOrdenacao(obtemDigitado).MergeSort(dados, 0 , obtemDigitado -1);
        for (int i = 0; i < obtemDigitado; i++)
        {
            cout << dados[i].Nome << " " << dados[i].Numero <<endl;
        }
        break;
    default:
        break;
    }
}
