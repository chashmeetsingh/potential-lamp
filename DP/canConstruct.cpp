#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <regex>

using namespace std;

map<string, bool> memo;

bool canConstruct(string target, vector<string> strings) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return true;

    for(string s : strings) {
        if (target.substr(0, s.length()) == s) {
            string remainder = target.substr(s.length(), target.length());
            if (canConstruct(remainder, strings)) {
                memo[remainder] = true;
                return true;
            }
        }
    }

    memo[target] = false;        
    return false;
}

int main() {
    vector<string> a = {"ab", "abc", "cd", "def", "abcd"};
    cout<<canConstruct("abc", a)<<endl;

    vector<string> b = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    cout<<canConstruct("skateboard", b)<<endl;

    vector<string> c = {"a", "p", "ent", "enter", "ot", "o", "t"};
    cout<<canConstruct("enterapotentpot", c)<<endl;

    vector<string> d = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
    cout<<canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", d)<<endl;
}