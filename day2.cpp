#include <iostream>
#include <vector>
using namespace std;

int MissingNumber(vector<int> &arr) {
    int n = arr.size();
    int total = (n + 1) * (n + 2) / 2;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int missingNumber = total - sum;
    cout << "Missing Number: " << missingNumber << endl;
    return missingNumber;
}   

int main() {

    vector<int> arr = {1};
    MissingNumber(arr);
    return 0;
}