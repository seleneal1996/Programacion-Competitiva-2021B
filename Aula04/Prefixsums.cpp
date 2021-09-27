#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void prefixSUm(vector<int>A){
  int n=A.size();
  A[0]=0;
  int previus=A[0];

  for(size_t i=1;i<n;i++){
    A[i]=previus+A[i];
    previus=A[i];
  }
}

int main(){
  vector<int>A={5,6,7,8,9};
  prefixSUm(A);
  for(size_t i=0;i<A.size();i++){
    cout<<A[i]<<" ";
  }
  cout<<endl;
}