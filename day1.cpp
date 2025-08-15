#include <iostream>
#include <vector>
using namespace std;

void sortarr(vector<int> &arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    sortarr(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }   
    cout << endl;
    return 0;
}