#include <iostream>
#include <map>

using namespace std;

map<string, long long> memo;

int gridTraveler(int r, int c) {
    string key = to_string(r) + ',' + to_string(c);

    if (memo.find(key) != memo.end()) return memo[key];
    if (r == 0 || c == 0) return 0;
    if (r == 1 && c == 1) return 1;

    memo[key] = gridTraveler(r - 1 , c) + gridTraveler(r ,c - 1);
    return memo[key];
}

int main() {
    cout<<gridTraveler(4, 5)<<endl;
    cout<<gridTraveler(2, 5)<<endl;
    cout<<gridTraveler(4, 8)<<endl;
    cout<<gridTraveler(1, 0)<<endl;
    cout<<gridTraveler(10, 10)<<endl;
}