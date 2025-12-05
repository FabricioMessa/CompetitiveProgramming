#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
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
            parent[root_i] = root_j;
        }
    }
};

void solve() {
    int m, n;
    while (cin >> m >> n && (m != 0 || n != 0)) {
        vector<Edge> edges;
        long long total_cost = 0;
        for (int i = 0; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            total_cost += w;
        }
        sort(edges.begin(), edges.end());
        DSU dsu(m);
        long long mst_cost = 0;
        int edges_count = 0;
        
        for (const auto& edge : edges) {
            if (dsu.find(edge.u) != dsu.find(edge.v)) {
                dsu.unite(edge.u, edge.v);
                mst_cost += edge.weight;
                edges_count++;
            }
        }
        cout << total_cost - mst_cost << "\n";
    }
}

int main() {
    solve();
    return 0;
}