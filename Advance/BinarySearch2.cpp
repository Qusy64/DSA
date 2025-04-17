#include <bits/stdc++.h>

using namespace std;

// QuickSort cho vector<pair<int,int>>, sắp xếp dành cho phần tử đầu tiên của pair
int partition(vector<pair<int, int>>& b, int low, int high) {
    int pivot = b[high].first;
    int pivot_pos = b[high].second;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (b[j].first < pivot || (b[j].first == pivot && b[j].second < pivot_pos)) {
            ++i;
            swap(b[i], b[j]);
        }
    }
    swap(b[i + 1], b[high]);
    return i + 1;
}

void quick(vector<pair<int, int>>& b, int low, int high) { 
    if (low < high) {
        int pi = partition(b, low, high);
        quick(b, low, pi - 1);
        quick(b, pi + 1, high);
    }
}

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> a(N); // Tạo vector lưu trữ giá trị và vị trí

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        a[i] = {val, i + 1};
    }

    quick(a, 0, N - 1); // QuickSort

    while (Q--) {
        string type;
        int x, y;
        cin >> type >> x >> y;
        if (x == 1){
            int q = x1(a, y);
            if (q == -1)
                cout << -1 << '\n';
            else
                cout << a[q].second << '\n';
        } else {
            int q = x2(a, y);
            if (q == -1)
                cout << -1 << '\n';
            else
                cout << a[q].second << '\n';
        }
        
    }
    return 0;
}

