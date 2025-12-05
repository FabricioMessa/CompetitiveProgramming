#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> grid;
int R, C;
int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

int dfs(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] == '0') {
        return 0;
    }
    grid[r][c] = '0';
    
    int size = 1;
    for (int i = 0; i < 8; ++i) {
        size += dfs(r + dr[i], c + dc[i]);
    }

    return size;
}

void solve() {
    R = grid.size();
    if (R == 0) {
        cout << "0\n";
        return;
    }
    C = grid[0].size();

    int max_blob = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == '1') {
                int current_blob = dfs(i, j);
                if (current_blob > max_blob) {
                    max_blob = current_blob;
                }
            }
        }
    }

    cout << max_blob << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        cin.ignore(); 
        cin.ignore(); 
        
        while (t--) {
            grid.clear();
            string line;
            while (getline(cin, line) && !line.empty()) {
                grid.push_back(line);
            }
            solve();
            if (t > 0) cout << "\n";
        }
    }

    return 0;
}