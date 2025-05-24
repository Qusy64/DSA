#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* root = NULL;

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

map<int, int> observable;

void observe(Node* root) {
    if (root == NULL) return;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        Node* current = q.front().first;
        int pos = q.front().second;
        q.pop();
        if (observable.find(pos) == observable.end()) {
            observable[pos] = current->data;
        }
        if (current->right) {
            q.push({current->right, pos - 1});
        }
        if (current->left) {
            q.push({current->left, pos + 1});
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    observe(root);
    vector<int> result;
    for (auto& p : observable) {
        result.push_back(p.second);
    }
    sort(result.begin(), result.end());
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}