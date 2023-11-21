#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

struct pessoa
{
	float peso; // peso em kg
	float altura; // altura em m
	float imc; // índice de massa corporal
};

int main()
{

	float MaiorIMC = -99999999;
	float MenorIMC = 99999999;
	int N;
	pessoa *v; // ponteiro do tipo pessoa(que é a struct)

	cin >> N;

	v = new pessoa[N];

	//aqui vai preencher os valores para preencher o vetor de structs
	for(int i = 0; i < N; i++)
	{
		cin >> v[i].peso;
		cin >> v[i].altura;
		v[i].imc = v[i].peso / (pow(v[i].altura, 2)); //aqui já está fazendo o calculo do imc
	}

	//aqui vai verificar qual é o maior e o menor imc
	for(int i = 0; i < N; i++)
	{
		if(v[i].imc > MaiorIMC)
		{
			MaiorIMC = v[i].imc;
		}
		if(v[i].imc < MenorIMC)
		{
			MenorIMC = v[i].imc;
		}
	}

	cout << fixed << setprecision(1); // fixa 1 casa decimal após a virgula
	cout << "Menor IMC: " << MenorIMC << endl; // mostra o menor imc
	cout << "Maior IMC: " << MaiorIMC << endl; // mostra o maior imc

	delete [] v;

	return 0;

}
