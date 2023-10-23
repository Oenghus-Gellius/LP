#pragma once

#include <conio.h> // _getch()
#include "Texto.h"

// Constantes usadas no programa Editor de Linha.
#define LOCALE_PORTUGUES_BRASIL "pt-BR"
#define CLS "cls"
#define CERQUILHA "#"
#define TABULACAO_HORIZONTAL "\t"
#define STRING_NULA ""
#define STRING_MENOS_UM "-1"
#define INT_MENOS_UM -1
#define PONTO_E_ESPACO ". "
#define DOIS_PONTO_ESPACO ": "
#define ESPACO_HIFEN_ESPACO " - "
#define HIFEN_ESPACO "- "
#define LINHA_UM 1

#define EDITOR_DE_LINHA "Editor de Linha"
#define ADICIONAR_LINHA "Adicionar linha"
#define RELATORIO "Relat�rio"
#define ALTERAR_LINHA "Alterar linha"
#define PESQUISAR_PALAVRA "Pesquisar palavra"
#define EXCLUIR_LINHA "Excluir linha"
#define SAIR "Sair"
#define ESCOLHA "Escolha"
#define PALAVRA "Palavra"

#define MSG_PROMPT_UNIVERSAL "Pressione qualquer tecla para retornar ao menu..."
#define MSG_TEXTO_VAZIO "- N�o h� nenhuma linha no texto."
#define MSG_LINHA_VAZIA ">> Digite # em uma linha vazia para retornar ao menu."
#define MSG_DADOS_DO_TEXTO ">> Dados do Texto"	
#define MSG_NUMERO_LINHAS "N�mero de Linhas: " 
#define MSG_QUANTIDADE_DE_PALAVRAS_DO_TEXTO "Quantidade de Palavras do Texto: "
#define MSG_RETORNO_AO_MENU ">> Digite -1 para retornar ao menu."
#define MSG_NOVO_CONTEUDO_DA_LINHA ">> Novo conte�do da linha "
#define MSG_NUMERO_DE_OCORRENCIAS_DA_PALAVRA " N�mero de ocorr�ncias da palavra no texto: "
#define MSG_LINHA_E_QUANTIDADE " Linha \t Quantidade"
#define MSG_PALAVRA_NAO_ENCONTRADA ">> A palavra n�o foi encontrada no texto."
#define MSG_CONFIRMACAO_EXCLUSAO "Confirma a exclus�o, Sim (S) ou N�o (N)? "
#define MSG_LINHA_EXCLUIDA ">> Linha exclu�da!"
#define MSG_LINHA_NAO_EXCLUIDA " N�o foi poss�vel excluir a linha: "
#define MSG_OPERACAO_CANCELADA ">> Opera��o de exclus�o cancelada."
#define MSG_NUMERO_DA_LINHA "N�mero da Linha (1.."
#define MSG_NUMERO_DE_LINHA_INVALIDO ">> N�mero de linha inv�lido."
#define MSG_TEXTO ">> Texto"

constexpr unsigned  
	ASCII_CARACTERE_UM = 49,   // C�digo ASCII do caractere 1.
	NUMERO_MAXIMO_LINHAS = 50; // N�mero m�ximo de linhas do texto. 

/* Op��es do menu do programa Editor de Linha.
 
   Por que a constante da enumera��o abaixo � iniciada com 49? 
   Porque 49 � o c�digo ASCII do caractere '1', j� que '1' � o valor usado no menu do Editor de Linha.
*/ 
enum class Menu { 
	EL_ADICIONAR_LINHA = ASCII_CARACTERE_UM, // 49
	EL_RELATORIO, 
	EL_ALTERAR_LINHA, 
	EL_PESQUISAR_PALAVRA, 
	EL_EXCLUIR_LINHA, 
	EL_SAIR 
};

class EditorLinha { 
public:
	EditorLinha() = default;

	/* Exibe o menu do Editor de Linha, l� a op��o do usu�rio e executa o comando escolhido.
	   Retorna EXIT_SUCCESS.
	*/
	int editorLinha(); 
	
	/*
		Permite adicionar linhas no fim do texto. Para cada linha fornecida pelo usu�rio deve ser criado um objeto Linha, configurar os seus atributos e 
		adicionar no objeto Texto. A entrada de dados deve ser finalizada quando o usu�rio digitar o caractere cerquilha (#) em uma linha vazia 
		na tela de edi��o de texto.
	*/
	void adicionarLinha();

	// Exibe o texto, o n�mero de linhas do texto e a quantidade de palavras do texto.
	void relatorio();

	/*
		Altera uma linha de texto segundo o n�mero da linha fornecido pelo usu�rio. 
		L� o n�mero da linha e verifica se ela existe, se sim, exibe o conte�do da linha para que o usu�rio
		possa digitar o conte�do da nova linha de texto. Se a linha n�o existe exibe a mensagem Linha inv�lida.
	*/
	void alterarLinha();

	/*
		L� uma palavra, pesquisa no texto e exibe todas as ocorr�ncias desta palavra no texto, incluindo o n�mero das linhas e a 
		quantidade que a palavra aparece em cada linha. Se a palavra n�o for encontrada no texto exibe a mensagem 
		A palavra xxxxx n�o foi encontrada no texto.; onde xxxxx deve ser substitu�do pela palavra pesquisada.
	*/
	void pesquisarPalavra();

	/*
		L� o n�mero da linha e verifica se ela existe, se sim, exibe no console o conte�do da linha de texto para que o usu�rio possa confirmar se ela deve ser exclu�da.
		Se a linha n�o existe, exibe a mensagem Linha inv�lida.
	*/
	void excluirLinha();

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

	// L�, valida e obt�m a op��o do menu escolhida pelo usu�rio.
	Menu lerOpcaoMenu();

	// Constr�i a tela com o nome do programa e da fun��o escolhida pelo usu�rio no menu. Exibe o texto na tela.
	void tela(string titulo, string mensagem);

	// L� o n�mero da linha de texto. Retorna o n�mero lido. Se a opera��o for cancelada retorna INT_MENOS_UM.
	int lerNumeroLinha(); 
	
	// Exibe as linhas de texto.
	void exibirTexto();

	// L� e valida um n�mero inteiro. O n�mero lido � retornado pela fun��o e usado para modificar o argumento real usado na chamada da fun��o.
	int ler(int& numeroInteiro);

	// L� e valida uma string. A string lida � retornada pela fun��o e usada para modificar o argumento real usado na chamada da fun��o. N�o aceita uma string vazia.
	string ler(string& dado);

	/* Limpa a tela do console.
	   Esta fun��o � implicitamente inline.
	*/ 
	void limpaTela() {
		system(CLS);
	}

	/* Exibe a mensagem "Pressione qualquer tecla para retornar ao menu..."
	   Esta fun��o � implicitamente inline.
	*/ 
	void promptUniversal() {
		cout << endl << MSG_PROMPT_UNIVERSAL;
		if (_getch()) return;
	}
};