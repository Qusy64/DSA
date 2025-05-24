if (root == NULL) {
    return new Node(data);
}
if (data <= root->data) {
    root->left = insert(root->left, data);
} else {
    root->right = insert(root->right, data);
}
return root;