#include "AppCripto.h"

#include <iostream>
#include <cstdlib>

int AppCripto::appCripto()
{
	Criptografia machCryptography;

	int numb;

	cout << "Por favor, digite um número de quatro dígitos." << endl;
	cin >> numb;
	
	cout << "Número criptografado: " << machCryptography.setNumEnc(numb) << endl;

	cout << "Teste reverso" << endl;

	cout << "Número descriptografado: " << machCryptography.setNumDec(numb) << endl;

	return EXIT_SUCCESS;
}


int main() {

	return AppCripto().appCripto();
}
