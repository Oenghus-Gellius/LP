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
#define RELATORIO "Relatório"
#define ALTERAR_LINHA "Alterar linha"
#define PESQUISAR_PALAVRA "Pesquisar palavra"
#define EXCLUIR_LINHA "Excluir linha"
#define SAIR "Sair"
#define ESCOLHA "Escolha"
#define PALAVRA "Palavra"

#define MSG_PROMPT_UNIVERSAL "Pressione qualquer tecla para retornar ao menu..."
#define MSG_TEXTO_VAZIO "- Não há nenhuma linha no texto."
#define MSG_LINHA_VAZIA ">> Digite # em uma linha vazia para retornar ao menu."
#define MSG_DADOS_DO_TEXTO ">> Dados do Texto"	
#define MSG_NUMERO_LINHAS "Número de Linhas: " 
#define MSG_QUANTIDADE_DE_PALAVRAS_DO_TEXTO "Quantidade de Palavras do Texto: "
#define MSG_RETORNO_AO_MENU ">> Digite -1 para retornar ao menu."
#define MSG_NOVO_CONTEUDO_DA_LINHA ">> Novo conteúdo da linha "
#define MSG_NUMERO_DE_OCORRENCIAS_DA_PALAVRA " Número de ocorrências da palavra no texto: "
#define MSG_LINHA_E_QUANTIDADE " Linha \t Quantidade"
#define MSG_PALAVRA_NAO_ENCONTRADA ">> A palavra não foi encontrada no texto."
#define MSG_CONFIRMACAO_EXCLUSAO "Confirma a exclusão, Sim (S) ou Não (N)? "
#define MSG_LINHA_EXCLUIDA ">> Linha excluída!"
#define MSG_LINHA_NAO_EXCLUIDA " Não foi possível excluir a linha: "
#define MSG_OPERACAO_CANCELADA ">> Operação de exclusão cancelada."
#define MSG_NUMERO_DA_LINHA "Número da Linha (1.."
#define MSG_NUMERO_DE_LINHA_INVALIDO ">> Número de linha inválido."
#define MSG_TEXTO ">> Texto"

constexpr unsigned  
	ASCII_CARACTERE_UM = 49,   // Código ASCII do caractere 1.
	NUMERO_MAXIMO_LINHAS = 50; // Número máximo de linhas do texto. 

/* Opções do menu do programa Editor de Linha.
 
   Por que a constante da enumeração abaixo é iniciada com 49? 
   Porque 49 é o código ASCII do caractere '1', já que '1' é o valor usado no menu do Editor de Linha.
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

	/* Exibe o menu do Editor de Linha, lê a opção do usuário e executa o comando escolhido.
	   Retorna EXIT_SUCCESS.
	*/
	int editorLinha(); 
	
	/*
		Permite adicionar linhas no fim do texto. Para cada linha fornecida pelo usuário deve ser criado um objeto Linha, configurar os seus atributos e 
		adicionar no objeto Texto. A entrada de dados deve ser finalizada quando o usuário digitar o caractere cerquilha (#) em uma linha vazia 
		na tela de edição de texto.
	*/
	void adicionarLinha();

	// Exibe o texto, o número de linhas do texto e a quantidade de palavras do texto.
	void relatorio();

	/*
		Altera uma linha de texto segundo o número da linha fornecido pelo usuário. 
		Lê o número da linha e verifica se ela existe, se sim, exibe o conteúdo da linha para que o usuário
		possa digitar o conteúdo da nova linha de texto. Se a linha não existe exibe a mensagem Linha inválida.
	*/
	void alterarLinha();

	/*
		Lê uma palavra, pesquisa no texto e exibe todas as ocorrências desta palavra no texto, incluindo o número das linhas e a 
		quantidade que a palavra aparece em cada linha. Se a palavra não for encontrada no texto exibe a mensagem 
		A palavra xxxxx não foi encontrada no texto.; onde xxxxx deve ser substituído pela palavra pesquisada.
	*/
	void pesquisarPalavra();

	/*
		Lê o número da linha e verifica se ela existe, se sim, exibe no console o conteúdo da linha de texto para que o usuário possa confirmar se ela deve ser excluída.
		Se a linha não existe, exibe a mensagem Linha inválida.
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

	// Lê, valida e obtém a opção do menu escolhida pelo usuário.
	Menu lerOpcaoMenu();

	// Constrói a tela com o nome do programa e da função escolhida pelo usuário no menu. Exibe o texto na tela.
	void tela(string titulo, string mensagem);

	// Lê o número da linha de texto. Retorna o número lido. Se a operação for cancelada retorna INT_MENOS_UM.
	int lerNumeroLinha(); 
	
	// Exibe as linhas de texto.
	void exibirTexto();

	// Lê e valida um número inteiro. O número lido é retornado pela função e usado para modificar o argumento real usado na chamada da função.
	int ler(int& numeroInteiro);

	// Lê e valida uma string. A string lida é retornada pela função e usada para modificar o argumento real usado na chamada da função. Não aceita uma string vazia.
	string ler(string& dado);

	/* Limpa a tela do console.
	   Esta função é implicitamente inline.
	*/ 
	void limpaTela() {
		system(CLS);
	}

	/* Exibe a mensagem "Pressione qualquer tecla para retornar ao menu..."
	   Esta função é implicitamente inline.
	*/ 
	void promptUniversal() {
		cout << endl << MSG_PROMPT_UNIVERSAL;
		if (_getch()) return;
	}
};