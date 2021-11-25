//https://open.kattis.com/problems/stack
#include <bits/stdc++.h>
const long long Maxi  = 9e18;
class Solution {
public:
  long long mfind(std::map<char, long long> &id, char c) {
    auto it = id.find(c);
    if (it == id.end()) {
      id.insert({c, id.size()});
      return id.size() - 1;
    } 
    else{
      return it->second;
    }
  }

  void Solve_Storing(long long &v, long long l, long long r) {
    if (l == Maxi || r == Maxi) {
      return;
    }
    else{
      v = fmin(v, l+r);
    }
  }

  void StackConstruction()
  {
    std::string S;
    std::getline(std::cin, S);
    std::map<char, long long> id;
    std::vector<std::vector<long long>> pos(256,std::vector<long long>());
    std::vector<long long> mpos(S.length(), 0);
    for (long long i = 0; i < (long long)S.length(); ++i) {
      long long mid = mfind(id, S[i]);
      mpos[i] = pos[mid].size();
      pos[mid].push_back(i);
    }
    std::vector<std::vector<long long>> dp(S.length(), std::vector<long long>(S.length(), Maxi));

    for (long long r = 0; r < (long long)S.length(); r++)
    {
      for (long long l = r; l >= 0; --l)
      {
        dp[l][r] = 3LL * (r - l + 1LL);
        for (long long m = l; m < r; ++m)
        Solve_Storing(dp[l][r], dp[l][m], dp[m+1][r]);
        if (S[l] == S[r]) 
        { 
          std::vector<long long> &p = pos[mfind(id, S[l])];
          long long li = mpos[l], ri = mpos[r];
          std::vector<long long> tdp(ri - li + 1,Maxi);
          tdp[0] = 3LL;
          for (long long i = li + 1; i <= ri; ++i)
          {
            tdp[i - li] = tdp[0] + 1LL;
            if (p[li] + 1 < p[i])
              tdp[i - li] += dp[p[li]+1][p[i]-1];
            for (long long j = li + 1; j < i; ++j)
            {
              long long tv = tdp[j - li] + 1LL;
              if (p[j] + 1 < p[i])
                tv += dp[p[j]+1][p[i]-1];
              if (tv < tdp[i - li]) tdp[i - li] = tv;
            }
          }
          if (tdp.back() < dp[l][r]) 
            dp[l][r] = tdp.back();
          }
        }
      }
      std::cout << dp[0].back() <<"\n";
  }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int N;
  Solution S1= Solution();
  std::cin >> N >> std::ws;
  while (N--){
    S1.StackConstruction();
  }
  return 0;
  
  //Entrada:
  /*4 
    d
    abba
    rollover ahead
    ogopogo spotted!
  Salida:
  3
  8
  34
  38
  */
}

    
