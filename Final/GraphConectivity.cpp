#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
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
            return true;
        }
        return false; 
    }
};

void solve() {
    string line;
    if (!getline(cin, line) || line.empty()) return;

    char max_char = line[0];
    int n = max_char - 'A' + 1; 
    int connected_components = n;
    DSU dsu(n);

    while (getline(cin, line) && !line.empty()) {
        int u = line[0] - 'A';
        int v = line[1] - 'A';
        if (dsu.unite(u, v)) {
            connected_components--;
        }
    }
    cout << connected_components << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        cin.ignore();
        cin.ignore(); 
        while (t--) {
            solve();
            if (t > 0) cout << "\n";
        }
    }
    return 0;
}