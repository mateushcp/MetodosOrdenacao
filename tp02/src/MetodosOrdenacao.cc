#include "metodosOrdenacao.h"
#include <fstream>
#include "Dados.h"

using namespace std;

MetodosOrdenacao::MetodosOrdenacao(int n)
{
    tamanhoPreenchido = n;
}

MetodosOrdenacao::~MetodosOrdenacao()
{
}

void MetodosOrdenacao::Particao(Dados dados[], int Esq, int Dir, int *i, int *j)
{
    Dados pivo, w;

    *i = Esq;
    *j = Dir;
    pivo = dados[(*i + *j) / 2];

    do
    {
        while ((&pivo)->Numero > dados[*i].Numero)
            (*i)++;
        while ((&pivo)->Numero < dados[*j].Numero)
            (*j)--;
        if (*i <= *j)
        {
            w = dados[*i];
            dados[*i] = dados[*j];
            dados[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void MetodosOrdenacao::Ordena(Dados dados[], int Esq, int Dir)
{
    int i, j;
    Particao(dados, Esq, Dir, &i, &j);
    if (Esq < j)
        Ordena(dados, Esq, j);
    if (i < Dir)
        Ordena(dados, i, Dir);
}

void MetodosOrdenacao::QuickSort(Dados dados[])
{
    Ordena(dados, 0, tamanhoPreenchido - 1);
}

// void comparaNome(Dados dados, Dados dados2){
//     string dados1 = dados.Nome;
//     string dados2zao = dados2.Nome;

//     for (int i = 0; i < dados1.size(); i++)
//     {
//         //lily
//         dados1[i] > dados2[i];

//     }
// }

void MetodosOrdenacao::Merge(Dados dados[], int e, int m, int d)
{

    auto const numEsq = m - e + 1;
    auto const numDir = d - m;

    Dados *esquerda = new Dados[numEsq];
    Dados *direita = new Dados[numDir];

    for (int i = 0; i < numEsq; i++)
    {
        esquerda[i] = dados[e + i];
    }
    for (int j = 0; j < numDir; j++)
    {
        direita[j] = dados[m + 1 + j];
    }

    int i = 0, j = 0, k = e;

    while (i < numEsq && j < numDir)
    {
        if (esquerda[i].Numero < direita[j].Numero)
        {
            dados[k] = esquerda[i];
            i++;
        }
        else
        {
            dados[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < numEsq)
    {
        dados[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < numDir)
    {
        dados[k] = direita[j];
        j++;
        k++;
    }

    delete esquerda;
    delete direita;
}

void MetodosOrdenacao::MergeSort(Dados dados[], int esq, int dir)
{
    if (esq < dir)
    {
        int m = esq + (dir - esq) / 2;
        MergeSort(dados, esq, m);
        MergeSort(dados, m + 1, dir);
        Merge(dados, esq, m, dir);
    }
}

void MetodosOrdenacao::Heapify(Dados dados[], int n, int i)
{
    int maior = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && dados[l].Numero > dados[maior].Numero)
        maior = l;
    if (r < n && dados[r].Numero > dados[maior].Numero)
        maior = r;
    if (maior != i)
    {
        swap(dados[i], dados[maior]);
        Heapify(dados, n, maior);
    }
}
void MetodosOrdenacao::HeapSort(Dados dados[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(dados, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(dados[0], dados[i]);
        Heapify(dados, i, 0);
    }
}