# Assignment5
Họ và tên : Lê Văn Quý
MSSV : 24521492
### [H007] - Alpha Problem
Bài này thì ta sẽ chuyển đổi một số từ hệ thập phân sang hệ `x` phân.
``` cpp=
void Alpha(int x){
    while (n > 0){
        long long i = n % x;
        solve.push_back(i);
        n = n / x;
    }
    for ( long long j = solve.size()-1 ; j >= 0 ; j--){
        cout << solve[j];
    }
}
```
### [H006] - Word Merging
Ở bài này ta sẽ dùng stack.Khi đưa từng kí tự vào stack, kiểm tra xem kí tự được đưa vào tiếp theo có giống với kí tự trên đỉnh stack hiện tại hay không.
``` cpp=
void Solve(string s){
    stack<char> st;
    for ( auto i : s ){
        if ( !st.empty() && i == st.top() ){
            st.pop();
        }
        else {
            st.push(i);
        }
    }
    int k = st.size();
    cout << k;
}
```
### [H004] - Wood Cutting
Ở bài này ta sử dụng thuật toán tham lam, với ý tưởng ghép hai khúc từ các khúc gỗ được chia thành một khúc gỗ sao cho khúc gỗ được ghép là nhỏ nhất.
``` cpp=
void Solve(vector<long long> a) {
    if (a.size() <= 1) {
        cout << 0; 
        return;
    }
    priority_queue<long long, vector<long long>, greater<long long>> pq(a.begin(), a.end());
    long long totalcost = 0;

    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        long long cost = first + second;
        totalcost =totalcost + cost;
        pq.push(cost);
    }
    cout << totalcost;
}
```
### 
[H003] - Isosceles Triangle
Ở bài này ta sẽ sắp xếp các độ dài cạnh tam giác theo chiều tăng dần, sau đó thì sẽ tìm các cặp cạnh có độ dài bằng nhau và cuối cùng là đếm số tam giác với cặp cạnh đó.
``` cpp=
while (i < n) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        int count = j - i;
        if (count >= 3) {
            tamgiac += C(count, 3); 
        }
        if (count >= 2) {
            tamgiac += C(count, 2) * i; 
            auto vitri = lower_bound(a.begin() + j, a.end(), 2 * a[i]);
            tamgiac += C(count, 2) * (vitri - (a.begin() + j));
        }
        i = j; 
    }
```
Để tránh TLE (Time Limit Exceeded) thì ta sẽ dùng [Binary Search](https://www.geeksforgeeks.org/binary-search/) để tìm vị trí phần tử lớn nhất thỏa mãn [bất đẳng thức tam giác](https://vi.wikipedia.org/wiki/B%E1%BA%A5t_%C4%91%E1%BA%B3ng_th%E1%BB%A9c_tam_gi%C3%A1c).
### [H002] - Difference in Height
Ở bài này, ta chỉ cần tính 
$$
\sum_{1 \leq i < j \leq n} |a_i - a_j|
$$
Nháp ra một chút thì ta thấy nếu dãy a được sắp xếp thì tổng trên sẽ bằng:
$$
\sum_{1 \leq i \leq n} [i \times a_i -  ( n - i ) \times a_j]
$$
``` cpp=
void Solve(vector<int> a){
    sort(a.begin(), a.end());
    int sum = 0;
    int cong,tru;
    for ( int i = 0; i < n; i++){
        sum = sum + i * a[i] - (n - 1 - i) * a[i];
    cout << sum;
}
```
### [H001] - Tom's Currency
Ở bài này ta dùng `set` để loại bỏ các giá trị trùng lặp.
### Hashing: VQ44_FLOWERS
``` cpp= 
for( auto t : A ){
    Hash[t]++;
}
vector<int> quy;
for ( auto &T : Hash) {
    if (k > 0 && T.second > 0){
        k--;
        T.second--;
        quy.push_back(T.first);
    }
}
while( k > 0){
for ( auto &T : Hash) {
    if (k > 0 && T.second > 0){
        k--;
        T.second--;
        quy.push_back(T.first);
    }
}
}
return quy;
```
### Hashing: KiemKe
``` cpp= 
for (auto s : ids){
    Hash[s]++;
}
return Hash.size();
```