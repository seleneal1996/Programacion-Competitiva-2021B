#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	
	ll B[INT_MAX]; 
  ll P,M;
  int T;
	std::cin>>T;
	do{
		std::cin>>P>>M;
		for(int i=1;i<=P;i++){
			std::cin>>B[i];
		}
		
		ll Pminsumx=50000;
		int ini=1;
		ll mx_st=0;
		ll state=0;
		ll sumx=0;
		
		for(int i=1;i<=P;i++){
			sumx=sumx+B[i];
			state++;
			if((mx_st<state&&sumx<=M)||(mx_st==state&&Pminsumx>sumx)){
				mx_st=state;
				Pminsumx=sumx;
			}
			while(sumx>M){
				sumx=sumx-B[ini];
				state--;
				ini++;
			}
			if((mx_st<state &&sumx<=M)||(mx_st==state&&Pminsumx>sumx)){
				mx_st=state;
				Pminsumx=sumx;
			}
		}
		std::cout<<Pminsumx<<mx_st;
	}
	while(T--);
	return 0;
}