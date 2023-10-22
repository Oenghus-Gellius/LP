#include <iostream>
#include <clocale>
#include <algorithm> // Requerido por sort.
#include <functional> // Requerido por less e greater.
#include "Vetor.h"

template <typename T, int tamanho> 
int Vetor::pesquisar(const T(& vetor)[tamanho], T elemento)
{
	for (int indice = 0; indice < tamanho; indice++)
		if (vetor[indice] == elemento)
			return indice;
	return -1;
}

template <typename T, int tamanho> 
void Vetor::exibir(string mensagem, const T(& vetor)[tamanho])
{
	const string DOIS_ESPACOS("  ");

	if (!mensagem.empty())
		cout << mensagem;

	for (const auto& numero : vetor)
		cout << numero << DOIS_ESPACOS;

	cout << endl << endl;
}

/* Classifica os elementos do vetor de segundo a ordem de classificação indicada.
	ASCENDENTE = em ordem ascendente;
	DESCENDENTE = em ordem descendente.
*/
template <typename T, int tamanho> 
void Vetor::classificar(T(&vetor)[tamanho], char ordemClassificacao) {

	if (ordemClassificacao == ASCENDENTE)
		sort(vetor, vetor + tamanho, less<T>());
	else
		sort(vetor, vetor + tamanho, greater<T>());
}


int Vetor::vetor() {
	int v1[] = { 15, 25, 18, 4, 8 };
	string palavras[] = { "terra", "mar", "sol", "lua" };

	Vetor vetor;

	vetor.exibir("v1: ", v1);
	vetor.classificar(v1, Vetor::ASCENDENTE); 
	vetor.exibir("v1 (crescente): ", v1);
	vetor.classificar(v1, Vetor::DESCENDENTE);
	vetor.exibir("v1 (decrescente): ", v1);

	vetor.exibir("palavras: ", palavras);
	vetor.classificar(palavras, Vetor::ASCENDENTE);
	vetor.exibir("palavras (a-z): ", palavras);
	vetor.classificar(palavras, Vetor::DESCENDENTE);
	vetor.exibir("palavras (z-a): ", palavras);

	return EXIT_SUCCESS;
}

int main() {
	return Vetor().vetor();
}
