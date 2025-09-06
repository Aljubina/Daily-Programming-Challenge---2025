#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int>& arr, int k) {
    deque<int> dq; // stores indices of useful elements
    vector<int> result;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Remove indices that are out of current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements (they are useless)
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Add the maximum (at the front) once window is of size k
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}

void printResult(vector<int> arr, int k) {
    vector<int> ans = slidingWindowMaximum(arr, k);
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    // Test Case 1
    vector<int> arr1 = {1, 5, 3, 2, 4, 6};
    int k1 = 3;
    cout << "Output 1: ";
    printResult(arr1, k1); // Expected: 5 5 4 6

    // Test Case 2
    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "Output 2: ";
    printResult(arr2, k2); // Expected: 2 3 4

    // Test Case 3
    vector<int> arr3 = {7, 7, 7, 7};
    int k3 = 1;
    cout << "Output 3: ";
    printResult(arr3, k3); // Expected: 7 7 7 7

    // Edge Case: Single Element
    vector<int> arr4 = {10};
    int k4 = 1;
    cout << "Output 4 (Single Element): ";
    printResult(arr4, k4); // Expected: 10

    return 0;
}
