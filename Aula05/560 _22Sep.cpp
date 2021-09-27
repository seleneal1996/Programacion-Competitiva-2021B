//560. Subarray Sum Equals K
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    int count=0;
    for (int i=0; i<n;i++){
      for(int j=i+1;j<=n;j++){
          int sum=0;
          for(int ki=i;ki<j;ki++){
              sum+=nums[ki];
          if(sum==k)
              count++;
          
          }
      }
    return count;
    }
   
    }
};
int main(){
    vector<int> arreglo_1={1,1,1};
    Solution S1=Solution();
    cout<<S1.subarraySum(arreglo_1,2)<<endl;
}