#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isStringValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if((c == ')' && top != '(') || 
               (c == '}' && top != '{') || 
               (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {

    string s = "{[()]}";
    string t = "()";

    cout << (isStringValid("()") ? "true" : "false") << endl;
    cout << (isStringValid("([)]") ? "true" : "false") << endl;
    cout << (isStringValid( "[{()}]") ? "true" : "false") << endl;
    cout << (isStringValid("") ? "true" : "false") << endl;
    cout << (isStringValid("{[}") ? "true" : "false") << endl;

    return 0;
}