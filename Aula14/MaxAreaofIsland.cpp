#include <bits/stdc++.h>
//busqueda en profundidad
class Solution {
public:
	int dfs(int x, int y, std::vector<std::vector<int>>& tmp){
    int m=tmp.size();
    int n=tmp[0].size();
		if( x<0 || (x>=m) || (y<0) || (y>=n))
    {
			return 0;
		}   
		if(tmp[x][y] == 1){
			tmp[x][y] = 0;
			return (1 + (dfs(x+1,y,tmp) + dfs(x-1,y,tmp) + dfs(x,y+1,tmp) + dfs(x,y-1,tmp))); 
		}
		return 0;
	}

	int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
  {
		int m=grid.size();
    int n=grid[0].size();
    int ans = 0;
		for(int i=0; i<m; i++)
    {
			for(int j=0; j<n; j++)
      {
				 if(grid[i][j]==1)
					ans = std::max(ans, dfs(i, j, grid));
			}
		}
		return ans;
	}
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  /*entrada*/
  /*[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]*/
}
