#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int minsum = INT_MAX;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            int sum = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    sum += a[x][y];
                }
            }
            minsum = min(minsum, sum);
        }
    }
    cout << minsum << endl;

    return 0;
}