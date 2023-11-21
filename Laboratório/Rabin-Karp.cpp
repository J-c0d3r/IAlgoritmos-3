#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void rabin_karp(char T[], char P[], int tamT, int tamP, int d, int q)
{

	int h; //valor utilzado para calculo do hash
	int p = 0; //padrao convertido para inteiro
	int t = 0; //texto convertido para inteiro
	int ult = -1;
	int qntd = 0;

	for(int i = 0; i < tamP; i++)
	{
		p = (d * p + (P[i] - '0')) % q; //converte o padrao
		t = (d * t + (T[i] - '0')) % q; //converte o texto para o primeiro valor (t0)
	}

	h = (int)pow(d, tamP - 1) % q; // utilizado para calculo de hash

	for(int i = 0; i <= tamT - tamP; i++)
	{
		if(p == t) //se encontrei um valor de hash valido
		{
			//verifico se existe diferencas
			int j;
			for(j = 0; j < tamP; j++)
			{
				if(P[j] != T[i + j])
				{
					break;
				}
			}

			if(j == tamP)
			{
				//cout << i << endl;
				ult = i;
				qntd++;
			}

		}

		if(i < tamT - tamP) //se ainda nao cheguei no final
		{
			t = (d * ( t - (T[i] - '0') * h ) + (T[i + tamP] - '0')) % q; // atualizo o ti para ti+1
			if(t < 0)
				t += q;

		}
	}
	if(ult > -1)
	{
		cout << "Ultima ocorrencia: " << ult << endl;
		cout << qntd << " ocorrencia(s)" << endl;
	}
	else
	{
		cout << qntd << " ocorrencia(s)" << endl;
	}
}

int main()
{

	int N, M;
	cin >> N >> M;
	char texto[N];
	char padrao[M];

	//cardinalidade do alfabeto usado no texto, em outras palavras, qntd de caracteres diferentes utilizados
	int d = 10;
	//numero primo grande, para calcular os valores do hash
	int q = 13;

	//cout << "Digite o texto: ";
	cin >> texto;

	//cout << "Agora, digite o padrao a ser buscado: ";
	cin >> padrao;

	rabin_karp(texto, padrao, strlen(texto), strlen(padrao), d, q);

	return 0;
}
