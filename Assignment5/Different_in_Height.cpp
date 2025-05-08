#include <bits/stdc++.h>

using namespace std;

#define int long long 

int n;

void Solve(vector<int> a){
    sort(a.begin(), a.end());
    int sum = 0;
    int cong,tru;
    for ( int i = 0; i < n; i++){
        sum = sum + i * a[i] - (n - 1 - i) * a[i];
    }
    cout << sum;
}

int32_t main() {
    cin >> n;
    vector<int> a(n);
    for (int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    Solve(a);
    return 0;
}