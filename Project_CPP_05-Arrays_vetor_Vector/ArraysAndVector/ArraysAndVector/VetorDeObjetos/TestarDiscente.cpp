#include <iostream>
#include <cstdlib>
#include <clocale>
#include "TestarDiscente.h"

// Testa os métodos das classes Discente e Curso.
int TestarDiscente::testarDiscente() 
{
    setlocale(LC_ALL, "pt-BR");

	string cursos[] = { "Biologia", "Física", "Matemática", "Sistemas Operacionais" };

	// Cria (instancia) e inicializa os objetos das classes Curso e Discente.
	Curso matematica, fisica(cursos[1], 80);
	Discente aline("Aline");

	// Exibe os atributos dos objetos da classe Curso.
	cout << matematica.toString() << endl << fisica.toString() << endl;

	// Altera os atributos do objeto Curso.
	matematica.setNome(cursos[2]);
	matematica.setCargaHoraria(120);

	// Exibe o nome e a carga horária dos cursos.
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
	for (const auto& curso : cursos)//auto é tipo string
		pesquisarCurso(aline, curso);

	// Exibe o nome e a relação de cursos da discente.
	cout << endl << aline.toString() << endl;

	return EXIT_SUCCESS;
} // testarDiscente()

// Exibe o nome e a carga horária do curso.
void TestarDiscente::exibirCurso(Curso curso) 
{
    cout << "Curso: " << curso.getNome() 
		 << " - Carga Horária: " << curso.getCargaHoraria() 
		 << " h\n";
}

/* Pesquisa e exibe o resultado da pesquisa de nome do curso na relação de
	   cursos do discente.
*/
void TestarDiscente::pesquisarCurso(Discente discente, string nome) 
{
    Curso curso = discente.pesquisarCurso(nome);

    if (curso.getNome().empty())
        cout << "\nO(A) discente " << discente.getNome() 
                 << " não está matriculada no curso " << nome << ".\n";
    else
        cout << "\nO(A) discente " << discente.getNome() << " está matriculada no curso " 
                << curso.getNome() << ".\n";
}

int main() {
    return TestarDiscente().testarDiscente();
}
