// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
int solution(vector<int> &A, vector<int> &B) {
    vector<int> Pescera;
    int cont=0,n=B .size(),m=A.size();
    for(int i=0;i<n;i++){
        if(B[i]==1){
            Pescera.push_back(A[i]); 
        }
        else{
            while(!Pescera.empty()){
                if(Pescera.back()>A[i]){
                    cont++;
                    break;
                }
                else if(Pescera.back()<A[i]){
                    Pescera.pop_back();
                    cont++;
                }
            }
        }
    }
    return m-cont;
}