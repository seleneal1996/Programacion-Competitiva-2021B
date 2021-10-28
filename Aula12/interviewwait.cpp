#include <bits/stdc++.h>
void solution(std::vector<int>A){
  std::deque<int> A1;
  int res=0;
  for(int i=0;i<=A.size();i++){
    A1.push_back(i);
  }
  while(A1.front()!=-1&&A1.back()!=-1){
    if(A1.front()<A1.back()){
      res+=A1.front();
    }else{
      res+=A1.back();
      A.pop_back();
    }
  }
  std::cout<<res<<std::endl;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::vector<int> a={4,-1,5,2,3};
  solution(a);
  return 0;
}