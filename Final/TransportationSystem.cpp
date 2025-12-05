#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

struct Edge {
    int u, v;
    double dist;
    bool operator<(const Edge& other) const {
        return dist < other.dist;
    }
};

double get_dist(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for(int i=0; i<n; ++i) parent[i] = i;
    }
    
    int find(int i) {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if(root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void solve(int t) {
    int n;
    double r;
    cin >> n >> r;
    
    vector<Point> cities(n);
    for(int i=0; i<n; ++i) {
        cin >> cities[i].x >> cities[i].y;
    }
    
    vector<Edge> edges;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            edges.push_back({i, j, get_dist(cities[i], cities[j])});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    double road_cost = 0;
    double rail_cost = 0;
    int states = n; 
    
    int edges_count = 0;
    for(const auto& edge : edges) {
        if(dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            
            if(edge.dist <= r) {
                road_cost += edge.dist;
                states--; 
            } else {
                rail_cost += edge.dist;
            }
            
            edges_count++;
        }
    }
    cout << "Case #" << t << ": " << states << " " << (int)round(road_cost) << " " << (int)round(rail_cost) << "\n";
}

int main() {
    int t;
    if(cin >> t) {
        for(int i=1; i<=t; ++i) {
            solve(i);
        }
    }
    return 0;
}