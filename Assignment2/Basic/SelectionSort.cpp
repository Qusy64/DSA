#include <bits/stdc++.h>
using namespace std;
 
void SelectionSort( vector<int>& a, int n){
    for ( int i = 0; i < n-1 ; i++){
        int min_index = i; // Với từng giá trị i, ta sẽ sắp xếp phần tử nhỏ lên trước
        for ( int j = i+1 ; j < n; j++){
            if ( a[j] < a[min_index])
                min_index = j;
        }
        if ( min_index != i){
            swap ( a[i], a[min_index]); // Đặt phần tử nhỏ lên đầu mảng
            for ( int k = 0; k< n ; k++){
                cout << a[k]<< " "; // Xuất mảng sau mỗi lần swap
            }
            cout<< endl;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector <int> a(n);
    for ( int i = 0 ; i< n; i++){
        cin >> a[i];
    }
    SelectionSort(a,n);
    return 0;
}   