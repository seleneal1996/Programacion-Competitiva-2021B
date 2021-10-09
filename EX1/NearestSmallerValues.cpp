#include <bits/stdc++.h>
class nearest
{
public:
  void nearest_(std::stack<std::pair<int,int>> s)
  {
    int n;
    std::vector<int>v(n);
    for(int i=0;i<n;i++)
    {
      while(s.size()>0 && s.top().first>=v[i])
      {
        s.pop();
      }if(s.size()>0){
        std::cout<<s.top().second<<" ";
      }else{
        std::cout<<0<< " ";
      }
      s.push({v[i],i+1});
    }
  }
  
};
int main(int argc, char const *argv[])
{
  int n;
  std::cin>>n;
  std::stack<int,int>v_input={3,1,4,2,5};
  nearest n1= nearest();
  std::stack<int,int>v_output=n1.nearest_(v_input);
}