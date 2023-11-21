#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>
#include <algorithm>

using namespace std;

// Funcao calcula distancia entre dois pontos, solicitando o ponto inicial e final de x e y
float dist(float x1, float x0, float y1, float y0)
{
	float distancia;
	distancia = sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0)));
	return distancia;
}

int main()
{
	float x[10], y[10]; // Vetores X e Y com no maximo 10 posicoes
	float distancia_ponto;	// Utilizada para salvar o resultado da funcao dist()
	float custo[10][10]; // Matriz de custo
	int n; // Numero de pontos

	// Definindo o ponto inicial
	x[0] = 0.00;
	y[0] = 0.00;

	// Entrando com o numero de pontos
	cin >> n;

	for(int i = 1; i <= n; i++)// i = 1, pois o ponto x[0] e y[0] ja foram definidos
	{
		// Entrando com as coordenadas de cada ponto i
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			// Calcula a distancia entre dois pontos e salva na variavel distancia_ponto
			distancia_ponto = dist(x[j], x[i], y[j], y[i]);
			// Adiciona a distancia calculada para a matriz custo
			custo[i][j] = distancia_ponto;
			// Espelha a matriz, cortando o processamento da matriz pela metade
			custo[j][i] = custo[i][j];
		}
	}

	int v[10]; // Vetor que será usado para as cidades que serao permutadas
	int p;	// Variavel auxiliar para definir o indice do vetor v
	float menor_custo = INT_MAX; // variavel usada para receber o menor custo
								 // foi inicializada com o maior numero inteiro
	float custo_caminho; // Custo do caminho que será atribuido

	//preenchimento do vetor v com a quantidades de pontos
	p = 0;
	for(int i = 1; i <= n; i++)
	{
		v[p] = i;
		p++;
	}

	int vet[10]; // Vetor para salvar o caminho percorrido no menor custo
	do
	{

		custo_caminho = custo[0][v[0]]; // Armazena o custo do Ponto Inicial -> Ponto v[0]

		// Incrimenta o custo da permutacao de uma sequencia de pontos
		for(int i = 0; i < n - 1; i++)
		{
			custo_caminho += custo[v[i]][v[i + 1]];
		}

		// Adiciona o custo para voltar para o ponto inicial
		custo_caminho += custo[v[n - 1]][0];

		// Verifica qual eh o menor custo, se foi o anterior ou se foi o que acabou de ser calculado
		menor_custo = min(menor_custo, custo_caminho);

		// salva o melhor caminho no vetor vet[]
		if (menor_custo >= custo_caminho)
		{
			for(int i = 0; i < n; i++)
			{
				vet[i] = v[i];
			}
		}

	}
	// Permuta a sequencia dos pontos para calcular uma nova sequencia de pontos
	while(next_permutation(v, v + (n)));

	// Imprime o menor custo com precisao de 2 casas decimais
	cout << fixed << setprecision(2) << menor_custo << endl;

	// Imprime as coordenadas dos pontos cujo caminho eh o menor
	cout << x[0] << " " << y[0] << endl;
	for(int i = 0; i < n; i++)
	{
		cout << fixed << setprecision(2) <<  x[vet[i]] << " " << y[vet[i]] << endl;
	}
	cout << x[0] << " " << y[0] << endl;

	return 0;
}
