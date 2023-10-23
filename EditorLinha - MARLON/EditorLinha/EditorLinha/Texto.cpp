#include "Texto.h"

constexpr int Texto::getNumeroLinhas() {
	return numeroLinhas;
}

// Adiciona uma linha de texto após a última linha do editor. 
void Texto::adicionarLinha(Linha linhaTexto) {
		texto.push_back(linhaTexto);
		numeroLinhas++;
} 

// Obtém um objeto Linha na posição indicada pelo parâmetro formal numeroLinha. A primeira linha é a de número um (1).
optional<Linha> Texto::obterLinha(int numeroLinha) {
	// Verifica se o número da linha é válido.
	if (numeroLinha >= 1 && numeroLinha <= getNumeroLinhas())
		return optional<Linha>(texto.at(numeroLinha - 1));

	// O uso do nullopt equivale a criar um objeto optional que não tem um valor, assim: optional<Linha>();
	return nullopt; 
}

/* Altera o linha no texto na posição indicada pelo parâmetro formal numeroLinha. A primeira linha é a de número um (1).
   Retorna true se a alteração for bem sucedida, caso contrário, false.
*/
bool Texto::alterarLinha(int numeroLinha, Linha linha) {
	// Verifica se o número da linha é válido.
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

/* Pesquisa por todas as ocorrências da palavra no texto. Retorna a quantidade de palavra no texto, se não encontrar, -1.
   Cada ocorrência da palavra deve ser registrada no parâmetro formal linhas do seguinte modo:

	Coluna 0: armazena o número da linha X onde há ocorrência da palavra;
	Coluna 1: armazena o número de ocorrências Y da palavra na linha X.

	Exemplo: Considere que foi pesquisado a palavra água e o resultado é:

		Col. 0		Col. 1
			3			2		-> água ocorre 2 vezes na linha 3
			10			5		-> água aparece 5 vezes na linha 10

	Assim o usuário da classe saberá em quais linhas do texto é usada a palavra, a quantidade total em cada linha e no texto. 
	Para o exemplo acima o método deve retornar 7. A primeira linha do texto é a de número um (1).
*/ 
int Texto::pesquisarPalavra(string palavra, int linhas[][2]) {
	int quantidadePalavras = 0, lin = 0, numeroPalavras = 0;
	Linha linha;

	// Procura no vector pela palavra fornecida pelo usuário.
	for (int l = 1; l <= numeroLinhas; l++) {
		linha = this->texto.at(l - 1); 

		// Calcula a quantidade de palavras da linha l que são iguais ao parâmetro palavra.
		numeroPalavras = linha.quantidadePalavras(palavra);

		// Verifica se encontrou alguma ocorrência da palavra na linha l.
		if (numeroPalavras > 0) {
			// Calcula o número de ocorrências (quantidade) da palavra no texto.
			quantidadePalavras += numeroPalavras;

			// Armazena o número da linha l e o número de ocorrências da palavra na linha l.
			linhas[lin][0] = l;
			linhas[lin++][1] = numeroPalavras;
		}
		else { linhas[lin][0] = linhas[lin++][1] = 0; }
	}
	return (quantidadePalavras > 0) ? quantidadePalavras : -1;
} // pesquisarPalavra()

/*
	Exclui uma linha de texto segundo o número da linha fornecido como parâmetro. A primeira linha é a de número um (1).
	Retorna true se a exclusão for bem sucedida, caso contrário, false.
*/
bool Texto::excluirLinha(int numeroLinha) {
	// Verifica se o número da linha é válido.
	if (numeroLinha >= 1 && numeroLinha <= numeroLinhas) {
		// Apaga a linha solicitada sem alterar a ordem das linhas de texto. 
		texto.erase(texto.begin() + numeroLinha - 1); 

		// Contabiliza que uma linha foi removida do texto.
		numeroLinhas--; 

		return true;
	}
	return false;
} 