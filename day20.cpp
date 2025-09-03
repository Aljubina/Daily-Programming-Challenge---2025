#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertSorted(stack<int>& st, int element) {
    if (st.empty() || element < st.top()) {
        st.push(element);
        return;
    }

    int topElement = st.top();
    st.pop();

    insertSorted(st, element);

    st.push(topElement);
}

void sortStack(stack<int>& st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, topElement);
}

void printStack(stack<int> st) {
    vector<int> temp;
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }
    cout << "[";
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i];
        if (i != 0) cout << ", ";
    }
    cout << "]" << endl;
}

stack<int> createStack(const vector<int>& arr) {
    stack<int> st;
    for (int x : arr) {
        st.push(x);
    }
    return st;
}

int main() {
    vector<vector<int>> testCases = {
        {7, 1, 5},
        {5},
        {-3, 14, 8, 2},
        {},            // empty stack
        {3, 3, 3}
    };

    for (auto& test : testCases) {
        stack<int> st = createStack(test);

        cout << "Input: ";
        printStack(createStack(test));  // Print original input

        sortStack(st);

        cout << "Output: ";
        printStack(st);
        cout << "------------------------" << endl;
    }

    return 0;
}
