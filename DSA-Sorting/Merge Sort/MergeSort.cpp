#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2000005], C[2000005]; 

string toString(int x){
    if (x == 0) return "0";  // Xử lý trường hợp x = 0
    string result = "";
    while(x > 0){
        result += (x % 10) + '0';
        x /= 10;
    }   
    reverse(result.begin() , result.end());
    return result;
}
void Merge(int L1, int R1, int L2, int R2) {
    int i = L1, j = L2, k = 0;

    while (i <= R1 && j <= R2) {
        if (a[i] <= a[j]) {
            C[k] = a[i];
            k++;
            i++;
        } else {
            C[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= R1){
        C[k] = a[i];
        k++;
        i++;
    } 
    while (j <= R2){
        C[k] = a[j];
        k++;
        j++;
    }
    for (i = L1, j = 0; i <= R2; i++, j++) {
        a[i] = C[j];
    }
}

void MergeSort(int L, int R) {
    if (R - L + 1 <= 1) return;

    int mid = (L + R) / 2;
    MergeSort(L, mid);
    MergeSort(mid + 1, R);
    Merge(L, mid, mid + 1, R);
}

int main() {
    for (int i = 1; i <= 10; i++) {
        string input = "day_" + toString(i) + ".txt";
        string output = "day_" + toString(i)+ ".out";
 
        fstream inputFile(input, fstream::in);   
        ofstream outputFile(output); 
 
        inputFile >> n;
        for (int j = 1; j <= n; j++) {
            inputFile >> a[j];
        }
 
        clock_t start , end;
 
        start = clock();
 
        MergeSort(1, n);
 
        end = clock();
 
        fstream out;
        out.open("Time.txt" , fstream::app);
 
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        out << "Merge sort chạy : " << fixed << time_taken << setprecision(5);
        out << " giây ở dãy " << i << endl;
 
        for(int k = 1; k <= n; k++) 
            outputFile << a[k] << " ";
 
        inputFile.close();
        outputFile.close();
        out.close();
    }
    return 0;
}
