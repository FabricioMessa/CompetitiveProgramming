#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void burger(int case_num) {
    string S;
    cin >> S;
    int N = S.length();
    vector<bool> is_invalid(N, false);

    for (int j = 0; j < N; ++j) {
        char object = S[j];
        if (object == 'D') {
            is_invalid[j] = true;
        } else if (object == 'B') {
            is_invalid[j] = true;
            if (j > 0) {
                is_invalid[j - 1] = true;
            }
            if (j > 1) {
                is_invalid[j - 2] = true;
            }
        } else if (object == 'S') {
            is_invalid[j] = true;
            if (j > 0) {
                is_invalid[j - 1] = true;
            }
            if (j < N - 1) {
                is_invalid[j + 1] = true;
            }
        }
    }

    int possible_spaces = 0;
    for (int i = 0; i < N; ++i) {
        if (!is_invalid[i]) {
            possible_spaces++;
        }
    }
    cout << "Case " << case_num << ": " << possible_spaces << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) { 
        return 0;
    }
    for (int i = 1; i <= T; ++i) {
        burger(i);
    }
    
    return 0;
}