#pragma once


#include <string>
using namespace std;
/*
Representa um objeto imut�vel com o valor de um n�mero inteiro positivo usando os algarismos ar�bicos
e romanos.
*/
class NumeroRomano {
private:
	string numeroRomano;
	unsigned int numeroArabico;
public:
	// Inicia os atributos do objeto NumeroRomano com os valores do n�mero ar�bico e romano.
	NumeroRomano(unsigned int numeroArabico);
	// Retorna o valor do n�mero romano.
	string getNumeroRomano();
	// Retorna o valor do n�mero ar�bico.
	unsigned int getNumeroArabico();
	/* Retorna uma string usando o formato N�meroAr�bico -> N�meroRomano
	 Exemplos:
	27 -> XXVII
	150 -> CL
	*/
	string toString();
	// Converte o n�mero ar�bico para romano.
	string converterArabicoParaRomano(unsigned int numeroArabico);
	// Converte o n�mero romano para ar�bico.
	unsigned int converterRomanoParaArabico(string numeroRomano);
};
