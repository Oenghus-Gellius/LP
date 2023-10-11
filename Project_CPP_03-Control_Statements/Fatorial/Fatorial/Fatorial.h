#pragma once
#include <string>

class Fatorial {
private:
	unsigned numero = 0;

public:
	/* O uso da sintaxe "= default" no cabe�alho do construtor sem argumentos informa
	     ao compilador para ger�-lo e n�o � necess�rio implement�-lo, ou seja, n�o precisa
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
