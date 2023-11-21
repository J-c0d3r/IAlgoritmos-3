#include <iostream>

using namespace std;

//criacao da struct da arvore
struct treenode
{
	int info; //info eh a informacao que ser� guardada
	treenode *esq; //filho ou n� esquedo
	treenode *dir; //filho ou n� direito
};
typedef treenode *treenodeptr;

//funcao que ira inserir os valores na arvore
void tInsere(treenodeptr &p, int x)
{
	//nesta parte, primeiro verifica se a arvore est� vazia, caso esteja, coloca o valor que deseja na arvore
	//depois chama os dois n�s filhos como NULL(vazio)
	if(p == NULL)
	{
		p = new treenode;
		p-> info = x;
		p-> esq = NULL;
		p-> dir = NULL;
	}
	//mas caso ja exista valor na arvore, verificar� se o novo valor � maior ou menor em rela��o ao que ja est� inserido naquele n�
	else if(x < p->info)
		tInsere(p->esq, x);
	else
		tInsere(p->dir, x);
}

//funcao que far� o percurso em ordem
void emOrdem(treenodeptr arvore)
{
	if(arvore != NULL) //verificacao se a arvore est� fazia
	{
		emOrdem(arvore->esq);
		if(arvore->info % 2 != 0) // verifica se a informa��o que est� no n� � impar
		{
			cout << arvore->info << " "; //caso seja impar, ser� impresso o valor
		}
		emOrdem(arvore->dir);
	}
}

int main()
{
	treenodeptr arvore = NULL;
	int i = 0; // variavel que ser� utilizada para receber os valores do usuario

	cin >> i;

	//aqui verifica se o numero que foi inserido � diferente de -1, caso seja, far� a inser��o na arvore
	while(i != -1)
	{
		tInsere(arvore, i);
		cin >> i;
	}

	//chama a fun��o que mostrar� os valores em ordem
	emOrdem(arvore);


	return 0;
}
