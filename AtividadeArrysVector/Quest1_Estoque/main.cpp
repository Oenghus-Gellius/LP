#include "main.h"

#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

//Função faz o controle de estoque de acordo com tres categorias
int classificaEstoque() {
	string tipoProd[] = {"alimentos", "limpeza", "higiene"};
	const int qtdStock = 50;

	setlocale(LC_ALL, "pt-BR");

	Estoque alimentos(qtdStock), limpeza(qtdStock), higiene(qtdStock);
}

int main() {

	return classificaEstoque();
}