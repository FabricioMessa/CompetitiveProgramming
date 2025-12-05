#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void sol() {
    string s;
    while (cin >> s && s != "#") {
        int counts[26] = {0};
        for (char c : s) {
            counts[c - 'a']++;
        }
        string odd_chars = "";
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_chars += (char)('a' + i);
            }
        }
        if (odd_chars.length() <= 1) {
            cout << "\n"; 
        } else {
            cout << odd_chars.substr(0, odd_chars.length() - 1) << "\n";
        }
    }
}

int main() {
    sol();
    return 0;
}