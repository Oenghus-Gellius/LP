#pragma once

#include "Curso.h"

constexpr unsigned char NUMERO_MAXIMO_DE_CURSOS = 5;

class Discente {
private:
	string nome;
	unsigned numeroAtualCursos = 0;

	// Representa a rela��o de cursos do discente usando um vetor de objetos da classe Curso.
	Curso cursos[NUMERO_MAXIMO_DE_CURSOS];

public:
	Discente() = default;
	Discente(string nome);

	void setNome(string nome);
	string getNome();

	// Obt�m o nome e a rela��o de cursos do discente.
	string toString();

	// Cadastra o discente em um curso. Se o cadastro foi feito retorna true, caso contr�rio, false.
	bool cadastrarCurso(Curso curso);

	/* Pesquisa um curso pelo nome. Se o discente est� cadastrado no curso retorna o objeto 
	     Curso com os seus atributos. Se o curso n�o existe ou se o discente n�o est� cadastrado 
		 no curso pesquisado, retorna um objeto Curso com atributos nulos.
	*/
	Curso pesquisarCurso(string nome);

	/* Obt�m um curso pelo nome. Se o discente est� cadastrado no curso retorna o objeto 
	    Curso com os seus atributos. Se o curso n�o existe ou se o discente n�o est� cadastrado 
		no curso pesquisado, retorna um objeto Curso com atributos nulos.
	*/
	Curso obterCurso(string nome);
};