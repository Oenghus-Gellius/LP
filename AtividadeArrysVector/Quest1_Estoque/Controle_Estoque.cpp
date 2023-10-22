#include "Controle_Estoque.h"
#include "estoque.h"
#include "Produto.h"

#include <iostream>

Controle_Estoque::Controle_Estoque(Estoque tipoEstoque, int tamanho)
{
	Estoque tipoEsoque = Estoque(tamanho);
}

int Controle_Estoque::superMercadoAlpha()
{ 
	Estoque Alimento;
	Estoque Limpleza;
	Estoque Higiene;

	int tamanhoEstoque = 50;

	Controle_Estoque(Alimento, tamanhoEstoque);
	Controle_Estoque(Limpleza, tamanhoEstoque);
	Controle_Estoque(Higiene, tamanhoEstoque);

	cadProdInEstoque(Alimento, "CocaCola", 13, 5.50);
	cadProdInEstoque(Alimento, "Pão de Forma", 9, 8.50);
	cadProdInEstoque(Alimento, "Feijão", 17, 5.50);

	cadProdInEstoque(Limpleza, "Veja clean", 18, 7.50);
	cadProdInEstoque(Limpleza, "Sabão", 48, 3.50);

	cadProdInEstoque(Higiene, "Escoca de dente", 13, 11.50);

	totalQtdProdEstoque(Alimento);

	totalQtdProdEstoque(Limpleza);

	totalQtdProdEstoque(Higiene);


	return 0;
}

int Controle_Estoque::cadProdInEstoque(Estoque& nomeEstoque, string nome, int quatidade, double preco)
{
	Produto p(nome,quatidade,preco);

	nomeEstoque.adicionarProduto(p);
	return 0;
}

float Controle_Estoque::totalValorEstoque(Estoque tipoEstoque)
{
	int index = 0;
	double valorTotalEstoque = 0.0;
	for (int i = 0; i < tipoEstoque.getQuantidadeEstoque(); i++)
	{
		valorTotalEstoque = valorTotalEstoque + (tipoEstoque.obterProduto(i)->getQuantidade() * tipoEstoque.obterProduto(i)->getPreco());
	}
	
	return valorTotalEstoque;
}

int Controle_Estoque::totalQtdProdEstoque(Estoque tipoEstoque)
{
	int index = 0;
	unsigned int qtdProdTotal = 0;
	
	for (int i = 0; i < tipoEstoque.getQuantidadeEstoque(); i++)
	{
		auto produtoOpt = tipoEstoque.obterProduto(i);
		if (produtoOpt.has_value())
		{
			qtdProdTotal = qtdProdTotal + produtoOpt->getQuantidade();
		}
	}

	cout << "Estoque.: " << "Quantidade de todos os produtos armazenados" << qtdProdTotal << endl;

	return qtdProdTotal;
}

void Controle_Estoque::printEstoque(Estoque estoque)
{
}

int main() {

	return Controle_Estoque().superMercadoAlpha();
}
