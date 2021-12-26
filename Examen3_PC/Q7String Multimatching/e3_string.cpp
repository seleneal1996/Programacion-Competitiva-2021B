//https://open.kattis.com/problems/std::stringmultimatching
#include <bits/stdc++.h>
const int mxN=1e5, mxM=2e5;
int n;
std::string s;
int var= s.size();

struct stringAutoMatching
{
    int sl[mxN+1], ol[mxN+1], sz=1, c[mxN+1][256], d[mxN+1][256];
    std::vector<int> oc[mxN];
    std::vector<std::array<int, 2>> no[mxN+1];
    
    void add(std::string s, int i)
    {
        int u=0;
        for(char a : s) {
            if(!c[u][a])
                c[u][a]=sz++;
            u=c[u][a];
        }
        ol[u]=u;
        no[u].push_back({i,var});
    }
    void ac()
    {
        for(std::queue<int> q({0}); q.size(); q.pop()) {
            int u=q.front();
            if(!ol[u])
                ol[u]=ol[sl[u]];
            for(int a=0; a<256; ++a) {
                int v=c[u][a], w=sl[u];
                if(v) {
                    sl[v]=d[w][a];
                    q.push(v);
                }
                d[u][a]=v?v:d[w][a];
            }
        }
    }
    int feed(int u, char a, int i)
    {
        u=d[u][a];
        for(int v=ol[u]; v; v=ol[sl[v]])
            for(std::array<int, 2> b : no[v])
                oc[b[0]].push_back(i-b[1]+1);
        return u;
    }
} ac;

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  while(std::cin >> n) {
    getline(std::cin, s);
    for(int i=0; i<n; ++i) {
      getline(std::cin, s);
      ac.add(s, i);
    }
    
    ac.ac();
    getline(std::cin, s);
    int u=0;
    for(int i=0; i<s.size(); ++i)
    u=ac.feed(u, s[i], i);
    for(int i=0; i<n; ++i) {
      for(int j : ac.oc[i])
        std::cout << j << " ";
        std::cout << "\n";
        ac.oc[i].clear();
      }
      memset(ac.sl, 0, 4*ac.sz);
      memset(ac.ol, 0, 4*ac.sz);
      memset(ac.c, 0, sizeof(ac.c[0])*ac.sz);
      memset(ac.d, 0, sizeof(ac.d[0]));
      for(int i=0; i<ac.sz; ++i)
        ac.no[i].clear();
      ac.sz=1;
    }
}
