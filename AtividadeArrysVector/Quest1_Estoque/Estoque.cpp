#include "Estoque.h"

#include <iostream>

Estoque::Estoque(int tamanho)
{
	estoque.resize(tamanho);
}

void Estoque::adicionarProduto(Produto p)
{
	estoque.push_back(p);
	quantidadeProdutos++;
}

optional<Produto> Estoque::obterProduto(int posicao)
{
	if (posicao > 0 && posicao < quantidadeProdutos)
	{
		for (int i = 0; i < posicao; i++)
		{
			return optional<Produto>(estoque[posicao]);
		}
	}
	return nullopt;
}

int Estoque::pesquisarProduto(string nome)
{
	for (int i = 0; i < quantidadeProdutos; i++)
	{
		if (nome == estoque[i].getNome());
		{

			return i;
		}
	}
	return -1;
}

bool Estoque::removerProduto(int posicao)
{
	if (posicao > 0 && posicao < quantidadeProdutos)
	{
		for (int i = posicao; i < quantidadeProdutos - 1; i++)
		{
			estoque[i] = estoque[i + 1];
		}
		quantidadeProdutos--;
		estoque.resize(quantidadeProdutos);
		/*	Solução 2
		estoque.erase(estoque.begin() + posicao);
		quantidadeProdutos--;		*/
		return true;
	}
	return false;
}

int Estoque::getQuantidadeEstoque()
{
	return this->quantidadeProdutos;
}
