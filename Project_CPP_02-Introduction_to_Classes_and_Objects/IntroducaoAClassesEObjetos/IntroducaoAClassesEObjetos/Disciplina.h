// Define a interface (conjunto de fun��es p�blicas) da classe Disciplina. 
#pragma once  // Evitar que arquivos de cabe�alho sejam inclu�dos mais de uma vez.

#include <string>

using namespace std;

class Disciplina {
private: // Define as vari�veis de inst�ncia (atributos) dos objetos da classe Disciplina.
	const unsigned TAMANHO_NOME = 50;
	string nome;
	float nota = 0;  // As vari�veis de inst�ncia de tipo primitivo tem que ser iniciadas.

public: // A interface � o conjunto de m�todos (fun��es-membro) p�blicos da classe.
	// Construtor default ou padr�o.
	Disciplina();

	// Construtor sobrecarregado.
	Disciplina(string nome, float nota);

	// M�todos modificadores permite alterar os atributos dos objetos.
	void setNome(string nome);

	// Define a nota da disciplina se o valor for positivo ou zero. Se for negativo n�o muda.
	void setNota(float nota);

	// M�todos de consulta para obter os atributos dos objetos.
	string getNome();
	float getNota();

	// Retorna uma representa��o string do objeto.
	string toString();
}; // class Disciplina

/* Exemplo v�lido de sobrecarga de fun��es.
 
		int maximo(int x, int y, int z);
		int maximo(int x, int y);
		char maximo(char x, char y, char z);
		float maximo(float x, float y, float z);

		int pesquisarNome(string nome, string nomes[]);
		int pesquisarNome(string nomes[], string nome);
 
	Exemplo inv�lido de sobrecarga de fun��es.

		int maximo(int x, int y, int z);
		char maximo(int x, int y, int z);
*/