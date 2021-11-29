//https://open.kattis.com/problems/dungeon
#include <bits/stdc++.h>
using namespace std;
int x, y, z;
bool inrange(int a, int b, int c)
{
    return (a >= 0 && b >= 0 && b >= 0 && a < x && b < y && c < z);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> x >> y >> z) {
        tuple<int,int,int> s;
        tuple<int,int,int> e;

        if(x == 0 || y == 0 || z == 0) {
            break;
        }

        vector<vector<vector<int>>> v(x);
        for(auto& i : v) {
            i.resize(y, vector<int>(z, -2));
        }

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                for(int k = 0; k < z; k++)
                {
                    char c;
                    cin >> c;
                    if(c == '#') {
                        v[i][j][k] = -1;
                    }
                    if(c == 'S') {
                        get<0>(s) = i;
                        get<1>(s) = j;
                        get<2>(s) = k;
                    }
                    if(c == 'E') {
                        get<0>(e) = i;
                        get<1>(e) = j;
                        get<2>(e) = k;
                    }
                }
            }
        }

        // BFS
        queue<tuple<int,int,int>> q;
        q.push(s);
        v[get<0>(s)][get<1>(s)][get<2>(s)] = 0;

        while(!q.empty()) {
            auto c = q.front();
            q.pop();
            int x = get<0>(c);
            int y = get<1>(c);
            int z = get<2>(c);
            if(inrange(x-1,y,z) && v[x-1][y][z] == -2) {
                v[ x-1][ y][ z] = v[ x][ y][ z] + 1;
                q.push({ x-1, y, z});
            }
            if(inrange( x+1, y, z) && v[ x+1][ y][ z] == -2) {
                v[ x+1][ y][ z] = v[ x][ y][ z] + 1;
                q.push({ x+1, y, z});
            }
            if(inrange( x, y-1, z) && v[ x][ y-1][ z] == -2) {
                v[ x][ y-1][ z] = v[ x][ y][ z] + 1;
                q.push({ x, y-1, z});
            }
            if(inrange( x, y+1, z) && v[ x][ y+1][ z] == -2) {
                v[ x][ y+1][ z] = v[ x][ y][ z] + 1;
                q.push({ x, y+1, z});
            }
            if(inrange( x, y, z-1) && v[ x][ y][ z-1] == -2) {
                v[ x][ y][ z-1] = v[ x][ y][ z] + 1;
                q.push({ x, y, z-1});
            }
            if(inrange( x, y, z+1) && v[ x][ y][ z+1] == -2) {
                v[ x][ y][ z+1] = v[ x][ y][ z] + 1;
                q.push({ x, y, z+1});
            }
        }

        if(v[get<0>(e)][get<1>(e)][get<2>(e)] < 0) {
            cout << "Trapped!" << endl;
        }
        else {
            cout << "Escaped in " << v[get<0>(e)][get<1>(e)][get<2>(e)]  << " minute(s)." << endl;
        }
    }
}
