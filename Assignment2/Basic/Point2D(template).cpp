#include <bits/stdc++.h>

using namespace std;

void S( vector<int> &a){
    int n = a.size();
    for (int i = 1; i < n; i++){
        int key = a[i]; // Đặt key có giá trị bằng phần tử đang xét
        int j = i - 1; // Thực hiện lặp để đặt a[i] vào phần dãy trước đó
        while ( j >=0 && a[j] > key){
            a[j+1]= a[j]; // Dịch phần tử lớn hơn key về sau một đơn vị
            j--;
        }
        a[j+1] = key; // Đặt giá trị của phần tử a[i] vào vị trí đúng
    }
}
map<int, vector<int>> b; // Tạo ánh xạ bằng map để sắp xếp sẵn x tăng dần, vector để chứa các giá trị của y 

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        b[x].push_back(y);
    }
    for(auto &p : b){ // Duyệt từng phần tử
        int x = p.first;
        vector<int> &list = p.second;
        S(list); // Sắp xếp các giá trị y của 1 giá trị x
        reverse(list.begin(), list.end()); // Đảo ngược để đưa giá trị y lớn nhất lên trước
        for (int y : list ){
            cout << x <<" "<< y << "\n"; 
        }
    }


    return 0;
}