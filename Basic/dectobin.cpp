#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    vector<int> a;
    cin >> x;
    while(x > 0){
        int i = x % 2;
        a.push_back(i); // Ghi nhận số dư khi chia x cho 2
        x = x / 2; 
    }
    for ( int i = (int)a.size() - 1; i >= 0; i--){ // Duyệt từ phần tử số dư cuối cùng 
        cout << a[i];
    }
    return 0;
}