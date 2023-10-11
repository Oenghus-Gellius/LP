#include "Discente.h"

Discente::Discente(string nome) {
    setNome(nome);
}

void Discente::setNome(string nome) {
    this->nome = nome;
}

string Discente::getNome() {
    return nome;
}

// Obt�m o nome e a rela��o de cursos do discente.
string Discente::toString() {
    string relatorio = "Nome: " + nome + "\nCursos:";

    for (unsigned indice = 0; indice < numeroAtualCursos; indice++)
        relatorio += "\n\t" + to_string(indice + 1) + ". " + cursos[indice].toString();

    return relatorio;
}

// Cadastra o discente em um curso. Se o cadastro foi feito retorna true, caso contr�rio, false.
bool Discente::cadastrarCurso(Curso curso) {
    if (numeroAtualCursos < NUMERO_MAXIMO_DE_CURSOS) {
        cursos[numeroAtualCursos++] = curso;
        return true;
    }
    return false;
}

/* Pesquisa um curso pelo nome. Se o discente est� cadastrado no curso retorna o objeto
     Curso com os seus atributos. Se o curso n�o existe ou se o discente n�o est� cadastrado
     no curso pesquisado, retorna um objeto Curso com atributos nulos.
*/
Curso Discente::pesquisarCurso(string nome) {
    for (unsigned indice = 0; indice < numeroAtualCursos; indice++)
        if (nome == cursos[indice].getNome())
            return cursos[indice];
    return Curso();
}

/* Obt�m um curso pelo nome. Se o discente est� cadastrado no curso retorna o objeto
    Curso com os seus atributos. Se o curso n�o existe ou se o discente n�o est� cadastrado
    no curso pesquisado, retorna um objeto Curso com atributos nulos.
*/
Curso Discente::obterCurso(string nome) {
    return pesquisarCurso(nome);
}