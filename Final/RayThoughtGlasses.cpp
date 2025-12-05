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
        cout << 0 << "\n";
        return;
    }
    for (int i = a.size() - 1; i >= 0; --i) {
        cout << a[i];
    }
    cout << "\n";
}

const int MAXN = 1005;
BigInt results[MAXN];

void precompute() {
    results[0] = {1};
    results[1] = {2};
    for (int i = 2; i <= 1000; ++i) {
        results[i] = add(results[i-1], results[i-2]);
    }
}

int main() {
    precompute();

    int n;
    while (cin >> n) {
        print(results[n]);
    }
    return 0;
}