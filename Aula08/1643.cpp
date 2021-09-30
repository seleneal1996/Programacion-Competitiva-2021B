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
    if(p+valor[i>=valor[i]]){
      p+=valor[i];
    }
    else{
      p=valor[i];
    }
    b=max(b,p);
  }
  cout<<b;
	return 0;
}