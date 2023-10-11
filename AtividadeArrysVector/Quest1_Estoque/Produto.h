#pragma once

#include <string>

using namespace std;
class Produto {
public:
	Produto() = default;

	Produto(string nome, int quantidade, double preco);

	void setNome(string nome);

	void setQuantidade(int quantidade);

	void setPreco(double preco);

	string getNome();

	int getQuantidade();

	double getPreco();

private:

	string nome; // Nome do produto.

	int quantidade = 0; // Quantidade do produto armazenada em estoque.

	double preco = 0; // Preço unitário do produto.
};

