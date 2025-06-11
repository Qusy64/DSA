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
map<int, map<int, vector<int>, greater<int>>> b; // Tạo ánh xạ bằng map để sắp xếp sẵn x tăng dần, y giảm dần và z

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        b[x][y].push_back(z);
    }
    for(auto &p : b){ // Duyệt từng giá trị x
        int x = p.first;
        for ( auto &q : p.second){ // Với mỗi x ta duyệt từng giá trị y
            int y = q.first;
            vector <int> &z = q.second; 
            S(z); // Sắp xếp mảng vector chứa các giá trị z
            for ( auto &i : z){
                cout << x << " " << y << " " << i << " \n"; // Xuất ra tọa độ của từng điểm thỏa đề
            }
        }
    }
    return 0;
}