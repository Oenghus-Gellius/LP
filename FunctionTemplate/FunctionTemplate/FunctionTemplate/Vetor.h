#pragma once

#include <string>

using namespace std;

class Vetor {
public:
	const char 
		ASCENDENTE = '1', 
		DESCENDENTE = '2';

	template <typename T, int tamanho> int pesquisar(const T (& vetor)[tamanho], T elemento);
	template <typename T, int tamanho> void exibir(string mensagem, const T (& vetor)[tamanho]);

	/* Classifica os elementos do vetor de segundo a ordem de classificação indicada.
		ASCENDENTE = em ordem ascendente;
		DESCENDENTE = em ordem descendente.
	*/
	template <typename T, int tamanho> void classificar(T (& vetor)[tamanho], char ordemClassificacao);

	int vetor();
};

