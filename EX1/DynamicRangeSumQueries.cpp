#include <bits/stdc++.h>
using abb = long long;
const int MX = 2e5+5;
int n, q;
std::vector<abb> bit(MX), x(MX);

void actualizar(int i, abb v) {
  for (; i<=n; i+=i&(-i)){
    bit[i]+=v;
  }
}

abb consultas(int ssx) {
  abb sum = 0;
	for(; ssx>0; ssx-=ssx&(-ssx)){
    sum += bit[ssx];
  }	
	return sum;
}

int main() {
	std::cin >> n >> q;
	for(int ix=1; ix<=n; ix++){
		std::cin >> x[ix];
		actualizar(ix, x[ix]);
	}
	for(int i=1; i<=q; i++){
		int t,a,b; 
    std::cin >> t >> a >> b;
    if (t==1) {
    	actualizar(a, -x[a]); 
    	x[a]=b; actualizar(a, x[a]); 
    } 
    else {
    	std::cout << consultas(b)-consultas(a-1) << "\n";
		}
	}
}