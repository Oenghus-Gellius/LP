#include "Shell.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // Para system()
#include <functional> // Para std::function

#include <direct.h> // Para _chdir e _getcwd

Shell::Shell()
{
	prompt = "shell:\\";

}

//"Tela" n�o finalizado
int Shell::shell()
{
	string imput;
	while (true)
	{
		cout << prompt;
		getline(cin, imput);

        if (analyzeCommand(imput) == true)
        {
            Command cmd = toCommand(imput);

            executeCommand(cmd);

            if (cmd.getCommandName() == "exit")
            {
                break;
            }

            if (cmd.getCommandName() == "cd")
            {
                prompt = changePrompt();
            }
        }
        else
        {
            cout << "Comando n�o reconhecido." << endl;
        }
	}
	return EXIT_SUCCESS;
}

bool Shell::executeCommand(string command)
{
    Command cmd = toCommand(command);
	return executeCommand(cmd);
}

bool Shell::executeCommand(Command command)
{
	return execute(command);
}

//// Converte uma string de comando em um objeto Command
Command Shell::toCommand(string command)
{
    string cmdName;
    string arg;

    //separa comando de argumento
    size_t spacePos = command.find(" ");
    if (spacePos != string::npos) {
        cmdName = command.substr(0, spacePos);
        arg = command.substr(spacePos + 1);
    }
    else {
        cmdName = command;
    }

    return Command(cmdName, arg);
}

//---------------------------PRIVATE---------------------------

bool Shell::analyzeCommand(string command)
{
    // Separe o comando do argumento usando espa�o como delimitador
    size_t spacePos = command.find(" ");
    string cmdName = (spacePos != string::npos) ? command.substr(0, spacePos) : command;

    string validCommand[] = { "cls", "date", "time", "dir", "type", "cd", "md", "copy", "rd", "del", "vol", "ver", "path", "set", "exit" };

    for (int i = 0; i < sizeof(validCommand) / sizeof(validCommand[0]); i++)
    {

        if (cmdName == validCommand[i])
        {
            return true;
        }
    }
    return false;
}

bool Shell::execute(Command command)
{
    if (command.getCommandName() == "cls") {
        system("cls");
    }
    else if (command.getCommandName() == "date") {
        system("date");
    }
    else if (command.getCommandName() == "time") {
        system("time");
    }
    else if (command.getCommandName() == "dir") {
        string cmd = "dir";
        if (!command.getArgument().empty()) {
            cmd = cmd + " " + command.getArgument();
            cout << "TESTE" << endl;
        }
        system(cmd.c_str());
    }
    else if (command.getCommandName() == "type") {
        string cmd = "type " + command.getArgument();
        system(cmd.c_str());
    }
    else if (command.getCommandName() == "cd") {
        changeDirectory(command.getArgument());
    }
    else if (command.getCommandName() == "md") {
        string cmd = "mkdir " + command.getArgument();
        system(cmd.c_str());
    }
    else if (command.getCommandName() == "copy") {
        // Implemente a l�gica para o comando "copy" aqui.
    }
    else if (command.getCommandName() == "rd") {
        // Implemente a l�gica para o comando "rd" aqui.
    }
    else if (command.getCommandName() == "del") {
        // Implemente a l�gica para o comando "del" aqui.
    }
    else if (command.getCommandName() == "vol") {
        system("vol");
    }
    else if (command.getCommandName() == "ver") {
        system("ver");
    }
    else if (command.getCommandName() == "path") {
        system("path");
    }
    else if (command.getCommandName() == "set") {
        system("set");
    }
    else if (command.getCommandName() == "exit") {
        return false; // Encerre o loop do shell.
    }
    else {
        cout << "Comando n�o reconhecido." << endl;
    }

    return true;
}



bool Shell::changeDirectory(string directory)
{
    // Implemente a l�gica para alterar o diret�rio atual.
    // Use a fun��o chdir() ou equivalentes para alterar o diret�rio.
    int result = _chdir(directory.c_str());   //S� para windons
    if (result == 0) {
        return true;
    }
    else {
        cout << "Diret�rio n�o encontrado." << endl;
        return false;
    }
}

string Shell::currentDirectory() {
    char buffer[FILENAME_MAX];
    if (_getcwd(buffer, sizeof(buffer)) != NULL) { // Somente para Windows
        return buffer;
    }
    else {
        return "";
    }
}

string Shell::changePrompt() {
    string currentDir = currentDirectory();
    if (!currentDir.empty()) {
        size_t lastSlash = currentDir.find_last_of('\\');
        if (lastSlash != string::npos) {
            currentDir = currentDir.substr(lastSlash + 1);
        }
        return "shell:\\" + currentDir + ">";
    }
    else {
        return prompt;
    }
}


int main() {

    return Shell().shell();
}