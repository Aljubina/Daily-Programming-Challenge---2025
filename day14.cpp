#include <bits/stdc++.h>
using namespace std;


int atMostKDistinct(const string &s, int k) {
    if (k == 0) return 0;
    int n = s.size();
    int left = 0, count = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < n; right++) {
        freq[s[right]]++;

        while ((int)freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        count += (right - left + 1);
    }
    return count;
}

int countExactlyKDistinct(const string &s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    vector<pair<string, int>> testCases = {
        {"pqpqs", 2},
        {"aabacbebebe", 3},
        {"a", 1},
        {"abc", 3},
        {"abc", 2}
    };

    for (auto &tc : testCases) {
        cout << "Input: s = " << tc.first << ", k = " << tc.second << endl;
        cout << "Output: " << countExactlyKDistinct(tc.first, tc.second) << endl;
        cout << "----" << endl;
    }

    return 0;
}
