#pragma once

/*
4. Desenvolva uma classe chamada Vetor separando a interface da implementa��o e usando o
template de classe vector da C++ Standard Library. Um objeto da classe Vetor pode armazenar no
m�ximo N elementos do tipo int, onde N � definido pelo usu�rio como par�metro do construtor
da classe Vetor. A interface da classe Vetor est� listada abaixo e n�o pode ser modificada.
*/

#pragma once
#include <vector>
#include <string>

using namespace std;

class Vetor {
public:
	/* Cria um objeto Vetor com a quantidade m�xima de n�meros definida por tamanho e os �ndices de
	acesso definidos de 0 a tamanho - 1. */
	Vetor(int tamanho);

	/* Cria um objeto Vetor com a quantidade m�xima de n�meros definida por tamanho e os �ndices de
	acesso definidos por limiteInferior e limiteSuperior. */
	Vetor(int tamanho, int limiteInferior, int limiteSuperior);

	void setNome(string nome);

	string getNome();

	int getLimiteInferior();

	int getLimiteSuperior();

	// Informa o n�mero atual de elementos armazenados no objeto Vetor.
	int tamanho();

	// Informa a capacidade (n�mero m�ximo de elementos) do objeto Vetor.
	int capacidade();

	/* Define um intervalo arbitr�rio de �ndices do Vetor, em vez de ter obrigatoriamente um intervalo
	definido de 0 (zero) a N - 1. O intervalo pode ser, por exemplo, de -(N / 2 - 1) a +(N / 2). Para N =
	200, teremos: -99 a 100 (-99..-1, 0, 1..100). */
	void definirIntervalo(int limiteInferior, int limiteSuperior);

	/* Armazena um n�mero Vetor. Retorna true se o n�mero foi armazenado. Se n�o foi poss�vel
	armazenar porque atingiu a capacidade (n�mero m�ximo de elementos), retorna false. */
	bool adicionar(int numero);

	/* Obt�m, verificando os limites do Vetor, um n�mero de acordo com o �ndice fornecido. Se o �ndice
	passado como argumento para a fun��o for inv�lido (estiver fora dos limites do Vetor), o m�todo
	deve alterar o par�metro formal para 0 (zero equivale a false) e tamb�m deve retornar 0. Se o
	�ndice for v�lido, o par�metro formal recebe 1 (um equivale a true) e o m�todo deve retornar o
	n�mero armazenado na posi��o indicado por indice. */
	int obter(int& indice);

	/* Altera um n�mero do Vetor verificando os limites dos �ndices definidos. O m�todo deve retornar
	true se a opera��o foi bem sucedida, no caso de erro deve retornar false. */
	bool alterar(int indice, int numero);

	/* Exclui, verificando os limites do Vetor, um n�mero de acordo com o �ndice fornecido. Se o �ndice
	passado como argumento para a fun��o for inv�lido (estiver fora dos limites do Vetor), o m�todo
	deve retornar false. Se o �ndice for v�lido, o n�mero deve ser exclu�do do Vetor e o m�todo deve
	retornar true. */
	bool excluir(int indice);

	/* Compara dois objetos da classe Vetor. Por exemplo: v1.comparar(v2); compara o conte�do dos
	objetos v1 e v2. A fun��o deve retornar:
	- zero se os objetos possuem a mesma quantidade de elementos e s�o iguais;
	- um n�mero negativo se este objeto possui menos elementos do que o objeto do par�metro
	formal vetor;
	- um n�mero positivo se este objeto possui mais elementos do que o objeto do par�metro formal
	vetor, ou possui a mesma quantidade de elementos, mas os valores s�o diferentes. */
	int comparar(Vetor vetor);

	/* Copia o conte�do dos membros de dados do objeto Vetor, passado como argumento, para os
	membros de dados deste objeto. Por exemplo: v1.copiar(v2); copia o conte�do do objeto v2 para o
	objeto v1. Se o tamanho de v1 for menor do que v2 a c�pia n�o ser� feita. Retorna true se a c�pia
	foi realizada, caso contr�rio retorna false. */
	bool copiar(Vetor vetor);

	/* Exibe no console todos os n�meros inteiros do objeto Vetor. Se o objeto Vetor possuir um nome,
definido pelo m�todo setNome, ele deve ser exibido. */
	void exibir();

private:
	int limiteInferior = 0, limiteSuperior = 0;
	string nome;
	vector<int> vetor;

	/* Obt�m o �ndice do objeto Vetor traduzindo o �ndice virtual de Vetor para o �ndice real do objeto
	vector do C++. Veja o exemplo abaixo para um objeto Vetor com 7 elementos e �ndices virtuais de
	-3 a +3.
								�ndice Virtual					�ndice Real
								-3(limiteInferior)					0
								-2									1
								-1									2
								0									3
								1									4
								2									5
								3 (limiteSuperior)					6 */
	int indiceReal(int indiceVirtual);

	/* Define o tamanho do objeto Vetor redimensionando o vector para um novo valor. Este m�todo
	deve ser invocado pelos construtores da classe.*/
	void definirTamanho(int tamanho);
};
