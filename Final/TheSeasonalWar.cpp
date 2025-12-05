#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<string> grid;
int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

void dfs(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N || grid[r][c] == '0') {
        return;
    }
    grid[r][c] = '0';
    for (int i = 0; i < 8; ++i) {
        dfs(r + dr[i], c + dc[i]);
    }
}

void solve(int image_num) {
    grid.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    int eagle_count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == '1') {
                eagle_count++;
                dfs(i, j);
            }
        }
    }

    cout << "Image number " << image_num << " contains " << eagle_count << " war eagles." << endl;
}

int main() {
    int image_num = 1;
    while (cin >> N) {
        solve(image_num++);
    }
    return 0;
}