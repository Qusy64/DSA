#include <bits/stdc++.h>

using namespace std;

vector<string> DFS(const unordered_map<string, vector<string>>& Graph, const string& start, const string& end) {
    stack<string> stk;
    set<string> visited;
    unordered_map<string, string> previous;  // lưu đỉnh trước đó trên đường đi

    stk.push(start);
    previous[start] = "";

    while (!stk.empty()) {
        string u = stk.top();
        stk.pop();

        if (visited.count(u)) continue;
        visited.insert(u);

        if (u == end) {
            // Truy vết đường đi
            vector<string> path;
            for (string cur = end; cur != ""; cur = previous[cur]) {
                path.push_back(cur);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Duyệt các đỉnh kề theo thứ tự ngược để stack lấy ra theo đúng thứ tự
        auto it = Graph.find(u);
        if (it != Graph.end()) {
            const vector<string>& neighbors = it->second;
            for (int i = (int)neighbors.size() - 1; i >= 0; i--) {
                const string& v = neighbors[i];
                if (!visited.count(v)) {
                    stk.push(v);
                    if (previous.find(v) == previous.end()) {
                        previous[v] = u;
                    }
                }
            }
        }
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    vector<string> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
    }
    unordered_map<string, vector<string>> Graph;
    for (int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string start, end;
        cin >> start >> end;
        vector<string> path = DFS(Graph, start, end);
        if (path.empty()) {
            cout << "no_path\n";
        } else {
            for (size_t j = 0; j < path.size(); j++) {
                if (j > 0) cout << " ";
                cout << path[j];
            }
            cout << "\n";
        }
    }

    return 0;
}