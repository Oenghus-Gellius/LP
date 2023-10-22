#pragma once

#include "Produto.h"
#include "Estoque.h"

/*
Implemente as duas classes definidas acima e crie um programa para:

a) Criar tr�s estoques de acordo com o tipo do produto: alimentos, limpeza e higiene pessoal.

b) Cadastrar no estoque o nome, a quantidade e o pre�o de um produto segundo o tipo do
estoque escolhido pelo usu�rio.

c) Calcular e exibir o valor total de cada estoque criado pelo usu�rio.

d) Calcular e exibir a quantidade de todos os produtos armazenados em cada estoque.

e) Localizar no estoque o nome de um produto fornecido pelo usu�rio.

f) Exibir um relat�rio usando o leiaute abaixo.

- Estoque de G�neros Aliment�cios
Produto				Quantidade		Pre�o Unit�rio		Valor Total
1. AAAA				99				99,99				R$ 9.999,99
2. BBBB				99				99,99				R$ 9.999,99
... ... ... ...
Total de Pe�as no Estoque: 999 Valor Total do Estoque:	R$ 999.999,99


*/
class Controle_Estoque
{
private:
	//Estoque alimentos, limpeza, higiene;

public:
	Controle_Estoque() = default;

	Controle_Estoque(Estoque tipoEstoque, int tamanho);

	int superMercadoAlpha();

	//b) Cadastrar no estoque o nome, a quantidade e o pre�o de um produto segundo o tipo do
	//estoque escolhido pelo usu�rio.
	int cadProdInEstoque(Estoque& nomeEstoque, string nome, int quatidade, double preco);
	
	//c) Calcular e exibir o valor total de cada estoque criado pelo usu�rio.
	float totalValorEstoque(Estoque tipoEstoque);

	//d) Calcular e exibir a quantidade de todos os produtos armazenados em cada estoque.
	int totalQtdProdEstoque(Estoque tipoEstoque);

	//e) Localizar no estoque o nome de um produto fornecido pelo usu�rio.
	int pesquisaProdutoEstoque(string produto);

	// f) Exibir um relat�rio usando o leiaute abaixo.
	void printEstoque(Estoque estoque);


};





