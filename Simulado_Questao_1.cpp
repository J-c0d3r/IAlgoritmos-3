#include <iostream>

using namespace std;

int main()
{

	int N, qntd3 = 0;
	int *p;

	cin >> N;

	int vet[N];

	p = vet;

	for(int i = 0; i < N; i++)
	{
		cin >> vet[i];
	}

	for(int i = 0; i < N; i++)
	{
		if(*p % 3 == 0)
		{
			qntd3++;
		}
		p++;

	}

	cout << qntd3 << endl;

	return 0;
}
