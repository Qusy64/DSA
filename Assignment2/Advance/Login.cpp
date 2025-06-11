#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n, Q;
    cin >>n >>Q;
    map <string, vector <string>> user; // Tạo mảng map user. Đối với bài login1 sẽ tạo map <string, string> user
    for ( int i = 0; i<n ;i ++){
        string a,b;
        cin >> a >> b;
        user[a].push_back(b); // Ghi lần lượt username, password. Đối với login1 thì sẽ gán giá trị user[a] là password gần nhất
    }
    for ( int i = 1; i <=Q; i++){
        string s;
        cin >> s;
        if (user.find(s) == user.end()){// Nếu không tìm thấy username trong danh sách user
            cout << "Chua Dang Ky!"<< endl; // Người dùng chưa đăng kí
        }
        else{ // Nếu tìm thấy username trong danh sách user
            for ( auto &j : user[s]){ // Xuất ra các password theo thời gian của tài khoản mà user đăng nhập. Đối với bài login1 thì sẽ xuất ra password gần nhất
                cout << j << " ";
            }
            cout<< endl;
        }
    }
    return 0;
}