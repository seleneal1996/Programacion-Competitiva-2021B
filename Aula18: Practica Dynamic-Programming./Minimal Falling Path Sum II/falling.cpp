#include <bits/stdc++.h>
class Solution {
    public:
    int n,m;
    int DP[1001][1001];
    //condicion de parada
    bool valido(int i,int j)
    {
      if(i<0 || i>=n || j<0 || j>=m)
        return false;
      return true;
    }
    int aux(std::vector<std::vector<int>>&grid,int x,int y)
    {
      if(!valido(x,y))
        return 0;
      if(DP[x][y]!=-1)
        return DP[x][y];
      int res=INT_MAX;
      int sum=0;
      for(int i=0;i<m;i++){
        if(i==y)
          continue;
        sum=grid[x][y]+aux(grid,x+1,i);
        res=fmin(res,sum);
      }
      return DP[x][y]=res;
    }
    
    int minFallingPathSum(std::vector<std::vector<int>>& grid){
      memset(DP,-1,sizeof(DP));
      n=grid.size();
      m=grid[0].size();
      if(n==1 && m==1)
        return grid[0][0];
      int res=INT_MAX;
      for(int i=0;i<m;i++){
        res=fmin(res,aux(grid,0,i));
      }
      return res;
    }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de prueba [[1,2,3],[4,5,6],[7,8,9]]
  //salida:13
  std::vector<std::vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
  std::cout<<S1.minFallingPathSum(grid);
  return 0;
}