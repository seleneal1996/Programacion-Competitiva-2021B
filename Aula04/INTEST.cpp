//INTEST - Enormous Input Test
/*cabecera*/
#include <iostream>
#include<bits/stdc++.h> //libreria STL
using namespace std;
int main(){
  //Leer entrada y salida de forma rapida
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k,rpta=0;
  cin>>n>>k;

  while(n--){
    int temporal;
    cin>>temporal;
    if(temporal%k==0) rpta++;
  }
  cout<<rpta<<"\n";
}