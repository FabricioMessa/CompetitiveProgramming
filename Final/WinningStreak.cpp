#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void solve() {
    int n;
    double p;

    while (cin >> n && n != 0) {
        cin >> p;
        vector<double> prob_max_streak_le_k(n + 1);
        for (int k = 0; k <= n; ++k) {
            vector<double> dp(n + 1);
            double p_pow_k_plus_1 = pow(p, k + 1);

            for (int i = 0; i <= n; ++i) {
                if (i <= k) {
                    dp[i] = 1.0;
                } else if (i == k + 1) {
                    dp[i] = 1.0 - p_pow_k_plus_1;
                } else {
                    dp[i] = dp[i - 1] - dp[i - k - 2] * (1.0 - p) * p_pow_k_plus_1;
                }
            }
            prob_max_streak_le_k[k] = dp[n];
        }
        double expected_value = 0.0;
        
        for (int k = 1; k <= n; ++k) {
            double prob_exactly_k = prob_max_streak_le_k[k] - prob_max_streak_le_k[k - 1];
            expected_value += k * prob_exactly_k;
        }

        cout << fixed << setprecision(6) << expected_value << "\n";
    }
}

int main() {
    solve();
    return 0;
}