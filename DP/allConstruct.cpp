#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <regex>

using namespace std;

map<string, vector< vector<string> > > memo;

vector< vector<string> > allConstruct(string target, vector<string> strings) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return vector< vector<string> >();

    vector< vector<string> > possibleWays;

    for(string s : strings) {
        if (target.substr(0, s.length()) == s) {
            string remainder = target.substr(s.length(), target.length());
            vector< vector<string> > result = allConstruct(remainder, strings);
            if (result.size() == 0) {
                result.insert(result.begin(), {s});
            } else {
                for(int i = 0; i < result.size(); i++) {
                    result[i].insert(result[i].begin(), s);
                }
            }

            for (vector<string> r : result) {
                possibleWays.push_back(r);
            }
        }
    }

    memo[target] = possibleWays;        
    return possibleWays;
}

int main() {
    vector<string> a = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
    vector< vector<string> > result = allConstruct("abcdef", a);
    for (vector<string> r : result) {
        for (string s : r) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<string> b = {"purp", "p", "ur", "le", "purpl"};
    result = allConstruct("purple", b);
    for (vector<string> r : result) {
        for (string s : r) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<string> c = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    result = allConstruct("cskateboard", c);
    for (vector<string> r : result) {
        for (string s : r) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
    if (result.size() == 0) cout<<"not possible"<<endl<<endl;

    vector<string> e = {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
    result = allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", e);
    for (vector<string> r : result) {
        for (string s : r) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}