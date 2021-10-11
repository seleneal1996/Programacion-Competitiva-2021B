#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int N = 100000;
int tree[4 * N];
int lazy[N];
void push(int v) {
    tree[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    tree[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return tree[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int main()
{
  int T,n;
	std::cin>>T;
	while(T--){
		int K;
		std::cin>>n>>K;
		for(int i=1;i<=n;i++){
			std::cin>>lazy[i];
		}
		int rpta=0;
		push(n);
		for(int i=1;i<=n;i++){
			int minor=min(query(1, 1, n, max(1,i-K-1), max(i-1,1)),query(1,1,n,min(i+1,n), min(i+K+1,n)));
			rpta=max(lazy[i]-minor,rpta);
		}
		std::cout<<rpta<<endl;
	}
	return 0;
}