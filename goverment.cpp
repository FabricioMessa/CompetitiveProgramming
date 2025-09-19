#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    int P;
    int C;
    int caso = 1;
    while (cin >> P >> C && (P || C)) {
        cout << "Case " << caso++ << ":\n";
        int limite;
        if (C < P) {
            limite = C;
        } else {
            limite = P;
        }
        list<int> cola;
        
        for (int i = 1; i <= limite; ++i) { 
            cola.push_back(i); 
        }

        while (C--) {
            char cmd; 
            cin >> cmd;
            if (cmd == 'N') {
                int id = cola.front(); 
                cola.pop_front();
                cout << id << '\n';
                cola.push_back(id);
            } else {                    
                int x; 
                cin >> x;
                cola.remove(x);
                cola.push_front(x);
            }
        }
    }
    return 0;
}