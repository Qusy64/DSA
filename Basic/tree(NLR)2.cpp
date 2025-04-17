void preOrder(Node *root) {
    if (root == nullptr) return;  // Nếu cây trống, không làm gì
    stack<Node*> s;  // Khởi tạo stack
    s.push(root);  // Đẩy node gốc vào stack
    while (!s.empty()) {
        Node* node = s.top();  // Lấy node ở đỉnh stack
        s.pop();  // Pop node khỏi stack
        cout << node->data << " ";  // Xuất giá trị của node
        if (node->right) { // Đẩy cây con phải vào ngăn xếp
            s.push(node->right);
        }
        if (node->left) { // Đẩy cây con trái vào ngăn xếp
            s.push(node->left);
        }
    }
}