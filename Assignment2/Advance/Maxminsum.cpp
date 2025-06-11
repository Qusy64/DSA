#include<bits/stdc++.h>
using namespace std;

const long long p = 1e9 + 7;// Khởi tạo giá trị p=1e9+7
const long long MAX_N = 1e6;
long long gt[MAX_N];// Khởi tạo mảng gt để tính sẵn các giai thừa

long long powerMod(long long base, long long exp, long long mod){// Hàm powerMod để lũy thừa
    long long result = 1;
    while(exp > 0){
        if ( exp & 1){
            result = (result * base ) % mod;;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

long long C(long long n, long long k){// Hàm C để tính giá trị tổ hợp chập k của n
    if (k > n){
        return 0;
    }
    return (((gt[n] * powerMod(gt[k], p - 2, p)) % p) * powerMod(gt[n - k], p - 2, p)) % p;// giá trị hàm C theo công thức
}
void giaithua(){// Hàm tính các giá trị giai thừa 
    gt[0]=1;
    for( long long i = 1; i <= 1e5 ; i++){
        gt[i] = (gt[i-1] * i) % p;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k;
    cin >> n >> k;
    long long a[n + 1];
    for (long long i =1 ; i <= n; i++){
        cin >> a[i];
    }
    giaithua();
    sort (a + 1, a + 1 + n);// Sắp xếp các giá trị trong mảng a[]
    long long solve = 0;
    for ( long long i = 1; i <= n ; i++){// Ta xét qua các phần tử mảng a[]
        if (i - 1 >= k - 1){
            solve = (solve + (a[i] * C(i - 1, k - 1))) % p;// Nếu phần tử thứ i có thể là giá trị của món quà do Alice chọn, ta nhân giá trị món quà với số lần bằng số cách chọn k-1 phần tử trong i-1 phần tử trước đó
        }
        if ( n - i >= k - 1){
            solve = (solve - (a[i] * C(n - i, k - 1))) % p;// Nếu phần tử thứ i có thể là giá trị của món quà do Bob chọn, ta nhân giá trị món quà với số lần bằng số cách chọn k-1 phần tử trong n-i phần tử sau đó
        }
    }
    cout << solve;
    return 0;
}