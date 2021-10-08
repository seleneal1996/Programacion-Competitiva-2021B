// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>

int solution(vector<int> &A) {
    int n=A.size();
    int indexMin2 =-1;
    double minSum2=  INT_MAX;
    int indexMin3=-1;
    double  minSum3=INT_MAX;

    for (int i=0;i<n-1;i++){
        int va1=A[i];
        int va2=A[i+1];
        int sum2=va1+va2;
        if(sum2<minSum2){
            minSum2=sum2;
            indexMin2=i;
        }
        if(i<n-2){
            va1=A[i];
            va2=A[i+1];
            int va3=A[i+2];
            int sum3=va1+va2+va3;
            if(sum3<minSum3){
                minSum3=sum3;
                indexMin3=i;
            }
        }
    }

    if(indexMin3== -1){
        return indexMin2;
    }
    double avg2 = minSum2 /2;
    double avg3 = minSum3 /3;
    if(avg2<avg3){
        return indexMin2;
    }
    if(avg3<avg2){
        return indexMin3;
    }
    min(indexMin2,indexMin3);
}

int main(){

  vector<int> A{4,2,2,5,1,5,8};
  solution(A);
}