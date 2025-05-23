#include <bits/stdc++.h>

using namespace std;

int n;

void Solve(vector<int> a){
    vector<int> dp(n,1);
    vector<int> trace(n,-1);
    int maxlen = 1, last = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
        if (maxlen < dp[i]){
            maxlen = dp[i];
            last = i;
        }
    }
    cout << maxlen << endl;
    vector<int> LIS;
    while( last != -1){
        LIS.push_back(a[last]);
        last = trace[last];
    }
    reverse(LIS.begin(), LIS.end());
    for( int i = 0; i < LIS.size(); i++){
        cout << LIS[i] << " ";
    }
}

int main(){
    cin >> n;
    vector <int> a(n);
    for ( int i = 0; i < n; i++){
        cin >> a[i];
    }
    Solve(a);
    return 0;
}