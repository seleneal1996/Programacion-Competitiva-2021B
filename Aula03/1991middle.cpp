#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
  int findMiddleIndex(vector<int>& arr){
    int n=arr.size();
    int ans=-1;
    for(int i=0;i<n;i++){
      int l=0,r=0;
      for(int j=i-1;j>=0;j--)
        l+=arr[j];
      for (int j=i+1;j<n;j++)
        r+=arr[j];
      if(l==r)
        return i;

    }
    return -1;

  }
};

int main(){
    vector<int> arreglo_1={2,3,-1,8,4};
    Solution S1=Solution();
    cout<<S1.findMiddleIndex(arreglo_1)<<endl;
}