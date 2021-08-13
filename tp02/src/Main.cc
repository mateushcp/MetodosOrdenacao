#include <iostream>
#include <fstream>
#include <string>
#include "Dados.h"
#include "MetodosOrdenacao.h"

using namespace std;

int main(int argc, char const* argv[]) {
	fstream infos(argv[1]);
    int obtemCombo = stoi(argv[2]);
    int obtemDigitado = stoi(argv[3]);

    Dados *dados = new Dados[obtemDigitado];

	string dadosDetail;
	string delimiter = " ";


	for (int i = 0; i < obtemDigitado; i++) {
		getline(infos, dadosDetail);
		dados[i].Nome = dadosDetail.substr(0, dadosDetail.find(delimiter));
		dados[i].Numero = stoi(dadosDetail.substr(dadosDetail.find(delimiter) + 1, dadosDetail.size()));
	}
	infos.close();

    MetodosOrdenacao(obtemDigitado).HeapSort(dados, obtemDigitado);

    for (int i = 0; i < obtemDigitado; i++)
    {
        cout << dados[i].Numero << endl;
    }
    

	delete[] dados;
	return 0;
}