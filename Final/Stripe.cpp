#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> BigInt;

BigInt add(const BigInt& a, const BigInt& b) {
    BigInt c;
    int carry = 0;
    int size_a = a.size();
    int size_b = b.size();
    int max_len = max(size_a, size_b);

    for (int i = 0; i < max_len || carry; ++i) {
        int sum = carry;
        if (i < size_a) sum += a[i];
        if (i < size_b) sum += b[i];
        c.push_back(sum % 10);
        carry = sum / 10;
    }
    return c;
}

void print(const BigInt& a) {
    if (a.empty()) {
        cout << 0;
        return;
    }
    for (int i = a.size() - 1; i >= 0; --i) {
        cout << a[i];
    }
    cout << "\n";
}

const int MAX_VAL = 205;
BigInt C[MAX_VAL][MAX_VAL];

void precompute() {
    C[0][0] = {1};
    for (int n = 1; n < MAX_VAL; ++n) {
        C[n][0] = {1}; 
        for (int k = 1; k <= n; ++k) {
            C[n][k] = add(C[n - 1][k - 1], C[n - 1][k]);
        }
    }
}

void solve() {
    int N;
    int K;
    if (!(cin >> N)) return;
    cin >> K;
    int sum_black = 0;
    for (int i = 0; i < K; ++i) {
        int val;
        cin >> val;
        sum_black += val;
    }

    int n_comb = N - sum_black + 1;
    int k_comb = K;
    if (n_comb < k_comb || n_comb < 0) {
        cout << "0\n";
    } else {
        print(C[n_comb][k_comb]);
    }
}

int main() {
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}