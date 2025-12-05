#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int max_dig = 200;

void solve(string s1, string s2) {
    vector<int> fib(max_dig, 0);
    int n1 = s1.length();
    for (int i = 0; i < n1; ++i) {
        if (s1[n1 - 1 - i] == '1') {
            fib[i]++;
        }
    }
    int n2 = s2.length();
    for (int i = 0; i < n2; ++i) {
        if (s2[n2 - 1 - i] == '1') {
            fib[i]++;
        }
    }
    bool chg = true;
    while (chg) {
        chg = false;
        for (int i = 0; i < max_dig; ++i) {
            if (fib[i] >= 2) {
                fib[i] -= 2;
                fib[i + 1]++;
                
                if (i == 0) {
                } else if (i == 1) {
                    fib[i - 1]++; 
                } else {
                    fib[i - 2]++;
                }
                chg = true;
            }
        }
        for (int i = 0; i < max_dig - 2; ++i) {
            if (fib[i] >= 1 && fib[i + 1] >= 1) {
                fib[i]--;
                fib[i + 1]--;
                fib[i + 2]++;
                chg = true;
            }
        }
    }
    int highest = -1;
    for (int i = max_dig - 1; i >= 0; --i) {
        if (fib[i] > 0) {
            highest = i;
            break;
        }
    }
    if (highest == -1) {
        cout << "0\n";
    } else {
        for (int i = highest; i >= 0; --i) {
            cout << fib[i];
        }
        cout << "\n";
    }
}

int main() {
    string s1;
    string s2;
    bool first = true;
    while (cin >> s1 >> s2) {
        if (!first) {
            cout << "\n"; 
        }
        solve(s1, s2);
        first = false;
    }
    return 0;
}