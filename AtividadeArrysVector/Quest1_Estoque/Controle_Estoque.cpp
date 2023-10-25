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
	Estoque Limpeza;
	Estoque Higiene;

	int tamanhoEstoque = 50;

	Controle_Estoque(Alimento, tamanhoEstoque);
	Controle_Estoque(Limpeza, tamanhoEstoque);
	Controle_Estoque(Higiene, tamanhoEstoque);

	cadProdInEstoque(Alimento, "CocaCola", 13, 5.50);
	cadProdInEstoque(Alimento, "P�o de Forma", 9, 8.50);
	cadProdInEstoque(Alimento, "Feij�o", 17, 5.50);

	cadProdInEstoque(Limpeza, "Veja clean", 18, 7.50);
	cadProdInEstoque(Limpeza, "Sab�o", 48, 3.50);

	cadProdInEstoque(Higiene, "Escoca de dente", 13, 11.50);

	totalQtdProdEstoque(Alimento);

	totalQtdProdEstoque(Limpeza);

	totalQtdProdEstoque(Higiene);

	string produtoPesq = "Feij�o";

	int finder = 0;
	
	finder = pesquisaProdutoEstoque(Alimento, produtoPesq);
	if (!finder)
	{
		cout << "No estoque" << "Produdo localizado.: " << produtoPesq <<  endl;
	}
	else
	{
		cout << "Produdo n�o localizado.: " << produtoPesq << endl;
	}

	finder = pesquisaProdutoEstoque(Limpeza, produtoPesq);
	if (!finder)
	{
		cout << "Produdo localizado.: " << produtoPesq << endl;
	}
	else
	{
		cout << "Produdo n�o localizado.: " << produtoPesq << endl;
	}

	finder = pesquisaProdutoEstoque(Higiene, produtoPesq);
	if (!finder)
	{
		cout << "Produdo localizado.: " << produtoPesq << endl;
	}
	else
	{
		cout << "Produdo n�o localizado.: " << produtoPesq << endl;
	}

	cout << "- Estoque de G�neros Aliment�cios\n" << endl;
	printEstoque(Alimento);

	cout << "- Estoque de G�neros Limpeza\n" << endl;
	printEstoque(Limpeza);

	cout << "- Estoque de G�neros Higiene\n" << endl;
	printEstoque(Higiene);


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
	double valorTotalEstoque = 0.0;
	auto produtoOpt = tipoEstoque.obterProduto(0);
	for (int i = 0; i < tipoEstoque.getQuantidadeEstoque(); i++)
		 produtoOpt = tipoEstoque.obterProduto(i);
		if (produtoOpt.has_value())
		{
			valorTotalEstoque = valorTotalEstoque + (produtoOpt.value().getQuantidade() * produtoOpt.value().getPreco());
		}
	
	return valorTotalEstoque;
}

int Controle_Estoque::totalQtdProdEstoque(Estoque& tipoEstoque)
{
	int index = 0;
	unsigned int qtdProdTotal = 0;

	index = tipoEstoque.getQuantidadeEstoque();
	for (int i = 0; i < index; i++)
	{
		auto produtoOpt = tipoEstoque.obterProduto(i);
		if (produtoOpt.has_value())
		{
			qtdProdTotal = qtdProdTotal + produtoOpt.value().getQuantidade();
		}
	}

	cout << "Estoque.: " << "Quantidade de todos os produtos armazenados" << qtdProdTotal << endl;

	return qtdProdTotal;
}

int Controle_Estoque::pesquisaProdutoEstoque(Estoque estoque, string produto)
{
	for (int i = 0; i < estoque.getQuantidadeEstoque(); i++)
	{
		if (!estoque.pesquisarProduto(produto))
		{
			return 0;
		}
	}
	return -1;
}

void Controle_Estoque::printEstoque(Estoque estoque)
{
	auto produtoOpt = estoque.obterProduto(0);
	cout << "Produto" << "\t\t" << "Quantidade\t" << "Preco Unitario\t" << "\tValor Total" << endl;
	for (int i = 0; i < estoque.getQuantidadeEstoque(); i++)
	{
		produtoOpt = estoque.obterProduto(i);
		if (produtoOpt.has_value())
		{
			cout << (i + 1) << ". " << produtoOpt.value().getNome() << "\t\t\t\t" << produtoOpt.value().getQuantidade() << "\t\t" << produtoOpt.value().getPreco() << "\t" << (produtoOpt.value().getQuantidade() * produtoOpt.value().getPreco()) << endl;
		}
	}
	cout << "... ... ... ... ... " << endl;
	cout << "Total de Pe�as no Estoque: " << totalQtdProdEstoque(estoque) << " .: R$ " << totalValorEstoque(estoque) << endl;

}

int main() {

	return Controle_Estoque().superMercadoAlpha();
}
