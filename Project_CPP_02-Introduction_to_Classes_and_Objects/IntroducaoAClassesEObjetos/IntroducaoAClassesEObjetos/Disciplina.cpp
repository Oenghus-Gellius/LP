// Define a implementação dos métodos (funções-membro) da classe Disciplina. 
#include <iostream>
#include "Disciplina.h"

// Construtor default ou padrão.
Disciplina::Disciplina() {
	cout << "Construtor padrão.\n";
}

// Construtor sobrecarregado.
Disciplina::Disciplina(string nome, float nota) {
	// O this é ponteiro C++ que aponta para o objeto atual.
	this->nome = nome;
	this->nota = nota;
}

/* Define o nome da disciplina com no máximo N caracteres, onde N é definido por
*   TAMANHO_NOME.
*/ 
void Disciplina::setNome(string nome) {
	/* Solução 1: usa o comando if.
	 
		if (nome.length() <= TAMANHO_NOME)
			this->nome = nome;
		else	
			this->nome = nome.substr(0, TAMANHO_NOME);
    
		Solução 2: usa o Operador Condicional Ternário (? :)
	*/
	this->nome = (nome.length() <= TAMANHO_NOME) ? nome : 
		                                                                                         nome.substr(0, TAMANHO_NOME);
}

// Define a nota da disciplina se o valor for positivo ou zero. Se for negativo não muda.
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

// Retorna uma representação string do objeto.
string Disciplina::toString() {
	/* Faz a concatenação (união) do objeto string nome com a string literal da Linguagem C 
	     e com a nota convertida de float para string.

		 Exemplo de  concatenação (união): "A" + "B" -> "AB" // Isso não funciona em C e C++.
	*/ 
	return nome + ", Nota: " +  to_string(nota);
}
