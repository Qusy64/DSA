#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> seen;  
    int mex = 0;  
    for (int i = 0; i < n; i++) {
        seen.insert(a[i]);  
        while (seen.find(mex) != seen.end()) {
            mex++;  
        }
        cout << mex << " ";
    }
    
    return 0;
}

