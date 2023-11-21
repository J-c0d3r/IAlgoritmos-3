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
	int N = 0; //variavel que será usada para dizer quantos pontos será usado
	int estadoCarro = 0; //variavel que será usada para guardar se o carro está no caminho ou nao, 0->nao está 1->está

	cin >> N; //entrada da quantidade de pontos que será usada

	ponto P[N]; //variavel do tipo struct ponto onde será armazenado os pontos
	ponto Carro; //variavel do tipo ponto que servirá para armazenar os pontos do carro
	segmento S[N - 1]; //variavel que guardará a quantidade de segmentos que será utilizado

	//aqui é onde será preenchido os valores dos pontos nas structs
	for(int i = 0; i < N; i++)
	{
		cin >> P[i].x >> P[i].y;
	}

	cin >> Carro.x >> Carro.y; //aqui está entrando com os valores de x e y do carro

	//neste for, será primeiro para montar os segmentos e logo após testar se o carro está naquele segmento
	for(int i = 0; i < (N - 1); i++)//(N-1) por causa da quantidade de segmentosq que é a quantidade de pontos total menos 1
	{
		//aqui está criando os segmentos que serão utilizados posteriormente
		S[i].A = P[i];
		S[i].B = P[i + 1];

		//no primeiro if irá verificar se o carro está naquele segmento da posição i
		//caso esteja, o estado do carro será alterado para 1 e o i irá receber o valor máximo do N para parar a verificação no for
		if(ponto_segmento(S[i], Carro) == true)
		{
			estadoCarro = 1;
			i = N;
		}

	}

	//aqui será feito a verificação do estado do carro se é 0(fora da estrada) ou 1(no caminho)
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




