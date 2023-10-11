#pragma once
#include <string>

class Fatorial {
private:
	unsigned numero = 0;

public:
	/* O uso da sintaxe "= default" no cabeçalho do construtor sem argumentos informa
	     ao compilador para gerá-lo e não é necessário implementá-lo, ou seja, não precisa
		 definir o seu corpo.
	*/ 
	Fatorial() = default;
	Fatorial(unsigned numero);

	void setNumero(unsigned numero);
	unsigned getNumero();

	std::string toString();

	// Calcula e retorna o fatorial do atributo numero do objeto Fatorial.
	unsigned long long calcular();

	// Calcula e retorna o fatorial de numero.
	unsigned long long calcular(unsigned int numero);
}; // class Fatorial 
