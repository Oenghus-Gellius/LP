#pragma once
/*
(Criptografia) Uma empresa quer transmitir dados por telefone, mas está preocupada com a possibilidade de seus telefones estarem
grampeados. Todos os dados são transmitidos como inteiros de quatro dígitos. A empresa solicitou que escrevêssemos um programa
que encriptasse dados para que pudessem ser transmitidos com maior segurança. Seu programa deve ler um inteiro de quatro dígitos e
encriptá-lo como mostrado a seguir: Substitua cada dígito pelo (a soma desse dígito mais 7) módulo 10. Em seguida, troque o primeiro
dígito pelo terceiro, o segundo dígito pelo quarto e imprima o inteiro encriptado. Escreva um programa separado que aceita como entrada
um inteiro de quatro dígitos criptografado e o descriptografe para formar o número original.
*/

#include <iostream>

using namespace std;

class Criptografia{
private:

	int num;

	//Função privada que guarda a chave de decripitação
	int decrypt(int num);

	//Função privada que guarda a chave de encripitação
	int encrypt(int num);

public:
	//Constructor defaut
	Criptografia() = default;

	//Constructor sobrecarregado
	Criptografia(int num);

	//Entra com o numero com 4 digitos - O numero é encripiato retorno o numero desejado
	int setNumDec(int num);

	//Entra com o numero com 4 digitos - Entra com o numero "cetro" e sai o numero decripitação
	int setNumEnc(int num);
};
