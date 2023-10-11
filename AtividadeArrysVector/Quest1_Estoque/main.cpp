#include "main.h"

#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;


//Função faz o controle de estoque de acordo com tres categorias
int ControlStock::admStock()
{
	Produto prod1("CocaCola", 13, 5.50);
	Produto prod2("Veja clean", 18, 7.50);
	Produto prod3("Sabão", 48, 3.50);
	Produto prod4("Pão de Forma", 9, 8.50);
	Produto prod5("Feijão", 17, 5.50);
	Produto prod6("Escoca de dente", 13, 11.50);

	Estoque stockFood;
	Estoque stockHygiene;
	Estoque stockCleaning;

	setlocale(LC_ALL, "pt-BR");

	stockFood.adicionarProduto(prod1);
	stockCleaning.adicionarProduto(prod2);
	stockCleaning.adicionarProduto(prod3);
	stockFood.adicionarProduto(prod4);
	stockFood.adicionarProduto(prod5);
	stockHygiene.adicionarProduto(prod6);

	stockFood.printRelatoriun("Alimentício");
	stockCleaning.printRelatoriun("Produtos de Limpeza");
	stockHygiene.printRelatoriun("Produtos de Higiene Pessoal");

	return EXIT_SUCCESS;
}

int main() {
	return ControlStock().admStock();
}


