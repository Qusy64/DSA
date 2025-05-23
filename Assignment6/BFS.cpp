#include <bits/stdc++.h>

using namespace std;

vector<char> BFS(const unordered_map<char, vector<char>>& graph, char start, char end) {
    unordered_map<char, bool> visited;
    unordered_map<char, char> parent;
    queue<char> q;
    for (const auto& node : graph) {
        visited[node.first] = false;
    }
    q.push(start);
    parent[start] = '\0';
    while (!q.empty()) {
        char current = q.front();
        q.pop();
        if (graph.find(current) != graph.end()) {
            for (char neighbor : graph.at(current)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    q.push(neighbor);
                    if (neighbor == end) {
                        vector<char> path;
                        char node = end;
                        path.push_back(end);
                        while (parent[node] != start) {
                            node = parent[node];
                            path.push_back(node);
                        }
                        path.push_back(start);
                        reverse(path.begin(), path.end());
                        return path;
                    }
                }
            }
        }
    }
    return {};
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<char> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }
    unordered_map<char, vector<char>> graph;
    for (char node : nodes) {
        graph[node] = {};
    }
    unordered_map <char, bool> check;
    for (int i = 0; i < e; ++i) {
        char u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        char start, end;
        cin >> start >> end;
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
            cout << "no_path" << endl;
            continue;
        }
        vector<char> path = BFS(graph, start, end);
        if (!path.empty()) {
            for (size_t j = 0; j < path.size(); ++j) {
                if (j != 0) cout << " ";
                cout << path[j];
            }
            cout << endl;
        } else {
            cout << "no_path" << endl;
        }
    }
    return 0;
}
