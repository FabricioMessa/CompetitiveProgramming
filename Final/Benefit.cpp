#include <iostream>
#include <vector>

using namespace std;

const int max_n = 10000005;
int lp[max_n];

void sieve() {
    for (int i = 2; i * i < max_n; ++i) {
        if (lp[i] == 0) { 
            for (int j = i * i; j < max_n; j += i) {
                if (lp[j] == 0) {
                    lp[j] = i; 
                }
            }
        }
    }
    for (int i = 2; i < max_n; ++i) {
        if (lp[i] == 0) lp[i] = i;
    }
}

void solve() {
    int A;
    int C;
    cin >> A >> C;

    if (C % A != 0) {
        cout << "NO SOLUTION\n";
        return;
    }

    long long B = 1;
    int tempC = C;
    int tempA = A;

    while (tempC > 1) {
        int prime = lp[tempC];
        int prime_C = 1;
        while (tempC % prime == 0) {
            tempC /= prime;
            prime_C *= prime;
        }

        int prime_A = 1;
        while (tempA % prime == 0) {
            tempA /= prime;
            prime_A *= prime;
        }

        if (prime_A < prime_C) {
            B *= prime_C;
        }
    }

    cout << B << "\n";
}

int main() {
    sieve();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}