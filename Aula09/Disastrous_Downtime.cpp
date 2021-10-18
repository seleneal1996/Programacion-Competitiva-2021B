#include <iostream>
#include <bits/stdc++.h>
  /*The first line contains two integers 1≤n≤100 000 and 1≤k≤100 000, the number of upcoming requests and the maximum number of requests per second that each server can handle.
  /*Then follow n lines with one integer 0≤ti≤100 000 each, specifying that the ith request will happen ti milliseconds from the exact moment you notified your customers. The timestamps are sorted in chronological order. It is possible that several requests come in at the same time.*/
int main(){
   //Leer entrada y salida de forma rapida
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n,k,tempo,proc=0,bts=0,ans;
  std::cin>>n>>k;
  std::map<int,int> A;
  for(int i=0;i<n;i++){
    std::cin>>tempo;
    A[tempo]++;
    A[tempo+1000]--;
  }
  for (auto ix:A){
    proc+=ix.second;
    bts=std::max(bts,proc);
  }
  ans=(bts+proc-1)/proc;
  std::cout<<ans<<'\n';
}