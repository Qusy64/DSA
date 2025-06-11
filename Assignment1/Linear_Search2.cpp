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
    int s = 0;  
    int tong = 0; 
    for (int i = 0; i < n; i++){
        if(a[i] == x)
            s++;       
    }
    cout << s << endl;
    for (int i = 0; i < n; i++) {
        tong++;  
        if (a[i] == x) {
            cout << i << " " << tong << endl;  
        }
    }
    
    return 0;
}