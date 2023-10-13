#pragma once

/*6. Desenvolva a implementa��o da classe Linha separando-a de sua interface que est� listada abaixo*/

#include <string>

using namespace std;

// Esta classe representa uma linha de texto.

class Linha {

public:
	// Inicia o objeto com valores nulos.
	Linha() = default;

	// Define um novo conte�do para a linha de texto.
	void setTexto(string texto);

	// Obt�m a linha de texto.
	string getTexto();

	// Obt�m a quantidade de caracteres da linha de texto.
	int getNumeroCaracteres();

	// Obt�m a quantidade de palavras da linha de texto.
	int quantidadePalavras();

private:

	string texto; // Conte�do da linha de texto.

	int numeroCaracteres = 0; // N�mero de caracteres da linha de texto.
};