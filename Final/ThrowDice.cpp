#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct BigInt {
    vector<int> digits;
    BigInt() {}
    BigInt(long long n) {
        if (n == 0) digits.push_back(0);
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
    }

    void add(const BigInt& other) {
        int carry = 0;
        for (size_t i = 0; i < max(digits.size(), other.digits.size()) || carry; ++i) {
            int sum = carry + (i < digits.size() ? digits[i] : 0) + (i < other.digits.size() ? other.digits[i] : 0);
            if (i < digits.size()) digits[i] = sum % 10;
            else digits.push_back(sum % 10);
            carry = sum / 10;
        }
    }

    void multiply(int n) {
        int carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            long long cur = carry + (long long)(i < digits.size() ? digits[i] : 0) * n;
            if (i < digits.size()) digits[i] = cur % 10;
            else digits.push_back(cur % 10);
            carry = cur / 10;
        }
        while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
    }

    void print() {
        if (digits.empty()) {
            cout << 0;
            return;
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            cout << digits[i];
        }
    }
};

void solve() {
    int F, N, S;
    while (cin >> F >> N >> S) {
        BigInt denominator(1);
        for (int i = 0; i < N; ++i) {
            denominator.multiply(F);
        }
        vector<BigInt> dp(S + 1);
        dp[0] = BigInt(1);
        for (int i = 1; i <= N; ++i) {
            vector<BigInt> new_dp(S + 1);
            for (int current_sum = 1; current_sum <= S; ++current_sum) {
                for (int face = 1; face <= F; ++face) {
                    if (current_sum - face >= 0) {
                        if (!dp[current_sum - face].digits.empty()) {
                            new_dp[current_sum].add(dp[current_sum - face]);
                        }
                    }
                }
            }
            dp = new_dp; 
        }
        if (dp[S].digits.empty()) cout << "0";
        else dp[S].print();
        cout << "/";
        denominator.print();
        cout << "\n";
    }
}

int main() {
    solve();
    return 0;
}