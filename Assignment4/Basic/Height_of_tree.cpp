if (root == NULL) return 0;
int left = height(root->left);
int right = height(root->right);
return (left > right ? left : right) + 1;


