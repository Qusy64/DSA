#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n;  
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    cin >> x;  
    int l = 0, r = n - 1, mid, duyet = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        duyet++; 
        if (a[mid] == x) {
            cout << mid << endl; 
            cout << count << endl; 
            return;
        } 
        else if (a[mid] < x) {
            l = mid + 1; 
        } 
        else {
            r = mid - 1;  
        }
    }
    cout << -1 << endl;
    
    return 0;
}