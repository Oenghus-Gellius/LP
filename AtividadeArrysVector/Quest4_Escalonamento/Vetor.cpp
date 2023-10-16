#include "Vetor.h"

#include <iostream>


Vetor::Vetor(int tamanho)
{
	definirTamanho(tamanho);
}

Vetor::Vetor(int tamanho, int limiteInferior, int limiteSuperior)
{
	definirTamanho(tamanho);
	this->limiteInferior = limiteInferior;
	this->limiteSuperior = limiteSuperior;

	definirIntervalo(limiteInferior, limiteSuperior);
}

void Vetor::setNome(string nome)
{
	this->nome = nome;
}

string Vetor::getNome()
{
	return nome;
}

int Vetor::getLimiteInferior()
{
	return limiteInferior;
}

int Vetor::getLimiteSuperior()
{
	return limiteSuperior;
}

int Vetor::tamanho()
{
	return vetor.size();
}

int Vetor::capacidade()
{
	return vetor.capacity();
}

void Vetor::definirIntervalo(int limiteInferior, int limiteSuperior)
{
	this->limiteInferior = limiteInferior;
	this->limiteSuperior = limiteSuperior;

	int valorIntervalo = limiteSuperior - limiteInferior + 1;
	int totalParcial = limiteInferior;
	int incremento = valorIntervalo / tamanho();

	for (int i = 0; i < tamanho(); i++)
	{
		vetor[i] = totalParcial;
		totalParcial = totalParcial + incremento;
	}
}

bool Vetor::adicionar(int numero)
{
	if (tamanho() < capacidade())
	{
		vetor.push_back(numero);
		return true;
	}
	return false;
}

int Vetor::obter(int& indice)
{
	if (indice <= limiteInferior && indice >= limiteSuperior)
	{
		indice = 0;
		return 0;
	}
	else
	{
		int indice_Real = indiceReal(indice);
		if (indice_Real <= 0 && indice_Real >= tamanho())
		{
			indice = 1;
		}
		return vetor[indice_Real];
	}
}

bool Vetor::alterar(int indice, int numero)
{
	if (indice >= limiteInferior && indice <= limiteSuperior)
	{
		int indice_Real = indiceReal(indice);
		if (indice_Real >= 0 && indice_Real <= tamanho())
		{
			vetor[indice_Real] = numero;
			return true;
		}
	}
	return false;
}

bool Vetor::excluir(int indice)//vou partir do pressuposto que é virtual pq ai sim faz sentido ter uma função indiceReal()
{
	if (indice >= limiteInferior && indice <= limiteSuperior)
	{
		int indice_Real = indiceReal(indice);
		if (indice_Real >= 0 && indice_Real <= tamanho())
		{
			vetor.erase(vetor.begin() + indice_Real);
			return true;
		}
	}
	return false;
}

int Vetor::comparar(Vetor vetorComp)
{
	if (tamanho() == vetorComp.tamanho())
	{
		for (int i = 0; i < tamanho(); i++)
		{
			if (vetor[i] != vetorComp.vetor[i])
			{
				return vetor[i] - vetorComp.vetor[i];
			}
		}
		return 0;
	}
	return tamanho() - vetorComp.tamanho();
}

bool Vetor::copiar(Vetor vetorFont)
{
	if (tamanho() >= vetorFont.tamanho())
	{
		for (int i = 0; i < vetorFont.tamanho(); i++)
		{
			vetor[i] = vetorFont.vetor[i];
		}
		return true;
	}
	return false;
}

void Vetor::exibir()
{
	if (!getNome().empty())
	{
		cout << "Nome Vetor.: " << getNome() << endl;
		for (int i = 0; i < tamanho(); i++)
		{
			cout << vetor[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Vetor vazio" << endl;
	}
}

int Vetor::indiceReal(int indiceVirtual)
{
	if (indiceVirtual >= limiteInferior && indiceVirtual <= limiteSuperior)
	{
		return indiceVirtual - limiteInferior;
	}
	return 0;
}

void Vetor::definirTamanho(int tamanho)
{
	vetor.resize(tamanho);
}
