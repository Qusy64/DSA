void merge(int a[], int n, int b[], int m, int c[]){ // Ta sử dụng thuật toán trộn
    // Nhập vào hai mảng con
    int i = 0, j = 0, k = 0;
    while ( i<n && j< m ){ // Trộn hai mảng con 
        if(a[i] <= b[j]){
            c[k]= a[i];
            i++;
        }else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    // Thêm phần còn lại
    while ( i < n){
        c[k]= a[i];
        i++;
        k++;
    }
    while ( j<m){ 
        c[k]= b[j];
        j++;
        k++;
    }
}