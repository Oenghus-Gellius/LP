#include <iostream>
#include <cstdlib>
#include <clocale>
#include <iomanip> // Requerido por setprecision.
#include <ios>          // Requerido por fixed.
#include "Matriz.h"

int main() {
	return Matriz().matriz();
}

// Apresenta o array bidimensional matriz.
int Matriz::matriz() {
	int matriz3x3[][3] = { {1,2,3}, // Linha 0
										  {4,5,6}, // Linha 1
										  {7,8,9} }; // Linha 2
	float matriz2x2[][2] = { 1.536f, 2.536f, 3.536f, 4.536f };
	string matriz4x2[][2] = { "terra", "sol", "lua", "mar", "água", "fogo", "ar", "marte" };

	setlocale(LC_ALL, "pt-BR");

	exibirMatriz(matriz3x3);
	exibirMatriz(matriz2x2, "- matriz 2x2 de float\n");
	exibirMatriz(matriz4x2, "- matriz 4x2 de strings\n");

	return EXIT_SUCCESS;
}

/* Exibe uma mensagem e os elementos de uma matriz de qualquer tipo de dado, 
     número de linhas e colunas. Se não for especificada uma mensagem será exibido a 
	 mensagem abaixo:

			- Matriz de linhas x colunas
*/
template <typename T, int linhas, int colunas>
void Matriz::exibirMatriz(const T(&matriz)[linhas][colunas], string mensagem) 
{
	if (mensagem == MATRIZ)
		cout << mensagem << " de " << linhas << " x " << colunas << endl;
	else
		cout << mensagem;

	// Fixa o ponto decimal no número real e define o número de casas decimais.
	cout << fixed << setprecision(2);

	// Exibe a matriz no formato tabular.
	for (int lin = 0; lin < linhas; lin++) {
		for (int col = 0; col < colunas; col++)
			cout << " " << matriz[lin][col] << "\t";
		cout << endl; // Avança o cursor para exibir a próxima linha da matriz.
	}
	cout << endl;
}
