#pragma once

/*6. Desenvolva a implementação da classe Linha separando-a de sua interface que está listada abaixo*/

#include <string>

using namespace std;

// Esta classe representa uma linha de texto.

class Linha {

public:
	// Inicia o objeto com valores nulos.
	Linha() = default;

	// Define um novo conteúdo para a linha de texto.
	void setTexto(string texto);

	// Obtém a linha de texto.
	string getTexto();

	// Obtém a quantidade de caracteres da linha de texto.
	int getNumeroCaracteres();

	// Obtém a quantidade de palavras da linha de texto.
	int quantidadePalavras() const;

	/*/ Função para pesquisar uma palavra na linha.
	bool pesquisaPalavra(const std::string& palavra) const;
	*/
private:

	string texto; // Conteúdo da linha de texto.

	int numeroCaracteres = 0; // Número de caracteres da linha de texto.
};