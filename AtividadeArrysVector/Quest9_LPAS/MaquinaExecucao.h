#pragma once

#include <optional>
#include "LPAS.h"
#include "ErroExecucao.h"

#include <optional>

// N�mero m�ximo de vari�veis do programa.
constexpr unsigned short NUMERO_MAXIMO_DE_VARIAVEIS = 25;

// N�mero m�ximo de programas da m�quina de execu��o.
constexpr unsigned short NUMERO_MAXIMO_DE_PROGRAMAS = 5;

// Indica endere�o inv�lido na mem�ria da m�quina de execu��o.
constexpr unsigned short ENDERECO_INVALIDO = 100;

// Esta classe representa a estrutura da m�quina de execu��o de um programa LPAS.
class MaquinaExecucao {
public:
	// Inicia as vari�veis da m�quina de execu��o.
	MaquinaExecucao();

	/* Carrega um programa LPAS para a mem�ria. Retorna true se o programa foi carregado, caso
	contr�rio retorna false. */
	bool carregar(Programa programa);

	// Obt�m o n�mero de programas LPAS carregados na mem�ria da m�quina de execu��o.
	int getNumeroDeProgramas();

	// Obt�m um programa LPAS armazenado na posi��o de mem�ria indicada por endereco.
	optional<Programa> obterPrograma(unsigned short endereco);

	/* Executa o programa armazenado na posi��o de mem�ria indicada por endereco. Esta fun��o deve
	usar a fun��o obterCodigoInstrucao() para obter o c�digo de m�quina da instru��o LPAS a ser
	executada. Retorna um objeto que permite identificar a instru��o, o n�mero da linha e o tipo de
	erro que pode ocorrer durante a execu��o do programa LPAS. */
	ErroExecucao executarPrograma(unsigned short endereco);

	/* Retorna um objeto que permite identificar a instru��o, o n�mero da linha e o tipo de erro que pode
	ocorrer durante a execu��o do programa LPAS. */
	ErroExecucao getErroExecucao();

private:
	// N�mero de programas LPAS carregados na mem�ria da m�quina de execu��o.
	unsigned short numeroDeProgramas;

	// Armazena os programas LPAS na mem�ria da m�quina de execu��o.
	Programa memoria[NUMERO_MAXIMO_DE_PROGRAMAS];

	// Registrador da m�quina de execu��o LPAS.
	int registrador;

	// Vari�veis do programa LPAS que est� sendo executado na m�quina de execu��o.
	int variaveis[NUMERO_MAXIMO_DE_VARIAVEIS];

	/* Identifica a instru��o, o n�mero da linha e o tipo de erro que pode ocorrer durante a execu��o de
	um programa LPAS. */
	ErroExecucao erroExecucao;

	/* Converte a instru��o mnem�nica LPAS para o seu c�digo de m�quina equivalente. Ver Tabela 1.
	Retorna o c�digo de m�quina da instru��o LPAS. */
	unsigned short obterCodigoInstrucao(string instrucao);

	// Define a instru��o, o n�mero da linha e o erro ocorrido na execu��o do programa.
	void definirErroExecucao(string instrucao, unsigned short numeroLinha, Erro erro);

	/* Executa a instru��o LPAS usando o valor armazenado em argumento ou na posi��o de mem�ria
	indicada por enderecoVariavel. Retorna o c�digo da instru��o executada. */
	unsigned short executarInstrucao(unsigned short codigoInstrucao, unsigned short enderecoVariavel, int argumento);
}; // class MaquinaExecucao

