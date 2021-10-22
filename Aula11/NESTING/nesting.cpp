// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
int solution(string &S) {
   int cont=0,n=S.size();
   for(int i=0;i<n;i++){
       if(S[i]=='(' || S[i]=='{' || S[i]=='['){
           cont++;
       }
       else if(S[i]==')' || S[i]=='}' || S[i]==']'){
           cont --;
           if(cont<0){
               return 0;
           }
       }
   }
   if(cont!=0){return 0;}
   else{return 1;}
}