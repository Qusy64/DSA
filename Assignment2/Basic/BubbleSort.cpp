#include <bits/stdc++.h>
using namespace std;
 
void BubbleSort( vector<int>& a, int n){ // Đưa dần những phần tử lớn nhất về sau mảng
    for ( int i = 0; i < n-1; i++){
        for ( int j= 0; j< n-1-i; j++){
            if ( a[j] > a[j+1]){ // Đổi chỗ nếu phần tử trước lớn hơn phần tử sau
                swap ( a[j], a[j+1]);
                for ( int k = 0; k < n; k++){ // Xuất mảng với mỗi lần swap
                    cout<< a[k]<< " ";
                }
                cout<< endl;
            }
        }
    }
}
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for ( int i = 0; i < n ; i++){
        cin >> a[i];
    }
    BubbleSort(a,n);
    return 0;
}