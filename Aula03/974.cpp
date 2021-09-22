#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> counts(k,0);
        int sum=0;
        for (int x:nums)
        {
          sum+=(x%k+k)%k;
          counts[sum%k]++;
        }
        int result=counts[0];
        for(int c: counts)
          result+=(c*(c-1))/2;
        return result; 
    }
};

int main(){
    vector<int> arreglo_1={4,5,0,-2,-3,1};
    int k=5;
    Solution S1=Solution();
    cout<<S1.subarraysDivByK(arreglo_1,k)<<endl;
}