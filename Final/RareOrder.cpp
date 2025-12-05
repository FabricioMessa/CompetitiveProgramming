#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std ;

int main(){
    vector<string> palabras;
    string linea;
    while (getline(cin, linea)){
        if (linea == "#") {
            break;
        }
        if (!linea.empty()){
            palabras.push_back(linea);
        }
    }

    set<char> abecedario;
    for(const string &s : palabras)
        for(char ch : s)
            abecedario.insert(ch);

    const int ALF = 26;
    vector<vector<int>> grafo(ALF);
    vector<int> indeg (ALF, 0);

    for(size_t i = 1; i < palabras.size(); i++){
        const string &prev = palabras[i - 1];
        const string &curr = palabras[i];
        size_t limite = min(prev.size(), curr.size());

        for(size_t pos = 0; pos < limite; pos++){
            char c1 = prev[pos];
            char c2 = curr[pos];
            if (c1 != c2){
                int u = c1 - 'A';
                int v = c2 - 'A';
                if (find(grafo[u].begin(), grafo[u].end(), v) == grafo[u].end()){
                    grafo[u].push_back(v);
                    indeg[v]++;
                }
                break ;         
            }
        }
    }

    queue<int> cola;
    for(char ch : abecedario){
        int idx = ch - 'A';
        if (indeg[idx] == 0){
            cola.push(idx);
        }
    }

    string orden;
    while (!cola.empty()){
        int u = cola.front();
        cola.pop();
        char letra = 'A' + u;
        orden.push_back(letra);

        for(int v : grafo[u]){
            indeg[v]--;
            if (indeg[v] == 0){
                cola.push(v);
            }
        }
    }

    cout << orden << "\n";
    return 0 ;
}
