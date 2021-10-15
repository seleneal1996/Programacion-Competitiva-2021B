// you can use includes, for example:
//#include <algorithm>
#include <bits/stdc++.h> 
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

std::vector<int> solution(std::string &S,std::vector<int> &P, std::vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    int n=S.length();
    int m=P.size();
    //int psize=P.size();
    int stIndex;
    int enIndex;
    int subx;
    int c[n][4];

    //int ax=1,cx=1,gx=1,tx=1;
    for(int i=0;i<n;i++){
        S.at(i);
        if(S.at(i)=='A'){
            c[i][0]=1;
        }
        else if(S.at(i)=='C'){
            c[i][1]=1;
        }
        else if(S.at(i)=='G'){
            c[i][2]=1;
        }
        else if(S.at(i)=='T'){
            c[i][3]=1;
        }
    }
    std::vector<int>re(m);
    //int rsize= re.size();
    for (int i=1;i<n;i++){
        //stIndex=P[i];
        //enIndex=Q[i]+1;
        //int resultado=4;
        for(int j=0;j<4;j++)
        {
            c[i][j]+=c[i-1][j];
            /*if(c[j][stIndex]!=c[j][enIndex])
            {
                resultado=j+1;
                break;
            }*/
        }
        //re[i]=resultado;  
    }
    for(int i=0;i<m;i++){
        stIndex=P[i];
        enIndex=Q[i];
        for(int j=0;j<4;j++){
            subx=0;
            if((stIndex-1)>=0){
                subx=c[stIndex-1][j];
            }
            if(c[enIndex][j]-subx>0){
                re[i]=j+1;
                break;
            }
        }
    }
    return re;
}