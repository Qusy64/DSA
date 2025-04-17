# Assignment3
Họ và tên : Lê Văn Quý
MSSV : 24521492
### Binary Search 2
Bài này ta sử dụng thuật toán ``Binary Search`` để tìm kiếm vị trí của y ( vị trí đầu tiên và cuối cùng )
``` cpp= 
// Binary Search cho trường hợp x = 1. Tìm vị trí đầu tiên y xuất hiện
int x1(const vector<pair<int, int>>& b, int y) {
    int l = 0, r = b.size() - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (b[mid].first >= y) {
            if (b[mid].first == y) ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

// Binary Search cho trường hợp x = 2. Tìm vị trí cuối cùng y xuất hiện
int x2(const vector<pair<int, int>>& b, int y) {
    int l = 0, r = b.size() - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (b[mid].first <= y) {
            if (b[mid].first == y) ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}
```
### Detectvirusin2D
Bài này ta sẽ tìm chuỗi kí tự theo chiều ngang và chiều dọc. Ý tưởng ban đầu sẽ dùng thuật toán [Rabin-Karp](https://youtu.be/yFHV7weZ_as?si=wDUbNWujGCsN2Gj7) nhưng sau nhiều lần không đúng, tôi đã thực hiện ``brute-force`` vì tôi thấy kích thước bài toán không lớn:
- $1 \leq N \times M \leq 10^5$
- $1 \leq Q \leq 10^4$
``` cpp=
// Duyệt ngang
    for (int i = 0; i < N; ++i) {
        for (int len = 1; len <= max_len; ++len) {
            if (M < len) continue;
            for (int j = 0; j <= M - len; ++j) {
                substr_by_length[len].insert(grid[i].substr(j, len));
            }
        }
    }

    // Duyệt dọc
    for (int col = 0; col < M; ++col) {
        string col_str;
        for (int row = 0; row < N; ++row)
            col_str += grid[row][col];
        for (int len = 1; len <= max_len; ++len) {
            if ((int)col_str.size() < len) continue;
            for (int j = 0; j <= (int)col_str.size() - len; ++j) {
                substr_by_length[len].insert(col_str.substr(j, len));
            }
        }
    }

    // Tìm chuỗi virus
    for (auto &[len, pat] : pattern_list) {
        cout << (substr_by_length[len].count(pat) ? '1' : '0');
    }
    cout << '\n';
```
### Kiểm kê 2
Vì wecode ban ``unordered_map, set, map,...`` Nên ta sẽ dùng hàm ``Quicksort`` tự viết, để rồi đếm số lần xuất hiện của một mã sản phẩm.
``` cpp=
Kiemke(a,0, n-1); // Đlà hàm quicksort để sắp xếp mảng đầu vào
    int c = 1;
    for ( int i = 0; i <n-1 ; i++){ // Ta sẽ ghi lại số lần xuất hiện ( giống như sử dụng unoreded-map )
        if(a[i] != a[i+1]){
            b.push_back({a[i],c});
            c = 1;
            continue;
        }
        else {
            c++;
        }
    }
    b.push_back({a[n - 1], c});
    quick(b, 0, b.size() - 1); // Sắp xếp lại theo yêu cầu đề bài
    for ( auto &p : b){
        cout <<p.first << " "<<  p.second << "\n";
    }
```
### Xếp hàng 1,2
Ở hai bài này thì ta sẽ lưu trữ lại danh sách các sinh viên được mời để thuận tiện cho việc quản lý sắp xếp.
Hai bài gần như giống nhau về mặt thuật toán.
``` cpp=
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
```