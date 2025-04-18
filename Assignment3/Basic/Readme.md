# Assignment3
Họ và tên : Lê Văn Quý
MSSV : 24521492
### BST
Bài này ta sẽ sử dụng [đệ quy](https://wiki.vnoi.info/algo/basic/backtracking.md) để tìm ra tổ tiên thấp nhất của v1 và v2
``` cpp=
Node *lca(Node *root, int v1, int v2) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data > v1 && root->data > v2) { // Nếu root->data đều lớn hơn cả v1 và v2
        // Đệ quy để tiếp tục tìm trong cây con bên trái 
        return lca(root->left, v1, v2);
    }
    if (root->data < v1 && root->data < v2) { // Nếu root->data đều bé hơn cả v1 và v2
        // Đệ quy để tiếp tục tìm trong cây con bên phải
        return lca(root->right, v1, v2);
    }
    return root; // Trả về tổ tiên thấp nhất của v1 và v2
}
```
### Dectobin
Chuyển đổi số từ hệ thập phân sang hệ nhị phân
``` cpp=
while(x > 0){
        int i = x % 2;
        a.push_back(i); // Ghi nhận số dư khi chia x cho 2
        x = x / 2; 
    }
    for ( int i = (int)a.size() - 1; i >= 0; i--){ // Duyệt từ phần tử số dư cuối cùng 
        cout << a[i];
    }
```
### FindNode
Khi hai danh sách liên kết có Node chung thì:
- Từ Node đó đến các Node tiếp theo của hai danh sách hoàn toàn giống nhau

$\Rightarrow$ So sánh song song sao cho hai Node cuối của hai danh sách song song với nhau

(Tôi nhận ra điều này sau khi dùng [ChatGPT](https://chatgpt.com/) :>)
``` cpp=
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1 == temp2) {
            return temp1;  // Trả về nút chung
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return nullptr;  // Nếu không tìm thấy nút chung, trả về nullptr
}
```
### Latex
Bài này ta sẽ kiểm tra các dấu "Đóng" có đóng đúng dấu "Mở" không?
``` cpp=
for (auto &i : s){
        if (i == '{' || i == '(' || i == '[') { // Duyệt qua các dấu mở
            stk.push_back(i); 
        }
        else if (i == '}' || i == ')' || i == ']') { // Duyệt qua các dấu đóng
            if (stk.empty()) { // Nếu không có dấu mở mà lại có dấu đóng, xuất ra 0
                cout << '0'; 
                return 0;
            }
            char top = stk.back();
            stk.pop_back();  
            if ((i == '}' && top != '{') || (i == ')' && top != '(') || (i == ']' && top != '[')) { // Nếu các dấu đóng mở không trùng khớp với nhau
                cout << '0';  
                return 0;
            }
        }
    }
```
### Linked-List-Insertion
Ta sẽ chú trọng phần tìm vị trí chèn cho danh sách liên kết
``` cpp=
while (current->next != nullptr && current->next->data < x) { // Duyệt đến khi tìm được node có giá trị lớn hơn hoặc bằng x
        current = current->next; 
    }
```
### Linked-List-Merge
Thực hiện trộn hai danh sách liên kết
``` cpp=
while (head_list1 != nullptr && head_list2 != nullptr) { // So sánh cái nào nhỏ hơn thì đưa vào danh sách mới
        if (head_list1->data <= head_list2->data) { 
            tail->next = head_list1;
            head_list1 = head_list1->next;
        } else {
            tail->next = head_list2;
            head_list2 = head_list2->next;
        }
        tail = tail->next;
    }
    // Trộn tiếp phần dư còn lại của danh sách
    if (head_list1 != nullptr) { 
        tail->next = head_list1;
    } else {
        tail->next = head_list2;
    }
```
### Linked-List-NhapDaThuc
Bài này chúng ta sẽ cần hàm ``Nhap()`` và hàm ``Xuat()``. Phân đáng chú ý nhất chắc là đoạn chung ta xử lý hiển thị số ( Hiển thị phần thập phân )
``` cpp=
stringstream ss;
ss << fixed << setprecision(2) << abs_heso;
string val = ss.str();
while (!val.empty() && val.back() == '0') val.pop_back();
if (!val.empty() && val.back() == '.') val.pop_back();
cout << val;
```
### Linked-List-Reverse
Ta sẽ thay đổi phần ``->next`` của mỗi Node trỏ đến Node trước đó.
``` cpp=
void reverseLinkedList(SinglyLinkedList* llist) { // Đảo ngược danh sách liên kết
    SinglyLinkedListNode* prev = 0; // Tạo con trỏ prev trỏ đến nullptr
    SinglyLinkedListNode* curr = llist->head; // Tạo con trỏ curr trỏ đến đầu danh sách
    while (curr != 0) { // Duyệt từ Node đầu tiên đến Node cuối cùng
        SinglyLinkedListNode* next_node = curr->next; 
        curr->next = prev; // Thay vì đến Node tiếp theo,ta sẽ đảo con trỏ trỏ đến Node trước đó
        // Di chuyển con trỏ prev và curr
        prev = curr;  
        curr = next_node;
    }
    // Sau khi kết thúc vòng lặp while, prev lúc này trỏ đến Node cuối của danh sách liên kết
    llist->head = prev; // Gán đầu danh sách đến Node cuối của danh sách ban đầu
}
```
### tree(NLR) 
Ở bài này ta sẽ duyệt cây theo thứ tự tiền tự ( Node → Left → Right.)
``` cpp= 
if (root == NULL) return;  // Nếu node hiện tại là NULL, kết thúc hàm
cout << root->data << " ";  // Xuất giá trị node hiện tại
preOrder(root->left);  // Duyệt cây con bên trái
preOrder(root->right); // Duyệt cây con bên phải
```
Bài số 2 ta không sử dụng đệ quy
``` cpp=
s.push(root);  // Đẩy node gốc vào stack
while (!s.empty()) {
    Node* node = s.top();  // Lấy node ở đỉnh stack
    s.pop();  // Pop node khỏi stack
    cout << node->data << " ";  // Xuất giá trị của node
    if (node->right) { // Đẩy cây con phải vào ngăn xếp
        s.push(node->right);
    }
    if (node->left) { // Đẩy cây con trái vào ngăn xếp
        s.push(node->left);
    }
}
```