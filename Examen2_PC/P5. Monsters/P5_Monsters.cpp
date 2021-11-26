//https://cses.fi/problemset/task/1194
#include <bits/stdc++.h>
int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, 1, -1};
char characters[] = {'U', 'D', 'R', 'L'};
int A[1005][1005];
class Monster{
public:
  void Solve(){
    int n,m; 
    std::cin>>n>>m;
    std::vector<std::string> grid(n);
    for (auto &i: grid)
      std::cin>>i;
      std::queue<std::pair<int,int>> q;
      int x,y;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (grid[i][j] == 'M')
            q.push({i,j});
          else if (grid[i][j] == 'A')
            x = i, y = j;
      q.push({x,y});
      A[x][y] = -1;
      while(!q.empty())
      {
        auto [x,y] = q.front();
        q.pop();
        if (grid[x][y] == 'A' && (x == 0 || x == n-1 || y == 0 || y == m-1))
        {
          std::cout<<"YES"<<"\n";
          std::string rpta;
          int d = A[x][y];
          while(d != -1)
          {
            rpta += characters[d];
            x -= fx[d];
            y -= fy[d];
            d = A[x][y];
          }
          reverse(rpta.begin(), rpta.end());
          std::cout<<rpta.size()<<"\n";
          std::cout<<rpta;
          return;
        }
        
        for (int i = 0; i < 4; i++)
        {
          int xx = x + fx[i],yy = y + fy[i];
          if (xx<0 || xx>=n || yy<0 || yy>=m || grid[xx][yy] != '.' ) 
            continue;
          else
          {
            grid[xx][yy] = grid[x][y];
            if (grid[xx][yy] == 'A') 
              A[xx][yy] = i;
            q.push({xx,yy});
          }
        }
      }
      std::cout<<"NO";
  }    
};
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  Monster S1= Monster();
  int t=1;
  for (int i = 1; i <= t; i++)
  {
    S1.Solve();
    std::cout<<'\n';
  }
  return 0;
}