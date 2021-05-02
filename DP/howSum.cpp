#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<int, vector<int>*> memo;

vector<int>* howSum(int target, vector<int> numbers) {
    if (memo.find(target) != memo.end()) return memo[target];
        
    if (target == 0) return new vector<int>();
    if (target < 0) return NULL;

    for(int number : numbers) {
        int remainder = target - number;
        vector<int> *result = howSum(remainder, numbers);
        memo[remainder] = result;
        if (result != NULL) {
            (*result).push_back(number);
            return result;
        }
    }

    memo[target] = NULL;
    return NULL;
}

int main() {
    vector<int> a = {2, 3};
    vector<int> *result = howSum(7, a);
    if (result != NULL) {
        for(int num : *result) {
            cout<<num<<" ";
        }
    } else {
        cout<<"null";
    }
    cout<<endl;

    memo.clear();
    vector<int> b = {5, 3, 4, 7};
    result = howSum(7, b);
    if (result != NULL) {
        for(int num : *result) {
            cout<<num<<" ";
        }
    } else {
        cout<<"null";
    }
    cout<<endl;

    memo.clear();
    vector<int> c = {2, 4};
    result = howSum(7, c);
    if (result != NULL) {
        for(int num : *result) {
            cout<<num<<",";
        }
    } else {
        cout<<"null";
    }
    cout<<endl;

    memo.clear();
    vector<int> d = {2, 3, 5};
    result = howSum(8, d);
    if (result != NULL) {
        for(int num : *result) {
            cout<<num<<" ";
        }
    } else {
        cout<<"null";
    }
    cout<<endl;

    memo.clear();
    vector<int> e = {7, 14};
    result = howSum(300, e);
    if (result != NULL) {
        for(int num : *result) {
            cout<<num<<" ";
        }
    } else {
        cout<<"null";
    }
    cout<<endl;
}