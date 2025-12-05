#include <iostream>
#include <string>

using namespace std;

long long solve() {
    long long paths = 1;
    string token;
    while (cin >> token) {
        if (token == "S") {
            continue;
        } 
        else if (token == "IF") {
            long long true_paths = solve();
            long long false_paths = solve();
            paths *= (true_paths + false_paths);
        } 
        else if (token == "ELSE") {
            return paths;
        } 
        else if (token == "END_IF") {
            return paths;
        } 
        else if (token == "ENDPROGRAM") {
            return paths;
        }
    }
    return paths;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            cout << solve() << "\n";
        }
    }
    return 0;
}