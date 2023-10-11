#include <iostream>
#include <clocale>
#include <string> // Requerido pela classe string do C++
#include <limits> // Requerido pela classe numeric_limits.

using namespace std;

// Protótipo de função
int introducao();
string lerString(string& str);

/*  Diretrizes para criação de identificadores

		valorMedio        -> variável
		valorMedio()     -> função ou método
		ValorMedio       -> classe 
		VALOR_MEDIO -> constante
*/
int main() {
	return introducao();
}

int introducao() {
	const char 
		ENTER = 13, // Código ASCII 13 da tecla Enter
		ARROBA = '\u0040'; // Código Unicode do caractere arroba (@)

	bool verdadeiro = true;
	double nota = 8.59;

	// Define um objeto da classe string.
	string frase = "Hoje o dia está nublado.";

	setlocale(LC_ALL, "pt-BR");

	cout << "\tverdadeiro = " << verdadeiro
		<< "\n\tEnter = " << ENTER
		<< "\n\tArroba = " << ARROBA
		<< "\n\tnota = " << nota
		<< "\n\tfrase = " << frase <<  "\tTamanho da frase = " << frase.length() 
		<< " caracteres\n\n\t5 && 2 = " << (5 && 2)
		<< "\n\t5 | 2 = " << (5 | 2) 
		<< "\n\t5 & 2 = " << (5 & 2) << endl;

	// Lê uma nota.
	cout << "\n\tNota: ";
	cin >> nota;

	// Lê uma string usando o objeto padrão de entrada de dados do C++ (cin).
	cout << "\n\tFrase: ";
	cin >> frase;
	cout << "\tA frase fornecida é: " << frase;

	// Lê uma string usando a função getline dentro da função lerString.
	cout << "\n\tFrase: ";
	lerString(frase);
	cout << "\tA frase fornecida é: " << frase << endl;

	return EXIT_SUCCESS;
} // introducao()

/* Lê uma string e armazena no parâmetro formal str. Aceita uma string vazia.
*  Retorna a string lida.
*/ 
string lerString(string& str) {
	/* Limpa o buffer usado pelo objeto cin.
	   Isso é feito extraindo todos os caracteres do buffer até encontrar o caractere de nova linha ('\n').
	*/ 
	cin.ignore(numeric_limits<int>::max(), '\n');

	// Lê a string e armazena em str quando o usuário teclar Enter.
	getline(cin, str);

	return str;
}