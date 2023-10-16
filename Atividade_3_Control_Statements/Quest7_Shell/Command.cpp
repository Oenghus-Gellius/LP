#include "Command.h"

Command::Command(string commandName)
{
	setCommandName(commandName);
}

Command::Command(string commandName, string argument)
{
	setCommandName(commandName);
	setArgument(argument);
}

void Command::setCommandName(string commandName)
{
	this->commandName = commandName;
}

string Command::getCommandName()
{
	return commandName;
}

void Command::setArgument(string argument)
{
	this->argument = argument;
}

string Command::getArgument()
{
	return argument;
}

string Command::commandLine()
{
	if (argument.empty())
	{
		return commandName;
	}
	return commandName + " " + argument;
}
