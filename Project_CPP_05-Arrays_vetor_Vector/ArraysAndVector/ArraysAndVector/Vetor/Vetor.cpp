#include <iostream>
#include <cstdlib>
#include <clocale>
#include "Vetor.h"

int main() {
	return Vetor().vetor();
}

// Apresenta o array unidimensional vetor.
int Vetor::vetor() {
	const char PASSO = 1;
	char alfabeto[26];
	int numerosInteiros[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	string strings[5], stringA = "A";

	setlocale(LC_ALL, "pt-BR");

	/*  Para se criar um vetor com tamanho calculado em tempo de execução.
	 
	 	Solução 1: usa o operador sizeof.
	 
			string palavras[sizeof numerosInteiros / sizeof (int)]; 

		Solução 2: usa uma função constexpr. 
	 */
	float numerosReais[tamanhoVetor(numerosInteiros)]; 

	iniciarVetor(numerosReais, 0.0F, 0.5F);
	iniciarVetor(alfabeto, 'A', PASSO);
	iniciarVetor(strings, stringA, string("B"));

	imprimirVetor("\tvetor[int]: ", numerosInteiros);
	imprimirVetor("\tvetor[float]: ", numerosReais);
	imprimirVetor("\tvetro[char]: ", alfabeto);
	imprimirVetor("\tvetor[string]: ", strings);

	return EXIT_SUCCESS;
} // vetor()

/* Exibe uma mensagem e os elementos do vetor de qualquer tipo de dado e
   tamanho no console.
*/
template <typename T, unsigned tamanho> void 
Vetor::imprimirVetor(string mensagem, const T(&vetor)[tamanho]) {
	int indice = 0;

	cout << mensagem;

	for ( ; indice < tamanho - 1; )
		cout << vetor[indice++] << ", ";
	cout << vetor[indice] << endl;
}

/* Inicia um vetor de qualquer tipo de dado começando em inicio e com incremento ou
	decremento definido por passo.
*/
template <typename T, unsigned tamanho> void 
Vetor::iniciarVetor(T(&vetor)[tamanho], T inicio, T passo) {
	T valor = inicio;

	for (int indice = 0; indice < tamanho; indice++) {
		vetor[indice] = valor;
		valor += passo;
	}
}