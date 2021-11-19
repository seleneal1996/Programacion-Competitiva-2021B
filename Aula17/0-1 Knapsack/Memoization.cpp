#include <bits/stdc++.h>
class Solution {
    public:
    int knapSackRec(int W, std::vector<int>wt,std::vector<int>val, int i,int** dp){
        if (i < 0)
            return 0;
        if (dp[i][W] != -1)
            return dp[i][W];
        if (wt[i] > W)
        {
            dp[i][W] = knapSackRec(W, wt,val, i - 1,dp);
            return dp[i][W];
        }
        else
        {
            dp[i][W] = fmax(val[i]+knapSackRec(W - wt[i],wt, val,i - 1, dp),knapSackRec(W, wt, val,i - 1, dp));
            return dp[i][W];
        }
    }
        
    int knapSack(int W,std::vector<int>wt,std::vector<int>val, int n){
        int** dp;
        dp = new int*[n];
        for (int i = 0; i < n; i++)
            dp[i] = new int[W + 1];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < W + 1; j++)
                dp[i][j] = -1;
        return knapSackRec(W, wt, val, n - 1, dp);
    }
      
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de prueba
  std::vector<int>val={60, 100,120};
  std::vector<int>wt={10,20,30};
  //salida=220
  int W = 50;
  int n = sizeof(val) / sizeof(val[0]);
  std::cout << S1.knapSack(W, wt, val, n);
  return 0;
}
