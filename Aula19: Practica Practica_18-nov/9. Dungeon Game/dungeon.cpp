//https://leetcode.com/problems/dungeon-game/
#include <bits/stdc++.h>
class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        std::vector<std::vector<int>> dp (m+1,std::vector<int>(n+1,INT_MAX));
        dp[m][n-1] = dp[m-1][n] = 1;
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                dp[i][j] = fmax(1,fmin(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
            }
        }
        return dp[0][0];
        
    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de entrada [[-2,-3,3],[-5,-10,1],[10,30,-5]]
  //salida: 7
  std::vector<std::vector<int>> dungeon= {{-2,-3,3},{-5,-10,1},{10,30,-5}};
  std::cout<<S1.calculateMinimumHP(dungeon);
  return 0;
}
