#include <iostream>
#include <clocale> // Requerido pelo setlocale
#include <cstdlib> // Requerido pelo EXIT_SUCCESS

#define SAUDACAO "\tBem-vindo a programação em C++.\n\tTchau!"
#define LC_PORTUGUES_BRASIL "pt-BR"

int olaMundo() {
	setlocale(LC_ALL, LC_PORTUGUES_BRASIL);
	std::cout << SAUDACAO 	<< std::endl;

	return EXIT_SUCCESS;
}

int main() {
	return olaMundo();
}

namespace Hector {
	struct Time {
		short day;
	};
}

namespace Igor {
	struct Time {
		int day;
	};
}

void namespaceTest() {
	// Namespace (espaço de nome)
	Hector::Time horaMG;
	Igor::Time horaAcre;

	horaAcre.day = 10;
	horaMG.day = 16;
}
