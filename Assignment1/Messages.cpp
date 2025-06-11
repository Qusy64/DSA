#include <iostream>
#include <string>

using namespace std;

int main() {
    string Sb, Se;
    cin >> Sb >> Se;
    int n = Sb.length();
    int m = Se.length();
    int max = 0;
    for (int i = 1; i <= min(n, m); i++) {
        if (Sb.substr(n - i, i) == Se.substr(0, i)) {
            max = i;
        }
    }
    int s = Sb.length() + Se.length() - max;
    cout << s<<endl;
    cout << Sb << Se.substr(max);
    return 0;
}
