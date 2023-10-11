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

	// Obtém o objeto Produto armazenado no estoque na posição indicada.
	optional<Produto> obterProduto(int posicao);

	/* Pesquisa o nome do produto no estoque.
	Retorna a posição do produto no estoque, se o produto não estiver cadastrado retorna -1. */
	int pesquisarProduto(string nome);

	/* Exclui um produto do estoque na posição indicada. Retorna true se o produto foi excluído, caso
	contrário retorna false. */
	bool removerProduto(int posicao);

private:
	// Relação de produtos do estoque.
	vector<Produto> estoque;

	// Quantidade de produtos cadastrados no estoque.
	int quantidadeProdutos = 0;
};