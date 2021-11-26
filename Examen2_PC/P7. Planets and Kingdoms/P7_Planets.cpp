//https://cses.fi/problemset/task/1683/
#include <bits/stdc++.h>
class P7{
  public:
  std::vector<bool> visit;
  std::vector<int> part, sequence,root, base_nodes;
  std::vector<std::vector<int>> adj, adj_rev;
  void first_dfs(int u)
  {
    visit[u] = true;
    for(auto v: adj[u])
    {
        if(!visit[v])
          first_dfs(v);
    }
    sequence.push_back(u);
  }

  void second_dfs(int u)
  {
    visit[u] = true;
    part.push_back(u);
    for(auto v: adj_rev[u])
    {
      if(!visit[v])
        second_dfs(v);
    }
  }

};
 
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    P7 S1= P7();
    int n, m;
    std::vector<bool> visit;
    std::vector<int> part, sequence,root, base_nodes;
    std::vector<std::vector<int>> adj, adj_rev;
    std::cin >> n >> m;
    adj.resize(n);
    adj_rev.resize(n);
 
    for(int i = 0; i < m; i++){
        int u, v;
        std::cin >> u >> v;
        u--, 
        v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
 
    visit.assign(n, false);
 
    for(int i = 0; i < n; i++){
        if(!visit[i]){
            S1.first_dfs(i);
        }
    }
 
    root.assign(n, 0);
    visit.assign(n, false);
    reverse(sequence.begin(), sequence.end());
    for(auto u: sequence)
    {
      if(!visit[u])
      {
        S1.second_dfs(u);
        int seed = part.front();
        for (auto u : part) root[u] = seed;
        base_nodes.push_back(seed);
        part.clear();
      }
    }
 
    int cnt = 0;
    std::map<int, int> key;
    for(auto e: base_nodes){
        key[e] = ++cnt;
    }
 
    std::cout << cnt << '\n';
    for(int i = 0; i < n; i++){
        std::cout << key[root[i]] << ' ';
    }
    return 0;
}
