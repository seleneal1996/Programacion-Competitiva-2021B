#include <iostream>
#include<bits/stdc++.h> //libreria STL
using namespace std;

int main()
{
   //Leer entrada y salida de forma rapida
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  //Declaramos longitud de matrix
	int n;
  //declaramos la matrx valor
  vector<long long > valor(n);
  // el long long para evitar problema de desbordamiento
  long long b= -1e18;
  long long p= 0;
  for(int i=0;i<n;i++)
  {
    //verificando si para valor de la matrix es mejor 
    //llevar la variable p que estar solo
    if(p+valor[i]>=valor[i]){
      p+=valor[i]; //mantenemos el p y se le agrega el valor real
    }
    else{
      p=valor[i]; //actualizar
    }
    b=max(b,p); //obtener max
  }
  cout<<b;// imprimir el mejor valor
  return 0;
}
