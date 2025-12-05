#include <iostream>
#include <cmath>

using namespace std;

void sol() {
    long long n;
    while (cin >> n && n != 0) {
        cout << n << " = ";
        if (n < 0) {
            cout << "-1 x ";
            n = -n; 
        }
        bool first = true;
        for (long long i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                if (!first) {
                    cout << " x ";
                }
                cout << i;
                first = false; 
                n /= i;
            }
        }
        if (n > 1) {
            if (!first) {
                cout << " x ";
            }
            cout << n;
        }

        cout << "\n";
    }
}

int main() {   
    sol();
    return 0;
}