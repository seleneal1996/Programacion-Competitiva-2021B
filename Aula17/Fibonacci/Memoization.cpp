#include <bits/stdc++.h>
class Solution {
  public:
  long fib(int n, vector<long>& memo)
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
  
  long fib_memoization(int n)
  {
    vector<long> memo(n+1);
    return fib(n, memo);
  }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //CASO DE PRUEBA:1O
  //SALIDA:55
  std::cout<<S1.fib_memoization(10);
  return 0;
}
