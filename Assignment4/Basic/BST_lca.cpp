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