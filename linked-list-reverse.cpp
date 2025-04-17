void insert_node(SinglyLinkedList* llist, int val) { // Thêm Node mới vào danh sách liên kết
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(val);
    if (llist->head == 0) {
        llist->head = new_node;
        llist->tail = new_node;
    } else {
        llist->tail->next = new_node;
        llist->tail = new_node;
    }
}

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

void printLinkedList(SinglyLinkedList* llist) { // Xuất ra danh sách liên kết 
    SinglyLinkedListNode* current = llist->head;
    while (current != 0) {
        cout << current->data;
        if (current->next != 0) {
            cout << " ";
        }
        current = current->next;
    }
}
