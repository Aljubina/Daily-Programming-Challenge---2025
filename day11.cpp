#include <bits/stdc++.h>
using namespace std;

void backtrack(string &s, int idx, set<string> &ans) {
    if (idx == s.size()) {
        ans.insert(s);  // store only unique permutations
        return;
    }
    for (int i = idx; i < s.size(); i++) {
        swap(s[i], s[idx]);              // choose
        backtrack(s, idx + 1, ans);      // explore
        swap(s[i], s[idx]);              // un-choose (backtrack)
    }
}

vector<string> PermutationString(string s) {
    set<string> ans;              // to avoid duplicates
    backtrack(s, 0, ans);
    return vector<string>(ans.begin(), ans.end()); // convert to vector
}

int main() {
    string s;
    cin >> s;

    vector<string> result = PermutationString(s);

    // print permutations
    for (auto &perm : result) {
        cout << perm << "\n";
    }
    return 0;
}
