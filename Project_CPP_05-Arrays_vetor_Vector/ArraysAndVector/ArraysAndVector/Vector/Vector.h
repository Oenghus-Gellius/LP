#pragma once
#include <vector> // Requerido pelo template de classe vector do C++.

using namespace std;

// Representa um vetor dinâmico que armazena números inteiros (int).
class Vector {
private:
	vector<int> intVector; // O vector é um vetor dinâmico.

public:
	//O vector C++ é um vetor dinamico e está armazenara valores primitivos do tipo int
	Vector() = default;

	// Adiciona um número no Vector.
	void adicionar(int numero);

	// Obtém o número atual de elementos do vector.
	vector<int>::size_type tamanho();

	/* Obtém o número máximo de elementos do vector, ou seja, a capacidade atual de 
	   armazenar os elementos sem alocar memória. 
	*/
	vector<int>::size_type capacidade();

	// Exibe as propriedades (nome, elementos, tamanho e capacidade) do Vector.
	void printVector(string nome = "");

	// Apaga todos os números do Vector.
	void excluir();

	// Obtém uma cópia dos números do Vector.
	vector<int> getVector();

	/* Obtém uma referência do Vector.
	 
	   ATENÇÃO: ao retornar a referência de um atributo privado o código chamador do método 
	            abaixo poderá alterar esse atributo diretamente, ou seja, quebra-se o 
				encapsulamento. Portanto, essa é considerada uma prática de programação ruim.
	*/
	vector<int>& getRefVector();
};