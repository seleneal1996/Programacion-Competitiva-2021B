//https://cses.fi/problemset/task/1683/
#include <bits/stdc++.h>
class P7{
  public:
  int visit[100005];
  std::stack<int>A;
  std::vector<int> part[100005], sequence[100005]/*,root, base_nodes*/;
  //std::vector<std::vector<int>> adj, adj_rev;
  int k=0;
  void first_dfs(int u)
  {
    if (visit[u])
      return;
    visit[u]=1;
    for(auto var:part[u])
      first_dfs(var);
    A.push(u);
 
  }
  void second_dfs(int u)
  {
    if(visit[u])
      return;
    visit[u]=k;
    for(auto var:sequence[u])
      second_dfs(var);
  }
 
  void final_solution(){
    int n,m;
    std::cin>>n>>m;
    for (int i=0; i<m; i++){
      int a,b;
      std::cin>>a>>b;
      part[a].push_back(b);
      sequence[b].push_back(a);
    }
    for (int i=1; i<n+1; i++){
      if(!visit[i])
        first_dfs(i);
    }
    memset(visit,0,sizeof visit);
    while(!A.empty())
    {
        int x = A.top(); 
        A.pop();
        if (!visit[x]) 
        {
          k++;
          second_dfs(x);
        }
    }
    std::cout << k <<"\n";
    for (int i=1; i<n+1; i++)
      std::cout <<visit[i]<<"\n";
  }
 
};
 
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    P7 S1= P7();
    int t=1;
    while(t--){
      S1.final_solution();
    }
    return 0;
}
