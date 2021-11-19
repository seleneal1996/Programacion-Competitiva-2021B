#include <bits/stdc++.h>
class Solution {
  public:
  long fib_bottomup(int n)
  {
    if(n <= 1)
      return n;
    vector<long> F(n+1);
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i <= n; i++)
      F[i] = F[i-1] + F[i-2];
    return F[n];
  }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  cout<<S1.fib_bottomup(40);
  return 0;
}
