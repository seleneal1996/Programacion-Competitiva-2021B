//https://open.kattis.com/problems/lifeforms
#include <bits/stdc++.h>
#define MAX 100107
int Input_Strings[MAX]; 
int r[MAX], SA[MAX];
int pos[MAX];
int tmp[MAX];
int Longest_common_prefix[MAX]; 
int w[MAX]; // Mapeo de palabras
int N, S, gap;
bool hasLongest_common_prefix = false;
bool cmp(int i, int j) {
    if (pos[i] == pos[j]) {
        i += gap;
        j += gap;
        if (i < S && j < S)
            return pos[i] < pos[j];
        else
            return i > j;
    }
    return pos[i] < pos[j];
}


void buildSA() {
    for (int i = 0; i < S; ++i) {
        pos[i] = Input_Strings[i];
        SA[i] = i;      
        tmp[i] = 0;    
    }
    gap = 1;
    while (true) {
        std::sort(std::begin(SA), std::begin(SA) + S, cmp);
        for(int i=0; i < (S-1); ++i){
            int higher = cmp(SA[i], SA[i+1]);   
            tmp[i+1] = tmp[i] + (higher ? 1 : 0);
        }
        for(int i=0; i < (S); ++i) pos[SA[i]] = tmp[i]; 
        if (tmp[S-1] >= S-1) 
            break;
        gap = gap << 1; 
    }
}

void buildLongest_common_prefix(int SAsize) {
    for(int i=0; i < (SAsize); ++i) r[SA[i]] = i;
    Longest_common_prefix[0] = 0;
    int h = 0;
    for (int i = 0; i < SAsize; ++i) {
        if (r[i] == 0) {
            Longest_common_prefix[i] = 0;
            continue;
        }
        if (r[i] > 0) {
            int j = SA[r[i]-1];
            while (i+h < SAsize && j+h < SAsize && Input_Strings[i+h] == Input_Strings[j+h]) ++h;
            Longest_common_prefix[r[i]] = h;
            if (h > 0) {
                --h;
                hasLongest_common_prefix = true;
            }
        }
    }
}
 
bool findLCS(int x, int SAsize, bool print) {
    bool counted[N];
    int count;
    for (int i = 1; i < SAsize; ++i) {
        if (Longest_common_prefix[i] >= x) {
            for(int i=0; i < (N); ++i) counted[i] = false;
            count = 1;
            counted[w[SA[i-1]]] = true;
            int j = i;
            while (j < SAsize && Longest_common_prefix[j] >= x) { 
                if (w[SA[j]] != w[SA[j]+x-1]) { 
                    break;
                }
                if (!counted[w[SA[j]]]) {
                    counted[w[SA[j]]] = true;
                    ++count;
                }
                ++j;
            }
            if (count > N/2) {
                if (print) {
                    printf("%c", 'a' + Input_Strings[SA[i]]); 
                    for (int k = 1; k < x; ++k) {
                        printf("%c", 'a' + Input_Strings[SA[i]+k]);
                    }
                    printf("\n");
                }
                else {
                    return true;
                }
            }
            i = j-1;
        }
    }
    return false;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, SAsize, longestWord = -1;
    std::string line;
    while (scanf("%d", &N) == 1 && N != 0) {
        SAsize = 0;
        getline(std::cin, line); 
        for(int i=0; i < (N); ++i){
            getline(std::cin, line);
            if (line.length() - longestWord > 0)
                longestWord = line.length();
            for (int j = 0; j < line.length(); ++j) {
                w[SAsize] = i;
                Input_Strings[SAsize++] = line[j] - 'a';
            }
            Input_Strings[SAsize++] = 27+i; 
            Input_Strings[SAsize] = 0;
        }
        Input_Strings[SAsize-1] = 0;

        --SAsize;
        S = SAsize;
        buildSA();
        buildLongest_common_prefix(SAsize);
        int low = 1, best = -1;
        int high = longestWord;
        if (hasLongest_common_prefix) {
            while (high >= low) {
                int mid = low + (high-low)/2;
                if (findLCS(mid, SAsize, false)) {
                    low = mid + 1;
                    best = fmax(mid,best);
                }
                else
                    high = mid - 1;
            }
        }
        if (best != -1) {
            findLCS(best, SAsize, true);
        }
        else
            printf ("?\n");
        printf ("\n");
     }
  return 0;
}