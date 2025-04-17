if (root == NULL) return;  // Nếu node hiện tại là NULL, kết thúc hàm

    cout << root->data << " ";  // Xuất giá trị node hiện tại
    preOrder(root->left);  // Duyệt cây con bên trái
    preOrder(root->right); // Duyệt cây con bên phải