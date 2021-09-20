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
int dfs(Nodo* node)
{
      bool ret;
      if(!node)
         return 0;
      int izq_ = 1 + dfs(node->hijo_izq);
      int der_ = 1 + dfs(node->hijo_der);
      if(abs(izq_ - der_) > 1)
         ret = false;
      return max(izq_, der_);
}
//FUNCION PARA LA PREGUNTA 5: ESTA BALANCEADO EL ARBOL?

bool es_BST_balanceado(Nodo* raiz) {
      bool ret = true;
      dfs(raiz);
      return ret;
}
int main()
{
	int arr[] = {3,5,4,1,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	Nodo *raiz = Crear_BST(arr, 0, n-1);
    //postORDER(raiz);
    preOrder(raiz);
    //si retorna 1 esta BALANCEADO 
    cout <<"\n" <<(es_BST_balanceado(raiz))<<endl;
	return 0;
}

