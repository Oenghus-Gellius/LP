#include "Linha.h"

#include <ctype.h>
#include <iostream>

void Linha::setTexto(string texto)
{
	this->texto = texto;
}

string Linha::getTexto()
{
	return texto;
}

int Linha::getNumeroCaracteres()
{
	return texto.length();
}

int Linha::quantidadePalavras()
{
	int count = 0;
	bool isWorld = false;

	for (char testChar : texto)
	{
		if (isalpha(testChar))
		{
			if (!isWorld)
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
