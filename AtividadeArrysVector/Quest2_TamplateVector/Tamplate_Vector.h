#pragma once

#include <vector>

/*
2. Crie um template de função que forneça a criação de funções para manipular arrays
unidimensionais (vetores) de qualquer tamanho e tipo de dado primitivo ou string do C++. Escreva
um template para cada função descrita abaixo.
a) Pesquisa no vetor por um elemento do tipo de dado do vetor. A função deve retornar a
posição onde o elemento foi encontrado, caso contrário retorna -1.
b) Classifica os elementos do vetor em ordem ascendente.
c) Classificar os elementos do vetor em ordem descendente.
d) Exibe os elementos do vetor.

?ATENÇÃO: Armazene os templates de função em um único arquivo de cabeçalho.
*/

using namespace std;

class Tamplate_Vector
{
private:
	vector<int> nElementos;
	vector<char> letras;	

public:
	//construtor default
	Tamplate_Vector() = default;

	//cria um vector do tipo TEMPLATE entrando o tamanho do tamplate e retorno o vector criado
	template<typename TEMP>
	vector<TEMP> bornTEMPVector(int size); //<===== SERA?

	//---------------------------------------------------
	//Preenche o vector TEMP para teste do projeto retorna um vetor preenchido;
	template<typename TEMP>
	void setVector(TEMP info, vector<TEMP>& vector);


	//b) Pesquisa no vetor por um elemento do tipo de dado do vetor. A função deve retornar a
	//posição onde o elemento foi encontrado, caso contrário retorna - 1.
	template<typename TEMP>
	int searchInVector(TEMP find, vector<TEMP>& vector);


	//b) Classifica os elementos do vetor em ordem ascendente.
	template<typename TEMP>
	void ascendVector(vector<TEMP>& vector);


	//c) Classificar os elementos do vetor em ordem descendente.
	template<typename TEMP>
	void descendVector(vector<TEMP>& vector);


	//d) Exibe os elementos do vetor.
	//Print o vector para teste, entra o vector mas nã retorna nada
	template<typename TEMP>
	void printVector(const vector<TEMP>& vector);

	template<typename TEMP>
	vector<TEMP>::size_type tamanho(const vector<TEMP>& vetor);

	template<typename TEMP>
	vector<TEMP>::size_type capacidade(const vector<TEMP>& vector);
};

void testTamplateVector();