//https://cses.fi/problemset/task/1653
#include <bits/stdc++.h>
class ElevatorRides{
public:
  void Solve(int n,int k)
  {
    int a[n];
    for (int i = 0; i < n; i++)
      std::cin>>a[i];
    std::pair<int, int> dp[1<<n];
    dp[0] = {0, k+1};
    for (int s = 1; s < (1<<n); s++)
    {
      dp[s] = {25, 0};
        for (int i = 0; i < n; i++)
        {
          if (s>>i&1)
          {
            auto [c, w] = dp[s^(1<<i)];
            if (w + a[i] > k)
            {
              c++;
              w = fmin(a[i], w);
            }
            else
                w += a[i];
            dp[s] = min(dp[s], {c, w});
          }
        }
    }
    std::cout<<dp[(1<<n)-1].first;
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  ElevatorRides S1= ElevatorRides();
  int n,k;
  std::cin>>n>>k;
  S1.Solve(n,k);
  return 0;
}