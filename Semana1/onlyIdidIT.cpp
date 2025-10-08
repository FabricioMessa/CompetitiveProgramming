#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; ++caso) {
        vector<set<int>> amigos(3);
        for (int i = 0; i < 3; ++i) {
            int S, p;
            cin >> S;
            for (int j = 0; j < S; ++j) {
                cin >> p;
                amigos[i].insert(p);
            }
        }
        vector<vector<int>> unique(3);
        for (int i = 0; i < 3; ++i) {
            set<int> otros;
            for (int j = 0; j < 3; ++j) {
                if (i != j)
                    otros.insert(amigos[j].begin(), amigos[j].end());
            }
            for (int prob : amigos[i]) {
                if (otros.count(prob) == 0)
                    unique[i].push_back(prob);
            }
            sort(unique[i].begin(), unique[i].end());
        }
        int maxCount = max({unique[0].size(), unique[1].size(), unique[2].size()});
        cout << "Case #" << caso << ":\n";
        for (int i = 0; i < 3; ++i) {
            if (unique[i].size() == maxCount && maxCount > 0) {
                cout << i+1 << " " << unique[i].size();
                for (int prob : unique[i])
                    cout << " " << prob;
                cout << "\n";
            }
        }
    }
    return 0;
}