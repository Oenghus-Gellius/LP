#include "criptografia.h"

#include <string>
#include <iostream>


Criptografia::Criptografia(int num)
{
	this->num = num;
}

int Criptografia::decrypt(int num)
{
	//Separando os digitos
	int n1, n2, n3, n4;

	n1 = (num / 1000 + 3) % 10;
	n2 = ((num / 100) % 10 + 3) % 10;
	n3 = ((num / 10) % 10 + 3) % 10;
	n4 = (num % 10 + 3) % 10;

	// Trocando os dígitos 1 e 3, e os dígitos 2 e 4
	return n3 * 1000 + n4 * 100 + n1 * 10 + n2;
}

int Criptografia::encrypt(int num)
{
	//Separando os digitos
	int n1, n2, n3, n4;
	n1 = (num / 1000 + 7) % 10;
	n2 = ((num / 100) % 10 + 7) % 10;
	n3 = ((num / 10) % 10 + 7) % 10;
	n4 = (num % 10 + 7) % 10;

	// Trocando os dígitos 1 e 3, e os dígitos 2 e 4
	return n3 * 1000 + n4 * 100 + n1 * 10 + n2;
}

int Criptografia::setNumDec(int num)
{
	if (num >= 1000 && num <= 9999)
	{
		this->num = decrypt(this->num);
	}
	else
	{
		cout << "NUMERO INVALIDO" << endl;
	}
	return this->num;
}

int Criptografia::setNumEnc(int num)
{
	if (num >= 1000 && num <= 9999)
	{
		this->num = encrypt(num);
	}
	else
	{
		cout << "NUMERO INVALIDO" << endl;
	}
	return this->num;
}
