#include <iostream>
#include <list>
#include <iomanip>

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

//funcao que calculara a media atraves do nivel
float calcMedia(treenodeptr arvore)
{
	treenodeptr n; // criacao da variavel "n" do tipo treenodeptr(arvore)
	list <treenodeptr> q;
	float soma = 0, qntd = 0; // variaveis que serao utilizadas para o calculo da media

	if(arvore != NULL)
	{
		q.push_back(arvore);
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
			soma += n->info;
			qntd++;
		}
	}

	return (soma / qntd); // retorna a razao da soma pela quantidade

}

int main()
{
	treenodeptr arvore = NULL;
	int i = 0; // variavel que ser� utilizada para receber os valores do usuario
	float media; // variavel que ser� usada para receber o valor de media

	cin >> i;

	//aqui verifica se o numero que foi inserido � diferente de -1, caso seja, far� a inser��o na arvore
	while(i != -1)
	{
		tInsere(arvore, i);
		cin >> i;
	}

	// atribui o resultado da media atrav�s da funcao que foi chamada na variavel media
	media = calcMedia(arvore);

	cout << fixed << setprecision(2); // fixa 2 casas decimais ap�s a virgula
	cout << "media = " << media << endl; // imprime o resultado

	return 0;
}
