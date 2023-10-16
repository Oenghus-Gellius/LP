#pragma once

#include "Texto.h"
#include "Linha.h"



constexpr unsigned char NUMERO_MAXIMO_LINHAS = 50;

// Esta classe define as fun��es a serem implementadas pelo programa Editor de Linha.
class EditorLinha {
public:
	EditorLinha();

	/* Permite adicionar linhas no fim do texto. Para cada linha fornecida pelo usu�rio deve ser criado um
	objeto Linha, configurar os seus atributos e adicionar no objeto Texto. A entrada de dados deve ser
	finalizada quando o usu�rio digitar o caractere cerquilha (#) em uma linha vazia na tela de edi��o de
	texto.	*/
	void adicionarLinha();

	// Exibe o texto, o n�mero de linhas do texto e a quantidade de palavras do texto.
	void relatorio();

	/* Altera uma linha de texto segundo o n�mero da linha fornecido pelo usu�rio. L� o n�mero da linha e
	verifica se ela existe, se sim, exibe o conte�do da linha para que o usu�rio possa digitar o conte�do
	da nova linha de texto. Se a linha n�o existe exibe a mensagem Linha inv�lida.
	*/
	void alterarLinha();

	/* L� uma palavra, pesquisa no texto e exibe todas as ocorr�ncias dessa palavra no texto, incluindo o
	n�mero das linhas e a quantidade que a palavra aparece em cada linha. Se a palavra n�o for
	encontrada no texto exibe a mensagem A palavra �xxxxx� n�o foi encontrada no texto.; onde xxxxx
	deve ser substitu�do pela palavra pesquisada.	*/
	void pesquisarPalavra();

	/* L� o n�mero da linha e verifica se ela existe, se sim, exibe o conte�do da linha de texto para que o
	usu�rio possa confirmar se ela deve ser exclu�da. Se a linha n�o existe exibe a mensagem Linha
	inv�lida.	*/
	void excluirLinha();

	//Obtem um objeto optmal cpm o objeto Linha
	optional<Linha> linhaOptional = texto.obterLinha(numeroLinhas);

	//recupera o objeto linha do objeto optonal para alterar o seu conteudo
	Linha linha = linhaOptional.value();

	//Altera o conteudo da linha de texto
	//linha.setLinha(conteudo);

	//Altera a linha no texto
	//texto.alterarLinha(numeroLinha, linha);

	/* Exibe o menu abaixo:
	- Editor de Linha
	1. Adicionar linha
	2. Relat�rio
	3. Alterar linha
	4. Pesquisar palavra
	5. Excluir linha
	6. Sair
	Escolha:
	*/
	void menu();

private:

	Texto texto; // Representa o texto do programa.
}; // class EditorLinha
