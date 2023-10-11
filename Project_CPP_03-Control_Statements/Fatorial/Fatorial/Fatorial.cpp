#include <iostream>
#include <string>
#include <cstdlib>
#include "Fatorial.h"

using namespace std;

Fatorial::Fatorial(unsigned numero) {
	setNumero(numero);
}

void Fatorial::setNumero(unsigned numero) {
	this->numero = numero;
}

unsigned Fatorial::getNumero() {
	return numero; // equivale a return this->numero;
}

std::string Fatorial::toString() {
	return "Fatorial de " + std::to_string(numero) + " = " + std::to_string(calcular(numero));
}

// Calcula e retorna o fatorial do atributo numero do objeto Fatorial.
unsigned long long Fatorial::calcular() {
	return calcular(this->numero);
}

// Calcula e retorna o fatorial de numero.
unsigned long long Fatorial::calcular(unsigned int numero) {
	unsigned long long fatorial = 1;

	for (unsigned n = 1; n <= numero; n++)
		fatorial *= n; // equivale a fatorial = fatorial * n; 

	return fatorial;
}

// Testa os métodos da classe Fatorial.
int fatorial() {
	Fatorial cinco, dez(10), quinze(15);

	cinco.setNumero(5);

	cout << "\t5! = " << cinco.calcular() 
		     << "\n\t10! = " << dez.calcular() 
			 << "\n\t15! = " << quinze.calcular();

	cout << "\n\n\t" << cinco.toString()
		 << "\n\t" << dez.toString()
		 << "\n\t" << quinze.toString() << endl;

	Fatorial fatorial;
	for (unsigned fat = 1; fat <= 9; fat++)
		cout << "\n\t" << fat << "! = " << fatorial.calcular(fat);
	
	cout << endl;
	return EXIT_SUCCESS;
}

int main() {
	return fatorial();
}
