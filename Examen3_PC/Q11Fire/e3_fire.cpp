//https://open.kattis.com/problems/fire2

#include <bits/stdc++.h>
class Fire{
  int n, m;
  public:
  
  bool inrangeguys(int x, int y) {
      return x >= 0 && x <= n+1 && y >= 0 && y <= m+1;
  }
  
  bool inrangefire(int x, int y) {
      return x >= 1 && x <= n && y >= 1 && y <= m;
  }

  void bfs(std::vector<std::vector<char>>& v, std::queue<std::pair<int,int>>& oldq, std::queue<std::pair<int,int>>& newq, bool fire)
  {
      std::vector<std::pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};
      while(!oldq.empty()) {
          int currx = oldq.front().first;
          int curry = oldq.front().second;
          oldq.pop();
          for(auto i : movement) {
              int nextx = currx + i.first;
              int nexty = curry + i.second;
              if(fire) {
                  if(inrangefire(nextx,nexty)) {
                      if(v[nextx][nexty] == '.' || v[nextx][nexty] == '@') {
                          v[nextx][nexty] = '*';
                          newq.push({nextx,nexty});
                      }
                  }
              }
              else {
                  if(inrangeguys(nextx,nexty)) {
                      if(v[nextx][nexty] == '.') {
                          v[nextx][nexty] = '@';
                          newq.push({nextx,nexty});
                      }
                  }
              }
          }
      }
  }

  void checkguys(std::vector<std::vector<char>>& v, std::queue<std::pair<int,int>>& guys) {
      std::queue<std::pair<int,int>> newguys;
      while(!guys.empty()) {
          std::pair<int,int> i = guys.front();
          guys.pop();
          if(v[i.first][i.second] != '*') {
              newguys.push(i);
          }
      }
      guys = newguys;
  }
  
  void solve() {
      std::cin >> m >> n;

      std::vector<std::vector<char>> v;
      v.resize(n+2, std::vector<char>(m+2, '.'));

      for(int i = 1; i <= n; i++) {
          for(int j = 1; j <= m; j++) {
              std::cin >> v[i][j];
          }
      }

      std::queue<std::pair<int,int>> guys;
      std::queue<std::pair<int,int>> fire;

      for(int i = 0; i < n+2; i++) {
          for(int j = 0; j < m+2; j++) {
              if(v[i][j] == '@') {
                  guys.push({i,j});
              }
              if(v[i][j] == '*') {
                  fire.push({i,j});
              }
          }
      }

      int time = 0;
      bool works = false;
      while(!fire.empty() || !guys.empty()) {
          std::queue<std::pair<int,int>> newguys;
          std::queue<std::pair<int,int>> newfire;

          bfs(v, guys, newguys, false);
          bfs(v, fire, newfire, true);

          for(int i = 0; i < n+2; i++) {
              if(v[i][0] == '@' || v[i][m+1] == '@') works = true;
          }
          for(int j = 0; j < m+2; j++) {
              if(v[0][j] == '@' || v[n+1][j] == '@') works = true;
          }

          checkguys(v, newguys);

          guys = newguys;
          fire = newfire;
          time++;

          if(works) break;
      }

      if(works) {
          std::cout << time << std::endl;
      }
      else {
          std::cout << "IMPOSSIBLE" << std::endl;
      }
  }

};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Fire F1= Fire();
  int cases;
  std::cin >> cases;
  while(cases--) {
    F1.solve();
  }
  return 0;
}