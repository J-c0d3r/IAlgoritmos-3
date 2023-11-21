#include <iostream>
#include <cstring> // biblioteca para usar o comando strcpy()

using namespace std;

void calcula_LPS(int lps[], char P[], int tamP)
{
	// tamanho do maior prefixo que tambem eh sufixo anterior
	int tam = 0;

	lps[0] = 0; // caso base

	// o loop calcula lps[i] para i = 1 ate tamP-1
	int i = 1;
	while (i < tamP)
	{
		if (P[i] == P[tam]) // se encontrar uma letra que bate tanto como prefixo quanto como sufixo
		{
			tam++; // aumento o tamanho do maior prefixo que tambem eh sufixo
			lps[i] = tam; // salvo o valor para esse prefixo
			i++; // vou para o proximo prefixo
		}
		else // (p[i] != p[tam]) se encontrar uma letra que nao bate como prefixo e sufixo
		{
			if (tam != 0) // se o tamanho do maior prefixo que tambem eh sufixo atual for diferente de 0
			{
				tam = lps[tam - 1]; // volto pro maior prefixo que tambem eh sufixo considerando o prefixo anterior
				// Note que neste caso nao incrementamos o 'i'
			}
			else // se o tamanho do maior prefixo que tambem eh sufixo atual for 0
			{
				lps[i] = 0; // o maior prefixo que tambem é prefixo agora vale 0
				i++; // vou para o proximo prefixo
			}
		}
	}
}

int kmp(char T[], char P[], int tamT, int tamP)
{
	int qntd = 0; // variavel que servirá para "contar" as quantidades que apareceu ANA no texto

	int lps[tamP]; //vetor que indica para onde voltarei no padrao quando ocorrer um mismatch
	//lps-> indica o tamanho do maior sufixo de p[0...i] que tambem eh prefixo de p[0...i] (exceto a string inteira)

	calcula_LPS(lps, P, tamP);

	int j = 0; //j eh tamanho do meu match atual, onde eu estou no meu padrao
	int i = 0; //posicao no texto

	while(i < tamT)
	{
		if(T[i] == P[j])// macth
		{
			j++;
			i++;
			if(j == tamP)
			{
				qntd++; //caso tenha encontrado a palavra ele soma +1
				j = lps[j - 1];
			}
		}
		else //mismatch
		{
			if(j != 0) //se ocorreu mismatch depois de j matchs
				j = lps[j - 1];
			else //mismatch na comparacao da primeira letra
			{
				i++;
			}
		}
	}

	return qntd; // retorna o valor total da quantidade

}

int main()
{
	char P[4], T[100]; // variavel P é o padrao a ser procurado e a variavel T é o texto

	strcpy(P, "ANA"); // aqui é a função que irá "copiar" a palavra ANA para dentro da variavel P

	cin.getline(T, 100); // aqui é a função que receberá a frase inteira

	// aqui chama a função para realizar a busca da palavra, e depois de econtrar irá retornar a quantidada de vezes que apareceu ANA no texto
	cout << kmp(T, P, strlen(T), strlen(P)) << endl;

	return 0;
}
