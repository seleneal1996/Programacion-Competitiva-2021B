//https://open.kattis.com/problems/howmanydigits
#include <bits/stdc++.h>
using namespace std;
int c=1e6;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double arr[c];
    arr[0] = 0;
    for (int x = 1; x <= 1e6; x++)
        arr[x] = arr[x - 1] + log10(x);
    int num;
    while (cin >> num)
        cout << (int)arr[num] + 1 << '\n';
    return 0;
}
