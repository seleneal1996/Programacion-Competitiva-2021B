#include <bits/stdc++.h>

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        int first=1;
        int second=2;
        for(int i=3;i<=n;i++){
            int third=second+first;
            first=second;
            second=third;
        }
        return second;
    }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de prueba
  /*Por ejemplo si n = 2
  Salida: 2
  Es decir, hay tres formas de subir a la cima.
  1. 1 paso + 1 paso + 1 paso
  2. 1 paso + 2 pasos
  3. 2 pasos + 1 paso*/
  std::cout<<S1.climbStairs(2);
  return 0;
}