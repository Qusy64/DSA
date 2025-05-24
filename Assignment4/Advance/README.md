# Assignment4
Họ và tên : Lê Văn Quý
MSSV : 24521492
### Kết bạn
Ở bài này thì ta sẽ tạo 2 vector `next` và `prev` để lưu trữ người đứng bên phải và người đứng bên trái của người có số thứ tự `i`.
``` c++
for(int i = 1; i <= n; ++i) {
    next[i] = (i % n) + 1;          
    prev[(i % n) + 1] = i;          
}
// next[n] = 1 và prev[1] = n
for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x == y) {
        continue;
    }
    int px = prev[x], nx = next[x];
    next[px] = nx;
    prev[nx] = px;
    int ny = next[y];
    next[y] = x;
    prev[x] = y;
    next[x] = ny;
    prev[ny] = x;
}
```

### HuffmanCoding
Ở bài này ta sẽ nén văn bản bằng phương pháp nén [Huffman](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/). 
``` c++
void buildCode(Node* node, string code, unordered_map<char, string>& codeMap) {
    if (!node) return;
    if (node->left == nullptr && node->right == nullptr) {
        if (code == "") code = "0"; 
        codeMap[node->ch] = code;
        return;
    }
    buildCode(node->left, code + "0", codeMap);
    buildCode(node->right, code + "1", codeMap);
}
```

### Hòa Nhạc
Ở bài này ta sẽ cần đếm số cặp có thể "nhìn thấy" nhau. Vì N khá lớn ($1 \leq N \leq 10^6$) nên nếu dùng 2 vòng for thì rất dễ bị `TLE`. Bài này ta có thể xử lý với [Stack](https://wiki.vnoi.info/vi/algo/data-structures/Stack) như sau.
``` c++
stack<pair<int,int>> st; 
// pair: (chiều cao, số lượng người có cùng chiều cao liên tiếp)
...
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
```

### Tree: levelOrder Traversal - Duyệt cây theo chiều rộng
Ở bài này thì ta sẽ cài đặt hàm `void levelOrder(Node* root)`.
``` c++
if (root == NULL) {
    return;
}
queue<Node*> q;
q.push(root);
while (!q.empty()) {
    Node* current = q.front();
    q.pop();
    cout << current->data << " ";
    if (current->left) {
        q.push(current->left);
    }
    if (current->right) {
        q.push(current->right);
    }
}
```
