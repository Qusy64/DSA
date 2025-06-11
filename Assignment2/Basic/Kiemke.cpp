#include <bits/stdc++.h>
using namespace std;

int Kk(vector<string>& a, int l, int r) { //Thuật toán QuickSort
    int left = l;
    int right = r;
    string pivot = a[(l+r)/2];
    // Thực hiện đưa tất cả phần tử lớn hơn pivot về bên phải
    // Thực hiện đưa tất cả phần tử nhỏ hơn pivot về bên trái
    while ( true){
        while ( a[left] < pivot){
            left++;
        }
        while( a[right] > pivot){
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
void Kiemke(vector<string>& a, int l, int r) { // Thuật toán QuickSort
    if (l < r) {
        int q = Kk(a, l, r);
        if (l < q - 1) Kiemke(a, l, q - 1);
        if (q < r) Kiemke(a, q, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;  
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Kiemke(a,0, n-1); // Sắp xếp mảng
    int c = 1;
    for ( int i = 0; i <n-1 ; i++){ // Tính số phần tử duy nhất
        if(a[i] != a[i+1]){
            c++;
        }
    }
    cout<<c;
    return 0;
}