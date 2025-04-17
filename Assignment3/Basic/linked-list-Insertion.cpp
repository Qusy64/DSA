SinglyLinkedListNode* newNode = new SinglyLinkedListNode(x);
    if (head == nullptr || head->data >= x) { // Nếu danh sách rỗng hoặc node đầu tiên có giá trị lớn hơn bằng x 
        newNode->next = head; // Chèn node newNode vào đầu danh sách
        return newNode; 
    }
    // Nếu không, ta duyệt tìm vị trí chèn newNode
    SinglyLinkedListNode* current = head;
    while (current->next != nullptr && current->next->data < x) { // Duyệt đến khi tìm được node có giá trị lớn hơn hoặc bằng x
        current = current->next; 
    }
    newNode->next = current->next;
    current->next = newNode;
    return head; // Trả về node đầu danh sách