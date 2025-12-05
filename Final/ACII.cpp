#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string raw_chars;
    double mini;
    double maxi;
    double preci;
    double minr;
    double maxr;
    double precr;

    cin >> raw_chars;
    string chars = raw_chars.substr(1, raw_chars.length() - 2);

    cin >> mini >> maxi >> preci;
    cin >> minr >> maxr >> precr;

    double eps = 1e-9;

    for (double y = mini; y <= maxi + eps; y += preci) {
        for (double x = minr; x <= maxr + eps; x += precr) {
            double c_r = x;
            double c_i = y;
            double z_r = 0.0;
            double z_i = 0.0;
            bool escaped = false;
            int k = 0;
            for (k = 0; k < 12; ++k) {
                double temp_r = (z_r * z_r) - (z_i * z_i) + c_r;
                double temp_i = (2.0 * z_r * z_i) + c_i;

                z_r = temp_r;
                z_i = temp_i;

                if ((z_r * z_r + z_i * z_i) > 4.0) {
                    escaped = true;
                    break;
                }
            }

            if (escaped) {
                cout << chars[k];
            } 
            
            else {
                cout << ' ';
            }
        }
        cout << "\n";
    }
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
            if (t > 0) cout << "\n";
        }
    }
    return 0;
}