#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, s;
vector<vector<int>> Graph;
vector<bool> visited;
vector<int> attacked;

void DFS(int u) {
    visited[u] = true;
    attacked.push_back(u);
    for (auto v : Graph[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int32_t main() {
    cin >> n >> m;
    Graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    cin >> s;
    DFS(s);

    sort(attacked.begin(), attacked.end());
    cout << attacked.size() << "\n";
    for (auto x : attacked) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
