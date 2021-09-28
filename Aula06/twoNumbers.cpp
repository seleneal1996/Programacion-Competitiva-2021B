#include <iostream>
#include<bits/stdc++.h> //libreria STL
using namespace std;
class solution{
    public:
    vector<int>twoNUmbers(vector<int>& numbers, int target){
        vector<int> solu;
    	for (int i = 0; i < numbers.size() ; i++)
    	{
    		for(int j =i + 1; j < numbers.size(); j++)
    		{
    		    if(numbers[j]==target-numbers[i]){
    		        solu.push_back(i+1);
    		        solu.push_back(j+1);
    		        if(numbers[i]<numbers[j]){
    		            i++;
    		            j++;
    		        }
    		    }
    		}
    	}
    	return solu; 
      }
};

int main()
{
   //Leer entrada y salida de forma rapida
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  solution S1=solution();
  vector<int> arr = {2,7,11,15 };
  int target = 9;
  S1.twoNUmbers(arr, target);
}
  