#include <iostream>

using namespace std;

struct cliente
{
	int id;
	char mesa;
	double conta;
};
cliente *joao;


int main()
{

	int *nota;
	int aluno;
	cin >> aluno;
	nota = &aluno;
	cout << "Endereço: " << nota << endl;
	cout << "Conteudo: " << *nota << endl;

	
	
	cliente *joao;
	joao = new cliente;
	cin >> joao->id;
	cin >> joao->mesa;
	cin >> joao->conta;

	cout << "Informações do cliente: " << endl;
	cout << "Cliente numero: " << joao->id << endl;
	cout << "Mesa: " << joao->mesa << endl;
	cout << "Conta a pagar: " << joao->conta << endl;
	delete joao;


	return 0;
}







