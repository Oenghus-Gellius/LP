#pragma once

#include "Command.h"

class Shell {
public:

	// Inicia o shell definindo o prompt com o diretório atual.
	Shell();

	/* Este método é responsável por iniciar o shell e realizar as seguintes funções:
	1. Mostra o prompt para o usuário digitar os comandos.
	2. Lê, analisa e executa o comando ou o programa fornecido pelo usuário.
	3. Finaliza o shell quando o usuário digitar o comando exit no prompt.
	Retorna sempre EXIT_SUCCESS.	*/
	int shell();

	/* Executa o comando armazenado na string.
	 Retorna true quando o comando é executado, senão retorna false.	*/
	bool executeCommand(string command);

	/* Executa o comando armazenado no objeto Command.
	 Retorna true quando o comando é executado, senão retorna false.	*/
	bool executeCommand(Command command);

	/* Extrai da string command as substrings com o comando a ser executado e o(s) 
	seu(s) argumento(s) para obter um objeto Command com esses atributos.
Retorna o objeto Command com os atributos obtidos da string command se o comando é válido,
caso contrário retorna um objeto Command com valores default.*/
	Command toCommand(string command);

private:

	// Comando a ser executado pelo shell.
	Command command;

	// Linha de comando a ser executada pelo shell.
	string prompt;

	/* Verifica se o nome do comando digitado no prompt é válido, ou seja, 
	se é um comando da Tabela 1.
	Analisa apenas o nome do comando sem os seus parâmetros.
	 Retorna true se o comando é válido, caso contrário retorna false.	*/
	bool analyzeCommand(string command);

	/* Executa o comando armazenado no objeto Comando.
	 Retorna true quando o comando é executado, senão retorna false.	*/
	bool execute(Command command);

	/* Modifica o diretório atual para o diretório especificado e atualiza o prompt do shell para indicar a
	nova localização.
	 Retorna true quando o diretório é alterado, senão retorna false.	*/
	bool changeDirectory(string directory);

	/* Obtém o diretório atual.
	 Retorna o caminho absoluto do diretório, em caso de erro retorna uma string vazia.	*/
	string currentDirectory();

	/* Modifica o prompt do shell incluindo o diretório atual.
	 Retorna o prompt atualizado.	*/
	string changePrompt();
};

