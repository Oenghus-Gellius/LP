#include "Template_Vetor.h"

#include <iostream>

template<typename T, unsigned tamanho>
inline constexpr unsigned int tamanhoVetor(T(&vetor)[tamanho])
{
	return tamanho;
}

template<typename T, unsigned tamanho>
void Template_Vetor::criarVetor(T(&vetor)[tamanho])
{
}

template<typename T, unsigned tamanho>
inline int Template_Vetor::pesquisaInVetor(const T(&vetor)[tamanho], T elemento)
{
	for (int i = 0; i < tamanho; i++)
	{
		if (vetor[i] == elemento)
		{
			return i;
		}
	}
	return -1;
}

template<typename T, unsigned tamanho>
void Template_Vetor::ascendingOrder(T(&vetor)[tamanho])
{
	T aux;
	for (int i = 0; i < tamanho - 1; i++)
	{
		for (int j = 0; j < tamanho - i - 1; j++)
		{
			if (vetor[j] > vetor[j + 1])
			{
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}

template<typename T, unsigned tamanho>
void Template_Vetor::descendingOrder(T(&vetor)[tamanho])
{
	T aux;
	for (int i = 0; i < tamanho - 1; i++)
	{
		for (int j = 0; j < tamanho - i - 1; j++)
		{
			if (vetor[j] < vetor[j + 1])
			{
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
		}
	}
}


template<typename T, unsigned tamanho>
void Template_Vetor::exibir(const T(&vetor)[tamanho])
{
	cout << "\nVetor.: ";
	for (int i = 0; i < tamanho; i++)
	{
		cout << vetor[i] << " ";
	}
}


int Template_Vetor::TestVetor()
{
	//Objetos
	Template_Vetor intVetor;
	Template_Vetor charVetor;
	Template_Vetor floatVetor;
	Template_Vetor stringVetor;

	int vetorA[] = {5, 4, 23, 6, 7, 9, 10, 87};
	char vetorB[] = { 'V','C','P','D','H','I','O' };
	float vetorC[] = {2.34,3.67, 5.78, 0.34, 34.5};
	string vetorD[] = { "mission", "arabian", "muslin", "solucion", "counter" };

	intVetor.exibir(vetorA);
	intVetor.ascendingOrder(vetorA);
	intVetor.exibir(vetorA);
	intVetor.descendingOrder(vetorA);
	intVetor.exibir(vetorA);

	charVetor.exibir(vetorB);
	charVetor.ascendingOrder(vetorB);
	charVetor.exibir(vetorB);
	charVetor.descendingOrder(vetorB);
	charVetor.exibir(vetorB);

	floatVetor.exibir(vetorC);
	floatVetor.ascendingOrder(vetorC);
	floatVetor.exibir(vetorC);
	floatVetor.descendingOrder(vetorC);
	floatVetor.exibir(vetorC);

	stringVetor.exibir(vetorD);
	stringVetor.ascendingOrder(vetorD);
	stringVetor.exibir(vetorD);
	stringVetor.descendingOrder(vetorD);
	stringVetor.exibir(vetorD);

	return EXIT_SUCCESS;
}

int main() {

	return Template_Vetor().TestVetor();
}