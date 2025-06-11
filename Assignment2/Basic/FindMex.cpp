#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;  
    vector<int> a(n+1);
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(x>n){ // Nếu x lớn hơn n thì ta không xét
            continue;
        }
        a[x]++; // Ghi lại số lần xuất hiện của giá trị x ( 0 <= x <= n)
    }
    for ( int i = 0; i<n+1; i++){ // Tìm số tự nhiên nhỏ nhất chưa được xuất hiện  
        if(a[i]==0){ 
            cout << i;
            break;
        }
    }
    
    return 0;
}