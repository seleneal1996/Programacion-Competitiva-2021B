#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
typedef long long ll;
ll B[MAX];
int main()
{
    int l, T, ini;
    ll sumx, min_sumx, state, mx_state;
    ll P, M;
    scanf("%d", &T);
    while(T--)
    {
        std::cin>>P>>M;
        for(int i=1; i<=P; i++){
          std::cin>>B[i];
        } 
        min_sumx = 50000;
        ini = 1;
        mx_state = 0;
        state=0;
        sumx = 0;
        for(int i=1; i<=P; i++)
        {
          sumx = sumx + B[i];
          state = state + 1;
          if((mx_state < state && sumx <=M) || (mx_state == state && min_sumx > sumx))
          {
            mx_state = state;
            min_sumx = sumx;
          }
          while(sumx>M)
          {
            sumx = sumx - B[ini];
            state--;
            ini++;
          }
          if ((mx_state < state && sumx <=M) || (mx_state == state && min_sumx > sumx))
          {
            mx_state = state;
            min_sumx = sumx;
          }
     }
    std::cout<<min_sumx<<mx_state<<endl;
    }
}