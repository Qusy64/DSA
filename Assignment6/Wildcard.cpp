#include <bits/stdc++.h>

using namespace std;

int N, M;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<int> ids; 
};

class Trie {
    TrieNode *root;
public:
    Trie() { root = new TrieNode(); }

    void insert(const string &s, int id) {
        TrieNode* cur = root;
        for (char c : s) {
            if (!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
            cur->ids.push_back(id);
        }
    }
    vector<int> searchPrefix(const string &s) {
        TrieNode* cur = root;
        for (char c : s) {
            if (!cur->children.count(c))
                return {}; 
            cur = cur->children[c];
        }
        return cur->ids;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cin.ignore();

    vector<string> messages(N);
    unordered_map<string,int> exactCount;
    Trie prefixTrie, suffixTrie;

    for (int i = 0; i < N; i++) {
        getline(cin, messages[i]);
        exactCount[messages[i]]++;
        prefixTrie.insert(messages[i], i);
        string rev = messages[i];
        reverse(rev.begin(), rev.end());
        suffixTrie.insert(rev, i);
    }

    for (int i = 0; i < M; i++) {
        string pattern; 
        getline(cin, pattern);

        size_t star = pattern.find('*');
        if (star == string::npos) {
            cout << exactCount[pattern] << '\n';
            continue;
        }

        string pre = pattern.substr(0, star);
        string suf = pattern.substr(star + 1);

        if (pre.empty() && suf.empty()) {
            cout << N << '\n';
            continue;
        }

        vector<int> candidates;

        if (!pre.empty() && suf.empty()) {
            candidates = prefixTrie.searchPrefix(pre);
        } else if (pre.empty() && !suf.empty()) {
            string rev_suf = suf;
            reverse(rev_suf.begin(), rev_suf.end());
            candidates = suffixTrie.searchPrefix(rev_suf);
        } else {
            candidates = prefixTrie.searchPrefix(pre);
            vector<int> filtered;
            for (int idx : candidates) {
                const string &msg = messages[idx];
                if ((int)msg.size() >= (int)(pre.size() + suf.size()) &&
                    msg.compare(msg.size()-suf.size(), suf.size(), suf) == 0) {
                    filtered.push_back(idx);
                }
            }
            candidates = filtered;
        }

        cout << (int)candidates.size() << '\n';
    }

    return 0;
}