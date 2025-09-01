#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int T;
    int caso = 1;
    cin >> T;

    while (T--) {
        // --- 1. Leer los problemas de los 3 amigos ---
        vector<vector<int>> solved_by_friends(3);
        map<int, int> problem_count;
        
        for (int i = 0; i < 3; ++i) {
            int S;
            cin >> S;
            solved_by_friends[i].resize(S);
            for (int j = 0; j < S; ++j) {
                cin >> solved_by_friends[i][j];
                problem_count[solved_by_friends[i][j]]++;
            }
        }
        
        // --- 2. Identificar y contar los problemas únicos por amigo ---
        vector<vector<int>> unique_problems(3);
        int unique_count[3] = {0, 0, 0};
        
        for (int i = 0; i < 3; ++i) {
            for (int problem : solved_by_friends[i]) {
                if (problem_count[problem] == 1) {
                    unique_problems[i].push_back(problem);
                    unique_count[i]++;
                }
            }
        }
        
        // --- 3. Encontrar el número máximo de problemas únicos ---
        int max_unique = 0;
        for (int i = 0; i < 3; ++i) {
            if (unique_count[i] > max_unique) {
                max_unique = unique_count[i];
            }
        }
        
        // --- 4. Ordenar y mostrar el o los ganadores ---
        cout << "Case #" << caso << ":" << endl;
        
        for (int i = 0; i < 3; ++i) {
            if (unique_count[i] == max_unique) {
                sort(unique_problems[i].begin(), unique_problems[i].end());
                cout << i + 1 << " " << unique_count[i];
                for (int problem : unique_problems[i]) {
                    cout << " " << problem;
                }
                cout << endl;
            }
        }
        
        caso++;
    }
    return 0;
}