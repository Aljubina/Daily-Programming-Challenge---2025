#include <bits/stdc++.h>
using namespace std;

int firstElementKTimes(const vector<int>& arr, int k) {
    unordered_map<int,int> freq;
    freq.reserve(arr.size() * 2);

    for (int x : arr) freq[x]++;

    for (int x : arr) {
        if (freq[x] == k) return x;
    }
    return -1;
}

int main() {
    cout << firstElementKTimes({3,1,4,4,5,2,6,1,4}, 2) << "\n";    
    cout << firstElementKTimes({2,3,4,2,2,5,5}, 2) << "\n";        
    cout << firstElementKTimes({1,1,1,1}, 1) << "\n";              
    cout << firstElementKTimes({10}, 1) << "\n";                   
    cout << firstElementKTimes({6,6,6,6,7,7,8,8,8}, 3) << "\n";    
    return 0;
}
