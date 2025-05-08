#include <bits/stdc++.h>

using namespace std;

#define int long long

void Solve(set<int> quy){
    cout << quy.size() << endl;
    for ( int i : quy ){
        cout << i << " ";
    }
}

int32_t main() {
    int n, x;
    cin >> n;
    set<int> quy;
    for (int i = 0; i< n; i++){
        cin >> x;
        quy.insert(x);
    }
    Solve(quy);
    return 0;
}