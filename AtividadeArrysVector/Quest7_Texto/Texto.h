#pragma once

/*
7. Desenvolva a implementação da classe Texto separando-a de sua interface que está listada abaixo.
*/

#include <vector>
#include <optional>
#include "Linha.h"

/* Esta classe define uma organização paras as linhas de um texto. Ela permite o armazenamento de várias
linhas de texto. O número máximo de linhas não deve ser definido na implementação da classe, mas pelos
programas que utilizarão a classe Texto.
*/
class Texto {
public:
	Texto() = default;
	int getNumeroLinhas();
	// Adiciona uma linha no fim do texto.
	void adicionarLinha(Linha linha);
	/* Obtém um objeto Linha na posição indicada pelo parâmetro formal numeroLinha. A primeira linha é
	a de número um (1).
	*/
	optional<Linha&> obterLinha(int numeroLinha);
	// Fornece a quantidade de palavras de todo o texto.
	int quantidadePalavras();
	/* Pesquisa por todas as ocorrências da palavra no texto. Se não encontrar retorna -1, em caso de
	sucesso retorna a quantidade de palavra no texto. Cada ocorrência da palavra deve ser registrada
	no parâmetro formal linhas do seguinte modo:
	Coluna 0: armazena o número da linha X onde há ocorrência da palavra;
	Coluna 1: armazena o número de ocorrências Y da palavra na linha X.
	Exemplo: Considere que foi pesquisado a palavra água e o resultado é:
	Col. 0 Col. 1
	3 2 -> água ocorre 2 vezes na linha 3
	10 5 -> água aparece 5 vezes na linha 10
	Assim o código usuário da classe saberá em quais linhas do texto é usada a palavra, a quantidade
total em cada linha e no texto. Para o exemplo acima o método deve retornar 7. A primeira linha
do texto é a de número um (1).
*/
	int pesquisarPalavra(string palavra, int linhas[][2]);
	/* Exclui uma linha de texto segundo o número da linha fornecido como parâmetro. A primeira linha é
	a de número um (1). Retorna true se a operação de exclusão for bem sucedida, caso contrário
	retorna false.
	*/
	bool excluirLinha(int numeroLinha);
private:
	vector<Linha> linhas; // Representa as linhas do texto.
	int numeroLinhas = 0; // Número de linhas do texto.
}; // class Texto
