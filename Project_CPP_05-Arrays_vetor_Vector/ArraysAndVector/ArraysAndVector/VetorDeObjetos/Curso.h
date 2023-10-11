#pragma once

#include <iostream>
#include <string>

using namespace std;

class Curso {
private:
	string nome;
	unsigned int  cargaHoraria = 0;

public:
	Curso() = default;
	Curso(string nome, unsigned int cargaHoraria);

	void setNome(string nome);
	string getNome();

	void setCargaHoraria(unsigned int cargaHoraria);
	unsigned int getCargaHoraria();

	string toString();
};