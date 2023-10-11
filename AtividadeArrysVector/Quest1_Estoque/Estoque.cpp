#include "Estoque.h"

#include <iostream>
#include <cstdlib>
#include <clocale>

Estoque::Estoque(int tamanho)
{
	this->estoque = tamanho;
}

void Estoque::adicionarProduto(Produto p)
{
	if (true)
	{

	}


}

optional<Produto> Estoque::obterProduto(int posicao)
{
	return optional<Produto>();
}

int Estoque::pesquisarProduto(string nome)
{
	return 0;
}

bool Estoque::removerProduto(int posicao)
{
	return false;
}
