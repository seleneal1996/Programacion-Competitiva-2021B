#include <iostream>
#include<bits/stdc++.h> //libreria STL
using namespace std;
//Prefix Sum Queries
int main()
{
   //Leer entrada y salida de forma rapida
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k,xsum=0;
  cin>>n>>k;
  int A[n+5];
  int pre[n+5];
  for(int c=1;c<=n;c++){
    cin>>A[c];
    xsum+=A[c];
    pre[c]=xsum;
  }
	while(k--){
    int left,right;
    cin>>left>>right;
    if(left==1){
      cout<<pre[right]<<endl;
    }
    else{
      cout<<pre[right]- pre[left-1]<<endl;
    }
  }
	return 0;
}