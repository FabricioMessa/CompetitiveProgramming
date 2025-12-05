#include <iostream>
#include <algorithm>

using namespace std;

long long reverseNum(long long n) {
    long long reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

void sol() {
    long long P;
    cin >> P;
    int iterations = 0;
    while (true) {
        long long rev = reverseNum(P);
        P = P + rev;
        iterations++;
        if (P == reverseNum(P)) {
            cout << iterations << " " << P << "\n";
            break;
        }
    }
}

int main() {
    int n;
    if (cin >> n) {
        while (n--) {
            sol();
        }
    }
    return 0;
}