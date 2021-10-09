#include <bits/stdc++.h>
int main(int argc, char const *argv[])
{
  int n;
  std::cin>>n;
	std::stack<std::pair<int,int>> s;
  std::vector<int>v(n);
  for(int i=0;i<n;i++)
    std::cin>>v[i];
  for(int i=0;i<n;i++){
    while(!s.empty() && s.top().first>=v[i]){
      s.pop();
    }
		if(!s.empty() ){
      std::cout<<s.top().second<<" ";}
		else{
      std::cout<<0<< " ";}
		s.push({v[i],i+1});
	}
}