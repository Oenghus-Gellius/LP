#include "Livro.h"

#include <iostream>

Livro::Livro(int code, string titulo, float valor, string autor, string editora)
{
	setCode(code);
	setTitulo(titulo);
	setValor(valor);
	setAutor(autor);
	setEditora(editora);
}

void Livro::setCode(int code)
{
	this->code = code;
}

void Livro::setTitulo(string titulo)
{
	this->titulo = titulo;
}

void Livro::setValor(float valor)
{
	this->valor = valor;
}

void Livro::setAutor(string autor)
{
	this->autor = autor;
}

void Livro::setEditora(string editora)
{
	this->editora = editora;
}

int Livro::getCode()
{
	return code;
}

string Livro::getTitulo()
{
	return titulo;
}

float Livro::getValor()
{
	return valor;
}

string Livro::getAutor()
{
	return autor;
}

string Livro::getEditora()
{
	return editora;
}

string Livro::toString()
{
	return "Codigo.: " + to_string(code) + "\n"
		+ "Titulo.: " + titulo + "\n"
		+ "Valor: R$" + to_string(valor) + "\n"
		+ "Autor: " + autor + "\n"
		+ "Editora: " + editora + "\n";
}

void Livro::printLivro()
{
	cout << toString() << endl;
}
