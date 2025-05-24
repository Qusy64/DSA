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