#pragma once

#include <string>

using namespace std;

/*
*    int vetor[2];		// Define um vetor de 2 números int
*	 int& refV[2];		// ERRO: Array (vetor) de referência é ilegal.
*    int (& refV)[2] = vetor; // Define uma referência para um vetor de 2 números int.
*    int (*ptrFunc)(); // Ponteiro de função para uma função que recebe nada e retorna int.
*
*   Calcula o tamanho de um vetor de qualquer tipo de dado.
*/
template <typename T, unsigned tamanho>
constexpr unsigned tamanhoVetor(const T (&vetor)[tamanho])
{
	return tamanho;
}

class Vetor {
public:
	// Apresenta o array unidimensional vetor.
	int vetor();

	/* Exibe uma mensagem e os elementos do vetor de qualquer tipo de dado e 
	   tamanho no console.
	*/
	template <typename T, unsigned tamanho> 
	void imprimirVetor(string mensagem, const T(&vetor)[tamanho]);

	/* Inicia um vetor de qualquer tipo de dado começando em inicio e com incremento ou 
	    decremento definido por passo.
	*/
	template <typename T, unsigned tamanho> 
	void iniciarVetor(T(&vetor)[tamanho], T inicio, T passo);
};

