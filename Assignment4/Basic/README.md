# Assignment4
Họ và tên : Lê Văn Quý
MSSV : 24521492
### Tree: Hieght of tree
Ở bài này thì ta cài đặt hàm `height(Node* root)`.
``` c++
if (root == NULL) {
    return 0;
}
int left = height(root->left);
int right = height(root->right);
return (left > right ? left : right) + 1;
```

### Binary Search Tree: Insert (không dùng đệ quy)
Ở bài này ta cài đặt hàm `Node * insert(Node * root, int data)` nhưng không được dùng đệ quy.
``` c++
Node* newNode = new Node(data);
if (root == 0){
    return newNode;
}
Node* current = root;
Node* parent = 0;

while (current != 0) {
    parent = current;
    if (data <= current->data){
        current = current->left;
    }
    else{
        current = current->right;
    }
}
if (data <= parent->data){
    parent->left = newNode;
}
else{
    parent->right = newNode;
}

return root;
```

### Binary Search Tree: Insert
Ở bài này ta cài đặt hàm `Node * insert(Node * root, int data)` và được phép sử dụng đệ quy.
``` c++
if (root == NULL) {
    return new Node(data);
}
if (data <= root->data) {
    root->left = insert(root->left, data);
} else {
    root->right = insert(root->right, data);
}
return root;
```

### Tree: levelOrder Traversal - Duyệt cây BST theo chiều rộng
Ở bài này ta cài đặt hàm `void levelOrder(Node* root)`.
``` c++
if (root == nullptr){
    return;
}
queue<Node*> q;
q.push(root);
while (!q.empty()) {
    Node* current = q.front();
    q.pop();
    cout << current->data << " ";
    if (current->left != nullptr){
        q.push(current->left);
    }
    if (current->right != nullptr){
        q.push(current->right);
    }
}
```

### Tree: Inorder Traversal (LNR) II - Duyệt cây BST theo LNR không đệ quy
Ở bài này ta cài đặt hàm `void inOrder(Node* root)` nhưng không được sử dụng đệ quy.
``` c++
stack<Node*> st;  
Node* current = root;
while (current != nullptr || !st.empty()) {
    while (current != nullptr) {
        st.push(current);
        current = current->left;
    }
    current = st.top();
    st.pop();
    cout << current->data << " ";
    current = current->right;
}
```

### Tree: Inorder Traversal (LNR) - Duyệt cây BST theo LNR
Ở bài này ta cài đặt hàm `void inOrder(Node* root)` và được phép sử dụng đệ quy.
``` c++
if (root == NULL){ 
    return;
}
inOrder(root->left);           
cout << root->data << " ";   
inOrder(root->right);
```

### Tree: Postorder Traversal (LRN) II - Duyệt cây BST theo LRN không đệ quy
Ở bài này ta cài đặt hàm `void postOrder(Node* root)` nhưng không sử dụng đệ quy.
``` c++
if (root == NULL) {
    return;
}
stack<Node*> s1, s2;
s1.push(root);
while (!s1.empty()) {
    Node* curr = s1.top();
    s1.pop();
    s2.push(curr);
    if (curr->left) {
        s1.push(curr->left);
    }
    if (curr->right) {
        s1.push(curr->right);
    }
}
while (!s2.empty()) {
    cout << s2.top()->data << " ";
    s2.pop();
}
```

### Tree: Postorder Traversal (LRN) - Duyệt cây BST theo LRN
Ở bài này ta cài đặt hàm `void postOrder(Node* root)` và được phép sử dụng đệ quy.
``` c++
if (root == nullptr){
    return;
}
postOrder(root->left);   
postOrder(root->right);  
cout << root->data << " ";
```

### Binary Search Tree: Nút chung gần nhất
Đây là 1 bài trên [Hackerrank](https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem). Ở bài này thì ta sẽ cài đặt hàm `Node *lca(Node *root, int v1,int v2)`.
``` c++
while (root != 0) {
    if (v1 < root->data && v2 < root->data) {
        root = root->left;
    } 
    else if (v1 > root->data && v2 > root->data) {
        root = root->right;
    } 
    else {
        return root;
    }
}
return 0;
```

### Tree: Top view
Ở bài này ta sẽ xử lý vấn đề quan sát cây nhị phân từ một phía nhất định. Ta sẽ chia cây thành các tọa độ theo hướng nhìn. 

- Ví dụ: Quan sát từ gốc của cây nhị phân, ta sẽ đặt tọa độ gốc này là 0. Mỗi `node` bên phải sẽ có tọa độ giảm đi 1, mỗi `node` bên trái thì sẽ có tọa độ tăng lên 1. 

Lúc này, ta chỉ cần in ra các `node` đầu tiên được nhìn thấy với mỗi tọa độ của cây nhị phân.
``` c++
map<int, int> observable; 
// observable là một map chứa các quả xoài (node có thể nhìn thấy)
void observe(Node* root) {
    if (root == NULL) return;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        Node* current = q.front().first;
        int pos = q.front().second;
        q.pop();
        if (observable.find(pos) == observable.end()) {
            observable[pos] = current->data;
        }
        if (current->right) {
            q.push({current->right, pos - 1});
        }
        if (current->left) {
            q.push({current->left, pos + 1});
        }
    }
}
```
