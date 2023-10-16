#include "Texto.h"
#include "Linha.h"

#include <iostream>
#include <sstream>
#include <algorithm>

#include <memory>


using namespace std;

int Texto::getNumeroLinhas()
{
	return numeroLinhas;
}

void Texto::adicionarLinha(Linha linha)
{
	linhas.push_back(linha);
	numeroLinhas++;
}


optional<Linha> Texto::obterLinha(int numeroLinha)
{
	if (numeroLinha > 0 && numeroLinha <= numeroLinhas)
	{
		return optional<Linha&>(linhas[numeroLinha - 1]);
	}
	else
	{
		return nullopt;
	}
}



int Texto::quantidadePalavras()
{
	int countWorld = 0;

	for (const Linha& linha : linhas)
	{
		countWorld = countWorld + linha.quantidadePalavras();
	}
	return countWorld;
}

int Texto::pesquisarPalavra(string palavra, int tabelaOcorre[][2]) {
    int totalOcorrencias = 0;

	for (int i = 0; i < numeroLinhas; i++) {
		int ocorrencias = 0;

		// Dividir a linha em palavras usando um stringstream.
		std::istringstream iss (linhas[i].getTexto());
		std::string word;
		while (iss >> word) {
			if (word == palavra) {
				ocorrencias++;
			}
		}

		if (ocorrencias > 0) {
			tabelaOcorre[i][0] = i + 1;
			tabelaOcorre[i][1] = ocorrencias;// Armazena o número da linha onde ocorre a palavra.
			totalOcorrencias += ocorrencias;// Armazena o número de ocorrências da palavra na linha.
		}
	}
	if (!totalOcorrencias)
	{
		return -1;
	}
	return totalOcorrencias;    
}


bool Texto::excluirLinha(int numeroLinha)
{
	return false;
}
