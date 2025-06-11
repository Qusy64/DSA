#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[a[i]]++;
    }
    while (b.size()!= k ){
        for (auto i = map.begin(); i != map.end(); i++) {
            if( i->second > 0){
             b.push_back(i->first);
             i->second--;
            }
            if ( b.size()== k ) break;
        }
    }
    for(int i = 0; i < k; i++ )
        cout << b[i] << " ";

    return 0;
}
