for( auto t : A ){
    Hash[t]++;
}
vector<int> quy;
for ( auto &T : Hash) {
    if (k > 0 && T.second > 0){
        k--;
        T.second--;
        quy.push_back(T.first);
    }
}
while( k > 0){
for ( auto &T : Hash) {
    if (k > 0 && T.second > 0){
        k--;
        T.second--;
        quy.push_back(T.first);
    }
}
}
return quy;