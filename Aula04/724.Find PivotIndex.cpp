#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int findPivotIndex(vector<int>& arr){
    int n=arr.size();
    int total_sum=0;
    for(int i=0;i<n;i++){
      total_sum+= arr[i];
    }
    int left_sum=0;
    for(int i=0;i<n;i++){
      if(i!=0){
        left_sum+=arr[i-1];
      }
      if(total_sum-left_sum-arr[i]==left_sum){
        return i;
      }
    }
    return -1;

  }
};

int main(){
    vector<int> arreglo_1={1,7,3,6,5,6};
    Solution S1=Solution();
    cout<<S1.findPivotIndex(arreglo_1)<<endl;
}