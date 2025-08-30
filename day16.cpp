#include <bits/stdc++.h>
using namespace std;

// Function to compute GCD using Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM
long long lcm(long long n, long long m) {
    return (n / gcd(n, m)) * m; // to avoid overflow: divide first, then multiply
}

int main() {
    long long N, M;
    cin >> N >> M;
    cout << lcm(N, M) << endl;
    return 0;
}
