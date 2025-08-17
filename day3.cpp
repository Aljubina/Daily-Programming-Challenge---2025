#include <iostream>
#include <vector>
using namespace std;

int FindDuplicate(vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while(slow != fast);

    slow = arr[0];
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main() {

    vector<int> arr = {1, 4, 4, 2, 3, 4};
    cout << "Duplicate Number: " << FindDuplicate(arr) << endl;
    return 0;
}