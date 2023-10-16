#include "HexToDecimal.h"

#include <iostream>
#include <string>

Hexadecimal::Hexadecimal(string base16)
{
	setNumero(base16);
}

void Hexadecimal::setNumero(string numero)
{
	this->numero = numero;
}

string Hexadecimal::hexadecimal() {
	return numero;
}


unsigned int Hexadecimal::decimal()
{
	int numDigit = numero.length();
	unsigned int result = 0;

	for (int i = 0; i < numDigit; i++)
	{
		char digit = numero[i];
		int digitValue;

		if (isdigit(digit)) {
			digitValue = digit - '0';
		}
		else if (isalpha(digit)) {
			digitValue = toupper(digit) - 'A' + 10;
		}
		else {
			// Se o dígito não for válido, trate o valor como 0.
			digitValue = 0;
		}

		result += digitValue * pow(16, numDigit - i - 1);
	}
	return result;
}

int TestDecToHex() {
	Hexadecimal numDecA;

	string hexNum = "AF45";

	numDecA.setNumero(hexNum);

	cout << "O numero Hexa " << hexNum << "  é em Decimal  " << numDecA.decimal() << endl;

	return EXIT_SUCCESS;
}

int main() {
	return TestDecToHex();
}
