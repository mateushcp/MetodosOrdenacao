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
        while (taAntesZe(dados[*i].Nome, (pivo).Nome)){
            (*i)++;
        }
        while (taAntesZe((pivo).Nome, dados[*j].Nome)){
            (*j)--;
        }

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

bool taAntesZe(string primeiraStr, string segundaStr)
{
    int aux;

    if (primeiraStr.size() < segundaStr.size())
    {
        aux = primeiraStr.size();
    }
    else
    {
        aux = segundaStr.size();
    }

    for (int i = 0; i < aux; i++)
    {
        if (primeiraStr[i] != segundaStr[i])
        {
            return primeiraStr[i] < segundaStr[i];
        }
    } 
    return (segundaStr.size() > primeiraStr.size());
}

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
        if (taAntesZe(esquerda[i].Nome, direita[j].Nome))
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

int pegaMax(Dados dados[], int n) {
  int max = dados[0].Numero;
  for (int i = 1; i < n; i++)
    if (dados[i].Numero > max)
      max = dados[i].Numero;
  return max;
}

void countingSort(Dados dados[], int tam, int place) {
  const int max = 10;
  int output[tam];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;
  for (int i = 0; i < tam; i++)
    count[(dados[i].Numero / place) % 10]++;
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];
  for (int i = tam - 1; i >= 0; i--) {
    output[count[(dados[i].Numero / place) % 10] - 1] = dados[i].Numero;
    count[(dados[i].Numero / place) % 10]--;
  }
  for (int i = 0; i < tam; i++)
    dados[i].Numero = output[i];
}

void MetodosOrdenacao::RadixSort(Dados dados[], int tam) {
  int max = pegaMax(dados, tam);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(dados, tam, place);
}