#include <bits/stdc++.h>
class Solution {
  public:
  int tilin(int n){
    if (n <= 1) 
      return n;
    std::vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i+=1){
      dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
  }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //CASO DE PRUEBA=4
  //SALIDA=3
  //CASO DE PRUEBA=8
  //SALIDA=21
  sts::cout <<S1.tilin(8) << endl;
  return 0;
}
