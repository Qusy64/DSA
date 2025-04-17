#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n + 1); // Tạo danh sách các sinh viên
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }

    list<int> moi; // Tạo mảng mới chứa các sinh viên đã được mời
    unordered_map<int, list<int>::iterator> vi_tri; // Lưu vị trí của sinh viên đã được mời

    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;

        if (vi_tri.count(x)) {
            moi.erase(vi_tri[x]); // Xóa sinh viên khỏi vị trí cũ nếu như sinh viên đã được mời
        }

        moi.push_front(x); // Đưa lên đầu hàng
        vi_tri[x] = moi.begin(); // Cập nhật lại vị trí mới (đầu hàng)

        if (a[x] != -1) { // Xóa đặt lại mssv của sinh viên đã được mời là -1
            a[x] = -1; 
        }
    }

    for (int x : moi) { // Xuất ra mssv của các sinh viên được mời trước
        cout << x << " ";
    }
    for (int i = 1; i <= n; i++) { // Xuất ra mssv của các sinh viên còn lại
        if (a[i] != -1) cout << a[i] << " ";
    }

    return 0;
}