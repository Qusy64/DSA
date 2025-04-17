#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    list<int> hang; // Tạo danh sách hàng các sinh viên
    unordered_map<int, list<int>::iterator> vi_tri; // 

    for (int i = 1; i <= n; ++i) {
        hang.push_back(i); 
        vi_tri[i] = prev(hang.end()); // Lưu vị trí iterator của sinh viên i
    }

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        if (vi_tri.count(x)) {
            hang.erase(vi_tri[x]); // Xóa sinh viên khỏi vị trí cũ
        }
        hang.push_front(x); // Đưa lên đầu hàng
        vi_tri[x] = hang.begin(); // Cập nhật lại vị trí mới (đầu hàng)
        cout << hang.back() << " "; // Xuất ra mssv của sinh viên cuối cùng sau khi thầy gọi
    }

    return 0;
}
