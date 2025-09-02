#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(const string &expression) {
    stack<int> st;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") {
                // integer division truncated toward zero
                st.push((int)(a / (double)b));
            }
        } else {
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main() {
    cout << evaluatePostfix("2 1 + 3 *") << endl;             
    cout << evaluatePostfix("5 6 +") << endl;                 
    cout << evaluatePostfix("-5 6 -") << endl;                
    cout << evaluatePostfix("15 7 1 1 + - / 3 * 2 1 1 + + -") << endl; 
    cout << evaluatePostfix("5") << endl;                      
    return 0;
}
