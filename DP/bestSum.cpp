#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<int>* bestSum(int target, vector<int> numbers, map<int, vector<int>*> memo = {}) {
    if (memo.find(target) != memo.end()) return memo[target];
        
    if (target == 0) return new vector<int>();
    if (target < 0) return NULL;

    vector<int>* shortestCombination = NULL;

    for(int number : numbers) {
        int remainder = target - number;
        vector<int> *result = bestSum(remainder, numbers, memo);
        if (result != NULL) {
            (*result).push_back(number);
            if (shortestCombination == NULL || ((*result).size() < (*shortestCombination).size())) {
                shortestCombination = result;
            }
        }
    }

    memo[target] = shortestCombination;
    return shortestCombination;
}

int main() {
    vector<int> a = {5, 3, 4, 7};
    vector<int> *result = bestSum(7, a);
    if (result != NULL) {
        for(int num : *result) {
            cout<<num<<" ";
        }
    } else {
        cout<<"null";
    }
    cout<<endl;

    vector<int> c = {2, 3, 5};
    result = bestSum(8, c);
    if (result != NULL) {
        for(int num : *result) {
            cout<<num<<" ";
        }
    } else {
        cout<<"null";
    }
    cout<<endl;

    vector<int> d = {1, 4, 5};
    result = bestSum(8, d);
    if (result != NULL) {
        for(int num : *result) {
            cout<<num<<" ";
        }
    } else {
        cout<<"null";
    }
    cout<<endl;

    vector<int> e = {1, 2, 5, 25};
    result = bestSum(100, e);
    if (result != NULL) {
        for(int num : *result) {
            cout<<num<<" ";
        }
    } else {
        cout<<"null";
    }
    cout<<endl;
}