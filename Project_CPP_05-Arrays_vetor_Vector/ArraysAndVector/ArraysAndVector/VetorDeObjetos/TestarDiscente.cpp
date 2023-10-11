#include <iostream>
#include <cstdlib>
#include <clocale>
#include "TestarDiscente.h"

// Testa os m�todos das classes Discente e Curso.
int TestarDiscente::testarDiscente() 
{
    setlocale(LC_ALL, "pt-BR");

	string cursos[] = { "Biologia", "F�sica", "Matem�tica", "Sistemas Operacionais" };

	// Cria (instancia) e inicializa os objetos das classes Curso e Discente.
	Curso matematica, fisica(cursos[1], 80);
	Discente aline("Aline");

	// Exibe os atributos dos objetos da classe Curso.
	cout << matematica.toString() << endl << fisica.toString() << endl;

	// Altera os atributos do objeto Curso.
	matematica.setNome(cursos[2]);
	matematica.setCargaHoraria(120);

	// Exibe o nome e a carga hor�ria dos cursos.
	cout << endl;
	exibirCurso(fisica);
	exibirCurso(matematica);

	// Cadastra os cursos para a discente.
	aline.cadastrarCurso(matematica);
	aline.cadastrarCurso(fisica);
	aline.cadastrarCurso(Curso(cursos[3], 90));

	/* Pesquisa pelos cursos da discente usando o 
	   Range-based for statement (loop for baseado em intervalo).
	*/
	for (const auto& curso : cursos)//auto � tipo string
		pesquisarCurso(aline, curso);

	// Exibe o nome e a rela��o de cursos da discente.
	cout << endl << aline.toString() << endl;

	return EXIT_SUCCESS;
} // testarDiscente()

// Exibe o nome e a carga hor�ria do curso.
void TestarDiscente::exibirCurso(Curso curso) 
{
    cout << "Curso: " << curso.getNome() 
		 << " - Carga Hor�ria: " << curso.getCargaHoraria() 
		 << " h\n";
}

/* Pesquisa e exibe o resultado da pesquisa de nome do curso na rela��o de
	   cursos do discente.
*/
void TestarDiscente::pesquisarCurso(Discente discente, string nome) 
{
    Curso curso = discente.pesquisarCurso(nome);

    if (curso.getNome().empty())
        cout << "\nO(A) discente " << discente.getNome() 
                 << " n�o est� matriculada no curso " << nome << ".\n";
    else
        cout << "\nO(A) discente " << discente.getNome() << " est� matriculada no curso " 
                << curso.getNome() << ".\n";
}

int main() {
    return TestarDiscente().testarDiscente();
}
