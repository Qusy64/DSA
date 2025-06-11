#include <bits/stdc++.h>

using namespace std;

int dem[201]; // Mảng này để lưu số lần xuất hiện của các số điểm a[i] ( 0 <= a[i] <= 200 )

int timtrungvi( int n ){ // Ta sẽ tìm trung vị của d lần đánh trước đó
    int trungvi = 0;
    for ( int i = 0; i < 201; i++){
        trungvi = trungvi + dem[i]; // Ta sẽ cộng số lần xuất hiện của các số từ bé đến lớn
        if ( trungvi >= n){ // Nếu thỏa điều kiện số lần xuất hiện lớn hơn n
            return i;// Trả về giá trị trung vị là i
        }
    }
    return -1;
}

void solve(vector<int> a, int d){
    int s = 0;
    for ( int i = 0; i < d; i++){ // Đầu tiên ta có số lần xuất hiện của các phần tử từ 0 đến d
        dem[a[i]]++;
    }
    for( int i = d ; i < a.size(); i++){
        if( d & 1){ // Nếu d lẻ
            int mid = timtrungvi( (d+1) / 2 ); // Đặt mid là giá trị trung vị 
            if ( a[i] >= 2*mid){
                s++;
            }
        }
        else { // Nếu d chẵn
            // Đặt mid1, mid2 lần lượt là hai giá trị ở giữa, sau khi sắp xếp d lần ghi điểm trước
            int mid1 = timtrungvi(d / 2); 
            int mid2 = timtrungvi( d / 2 + 1 );
            // Trung vị lúc này sẽ là ( mid1 + mid2 ) / 2
            if( a[i] >= (mid1 + mid2)){
                s++;
            }
        }
        // Sau khi xét xong 1 phần tử thì ta sẽ thay đổi mảng dem sao cho đúng với d lần đánh trước
        dem[a[i - d]]--;
        dem[a[i]]++;
    }
    cout << s;
}
int main (){
    int n,d;
    cin>> n>>d;
    vector<int> a(n);
    for (int i = 0; i<n; i++){
        cin>>a[i];
    }
    solve(a, d);
    return 0;
}