#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    vector<char> stk; 
    for (auto &i : s){
        if (i == '{' || i == '(' || i == '[') { // Duyệt qua các dấu mở
            stk.push_back(i); 
        }
        else if (i == '}' || i == ')' || i == ']') { // Duyệt qua các dấu đóng
            if (stk.empty()) { // Nếu không có dấu mở mà lại có dấu đóng, xuất ra 0
                cout << '0'; 
                return 0;
            }
            char top = stk.back();
            stk.pop_back();  
            if ((i == '}' && top != '{') || (i == ')' && top != '(') || (i == ']' && top != '[')) { // Nếu các dấu đóng mở không trùng khớp với nhau
                cout << '0';  
                return 0;
            }
        }
    }
    if (!stk.empty()) { // Sau vòng lặp for, nếu stk còn phần tử thì còn thừa các dấu mở
        cout << '0';  
    }
    else { // stk không còn phần tử nào thì chuỗi latex hợp lệ
        cout << '1';
    }
    return 0;
}