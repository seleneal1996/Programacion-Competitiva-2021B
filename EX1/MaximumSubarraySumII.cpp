#include <bits/stdc++.h>
typedef long long ll;
#define INF 1e18
int main(){
  int n,a,b;
  std::cin>>n>>a>>b;
  std::vector<ll>val(n+1);
  for(int i=1;i<=n;i++)
    std::cin>>val[i];
  for(int i=1;i<=n;i++)
    val[i]+=val[i-1];
  std::set<std::pair<ll,int>> al;
  for(int i=a;i<=b;i++)
    al.insert({val[i],i});
  ll mxSUM= -INF;
  for(int i=1;i<=n-a+1;i++){
    mxSUM=std::max(mxSUM,al.rbegin()->first-val[i-1]);
    al.erase({val[i+a-1],i+a-1});
    if(i+b<=n)
      al.insert({val[i+b],i+b});
  }
  std::cout<<mxSUM;
}