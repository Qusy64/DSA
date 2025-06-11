#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int trongso = 0;
        sort(a, a + n);
        if( n>=4)
            trongso= a[n-1] + a[n-2] - a[0] -a[1];
        else if( n >1)
            trongso = a[n-1]- a[0];
        cout << trongso << endl;
    }

    return 0;
}