#pragma once

#include <optional>
#include "LPAS.h"
#include "ErroExecucao.h"

#include <optional>

// Número máximo de variáveis do programa.
constexpr unsigned short NUMERO_MAXIMO_DE_VARIAVEIS = 25;

// Número máximo de programas da máquina de execução.
constexpr unsigned short NUMERO_MAXIMO_DE_PROGRAMAS = 5;

// Indica endereço inválido na memória da máquina de execução.
constexpr unsigned short ENDERECO_INVALIDO = 100;

// Esta classe representa a estrutura da máquina de execução de um programa LPAS.
class MaquinaExecucao {
public:
	// Inicia as variáveis da máquina de execução.
	MaquinaExecucao();

	/* Carrega um programa LPAS para a memória. Retorna true se o programa foi carregado, caso
	contrário retorna false. */
	bool carregar(Programa programa);

	// Obtém o número de programas LPAS carregados na memória da máquina de execução.
	int getNumeroDeProgramas();

	// Obtém um programa LPAS armazenado na posição de memória indicada por endereco.
	optional<Programa> obterPrograma(unsigned short endereco);

	/* Executa o programa armazenado na posição de memória indicada por endereco. Esta função deve
	usar a função obterCodigoInstrucao() para obter o código de máquina da instrução LPAS a ser
	executada. Retorna um objeto que permite identificar a instrução, o número da linha e o tipo de
	erro que pode ocorrer durante a execução do programa LPAS. */
	ErroExecucao executarPrograma(unsigned short endereco);

	/* Retorna um objeto que permite identificar a instrução, o número da linha e o tipo de erro que pode
	ocorrer durante a execução do programa LPAS. */
	ErroExecucao getErroExecucao();

private:
	// Número de programas LPAS carregados na memória da máquina de execução.
	unsigned short numeroDeProgramas;

	// Armazena os programas LPAS na memória da máquina de execução.
	Programa memoria[NUMERO_MAXIMO_DE_PROGRAMAS];

	// Registrador da máquina de execução LPAS.
	int registrador;

	// Variáveis do programa LPAS que está sendo executado na máquina de execução.
	int variaveis[NUMERO_MAXIMO_DE_VARIAVEIS];

	/* Identifica a instrução, o número da linha e o tipo de erro que pode ocorrer durante a execução de
	um programa LPAS. */
	ErroExecucao erroExecucao;

	/* Converte a instrução mnemônica LPAS para o seu código de máquina equivalente. Ver Tabela 1.
	Retorna o código de máquina da instrução LPAS. */
	unsigned short obterCodigoInstrucao(string instrucao);

	// Define a instrução, o número da linha e o erro ocorrido na execução do programa.
	void definirErroExecucao(string instrucao, unsigned short numeroLinha, Erro erro);

	/* Executa a instrução LPAS usando o valor armazenado em argumento ou na posição de memória
	indicada por enderecoVariavel. Retorna o código da instrução executada. */
	unsigned short executarInstrucao(unsigned short codigoInstrucao, unsigned short enderecoVariavel, int argumento);
}; // class MaquinaExecucao

