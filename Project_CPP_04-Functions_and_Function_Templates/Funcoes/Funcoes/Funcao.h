#pragma once

#include <string>

using namespace std;

/*	A palavra reservada constexpr (constant expression) foi introduzida no C++11 e
	aperfei�oada no C++14.

	Ao contr�rio de const, constexpr tamb�m pode ser aplicado a fun��es e
	constructores de classe. Ela indica que o valor, ou valor de retorno,
	� constante e, quando poss�vel, � calculado em tempo de compila��o.

	Um valor integral (n�mero inteiro) constexpr pode ser usado onde um inteiro
	constante � necess�rio, como em defini��es de vetor e matriz.
	Quando um valor � calculado em tempo de compila��o e n�o tempo de execu��o,
	isso ajuda o programa a ser executado mais r�pido e usa menos
	mem�ria.

	A principal diferen�a entre vari�veis const e constexpr � que a inicializa��o de uma
	vari�vel const pode ser adiada at� o tempo de execu��o, e uma vari�vel constexpr
	deve ser inicializada em tempo de compila��o.

	Uma vari�vel pode ser declarada com constexpr quando tem um tipo literal (que
	pode ser determinado em tempo de compila��o) e � inicializada.
	Se a inicializa��o for realizada por um construtor, esse deve ser declarado como
	constexpr.

	Uma fun��o constexpr � aquela cujo valor de retorno � comput�vel em tempo de
	compila��o quando o c�digo chamador o requerer.
	O c�digo que chama a fun��o requer o valor de retorno em tempo de compila��o
	para inicializar uma vari�vel constexpr.
	Quando seus argumentos s�o valores constexpr, uma fun��o constexpr produz uma
	constante em tempo de compila��o. Quando ela � chamada com argumentos n�o
	constexpr, ou quando seu valor n�o � exigido em tempo de compila��o, ela produz
	um valor em tempo de execu��o como uma fun��o regular. Este comportamento
	duplo evita que voc� tenha que escrever vers�es constexpr e n�o constexpr da
	mesma fun��o.
*/

constexpr int fatorial(int numero) {
	return (numero == 0) ? 1 : numero * fatorial(numero - 1);
}

constexpr int CINCO = 5;

/*
  Fatorial de cinco calculado em tempo de compila��o.
*/
constexpr int FATORIAL_DE_CINCO = fatorial(CINCO);

class Funcao {
public:
	// Apresenta os t�picos deste cap�tulo.
	int funcao();

/*
	O padr�o C++11 definiu um significado original e revisado para a palavra reservada auto. 
	Antes ela declarava uma vari�vel na classe de armazenamento autom�tica, ou seja, uma 
	vari�vel que tem um tempo de vida local, como as vari�veis locais definidas 	em uma 
	fun��o. Com o C++11 a palavra reservada auto pode ser usada para declarar uma 
	vari�vel em que seu tipo de dado � deduzido com base na express�o de inicializa��o 
	de declara��o.

	O uso da palavra reservada auto � recomendado para a maioria das situa��es porque 
	ela fornece estes benef�cios:

	1. Robustez: Se o tipo da express�o for alterado (incluindo o tipo de retorno de fun��o) 
	                       ele simplesmente funcionar�.
	2. Desempenho: Voc� tem a garantia de que n�o haver� nenhuma convers�o.
	3. Usabilidade: Voc� n�o precisa se preocupar com dificuldades de ortografia e erros 
	                           de digita��o nos nomes dos tipo de dados.
	4. Efici�ncia: Sua codifica��o pode ser mais eficiente.

	Apresenta a palavra reservada auto.
*/
	void autoKeyword();

	void referencias();
	void staticKeyword();
	void testarPesquisa();
	void enumeracao();
	void templateDeFuncao();

	/* O uso do auto para definir o tipo do par�metro formal � v�lido a partir do C++20.
	   A sintaxe abaixo � conhecida como template de fun��o abreviado, introduzida 
	   no C++20.
	*/ 
	void imprimir(std::string mensagem, auto valor);

	template <typename T1, typename T2, typename T3> 
	void imprimir(T1 valor1, T2 valor2, T3 valor3);

	inline void exibirMensagem(string mensagem);

private:
	const int NAO_ACHOU = -1;

	// Substitui o caractere atual pelo caractere novo na string. Retorna a string modificada.
	string replace(string& str, char caracterAtual, char caracterNovo);

	/* L� e retorna uma string. A mensagem representa o texto a ser exibido antes de ler 
	   a string.
	*/
	string lerString(string mensagem);

	/* Pesquisa por todas as ocorr�ncias do n�mero no vetor.
	   Retorna a posi��o onde o n�mero foi localizado ou NAO_ACHOU se o n�mero n�o 
	   foi encontrado.
	*/
	int pesquisar(int vetor[], int tamanhoVetor, int numero);

	/* Pesquisa pela primeira ocorr�ncia da string no vetor. A pesquisa ocorrer� apenas no 
	   intervalo definido pelos par�metros posicaoInicial e posicaoFinal.
	   Retorna a posi��o onde a string foi localizada ou NAO_ACHOU se ela n�o foi 
	   encontrada.
	*/
	int pesquisar(string vetor[], string str, int posicaoInicial = 0, int posicaoFinal = 10);
}; // class Funcao