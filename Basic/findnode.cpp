SinglyLinkedListNode* findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int len1 = 0, len2 = 0;
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;

    while (temp1 != nullptr) { // Tính len1 là độ dài của danh sách liên kết 1
        len1++;
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) { // Tính len2 là độ dài của danh sách liên kết 2
        len2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if (len1 > len2) { // Nếu dsach 1 dài hơn dsach 2
        for (int i = 0; i < len1 - len2; i++) {
            temp1 = temp1->next;
        }
    }
    else if (len2 > len1) { // Nếu dsach 2 dài hơn dsach 1
        for (int i = 0; i < len2 - len1; i++) {
            temp2 = temp2->next;
        }
    }
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1 == temp2) {
            return temp1;  // Trả về nút chung
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return nullptr;  // Nếu không tìm thấy nút chung, trả về nullptr
}
