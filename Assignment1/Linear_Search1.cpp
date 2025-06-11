#include <iostream>
using namespace std;

void linear_search(int a[], int n, int x) {
    int forward_pos = -1, backward_pos = -1;
    int forward_count = 0, backward_count = 0;
    for (int i = 0; i < n; i++) {
        forward_count++;
        if (a[i] == x) {
            forward_pos = i;
            cout << forward_pos << endl;  
            cout << forward_count << endl;  
            break;
        }
    }  
    if (forward_pos != -1) {
        for (int i = n - 1; i >= 0; i--) {
            backward_count++;
            if (a[i] == x) {
                backward_pos = n -1 - i;
                cout << backward_pos << endl;  
                cout << backward_count << endl;
                break; 
            }
        }
    }
    if (forward_pos == -1) {
        cout << -1 << endl;  
    } 
}  

int main() {
    int n, x;
    cin >> n;  
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }
    cin >> x;  
    linear_search(a, n, x);  
    
    return 0;
}