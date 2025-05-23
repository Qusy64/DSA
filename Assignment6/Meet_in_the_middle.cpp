#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int N, X;
 
void generate_subsums(vector<int> a, vector<int>& subsums) {
    int N = a.size();
    for (int i = 0; i < (1 << N); i++) {
        int sum = 0;
        int temp = i;
        for (int j = 0; j < N; j++) {
            if (temp % 2 == 1){
                sum = sum + a[j];  
            }
            temp /= 2;
        }
        subsums.push_back(sum);
    }
}
 
void Solve(vector<int> a){
    int mid = N / 2;
    vector<int> left( a.begin() , a.begin() + mid);
    vector<int> right( a.begin() + mid , a.end());
    vector<int> sum_left , sum_right;
    generate_subsums(left, sum_left);
    generate_subsums(right, sum_right);
    sort(sum_right.begin(), sum_right.end());
    int result = 0;
    for (int i : sum_left) {
        int count = X - i;
        auto lower = lower_bound(sum_right.begin(), sum_right.end(), count);
        auto upper = upper_bound(sum_right.begin(), sum_right.end(), count);
        result = result + (upper - lower);
    }
    cout << result;
}
 
int32_t main() {
    cin >> N >> X;
    vector<int> a(N);
    for ( int i = 0; i < N; i++){
        cin >> a[i];
    }
    Solve(a);
    return 0;
}
