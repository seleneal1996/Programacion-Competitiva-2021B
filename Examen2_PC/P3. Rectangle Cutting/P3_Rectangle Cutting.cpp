  //https://cses.fi/problemset/task/1744
#include <bits/stdc++.h>
class RectangleCutting{
public:
  int Solve(int a,int b){
    int dp[a+1][b+1];
    for(int h=1;h<=a;h++)
    {
      for(int w=1;w<=b;w++)
      {
        if(h==w)
          dp[h][w]=0;
        else
        {
          int ans=1e8;
          for(int i=1;i<w;i++)
            ans=fmin(ans,1+dp[h][w-i]+dp[h][i]);
          for(int i=1;i<h;i++)
            ans=fmin(ans,1+dp[h-i][w]+dp[i][w]);
          dp[h][w]=ans;
        }
      }
    }
    return dp[a][b];
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  RectangleCutting S1=RectangleCutting();
  long long t;
  t=1;
  while(t--){
    int a,b;
    std::cin>>a>>b;
    std::cout<<S1.Solve(a,b);
  }
  return 0;
}