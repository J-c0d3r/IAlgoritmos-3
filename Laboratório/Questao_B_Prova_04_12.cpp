#include <iostream>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

struct reta
{
	ponto A;
	ponto B;
};
typedef reta segmento;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

/*
Posicao de C em relacao ao segmento AB
1 -> esquerda
-1 -> direita
0 -> colinear
*/
int sentido(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float vet;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	vet = vetorial(AB, AC);
	if(vet > 0)
		return 1;
	else if(vet < 0)
		return -1;
	else
		return 0;
}

// Verifica se um ponto pertence a um segmento
bool ponto_segmento(segmento S, ponto P)
{
	if(sentido(S.A, S.B, P) != 0)
		return false;
	else if(P.x > S.A.x && P.x < S.B.x)
		return true;
	else if(P.x < S.A.x && P.x > S.B.x)
		return true;
	else if(P.y < S.A.y && P.y > S.B.y)
		return true;
	else if(P.y > S.A.y && P.y < S.B.y)
		return true;
	else
		return false;
}

int main()
{
	int N = 0; //variavel que ser� usada para dizer quantos pontos ser� usado
	int estadoCarro = 0; //variavel que ser� usada para guardar se o carro est� no caminho ou nao, 0->nao est� 1->est�

	cin >> N; //entrada da quantidade de pontos que ser� usada

	ponto P[N]; //variavel do tipo struct ponto onde ser� armazenado os pontos
	ponto Carro; //variavel do tipo ponto que servir� para armazenar os pontos do carro
	segmento S[N - 1]; //variavel que guardar� a quantidade de segmentos que ser� utilizado

	//aqui � onde ser� preenchido os valores dos pontos nas structs
	for(int i = 0; i < N; i++)
	{
		cin >> P[i].x >> P[i].y;
	}

	cin >> Carro.x >> Carro.y; //aqui est� entrando com os valores de x e y do carro

	//neste for, ser� primeiro para montar os segmentos e logo ap�s testar se o carro est� naquele segmento
	for(int i = 0; i < (N - 1); i++)//(N-1) por causa da quantidade de segmentosq que � a quantidade de pontos total menos 1
	{
		//aqui est� criando os segmentos que ser�o utilizados posteriormente
		S[i].A = P[i];
		S[i].B = P[i + 1];

		//no primeiro if ir� verificar se o carro est� naquele segmento da posi��o i
		//caso esteja, o estado do carro ser� alterado para 1 e o i ir� receber o valor m�ximo do N para parar a verifica��o no for
		if(ponto_segmento(S[i], Carro) == true)
		{
			estadoCarro = 1;
			i = N;
		}

	}

	//aqui ser� feito a verifica��o do estado do carro se � 0(fora da estrada) ou 1(no caminho)
	if(estadoCarro == 0)
	{
		cout << "O carro esta fora do caminho" << endl;
	}
	else
	{
		cout << "O carro esta no caminho" << endl;
	}


	return 0;
}




