---
title: IT003.P21.CTTN.2.Assignment2

---

# IT003.P21.CTTN.2.Assignment2
 Họ và tên:Lê Văn Quý
MSSV: 24521492
## Task:
Bài này ta sẽ tìm giá trị vị trí chỗ ngồi của Alice, rồi sau đó chọn vị trí cho Bob bằng cách lấy vị trí của Alice ± k.
## Point3D:
Bài này ta sẽ sắp xếp theo đề bài yêu cầu
``` c++
map<int, map<int, vector<int>, greater<int>>> b;
```
Lúc này ta đã có x được sắp xếp tăng dần và y sắp xếp giảm dần.
``` c++
for(auto &p : b){
        int x = p.first;
        for ( auto &q : p.second){
            int y = q.first;
            vector <int> &z = q.second; 
            S(z); 
        }
    }
```
Sau đó ta sắp xếp lại z theo thứ tự tăng dần là được.
## an.512.Trộn 2 mảng:
Bài này ta sẽ merge 2 mảng lại với nhau.
## Find Mex:
Ta thấy với một dãy có n phần tử thì giá trị MEX sẽ thuộc đoạn [0,n], nên nếu như giá trị aᵢ nhập vào mà lớn hơn n thì ta sẽ không quan tâm đền.
## Point2D (template):
Bài này tương tự với bài Point3D.
## VU33_MaxStr:
Nếu tổng chuỗi kí tự chia 3 dư 1 thì ta sẽ xóa 1 phần tử chia 3 dư 1 hoặc xóa 2 phần tử chia 3 dư 2 ( nếu không có phần tử nào chia 3 dư 1).
Làm điều tương tự nếu chuỗi kí tự chia 3 dư 2.
## VQ44_FLOWERS(template):
Ta sẽ dùng Quicksort để sắp xếp lại mảng, sau đó xuất ra giá trị các phần tử riêng biệt, những giá trị trùng sẽ được xuất sau đó, đến khi nào đủ theo yêu cầu đề bài.
## Kiểm kê:
Bài này ta sẽ sắp xếp lại mảng sau đó đếm số phần tử phân biệt.
## MergeSort:
Sử dụng thuật toán MergeSort
``` c++
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
```
## InsertionSort:
Sử dụng thuật toán InsertionSort
``` c++
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
```
## BubbleSort:
Sử dụng thuật toán BubbleSort
``` c++
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
```
## SelectionSort:
Sử dụng thuật toán SelectionSort
``` c++
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
```
