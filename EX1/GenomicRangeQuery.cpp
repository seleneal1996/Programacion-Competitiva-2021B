// you can use includes, for example:
//#include <algorithm>
#include <bits/stdc++.h> 
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

std::vector<int> solution(std::string &S,std::vector<int> &P, std::vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    int n=S.length();
    int m=P.size();
    std::vector<int>resultado(m);
    int c[4][n];
    int prefixSum[4][n+1];
    for (int i = 0; i <n; i++) 
    {
        char ch = S.at(i);
        switch(ch)
        {
            case 'A':
                c[0][i]++;
                break;
            case 'C':
                c[1][i]++;
                break;
            case 'G':
                c[2][i]++;
                break;
            case 'T':
                c[3][i]++;
                break;
        }
    }
    for (int k = 1; k < n + 1; k++) 
    {
        for (int j = 0; j < 4; j++)
        {
            prefixSum[j][k] = prefixSum[j][k-1] + c[j][k-1];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x = P[i];
        int y = Q[i];
        for (int j = 0; j < 4; j++)
        {
            if (prefixSum[j][y + 1] - prefixSum[j][x] > 0)
            {
                resultado[i] = j + 1;
                break;
            }
        }
    }
    return resultado;
}