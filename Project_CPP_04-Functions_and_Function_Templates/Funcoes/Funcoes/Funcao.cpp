#define _USE_MATH_DEFINES 

#include <iostream>
#include <cstdlib> // Requerido por _countof (essa macro n�o � padr�o, s� funciona no Microsoft C++).
#include <clocale>
#include <cmath>    // Requerido por M_PI.
#include <iomanip> // Requerido por setw e setprecision.
#include "Funcao.h"

void Funcao::autoKeyword() {
	/*
		auto c = 'c', i = 6;  // Erro: porque a vari�vel c � char e i � int.

		Para corrigir esse erro devemos assegurar que as inicializa��es na lista de defini��o 
		de vari�veis sejam do mesmo tipo de dado ou que elas sem feitas em linhas 
		separadas.
	*/
	const auto PI = M_PI; // constante double, logo n�o se pode modificar o PI.
	auto numero = 10;  // int
	auto caractere = 'A'; // char
	auto number = numero; // int
	auto& refNumero = numero; // refer�ncia para int

	auto palavra = "almo�o"; // a string da Linguagem C, ou seja, o vetor de caracteres terminado com nulo ('\0').
	auto frase = string("T� com fome."); // objeto string do C++

	auto tamanhoFrase = frase.length(); // size_t (unsigned int)

	cout << "\n- Palavra reservada auto\n\tPi = " << setw(20) << setprecision(20) << PI <<
		     endl;
} // autoKeyword()

void Funcao::referencias() {
	string path = "/home/aluno";

	cout << "Diret�rio no Linux: " << path;

	replace(path, '/', '\\');

	cout << "\nDiret�rio no Windows: " << path << endl;

	int x = 10, y = 15;

	/* A refer�ncia deve ser iniciada na defini��o. Refer�ncia n�o � ponteiro, logo 
	   int& (refer�ncia) � diferente de int* (ponteiro).

		 refX = &x;  // ERRO: n�o se pode converter um ponteiro para int (int *) em (int).
	*/
	int& refX = x;

	// Define um refer�ncia para uma constante do tipo int.
	const int& refConstX = x;

	/*ERRO: n�o � permitido alterar uma vari�vel usando uma refer�ncia para uma constante.
	 
			refConstX = 50; 
	*/
	cout << "\n- Refer�ncias\n\tx = " << x << "\n\tx via refX = " << refX << endl;

	refX = 20;
	cout << "\tx = " << x << "\n\tx via refX = " << refX << endl;

	refX = y;
	cout << "\tx = " << x << "\n\tx via refX = " << refX << endl;
} // referencias()

void Funcao::testarPesquisa() {
	int posicao, teste = 1, numeros[] = { 2, 4, 2, 6, 2, 8 };
	string palavra, palavras[] = { "sol", "terra", "lua", "mar" , "uva", "abacaxi", "laranja", "ameixa", "fogo", "praia", "oi" };

	cout << "\n- Testar Pesquisa";
	do {
		posicao = pesquisar(numeros, sizeof numeros / sizeof(int), 2);

		if (posicao != NAO_ACHOU)
			cout << "\n\tPosi��o: " << posicao;

	} while (posicao != NAO_ACHOU);

	cout << "\n\n- Pesquisar string";
	do {
		switch (teste) {
		case 1: palavra = lerString("\n\tTeste 1: pesquisa na primeira metade do vetor\n\tPalavra: ");
			posicao = pesquisar(palavras, palavra, 0, _countof(palavras) / 2);
			break;

		case 2:  palavra = lerString("\n\tTeste 2: pesquisa na segunda metade do vetor\n\tPalavra: ");
			posicao = pesquisar(palavras, palavra, _countof(palavras) / 2 + 1);
			break;

		default: // Usado a partir do teste 3.
			palavra = lerString("\n\tTeste 3: pesquisa em todo o vetor\n\tPalavra: ");
			posicao = pesquisar(palavras, palavra);
		}
		teste++;

		if (posicao != NAO_ACHOU)
			cout << "\n\tA palavra \"" << palavra << "\" foi localizada na posi��o " << posicao << ".\n";
		else
			if (palavra != "fim")
				cout << "\tPalavra n�o localizada.\n";
	} while (palavra != "fim");
} // testarPesquisa()

/* Testa os m�todos p�blicos da classe Funcao. Portanto,  os m�todos privados dessa
* classe n�o ser�o invocados abaixo.
*/
int Funcao::funcao()  {
	setlocale(LC_ALL, "pt-BR");

	this->referencias();
	autoKeyword(); // equivale a this->autoKeyword();
	staticKeyword();
	testarPesquisa();
	enumeracao();
	templateDeFuncao();

	exibirMensagem("\n- Fatorial\n\tfat(5) = ");	cout << FATORIAL_DE_CINCO;
	exibirMensagem("\n\tfat(10) = ");				    cout << fatorial(10) << endl;

	return EXIT_SUCCESS;
}

string Funcao::replace(string& str, char caracterAtual, char caracterNovo) {
	/* A string C++ permite acessar cada caractere usando o operador colchetes por
	     causa do recurso de sobrecarga de operadores da linguagem.
    */
	for (size_t indice = 0; indice < str.length(); indice++)
		if (str[indice] == caracterAtual)
			str[indice] = caracterNovo;

	return str;
}

/* L� e retorna uma string. A mensagem representa o texto a ser exibido antes de ler
	 a string.
*/
string Funcao::lerString(string mensagem) {  
	string palavra;

	cout << mensagem;
	getline(cin, palavra);

	return palavra;
}

/* Pesquisa por todas as ocorr�ncias do n�mero no vetor.
   Retorna a posi��o onde o n�mero foi localizado ou NAO_ACHOU se o n�mero n�o
   foi encontrado.
*/
int Funcao::pesquisar(int vetor[], int tamanhoVetor, int numero) {  
	/* As vari�veis locais est�ticas n�o s�o armazendas na pilha como as demais vari�veis
	   locais, e sim na regi�o de mem�ria conhecida como �rea de dados globais e est�ticos.
	*/
	static int posicao = 0; // Essa inicia��o � feita somente na primeira chamada da fun��o.

	for ( ; posicao < tamanhoVetor; posicao++)
		if (vetor[posicao] == numero)
			return posicao++;

	return NAO_ACHOU;
}

/* Pesquisa pela primeira ocorr�ncia da string no vetor. A pesquisa ocorrer� apenas no
   intervalo definido pelos par�metros posicaoInicial e posicaoFinal.
   Retorna a posi��o onde a string foi localizada ou NAO_ACHOU se ela n�o foi
   encontrada.
*/
int Funcao::pesquisar(string vetor[], string str, int posicaoInicial, int posicaoFinal) {  
	for (int indice = posicaoInicial; indice <= posicaoFinal; indice++)
		if (str == vetor[indice]) // ou (str.compare(vetor[indice]) == 0)    
			return indice;

	return NAO_ACHOU;
}

void Funcao::staticKeyword() {
	/*  Use sempre o static_cast em C++ para realizar a coer��o (cast) de tipo de dado, 
	      porque ele captura, em tempo de compila��o, convers�es de tipo que n�o podem 
		  ser realizadas com seguran�a.

		  A coer��o (cast) de tipo de dado abaixo n�o � permitida pelo compilador C++, 
		  porque o static_cast faz a verifica��o de seguran�a de tipo.

		  O n�mero hexadecimal B8000 em decimal � 753.664.
		  int *ptrInt = static_cast<int *>(0xB8000); 
		  
		  A linha abaixo � permitida pelo compilador C / C++, mas representa um erro em 
		  potencial. Portanto, n�o fa�a isso. Sempre que for fazer um cast em C++ use o 
		  static_cast.
	 */
	double* ptrDouble = (double*)(100);

	/* O acesso abaixo representa um erro grave porque voc� est� tentando acessar uma
	     posi��o de mem�ria desconhecida.
	 
			 *ptrDouble = 9.5;
	*/
} // staticKeyword()

void Funcao::enumeracao() {
	/* Enumera��o � uma lista de constantes com valor inicial default zero na primeira constante.
             A defini��o abaixo � uma enumera��o sem escopo.
	*/
	enum Erro { ERRO_LEITURA = 10, ERRO_GRAVACAO };

	// Enumera��o com escopo.
	enum class Sudeste { ES, MG, RJ, SP };

	string estados[] = { "Esp�rito Santo", "Minas Gerais", "Rio de Janeiro", "S�o Paulo" };

	int erro = ERRO_LEITURA,
		mg = static_cast<int>(Sudeste::MG);

	cout << "\n- Enumera��o\n\tErro de leitura = " << ERRO_LEITURA << "\n\tMG = " << mg 
		     << "\n\tES = " << static_cast<int>(Sudeste::ES);

	cout << "\n\n- Estados da Regi�o Sudeste\n";
	for (Sudeste uf = Sudeste::ES; uf <= Sudeste::SP; 
		                                                             uf = static_cast<Sudeste>(static_cast<int>(uf) + 1))
		cout << "\n\t" << estados[static_cast<int>(uf)];

	cout << endl;
} // enumeracao() 

inline void Funcao::exibirMensagem(string mensagem) {
	cout << mensagem;
}

// Implementa um template de fun��o com um par�metro de tipo formal. 
void Funcao::imprimir(std::string mensagem, auto valor) 
{
	cout << "\t" << mensagem << valor << endl;
}

// Implementa um template de fun��o com tr�s par�metros de tipo formal diferentes.
template<typename T1, typename T2, typename T3> 
void Funcao::imprimir(T1 valor1, T2 valor2, T3 valor3) 
{
	cout << "\n\tValor 1 = " << valor1
		<< "\n\tValor 2 = " << valor2
		<< "\n\tValor 3 = " << valor3 << endl;
}

// Apresenta o uso de templates de fun��es.
void Funcao::templateDeFuncao() {
	cout << "\n- Template de Fun��o\n\n";

	imprimir("Artista: ", "Michael Jackson");
	imprimir("Nota: ", 35.0);
	imprimir("Idade: ", 18);
	imprimir(25, "frio", 'A');
}

int main() {
	/* ERRO: n�o se pode invocar um m�todo privado fora da classe, ou seja, fora de uma
	         fun��o que n�o pertence a classe.       
	 
			string path = "/home/aluno";
			Funcao f;
			f.replace(path, '/', '\\');   // ERRO: replace � privado.
	*/

	/* Solu��o 1 para invocar um m�todo da classe Funcao.
	 
		Funcao funcao;
		return funcao.funcao();

	   Solu��o 2 para invocar um m�todo da classe Funcao. 
	*/
	return Funcao().funcao();
}
