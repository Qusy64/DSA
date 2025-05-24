#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];

    stack<pair<int,int>> st;  
    long long result = 0;

    for (int i = 0; i < N; i++) {
        int cur = h[i];
        int cnt = 1;
        while (!st.empty() && st.top().first < cur) {
            result = result + st.top().second;
            st.pop();
        }
        if (!st.empty() && st.top().first == cur) {
            result = result + st.top().second;  
            cnt = st.top().second + 1;
            st.pop();
        }
        if (!st.empty()) {
            result++;
        }
        st.push({cur, cnt});
    }

    cout << result;
    return 0;
}
