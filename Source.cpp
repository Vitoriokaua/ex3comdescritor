/*) Fa�a uma fun��o que receba uma lista encadeada e retorne uma outra lista encadeada
com os mesmos elementos, nas mesmas posi��es. Note que toda a mem�ria deve ser
alocada, ou seja, a nova lista n�o apenas referencia as mesmas posi��es de mem�ria, e
sim cria suas pr�prias aloca��es.*/

#include <iostream>
using namespace std;

struct nolista
{
	int dado;
	nolista* ant;
	nolista* prox;

};


struct descritor
{
	nolista* ini;
	nolista* fim;
	int tam;
};

descritor* criarlista() {
	descritor* novo = new descritor;
	novo->ini = NULL;
	novo->fim = NULL;
	novo->tam = 0;
	return novo;
}

void inserir_fim(descritor* l, int dado) {
	nolista* novo = new nolista;
	novo->dado = dado;
	novo->ant = NULL;
	novo->prox = NULL;
	if (l->ini == NULL)
	{
		l->ini = novo;
		l->fim = novo;
		l->tam++;
	}
	else
	{
		l->fim->prox = novo;
		novo->ant = l->fim;
		l->fim = novo;
		l->tam++;
	}
}
descritor* mesmoelemento(descritor* l) {
	descritor* l2 = criarlista();
	nolista* p = l->ini;

	while (p != NULL)
	{
		inserir_fim(l2, p->dado);
		p = p->prox;
	}

	  return l2;
}

void imprimir(descritor* l) {
	nolista* p = l->ini;
	while (p != NULL)
	{
		cout << p->dado << "-";
		p = p->prox;
	}
}

int main() {
	descritor* l = criarlista();

	int dado;
	cout<< "informe um numero: (-1, PARA) ";
	cin >> dado;
	while (dado != -1)
	{
		inserir_fim(l, dado);
		cout << "informe um numero: (-1, PARA) ";
		cin >> dado;

	}

	descritor* noval =  mesmoelemento(l);


	cout << "lista 1: ";
	imprimir(l);
	cout << endl;
	cout << "lista com os mesmos elementos";
	imprimir(noval);

	delete l;
	delete noval;
}