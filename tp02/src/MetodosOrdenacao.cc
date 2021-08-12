#include "metodosOrdenacao.h"
#include <fstream>
#include "Dados.h"

using namespace std;


MetodosOrdenacao::MetodosOrdenacao(int n){
	tamanhoPreenchido = n;
}

MetodosOrdenacao::~MetodosOrdenacao(){
}

void MetodosOrdenacao::Particao(Dados dados[], int Esq, int Dir, int *i, int *j){
    Dados pivo, w;

    *i = Esq; 
    *j = Dir;
    pivo = dados[(*i + *j)/2];

    do {
        while ((&pivo)->Numero < dados[*i].Numero) (*i)++;
        while ((&pivo)->Numero > dados[*j].Numero) (*j)--;
        if(*i <= *j){
            w = dados[*i];
            dados[*i] = dados[*j];
            dados[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void MetodosOrdenacao::Ordena(Dados dados[],int Esq, int Dir){
    int i, j;
    Particao(dados, Esq, Dir, &i, &j);
    if(Esq < j) Ordena(dados, Esq, j);
    if(i < Dir) Ordena(dados, i, Dir);
}

void MetodosOrdenacao::QuickSort(Dados dados[]){
    Ordena(dados, 0, tamanhoPreenchido-1);

}