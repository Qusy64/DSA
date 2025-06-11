#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a,int n, int k) {
    // Gọi k1 là số phần tử chỉ xuất hiện 1 lần
    // Gọi k2 là số phần tử xuất hiện từ 2 lần trở lên
    int k1 = 0, k2 = 0; 
    for (int i = 1; i <= n; i++) { // Duyện qua các số chạy từ 1 đến n
        if (a[i] == 1) { // Nếu a[i] = 1 thì k1 tăng thêm 1
            k1++;
        }
        else if ( a[i] >= 2){ // Nếu a[i] >= 2 thì k2 tăng thêm 1
            k2++;
        }
    }
    // Nếu k1 + k2 <= 2 * k <= k1 + 2 * k2 thì say YES
    if ((k1 + 2 * k2) >= 2 * k && 2 * k >= (k1 + k2) ) { 
        cout << "YES"<< endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) { // Với T test
        int n, k;
        cin >> n >> k;
        vector<int> a(n+2); // Khởi tạo mảng a lưu trữ số lần xuất hiện của giá trị trong khoảng 1 đến n
        for (int i = 0; i <= n+1 ; i++){ // Khởi tạo các giá trị 0
            a[i] =0;
        }
        for (int i = 1; i <= n; i++) { // Với mỗi phần tử được nhập vào thì ta cộng số lần xuất hiện của số đó thêm 1
            int x;
            cin >> x;
            a[x]++;
        }
        solve( a, n, k);
    }
    return 0;
}
