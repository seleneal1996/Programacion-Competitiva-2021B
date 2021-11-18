#include <bits/stdc++.h>
#include <bits/stdc++.h>
class Solution {
public:
int i,j;
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& A)
    {
        if (A[0][0] == 1) return 0;
        int m = A.size(), n = A[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n,0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
            if (A[i][j] == 1 || (i == 0 && j == 0)) continue;
            else dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0);
        return dp[m-1][n-1];
    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //CASO DE PRUEBA [[0,0,0],[0,1,0],[0,0,0]]
  std::vector<std::vector<int>>A={{0,0,0},{0,1,0},{0,0,0}};
  std::cout<<S1.uniquePathsWithObstacles(A);
  return 0;
}