#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string decrypt( string a) {
    int n = a.length();
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            reverse(a.begin(), a.begin() + i);
        }
    }
    return a;
}

int main() {
    string a;
    cin >>a;
    string q = decrypt(a);
    cout << q << endl;
    
    return 0;
}