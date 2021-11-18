#include <bits/stdc++.h>
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n=cost.size() ;
        for (int i =n-3; ~i; i--)
            cost[i] += fmin(cost[i+1], cost[i+2]);
        return fmin(cost[0], cost[1]);
    }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de prueba [10,15,20]
  //salida:15
  std::vector<int>cost={10,15,20};
  std::cout<<S1.minCostClimbingStairs(cost);
  return 0;
}