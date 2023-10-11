#include <iostream>
#include "Vector.h"

// Adiciona um número no Vector.
void Vector::adicionar(int numero) {
	intVector.push_back(numero);
}

// Obtém o número atual de elementos do vector.
vector<int>::size_type Vector::tamanho() {
	return intVector.size();
}

/* Obtém o número máximo de elementos do vector, ou seja, a capacidade atual de
   armazenar os elementos sem alocar memória.
*/
vector<int>::size_type Vector::capacidade() {
	return intVector.capacity();
}

// Exibe as propriedades (nome, elementos, tamanho e capacidade) do Vector.
void Vector::printVector(string nome) {
	const string DOIS_ESPACOS = "  ";

	if (nome != "")
		cout << nome << ": ";

	// Range-based for statement: loop for baseado em intervalo
	for (const auto& numero : intVector)
		cout << numero << DOIS_ESPACOS;

	cout << "\nTamanho: " << tamanho() << "\nCapacidade: " << capacidade() << endl << endl;
}

// Apaga todos os números do Vector.
void Vector::excluir() {
	intVector.clear();
}

// Obtém uma cópia dos números do Vector.
vector<int> Vector::getVector() {
	return intVector;
}

/* Obtém uma referência do Vector.

   ATENÇÃO: ao retornar a referência de um atributo privado o código chamador do método abaixo poderá alterar
			esse atributo diretamente, ou seja, quebra-se o encapsulamento. Portanto, essa é considerada uma
			prática de programação ruim.
*/
vector<int>& Vector::getRefVector() {
	return intVector;
}
