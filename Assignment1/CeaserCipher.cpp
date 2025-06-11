#include <iostream>
#include <string>
using namespace std;

string caesar(int k, string s) {
    k = k % 26;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'A' + (s[i] - 'A' + k) % 26;
        }
    }
    return s;
}

int main() {
    int k;
    string s;
    cin >> k; 
    cin.ignore(); 
    getline(cin, s); 
    string cipher = caesar(k, s);
    cout << cipher << endl;
    
    return 0;
}