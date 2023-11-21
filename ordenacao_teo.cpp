#include <iostream>

using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;

void tInsere(treenodeptr &p, int x)
{
	if(p == NULL)
	{
		p = new treenode;
		p-> info = x;
		p-> esq = NULL;
		p-> dir = NULL;
	}
	else if(x < p->info)
		tInsere(p->esq, x);
	else
		tInsere(p->dir, x);
}

treenodeptr tPesq(treenodeptr &p, int x) //treenodeptr retorna um ponteiro
{
	if(p == NULL)
	{
		return NULL;
	}
	else if(x == p->info)
	{
		return p;
	}
	else if(x < p->info)
	{
		return tPesq(p->esq, x);
	}
	else
		return tPesq(p->dir, x);
}

void preOrdem(treenodeptr arvore)
{
	if(arvore != NULL)
	{
		cout << arvore->info << endl;
		preOrdem(arvore->esq);
		preOrdem(arvore->dir);
	}
}

void emOrdem(treenodeptr arvore)
{
	if(arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << endl;
		emOrdem(arvore->dir);
	}
}

void emOrdemContraria(treenodeptr arvore)
{
	if(arvore != NULL)
	{
		emOrdemContraria(arvore->dir);
		cout << arvore->info << endl;
		emOrdemContraria(arvore->esq);
	}
}

void posOrdem(treenodeptr arvore)
{
	if(arvore != NULL)
	{
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << endl;
	}
}

//retorna em s, o valor da soma dos nós
void soma(treenodeptr arvore, int &s)
{
	if(arvore != NULL)
	{
		soma(arvore->esq, s);
		soma(arvore->dir, s);
		s = s + arvore->info;
		//cout << arvore - info << endl;
	}
}


int main()
{
	treenodeptr arvore = NULL;

	int i;
	cin >> i;
	while(i != -1)
	{
		tInsere(arvore, i);
		cin >> i;
	}

	emOrdemContraria(arvore);


	return 0;
}
