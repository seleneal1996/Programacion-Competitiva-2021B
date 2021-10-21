// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
int solution(string &S) {
    vector<int> A;
    int n=S.size(),cont;
    if(S.empty()){
        return 1;
    }
    for(int i=0;i<n;i++){
        if(S[i]=='['){
            cont=+1;
        }
        if(S[i]==']'){
            cont=-1;
        }
        if(S[i]=='('){
            cont=+2;
        }
        if(S[i]==')'){
            cont=-2;
        }
        if(S[i]=='{'){
            cont=+3;
        }
        if(S[i]=='}'){
            cont=-3;
        }
        if((i==0 && cont<0) || (cont<0 && cont!=-A.back())){return 0;}
        else if(cont<0){A.pop_back();}
        else{A.push_back(cont);}
    }
    if(A.empty()){return 1;}
    else {return 0;}
}