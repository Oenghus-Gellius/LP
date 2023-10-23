#include <vector>
#include <sstream> // Requerido pelo template de classe stringstream.
#include "Linha.h"

// Define um novo conteúdo para a linha de texto.
void Linha::setLinha(string linhaTexto) {
	numeroCaracteres = linhaTexto.size();
	linha = linhaTexto;
}

// Obtém a linha de texto.
string Linha::getLinha() {
	return linha;
}

// Obtém a quantidade de caracteres da linha de texto.
int Linha::getNumeroCaracteres() {
	return numeroCaracteres;
}

// Calcula a quantidade de palavras da linha de texto.
int Linha::quantidadePalavras() {
	const char ESPACO = ' ';
	vector<string> palavras;
	string tokens;

	// Cria o objeto stringstream para obter o conteúdo da linha de texto.
	stringstream linha(this->linha);

	// Extrai todas as palavras (tokens) da linha com getline usando o objeto stringstream e insere no vector palavras.
	while (getline(linha, tokens, ESPACO))
		palavras.push_back(tokens);

	// Retorna a quantidade de palavras da linha.
	return palavras.size();
}  

// Calcula a quantidade de palavras da linha de texto iguais ao parâmetro palavra.
int Linha::quantidadePalavras(string palavra) {
	int indice = 0, numeroPalavras = 0;

	do { // Pesquisa pela palavra na linha de texto.
		indice = linha.find(palavra, indice);

		// Se encontrar a palavra contabiliza a ocorrência e ajusta a posição da string para a próxima pesquisa.
		if (indice != string::npos) {
			indice += palavra.length();
			numeroPalavras++;
		}
	} while (indice != string::npos);
	return numeroPalavras;
}