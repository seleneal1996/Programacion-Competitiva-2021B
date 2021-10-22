#include <bits/stdc++.h>
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    int ladrillo = 0;
    stack<int> muro;

    for (auto i:H) {
        while (!muro.empty() && i < muro.top()) {
            muro.pop();
        }
        if (muro.empty() || i > muro.top()) {
            muro.push(i);
            ++ladrillo;
        }
    }
    return ladrillo;
}