#include <bits/stdc++.h>
using namespace std;

vector<long long> primeFactorization(long long N) {
    vector<long long> factors;

    // Step 1: Handle factor 2
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }

    // Step 2: Handle odd factors
    for (long long i = 3; i * i <= N; i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }

    // Step 3: If N is prime and > 1
    if (N > 1) {
        factors.push_back(N);
    }

    return factors;
}

int main() {
    long long N;
    cin >> N;

    vector<long long> result = primeFactorization(N);

    // Print result in list format
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
