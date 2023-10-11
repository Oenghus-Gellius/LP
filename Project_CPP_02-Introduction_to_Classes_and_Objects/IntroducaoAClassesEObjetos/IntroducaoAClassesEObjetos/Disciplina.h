// Define a interface (conjunto de funções públicas) da classe Disciplina. 
#pragma once  // Evitar que arquivos de cabeçalho sejam incluídos mais de uma vez.

#include <string>

using namespace std;

class Disciplina {
private: // Define as variáveis de instância (atributos) dos objetos da classe Disciplina.
	const unsigned TAMANHO_NOME = 50;
	string nome;
	float nota = 0;  // As variáveis de instância de tipo primitivo tem que ser iniciadas.

public: // A interface é o conjunto de métodos (funções-membro) públicos da classe.
	// Construtor default ou padrão.
	Disciplina();

	// Construtor sobrecarregado.
	Disciplina(string nome, float nota);

	// Métodos modificadores permite alterar os atributos dos objetos.
	void setNome(string nome);

	// Define a nota da disciplina se o valor for positivo ou zero. Se for negativo não muda.
	void setNota(float nota);

	// Métodos de consulta para obter os atributos dos objetos.
	string getNome();
	float getNota();

	// Retorna uma representação string do objeto.
	string toString();
}; // class Disciplina

/* Exemplo válido de sobrecarga de funções.
 
		int maximo(int x, int y, int z);
		int maximo(int x, int y);
		char maximo(char x, char y, char z);
		float maximo(float x, float y, float z);

		int pesquisarNome(string nome, string nomes[]);
		int pesquisarNome(string nomes[], string nome);
 
	Exemplo inválido de sobrecarga de funções.

		int maximo(int x, int y, int z);
		char maximo(int x, int y, int z);
*/