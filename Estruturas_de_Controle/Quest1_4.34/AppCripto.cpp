#include "AppCripto.h"

#include <iostream>
#include <cstdlib>

int AppCripto::appCripto()
{
	Criptografia machCryptography;

	int numb;

	cout << "Por favor, digite um n�mero de quatro d�gitos." << endl;
	cin >> numb;
	
	cout << "N�mero criptografado: " << machCryptography.setNumEnc(numb) << endl;

	cout << "Teste reverso" << endl;

	cout << "N�mero descriptografado: " << machCryptography.setNumDec(numb) << endl;

	return EXIT_SUCCESS;
}


int main() {

	return AppCripto().appCripto();
}
