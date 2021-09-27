#include <bits/stdc++.h>
using namespace std;

int findTriplet(vector<int>& arr, int x)
{
	int Sum = INT_MAX;

	for (int i = 0; i < arr.size() ; i++)
	{
		for(int j =i + 1; j < arr.size(); j++)
		{
			for(int k =j + 1; k < arr.size(); k++)
			{
				if(abs(x - Sum) > abs(x - (arr[i] + arr[j] + arr[k])))
					Sum = (arr[i] + arr[j] + arr[k]);
			}
		}
	}
	return Sum;
}

// Driver code
int main()
{
	vector<int> arr = { -1, 2, 1, -4 };
	int x = 1;
	cout << findTriplet(arr, x);

	return 0;
}
