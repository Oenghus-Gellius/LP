#pragma once

/*
9. Uma linguagem de máquina denominada LPAS - Linguagem de Programação para Aritmética
Simples é usada para escrever programas que executam as operações aritméticas somente com
números inteiros. As instruções LPAS são apresentadas na Tabela 1.
LPAS possui a seguinte organização:
1. Cada linha de código deve ter apenas uma única instrução.
2. As instruções e os seus argumentos variáveis devem ser escritos em maiúsculo.
3. Os comentários devem iniciar com ponto-e-vírgula.
4. Os programas LPAS são executados por uma Máquina de Execução (ME) ou processador.
Um programa é executado por vez.
5. A ME é responsável por carregar o programa para a memória e executá-lo.
6. A ME possui duas memórias (código e dados) e um único registrador que permite armazenar
um número inteiro.
7. A memória de código armazena os programas LPAS a serem executados pela ME.
8. A memória de dados armazena as variáveis do programa que está em execução. Todas as
variáveis são do tipo de dado inteiro.

Exemplos de programas LPAS:
00 ; Programa: soma.lpas
01 ; Descrição: Realização a soma de 2 números inteiros.
02 ;
03 READ X ; X recebe o valor lido do teclado
04 READ Y ; Y recebe o valor lido do teclado
05 LOAD X ; carrega o valor de X no registrador (registrador  X)
06 ADD Y ; soma Y com X e coloca o resultado no registrador (registrador  registrador + Y)
07 STORE Z ; armazena o resultado da soma na variável Z (Z  registrador)
08 WRITE Z ; escreve no vídeo o valor de Z (o resultado da soma)
09 HALT ; finaliza o programa
00 ; Programa: contar1a15.lpas
01 ; Descrição: Exibe os números ímpares de 1 a 15.
02 ;
03 MOV X, 1 ; X  1
04 LOAD X ; registrador  X
05 RDIV 2 ; registrador  X % 2
06 JPZERO 8 ; não exibe o valor de X se é par, ou seja, o resultado de X % 2 é zero.
07 WRITE X ; escreve o valor de X no vídeo se X é ímpar, ou seja, o resultado de X % 2 é um.
08 LOAD X ; registrador  X
09 SUB 15 ; registrador  registrador - 15
10 JPZERO 15 ; finaliza o programa se o valor de X é 15, ou seja, registrador é zero
11 LOAD X ; registrador  X
12 ADD 1 ; registrador  X + 1
13 STORE X ; X  registrador
14 JUMP 5 ; loop: desvia para o endereço de memória 5 correspondente a instrução RDIV 2
15 HALT ; finaliza o programa

Observe que nesses exemplos de programas LPAS cada linha de código é precedida pelo endereço
de sua localização na memória do programa. Essa memória é formada pelas linhas de código
(instruções) que compõem o programa. Um programa pode ter no máximo 100 instruções ou linhas
de código LPAS.

Tabela 1: Instruções de máquina LPAS

Código Instrução Descrição
10 READ Lê um valor do teclado para uma variável. Ex.: READ X ; lê um valor do teclado e armazena na variável X

11 WRITE Escreve no vídeo o valor armazenado em uma variável. Ex.: WRITE X ; escreve no vídeo o valor da variável X

20 MOV Movimenta o valor de uma variável ou um número para uma outra posição de memória. Ex.: MOV X, Y ; X  Y

MOV X, 20 ; X  20 21 LOAD Carrega o valor de uma variável para o registrador. Ex.: LOAD X ; registrador  X

22 STORE Armazena o valor do registrador em uma variável. Ex.: STORE X ; X  registrador

30 ADD Adiciona o valor do registrador ao valor de uma variável ou número e guarda o resultado no registrador.

Ex.: ADD X ; registrador  registrador + X ADD 20 ; registrador  registrador + 20 

31 SUB Subtrai o valor do registrador do valor de uma variável ou número e guarda o resultado no registrador. Ex.: SUB X ; registrador  registrador - X

SUB 20 ; registrador  registrador - 20 

32 MUL Multiplica o valor do registrador com o valor de uma variável ou número e guarda o resultado no registrador. Ex.: MUL X ; registrador  registrador * X MUL 20 ; registrador  registrador * 20

33 DIV Divide o valor do registrador pelo valor de uma variável ou número e guarda o resultado no registrador. Ex.: DIV X ; registrador  registrador / X DIV 20 ; registrador  registrador / 20

34 RDIV Calcula o resto da divisão do registrador pelo valor de uma variável ou número e guarda o resultado no registrador. Ex.: RDIV X ; registrador  registrador % X RDIV 20 ; registrador  registrador % 20

40 JUMP Desvia para um endereço de memória. Ex.: JUMP 20 ; desvia para o endereço 20 da memória

41 JPNEG Desvia para um endereço de memória se o valor do registrador for negativo. Ex.: JPNEG 20 ; desvia para o endereço 20 se o acumulador for negativo

42 JPZERO Desvia para um endereço de memória se o valor do registrador for zero. Ex.: JPZERO 20 ; desvia para o endereço 20 se o acumulador for zero

50 HALT Finaliza o programa.

O limite de memória da ME é de cinco programas, ou seja, esse é o número de programas que
podem ser carregados para a ME, sendo que somente um pode ser executado por vez. O
programador LPAS pode, por exemplo, digitar e carregar dois programas para escolher qual ele
deseja executar. Os programas devem ser numerados para o programador escolher qual programa
LPAS ele quer exibir ou executar.

Desenvolva um programa chamado LPAS que possui um menu com os comandos a seguir:

1. Editar programa: 

gera automaticamente um número para o programa, lê as instruções LPAS e
armazena o programa na memória da máquina de execução. O número
gerado para o programa deve iniciar em 1 e ser exibido para o usuário saber
que programa ele está editando. O programa LPAS deve gerar
automaticamente um número para cada linha de código a ser digitada pelo
programador LPAS. Esse número representa o endereço de localização da
instrução (linha de código) LPAS na memória do programa. Veja no exemplo
abaixo que os números na cor azul representam esses endereços de memória
que devem ser gerados automaticamente para o usuário digitar a instrução
LPAS na frente desse endereço.
00 ; Programa: soma.lpas
01 ; Descrição: Realização a soma de 2 números inteiros.
02 ;
03 READ X
04

2. Exibir programa: lê o número de um programa LPAS armazenado na memória da máquina de execução para exibir suas instruções.

3. Executar programa: lê o número de um programa LPAS armazenado na memória da máquina de execução para executá-lo.

4. Sair: finaliza o programa
*/

#include <string>

// Número máximo de instruções do programa.
constexpr unsigned short NUMERO_DE_INSTRUCOES = 100;

using namespace std;

// Esta classe representa a estrutura de um programa LPAS.
class Programa {
public:
	// Inicia as variáveis do programa com valores default.
	Programa();

	/* Lê as instruções de um programa LPAS para a memória. Retorna true se as instruções foram lidas
	com sucesso e false se ocorreu algum erro durante a leitura. */
	bool carregar();

	// Obtém o número de instruções do programa LPAS.
	unsigned short getNumeroDeInstrucoes();

	/* Obtém uma instrução LPAS armazenada na posição de memória indicada por endereco. Se o
	endereço de memória for inválido, retorna uma string nula. */
	string obterInstrucao(unsigned short endereco);

	/* Altera uma instrução armazenada na posição de memória indicada por endereco por uma nova
	instrucao. Retorna true se a instrução foi alterada. Se o endereço de memória for inválido, retorna
	false. */
	bool alterarInstrucao(string instrucao, unsigned short endereco);
	// Exibe no console as instruções do programa.
	void exibir();
private:
	// Número de instruções do programa.
	unsigned short numeroDeInstrucoes;

	/* Memória que armazena as instruções LPAS que compõem o programa.
	 Cada linha do programa é armazenada em uma posição do vetor. */
	string instrucoes[NUMERO_DE_INSTRUCOES];
}; // class Programa

