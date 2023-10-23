#include <iostream>
#include <locale>
#include <iomanip>
#include <sstream>

#include "EditorLinha.h"

int main() {
	return EditorLinha().editorLinha();
}

/* Exibe o menu do Editor de Linha, l� a op��o do usu�rio e executa o comando escolhido.
   Retorna EXIT_SUCCESS.
*/
int EditorLinha::editorLinha() {
	Menu opcao;

	setlocale(LC_ALL, LOCALE_PORTUGUES_BRASIL);

	do { menu();
		 opcao = lerOpcaoMenu();

		 // Valida e executa a op��o de menu escolhida pelo usu�rio.
		 if (opcao == Menu::EL_ADICIONAR_LINHA) 
			 adicionarLinha();
		 else
			if (opcao < Menu::EL_SAIR)
				if (texto.getNumeroLinhas() > 0)
					switch (opcao) 
					{
						case Menu::EL_RELATORIO: relatorio(); break;
						case Menu::EL_ALTERAR_LINHA: alterarLinha(); break;
						case Menu::EL_PESQUISAR_PALAVRA: pesquisarPalavra(); break;
						case Menu::EL_EXCLUIR_LINHA: excluirLinha();
					}
				else { cout << endl << endl << MSG_TEXTO_VAZIO << endl;
					   promptUniversal();
					 }
	} while (opcao != Menu::EL_SAIR);
	cout << endl << endl;
	return EXIT_SUCCESS;
}

/*
	Permite adicionar linhas no fim do texto. Para cada linha fornecida pelo usu�rio deve ser criado um objeto Linha, configurar os seus atributos e
	adicionar no objeto EditorLinha. A entrada de dados deve ser finalizada quando o usu�rio digitar o caractere cerquilha (#) em uma linha vazia
	na tela de edi��o de texto.
*/
void EditorLinha::adicionarLinha() {
	Linha linha;
	string conteudo;

	// Exibe a tela de edi��o de texto.
	tela(ADICIONAR_LINHA, MSG_LINHA_VAZIA);

	do { // Exibe o n�mero da linha a ser editada.
		cout << setw(3) << texto.getNumeroLinhas() + 1 << PONTO_E_ESPACO;

		// L� o conte�do da linha de texto.  
		ler(conteudo);

		// Verifica se o usu�rio deseja finalizar a entrada de dados.
		if (!conteudo.compare(CERQUILHA)) return;

		// Define o conte�do da linha de texto.
		linha.setLinha(conteudo);

		// Armazena o objeto linha no texto.
		texto.adicionarLinha(linha);

	} while (conteudo.compare(CERQUILHA));
} 

// Exibe o texto, o n�mero de linhas do texto e a quantidade de palavras do texto.
void EditorLinha::relatorio() {
	// Exibe a tela de relat�rio.
	tela(RELATORIO, STRING_NULA);

	// Exibe o n�mero de linhas e a quantidade de palavras do texto.
	cout << endl << MSG_DADOS_DO_TEXTO << endl << endl << MSG_NUMERO_LINHAS << texto.getNumeroLinhas()
		 << endl << MSG_QUANTIDADE_DE_PALAVRAS_DO_TEXTO << texto.quantidadePalavras();
	
	cout << endl;
	promptUniversal();
} 

/*
	Altera uma linha de texto segundo o n�mero da linha fornecido pelo usu�rio.
	L� o n�mero da linha e verifica se ela existe, se sim, exibe o conte�do da linha para que o usu�rio
	possa digitar o conte�do da nova linha de texto. Se a linha n�o existe exibe a mensagem Linha inv�lida.
*/
void EditorLinha::alterarLinha() {
	string conteudo;
	
	// Exibe a tela de altera��o de texto.
	tela(ALTERAR_LINHA, MSG_RETORNO_AO_MENU);

	// L� e valida o n�mero da linha de texto. 
	int numeroLinha = lerNumeroLinha();

	// Verifica se o usu�rio deseja finalizar a entrada de dados.
	if (numeroLinha == INT_MENOS_UM) return;

	// L� o novo conte�do da linha de texto.  
	cout << endl << MSG_NOVO_CONTEUDO_DA_LINHA << numeroLinha << endl << endl;
	ler(conteudo);

	// Verifica se o usu�rio deseja finalizar a entrada de dados.
	if (!conteudo.compare(STRING_MENOS_UM)) return;

	// Obt�m um objeto optional com o objeto Linha.
	optional<Linha> linhaOptional = texto.obterLinha(numeroLinha);

	// Recupera o objeto Linha do objeto optional para alterar o seu conte�do.
	Linha linha = linhaOptional.value();

	// Altera o conte�do da linha de texto.
	linha.setLinha(conteudo);

	// Altera a linha no texto.
	texto.alterarLinha(numeroLinha, linha);

	promptUniversal();
} // alterarLinha()

/*
	L� uma palavra, pesquisa no texto e exibe todas as ocorr�ncias desta palavra no texto, incluindo o n�mero das linhas e a
	quantidade que a palavra aparece em cada linha. Se a palavra n�o for encontrada no texto, exibe a mensagem
	A palavra xxxxx n�o foi encontrada no texto.; onde xxxxx deve ser substitu�do pela palavra pesquisada.
*/
void EditorLinha::pesquisarPalavra() {
	string palavra;
	int linhas[NUMERO_MAXIMO_LINHAS][2];

	// Exibe a tela de consulta.
	tela(PESQUISAR_PALAVRA, MSG_RETORNO_AO_MENU);

	// L� a palavra a ser pesquisada.
	cout << endl << PALAVRA << DOIS_PONTO_ESPACO;
	ler(palavra);

	// Verifica se o usu�rio deseja finalizar a consulta.
	if (!palavra.compare(STRING_MENOS_UM)) return;

	// Pesquisa pela palavra e verifica se a palavra foi encontrada.
	int numeroPalavras = texto.pesquisarPalavra(palavra, linhas);
	if (numeroPalavras != -1) {
		// Exibe todas as ocorr�ncias da palavra no texto, o n�mero da linha l e a quantidade que a palavra aparece em cada linha l.
		cout << endl << MSG_DADOS_DO_TEXTO << endl << endl << MSG_NUMERO_DE_OCORRENCIAS_DA_PALAVRA << numeroPalavras << endl << endl << MSG_LINHA_E_QUANTIDADE << endl;

		for (int l = 0; l < texto.getNumeroLinhas(); l++)
			if (linhas[l][1] != 0)
				cout << setw(4) << linhas[l][0] << setw(10) << linhas[l][1] << endl;
	}
	else
		cout << endl << MSG_PALAVRA_NAO_ENCONTRADA << endl << endl;

	promptUniversal();
} 

/*
	L� o n�mero da linha e verifica se ela existe, se sim, exibe no console o conte�do da linha de texto para que o usu�rio possa confirmar se ela deve ser exclu�da.
	Se a linha n�o existe, exibe a mensagem Linha inv�lida.
*/
void EditorLinha::excluirLinha() {
	const char SIM = 'S', NAO = 'N';
	char resposta;

    // Exibe a tela de exclus�o.
	tela(EXCLUIR_LINHA, MSG_RETORNO_AO_MENU);

	// L� e valida o n�mero da linha de texto. 
	int numeroLinha = lerNumeroLinha();

	// Verifica se o usu�rio deseja finalizar a entrada de dados.
	if (numeroLinha == INT_MENOS_UM) return;

	// Solicita ao usu�rio a confirma��o de exclus�o e valida sua resposta.
	cout << endl << MSG_CONFIRMACAO_EXCLUSAO; 

	do { resposta = toupper(_getche());
	} while (resposta != SIM && resposta != NAO); 

	// Exclui a linha de texto se o usu�rio confirmar. 
	if (resposta == SIM)
		if (texto.excluirLinha(numeroLinha))
			cout << endl << endl << MSG_LINHA_EXCLUIDA << endl;
		else
			cout << endl << endl << MSG_LINHA_NAO_EXCLUIDA << numeroLinha << endl;
	else
		cout << endl;
	promptUniversal();
} 

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
void EditorLinha::menu() {
	const string TABULACAO_HORIZONTAL_DUPLA = "\t\t";
	string menu[] = {ADICIONAR_LINHA, RELATORIO, ALTERAR_LINHA, PESQUISAR_PALAVRA, EXCLUIR_LINHA, SAIR };

	limpaTela();
	cout << TABULACAO_HORIZONTAL << HIFEN_ESPACO << EDITOR_DE_LINHA << endl << endl;

	for (int opcao = 1; opcao <= 6; opcao++)
		cout << TABULACAO_HORIZONTAL_DUPLA << opcao << PONTO_E_ESPACO << menu[opcao - 1] << endl;

	cout << endl << TABULACAO_HORIZONTAL << ESCOLHA << DOIS_PONTO_ESPACO;
}

// L�, valida e obt�m a op��o do menu escolhida pelo usu�rio.
Menu EditorLinha::lerOpcaoMenu() {
	Menu opcoes[] = {Menu::EL_ADICIONAR_LINHA, Menu::EL_RELATORIO, Menu::EL_ALTERAR_LINHA, Menu::EL_PESQUISAR_PALAVRA, Menu::EL_EXCLUIR_LINHA, Menu::EL_SAIR};
	int opcao;

	do { opcao = _getch();
	} while (opcao < static_cast<int>(Menu::EL_ADICIONAR_LINHA) || opcao > static_cast<int>(Menu::EL_SAIR));

	return opcoes[opcao - ASCII_CARACTERE_UM];
}

// Constr�i a tela com o nome do programa e da fun��o escolhida pelo usu�rio no menu. Exibe o texto na tela.
void EditorLinha::tela(string titulo, string mensagem) {
	limpaTela();

	cout << TABULACAO_HORIZONTAL << EDITOR_DE_LINHA << ESPACO_HIFEN_ESPACO << titulo << endl << endl;
	if (mensagem != STRING_NULA) cout << mensagem << endl << endl;

	exibirTexto();
}

// L� e valida o n�mero da linha de texto. Retorna o n�mero lido. Se a opera��o for cancelada retorna INT_MENOS_UM.
int EditorLinha::lerNumeroLinha() {
	const string FECHA_PARENTESES_DOIS_PONTOS_ESPACO = "): ";
	int numeroLinha;

	// L� o n�mero da linha de texto. Exibe o dom�nio do n�mero de linhas entre par�nteses. 
	do {  cout << endl << MSG_NUMERO_DA_LINHA << texto.getNumeroLinhas() << FECHA_PARENTESES_DOIS_PONTOS_ESPACO;
		  numeroLinha = ler(numeroLinha);

		  // Verifica se o usu�rio deseja sair.
		  if (numeroLinha == INT_MENOS_UM) return INT_MENOS_UM;

		  // Verifica se o n�mero da linha � v�lido.
		  if (numeroLinha < 1 || numeroLinha > texto.getNumeroLinhas())
			  cout << endl << MSG_NUMERO_DE_LINHA_INVALIDO << endl;

	} while (numeroLinha < 1 || numeroLinha > texto.getNumeroLinhas());

	return numeroLinha;
} 

// Exibe as linhas de texto.
void EditorLinha::exibirTexto() 
{
	cout << MSG_TEXTO << endl << endl;

	for (int linha = 1; linha <= texto.getNumeroLinhas(); linha++)
		cout << setw(3) << linha << PONTO_E_ESPACO << texto.obterLinha(linha).value().getLinha() << endl;
}

// L� e valida um n�mero inteiro. O n�mero lido � retornado pela fun��o e usado para modificar o argumento real usado na chamada da fun��o.
int EditorLinha::ler(int& numeroInteiro) 
{
	do {
		cin >> numeroInteiro;
	} while (numeroInteiro < INT_MENOS_UM);

	return numeroInteiro;
}

// L� e valida uma string. A string lida � retornada pela fun��o e usada para modificar o argumento real usado na chamada da fun��o. N�o aceita uma string vazia.
string EditorLinha::ler(string& dado)  
{
	do { getline(cin, dado);
	} while (dado.length() == 0);

	return dado;
}