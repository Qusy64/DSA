SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head_list1,SinglyLinkedListNode* head_list2){
    // Tạo dummy để quản lý danh sách mới
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* tail = dummy;

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
    // Lúc này, ta có Node đầu tiên của danh sách sau khi trộn là dummy->next
    SinglyLinkedListNode* merged = dummy->next; // Tạo con trỏ merged, gán cho nó là Node đầu tiên của danh sách sau khi trộn
    delete dummy;
    return merged;
}
