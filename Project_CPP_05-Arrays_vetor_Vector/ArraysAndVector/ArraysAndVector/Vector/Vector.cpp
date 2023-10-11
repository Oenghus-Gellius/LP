#include <iostream>
#include "Vector.h"

// Adiciona um n�mero no Vector.
void Vector::adicionar(int numero) {
	intVector.push_back(numero);
}

// Obt�m o n�mero atual de elementos do vector.
vector<int>::size_type Vector::tamanho() {
	return intVector.size();
}

/* Obt�m o n�mero m�ximo de elementos do vector, ou seja, a capacidade atual de
   armazenar os elementos sem alocar mem�ria.
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

// Apaga todos os n�meros do Vector.
void Vector::excluir() {
	intVector.clear();
}

// Obt�m uma c�pia dos n�meros do Vector.
vector<int> Vector::getVector() {
	return intVector;
}

/* Obt�m uma refer�ncia do Vector.

   ATEN��O: ao retornar a refer�ncia de um atributo privado o c�digo chamador do m�todo abaixo poder� alterar
			esse atributo diretamente, ou seja, quebra-se o encapsulamento. Portanto, essa � considerada uma
			pr�tica de programa��o ruim.
*/
vector<int>& Vector::getRefVector() {
	return intVector;
}
