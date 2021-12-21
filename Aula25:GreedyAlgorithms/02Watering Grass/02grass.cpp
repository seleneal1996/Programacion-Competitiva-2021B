//https://open.kattis.com/problems/grass
#include <bits/stdc++.h>
typedef pair<double, double> dd;
double N, L, W, x, r;
void p_DistanceX(std::vector<dd> &lis, double &L){
    double c = 0, i = 0, aux = 0;
    double n = lis.size();

    while(true){
        double tmp = -1;
        while(i < n &&  lis[i].first <= aux){
            tmp = max(tmp, lis[i].second);
            i++;
        }
        if(tmp == -1){
            std::cout << -1 << std::endl;
            return;
        }
        c++;
        aux = tmp;
        if (aux >= L){
            std::cout << c << endl;
            return;
        }
    }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  while(std::cin >> N >> L >> W){
    std::vector<dd> lis;
    while(N--){
      std::cin >> x >> r;
      if (2*r > W){
        double d = sqrt(pow(r, 2) - pow(W/2, 2));
        lis.push_back(dd(x - d, x + d));
       }
     }
     sort(lis.begin(), lis.end());
     p_DistanceX(lis, L);
    }
   return 0;
}
