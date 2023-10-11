#pragma once

#include "Discente.h"

class TestarDiscente { 
public:
	// Testa os m�todos das classes Discente e Curso.
	int testarDiscente();

	// Exibe o nome e a carga hor�ria do curso.
	void exibirCurso(Curso curso);

	/* Pesquisa e exibe o resultado da pesquisa de nome do curso na rela��o de 
	   cursos do discente.
	*/
	void pesquisarCurso(Discente discente, string nome);
};

