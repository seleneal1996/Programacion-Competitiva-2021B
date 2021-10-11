#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int N = 100000;
int tree[4 * N];
int arr[N];
int n;
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

int suma(int v, int tl, int tr, int l, int r){
    if (l > r) {return INF;}
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return min(suma(v*2, tl, tm, l, min(r, tm)),suma(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main()
{
	int T;
	std::cin>>T;
	while(T--){
		int K;
		std::cin>>n>>K;
		for(int i=1;i<=n;i++){
			std::cin>>arr[i];
		}
		int rpta=0;
		build(1,0,n);
		for(int i=1;i<=n;i++){
			int minor=min(suma(1, 1, n, max(1,i-K-1), max(i-1,1)),suma(1,1,n,min(i+1,n), min(i+K+1,n)));
			rpta=max(arr[i]-minor,rpta);
		}
		std::cout<<rpta<<endl;
	}
	return 0;
}