#include "Estoque.h"

#include <iostream>
#include <cstdlib>
#include <clocale>
#include <iomanip>

Estoque::Estoque(int tamanho)
{
	estoque.reserve(tamanho);
}

void Estoque::adicionarProduto(Produto p)
{
	estoque.push_back(p);
	quantidadeProdutos++;
}

optional<Produto> Estoque::obterProduto(int posicao)
{
	if (posicao >= 0 && posicao < quantidadeProdutos)
	{
		return optional<Produto>(estoque[posicao]);
	}
	else
	{
		return nullopt;
	}
}

int Estoque::pesquisarProduto(string nome)
{
	for (int i = 0; i < quantidadeProdutos; i++)
	{
		if (nome == estoque[i].getNome())
		{
			return i;
		}
	}
	return -1;
}

bool Estoque::removerProduto(int posicao)
{
	if (posicao >= 0 && posicao < quantidadeProdutos)
	{
		estoque.erase(estoque.begin() + posicao);
		quantidadeProdutos--;
		return true;
	}
	return false;
}

void Estoque::printRelatoriun(string info)
{
	double valorTotalStock = 0;

	cout << "Estoque de Gêneros " << info << "\n" << endl;
	cout << "Produto\t\tQuantidade\tPreço Unitário\tValor Total\n" << endl;

	for (int i = 0; i < quantidadeProdutos; i++)
	{
		Produto produto = estoque[i];
		double valorTotalProd = produto.getQuantidade() * produto.getPreco();
		valorTotalStock += valorTotalProd;

		cout << i + 1 << ". " << produto.getNome() << "\t" << produto.getQuantidade() << "\t";
		cout << fixed << setprecision(2) << "\t" << produto.getPreco() << "\tR$ " << valorTotalProd << "\n";
	}

	cout << "Total de Peças no Estoque: " << quantidadeProdutos << " Valor Total do Estoque: R$ " << valorTotalStock << "\n" << endl;
}

