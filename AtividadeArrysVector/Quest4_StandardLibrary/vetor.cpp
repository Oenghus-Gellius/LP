#include "vetor.h"

#include <iostream>

/*
Vetor::Vetor(int tamanho)//ok
{
	definirTamanho(tamanho);
}

Vetor::Vetor(int tamanho, int limiteInferior, int limiteSuperior)//ok
{
	definirTamanho(tamanho);
	this->limiteInferior = limiteInferior;
	this->limiteSuperior = limiteSuperior;

	definirIntervalo(limiteInferior, limiteSuperior);
}

void Vetor::setNome(string nome)//ok
{
	this->nome = nome;
}

string Vetor::getNome()//ok
{
	return nome;
}

int Vetor::getLimiteInferior()//ok
{
	return limiteInferior;
}

int Vetor::getLimiteSuperior()//ok
{
	return limiteSuperior;
}

int Vetor::tamanho()//ok
{
	return vetor.size();
}

int Vetor::capacidade()//ok
{
	return limiteSuperior - limiteInferior + 1;
}

void Vetor::definirIntervalo(int limiteInferior, int limiteSuperior)//ok
{
	this->limiteInferior = limiteInferior;
	this->limiteSuperior = limiteSuperior;

	definirTamanho(capacidade());

	int intervalo = limiteSuperior - limiteInferior + 1;
	int incremento = intervalo / tamanho();

	int valorAtual = limiteInferior;

	for (int i = 0; i < tamanho(); i++)
	{
		vetor[i] = valorAtual;

		valorAtual = valorAtual + incremento;
	}
}

bool Vetor::adicionar(int numero)//ok
{
	if (tamanho() < capacidade())
	{
		vetor.push_back(numero);
		return true;
	}
	else
	{
		return false;
	}
}

int Vetor::obter(int& indice)//ok
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

bool Vetor::alterar(int indice, int numero)//ok
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

bool Vetor::excluir(int indice)//ok
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

int Vetor::comparar(Vetor comparado)//ok
{

	if (tamanho() == comparado.tamanho())
	{
		for (int i = 0; i < tamanho(); i++)
		{
			if (vetor[i] != comparado.vetor[i])
			{
				return vetor[i] - comparado.vetor[i];
			}
		}
		return 0;
	}
	return tamanho() - comparado.tamanho();
}

bool Vetor::copiar(Vetor fontVetor)//ok
{
	if (tamanho() >= fontVetor.tamanho())
	{
		for(int i = 0; i < fontVetor.tamanho(); i++)
		{
			vetor[i] = fontVetor.vetor[i];
		}
		return true;
	}
	return false;
}

void Vetor::exibir()//ok
{
	if (!getNome().empty())
	{
		cout << "Nome vetor.: " << getNome() << "\n" << endl;
	}
	for (int i = 0; i < tamanho(); i++)
	{
		cout << vetor[i] << " ";
	}
	cout << endl;
}

int Vetor::indiceReal(int indiceVirtual)//ok
{
	if (indiceVirtual <= limiteInferior && indiceVirtual >= limiteSuperior)
	{
		return 0;
	}
	else
	{
		/*
		int indexReal = 0;
		for (int i = limiteInferior; i < limiteSuperior; i++)
		{
			indexReal++;
		}
		return indexReal;
		return indiceVirtual - limiteInferior;
	}
	// Opção 2 e 3 HAUHAUHAUHAUAHuhaAHUAHAUHAUHA
	//return limiteInferior + indiceVirtual;
}

void Vetor::definirTamanho(int tamanho)//ok
{
	vetor.resize(tamanho);
}


*/