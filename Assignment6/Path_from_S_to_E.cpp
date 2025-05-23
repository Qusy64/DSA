#include <bits/stdc++.h>

using namespace std;

#define int long long

int m,n;
const int MAX_N = 2e3;
vector<int> Graph[MAX_N];
bool visited[MAX_N];
vector<int> List;

void DFS(int u){
    visited[u] = true;
    for (auto v : Graph[u]){
        if (!visited[v]){
            DFS(v);
            List.push_back(v);
        }
    }
}

int32_t main() {
    cin >> m >> n;
    for ( int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    DFS(0);
    for (int i = 1; i < m; i++){
        if(find(List.begin(), List.end(), i) != List.end()){
            cout << "CO\n";
        }
        else {
            cout << "KHONG\n";
        }
    }

    return 0;
}