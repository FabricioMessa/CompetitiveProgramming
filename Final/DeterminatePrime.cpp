#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int max_n = 32005;
vector<int> primes;
bool is_prime[max_n];

void sieve() {
    fill(is_prime, is_prime + max_n, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i < max_n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < max_n; j += i)
                is_prime[j] = false;
        }
    }
    
    for (int i = 2; i < max_n; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}

void solve(int x, int y) {
    if (x > y) { 
        swap(x, y);
    }
    int start_idx = -1, end_idx = -1;

    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] >= x) {
            start_idx = i;
            break;
        }
    }

    for (int i = primes.size() - 1; i >= 0; --i) {
        if (primes[i] <= y) {
            end_idx = i;
            break;
        }
    }

    if (start_idx == -1 || end_idx == -1 || (end_idx - start_idx + 1) < 3) {
        return;
    }

    for (int i = start_idx; i <= end_idx; ++i) {
        if (i + 1 > end_idx) {
            break;
        }

        int diff = primes[i+1] - primes[i];
        int count = 2; 
        int k = i + 1;

        while (k + 1 <= end_idx && (primes[k+1] - primes[k] == diff)) {
            count++;
            k++;
        }

        if (count >= 3) {
            for (int j = 0; j < count; ++j) {
                cout << primes[i + j] << (j == count - 1 ? "" : " ");
            }
            cout << "\n";
            i = k - 1; 
        }
    }
}

int main() {
    sieve();
    int x, y;
    while (cin >> x >> y && (x != 0 || y != 0)) {
        solve(x, y);
    }
    return 0;
}