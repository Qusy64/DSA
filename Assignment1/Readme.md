# [IT003.P21.CTTN.2] Assigment1

## Lê Văn Quý
 
## MSSV:24521492

#### Bài 1. VQ44_FLOWERS

Ở bài đầu tiền thì ta sẽ dùng cấu trúc **unordered_map** để lưu số lần xuất hiện của các số trong dãy gồm n số nguyên ( mỗi màu có bao nhiêu bóng đèn có màu đó ). Sau đó chọn ra mỗi màu một bóng đèn để đạt được kết quả nhiều màu nhất, khi số màu được chọn chưa đủ số k được yêu cầu thì sẽ chọn ngẫu nhiên những bóng đèn còn lại.

``` c++
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
```
#### Bài 2. Point2D

Ở bài này thì ta sẽ sắp xếp các điểm theo chiều tăng dần của x, nếu các điểm có giá trị x bằng nhau thì sẽ sắp xếp theo chiều giảm dần của y. Ta sẽ sử dụng hàm sort với hàm so sánh **cmp**.
``` c++
#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    for ( int i = 0; i <n ; i++)
        cout << a[i].first <<" "<< a[i].second << "\n";
    return 0;
}
```
#### Bài 3. VS14_Gifts

Ở bài này ta sẽ sử dụng thuật toán **Hai con trỏ** để xử lý nhằm tính được tổng hai món quà có giá trị lớn nhất có thể trong tầm khả năng chi trả.
``` c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tongqua(int n, int x, vector<int>& a) {
    sort(a.begin(), a.end()); 
    int l = 0,r = n -1;
    int tong = -1;
    while (l< r) {
        int s = a[l] + a[r];
        if (s >x) {
            r--; 
        } else {
            tong = max(tong,s); 
            l++; 
        }
    }
    return tong;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << tongqua(n, x, a) << endl;
    return 0;
}
```
#### Bài 4. PasswordStrength

Với để bài dài nhiều dữ kiện, không dễ dàng để có thể code mà không có sai sót. Mặc dù có nhờ sự hỗ trợ khá nhiều từ ChatGPT.
``` c++
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isSpecialChar(char c) {
    string specialChars = "!@#$%^&*?_~";
    return specialChars.find(c) != string::npos;
}

bool isInvalidChar(char c) {
    string invalidChars = "./\\'\",";
    return invalidChars.find(c) != string::npos;
}

string evaluatePasswordStrength(const string& password) {
    int length = password.length();
    if (length < 8) return "KhongHopLe";
    
    int numUpper = 0, numNumbers = 0, numSymbols = 0;
    for (char c : password) {
        if (isupper(c)) numUpper++;
        else if (isdigit(c)) numNumbers++;
        else if (isSpecialChar(c)) numSymbols++;
        else if (isInvalidChar(c)) return "KhongHopLe";
    }
    
    int numExcess = length - 8;
    int score = 40 + (numExcess * 3) + (numUpper * 4) + (numNumbers * 5) + (numSymbols * 5);
    
    if (numUpper > 0 && numNumbers > 0 && numSymbols > 0) score += 25;
    else if ((numUpper > 0 && numNumbers > 0) || (numUpper > 0 && numSymbols > 0) || (numNumbers > 0 && numSymbols > 0)) score += 15;
    
    if (numUpper == 0 && numNumbers == 0 && numSymbols == 0) score -= 15;
    if (numUpper == 0 && numSymbols == 0 && numNumbers == length) score -= 35;
    
    if (score < 50) return "Yeu";
    else if (score < 75) return "Vua";
    else if (score < 100) return "Manh";
    else return "RatManh";
}

int main() {
    string password;
    cin >> password;
    cout << evaluatePasswordStrength(password) << endl;
    return 0;
}
```
#### Bài 5. CeaserCipher

Bài này cho ta biết biểu thức toán học trong mã hóa Ceaser
$$ 
E(x)=(x+k) mod 26
$$
Việc của chúng ta chỉ là mã hóa theo mô tả của đề bài
``` c++
#include <iostream>
#include <string>
using namespace std;

string caesar(int k, string s) {
    k = k % 26;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = 'A' + (s[i] - 'A' + k) % 26;
        }
    }
    return s;
}

int main() {
    int k;
    string s;
    cin >> k; 
    cin.ignore(); 
    getline(cin, s); 
    string cipher = caesar(k, s);
    cout << cipher << endl;
    
    return 0;
}
```
#### Bài 6. ReversingEncryption
 
Ở bài này thì ta sẽ giải mã thuật toán mã hóa để có được chuỗi kí tự ban đầu. Bằng cách đảo ngược lần lượt các chuỗi có độ dài từ 1 đến i với i lần lượt là các ước tăng dần của n.
``` c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string decrypt( string a) {
    int n = a.length();
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            reverse(a.begin(), a.begin() + i);
        }
    }
    return a;
}

int main() {
    string a;
    cin >>a;
    string q = decrypt(a);
    cout << q << endl;
    
    return 0;
}
```
#### Bài 7. Messages

Ở bài này ta sẽ tìm xâu con chung dài nhất ở phần cuối chuỗi Sb và phần đầu của chuỗi Se.
``` c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string Sb, Se;
    cin >> Sb >> Se;
    int n = Sb.length();
    int m = Se.length();
    int max = 0;
    for (int i = 1; i <= min(n, m); i++) {
        if (Sb.substr(n - i, i) == Se.substr(0, i)) {
            max = i;
        }
    }
    int s = Sb.length() + Se.length() - max;
    cout << s<<endl;
    cout << Sb << Se.substr(max);
    return 0;
}
```
#### Bài 8. Binary_Search1

Đề bài yêu cầu rất rõ là sử dụng thuật toán tìm kiếm nhị phân.
``` c++
#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n;  
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    cin >> x;  
    int l = 0, r = n - 1, mid, duyet = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        duyet++; 
        if (a[mid] == x) {
            cout << mid << endl; 
            cout << count << endl; 
            return;
        } 
        else if (a[mid] < x) {
            l = mid + 1; 
        } 
        else {
            r = mid - 1;  
        }
    }
    cout << -1 << endl;
    
    return 0;
}
```
#### Bài 9. Binary_Search2
 
Ta sẽ làm như đề bài yêu cầu
``` c++
#include <iostream>
#include <string>
using namespace std;

void binarysearch(string a[], int n, string x) {
    int l = 0, r = n -1, mid, duyet = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        duyet++;  
        if (a[mid] == x) {
            cout << mid << endl;  
            cout << duyet << endl; 
            return;
        } 
        else if (a[mid] < x) {
            l = mid + 1;  
        } 
        else {
            r = mid - 1; 
        }
    }
    cout << -1 << endl;  
}

int main() {
    int n;
    cin >> n;  
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }
    string x;
    cin >> x; 
    binarysearch(a, n, x);  
    return 0;
}
```
#### Bài 10. Linear_Search1

Ta vẫn làm như đề bài yêu cầu
``` c++
#include <iostream>
using namespace std;

void linear_search(int a[], int n, int x) {
    int forward_pos = -1, backward_pos = -1;
    int forward_count = 0, backward_count = 0;
    for (int i = 0; i < n; i++) {
        forward_count++;
        if (a[i] == x) {
            forward_pos = i;
            cout << forward_pos << endl;  
            cout << forward_count << endl;  
            break;
        }
    }  
    if (forward_pos != -1) {
        for (int i = n - 1; i >= 0; i--) {
            backward_count++;
            if (a[i] == x) {
                backward_pos = n -1 - i;
                cout << backward_pos << endl;  
                cout << backward_count << endl;
                break; 
            }
        }
    }
    if (forward_pos == -1) {
        cout << -1 << endl;  
    } 
} 
```
#### Bài 11. Linear_Search2

Vẫn như vậy, ta lại làm như đề bài yêu cầu
``` c++
#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n;  
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;  
    int s = 0;  
    int tong = 0; 
    for (int i = 0; i < n; i++){
        if(a[i] == x)
            s++;       
    }
    cout << s << endl;
    for (int i = 0; i < n; i++) {
        tong++;  
        if (a[i] == x) {
            cout << i << " " << tong << endl;  
        }
    }
    
    return 0;
}
```
#### Bài 12. Linear_Search3

Ở bài toán này, để in ra n số nguyên tương ứng với MEXᵢ ta sẽ đặt MEX = 0 sau đó lần lượt với mỗi giá trị i ta sẽ tìm giá trị MEX nhỏ nhất chưa xuất hiện tính đến phần tử i
``` c++
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> seen;  
    int mex = 0;  
    for (int i = 0; i < n; i++) {
        seen.insert(a[i]);  
        while (seen.find(mex) != seen.end()) {
            mex++;  
        }
        cout << mex << " ";
    }
    
    return 0;
}
```
#### Bài 13. Linear_Search5

Ở bài toán này ta nhận thấy rằng nếu n >= 4 thì tổng trọng số hay dãy lớn nhất sẽ có giá trị là 
$ a[n-1] + a[n-2] - a[0] - a[1] $
Nếu n <= 1 thì trọng số sẽ bằng 0
``` c++
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int trongso = 0;
        sort(a, a + n);
        if( n>=4)
            trongso= a[n-1] + a[n-2] - a[0] -a[1];
        else if( n >1)
            trongso = a[n-1]- a[0];
        cout << trongso << endl;
    }

    return 0;
}
```
#### Bài 14. VW05p_Enrichement

Ở bài này thì ý tưởng không có gì đặc biệt, ta sẽ tính tổng các giá trị của các ô vuông 3x3, sau đó chọn ra giá trị nhỏ nhất.
``` c++
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
```
