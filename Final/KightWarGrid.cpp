#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Point {
    int r, c;
};

void solve(int t) {
    int R, C, M, N;
    cin >> R >> C >> M >> N;
    int W;
    cin >> W;

    vector<vector<int>> grid(R, vector<int>(C, 0));
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (int i = 0; i < W; ++i) {
        int r, c;
        cin >> r >> c;
        grid[r][c] = -1; // Agua
    }

    set<pair<int, int>> moves;
    int dr[] = {-1, -1, 1, 1};
    int dc[] = {-1, 1, -1, 1};
    
    for (int i = 0; i < 4; ++i) {
        moves.insert({dr[i] * M, dc[i] * N});
        moves.insert({dr[i] * N, dc[i] * M});
    }

    int even_squares = 0;
    int odd_squares = 0;
    queue<Point> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        int valid_neighbors_count = 0;

        for (auto mv : moves) {
            int nr = curr.r + mv.first;
            int nc = curr.c + mv.second;
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != -1) {
                valid_neighbors_count++; 
                if (!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        if (valid_neighbors_count % 2 == 0) {
            even_squares++;
        } else {
            odd_squares++;
        }
    }

    cout << "Case " << t << ": " << even_squares << " " << odd_squares << "\n";
}

int main() {
    int T;
    if (cin >> T) {
        for (int i = 1; i <= T; ++i) {
            solve(i);
        }
    }
    return 0;
}