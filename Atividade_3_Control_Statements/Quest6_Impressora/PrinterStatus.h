#pragma once

/*6. Considere que um sistema para verificar o funcionamento da impressora consegue ler um valor da
memória desse hardware para sinalizar ao usuário o seu estado. Considere que as situações abaixo
são sinalizadas quando os bits 0 a 4 estão ligados (1) ou desligados (0).

b0 = impressora desligada (0) ou ligada (1)
b1 = impressora sem papel (0) ou com papel (1)
b2 = buffer com espaço livre (0) ou cheio (1)
b3 =cartucho de impressão preto vazio (0) ou com tinta (1)
b4 =cartucho de impressão tricolor vazio (0) ou com tinta (1)

Use a interface da classe abaixo para desenvolver um programa chamado PrinterStatusTest que:

1. leia um número inteiro sem sinal (unsigned char);

2. crie um objeto PrinterStatus para representar o estado da impressora com esse número;

3. informe ao usuário o estado atual da impressora invocando todos os métodos desse objeto.

O aplicativo deve ser finalizado quando o usuário digitar zero.

A implementação dos métodos da classe PrinterStatus deve considerar os valores dos primeiros
cinco (5) bits do número fornecido pelo usuário para obter o estado da impressora. Como esses
bits são usados para sinalizar o funcionamento da impressora e esse pode ser alterado a qualquer
instante, é possível que o programa informe que a impressora está, por exemplo, desligada, com
papel, o buffer está cheio, os cartuchos preto e colorido estão com tinta. No entanto, imagine a
seguinte situação: a impressora estava imprimindo um documento e o usuário a desligou
acidentalmente, ou seja, a impressora está com papel, os cartuchos preto e colorido estão com
tinta, o buffer está cheio e o seu estado mudou de ligada para desligada porque a impressão foi
interrompida quando o usuário desligou a impressora. Esse cenário exige que o programa fique
em loop lendo e informando o status da impressora até que o usuário tecle zero.*/

#include <iostream>


using namespace std;

// Representa um objeto imutável com o status da impressora.
class PrinterStatus {

private:

	unsigned char status;

public:

	// Inicia o objeto com o status inicial da impressora.
	PrinterStatus(unsigned char status);

	// Obtém o status atual da impressora.
	unsigned char getStatus();

	// Retorna true se a impressora está ligada ou false se está desligada.
	bool printerOn();

	// Retorna true se a impressora está com papel ou false se está sem papel.
	bool printerWithPaper();

	// Retorna true se o buffer da impressora está cheio ou false se está com espaço livre.
	bool printerBufferFull();

	// Informa true se o cartucho de impressão preto está com tinta ou false se está vazio.
	bool blackPrintCartridge();

	// Informa true se o cartucho de impressão tricolor está com tinta ou false se está vazio.
	bool tricolorPrintCartridge();

};