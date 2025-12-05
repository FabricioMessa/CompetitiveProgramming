#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
int dp[1005][1005];
string left_half; 
string mid_char; 

void construct(int i, int j) {
    if (i > j) {
        return;
    }
    int current_len = dp[i][j];
    if (current_len == 0) {
        return;
    }
    if (current_len == 1) {
        for (char c = 'a'; c <= 'z'; c++) {
            for (int k = i; k <= j; k++) {
                if (s[k] == c) {
                    mid_char = c;
                    return;
                }
            }
        }
        return;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        int L = -1, R = -1;
        for (int k = i; k <= j; k++) {
            if (s[k] == c) {
                L = k;
                break;
            }
        }
        if (L == -1) {
            continue;
        }
        for (int k = j; k >= i; k--) {
            if (s[k] == c) {
                R = k;
                break;
            }
        }
        if (L < R) {
            if (dp[L+1][R-1] == current_len - 2) {
                left_half += c;
                construct(L + 1, R - 1);
                return; 
            }
        }
    }
}

void sol() {
    int n = s.length();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            if (len == 1) {
                dp[i][j] = 1;
            } else if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    left_half = "";
    mid_char = "";
    construct(0, n - 1);
    cout << left_half << mid_char;
    reverse(left_half.begin(), left_half.end());
    cout << left_half << "\n";
}

int main() {
    while (cin >> s) {
        sol();
    }
    return 0;
}