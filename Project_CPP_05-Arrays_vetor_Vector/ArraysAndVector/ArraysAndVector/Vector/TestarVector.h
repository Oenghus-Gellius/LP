#pragma once

#include <vector>
#include <string> 

using namespace std;

class TestarVector {
public: 
	// Apresenta as propriedades da classes Vector e vector.
	int testarVector();

	// Exibe as propriedades (nome, elementos, tamanho e capacidade) do vector de caracteres.
	void printVector(const vector<char>& vector, string nome = "");
	
};
