#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, w;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w > b.w;
}

struct DSU {
    vector<int> parent;
    vector<int> sz; 

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); 
        sz.assign(n + 1, 1); 
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); 
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            sz[root_j] += sz[root_i];
            return true;
        }
        return false;
    }
    
    int getSize(int i) {
        return sz[find(i)];
    }
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(n);
    long long total_candidates_size = 0;

    int i = 0;
    while (i < m) {
        int j = i;
        while (j < m && edges[j].w == edges[i].w) {
            j++;
        }
        vector<int> merge_indices;
        for (int k = i; k < j; ++k) {
            if (dsu.find(edges[k].u) != dsu.find(edges[k].v)) {
                dsu.unite(edges[k].u, edges[k].v);
                merge_indices.push_back(k); 
            }
        }
        vector<int> unique_roots;
        for (int idx : merge_indices) {
            unique_roots.push_back(dsu.find(edges[idx].u));
        }
        sort(unique_roots.begin(), unique_roots.end());
        unique_roots.erase(unique(unique_roots.begin(), unique_roots.end()), unique_roots.end());
        for (int root : unique_roots) {
            total_candidates_size += dsu.sz[root];
        }
        i = j;
    }
    cout << total_candidates_size << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}