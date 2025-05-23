#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, W;

void Solve(vector<int> weight, vector<int> value){
    vector<int> dp(W + 1, 0);
    for ( int i = 0; i < n; i++){
        for ( int j = W; j >= weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[W];
}

int32_t main() {
    cin >> n;
    cin >> W;
    vector<int> weight(n);
    vector<int> value(n);
    for( int i = 0; i < n; i++){
        cin >> weight[i];
        cin >> value[i];
    }
    Solve(weight, value);

    return 0;
}