#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

int C(int n, int k) {
    if (k > n) return 0;
    int res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void Solve(vector<int>& a) {  
    int tamgiac = 0;
    sort(a.begin(), a.end());
     
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        int lap = j - i;
        if (lap >= 3) {
            tamgiac += C(lap, 3); 
        }
        if (lap >= 2) {
            tamgiac += C(lap, 2) * i; 
            auto vitri = lower_bound(a.begin() + j, a.end(), 2 * a[i]);
            tamgiac += C(lap, 2) * (vitri - (a.begin() + j));
        }
        i = j; 
    }
    
    cout << tamgiac << endl;
}

int32_t main() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solve(a);
    return 0;
}
