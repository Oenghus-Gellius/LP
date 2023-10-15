#pragma once

/*
3. Desenvolva um programa chamado HexToDecimal que leia um n�mero representado no sistema
hexadecimal (base 16) e converta este n�mero para o sistema decimal (base 10). Para efetuar a
convers�o utilize a seguinte f�rmula:

Dn-1* 16n-1 + Dn-2* 16n-2 + .... + D1* 161 + D0* 160 , onde:

a) Di � um d�gito do n�mero hexadecimal na posi��o i;
b) n � a quantidade de d�gitos hexadecimais;
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

	// Define o valor do n�mero hexadecimal (base 16).
	void setNumero(string numero);

	// Obt�m o n�mero em hexadecimal (base 16).
	string hexadecimal();

	// Obt�m o n�mero em decimal (base 10). O n�mero decimal � calculado usando a f�rmula acima.
	unsigned int decimal();

};

