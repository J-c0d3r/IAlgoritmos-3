#include <iostream>

using namespace std;

//criacao da struct da arvore
struct treenode
{
	int info; //info eh a informacao que será guardada
	treenode *esq; //filho ou nó esquedo
	treenode *dir; //filho ou nó direito
};
typedef treenode *treenodeptr;

//funcao que ira inserir os valores na arvore
void tInsere(treenodeptr &p, int x)
{
	//nesta parte, primeiro verifica se a arvore está vazia, caso esteja, coloca o valor que deseja na arvore
	//depois chama os dois nós filhos como NULL(vazio)
	if(p == NULL)
	{
		p = new treenode;
		p-> info = x;
		p-> esq = NULL;
		p-> dir = NULL;
	}
	//mas caso ja exista valor na arvore, verificará se o novo valor é maior ou menor em relação ao que ja está inserido naquele nó
	else if(x < p->info)
		tInsere(p->esq, x);
	else
		tInsere(p->dir, x);
}

//funcao que fará o percurso em ordem
void emOrdem(treenodeptr arvore)
{
	if(arvore != NULL) //verificacao se a arvore está fazia
	{
		emOrdem(arvore->esq);
		if(arvore->info % 2 != 0) // verifica se a informação que está no nó é impar
		{
			cout << arvore->info << " "; //caso seja impar, será impresso o valor
		}
		emOrdem(arvore->dir);
	}
}

int main()
{
	treenodeptr arvore = NULL;
	int i = 0; // variavel que será utilizada para receber os valores do usuario

	cin >> i;

	//aqui verifica se o numero que foi inserido é diferente de -1, caso seja, fará a inserção na arvore
	while(i != -1)
	{
		tInsere(arvore, i);
		cin >> i;
	}

	//chama a função que mostrará os valores em ordem
	emOrdem(arvore);


	return 0;
}
