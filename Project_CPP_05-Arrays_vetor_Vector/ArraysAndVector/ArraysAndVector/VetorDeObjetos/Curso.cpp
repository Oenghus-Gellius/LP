#include "Curso.h"

Curso::Curso(string nome, unsigned int cargaHoraria) {
    setNome(nome);
    setCargaHoraria(cargaHoraria);
}

void Curso::setNome(string nome) {
    this->nome = nome;
}

string Curso::getNome() {
    return nome;
}

void Curso::setCargaHoraria(unsigned int cargaHoraria) {
    this->cargaHoraria = cargaHoraria;
}

unsigned int Curso::getCargaHoraria() {
    return cargaHoraria;
}

string Curso::toString() {
    return "Curso: " + nome + " (" + to_string(cargaHoraria) + " h)";
}