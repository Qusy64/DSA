#include <bits/stdc++.h>
using namespace std;

int Kk(vector<string>& a, int l, int r) { //Thuật toán QuickSort
    int left = l;
    int right = r;
    string pivot = a[(l+r)/2];
    // Thực hiện đưa tất cả phần tử lớn hơn pivot về bên phải
    // Thực hiện đưa tất cả phần tử nhỏ hơn pivot về bên trái
    while ( true){
        while ( a[left] < pivot){
            left++;
        }
        while( a[right] > pivot){
            right--;
        }
        if(left <= right){
            swap(a[left], a[right]);
            left++;
            right--;
        }else break;
    }
    return left;
}
void Kiemke(vector<string>& a, int l, int r) { // Thuật toán QuickSort
    if (l < r) {
        int q = Kk(a, l, r);
        if (l < q - 1) Kiemke(a, l, q - 1);
        if (q < r) Kiemke(a, q, r);
    }
}

bool compare(const pair<string, int>& a, const pair<string, int>& b) { // Hàm cmp so sánh
    if (a.second != b.second) return a.second > b.second;
    
    string sa = a.first, sb = b.first;
    sa.erase(0, sa.find_first_not_of('0'));
    sb.erase(0, sb.find_first_not_of('0'));
    if (sa.empty()) sa = "0";
    if (sb.empty()) sb = "0";
    if (sa.size() != sb.size()) return sa.size() < sb.size();
    return sa < sb;
}
int partition(vector<pair<string, int>>& b, int l, int r) {
    auto pivot = b[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (compare(b[i], pivot)) i++;
        while (compare(pivot, b[j])) j--;
        if (i <= j) {
            swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quick(vector<pair<string, int>>& b, int l, int r) {
    if (l < r) {
        int pi = partition(b, l, r);
        quick(b, l, pi - 1);
        quick(b, pi, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;  
    vector<string> a(n); 
    vector<pair<string, int>> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Kiemke(a,0, n-1); 
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
    return 0;
}