#include <iostream>
#include <vector>

using namespace std;

const int max_n = 100005;
long long d[max_n];
long long sigma[max_n];

void precompute() {
    for (int i = 0; i < max_n; ++i) {
        d[i] = 0;
        sigma[i] = 0;
    }

    for (int i = 1; i < max_n; ++i) {
        for (int j = i; j < max_n; j += i) {
            d[j]++;      
            sigma[j] += i; 
        }
    }
}

void solve() {
    int a;
    int b;
    int k;
    if (!(cin >> a >> b >> k)) { 
        return;
    }

    long long g_res = 0; 
    long long h_res = 0; 
    int start = a;

    if (start % k != 0) {
        start = start + (k - (start % k));
    }

    for (int i = start; i <= b; i += k) {
        g_res += d[i];
        h_res += sigma[i];
    }

    cout << g_res << " " << h_res << "\n";
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