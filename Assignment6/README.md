# Assignment6
Họ và tên : Lê Văn Quý
MSSV : 24521492
### Longest Increasing Sequence (LIS)
Bài này thì ta sẽ dùng quy hoạch động để tìm ra dãy con tăng dài nhất thỏa mãn yêu cầu bài toán.
Vector `dp` dùng để lưu độ dài của dãy con tăng dài nhất kết thúc tại vị trí `i`.
Vector `trace` dùng để lưu lại chỉ số phần tử trước đó trong dãy con tăng dài nhất kết thúc tại `i`.
``` c++
void Solve(vector<int> a){
    vector<int> dp(n,1);
    vector<int> trace(n,-1);
    int maxlen = 1, last = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
        if (maxlen < dp[i]){
            maxlen = dp[i];
            last = i;
        }
    }
    cout << maxlen << endl;
    vector<int> LIS;
    while( last != -1){
        LIS.push_back(a[last]);
        last = trace[last];
    }
    reverse(LIS.begin(), LIS.end());
    for( int i = 0; i < LIS.size(); i++){
        cout << LIS[i] << " ";
    }
}
```
### Knapsack
Bài này ta sử dụng quy hoạch động để tìm ra tổng giá trị lớn nhất có thể đạt được với túi có sức chứa n.
Vector `dp` dùng để lưu tổng giá trị lớn nhất có thể đạt được với túi có sức chứa `i`.
``` c++
void Solve(vector<int> weight, vector<int> value){
    vector<int> dp(W + 1, 0);
    for ( int i = 0; i < n; i++){
        for ( int j = W; j >= weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[W];
}
```
### Sum of Four Values
Bài này thì ta sẽ tính tất cả các tổng của hai số bất kì và lưu vào `sum_2` (lưu cả tổng và cặp số). Sau đó ta chỉ cần tìm xem trong số các tổng đó, có tổng nào khác có cộng vào bằng $X$ hay không.
``` c++
void Solve(vector<int> a){
    unordered_map<long long, vector<pair<int, int>>> sum_2;
    for (int i = 1 ; i <= N; i++){
        for (int j = i + 1 ; j <= N; j++){
            sum_2[a[i] + a[j]].emplace_back(i, j);
        }
    }
    for (int k = 1; k <= N; k++) {
        for (int l = k + 1; l <= N; l++) {
            int quy = X - (a[k] + a[l]);
            if (sum_2.count(quy)) {
                for (auto [i, j] : sum_2[quy]) {
                    if (i != k && i != l && j != k && j != l) {
                        cout << i << " " << j << " " << k << " " << l;
                        return;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}
```
### Meet in the middle
Bài này ta thực hiện chia đầu vào thành 2 nửa, sau đó tính tất cả tổng của các tập con của hai nửa rồi thực hiện tìm kiếm hai giá trị tổng cộng lại bằng $X$ giống bài `Sum of Four Value` ở trên.
``` c++
void Solve(vector<int> a){
    int mid = N / 2;
    vector<int> left( a.begin() , a.begin() + mid);
    vector<int> right( a.begin() + mid , a.end());
    vector<int> sum_left , sum_right;
    generate_subsums(left, sum_left); // Vector sum_left lưu trữ các tổng của các tập con bên trái
    generate_subsums(right, sum_right); // Vector sum_right lưu trữ các tổng của các tập con bên phải
    sort(sum_right.begin(), sum_right.end());
    int result = 0;
    for (int i : sum_left) {
        int count = X - i;
        auto lower = lower_bound(sum_right.begin(), sum_right.end(), count);
        auto upper = upper_bound(sum_right.begin(), sum_right.end(), count);
        result = result + (upper - lower);
    }
    cout << result;
}
```
### BFS
Bài này ta sử dụng thuật toán `BFS` để tìm đường đi ngắn nhất trên đồ thị.
``` c++
vector<char> BFS(const unordered_map<char, vector<char>>& graph, char start, char end) {
    unordered_map<char, bool> visited;
    unordered_map<char, char> parent;
    queue<char> q;
    for (const auto& node : graph) {
        visited[node.first] = false;
    }
    q.push(start);
    parent[start] = '\0';
    while (!q.empty()) {
        char current = q.front();
        q.pop();
        if (graph.find(current) != graph.end()) {
            for (char neighbor : graph.at(current)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    q.push(neighbor);
                    if (neighbor == end) {
                        vector<char> path;
                        char node = end;
                        path.push_back(end);
                        while (parent[node] != start) {
                            node = parent[node];
                            path.push_back(node);
                        }
                        path.push_back(start);
                        reverse(path.begin(), path.end());
                        return path;
                    }
                }
            }
        }
    }
    return {};
}
```
### DFS
Bài này ta sử dụng thuật toán `DFS` để tìm đường đi trên đồ thị.
``` c++
vector<string> DFS(const unordered_map<string, vector<string>>& Graph, const string& start, const string& end) {
    stack<string> stk;
    set<string> visited;
    unordered_map<string, string> previous;
    stk.push(start);
    previous[start] = "";
    while (!stk.empty()) {
        string u = stk.top();
        stk.pop();
        if (visited.count(u)) continue;
        visited.insert(u);
        if (u == end) {
            vector<string> path;
            for (string cur = end; cur != ""; cur = previous[cur]) {
                path.push_back(cur);
            }
            reverse(path.begin(), path.end());
            return path;
        }
        auto it = Graph.find(u);
        if (it != Graph.end()) {
            const vector<string>& neighbors = it->second;
            for (int i = (int)neighbors.size() - 1; i >= 0; i--) {
                const string& v = neighbors[i];
                if (!visited.count(v)) {
                    stk.push(v);
                    if (previous.find(v) == previous.end()) {
                        previous[v] = u;
                    }
                }
            }
        }
    }
    return {};
}
```
### ConnectedComponents
Bài này ta sẽ ứng dụng thuật toán `DFS` để tìm các máy tính kết nối trực tiếp với máy bị tấn công.
``` c++
void DFS(int u) {
    visited[u] = true;
    attacked.push_back(u); // Vector `attacked` lưu trữ những máy tính thuộc thành phần liên thông chứa đỉnh `u`
    for (auto v : Graph[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}
```
### Đồ thị vô hướng - Đếm số đỉnh cô lập
Bài này thì ta dùng Vector `Graph` để lưu trữ các đỉnh kề với đỉnh `i`.
``` c++
for( int i = 0; i < m; i++){
    if ( Graph[i] == 0){
        Vertice_alone++; // Đây là biến đếm số đỉnh cô lập
    }
}
```
### Đồ thị vô hướng - Đếm số thành phần liên thông
Bài này ta dùng thuật toán `DFS` để tìm thành phần liê thông chứa đỉnh `i`.
``` c++
void DFS(int u) {
    visited[u] = true;
    for (int v : Graph[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}
...
for (int i = 0; i < m; i++) {
    if (!visited[i]) {
        DFS(i);
        Connected_Components++; // Đây là biến đếm số thành phần liên thông
    }
}
```
### Đồ thị vô hướng - Liêt kê các đỉnh có thể tới từ đỉnh S
Bài này ta sử dụng thuật toán `DFS` để tìm các đỉnh thuộc thành phần liên thông có chứa đỉnh 0.
``` c++
void DFS(int u){
    visited[u] = true;
    for (auto v : Graph[u]){
        if (!visited[v]){
            DFS(v);
            List.push_back(v);
        }
    }
}
...
DFS(0);
```
### Đồ thị vô hướng - Kiểm tra có đường đi từ đỉnh S tới đỉnh E
Bài này ta sẽ kiểm tra xem có đường đi từ đỉnh 0 đến các đỉnh còn lại trong đồ thị hay không. Tương tự, ta sẽ dùng thuật toán `DFS` để tìm các đỉnh thuộc thành phần liên thông có chứa đỉnh 0. Sau đó in ra "CO" hoặc "KHONG" với từng điểm (từ 1 đến n).
``` c++
oid DFS(int u){
    visited[u] = true;
    for (auto v : Graph[u]){
        if (!visited[v]){
            DFS(v);
            List.push_back(v);
        }
    }
}
...
DFS(0);
for (int i = 1; i < m; i++){
    if(find(List.begin(), List.end(), i) != List.end()){
        cout << "CO\n";
    }
    else {
            cout << "KHONG\n";
    }
}
```
### Wildcard
Ở bài này ta sẽ đếm một chuỗi kí tự trong tập hợp các chuỗi kí tự xuất hiện bao nhiêu lần. Với sự xuất hiện của dấu `*`, bài toán trở nên khó hơn rất nhiều. Lúc này nếu tìm kiếm tuyến tính thì sẽ bị `Time Limit Exceeded`. Bài này có thể giải quyết bằng cấu trúc `trie` để tăng hiệu năng tìm kiếm.
``` c++
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<int> ids; 
};

class Trie {
    TrieNode *root;
public:
    Trie() { root = new TrieNode(); }

    void insert(const string &s, int id) {
        TrieNode* cur = root;
        for (char c : s) {
            if (!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
            cur->ids.push_back(id);
        }
    }
    vector<int> searchPrefix(const string &s) {
        TrieNode* cur = root;
        for (char c : s) {
            if (!cur->children.count(c))
                return {}; 
            cur = cur->children[c];
        }
        return cur->ids;
    }
};
```