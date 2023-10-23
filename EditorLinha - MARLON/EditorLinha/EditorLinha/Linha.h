#pragma once

#include <string>

using namespace std;

// Classe para representar uma linha de texto.
class Linha {
public:
	// Inicia o objeto com valores nulos. 
	Linha() = default;

	// Define um novo conteúdo para a linha de texto.
	void setLinha(string linha);

	// Obtém a linha de texto.
	string getLinha();

	// Obtém a quantidade de caracteres da linha de texto.
	int getNumeroCaracteres();

	// Calcula a quantidade de palavras da linha de texto.
	int quantidadePalavras();

	// Calcula a quantidade de palavras da linha de texto iguais ao parâmetro palavra.
	int quantidadePalavras(string palavra);

private:
	string linha; 	// Conteúdo da linha de texto.
	int numeroCaracteres = 0; // Número de caracteres da linha de texto.
};