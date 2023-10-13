#include "Linha.h"

#include <iostream>
#include <ctype.h>

void Linha::setTexto(string texto) {
	this->texto = texto;
}

string Linha::getTexto() {
	return texto;
}

int Linha::getNumeroCaracteres() {
	return texto.length();
}

int Linha::quantidadePalavras() const {
	int count = 0;
	bool isWorld = false;

	for (char testChar : texto)
	{
		if (isalpha(testChar))
		{
			if(!isWorld)
			{
				isWorld = true;
				count++;
			}
		}
		else
		{
			isWorld = false;
		}
	}
	return count;
}

/*
bool Linha::pesquisaPalavra(const std::string& palavra) const
{
	// Dividir a linha em palavras usando um stringstream.
	istringstream iss(texto);
	string word;
	while (iss >> word) {
		// Comparar a palavra atual com a palavra fornecida.
		if (word == palavra) {
			return true; // A palavra foi encontrada.
		}
	}
	return false; // A palavra não foi encontrada.
}
*/
