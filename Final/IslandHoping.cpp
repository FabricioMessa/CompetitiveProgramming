#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

struct Island {
    double x, y;
    int population;
};

double get_dist(const Island& a, const Island& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void solve(int n, int case_num) {
    vector<Island> islands(n);
    double total_population = 0;

    for (int i = 0; i < n; ++i) {
        cin >> islands[i].x >> islands[i].y >> islands[i].population;
        total_population += islands[i].population;
    }

    vector<double> dist_to_tree(n, numeric_limits<double>::max());
    vector<int> parent(n, -1);
    vector<bool> in_mst(n, false);

    dist_to_tree[0] = 0;
    
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (!in_mst[v]) {
                if (u == -1 || dist_to_tree[v] < dist_to_tree[u]) {
                    u = v;
                }
            }
        }
        in_mst[u] = true;
        for (int v = 0; v < n; ++v) {
            if (!in_mst[v]) {
                double weight = get_dist(islands[u], islands[v]);
                if (weight < dist_to_tree[v]) {
                    dist_to_tree[v] = weight;
                    parent[v] = u;
                }
            }
        }
    }
    double total_weighted_time = 0;

    for (int i = 0; i < n; ++i) {
        if (i == 0) continue;
        double max_edge_on_path = 0;
        int curr = i;
        
        while (curr != 0) {
            int p = parent[curr];
            double edge_w = get_dist(islands[curr], islands[p]);
            if (edge_w > max_edge_on_path) {
                max_edge_on_path = edge_w;
            }
            
            curr = p;
        }
        total_weighted_time += max_edge_on_path * islands[i].population;
    }
    cout << "Island Group: " << case_num << " Average " << fixed << setprecision(2) << (total_weighted_time / total_population) << "\n"; 
    cout << "\n";
}

int main() {
    int n, case_num = 1;
    while (cin >> n && n != 0) {
        solve(n, case_num++);
    }
    return 0;
}