#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(vector<int> &a, int n, vector<int> &b) {
    vector<int> a1 = a, a2 = a; // Ta tạo hai mảng a1 a2 giống mảng a ban đầu để xử lý
    b = a; // Mảng b sẽ là mảng để sắp xếp
    unordered_map<int, int> c, d; // Tạo mảng c và d lưu vị trí của giá trị đã được sắp xếp 
    int tang = 0, giam = 0; // Hai biến tang, giam lần lượt là số lần đổi trong việc sắp xếp mảng tăng dần và giảm dần
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++){ // Ghi các vị trí đúng của giá trị được sắp xếp
        c[b[i]] = i; 
    }
    for (int i = 0; i < n; i++){ 
        while (c[a1[i]] != i) {// Với từng vị trí trong mảng a1, ta sẽ swap đến khi đưa đúng phần tử về vị trí đó
            swap(a1[i], a1[c[a1[i]]]);
            tang++; // Biến tang tăng lên 1
        }        
    }
    // Tương tự với mảng sắp xếp giảm dần
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < n; i++){ // Ghi các vị trí đúng của giá trị được sắp xếp
        d[b[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--){
        while (d[a2[i]] != i) {// Với từng vị trí trong mảng a2, ta sẽ swap đến khi đưa đúng phần tử về vị trí đó
            swap(a2[i], a2[d[a2[i]]]);
            giam++; // Biến giam tăng lên 1 
        }        
    }
    
    cout << min(tang, giam); // Xuất ra giá trị nhỏ hơn trong hai biến tang, giam
    return 0;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    solve(a, n, b);
    return 0;
}