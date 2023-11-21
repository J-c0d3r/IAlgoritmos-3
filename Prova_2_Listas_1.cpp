#include <iostream>

using namespace std;

int main()
{

	int N; //variavel para o uso do tamanho do vetor
	int encontrado = 0; //variavel que servirá para verificar se valor foi encontrado ou nao, 0->nao encontrado 1->encontrado
	float X;
	float *p; //criacao do ponteiro

	cin >> N;

	float vet[N]; //criacao do vetor com o tipo float(real)

	p = vet; //ponteiro que está apontando para o vetor

	//aqui irá preencher o vetor
	for(int i = 0; i < N; i++)
	{
		cin >> vet[i];
	}

	cin >> X; //usuario entrará com o valor que deseja procurar

	//aqui fará a verredura pelo vetor
	for(int i = 0; i < N; i++)
	{
		if(*p == X) //verifica se o valor que o ponteiro aponta é igual ao valor procurado
		{
			cout << X << " foi encontrado no vetor" << endl; // caso seja igual, irá imprimir esta mensagem
			i = N; // i recebe o valor de N para parar o for
			encontrado = 1; //a variavel encontrado recebe o valor 1 dizendo que foi encontrado
		}
		p++; // caso nao tenha sido encontrado, o ponteiro "anda" para o proximo lugar onde o proximo valor está armazedado no vetor
	}

	//caso nao tenha sido encontrado o valor, irá imprimir esta mensagem
	if(encontrado == 0 )
	{
		cout << X << " nao esta no vetor" << endl;
	}

	return 0;
}
