#include <iostream>

using namespace std;

int main()
{
	int *p;
	int N, MPar = -99999999;

	cin >> N;

	p = new int [N];

	for(int i = 0; i < N; i++)
	{
		cin >> p[i];
	}
	
	for(int i = 0; i < N; i++)
	{
		if(*p % 2 == 0)
		{
			if(MPar < *p)
				MPar = *p;
		}
		p++;
	}

	cout << MPar << endl;

	delete [] p;
	
	return 0;
}
