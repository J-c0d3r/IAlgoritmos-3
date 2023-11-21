#include <iostream>
#include<list>
#include<iomanip>

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
		cout << arvore->info << " ";
		emOrdem(arvore->dir);
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

//detruir a arvore folha por folha
void tDestruir(treenodeptr &arvore)
{
	if(arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

void emNivel(treenodeptr t)
{
	treenodeptr n;
	list <treenodeptr> q;

	if(t != NULL)
	{
		q.push_back(t);
		while(!q.empty())
		{
			n = *q.begin();
			q.pop_front();
			if(n->esq != NULL)
			{
				q.push_back(n->esq);
			}
			if(n->dir != NULL)
			{
				q.push_back(n->dir);
			}
			cout << n->info << " ";
		}
	}

}

void contf(treenodeptr arvore, int &nFolhas)
{
	if(arvore != NULL)
	{
		contf(arvore->esq, nFolhas);
		contf(arvore->dir, nFolhas);
		if(arvore->esq == NULL && arvore->dir == NULL)
		{
			nFolhas++;
		}
	}
}

int conta_folhas(treenodeptr arvore)
{
	int nFolhas = 0;
	contf(arvore, nFolhas);

	return nFolhas;
}

void contar(treenodeptr arvore, float &qntd, float &valores)
{
	if(arvore != NULL)
	{
		contar(arvore->esq, qntd, valores);
		contar(arvore->dir, qntd, valores);
		qntd++;
		valores += arvore->info;
	}


}

float media(treenodeptr arvore)
{
	float qntd = 0.00;
	float somaValores = 0.00;
	float media;

	contar(arvore, qntd, somaValores);

	media = somaValores / qntd;

	return media;
}

treenodeptr pMenor(treenodeptr &arvore)
{
	pMenor(arvore->esq);
	if(arvore->esq == NULL)
	{
		return arvore;
	}

}

treenodeptr pMaior(treenodeptr &arvore)
{
	pMaior(arvore->dir);
	if(arvore->dir == NULL)
	{
		return arvore;
	}

}

treenodeptr tMenor(treenodeptr &raiz)
{
	treenodeptr t;
	t = raiz;
	if (t->esq == NULL) // encontrou o menor valor
	{
		raiz = raiz->dir;
		return t;
	}
	else // continua a busca na subarvore esquerda
		return tMenor(raiz->esq);
}


int tRemove(treenodeptr &raiz, int x)
{
	treenodeptr p;
	if (raiz == NULL) // arvore vazia
		return 1;
	if (x == raiz->info)
	{
		p = raiz;
		if (raiz->esq == NULL) // a raiz nao tem filho esquerdo
			raiz = raiz->dir;
		else if (raiz->dir == NULL) // a raiz nao tem filho direito
			raiz = raiz->esq;
		else // a raiz tem ambos os filhos
		{
			p = tMenor(raiz->dir);
			raiz->info = p->info;
		}
		delete p;
		return 0;
	}
	else if (x < raiz->info)
		return tRemove(raiz->esq, x);
	else
		return tRemove(raiz->dir, x);
}



/////////////////////////////////////////////////
int maiorPar(treenodeptr arvore, int &MPar)
{
	if(arvore != NULL)
	{
		maiorPar(arvore->esq, MPar);
		if(arvore->info % 2 == 0){
			if(arvore->info > MPar)
			MPar = arvore->info;
		}
		maiorPar(arvore->dir, MPar);
	}
	
	return MPar;
}

int main()
{
	treenodeptr arvore = NULL;

	int n = 0, MPar=0;

	cin >> n;
	while(n != -1)
	{
		tInsere(arvore, n);
		cin >> n;
	}

	MPar = maiorPar(arvore, MPar);
	
	cout << MPar << endl;

	return 0;
}
