#pragma once

#include <string>

using namespace std;

// Classe para representar uma linha de texto.
class Linha {
public:
	// Inicia o objeto com valores nulos. 
	Linha() = default;

	// Define um novo conte�do para a linha de texto.
	void setLinha(string linha);

	// Obt�m a linha de texto.
	string getLinha();

	// Obt�m a quantidade de caracteres da linha de texto.
	int getNumeroCaracteres();

	// Calcula a quantidade de palavras da linha de texto.
	int quantidadePalavras();

	// Calcula a quantidade de palavras da linha de texto iguais ao par�metro palavra.
	int quantidadePalavras(string palavra);

private:
	string linha; 	// Conte�do da linha de texto.
	int numeroCaracteres = 0; // N�mero de caracteres da linha de texto.
};