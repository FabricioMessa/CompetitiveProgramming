#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    while (true) {
        long long numSoldados;
        cin >> numSoldados;
        if (!cin || numSoldados == 0) {
            break;
        }

        long long constanteA;
        long long constanteB;
        cin >> constanteA >> constanteB;  

        unordered_map<long long, int> cuenta;
        long long actual = 0;
        cuenta[actual] = 1;
        int muertes = 0;

        while (true) {
            long long t1 = (actual * actual) % numSoldados;
            long long t2 = (constanteA * t1) % numSoldados;
            long long siguiente = (t2 + constanteB) % numSoldados;
            actual = siguiente;
            cuenta[actual] = cuenta[actual] + 1;
            if (cuenta[actual] == 2) {
                muertes = muertes + 1;
            }
            else if (cuenta[actual] == 3) {
                break;
            }
        }

        long long sobrevivientes = numSoldados - muertes;
        cout << sobrevivientes << endl;
    }

    return 0;
}

