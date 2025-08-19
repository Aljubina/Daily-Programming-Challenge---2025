#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> LeaderArray(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    int cmax = arr[n-1];
    ans.push_back(cmax);

    for (int i = n-2; i >= 0; i--) {
        if(arr[i] > cmax) {
            cmax = arr[i];
            ans.push_back(cmax);
        }
    }
    reverse(ans.begin(), ans.end()); // Reverse to maintain order
    return ans;
}

int main() {

    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = LeaderArray(arr);

    cout << "Leaders in array: ";
    for(int num : leaders) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}