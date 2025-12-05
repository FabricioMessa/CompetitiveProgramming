#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    while (cin >> s) {
        int n = s.length();
        int zeros = 0;
        int ones = 0;
        int zero_to_one = 0; 

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                zeros++;
                if (s[(i + 1) % n] == '1') {
                    zero_to_one++;
                }
            } else {
                ones++;
            }
        }
        int val_shoot = zero_to_one * n;
        int val_rotate = ones * zeros;

        if (val_shoot < val_rotate) {
            cout << "SHOOT" << "\n";
        } else if (val_shoot > val_rotate) {
            cout << "ROTATE" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}