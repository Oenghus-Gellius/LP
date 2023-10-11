#include <iostream>
#include <locale>
#include <cstdlib>
#include "Vector.h"
#include "TestarVector.h"

// Apresenta as propriedades da classes Vector e vector.
int TestarVector::testarVector() {
	setlocale(LC_ALL, "pt-BR");

	//Cria o objeto vector da classe Vector para armazenar int
	Vector vector;

	//Cria o objeto charVector da classe Vector para armazenar caracteres
	std::vector<char> charVector;

	vector.printVector();
	printVector(charVector);

	/* ERRO - O codigo abaixo gera um erro em tempo de execução poq o vector possui tamanho zero
		charVector[0] = 'a';
		charVector(0) = 'a';
	*/

	for (int numero = 1; numero <= 10; numero++)
		vector.adicionar(numero);

	vector.printVector("números");

	for (char caractere = 'a'; caractere <= 'z'; caractere++)
		charVector.push_back(caractere);

	// Chamada do metodo at classe vector(C++) retorna uma referencia 
	//para a posição zero do vector, por isso a modificação é possivel no comando abaixo
	charVector.at(0) = 'A';
	charVector[25] = 'Z';

	printVector(charVector, "alfabeto");

	// Modifica o primeiro caractere do vector usando uma referência.
	auto& caractere = charVector.at(0);
	caractere = 'a';

	printVector(charVector, "alfabeto");

	// Aumentando o tamanho do vector de caracteres.
	charVector.resize(40, '@');

	printVector(charVector, "alfabeto");

	// Descarta o excesso de capacidade.
	charVector.shrink_to_fit();

	printVector(charVector, "alfabeto");

	// Apaga o último caractere do vector.
	for (int caractere = 1; caractere <= 14; caractere++)
		charVector.pop_back();

	printVector(charVector, "alfabeto");

	//O exemplo abaixo obtem uma copia do vector int emcapsulado no bbjeto vector
	// por isso não é possivel Altera-lo
	std::vector<int> v1 = vector.getVector();
	v1[0] = 10;

	vector.printVector("números: ");

	//O exemplo abaixo obtem uma referencia do vector<int> encapsulado 
	//no objeto vector, por isso é possivel altera-lo usando a referencia v2
	std::vector<int>& v2 = vector.getRefVector();
	v2.at(0) = 10;

	vector.printVector("números: ");

	vector.excluir();
	charVector.clear();

	vector.printVector("números: ");
	printVector(charVector, "alfabeto");

	return EXIT_SUCCESS;
}

// Exibe as propriedades (nome, elementos, tamanho e capacidade) do vector de caracteres.
void TestarVector::printVector(const vector<char>& vector, string nome) {
	const string DOIS_ESPACOS = "  ";

	if (nome != "")
		cout << nome << ": ";

	// Range-based for statement: loop for baseado em intervalo
	for (const auto& numero : vector)
		cout << numero << DOIS_ESPACOS;

	cout << "\nTamanho: " << vector.size() << "\nCapacidade: " << vector.capacity() << endl << endl;
}

int main() {
	return TestarVector().testarVector();
}