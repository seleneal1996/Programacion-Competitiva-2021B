#include <bits/stdc++.h>
const int N = 1e5+5;
int input, n, x;
char s[N];
std::deque <int> d;

int main () {
    scanf("%d", &input);
    while (input--) {
        scanf(" %s", s);
        scanf("%d", &n);
        char c;
        scanf(" %*c");
        for (int i = 0; i < n; i++) {
            scanf(" %d%*c", &x);
            d.push_back(x);
        }
        if (n == 0) scanf(" %*c");
        int sz = strlen(s);
        int side = 1;
        int ok = 1;
        for (int i = 0; i < sz; i++) {
            if (s[i] == 'D' and d.empty()) {
                printf("error\n");
                ok = 0;
                break;
            }
            if (s[i] == 'D' and  side) d.pop_front();
            if (s[i] == 'D' and !side) d.pop_back();
            if (s[i] == 'R') side ^= 1;
        }

        if (ok) {
            printf("[");
            if (d.size()) {
                if (side) {
                    printf("%d", d.front());
                    d.pop_front();
                    while (d.size()) {
                        printf(",%d", d.front());
                        d.pop_front();
                    }
                } else {
                    printf("%d", d.back());
                    d.pop_back();
                    while (d.size()) {
                        printf(",%d", d.back());
                        d.pop_back();
                    }
                }
            }
            printf("]\n");
        }
    }

    return 0;
}