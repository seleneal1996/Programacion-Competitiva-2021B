#include <bits/stdc++.h>
class Solution {
  public:
  int max(int a, int b){ 
    return (a > b) ? a : b; 
  }
  int knapSack(int W, std::vector<int>wt, std::vector<int>val, int n){
    if (n == 0 || W == 0)
      return 0;
    if (wt[n - 1] > W)
      return knapSack(W, wt, val, n - 1);
    else
      return fmax(val[n - 1]+ knapSack(W - wt[n - 1],wt, val, n - 1), knapSack(W, wt, val, n - 1));
  }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de prueba
  std::vector<int>val ={60, 100, 120};
  std::vector<int>wt={10, 20, 30};
  int W = 50;
  int n = sizeof(val) / sizeof(val[0]);
  //SALIDA:220
  std::cout << S1.knapSack(W, wt, val, n);
  return 0;
}
