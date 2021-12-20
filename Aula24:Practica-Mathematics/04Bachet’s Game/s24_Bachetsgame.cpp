//https://open.kattis.com/problems/bachetsgame
#include <bits/stdc++.h>
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, m;
  while(std::cin >> n >> m){
    std::vector<int> v;
    std::vector<bool> numbers(n,false);  
    for(int i = 0; i < m; ++i){
      int j;
      std::cin >> j;
      v.push_back(j);
      numbers[j-1] = true;        
     }
     for(auto it = numbers.begin(); it != numbers.end(); ++it){
       if(!(*it)){
         for(auto it2 = v.begin(); it2 != v.end(); ++it2){
           if(it + *it2 < numbers.end()){
             auto pos = *(it + *it2);
             pos = true;
            }
          }
        }
     }
    if(numbers[n-1])
      std::cout << "Stan wins" << endl;
    else
      std::cout << "Ollie wins" << endl;
    return 0;
}
