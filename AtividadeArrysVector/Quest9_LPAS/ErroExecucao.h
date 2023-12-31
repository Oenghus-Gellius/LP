#pragma once

#include <string>

using namespace std;

/* C�digos resultantes da execu��o do programa LPAS. Os c�digos v�lidos s�o:
0 = execu��o bem sucedida;
1 = instru��o LPAS inv�lida;
2 = argumento de instru��o LPAS inv�lido;
3 = argumento de instru��o LPAS ausente;
4 = duas ou mais instru��es LPAS na mesma linha de c�digo;
5 = s�mbolo inv�lido.*/
enum class Erro {
	EXECUCAO_BEM_SUCEDIDA, INSTRUCAO_LPAS_INVALIDA,
	ARGUMENTO_INSTRUCAO_LPAS_INVALIDO,
	ARGUMENTO_INSTRUCAO_LPAS_AUSENTE, MUITAS_INSTRUCOES, SIMBOLO_INVALIDO
};

/* Esta classe representa a instru��o, o n�mero da linha e o tipo de erro que pode ocorrer durante a execu��o
de um programa LPAS.*/

class ErroExecucao {
public:
	ErroExecucao();
	ErroExecucao(string instrucao, unsigned short numeroLinha, Erro erro);
	string getInstrucao();
	unsigned short getNumeroLinha();
	Erro getErro();
	void setInstrucao(string instrucao);
	void setNumeroLinha(unsigned short numeroLinha);
	void setErro(Erro erro);
private:
	string instrucao;
	unsigned short numeroLinha = 0;
	Erro erro;
};
