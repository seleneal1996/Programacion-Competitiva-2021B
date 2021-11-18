//https://leetcode.com/problems/number-of-enclaves/
#include <bits/stdc++.h>
class Solution {
public:
    
    std::pair<int, int> direcciones[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isValid(int x, int y, int row, int col){
      if(x>=0 && x<row && y>=0 && y<col) 
        return true;
      return false;
    }
    
    void DFS(int x, int y, int row, int col, std::vector<std::vector<int>>& A){
      A[x][y] = 0;
      for(int i=0;i<4;i++)
      {
        int newx = x + direcciones[i].first;
        int newy = y + direcciones[i].second;
        if(isValid(newx, newy, row, col) && A[newx][newy]==1)
          DFS(newx, newy, row, col, A);
      }
    }
    
    int numEnclaves(std::vector<std::vector<int>>& A) {
      int row = A.size();
      int col = A[0].size();
      for(int i=0;i<col;i++)
      {
        if(A[0][i] == 1)
          DFS(0, i, row, col, A);
          if(A[row-1][i] == 1)
            DFS(row-1, i, row, col, A);
      }
      
      for(int i=0;i<row;i++){
        if(A[i][0] == 1)
          DFS(i,0, row, col, A);
        if(A[i][col-1] == 1)
          DFS(i, col-1, row, col, A);
      }
        
      int ans = 0;
      for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          if(A[i][j] == 1)ans++;
        }
      }
      return ans;
    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de prueba: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
  //salida:3
  std::vector<std::vector<int>>A={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
  std::cout<<S1.numEnclaves(A);
}