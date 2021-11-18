//https://leetcode.com/problems/asteroid-collision/
#include <bits/stdc++.h>
class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> RES;
        for (auto y: asteroids)
        {
            while (!RES.empty() && (RES.top() > 0 && y < 0))
            {
                int x = RES.top(); 
                RES.pop();

                if (x + y == 0) {
                    y = 0;
                    break;
                }
                //el valor absoluto representa su tamaño y el signo representa su dirección
                if (abs(x) > abs(y))
                {
                    y = x;
                }
            }
            
            if (y)
            {
                RES.push(y);
            }
            
        }
        
        std::vector<int> ans(RES.size());
        int n=ans.size();
        for (int i =n-1; i>= 0; i--)
        {
            ans[i] = RES.top(); 
            RES.pop();
        }
        return ans;
    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de entrada [5,10,-5]
  //salida: [5,10]
  std::vector<int>asteroids={5,10,-5};
  S1.asteroidCollision(asteroids);
  return 0;
}