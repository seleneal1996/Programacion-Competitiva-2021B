#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sufixSUm(vector<int>A){
  int n=A.size();
  vector<int>result;
  result[n-1]=A[n-1];

  for(int i=n-2;i>=0;i--){
    result[i]=result[i+1]+A[i];
  }
}

int main(){
  vector<int>A={5,6,7,8,9};
  sufixSUm(A);
  for(int i=0;i<A.size();i++){
    cout<<A[i]<<" ";
  }
  cout<<endl;
}