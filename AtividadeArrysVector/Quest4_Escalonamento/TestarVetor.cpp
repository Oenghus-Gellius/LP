#include "TestarVetor.h"

#include <iostream>

using namespace std;

int TestarVetor::testVetor()
{
	Vetor vetorTest(11, -5, 5);

	Vetor vetorComp(13, -6, 6);

	Vetor vetorClone(13);

	vetorTest.setNome("Graus celsius");

	for (int i = -5; i < vetorTest.tamanho(); i++)
	{
		vetorTest.adicionar(i);
	}

	vetorTest.exibir();

	cout << "Nome vetor" << vetorTest.getNome() << endl;;

	cout << "O O limite inferior �>: " << vetorTest.getLimiteInferior() << endl;

	cout << "O O limite superior �>: " << vetorTest.getLimiteSuperior() << endl;

	cout << "O tamanho �.: " << vetorTest.tamanho() << endl;

	cout << "A capacidade �.: " << vetorTest.capacidade() << endl;

	cout << "definindo os valores" << endl;

	vetorTest.definirIntervalo(-6, 6);

	cout << "Intervalo.: ";
	vetorTest.exibir();

	vetorTest.excluir(1);

	vetorTest.exibir();

	vetorTest.adicionar(13);

	vetorTest.exibir();

	int indiceObter = 0;

	cout << "O Item buscado foi.: " << vetorTest.obter(indiceObter) << endl;

	int indiceTroca = -1;
	int numTroca = 99;

	cout << "Trocando no indice " << indiceTroca << "o " << vetorTest.obter(indiceTroca) << "por " << vetorTest.alterar(indiceTroca, numTroca) << endl;

	vetorTest.exibir();
	vetorComp.exibir();

	if (vetorTest.comparar(vetorComp) == 0)
	{
		cout << "Objetos possuem a mesma quantidade de elementos e s�o iguais" << endl;
	}
	else
	{
		if (vetorTest.comparar(vetorComp) < 0)
		{
			cout << "Objeto possui menos elementos do que o objeto do par�metro formal vetor" << endl;
		}
		else
		{
			cout << "Objeto possui mais elementos do que o objeto do par�metro formal vetor, ou possui a mesma quantidade de elementos, mas os valores s�o diferentes." << endl;
		}
	}

	vetorClone.copiar(vetorTest);

	cout << "\nTodas os Vetores" << "\n" << endl;

	vetorClone.exibir();

	vetorTest.exibir();
	vetorComp.exibir();

	return EXIT_SUCCESS;
}

int main() {

	return TestarVetor().testVetor();
}