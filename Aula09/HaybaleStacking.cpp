/*INPUT FORMAT:

* Line 1: Two space-separated integers, N K.
b
* Lines 2..1+K: Each line contains one of FJ's instructions in the
        form of two space-separated integers A B (1 <= A <= B <= N).*/

#include <iostream>
#include <bits/stdc++.h>
int n,K,a,b;
std:: vector<int> arr_diferencia(n+1);
int solucion[1000000];
int main(){
  std::cin>>n>>K;
  for(int i=0;i<K;i++){
    std::cin>>a>>b;
    a--;
    b--;
    arr_diferencia[a]++;
    arr_diferencia[b+1]--;
  }

  int total=0;
  for(int i=0;i<n;i++){
    total+=arr_diferencia[i];
    solucion[i]= total;
  }
  std::sort(solucion,solucion+n);
  std::cout<<solucion[n+2]<<'\n';
}
