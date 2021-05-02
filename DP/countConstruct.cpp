#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <regex>

using namespace std;

map<string, bool> memo;

int countConstruct(string target, vector<string> strings) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return 1;

    int count = 0;

    for(string s : strings) {
        if (target.substr(0, s.length()) == s) {
            string remainder = target.substr(s.length(), target.length());
            count += countConstruct(remainder, strings);
        }
    }

    memo[target] = count;        
    return count;
}

int main() {
    vector<string> a = {"ab", "abc", "cd", "def", "abcd"};
    cout<<countConstruct("abc", a)<<endl;

    vector<string> b = {"purp", "p", "ur", "le", "purpl"};
    cout<<countConstruct("purple", b)<<endl;

    vector<string> c = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    cout<<countConstruct("skateboard", c)<<endl;

    vector<string> d = {"a", "p", "ent", "enter", "ot", "o", "t"};
    cout<<countConstruct("enterapotentpot", d)<<endl;

    vector<string> e = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
    cout<<countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", e)<<endl;
}