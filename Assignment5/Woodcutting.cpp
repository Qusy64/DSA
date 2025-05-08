#include <bits/stdc++.h>

using namespace std; 

void Solve(vector<long long> a) {
    if (a.size() <= 1) {
        cout << 0; 
        return;
    }
    priority_queue<long long, vector<long long>, greater<long long>> pq(a.begin(), a.end());
    long long totalcost = 0;

    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        long long cost = first + second;
        totalcost =totalcost + cost;
        pq.push(cost);
    }
    cout << totalcost;
}

int main() {
    int n;
    long long S;
    cin >> n;
    cin >> S;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solve(a);
    return 0;
}