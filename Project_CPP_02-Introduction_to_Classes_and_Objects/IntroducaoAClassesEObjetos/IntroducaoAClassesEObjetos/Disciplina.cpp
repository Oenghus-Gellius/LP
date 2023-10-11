// Define a implementa��o dos m�todos (fun��es-membro) da classe Disciplina. 
#include <iostream>
#include "Disciplina.h"

// Construtor default ou padr�o.
Disciplina::Disciplina() {
	cout << "Construtor padr�o.\n";
}

// Construtor sobrecarregado.
Disciplina::Disciplina(string nome, float nota) {
	// O this � ponteiro C++ que aponta para o objeto atual.
	this->nome = nome;
	this->nota = nota;
}

/* Define o nome da disciplina com no m�ximo N caracteres, onde N � definido por
*   TAMANHO_NOME.
*/ 
void Disciplina::setNome(string nome) {
	/* Solu��o 1: usa o comando if.
	 
		if (nome.length() <= TAMANHO_NOME)
			this->nome = nome;
		else	
			this->nome = nome.substr(0, TAMANHO_NOME);
    
		Solu��o 2: usa o Operador Condicional Tern�rio (? :)
	*/
	this->nome = (nome.length() <= TAMANHO_NOME) ? nome : 
		                                                                                         nome.substr(0, TAMANHO_NOME);
}

// Define a nota da disciplina se o valor for positivo ou zero. Se for negativo n�o muda.
void Disciplina::setNota(float nota) {
	if (nota >= 0)
		this->nota = nota;
}

string Disciplina::getNome() {
	return nome;
}

float Disciplina::getNota() {
	return nota;
}

// Retorna uma representa��o string do objeto.
string Disciplina::toString() {
	/* Faz a concatena��o (uni�o) do objeto string nome com a string literal da Linguagem C 
	     e com a nota convertida de float para string.

		 Exemplo de  concatena��o (uni�o): "A" + "B" -> "AB" // Isso n�o funciona em C e C++.
	*/ 
	return nome + ", Nota: " +  to_string(nota);
}
