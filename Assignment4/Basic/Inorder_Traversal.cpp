if (root == NULL){ 
    return;
}
inOrder(root->left);           
cout << root->data << " ";   
inOrder(root->right);