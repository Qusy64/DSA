#include <bits/stdc++.h>
using namespace std;
 
void Merge(vector<int> &a , int left , int mid, int right){
    int n = a.size();
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> l(n1), r(n2); // Tạo hai mảng con 
    // Nhập vào hai mảng con
    for ( int i = 0; i< n1; i++){
        l[i]= a[left + i];
    }
    for ( int j = 0; j <n2 ; j++){
        r[j]= a[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while ( i<n1 && j< n2 ){ // Trộn hai mảng con 
        if(l[i] <= r[j]){
            a[k]= l[i];
            i++;
        }else {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    // Thêm phần còn lại
    while ( i < n1){
        a[k]= l[i];
        i++;
        k++;
    }
    while ( j<n2){ 
        a[k]= r[j];
        j++;
        k++;
    }
    // Quá trình in mảng sau mỗi lần trộn
    for ( int i = 0; i < left; i++){
        cout << a[i] << " ";
    }
    cout << "[ ";
    for ( int i = left; i< right + 1; i++){
        cout << a[i] << " ";
    }
    cout << "] ";
    for (int i = right + 1; i< n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void MergeSort(vector<int>& a, int left, int right){
    if( left < right ){
        int mid = (left + right)/2;
        // Áp dụng đệ quy để sắp xếp
        MergeSort ( a, left, mid);
        MergeSort ( a, mid + 1, right);
        Merge( a, left, mid, right);
    }
}
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for ( int i = 0; i < n ; i++){
        cin >> a[i];
    }
    MergeSort(a, 0, n - 1);
    return 0;
}