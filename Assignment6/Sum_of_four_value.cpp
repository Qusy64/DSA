#include <bits/stdc++.h>

using namespace std;

#define int long long

int N, X;

void Solve(vector<int> a){
    unordered_map<long long, vector<pair<int, int>>> sum_2;
    for (int i = 1 ; i <= N; i++){
        for (int j = i + 1 ; j <= N; j++){
            sum_2[a[i] + a[j]].emplace_back(i, j);
        }
    }
    for (int k = 1; k <= N; ++k) {
        for (int l = k + 1; l <= N; ++l) {
            int quy = X - (a[k] + a[l]);
            if (sum_2.count(quy)) {
                for (auto [i, j] : sum_2[quy]) {
                    if (i != k && i != l && j != k && j != l) {
                        cout << i << " " << j << " " << k << " " << l;
                        return;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int32_t main() {
    cin >> N >> X;
    vector<int> a(N + 1);
    for ( int i = 1; i <= N; i++){
        cin>> a[i];
    }
    Solve(a);
    return 0;
}