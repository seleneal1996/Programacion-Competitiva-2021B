//https://open.kattis.com/problems/narrowartgallery
#include <bits/stdc++.h>
long long inf = (long long)1 << 60;
struct condicion {
    long long necesaria;
    long long lugar;
    bool prevl;
    bool prevr;
};

bool operator<(const condicion& s1, const condicion& s2) {
    return std::tie(s1.necesaria, s1.lugar, s1.prevl, s1.prevr) <
           std::tie(s2.necesaria, s2.lugar, s2.prevl, s2.prevr);
}

bool operator==(const condicion& s1, const condicion& s2) {
    return std::tie(s1.necesaria, s1.lugar, s1.prevl, s1.prevr) ==
           std::tie(s2.necesaria, s2.lugar, s2.prevl, s2.prevr);
}

std::map<condicion, long long> memo;

long long solve(std::vector<std::pair<long long,long long>>& v, int n, condicion s) {
    if(memo.count(s) > 0) {
        return memo[s];
    }

    long long necesaria = s.necesaria;
    long long lugar = s.lugar;
    bool prevl = s.prevl;
    bool prevr = s.prevr;

    if(lugar >= n) {
        if(necesaria <= 0) {
            return 0;
        }
        else {
            return -inf;
        }
    }

    long long lval = v[lugar].first;
    long long rval = v[lugar].second;

    long long ans = -inf;

    if(necesaria <= 0) {
        condicion next = {necesaria, lugar+1, true, true};
        ans = lval + rval + solve(v, n, next);
        memo[s] = ans;
        return ans;
    }

    if(prevl) {
        condicion next = {necesaria-1, lugar+1, true, false};
        ans = fmax(ans, lval + solve(v, n, next));
    }

    if(prevr) {
        condicion next = {necesaria-1, lugar+1, false, true};
        ans = fmax(ans, rval + solve(v, n, next));
    }

    condicion next = {necesaria, lugar+1, true, true};
    ans = fmax(ans, lval + rval + solve(v, n, next));

    memo[s] = ans;
    return ans;
}

void hacer_caso(int n, int m) {
  std::vector<std::pair<long long,long long>> v(n);
  for(auto& i : v) {
    std::cin >> i.first >> i.second;
  }

  memo.clear();
  condicion s = {m, 0, true, true};
  long long ans = solve(v, n, s);
  std::cout << ans << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, m;
  while(std::cin >> n && std::cin >> m) {
    if(n == 0 && m == 0) {
      break;
    }
    hacer_caso(n, m);
  }
}    