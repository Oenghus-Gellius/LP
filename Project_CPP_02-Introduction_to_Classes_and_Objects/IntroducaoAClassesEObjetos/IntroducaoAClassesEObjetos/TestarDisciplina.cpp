#include <iostream>
#include <cstdlib>
#include <clocale>
#include <format> // Requerido por format.
#include "Disciplina.h"

// Exibe no console os atributos do objeto Disciplina.
void exibirDisciplina(Disciplina disciplina) {
	// printf("%s , Nota: %1.2f\n", disciplina.getNome(), disciplina.getNota());
	cout << format("{} , Nota: {:1.2f}\n", disciplina.getNome(), disciplina.getNota());
}

// Apresenta os métodos da classe Disciplina.
int testarDisciplina() {
	setlocale(LC_ALL, "pt-BR");

	/* Cria(instancia) os objetos da classe Disciplina.Usa, respectivamente, os construtores
	*   default (padrão) e sobrecarregado.
	*/
	Disciplina matematica, fisica("Física", 8.59F), biologia("Biologia", 7.8324f);

	/* Exibe os atributos do objeto da classe Disciplina usando os métodos get.

		// ERRO: não é possível acessar um membro privado fora da classe.
		 cout << matematica.nota;

		 Enviar uma mensagem a um objeto na terminologia da orientação a objetos é fazer
		 uma chamada de método.
	*/
	cout << matematica.getNome() << ": " << matematica.getNota() << endl
		<< fisica.getNome() << ": " << fisica.getNota() << endl;

	/* Modifica os atributos do objeto matematica da classe Disciplina.
	*
	*			matematica.nome = "Matemática"; // ERRO: nome é privado
	*/
	matematica.setNome("Matemática");
	matematica.setNota(9.57F);

	// Exibe os atributos do objeto da classe Disciplina usando o método toString.
	cout << matematica.toString() << endl;

	exibirDisciplina(biologia);

	return EXIT_SUCCESS;
} // testarDisciplina() 

// Inicia o programa C++.
int main() {
	return testarDisciplina();
}