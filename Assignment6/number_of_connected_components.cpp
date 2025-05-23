#include <bits/stdc++.h>

using namespace std;

#define int long long

int m,n;
const int MAX_N = 2e3;
vector<int> Graph[MAX_N];
bool visited[MAX_N];

void DFS(int u) {
    visited[u] = true;
    for (int v : Graph[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int32_t main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    int Connected_Components = 0;
    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            DFS(i);
            Connected_Components++;
        }
    }
    cout << Connected_Components;
    return 0;
}
