#include <bits/stdc++.h>

using namespace std;

int n,m;

int main() {
    cin >> n >> m;
    vector<int> next(n + 1), prev(n + 1);
    for(int i = 1; i <= n; ++i) {
        next[i] = (i % n) + 1;          
        prev[(i % n) + 1] = i;          
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            continue;
        }
        int px = prev[x], nx = next[x];
        next[px] = nx;
        prev[nx] = px;
        int ny = next[y];
        next[y] = x;
        prev[x] = y;
        next[x] = ny;
        prev[ny] = x;
    }
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        cout << cur << ' ';
        cur = next[cur];
    }
    return 0;
}
