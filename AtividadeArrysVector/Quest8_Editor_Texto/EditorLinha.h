#pragma once

#include "Texto.h"
#include "Linha.h"



constexpr unsigned char NUMERO_MAXIMO_LINHAS = 50;
// Esta classe define as funções a serem implementadas pelo programa Editor de Linha.
class EditorLinha {
public:
	EditorLinha();
	/* Permite adicionar linhas no fim do texto. Para cada linha fornecida pelo usuário deve ser criado um
	objeto Linha, configurar os seus atributos e adicionar no objeto Texto. A entrada de dados deve ser
	finalizada quando o usuário digitar o caractere cerquilha (#) em uma linha vazia na tela de edição de
	texto.
	*/
	void adicionarLinha();
	// Exibe o texto, o número de linhas do texto e a quantidade de palavras do texto.
	void relatorio();
	/* Altera uma linha de texto segundo o número da linha fornecido pelo usuário. Lê o número da linha e
	verifica se ela existe, se sim, exibe o conteúdo da linha para que o usuário possa digitar o conteúdo
	da nova linha de texto. Se a linha não existe exibe a mensagem Linha inválida.
	*/
	void alterarLinha();
	/* Lê uma palavra, pesquisa no texto e exibe todas as ocorrências dessa palavra no texto, incluindo o
	número das linhas e a quantidade que a palavra aparece em cada linha. Se a palavra não for
	encontrada no texto exibe a mensagem A palavra “xxxxx” não foi encontrada no texto.; onde xxxxx
	deve ser substituído pela palavra pesquisada.
	*/
	void pesquisarPalavra();
	/* Lê o número da linha e verifica se ela existe, se sim, exibe o conteúdo da linha de texto para que o
	usuário possa confirmar se ela deve ser excluída. Se a linha não existe exibe a mensagem Linha
	inválida.
	*/
	void excluirLinha();
	/* Exibe o menu abaixo:
	- Editor de Linha
	1. Adicionar linha
	2. Relatório
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
