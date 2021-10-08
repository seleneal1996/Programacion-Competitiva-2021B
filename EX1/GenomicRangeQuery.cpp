// you can use includes, for example:
//#include <algorithm>
#include <bits/stdc++.h> 
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    int n=S.length();
    int psize=P.size();
    int stIndex;
    int enIndex;
    int resultado;
    int c[3][n+1];

    int ax=0,cx=0,gx=0;
    for(int i=0;i<n;i++){
        if(S[i]=='A'){
            ax=ax+1;
        }
        else if(S[i]=='C'){
            cx=cx+1;
        }
        else if(S[i]=='G'){
            gx=gx+1;
        }
        c[0][i+1]=ax;
        c[1][i+1]=cx;
        c[2][i+1]=gx;
    }
    std::vector<int>re(psize);
    int rsize= re.size();
    for (int i=0;i<rsize;i++){
        stIndex=P[i];
        enIndex=Q[i]+1;
        resultado=4;
        for(int j=0;j<3;j++)
        {
            if(c[j][stIndex]!=c[j][enIndex])
            {
                resultado=j+1;
                break;
            }
        }
        re[i]=resultado;  
    }
    return re;
}

int main(){
 
}