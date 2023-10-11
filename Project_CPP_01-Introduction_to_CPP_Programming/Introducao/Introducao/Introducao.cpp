#include <iostream>
#include <clocale>
#include <string> // Requerido pela classe string do C++
#include <limits> // Requerido pela classe numeric_limits.

using namespace std;

// Prot�tipo de fun��o
int introducao();
string lerString(string& str);

/*  Diretrizes para cria��o de identificadores

		valorMedio        -> vari�vel
		valorMedio()     -> fun��o ou m�todo
		ValorMedio       -> classe 
		VALOR_MEDIO -> constante
*/
int main() {
	return introducao();
}

int introducao() {
	const char 
		ENTER = 13, // C�digo ASCII 13 da tecla Enter
		ARROBA = '\u0040'; // C�digo Unicode do caractere arroba (@)

	bool verdadeiro = true;
	double nota = 8.59;

	// Define um objeto da classe string.
	string frase = "Hoje o dia est� nublado.";

	setlocale(LC_ALL, "pt-BR");

	cout << "\tverdadeiro = " << verdadeiro
		<< "\n\tEnter = " << ENTER
		<< "\n\tArroba = " << ARROBA
		<< "\n\tnota = " << nota
		<< "\n\tfrase = " << frase <<  "\tTamanho da frase = " << frase.length() 
		<< " caracteres\n\n\t5 && 2 = " << (5 && 2)
		<< "\n\t5 | 2 = " << (5 | 2) 
		<< "\n\t5 & 2 = " << (5 & 2) << endl;

	// L� uma nota.
	cout << "\n\tNota: ";
	cin >> nota;

	// L� uma string usando o objeto padr�o de entrada de dados do C++ (cin).
	cout << "\n\tFrase: ";
	cin >> frase;
	cout << "\tA frase fornecida �: " << frase;

	// L� uma string usando a fun��o getline dentro da fun��o lerString.
	cout << "\n\tFrase: ";
	lerString(frase);
	cout << "\tA frase fornecida �: " << frase << endl;

	return EXIT_SUCCESS;
} // introducao()

/* L� uma string e armazena no par�metro formal str. Aceita uma string vazia.
*  Retorna a string lida.
*/ 
string lerString(string& str) {
	/* Limpa o buffer usado pelo objeto cin.
	   Isso � feito extraindo todos os caracteres do buffer at� encontrar o caractere de nova linha ('\n').
	*/ 
	cin.ignore(numeric_limits<int>::max(), '\n');

	// L� a string e armazena em str quando o usu�rio teclar Enter.
	getline(cin, str);

	return str;
}