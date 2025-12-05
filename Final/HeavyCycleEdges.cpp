#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    int weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for(int i = 0; i < n; ++i) parent[i] = i;
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

void solve(int n, int m) {
    vector<Edge> edges;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<int> heavy_edges;

    for(const auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
        } else {
            heavy_edges.push_back(edge.weight);
        }
    }

    if (heavy_edges.empty()) {
        cout << "forest" << "\n";
    } else {
        for(size_t i = 0; i < heavy_edges.size(); ++i) {
            cout << heavy_edges[i] << (i == heavy_edges.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        solve(n, m);
    }
    return 0;
}