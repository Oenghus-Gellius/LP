#pragma once

/*
3. Desenvolva um programa chamado HexToDecimal que leia um número representado no sistema
hexadecimal (base 16) e converta este número para o sistema decimal (base 10). Para efetuar a
conversão utilize a seguinte fórmula:

Dn-1* 16n-1 + Dn-2* 16n-2 + .... + D1* 161 + D0* 160 , onde:

a) Di é um dígito do número hexadecimal na posição i;
b) n é a quantidade de dígitos hexadecimais;
c) 0 <= i < n

Exemplos:
a) (FF)16 = 15*161 + 15*160 = 15*16 + 15*1 = (255)10
b) (20)16 = 2*161 + 0*160 = 2*16 + 0*1 = (32)10
c) (5DC)16 = 5*162 + 13*161 + 12*160 = 5*256 + 13*16 + 12*1 = (1500)10

Use a interface da classe abaixo para implementar esse aplicativo.
*/

#include <string>

using namespace std;

class Hexadecimal {

private:

	string numero;
public:

	Hexadecimal() = default;

	Hexadecimal(string base16);

	// Define o valor do número hexadecimal (base 16).
	void setNumero(string numero);

	// Obtém o número em hexadecimal (base 16).
	string hexadecimal();

	// Obtém o número em decimal (base 10). O número decimal é calculado usando a fórmula acima.
	unsigned int decimal();

};

