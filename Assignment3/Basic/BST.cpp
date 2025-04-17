Node *lca(Node *root, int v1, int v2) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data > v1 && root->data > v2) { // Nếu root->data đều lớn hơn cả v1 và v2
        // Đệ quy để tiếp tục tìm trong cây con bên trái 
        return lca(root->left, v1, v2);
    }
    if (root->data < v1 && root->data < v2) { // Nếu root->data đều bé hơn cả v1 và v2
        // Đệ quy để tiếp tục tìm trong cây con bên phải
        return lca(root->right, v1, v2);
    }
    return root; // Trả về tổ tiên thấp nhất của v1 và v2
}
