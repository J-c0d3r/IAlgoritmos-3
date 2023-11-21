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

int main()
{
	





	return 0;
}













