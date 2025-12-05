#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

const int MAXN = 1005;

vector<int> ady[MAXN];
int tin[MAXN];
int low[MAXN];
int tiempoGlobal;
vector<pair<int,int>> listaPuentes;
int n, m;

void dfs(int u, int padre){
    tiempoGlobal++;
    tin[u] = tiempoGlobal;
    low[u] = tiempoGlobal;

    for (int v : ady[u]) {
        if (v == padre) {
            continue;
        }
        if (tin[v] == 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > tin[u] ){
                int menor = min(u, v);
                int mayor = max(u, v);
                listaPuentes.push_back({menor, mayor});
            }
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
}

int main(){
    while (cin >> n >> m , n || m){
        for (int i = 0; i < n; i++){
            ady[i].clear();
            tin[i] = 0;
            low[i] = 0;
        }
        listaPuentes.clear();
        tiempoGlobal = 0;

        for (int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            ady[a].push_back(b);
            ady[b].push_back(a);
        }

        dfs(0, -1);     

        sort(listaPuentes.begin(), listaPuentes.end());

        cout << listaPuentes.size();
        for (auto par : listaPuentes){
            int u = par.first;
            int v = par.second;
            cout << " " << u << " " << v;
        }
        cout << "\n";
    }
    return 0;
}
