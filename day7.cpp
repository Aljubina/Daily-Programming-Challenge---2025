#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0; // less than 3 bars => no water

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int res = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                res += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                res += rightMax - height[right];
            }
            right--;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> tests = {
        {0,1,0,2,1,0,1,3,2,1,2,1}, // expected 6
        {4,2,0,3,2,5},             // expected 9
        {1,1,1},                   // expected 0
        {5},                       // expected 0
        {2,0,2}                    // expected 2
    };

    for (auto &t : tests) {
        cout << "Water trapped: " << trap(t) << endl;
    }
    return 0;
}
