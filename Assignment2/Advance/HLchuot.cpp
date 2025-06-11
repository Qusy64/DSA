#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int MAXN = 2e6 + 5;  
int T, p; // Tạo biến toàn cục
long long gt[MAXN];

// Ta sẽ sử dụng định lý Lucas
vector<int> getRepresentation(int n, int p) { // Chuyển số n sang cơ số p
    vector<int> res;
    while (n > 0) {
        res.push_back(n % p); // Thêm vào mảng res phần dư khi chia n cho p
        n /= p; // Lấy số n mới bằng cách chia n cho p
    }
    return res;
}

long long powerMod(long long base, long long exp, long long mod) { // Tính số mũ của một số
    int result = 1;
    while (exp > 0) {
        if (exp & 1){ // Phép and số exp với 1, kiểm tra rằng số này có phải 1 không
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Nếu không thì bình phương giá trị
        exp >>= 1; // Phép dịch phải số mũ ( dịch phải là chia 2 )
    }
    return result;
}

long long C(int n, int k, int p) { // Hàm tổ hợp chập k của n phần tử
    if (k > n || k < 0) 
        return 0;
    // ta không thể dùng phép chia a/b trong modunlo, theo định lý fermat thì ta có a.b^(p-2)
    return (((gt[n] * powerMod(gt[k], p - 2, p)) % p) * powerMod(gt[n - k], p - 2, p)) % p;
}
 
void solve(int n) {
    int s = 1;
    vector<int > ni = getRepresentation(2 * n - 1, p); // Đặt ni là mảng chứa các chữ số của số 2*n - 1 trong cơ số p
    vector<int> ki = getRepresentation(n, p);// Đặt ki là mảng chứa các chữ số của số n trong cơ số p
    int len = max(ni.size(), ki.size()); // Ta sẽ thêm các số 0 sao cho độ dài ki và ni bằng nhau
    while (ni.size() < len) ni.push_back(0);
    while (ki.size() < len) ki.push_back(0);
    for (int i = 0; i < len; i++) {
        s = (s * C(ni[i], ki[i], p)) % p; // Ta tính theo định lý Lucas
    }
    cout << s << "\n";// Xuất kết quả
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T >> p;
    vector<int> a(T);   
    for (int i = 0; i < T; i++) { // Nhập các số N
        cin >> a[i];
    }
    gt[0] = 1;
    for (int i = 1; i < p; i++) { // Tiền xử lý các lũy thừa 
        gt[i] = (gt[i - 1] * i) % p;
    }
    for (int i = 0; i < T; i++) {
        solve(a[i]);
    }
    
    return 0;
}
