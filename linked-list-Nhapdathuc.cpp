void Nhap(DATHUC &p, double heso, int somu){
    DONTHUC* t = new DONTHUC(heso,somu);
    Node* newNode = new Node(t);
    if(!p.head){ // Nếu danh sách trống, tạo danh sách với phần tử Node đầu tiên
        p.head = newNode;
        p.tail = newNode;
    }
    else { // Chèn newNode đến cuối danh sách
        p.tail->next = newNode;
        p.tail = newNode;
    }
}
void Xuat(DATHUC p) {
    if (!p.head) { // Nếu đa thức trống, xuất 0
        cout << "0";
        return;
    }
    Node* current = p.head;
    bool firstTerm = true;

    while (current) { // Duyệt từ đầu đến cuối danh sách liên kết
        if (current->data->heso != 0) { // Chỉ xét các phần tử có heso khác 0
            if (!firstTerm) { // Trường hợp không phải phần tử đầu tiên có heso khác 0 của đa thức
                cout << (current->data->heso > 0 ? "+" : "-"); // Xuất ra dấu của heso
            } else if (firstTerm && current->data->heso < 0) { // Nếu phần tử đầu tiên có heso bé hơn 0
                cout << "-"; // Xuất ra dấu - ( Với dấu + thì không cần quan tâm vì đây là phần tử đầu tiên của đa thức)
            }

            double abs_heso = abs(current->data->heso);
            bool isInteger = floor(abs_heso) == abs_heso;
            
            if (abs_heso != 1 || current->data->somu == 0) { // Xét các trường hợp phải in heso
                if (isInteger)
                    cout << (int)abs_heso; // Xuất ra số nguyên ( ví dụ 2.0 thì xuất ra 2)
                else{ // Xuất ra các số thực nhưng không bị dư số 0 hoặc dấu chấm cuối
                    stringstream ss;
                    ss << fixed << setprecision(2) << abs_heso;
                    string val = ss.str();
                    while (!val.empty() && val.back() == '0') val.pop_back();
                    if (!val.empty() && val.back() == '.') val.pop_back();
                    cout << val;
                }
            }

            if (current->data->somu > 0) { // Trường hợp không cần in heso
                cout << "x";
                if (current->data->somu > 1) {
                    cout << "^" << current->data->somu;
                }
            }
            firstTerm = false; // Đặt thành false sau khi làm việc với Node đầu tiền có heso khác 0
        }
        current = current->next;
    }

    if (firstTerm) { // Nếu sau khi duyệt, không có phần tử nào được xuất ra thì xuất giá trị 0
        cout << "0";
    }
}
double TinhDaThuc(DATHUC p, double x) { // Thay giá trị x để tính giá trị của đa thức P(x)
    double result = 0;
    Node* current = p.head;
    while (current) { 
        result += current->data->heso * pow(x, current->data->somu); 
        current = current->next;
    }
    return result;
}