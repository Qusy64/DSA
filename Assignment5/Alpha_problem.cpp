#include<bits/stdc++.h>

using namespace std;

long long n; 

vector <long long> solve;

void Alpha(int x){
    long long copy = n;
    while (copy > 0){
        long long i = copy % x;
        solve.push_back(i);
        copy = copy / x;
    }
    for ( long long j = solve.size()-1 ; j >= 0 ; j--){
        cout << solve[j];
    }
}

int main(){
    int x;
    cin >> n;
    cin >> x; 
    Alpha (x);
    return 0;
}