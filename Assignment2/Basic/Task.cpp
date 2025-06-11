#include <bits/stdc++.h>

using namespace std;

void Choncho(int n, int k, int p, int q){ // Đánh số các chỗ ngồi từ trên xuống dưới, trái qua phải
    int u,v;
    int alice = 2 * (p-1) + q; // Ta tính số của vị trí mà alice ngồi
    int bob;
    if( alice - k > 0){ // Nếu ở trước alice có chỗ ngồi sao cho bob chung đề với alice
        bob = alice - k;
    }
    else if( n >= alice + k ){ // Nếu ở trước không có chỗ ngồi cho bob chung đề với alice
        bob = alice + k;
    }
    else { // Nếu chỗ ngồi thỏa điều kiện không tồn tại
        cout<< "-1";
        return;
    }
    // Ta xác định ví trị ngồi của bob với con số vừa tìm được 
    if( bob % 2 ==0 ){ 
        u = (bob/2);
        v = 2;
    }
    else {
        u = (bob+1)/2;
        v = 1;
    }
    cout<< u<<" "<<v; // Xuất ra chỗ ngồi của bob
}

int main() {
    int n,k,p,q;
    cin>>n>>k>>p>>q;
    Choncho(n,k,p,q);
    return 0;
}