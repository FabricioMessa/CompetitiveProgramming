#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Med {
    int tiempo;
    int idx;
    int freq;
    string nombre;

    bool operator < (const Med& o) const {
        if(tiempo != o.tiempo) {
            return tiempo > o.tiempo;
        }
        return idx > o.idx;
    }
};

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        int k;
        cin >> n >> k;
        priority_queue<Med> pq;
        for (int j = 0; j < n; ++j) {
            string nombre;
            int f;
            cin >> nombre >> f;
            pq.push({f, j, f, nombre});
        }

        while(k--) {
            Med cur = pq.top();
            pq.pop();
            cout << cur.tiempo << " " << cur.nombre << endl;
            cur.tiempo += cur.freq;
            pq.push(cur);
        }
    }
    return 0;
}