#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, bool> memo;

bool canSum(int target, vector<int> numbers) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == 0) return true;
    if (target < 0) return false;

    for (int number : numbers) {
        int remainder = target - number;
        if (canSum(remainder, numbers)) {
            memo[remainder] = true;
            return true;
        }
    }

    memo[target] = false;
    return false;
}

int main() {
    vector<int> a = {2, 3};
    cout<<canSum(7, a)<<endl;

    memo.clear();
    vector<int> b = {5, 3, 4, 7};
    cout<<canSum(7, b)<<endl;

    memo.clear();
    vector<int> c = {2, 4};
    cout<<canSum(7, c)<<endl;

    memo.clear();
    vector<int> d = {2, 3, 5};
    cout<<canSum(8, d)<<endl;

    memo.clear();
    vector<int> e = {7, 14};
    cout<<canSum(300, e)<<endl;
}