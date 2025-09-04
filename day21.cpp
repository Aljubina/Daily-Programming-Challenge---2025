#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(topElement);
}

void reverseStack(stack<int> &st) {
    if (st.empty()) return;
    
    int topElement = st.top();
    st.pop();
    reverseStack(st);  
    insertAtBottom(st, topElement); 
}

void printStack(stack<int> st) {
    vector<int> elements;
    while (!st.empty()) {
        elements.push_back(st.top());
        st.pop();
    }
    reverse(elements.begin(), elements.end()); 
    cout << "[";
    for (int i = 0; i < elements.size(); i++) {
        cout << elements[i];
        if (i != elements.size() - 1) cout << ", ";
    }
    cout << "]\n";
}


int main() {
    stack<int> st;

    vector<int> arr = {1, 2, 3, 4};
    for (int val : arr) st.push(val);

    cout << "Original Stack: ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed Stack: ";
    printStack(st);

    return 0;
}
