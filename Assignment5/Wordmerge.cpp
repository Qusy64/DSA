#include<bits/stdc++.h>

using namespace std; 

void Solve(string s){
    stack<char> st;
    for ( auto i : s ){
        if ( !st.empty() && i == st.top() ){
            st.pop();
        }
        else {
            st.push(i);
        }
    }
    int k = st.size();
    cout << k;
}

int main(){
    string s;
    cin >> s;
    Solve(s);
    return 0;
}