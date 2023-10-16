#pragma once


#include <string>
using namespace std;
/*
Representa um objeto imutável com o valor de um número inteiro positivo usando os algarismos arábicos
e romanos.
*/
class NumeroRomano {
private:
	string numeroRomano;
	unsigned int numeroArabico;
public:
	// Inicia os atributos do objeto NumeroRomano com os valores do número arábico e romano.
	NumeroRomano(unsigned int numeroArabico);
	// Retorna o valor do número romano.
	string getNumeroRomano();
	// Retorna o valor do número arábico.
	unsigned int getNumeroArabico();
	/* Retorna uma string usando o formato NúmeroArábico -> NúmeroRomano
	 Exemplos:
	27 -> XXVII
	150 -> CL
	*/
	string toString();
	// Converte o número arábico para romano.
	string converterArabicoParaRomano(unsigned int numeroArabico);
	// Converte o número romano para arábico.
	unsigned int converterRomanoParaArabico(string numeroRomano);
};
