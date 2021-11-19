#include <bits/stdc++.h>
class Solution {
  public:
  int max(int a, int b)
  {
    return (a > b) ? a : b;
  }
  
  int knapSack(int W,std::vector<int>wt,std::vector<int>val,int n)
  {
    int i, w;
    std::vector<std::vector<int>> K(n + 1, std::vector<int>(W + 1));
    for(i = 0; i <= n; i++)
    {
      for(w = 0; w <= W; w++)
      {
        if (i == 0 || w == 0)
          K[i][w] = 0;
        else if (wt[i - 1] <= w)
          K[i][w] = fmax(val[i - 1] + K[i - 1][w - wt[i - 1]],K[i - 1][w]);
        else
          K[i][w] = K[i - 1][w];
      }
    }
    return K[n][W];
  }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de prueba
  std::vector<int>val={60,100,120};
	std::vector<int>wt={10,20,30};
  //salida:220
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	std::cout << S1.knapSack(W, wt, val, n);
  return 0;
}
