// you can use includes, for example:
//#include <algorithm>
#include <bits/stdc++.h> 
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	int n = S.length();
    int M = P.size();
	vector<int> result(M, 0);
  vector<int> V(n, 0);
  const int A = 1;
	const int C = 2;
	const int G = 3;
	const int T = 4;
	for (int i=0; i<n; i++)
    {
		switch (S[i]) {
			case 'A': 
                V[i] = A; 
                break;
			case 'C': 
                V[i] = C; 
                break;
			case 'G': 
                V[i] = G; 
                break;
			case 'T': 
                V[i] = T; 
                break;
			default: 
                break;
		}
	}

	for (int m=0; m<M; m++) {
		int l = P[m];
		int r = Q[m];

		int minimum = 4;

		for (int i=l; i<=r; i++) {
			if (V[i] < minimum) {
				minimum = V[i];
			}
			
			if (minimum == 1) {
				result[m] = minimum;
				break;
			}
		}
		result[m] = minimum;
	}

	return result;
}