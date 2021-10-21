#include <iostream>
#include <bits/stdc++.h>
int main(){
  std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(0);
  int n;
  int cont = 0;
  std::cin >> n;
  std::vector<int> socks(2*n), tmp;
  for(auto& i : socks){
    std::cin >> i;
  }
  while(!socks.empty()){
    cont++;
    if(tmp.empty()){
      tmp.push_back(socks.back());
      socks.pop_back();
      continue;
    }
    if(socks.back() == tmp.back()){
      socks.pop_back();
      tmp.pop_back();
      continue;
    }
    tmp.push_back(socks.back());
    socks.pop_back();
  }
  if(tmp.empty()){
    std::cout << cont<<'\n';
  }else {
    std::cout << "impossible"<<'\n';
  }
  return 0;
}
