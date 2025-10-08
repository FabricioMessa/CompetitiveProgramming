#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string row;
    while (getline(cin, row)) {
        int N = row.size();
        vector<int> left(N, -1), right(N, -1);

        int last = -1;
        for (int i = 0; i < N; ++i) {
            if (row[i] == 'X') last = i;
            left[i] = last;
        }

        last = -1;
        for (int i = N-1; i >= 0; --i) {
            if (row[i] == 'X') last = i;
            right[i] = last;
        }

        int max_dist = 0;
        for (int i = 0; i < N; ++i) {
            if (row[i] == '.') {
                int d_left = (left[i] == -1) ? N : i - left[i];
                int d_right = (right[i] == -1) ? N : right[i] - i;
                int dist = min(d_left, d_right);
                max_dist = max(max_dist, dist);
            }
        }
        cout << max_dist - 1 << endl;
    }
    return 0;
}