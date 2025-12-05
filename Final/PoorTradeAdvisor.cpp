#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, ppa;
};

struct DSU {
    vector<int> parent;
    vector<int> size; 

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1); 
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); 
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }

    int get_size(int i) {
        return size[find(i)];
    }
};

void solve() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<Edge> edges;
        edges.reserve(m); 
        int max_ppa = -2147483648; 
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            if (w > max_ppa) {
                max_ppa = w;
            }
        }
        DSU dsu(n);
        for (const auto& edge : edges) {
            if (edge.ppa == max_ppa) {
                dsu.unite(edge.u, edge.v);
            }
        }

        int max_cities = 0;
        for (int i = 1; i <= n; ++i) {
            int current_size = dsu.get_size(i);
            if (current_size > max_cities) {
                max_cities = current_size;
            }
        }

        cout << max_cities << "\n";
    }
}

int main() {
    solve();
    return 0;
}