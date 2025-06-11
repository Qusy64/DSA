#include <bits/stdc++.h>
using namespace std;

int Xep(vector<string>& a, int l, int r) { // Thuật toán QuickSort
    int left = l;
    int right = r;
    string pivot = a[(l+r)/2];
    while ( true){
        while (left <= r && a[left] < pivot){
            left++;
        }
        while(right >= l && a[right] > pivot){
            right--;
        }
        if(left <= right){
            swap(a[left], a[right]);
            left++;
            right--;
        }else break;
    }
    return left;
}
void Sapxep(vector<string>& a, int l, int r) { // thuật toán Quicksort
    if (l < r) {
        int q = Xep(a, l, r);
        if (l < q - 1) Sapxep(a, l, q - 1);
        if (q  < r) Sapxep(a, q, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n>>k;
    vector<string> a(n),b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Sapxep(a,0, n-1);
    int c=1;
    cout<<a[0]<<" "; // Xuất phần tử đầu tiên
    for (int i = 1; i < n && c < k; i++) { // Xuất ra các phần tử riêng biệt
        if (a[i] != a[i - 1]) {
            cout << a[i]<<" ";
            c++;
        } else {
            b.push_back(a[i]); // Các phần tử trùng lặp được thêm vào một mảng khác
        }
    }
    for (int i = 0; i < (int)b.size() && c < k; i++) { // Nếu chưa đủ k phần tử thì tiếp tục xuất 
        cout <<b[i]<<" ";
        c++;
    }
    return 0;
}