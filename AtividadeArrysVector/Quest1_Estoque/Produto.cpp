#include "Produto.h"

#include <iostream>

Produto::Produto(string nome, int quantidade, double preco)
{
	setNome(nome);
	setQuantidade(quantidade);
	setPreco(preco);
}

void Produto::setNome(string nome)
{
	this->nome = nome;
}

void Produto::setQuantidade(int quantidade)
{
	this->quantidade = quantidade;
}

void Produto::setPreco(double preco)
{
	this->preco = preco;
}

string Produto::getNome()
{
	return nome;
}

int Produto::getQuantidade()
{
	return quantidade;
}

double Produto::getPreco()
{
	return preco;
}
