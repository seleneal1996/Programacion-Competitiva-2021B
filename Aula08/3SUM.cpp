#include <iostream>
#include<bits/stdc++.h> //libreria STL
using namespace std;


class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
      vector<vector<int> > xrpta;
      if(nums.size()<3)
      {
        return xrpta;
      }
        sort(nums.begin(), nums.end());
        int i=0, n=nums.size();
        while(i<(n-2))
        {
            int j=i+1, k=n-1, target=(-1)*nums[i];
            while(j<k)
            {
                int s=nums[j]+nums[k];
                if(s<target)
                {
                  j=j+1;
                }
                else if(s>target)
                {
                  k=k-1;
                }
                else{
                    vector<int> temporal;
                    temporal.push_back(nums[i]);
                    temporal.push_back(nums[j]);
                    temporal.push_back(nums[k]);
                    xrpta.push_back(temporal);
					
                    j=j+1;
                    k=k-1;
        
                    while(j<k && nums[j]==nums[j-1])
                    {
                      j++;
                    }
                    while(k>j && nums[k]==nums[k+1])
                    {
                      k--;
                    }
                }
            }
            i=i+1;
            while(i<nums.size() && nums[i]==nums[i-1])i++;
        }
        return xrpta;
    }
};
int main()
{
   //Leer entrada y salida de forma rapida
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> arreglo_1={1,0,1,2,-1,-4};
  Solution S1=Solution();
  S1.threeSum(arreglo_1);
	return 0;
}