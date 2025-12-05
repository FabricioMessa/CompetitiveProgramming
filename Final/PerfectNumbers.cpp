#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long n) {
    if (n < 2) {
        return false;
    }
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void sol() {
    int n;
    if (!(cin >> n)) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        if (cin.peek() == ',') {
            cin.ignore();
        }
        if (!isPrime(p)) {
            cout << "No\n";
            continue;
        }
        long long mersenne = (1LL << p) - 1;
        if (isPrime(mersenne)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    sol();
    return 0;
}