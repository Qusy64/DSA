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