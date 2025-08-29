#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.size(); ++right) {
        while (seen.count(s[right])) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    vector<string> testCases = {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "",
        "a",
        "au",
        "dvdf"
    };

    for (const auto &s : testCases) {
        cout << "Input: s = \"" << s << "\"" << endl;
        cout << "Output: " << lengthOfLongestSubstring(s) << endl;
        cout << endl;
    }

    return 0;
}

