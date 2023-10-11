#pragma once
#include <vector> // Requerido pelo template de classe vector do C++.

using namespace std;

// Representa um vetor din�mico que armazena n�meros inteiros (int).
class Vector {
private:
	vector<int> intVector; // O vector � um vetor din�mico.

public:
	//O vector C++ � um vetor dinamico e est� armazenara valores primitivos do tipo int
	Vector() = default;

	// Adiciona um n�mero no Vector.
	void adicionar(int numero);

	// Obt�m o n�mero atual de elementos do vector.
	vector<int>::size_type tamanho();

	/* Obt�m o n�mero m�ximo de elementos do vector, ou seja, a capacidade atual de 
	   armazenar os elementos sem alocar mem�ria. 
	*/
	vector<int>::size_type capacidade();

	// Exibe as propriedades (nome, elementos, tamanho e capacidade) do Vector.
	void printVector(string nome = "");

	// Apaga todos os n�meros do Vector.
	void excluir();

	// Obt�m uma c�pia dos n�meros do Vector.
	vector<int> getVector();

	/* Obt�m uma refer�ncia do Vector.
	 
	   ATEN��O: ao retornar a refer�ncia de um atributo privado o c�digo chamador do m�todo 
	            abaixo poder� alterar esse atributo diretamente, ou seja, quebra-se o 
				encapsulamento. Portanto, essa � considerada uma pr�tica de programa��o ruim.
	*/
	vector<int>& getRefVector();
};