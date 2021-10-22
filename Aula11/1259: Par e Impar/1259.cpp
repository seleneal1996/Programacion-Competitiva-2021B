#include <bits/stdc++.h>
#include <iostream>
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::cin>>n;
  int V1[n],V2[n];
  int var1=0,var2=0,x;
  for(int i=0;i<n;i++){
    std::cin>>x;
    if(x%2==0){
      V2[var2++]=x;
    }else{
      V1[var1++]=x;
    }
  }
  std::sort(V2,V2+var2);
  std::sort(V1,V1+var1,std::greater<int>());
  for(int i=0;i<var2;i++)
    std::cout<<V2[i]<<std::endl;
  for(int i=0;i<var1;i++)
    std::cout<<V1[i]<<std::endl;
  return 0;
}