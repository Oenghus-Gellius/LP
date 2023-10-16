#include "TestarLivro.h"

#include "Livro.h"

#include <iostream>


int TestarLivro::testCadLivro()
{
	Livro livroA;
	Livro livroB(511, "A Origem", 50.0, "Dias. Bolivar", "Quinhetos11");

	livroA.printLivro();
	livroB.printLivro();

	livroA.setCode(123);
	livroA.setAutor("Oenghus");
	livroA.setValor(99.99);
	livroA.setTitulo("O Guerreiro");
	livroA.setEditora("Azeroph");

	livroA.printLivro();
	livroB.printLivro();

	cout << "cod.: " << livroA.getCode() << "- nome.: " << livroA.getTitulo() << "- valor.: "
		<< livroA.getValor() << endl;


	return EXIT_SUCCESS;
}

int main() {

	return TestarLivro().testCadLivro();
}
