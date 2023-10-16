#pragma once


#include <vector>
#include <string>

using namespace std;

class Vetor {

public:
	/* Cria um objeto Vetor com a quantidade máxima de números definida por tamanho e os índices de
	acesso definidos de 0 a tamanho - 1. */
	Vetor(int tamanho);

	/* Cria um objeto Vetor com a quantidade máxima de números definida por tamanho e os índices de
	acesso definidos por limiteInferior e limiteSuperior. */
	Vetor(int tamanho, int limiteInferior, int limiteSuperior);

	void setNome(string nome);

	string getNome();

	int getLimiteInferior();

	int getLimiteSuperior();

	// Informa o número atual de elementos armazenados no objeto Vetor.
	int tamanho();

	// Informa a capacidade (número máximo de elementos) do objeto Vetor.
	int capacidade();

	/* Define um intervalo arbitrário de índices do Vetor, em vez de ter obrigatoriamente um intervalo
	definido de 0 (zero) a N - 1. O intervalo pode ser, por exemplo, de -(N / 2 - 1) a +(N / 2). Para N =
	200, teremos: -99 a 100 (-99..-1, 0, 1..100). */
	void definirIntervalo(int limiteInferior, int limiteSuperior);
	
	/* Armazena um número Vetor. Retorna true se o número foi armazenado. Se não foi possível
	armazenar porque atingiu a capacidade (número máximo de elementos), retorna false. */
	bool adicionar(int numero);

	/* Obtém, verificando os limites do Vetor, um número de acordo com o índice fornecido. Se o índice
	passado como argumento para a função for inválido (estiver fora dos limites do Vetor), o método
	deve alterar o parâmetro formal para 0 (zero equivale a false) e também deve retornar 0. Se o
	índice for válido, o parâmetro formal recebe 1 (um equivale a true) e o método deve retornar o
	número armazenado na posição indicado por indice. */
	int obter(int& indice);

	/* Altera um número do Vetor verificando os limites dos índices definidos. O método deve retornar
	true se a operação foi bem sucedida, no caso de erro deve retornar false. */
	bool alterar(int indice, int numero);

	/* Exclui, verificando os limites do Vetor, um número de acordo com o índice fornecido. Se o índice
	passado como argumento para a função for inválido (estiver fora dos limites do Vetor), o método
	deve retornar false. Se o índice for válido, o número deve ser excluído do Vetor e o método deve
	retornar true. */
	bool excluir(int indice);

	/* Compara dois objetos da classe Vetor. Por exemplo: v1.comparar(v2); compara o conteúdo dos
	objetos v1 e v2. A função deve retornar:
	- zero se os objetos possuem a mesma quantidade de elementos e são iguais;
	- um número negativo se este objeto possui menos elementos do que o objeto do parâmetro
	formal vetor;
	- um número positivo se este objeto possui mais elementos do que o objeto do parâmetro formal
	vetor, ou possui a mesma quantidade de elementos, mas os valores são diferentes. */
	int comparar(Vetor vetor);

	/* Copia o conteúdo dos membros de dados do objeto Vetor, passado como argumento, para os
	membros de dados deste objeto. Por exemplo: v1.copiar(v2); copia o conteúdo do objeto v2 para o
	objeto v1. Se o tamanho de v1 for menor do que v2 a cópia não será feita. Retorna true se a cópia
	foi realizada, caso contrário retorna false. */
	bool copiar(Vetor vetor);

	/* Exibe no console todos os números inteiros do objeto Vetor. Se o objeto Vetor possuir um nome,
definido pelo método setNome, ele deve ser exibido. */
	void exibir();

	

private:

	int limiteInferior = 0, limiteSuperior = 0;

	string nome;

	vector<int> vetor;

	/* Obtém o índice do objeto Vetor traduzindo o índice virtual de Vetor para o índice real do objeto
	vector do C++. Veja o exemplo abaixo para um objeto Vetor com 7 elementos e índices virtuais de
	
			-3 a +3.
		 Índice Virtual						Índice Real
		-3 (limiteInferior)					0
		-2									1
		-1									2
		0									3
		1									4
		2									5
		3 (limiteSuperior)					6 */
	int indiceReal(int indiceVirtual);

	/* Define o tamanho do objeto Vetor redimensionando o vector para um novo valor. Este método
	deve ser invocado pelos construtores da classe.*/
	void definirTamanho(int tamanho);
};
