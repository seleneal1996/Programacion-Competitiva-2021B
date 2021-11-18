#include <bits/stdc++.h>
int inf = 2 << 28;
class Solution {
public:
  bool inrange(int n, int m, int x, int y) {
      if(x < 0) {
          return false;
      }
      if(y < 0) {
          return false;
      }
      if(x >= n) {
          return false;
      }
      if(y >= m) {
          return false;
      }
      return true;
  }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v;
    v.resize(n, std::vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            std::cin >> c;
            v[i][j] = c - '0';
        }
    }

    std::vector<std::vector<int>> dist;
    dist.resize(n, std::vector<int>(m, inf));

    std::queue<std::pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0,0});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int range = v[x][y];
        if(S1.inrange(n, m, x-range, y)) {
            if(dist[x][y] + 1 < dist[x-range][y]) {
                dist[x-range][y] = dist[x][y] + 1;
                q.push({x-range,y});
            }
        }
        if(S1.inrange(n, m, x+range, y)) {
            if(dist[x][y] + 1 < dist[x+range][y]) {
                dist[x+range][y] = dist[x][y] + 1;
                q.push({x+range,y});
            }
        }
        if(S1.inrange(n, m, x, y-range)) {
            if(dist[x][y] + 1 < dist[x][y-range]) {
                dist[x][y-range] = dist[x][y] + 1;
                q.push({x,y-range});
            }
        }
        if(S1.inrange(n, m, x, y+range)) {
            if(dist[x][y] + 1 < dist[x][y+range]) {
                dist[x][y+range] = dist[x][y] + 1;
                q.push({x,y+range});
            }
        }
    }

    int d = dist[n-1][m-1];
    if(d == inf) {
        std::cout << "-1" << std::endl;
    }
    else {
        std::cout << d << std::endl;
    }
  return 0;
}