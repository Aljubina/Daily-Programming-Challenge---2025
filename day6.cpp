#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> result;
    long long prefixSum = 0;

    unordered_map<long long, vector<int>> sumMap;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            result.push_back({0, i});
        }

        if (sumMap.find(prefixSum) != sumMap.end()) {
            for (int startIdx : sumMap[prefixSum]) {
                result.push_back({startIdx + 1, i});
            }
        }


        sumMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};

    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    cout << "[";
    for (int i = 0; i < subarrays.size(); i++) {
        cout << "(" << subarrays[i].first << ", " << subarrays[i].second << ")";
        if (i != subarrays.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

