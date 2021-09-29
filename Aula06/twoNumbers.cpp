#include <iostream>
#include<bits/stdc++.h> //libreria STL
using namespace std;
class solution
{
    public:
    vector<int>findtwoNUmbers(vector<int>& numbers, int target)
    {
      int i=0,j=numbers.size()-1, tmp1=0,tmp2=0,k=0;
      vector<int> solu(numbers.size());
      for(int l=0;l<numbers.size();l++){
        solu[k++]=numbers[l];
      }
      sort(numbers.begin(), numbers.end());
      while(i<j)
      {
        if(solu[i]+solu[j]==target)
        {
          tmp1=solu[i];
          tmp2=solu[j];
        }
        if(solu[i]+solu[j]<target)
          i++;
        else{
          j--;
        }
      }
      k=0;
      vector<int> res(2);;
      for(int l=0;l<numbers.size();l++){
          if(tmp1==numbers[l] || tmp2==numbers[l]){
              res[k++]=l;
          }
      }
      return res;
    } 
};

int main()
{
   //Leer entrada y salida de forma rapida
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> nums={2,7,11,15};
  int target=9;
  solution S1=solution();
  S1.findtwoNUmbers(nums,target);
}
  