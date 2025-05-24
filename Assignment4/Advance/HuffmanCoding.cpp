#include<bits/stdc++.h>

using namespace std;

struct Node {
    char ch;              
    int freq;             
    Node* left;           
    Node* right;          
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
    Node(int f, Node* l, Node* r) {
        ch = 0;
        freq = f;
        left = l;
        right = r;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCode(Node* node, string code, unordered_map<char, string>& codeMap) {
    if (!node) return;
    if (node->left == nullptr && node->right == nullptr) {
        if (code == "") code = "0"; 
        codeMap[node->ch] = code;
        return;
    }
    buildCode(node->left, code + "0", codeMap);
    buildCode(node->right, code + "1", codeMap);
}

int main() {
    int n;              
    string text;        
    cin >> n;
    cin.ignore();       
    getline(cin, text); 
    unordered_map<char, int> freqMap;
    for (char c : text) {
        freqMap[c]++;
    }
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto it : freqMap) {
        pq.push(new Node(it.first, it.second));
    }
    if (pq.size() == 1) {
        Node* only = pq.top();
        cout << only->freq << endl; 
        return 0;
    }
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();   
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node(left->freq + right->freq, left, right);
        pq.push(parent); 
    }
    Node* root = pq.top();
    unordered_map<char, string> codeMap;
    buildCode(root, "", codeMap);
    int totalBits = 0;
    for (char c : text) {
        totalBits += codeMap[c].length();
    }
    cout << totalBits << endl;

    return 0;
}
