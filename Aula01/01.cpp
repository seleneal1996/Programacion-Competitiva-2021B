#include <iostream>
#include <algorithm>  
#include <bits/stdc++.h>

void MultiMAX(int a[], int n)
{
	int dp[n][2];
	memset(dp, 0, sizeof(dp));
	
	dp[0][0] = a[0] * a[1];
	dp[0][1] = a[0] * a[1];
	
	for (int i = 1; i <= n - 2; i++) {
		dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1]) + a[i + 1];
		dp[i][1] = dp[i - 1][0] - a[i] + a[i] * a[i + 1];	
	}

	std::cout << fmax(dp[n - 2][0], dp[n - 2][1]);
}

int main()

{
	int arr[] = {1,2,3};
	MultiMAX(arr,3);
}