#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2000005;  
int a[MAX_N], n;
int m;

void heapify(int id){
    int L = id * 2;
    int R = id * 2 + 1;

    int largest = id;

    if(L <= m && a[L] > a[largest])
        largest = L;
    if(R <= m && a[R] > a[largest])
        largest = R;
    if(largest != id){
        swap(a[id] , a[largest]);
        heapify(largest);
    }
}

void heapSort(){
    m = n;

    for(int i = n ; i > 0 ; i--)
        heapify(i);
        
    for(int i = 1 ; i <= n ; i++){
        swap(a[1] , a[m]);
        m--;
        heapify(1);
    }
}

string toString(int x){
    string result = "";
    while(x > 0){
        result += (x % 10) + '0';
        x /= 10;
    }   
    reverse(result.begin() , result.end());
    return result;
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

        clock_t start, end;
        start = clock();

        heapSort();  

        end = clock();

        fstream out;
        out.open("Time.txt", fstream::app);

        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        out << "Heap sort chạy : " << fixed << time_taken << setprecision(5);
        out << " giây ở dãy " << i << endl;

        for(int k = 1; k <= n; k++) 
        outputFile << a[k] << " ";

        inputFile.close();
        outputFile.close();
        out.close();
    }

    return 0;
}