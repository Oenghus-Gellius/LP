#include "Texto.h"

constexpr int Texto::getNumeroLinhas() {
	return numeroLinhas;
}

// Adiciona uma linha de texto ap�s a �ltima linha do editor. 
void Texto::adicionarLinha(Linha linhaTexto) {
		texto.push_back(linhaTexto);
		numeroLinhas++;
} 

// Obt�m um objeto Linha na posi��o indicada pelo par�metro formal numeroLinha. A primeira linha � a de n�mero um (1).
optional<Linha> Texto::obterLinha(int numeroLinha) {
	// Verifica se o n�mero da linha � v�lido.
	if (numeroLinha >= 1 && numeroLinha <= getNumeroLinhas())
		return optional<Linha>(texto.at(numeroLinha - 1));

	// O uso do nullopt equivale a criar um objeto optional que n�o tem um valor, assim: optional<Linha>();
	return nullopt; 
}

/* Altera o linha no texto na posi��o indicada pelo par�metro formal numeroLinha. A primeira linha � a de n�mero um (1).
   Retorna true se a altera��o for bem sucedida, caso contr�rio, false.
*/
bool Texto::alterarLinha(int numeroLinha, Linha linha) {
	// Verifica se o n�mero da linha � v�lido.
	if (numeroLinha >= 1 && numeroLinha <= getNumeroLinhas()) {
		texto.at(numeroLinha - 1) = linha;
		return true;
	}
	return false;
}

// Calcula a quantidade de palavras de todo o texto.
int Texto::quantidadePalavras() {
	int quantidadePalavras = 0;

	for (Linha& linha : texto)
		quantidadePalavras += linha.quantidadePalavras();

	return quantidadePalavras;
}

/* Pesquisa por todas as ocorr�ncias da palavra no texto. Retorna a quantidade de palavra no texto, se n�o encontrar, -1.
   Cada ocorr�ncia da palavra deve ser registrada no par�metro formal linhas do seguinte modo:

	Coluna 0: armazena o n�mero da linha X onde h� ocorr�ncia da palavra;
	Coluna 1: armazena o n�mero de ocorr�ncias Y da palavra na linha X.

	Exemplo: Considere que foi pesquisado a palavra �gua e o resultado �:

		Col. 0		Col. 1
			3			2		-> �gua ocorre 2 vezes na linha 3
			10			5		-> �gua aparece 5 vezes na linha 10

	Assim o usu�rio da classe saber� em quais linhas do texto � usada a palavra, a quantidade total em cada linha e no texto. 
	Para o exemplo acima o m�todo deve retornar 7. A primeira linha do texto � a de n�mero um (1).
*/ 
int Texto::pesquisarPalavra(string palavra, int linhas[][2]) {
	int quantidadePalavras = 0, lin = 0, numeroPalavras = 0;
	Linha linha;

	// Procura no vector pela palavra fornecida pelo usu�rio.
	for (int l = 1; l <= numeroLinhas; l++) {
		linha = this->texto.at(l - 1); 

		// Calcula a quantidade de palavras da linha l que s�o iguais ao par�metro palavra.
		numeroPalavras = linha.quantidadePalavras(palavra);

		// Verifica se encontrou alguma ocorr�ncia da palavra na linha l.
		if (numeroPalavras > 0) {
			// Calcula o n�mero de ocorr�ncias (quantidade) da palavra no texto.
			quantidadePalavras += numeroPalavras;

			// Armazena o n�mero da linha l e o n�mero de ocorr�ncias da palavra na linha l.
			linhas[lin][0] = l;
			linhas[lin++][1] = numeroPalavras;
		}
		else { linhas[lin][0] = linhas[lin++][1] = 0; }
	}
	return (quantidadePalavras > 0) ? quantidadePalavras : -1;
} // pesquisarPalavra()

/*
	Exclui uma linha de texto segundo o n�mero da linha fornecido como par�metro. A primeira linha � a de n�mero um (1).
	Retorna true se a exclus�o for bem sucedida, caso contr�rio, false.
*/
bool Texto::excluirLinha(int numeroLinha) {
	// Verifica se o n�mero da linha � v�lido.
	if (numeroLinha >= 1 && numeroLinha <= numeroLinhas) {
		// Apaga a linha solicitada sem alterar a ordem das linhas de texto. 
		texto.erase(texto.begin() + numeroLinha - 1); 

		// Contabiliza que uma linha foi removida do texto.
		numeroLinhas--; 

		return true;
	}
	return false;
} 