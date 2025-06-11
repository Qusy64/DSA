#include <bits/stdc++.h>
using namespace std;

int n;
int a[2000005];

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
int partition( int l, int r) {
    int pivot = a[(l + r) / 2];
    
    int left = l;
    int right = r;
    
    while (true) {
        while (a[left] < pivot) {
            left++;
        }
        
        while (a[right] > pivot) {
            right--;
        }
        
        if (left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        } else {
            break;
        }
    }
    
    return left;  
}
void QuickSort(int l , int r){
    if(l < r){
        int j = partition( l, r);
        QuickSort(l , j - 1);
        QuickSort(j + 1 , r);
    }
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
 
        QuickSort(1,n);

        end = clock();
 
        fstream out;
        out.open("Time.txt" , fstream::app);
 
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        out << "Quick sort chạy : " << fixed << time_taken << setprecision(5);
        out << " giây ở dãy " << i << endl;
 
        for(int k = 1; k <= n; k++) 
            outputFile << a[k] << " ";
 
        inputFile.close();
        outputFile.close();
        out.close();
    }
    return 0;
}
