//https://open.kattis.com/problems/collatz
#include <bits/stdc++.h>

void collatzConjecture(int numero)
{
  if(numero>0){
    while(numero!=1)
    {
      if(numero%2 == 0)
        numero=numero/2;
      else
        numero=numero*3+1;
      std::cout<<numero<<std::endl;
    }
  }
  else
   return;
}

int main (void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int numero;
  std::cin>>numero;
  collatzConjecture(numero);
}