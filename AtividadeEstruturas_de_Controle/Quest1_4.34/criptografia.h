#pragma once
/*
(Criptografia) Uma empresa quer transmitir dados por telefone, mas est� preocupada com a possibilidade de seus telefones estarem
grampeados. Todos os dados s�o transmitidos como inteiros de quatro d�gitos. A empresa solicitou que escrev�ssemos um programa
que encriptasse dados para que pudessem ser transmitidos com maior seguran�a. Seu programa deve ler um inteiro de quatro d�gitos e
encript�-lo como mostrado a seguir: Substitua cada d�gito pelo (a soma desse d�gito mais 7) m�dulo 10. Em seguida, troque o primeiro
d�gito pelo terceiro, o segundo d�gito pelo quarto e imprima o inteiro encriptado. Escreva um programa separado que aceita como entrada
um inteiro de quatro d�gitos criptografado e o descriptografe para formar o n�mero original.
*/

#include <iostream>

using namespace std;

class Criptografia{
private:

	int num;

	//Fun��o privada que guarda a chave de decripita��o
	int decrypt(int num);

	//Fun��o privada que guarda a chave de encripita��o
	int encrypt(int num);

public:
	//Constructor defaut
	Criptografia() = default;

	//Constructor sobrecarregado
	Criptografia(int num);

	//Entra com o numero com 4 digitos - O numero � encripiato retorno o numero desejado
	int setNumDec(int num);

	//Entra com o numero com 4 digitos - Entra com o numero "cetro" e sai o numero decripita��o
	int setNumEnc(int num);
};
