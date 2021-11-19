#include <bits/stdc++.h>
class Solution {
  public:
  long fib_memo(int n, vector<long>& memo)
  {
    if(memo[n]) return memo[n];
    long result{};
    if(n <= 1)
      result = n;
    else
      result = fib(n-1, memo) + fib(n-2, memo);
    memo[n] = result;
    return result;
  }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //CASO DE PRUEBA:1O
  //SALIDA:55
  std::cout<<S1.fib_memo(10);
  return 0;
}
