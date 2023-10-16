#pragma once

/* 4. Crie uma classe denominada Livro com os seguintes atributos privados: 
c�digo, t�tulo e o pre�o do livro; nome do autor e da editora. 
Use o encapsulamento nessa classe e inclua os m�todos a seguir:

a) inicializar os atributos com valores default;
b) iniciar os atributos com valores especificados pelo usu�rio da classe;
c) consultar (get) e modificar (set) os atributos da classe;
d) retornar uma representa��o string com os atributos do livro. 
Use a declara��o: string toString();

5. Use a classe Livro, criada no Exerc�cio 4, para desenvolver um programa chamado TestarLivro com o
objetivo de testar todos os m�todos dessa classe.*/

#include <string>

using namespace std;

class Livro
{
private:
	int code = 0;
	string titulo = " ";
	float valor = 0.0;
	string autor =  " ";
	string editora =  " ";

public:
	Livro() = default;

	Livro(int code, string titulo, float valor, string autor, string editora);

	void setCode(int code);

	void setTitulo(string titulo);

	void setValor(float valor);

	void setAutor(string autor);

	void setEditora(string editora);

	int getCode();

	string getTitulo();

	float getValor();

	string getAutor();

	string getEditora();

	string toString();

	void printLivro();
};

