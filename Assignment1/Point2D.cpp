#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    for ( int i = 0; i <n ; i++)
        cout << a[i].first <<" "<< a[i].second << "\n";
    return 0;
}