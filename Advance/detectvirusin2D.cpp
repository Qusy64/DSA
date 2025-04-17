#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    vector<string> patterns(Q); // Lưu trữ các chuỗi virus cần tìm kiếm
    unordered_map<int, unordered_set<string>> substr_by_length; // Một map với khóa là độ dài chuỗi và giá trị là một set chứa tất cả các chuỗi con có độ dài đó 
    vector<pair<int, string>> pattern_list; //Một danh sách độ dài chuỗi của các chuỗi cần tìm.

    int max_len = 0;

    for (int i = 0; i < Q; ++i) {
        cin >> patterns[i];
        int len = patterns[i].size();
        max_len = max(max_len, len); // độ dài chuỗi lớn nhất trong các chuỗi cần tìm
        pattern_list.emplace_back(len, patterns[i]);
    }

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

    return 0;
}
