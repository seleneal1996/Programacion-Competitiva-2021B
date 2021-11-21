//https://leetcode.com/problems/pacific-atlantic-water-flow/
#include <bits/stdc++.h>
class Solution {
public:
    std::vector<int> direction = {0, 1, 0, -1, 0};
    bool outOfBound(int i, int j, int m, int n) {
        return (i<0 || j<0 || i>=m || j>=n);
    }

    void DFS(std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& visited, int i, int j) {
        int m = matrix.size();
        int n =matrix[0].size();
        
        visited[i][j] = true;
        
        for(int k=1;k<direction.size();k++) {
            int row = i + direction[k-1];
            int col = j + direction[k];
            
            if(!outOfBound(row, col, m, n) && !visited[row][col] && matrix[row][col] >= matrix[i][j] )
                DFS(matrix, visited, row, col);
        }
    }
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, false));
        std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, false));
        
        for(int i=0;i<m;i++) {
            if(!pacific[i][0])
                DFS(matrix, pacific, i, 0);
            if(!atlantic[i][n-1])
                DFS(matrix, atlantic, i, n-1);
        }
        
        for(int j=0;j<n;j++) {
            if(!pacific[0][j])
                DFS(matrix, pacific, 0, j);
            if(!atlantic[m-1][j])
                DFS(matrix, atlantic, m-1, j);
        }
        
        std::vector<std::vector<int>> res;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        
        return res;
    }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de entrada 3,7
  std::vector<std::vector<int>>matrix={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
  //salida: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
  S1.pacificAtlantic(matrix);
  return 0;
}
