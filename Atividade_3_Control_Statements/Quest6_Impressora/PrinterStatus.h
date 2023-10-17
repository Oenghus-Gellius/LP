#pragma once

/*6. Considere que um sistema para verificar o funcionamento da impressora consegue ler um valor da
mem�ria desse hardware para sinalizar ao usu�rio o seu estado. Considere que as situa��es abaixo
s�o sinalizadas quando os bits 0 a 4 est�o ligados (1) ou desligados (0).

b0 = impressora desligada (0) ou ligada (1)
b1 = impressora sem papel (0) ou com papel (1)
b2 = buffer com espa�o livre (0) ou cheio (1)
b3 =cartucho de impress�o preto vazio (0) ou com tinta (1)
b4 =cartucho de impress�o tricolor vazio (0) ou com tinta (1)

Use a interface da classe abaixo para desenvolver um programa chamado PrinterStatusTest que:

1. leia um n�mero inteiro sem sinal (unsigned char);

2. crie um objeto PrinterStatus para representar o estado da impressora com esse n�mero;

3. informe ao usu�rio o estado atual da impressora invocando todos os m�todos desse objeto.

O aplicativo deve ser finalizado quando o usu�rio digitar zero.

A implementa��o dos m�todos da classe PrinterStatus deve considerar os valores dos primeiros
cinco (5) bits do n�mero fornecido pelo usu�rio para obter o estado da impressora. Como esses
bits s�o usados para sinalizar o funcionamento da impressora e esse pode ser alterado a qualquer
instante, � poss�vel que o programa informe que a impressora est�, por exemplo, desligada, com
papel, o buffer est� cheio, os cartuchos preto e colorido est�o com tinta. No entanto, imagine a
seguinte situa��o: a impressora estava imprimindo um documento e o usu�rio a desligou
acidentalmente, ou seja, a impressora est� com papel, os cartuchos preto e colorido est�o com
tinta, o buffer est� cheio e o seu estado mudou de ligada para desligada porque a impress�o foi
interrompida quando o usu�rio desligou a impressora. Esse cen�rio exige que o programa fique
em loop lendo e informando o status da impressora at� que o usu�rio tecle zero.*/

#include <iostream>


using namespace std;

// Representa um objeto imut�vel com o status da impressora.
class PrinterStatus {

private:

	unsigned char status;

public:

	// Inicia o objeto com o status inicial da impressora.
	PrinterStatus(unsigned char status);

	// Obt�m o status atual da impressora.
	unsigned char getStatus();

	// Retorna true se a impressora est� ligada ou false se est� desligada.
	bool printerOn();

	// Retorna true se a impressora est� com papel ou false se est� sem papel.
	bool printerWithPaper();

	// Retorna true se o buffer da impressora est� cheio ou false se est� com espa�o livre.
	bool printerBufferFull();

	// Informa true se o cartucho de impress�o preto est� com tinta ou false se est� vazio.
	bool blackPrintCartridge();

	// Informa true se o cartucho de impress�o tricolor est� com tinta ou false se est� vazio.
	bool tricolorPrintCartridge();

};