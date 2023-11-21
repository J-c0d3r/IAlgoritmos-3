#include <iostream>
#include <iomanip>
#include <cmath>
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

float escalar(vetor A, vetor B)
{
	float resultado;
	resultado = A.x * B.x + A.y * B.y;
	return resultado;

}

float vetorial(vetor A, vetor B)
{
	float resultado;
	resultado = A.x * B.y + A.y * B.x;
	return resultado;

}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;

}

int sentido(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor BC;


}

float area_poligono(ponto v[], int n)
{
	float area = 0;
	for(int i = 0; i < n - 2; i++)
	{
		area = area + area_triangulo(v[0], v[i + 1], v[i + 2]);
	}
	return area;
}

bool ponto_segmento(segmento S, ponto P)
{
	if(sentido(S.A, S.B, P) != 0 ){
		return false;
	}else if(P.x > S.A.x && P.x < S.B.x){
		return false;
	}else if(P.x < S.A.x && )
	
	
}

//AB x BC > 0 para cima curva a esquerda
//AB x AC < 0 para baixo curva a direita
//AB x AC = 0 nulo

int main()
{
	int n;
	ponto A0, A1, A2;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> A0.x >> A0.y;
		cin >> A1.x >> A1.y;
		cin >> A2.x >> A2.y;

		//A=A0, B=A1, C=A2
		vetor AB, AC, BC;
		AB = cria_vetor(A0, A1);
		AC = cria_vetor(A0, A2);
		BC = cria_vetor(A1, A2);

		float tamAB = sqrt((AB.x * AB.x + AB.y * AB.y));
		float tamAC = sqrt((AC.x * AC.x + AC.y * AC.y));
		float tamBC = sqrt((BC.x * BC.x + BC.y * BC.y));

		if(((tamAB + tamAC) > tamBC) && ((tamAB + tamBC) > tamAC) && ((tamBC + tamAC) > tamAB))
		{
			cout << fixed << setprecision(2);
			cout << area_triangulo(A0, A1, A2) << endl;

		}
		else
		{
			cout << "Nao formam triangulo" << endl;
		}


	}



	return 0;
}













