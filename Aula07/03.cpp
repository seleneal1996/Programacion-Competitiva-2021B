#include <iostream>
#include<bits/stdc++.h> //libreria STL
using namespace std;

class Solution {
public:
    int sumaContinua(vector<int>& nums, int k) {
        int maxi = nums[0];
        int c_max = nums[0];
        for (int i = 1; i < nums.size(); i++){
          c_max = max(nums[i], c_max+nums[i]);
          maxi = max(maxi, c_max);

          int sum=0;
          for(int k=i;k<nums.size();k++){
              sum+=nums[k];
        }
        return maxi;

    }
};
 
int main()
{
   //Leer entrada y salida de forma rapida
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	vector<int> a= {2,3,4,1,5};
  Solution S1;
  S1.sumaContinua(a, 10);
	return 0;
}
