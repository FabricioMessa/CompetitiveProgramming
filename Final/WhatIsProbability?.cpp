#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void solve() {
    int N, I;
    double p;
    cin >> N >> p >> I;
    if (p == 0) {
        cout << "0.0000\n";
        return;
    }
    double q = 1.0 - p;
    double a = pow(q, I - 1) * p;
    double r = pow(q, N);
    double result = a / (1.0 - r);
    cout << fixed << setprecision(4) << result << "\n";
}

int main() {
    int S;
    if (cin >> S) {
        while (S--) {
            solve();
        }
    }
    return 0;
}