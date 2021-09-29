#include <iostream>
#include<bits/stdc++.h> //libreria STL
using namespace std;

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int windowSum = 0, minLength = numeric_limits<int>::max();
    int VentanaInicio = 0;
    for (int Ventanafin = 0; Ventanafin < arr.size(); Ventanafin++) {
      windowSum += arr[Ventanafin];  
        minLength = min(minLength, Ventanafin - VentanaInicio + 1);
        windowSum -= arr[VentanaInicio]; 
        VentanaInicio++;                  
      }
    }

    return minLength == numeric_limits<int>::max() ? 0 : minLength;
  }
};

int main()
{
   //Leer entrada y salida de forma rapida
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2,3,4,1,5});
  cout << result << endl;
	return 0;
}
