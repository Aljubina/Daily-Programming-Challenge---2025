#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(long long N) {
    int count = 0;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            if (i * i == N)
                count += 1;   // perfect square case
            else
                count += 2;   // i and N/i
        }
    }
    return count;
}

int main() {
    long long N;
    cin >> N;
    cout << countDivisors(N) << endl;
    return 0;
}
