#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Dados.h"
#include "MetodosOrdenacao.h"
#include "Combinacoes.h"

using namespace std;

int main(int argc, char const *argv[])
{
	fstream infos(argv[1]);
	int obtemCombo = stoi(argv[2]);
	int obtemDigitado = stoi(argv[3]);

	Dados *dados = new Dados[obtemDigitado];
	Combinacoes combinacoes;

	string dadosDetail;
	string delimiter = " ";

	for (int i = 0; i < obtemDigitado; i++)
	{
		getline(infos, dadosDetail);
		dados[i].Nome = dadosDetail.substr(0, dadosDetail.find(delimiter));
		dados[i].Numero = stoi(dadosDetail.substr(dadosDetail.find(delimiter) + 1, dadosDetail.size()));
	}
	infos.close();

	combinacoes.GetCombo(dados, obtemCombo, obtemDigitado);

	for (int i = 0; i < obtemDigitado; i++)
	{

		cout << dados[i].Nome;
		cout.fill('0');
		cout << " " << setw(8) << left << dados[i].Numero << endl;
	}

	delete[] dados;
	return 0;
}