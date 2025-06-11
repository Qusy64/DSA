#include <bits/stdc++.h>
using namespace std;
 
void InsertionSort( vector<int> &a, int n){
    for (int i = 1; i < n; i++){
        int key = a[i]; // Đặt key có giá trị bằng phần tử đang xét
        int j = i - 1; // Thực hiện lặp để đặt a[i] vào phần dãy trước đó
        while ( j >=0 && a[j] > key){
            a[j+1]= a[j]; // Dịch phần tử lớn hơn key về sau một đơn vị
            j= j-1;
            for ( int k = 0; k<n ; k++){
                cout<<a[k] << " "; // Xuất ra mảng sau mỗi lần biến đổi
            }
            cout << endl;
        }
        a[j+1] = key; // Đặt giá trị của phần tử a[i] vào vị trí đúng
        for ( int k = 0; k<n ; k++){
            cout<<a[k] << " "; // Xuất ra mảng
        }
        cout << endl;
    }
}
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for ( int i = 0; i < n ; i++){
        cin >> a[i];
    }
    InsertionSort(a,n);
    return 0;
}