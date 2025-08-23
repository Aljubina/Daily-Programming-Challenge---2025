#include <iostream>
#include <vector>
#include<string>

using namespace std;

string LongestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) return "";
    }

    return prefix;
}

int main() {

    vector<string> test1 = {"flower", "flow", "flight"};
    cout << LongestCommonPrefix(test1) << endl; // "fl"

    vector<string> test2 = {"dog", "racecar", "car"};
    cout << LongestCommonPrefix(test2) << endl; // ""

    vector<string> test3 = {"apple", "ape", "april"};
    cout << LongestCommonPrefix(test3) << endl; // "ap"

    vector<string> test4 = {"alone"};
    cout << LongestCommonPrefix(test4) << endl; // "alone"

    vector<string> test5 = {""};
    cout << LongestCommonPrefix(test5) << endl; // ""

    return 0;
}