#include <bits/stdc++.h>

using namespace std;

#define int long long

int m,n;

int32_t main() {
    cin >> m >> n;
    vector<int> Graph(m, 0);
    for ( int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        Graph[u]++;
        Graph[v]++;
    }
    int Vertice_alone = 0;
    for( int i = 0; i < m; i++){
        if ( Graph[i] == 0){
            Vertice_alone++;
        }
    }
    cout << Vertice_alone;
    return 0;
}