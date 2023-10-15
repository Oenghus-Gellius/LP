#pragma once

/*
2. Crie um template de fun��o que forne�a a cria��o de fun��es para manipular arrays
unidimensionais (vetores) de qualquer tamanho e tipo de dado primitivo ou string do C++. 
Escreva um template para cada fun��o descrita abaixo.

a) Pesquisa no vetor por um elemento do tipo de dado do vetor. A fun��o deve retornar a
posi��o onde o elemento foi encontrado, caso contr�rio retorna -1.
b) Classifica os elementos do vetor em ordem ascendente.
c) Classificar os elementos do vetor em ordem descendente.
d) Exibe os elementos do vetor.

?ATEN��O: Armazene os templates de fun��o em um �nico arquivo de cabe�alho.
*/

#include <string>

using namespace std;

template<typename T, unsigned tamanho>
constexpr unsigned int tamanhoVetor(T (& vetor)[tamanho]);

class Template_Vetor
{
public:
	Template_Vetor() = default;

	//-----------------------
	template<typename T, unsigned tamanho>
	void criarVetor(T(&vetor)[tamanho]);

	//-------------------------
	
	//a) Pesquisa no vetor por um elemento do tipo de dado do vetor. A fun��o deve retornar a
	//posi��o onde o elemento foi encontrado, caso contr�rio retorna - 1.
	template<typename T, unsigned tamanho>
	int pesquisaInVetor(const T(&vetor)[tamanho], T elemento);

	//b) Classifica os elementos do vetor em ordem ascendente.
	template<typename T, unsigned tamanho>
	void ascendingOrder(T (& vetor)[tamanho]);

	//c) Classificar os elementos do vetor em ordem descendente.
	template<typename T, unsigned tamanho>
	void descendingOrder(T(&vetor)[tamanho]);

	//d) Exibe os elementos do vetor.
	template<typename T, unsigned tamanho>
	void exibir(const T (&vetor)[tamanho]);

	template<typename T, unsigned tamanho>
	int excluirArray(T (&vetor)[tamanho]);


	int TestVetor();
private:
	/*
	int intVetor;
	char charVetor;
	float floatVetor;
	string stringVetor;
	*/
};


