#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ve tor<int> counts(k,0);
        int sum=0;
        for (int x:A)
        {
          sum+=(x%k+k)%k;
          counts[sum%k]++;
        }
        int result=counts[0];
        for(int c:counts[0])
          result+=(c*(c-1))/2;
        return result; 
    }
};