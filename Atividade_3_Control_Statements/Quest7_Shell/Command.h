#pragma once

/*
7. O Windows possui um prompt de comandos que pode ser usado para a execução de comandos
desse sistema operacional. 
O shell5 de comandos do Windows utiliza o interpretador de comandos
cmd.exe. Um subconjunto desses comandos possui a sintaxe listada na primeira coluna da 
Tabela 1.

Sintaxe				Descrição									Exemplos

cls					Limpa a tela.								c:\> cls
date[/t]			Exibe a data do sistema.					c:\> date /t
time[/t]			Exibe a hora do sistema.					c:\> time /t
dir [<diretório>]	Lista o conteúdo do diretório.				c:\> dir c:\> dir windows
type <arquivo>		Exibe o conteúdo de um arquivo.				c:\> type windows\win.ini
cd [<diretório>]	Muda de diretório.							c:\> cd windows
md <diretório>		Cria um diretório.							c:\> md user\c++
copy <arquivo> <diretorio> Copia um arquivo de um diretório para outro. c:\> copy aula.java f:\fontes
rd <diretório>		Apaga um diretório vazio.					c:\> rd user\c++
del <arquivo>		Apaga um arquivo.							c:\> del user\carta.txt
vol					Exibe o nome e o número de série do disco.	c:\> vol
ver					Exibe a versão do Windows.					c:\> ver
path				Exibe o caminho de pesquisa atual.			c:\> path
set					Exibe as variáveis de ambiente do sistema.	c:\> set

Os colchetes na Tabela 1 indicam usam opcional. Para obter informações sobre esses comandos
do Windows use a sintaxe <comando> /?, por exemplo, o texto de ajuda do dir será exibido quando o
comando abaixo for executado.
c:\> dir /?

Desenvolva um programa chamado Shell que:

1. Mostra um prompt ao usuário para que ele possa digitar os comandos da Tabela 1. Use o
prompt abaixo.

shell:\>

2. Lê, analisa e executa o comando ou o programa fornecido pelo usuário.

3. Finaliza o programa shell quando o usuário digitar a palavra exit no prompt.

Atenção: 1. Para executar os comandos da Tabela 1 use a função system.

2. O prompt deve sempre mostrar o nome do diretório atual do disco. Considere
somente um disco no sistema. Os comandos devem ser executados considerando
o diretório corrente. Observe os exemplos abaixo:

shell:\> cd windows

shell:\windows> dir

Como o diretório corrente foi alterado do raiz (\) para windows, esse deve ser
exibido no prompt (shell\windows>), e é o conteúdo do diretório windows que
deve ser listado quando o comando dir for executado.

shell:\programas> md java

Como o diretório atual agora é programas, o diretório java deve ser criado como
subdiretório de programas quando o comando md for executado.

Use as interfaces das classes Command e Shell abaixo para implementá-lo.

Atenção: Observe que a interface da classe Shell possui 5 métodos privados, chamados de
funções utilitárias, porque elas não podem ser usadas fora da classe, apenas
pelas outras funções-membro (métodos) da própria classe.
*/

#include <string>

using namespace std;

class Command {
private:
	string commandName, // Nome do comando a ser executado.

		argument; // Argumento do comando a ser executado.
public:
	Command() = default;

	// Inicia o nome do comando.
	Command(string commandName);

	// Inicia o nome do comando e o seu argumento.
	Command(string commandName, string argument);

	void setCommandName(string commandName);

	string getCommandName();

	void setArgument(string argument);

	string getArgument();

	// Fornece a linha de comando composta por nome e argumentos do comando.
	string commandLine();
};


