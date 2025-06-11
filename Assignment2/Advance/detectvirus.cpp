#include <bits/stdc++.h>

using namespace std;

vector<int> LPS(string &T) { // Tạo mảng lps (Longest Prefix Suffix) để lưu độ dài chuỗi vừa là tiền tố vừa là hậu tố
    int m = T.size();
    vector<int> lps(m, 0); // Tạo mảng vector lps toàn phần tử 0
    int len = 0, i = 1;// Đặt len là độ dài chuỗi vừa là tiền tố vừa là hậu tố, i số thứ tự phần tử để xét
    while (i < m) {
        if (T[i] == T[len]) { // Thực hiện so sánh để xem phần tử tiếp theo của tiền tố có bằng phần tử tiếp theo của hậu tố không
            len++;
            lps[i] = len; // Nếu có thì độ dài tiền tố bằng hậu tố lớn nhất của chuỗi kí tự sẽ là len
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Nếu T[i] khác với T[len] thì ta sẽ đặt len = lps[len - 1] để tìm tiền tố ngắn hơn bằng với hậu tố
            }
            // Khi không còn tiền tố nào ngắn hơn nữa thì lps[i] = 0
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps; // Kết quả trả về của hàm này sẽ là mảng ghi lại các độ dài chuỗi dài nhất vừa là tiền tố vừa là hậu tố
}

void KMP(string &s, string &T) { // Sử dụng thuật toán KMP
    int n = s.size(), m = T.size();
    vector<int> lps = LPS(T);
    vector<int> solve;
    int i = 0, j = 0;
    while (i < n) {
        if (s[i] == T[j]) { // Nếu s[i] = T[j] thì tăng i và j
            i++;
            j++;
        }
        if (j == m) {// Khi nào j = m thì lúc này ta tìm được một chuỗi T trong s, ta ghi kết quả vào mảng solve
            solve.push_back(i - j + 1);
            j = lps[j - 1]; // Đặt lại j = lps[j - 1] để tìm chuỗi tiếp theo
        } else if (i < n && s[i] != T[j]) { // Nếu không rơi vào hai trường hợp trên thì khi đó
            if (j != 0) { // Nếu j khác 0, ta đặt j = lps[j - 1] rồi so sánh lại với s[i] giúp thuật toán tối ưu
                j = lps[j - 1];
            }
            else {// Nếu j = 0, bỏ qua và tăng i lên 1
                i++;
            }
        }
    }
    int k = solve.size();
    if (k != 0) { // Nếu kích thước mảng solve khác 0, tức là tồn tại chuỗi T trong s thì ta ghi YES
        cout << "YES\n";
        for (auto &i : solve) { // Viết từng vị trí xuất hiện chuỗi T
            cout << i << " ";
        }
        cout << endl;
    } else { // Còn không ghi NO
        cout << "NO";
    }
}

int main() {
    string s, T;
    cin >> s;
    cin >> T;
    KMP(s,T);

    return 0;
}