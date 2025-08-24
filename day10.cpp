#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;
    
    for (string word : strs) {
        string key = word;
        sort(key.begin(), key.end());  // sorted word as key
        anagramMap[key].push_back(word);
    }
    
    vector<vector<string>> result;
    for (auto& entry : anagramMap) {
        result.push_back(entry.second);
    }
    return result;
}

int main() {
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs2 = {""};
    vector<string> strs3 = {"a"};
    vector<string> strs4 = {"abc", "bca", "cab", "xyz", "zyx", "yxz"};
    vector<string> strs5 = {"abc", "def", "ghi"};
    
    auto printGroups = [](vector<vector<string>> groups) {
        for (auto& group : groups) {
            cout << "[ ";
            for (auto& word : group) cout << word << " ";
            cout << "] ";
        }
        cout << "\n";
    };

    printGroups(groupAnagrams(strs1));
    printGroups(groupAnagrams(strs2));
    printGroups(groupAnagrams(strs3));
    printGroups(groupAnagrams(strs4));
    printGroups(groupAnagrams(strs5));
    
    return 0;
}
