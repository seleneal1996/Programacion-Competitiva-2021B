#include<bits/stdc++.h>
using namespace std;

class Nodo
{
	public:
	int dato;
	Nodo* hijo_izq;
	Nodo* hijo_der;
};

Nodo* newNode(int dato);

Nodo* Crear_BST(int arr[],int izq, int der)
{
	if (izq > der)
	return NULL;

	int m = (izq + der)/2;
	Nodo *raiz = newNode(arr[m]);
	raiz->hijo_izq = Crear_BST(arr, izq,	m - 1);
	raiz->hijo_der = Crear_BST(arr, m + 1, der);

	return raiz;
}

Nodo* newNode(int dato)
{
	Nodo* node = new Nodo();
	node->dato = dato;
	node->hijo_izq = NULL;
	node->hijo_der = NULL;

	return node;
}

void postORDER(Nodo* node)
{
	if (node != NULL){
	if(node->hijo_izq) postORDER(node->hijo_izq);
	if(node->hijo_der) postORDER(node->hijo_der);
	cout<<"     "<<node->dato<<"\n ";
	}
	else return;
}
void preOrder(Nodo* node)
{
    if (node != NULL){
    preOrder(node->hijo_izq);
    preOrder(node->hijo_der);
    cout << node->dato << " " ;
    }
    else return;
}
int main()
{
	int arr[] = {3,5,4,1,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	Nodo *raiz = Crear_BST(arr, 0, n-1);
    postORDER(raiz);
    preOrder(raiz);
	return 0;
}
