#include <iostream>
#include <vector>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap + 1) / 2;
}

void mergeInPlace(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int gap = nextGap(m + n);

    while (gap > 0) {
        int i, j;

        // Compare elements in arr1
        for (i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap]) swap(arr1[i], arr1[i + gap]);
        }

        // Compare elements between arr1 and arr2
        for (j = gap > m ? gap - m : 0; i < m && j < n; i++, j++) {
            if (arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);
        }

        // Compare elements in arr2
        if (j < n) {
            for (j = 0; j + gap < n; j++) {
                if (arr2[j] > arr2[j + gap]) swap(arr2[j], arr2[j + gap]);
            }
        }

        gap = nextGap(gap);
    }
}

void printArrays(vector<int>& arr1, vector<int>& arr2) {
    for (int x : arr1) cout << x << " ";
    cout << endl;
    for (int x : arr2) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr1 = {10, 12, 14};
    vector<int> arr2 = {1, 3, 5};

    mergeInPlace(arr1, arr2);

    printArrays(arr1, arr2); // Output: 1 2 3 | 4 5 6

    return 0;
}
