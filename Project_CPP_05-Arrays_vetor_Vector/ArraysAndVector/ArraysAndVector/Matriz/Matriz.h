#pragma once

#include <string>

using namespace std;

#define MATRIZ "- matriz"

class Matriz {
public:
	// Apresenta o array bidimensional matriz.
	int matriz();

	/* Exibe uma mensagem e os elementos de uma matriz de qualquer tipo de dado, 
	      número de linhas e colunas.
	      Se não for especificada uma mensagem será exibido a mensagem abaixo:
	
				- Matriz de linhas x colunas
	*/
	template <typename T, int linhas, int colunas>
	void exibirMatriz(const T(&matriz)[linhas][colunas], string mensagem = MATRIZ);
};