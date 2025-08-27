#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s; 

        int start = 0, maxLen = 1; 

        for (int i = 0; i < s.size(); i++) {
            // Case 1: Odd length palindrome (centered at i)
            expandAroundCenter(s, i, i, start, maxLen);

            // Case 2: Even length palindrome (centered between i and i+1)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen); 
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                start = left;
                maxLen = currLen;
            }
            left--;
            right++;
        }
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl; 
    cout << sol.longestPalindrome("cbbd") << endl;  
    cout << sol.longestPalindrome("a") << endl;     
    cout << sol.longestPalindrome("aaaa") << endl;  
    return 0;
}
