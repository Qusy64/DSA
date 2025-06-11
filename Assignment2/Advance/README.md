---
title: IT003.P21.CTTN.2.Assignment2

---

# IT003.P21.CTTN.2.Assignment2
 Họ và tên:Lê Văn Quý
MSSV: 24521492
## MaxMinSum:
Đầu tiên ta sẽ sắp xếp tăng dần giá trị các món quà. Sau đó ta tính số lần món quà có giá trị aᵢ được Alice chọn ( là số lớn nhất trong dãy k phần tử ) và số lần món quà có giá trị aᵢ được Bob chọn ( là số bé nhất trong dãy k phần tử )
- Ta thấy số lần aᵢ được Alice chọn là : **C(i−1,k−1)**  tương ứng với số cách chọn k-1 phần tử bé hơn aᵢ
- Ta thấy số lần aᵢ được Bob chon là : **C(n-i,k−1)** tương ứng với số cách chọn k-1 phần tử lớn hơn aᵢ
``` c++
for ( long long i = 1; i <= n ; i++){// Ta xét qua các phần tử mảng a[]
        if (i - 1 >= k - 1){
            solve = (solve + (a[i] * C(i - 1, k - 1))) % p;// Nếu phần tử thứ i có thể là giá trị của món quà do Alice chọn, ta nhân giá trị món quà với số lần bằng số cách chọn k-1 phần tử trong i-1 phần tử trước đó
        }
        if ( n - i >= k - 1){
            solve = (solve - (a[i] * C(n - i, k - 1))) % p;// Nếu phần tử thứ i có thể là giá trị của món quà do Bob chọn, ta nhân giá trị món quà với số lần bằng số cách chọn k-1 phần tử trong n-i phần tử sau đó
        }
    }
```
Ý tưởng ban đầu mình định là đặt biến `add` là tổng giá trị aᵢ được Alice chọn, `sub` là tổng giá trị được Bob chọn. Nhưng không hiểu vì sao đặt kiểu đó lại không AC :< 
## khangtd.Login1:
Bài này ta tạo ``map <string, string> user;`` để lưu các giá trị password tương ứng với user. Sau đó ta kiểm tra xem Q có trong map hay chưa.
## khangtd.Login2:
Bài này tương tự bài trên nhưng ta dùng ``map <string, vector <string>> user;`` để lưu các giá trị password vì đề bài bắt ta in ra các giá trị password theo thời gian nhập vào.
## khangtd.DetectVirus:
## khangtd.DetectVirus2:
Cả hai bài này đều yêu cầu giống nhau, chỉ khác là ở bài khangtd.DetectVirus2 thì |S|, |T| có thể lên đến $10^6$. Nên ta sẽ sử dụng thuật toán [KMP](https://youtu.be/JoF0Z7nVSrA?si=5ZgPSiRhKVxRVyRm).
## Linear Search 4:
Gọi `k1` là số môn học chỉ có 1 người giỏi
Gọi `k2` là số môn học có 2 người giỏi trở lên
Khi đó ta sẽ có cách chia 2 đội thỏa mãn yêu cầu đề bài khi và chỉ khi:
$$ k_1 + k_2 \leq 2k \leq k_1 + 2k_2 $$

## Vượt mức Pickleball v2:
Ta tìm giá trị trung vị bằng cách
``` c++
int timtrungvi( int n ){ 
    int trungvi = 0;
    for ( int i = 0; i < 201; i++){
        trungvi = trungvi + dem[i]; 
        if ( trungvi >= n){ 
            return i;
        }
    }
    return -1;
}
```
## Bốn ông điên:
Đề bảo là " Mảng có trật tự " nghĩa là ta sẽ đi tìm số lần swap để mảng tăng dần hoặc giảm dần sao cho con số tìm được là nhỏ nhất.
Code của mình có phần chưa đúng nếu như dãy nhập vào có các phần tử trùng nhau, nhưng vì test sinh ít nên mình đã AC :>
Tổng quát thì bài này ta dùng [Cycle Detection](https://www.geeksforgeeks.org/detect-cycle-undirected-graph/).
## Huấn luyện chuột:
Với bài toán này, ta sẽ đếm số dãy không giảm có độ dài N.
Dựa trên bài toán [chia kẹo Euler](https://viblo.asia/p/bai-toan-chia-keo-euler-L4x5xqvqKBM), ta có thể dễ dàng có được công thức tính số dãy nói trên. Nhưng lúc này ta có một vấn đề khác đó là $$ aᵢ \leq 10^{10} $$
Cho nên ta sẽ dùng định lí [Lucas](https://wiki.vnoi.info/translate/he/Lucas-theorem) để tính.
``` c++
// Biểu diễn n trong cơ số p
vector<int> getRepresentation(int n, int p) { 
    vector<int> res;
    while (n > 0) {
        res.push_back(n % p);
        n /= p; 
    }
    return res;
}
```




