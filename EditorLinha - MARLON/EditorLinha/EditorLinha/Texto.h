#pragma once 

#include <vector>
#include <optional>
#include "Linha.h"

/* Esta classe define uma organiza��o paras as linhas de um texto. Ela permite o armazenamento de v�rias linhas de texto. 
    O n�mero m�ximo de linhas n�o deve ser definido na implementa��o da classe, mas pelos programas que utilizar�o a classe Texto.
*/
class Texto {
public:
	Texto() = default;

	constexpr int getNumeroLinhas();

	// Adiciona uma linha no fim do texto. 
	void adicionarLinha(Linha linha);

	// Obt�m um objeto Linha na posi��o indicada pelo par�metro formal numeroLinha. A primeira linha � a de n�mero um (1).
	optional<Linha> obterLinha(int numeroLinha);

	/* Altera a linha no texto na posi��o indicada pelo par�metro formal numeroLinha. 
	   A primeira linha � a de n�mero um (1).
	   Retorna true se a altera��o for bem sucedida, caso contr�rio, false.
	*/ 
	bool alterarLinha(int numeroLinha, Linha linha);

	// Calcula a quantidade de palavras de todo o texto.
	int quantidadePalavras();

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
	int pesquisarPalavra(string palavra, int linhas[][2]);

	/* 
		Exclui uma linha de texto segundo o n�mero da linha fornecido como par�metro. A primeira linha � a de n�mero um (1). 
		Retorna true se a exclus�o for bem sucedida, caso contr�rio, false.
	*/
	bool excluirLinha(int numeroLinha);

private:
	// Representa as linhas do texto.
	vector<Linha> texto;

	// N�mero de linhas do texto.
	int numeroLinhas = 0;
};