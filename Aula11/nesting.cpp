// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++. h>
int solution(string &s) {
    stack<char>A;
    int n=s.size();
    for (int i=0;i<n;i++){ 
        if(A.top()=='{' || s[i]=='[' || s[i]=='('){
            A.push(s[i]);
        }
        else{
            if(A.empty()){
                return 0;
            }
        }
    }
    return 1;
}
