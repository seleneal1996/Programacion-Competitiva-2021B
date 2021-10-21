#include <iostream>
#include <bits/stdc++.h>
class Solution {
public:
    int minAddToMakeValid(std::string s) {
        std::stack<char>A;
        int n=s.size();
        for (int i=0;i<n;i++){
            if(!A.empty() && A.top()=='(' && s[i]==')')
            {
                A.pop();
            }
            else{
                A.push(s[i]);
            }
        }
        return A.size();
    }
};