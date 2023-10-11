#include "Tamplate_Vector.h"

#include <iostream>
#include <cstdlib>

template<typename TEMP>
vector<TEMP> Tamplate_Vector::bornTEMPVector(int size)
{
	return vector <TEMP>(size);
}

vector<int> Tamplate_Vector::setVector(int info)
{
	nElementos.push_back(info);
	return nElementos;
}

vector<char> Tamplate_Vector::setVector(char info)
{
	letras.push_back(info);
	return letras;
}

//--------------------------------------------------------------------
template<typename TEMP>
void Tamplate_Vector::setVector(TEMP info, vector<TEMP> &vector)
{
	vector.push_back(info);
}


template<typename TEMP>
int Tamplate_Vector::searchInVector(TEMP find, vector<TEMP> &vector)
{
	int achou = 0;
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i] == find)
		{
			return i;
		}
	}
	return -1;
}

template<typename TEMP>
void Tamplate_Vector::ascendVector(vector<TEMP>& vector)
{
	TEMP aux;
	for (int i = 0; i < vector.size() -1; i++)
	{
		for (int j = 0; j < vector.size() - i - 1; j++)
		{
			if (vector[j] > vector[j + 1])
			{
				aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;
			}
		}
	}
}

template<typename TEMP>
void Tamplate_Vector::descendVector(vector<TEMP>& vector)
{
	TEMP aux;
	for (int i = 0; i < vector.size() - 1; i++)
	{
		for (int j = 0; j < vector.size() - i - 1; j++)
		{
			if (vector[j] < vector[j + 1])
			{
				aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;
			}
		}
	}
}

template<typename TEMP>
inline void Tamplate_Vector::printVector(const vector<TEMP>& vector)
{
	for (const auto& element : vector)
	{
		cout << element << " ";
	}
	cout << "\nTamanho" << tamanho(vector) << "\nCapacidade" << capacidade(vector) << "\n" << endl;
}

template<typename TEMP>
vector<TEMP>::size_type Tamplate_Vector::tamanho(const vector<TEMP>& vector)
{
	return vector.size();
}

template<typename TEMP>
vector<TEMP>::size_type Tamplate_Vector::capacidade(const vector<TEMP>& vector)
{
	return vector.capacity();
}

void testTamplateVector(){

	Tamplate_Vector vectorTestA;
	Tamplate_Vector vectorTestB;

	vector<int> nElementos = { 12, 25, 98, 34 };

	vector<char> letras = {'C','S','W','R','Q','E' };

	int num = 2;
	int finderA = 98;
	char finderB = 'R';
	int position = 0;
	

	vectorTestA.printVector(nElementos);
	vectorTestB.printVector(letras);

	for (const auto& vectorA : nElementos)
	{
		num = num + num - 1;
		vectorTestA.setVector(num,nElementos);
	}
	vectorTestA.printVector(nElementos);

	position = vectorTestA.searchInVector(finderA, nElementos);
	
	if (position != -1)
	{
		cout << "Numero encontrado " << finderA << " Na posição  " << position << endl;
	}
	else
	{
		cout << "Numero não encontrado!!!!" << endl;
	}

	position = vectorTestB.searchInVector(finderB, letras);

	if (position != -1)
	{
		cout << "Numero encontrado " << finderB << " Na posição  " << position << endl;
	}
	else
	{
		cout << "Numero não encontrado!!!!" << endl;
	}

	vectorTestA.ascendVector(nElementos);
	vectorTestA.printVector(nElementos);
	vectorTestB.ascendVector(letras);
	vectorTestB.printVector(letras);

	vectorTestA.descendVector(nElementos);
	vectorTestA.printVector(nElementos);
	vectorTestB.descendVector(letras);
	vectorTestB.printVector(letras);
}

int main() {
	testTamplateVector();
	return 0;
}
