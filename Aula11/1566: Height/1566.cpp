#include <bits/stdc++.h>
#define MAX  3000000
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int array[MAX]={0};
  int tc,n;
  std::cin>>tc;
  while(tc--){
    std::cin>>n;
    for(int j=0;j<n;j++){
      std::cin>>array[j];
    }
    std::sort(array,array+n);
    for(int i=0;i<n-1;i++)
      std::cout<<array[i];
    std::cout<<array[n-1];
    std::cout<<"\n";
  }
  return 0;
}