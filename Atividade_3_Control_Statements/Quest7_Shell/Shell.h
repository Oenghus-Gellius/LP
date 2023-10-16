#pragma once

#include "Command.h"

class Shell {
public:

	// Inicia o shell definindo o prompt com o diret�rio atual.
	Shell();

	/* Este m�todo � respons�vel por iniciar o shell e realizar as seguintes fun��es:
	1. Mostra o prompt para o usu�rio digitar os comandos.
	2. L�, analisa e executa o comando ou o programa fornecido pelo usu�rio.
	3. Finaliza o shell quando o usu�rio digitar o comando exit no prompt.
	Retorna sempre EXIT_SUCCESS.	*/
	int shell();

	/* Executa o comando armazenado na string.
	 Retorna true quando o comando � executado, sen�o retorna false.	*/
	bool executeCommand(string command);

	/* Executa o comando armazenado no objeto Command.
	 Retorna true quando o comando � executado, sen�o retorna false.	*/
	bool executeCommand(Command command);

	/* Extrai da string command as substrings com o comando a ser executado e o(s) 
	seu(s) argumento(s) para obter um objeto Command com esses atributos.
Retorna o objeto Command com os atributos obtidos da string command se o comando � v�lido,
caso contr�rio retorna um objeto Command com valores default.*/
	Command toCommand(string command);

private:

	// Comando a ser executado pelo shell.
	Command command;

	// Linha de comando a ser executada pelo shell.
	string prompt;

	/* Verifica se o nome do comando digitado no prompt � v�lido, ou seja, 
	se � um comando da Tabela 1.
	Analisa apenas o nome do comando sem os seus par�metros.
	 Retorna true se o comando � v�lido, caso contr�rio retorna false.	*/
	bool analyzeCommand(string command);

	/* Executa o comando armazenado no objeto Comando.
	 Retorna true quando o comando � executado, sen�o retorna false.	*/
	bool execute(Command command);

	/* Modifica o diret�rio atual para o diret�rio especificado e atualiza o prompt do shell para indicar a
	nova localiza��o.
	 Retorna true quando o diret�rio � alterado, sen�o retorna false.	*/
	bool changeDirectory(string directory);

	/* Obt�m o diret�rio atual.
	 Retorna o caminho absoluto do diret�rio, em caso de erro retorna uma string vazia.	*/
	string currentDirectory();

	/* Modifica o prompt do shell incluindo o diret�rio atual.
	 Retorna o prompt atualizado.	*/
	string changePrompt();
};

