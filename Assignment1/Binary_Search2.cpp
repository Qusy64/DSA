#include <iostream>
#include <string>
using namespace std;

void binarysearch(string a[], int n, string x) {
    int l = 0, r = n -1, mid, duyet = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        duyet++;  
        if (a[mid] == x) {
            cout << mid << endl;  
            cout << duyet << endl; 
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
}

int main() {
    int n;
    cin >> n;  
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }
    string x;
    cin >> x; 
    binarysearch(a, n, x);  
    return 0;
}