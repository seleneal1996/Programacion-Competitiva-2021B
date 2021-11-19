#include <bits/stdc++.h>
class Solution {
  public:
  long fib_recursivo(int n)
  {
    if(n <= 1)
      return n;
    return fib(n-1) + fib(n-2);
  }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //CASO DE PRUEBA: 2
  //SALIDA:1
  std::cout<<S1.fib_recursivo(2);
  return 0;
}
