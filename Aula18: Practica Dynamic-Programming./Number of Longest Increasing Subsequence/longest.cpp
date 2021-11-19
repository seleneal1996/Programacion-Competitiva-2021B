#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
       int n = nums.size();
       int L[n];
       L[0] = 1;
       for(int i=1;i<n;i++){
           L[i] = 1;
           for(int j=0;j<i;j++){
               if(nums[j]<nums[i])
                L[i] = fmax(L[i],L[j]+1);
           }
       }
       
       int maxL = L[0];
       for(int i=1;i<n;i++)
        maxL = fmax(L[i],maxL);
       return maxL;
    }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //CASO DE PRUEBA [10,9,2,5,3,7,101,18]
  //SALIDA: 4
  std::vector<int>nums={10,9,2,5,3,7,101,18};
  std:: cout<<S1.lengthOfLIS(nums);
  return 0;
}