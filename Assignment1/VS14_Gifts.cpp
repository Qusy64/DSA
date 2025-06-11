#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tongqua(int n, int x, vector<int>& a) {
    sort(a.begin(), a.end()); 
    int l = 0,r = n -1;
    int tong = -1;
    while (l< r) {
        int s = a[l] + a[r];
        if (s >x) {
            r--; 
        } else {
            tong = max(tong,s); 
            l++; 
        }
    }
    return tong;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << tongqua(n, x, a) << endl;
    return 0;
}