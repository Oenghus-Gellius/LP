// Estoque.h - Interface da classe Estoque
#pragma once
#include <vector>
#include <optional>

#include "Produto.h"

class Estoque {
public:
	// Cria um estoque de produtos com tamanho inicial igual a zero.
	Estoque() = default;

	// Cria um estoque de produtos com capacidade de armazenamento inicial definido por tamanho.
	Estoque(int tamanho);

	// Acrescenta um produto no estoque.
	void adicionarProduto(Produto p);

	// Obt�m o objeto Produto armazenado no estoque na posi��o indicada.
	optional<Produto> obterProduto(int posicao);

	/* Pesquisa o nome do produto no estoque.
	Retorna a posi��o do produto no estoque, se o produto n�o estiver cadastrado retorna -1. */
	int pesquisarProduto(string nome);

	/* Exclui um produto do estoque na posi��o indicada. Retorna true se o produto foi exclu�do, caso
	contr�rio retorna false. */
	bool removerProduto(int posicao);

	int getQuantidadeEstoque();

private:

	// Rela��o de produtos do estoque.
	vector<Produto> estoque;

	// Quantidade de produtos cadastrados no estoque.
	int quantidadeProdutos = 0;
};
