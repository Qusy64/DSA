#include <bits/stdc++.h>

using namespace std;

void khoa (string &s){
    sort(s.begin(),s.end()); // Sắp xếp chuỗi kí tự 
    int n= s.size();
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum = sum + (s[i] - '0'); // Tính tổng chuỗi kí tự
    }
    if( sum % 3 == 0){ // Nếu tổng chia hết cho 3 thì xuất giá trị lớn nhất
        for (int i = n-1; i >= 0; i--){
            cout << s[i];
        }
    }
    else if( sum % 3 == 1){ // Nếu tổng chia 3 dư 1 thì ta xóa bớt phần tử
        int k=0;
        for ( int i = 0; i < s.size(); i++){ // Duyệt từ phần tử bé nhất để xóa
            if( (s[i]-'0') % 3 == 1){
                s.erase(i,1); // Xóa 1 phần tử chia 3 dư 1 
                i--;
                k++;
                break;
            }
        }
        if( k ==0){ 
        // Nếu không tồn tại phần tử nào chia 3 dư 1 thì ta sẽ xóa 2 phần tử chia 3 dư 2
            for ( int i = 0; i<s.size();i++){ // Duyệt từ phần tử bé nhất để xóa
                if((s[i]-'0') % 3 ==2){
                    s.erase(i,1); // Xóa phần tử chia 3 dư 2
                    i--;
                    k++;
                    if (k==2) break;
                }
            }
        }
        n = s.size();
        for (int i = n-1; i >= 0; i--){ // Xuất ra giá trị lớn nhất chia hết cho 3
            cout << s[i];
        }
    }
    else if (sum %3==2){ // Nếu tổng chia 3 dư 2
        int k=0;
        for ( int i = 0; i < s.size(); i++){ // Duyệt từ phần tử nhỏ nhất để xóa
            if( (s[i]-'0') % 3 == 2){
                s.erase(i,1);// Xóa phần tử chia 3 dư 2
                i--;
                k++;
                break;
            }
        }
        if( k ==0){
        //Trường hợp không có phần tử nào chia 3 dư 2 thì ta xóa 2 phần tử chia 3 dư 1
            for ( int i = 0; i<s.size();i++){ // Duyệt phần tử nhỏ nhất để xóa
                if((s[i]-'0') % 3 ==1){
                    s.erase(i,1);// Xóa phần tử chia 3 dư 1
                    i--;
                    k++;
                    if (k==2) break;
                }
            }
        } 
        n = s.size();
        for (int i = n-1; i >= 0; i--){ // Xuất ra giá trị lớn nhất chia hết cho 3
            cout << s[i];
        }
    }
}

int main() {
    string s;
    cin>> s;
    khoa(s);
    

    return 0;
}