#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string ReverseString(string s) {
    vector<string> words;
    string word = "";

    for (char c : s) {
        if (c != ' ') {
            word += c;  // build a word
        } else if (!word.empty()) {
            words.push_back(word); // save word
            word = "";
        }
    }
    if (!word.empty()) {
        words.push_back(word); // push last word
    }

    // reverse the words
    reverse(words.begin(), words.end());

    // join with single space
    string result = "";
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) result += " ";
    }

    return result;
}

int main() {
    cout << ReverseString("the sky is blue") << endl;     // "blue is sky the"
    cout << ReverseString("  hello world  ") << endl;     // "world hello"
    cout << ReverseString("a good   example") << endl;    // "example good a"
    cout << ReverseString("    ") << endl;                // ""
    cout << ReverseString("word") << endl;                // "word"
    return 0;
}
