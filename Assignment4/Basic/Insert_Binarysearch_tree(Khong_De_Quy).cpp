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