#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

long long calcularMediana(vector<long long>& lista) {
    sort(lista.begin(), lista.end());
    int n = lista.size();
    if (n % 2 != 0) {
        return lista[n / 2];
    }
    else {
        return (lista[n / 2 - 1] + lista[n / 2]) / 2;
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<long long> a(n);
        long long suma = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            suma += a[i];
        }

        long long promedio = suma / n;
        vector<long long> c(n);
        long long acum = 0;
        for (int i = 0; i < n; ++i) {
            acum += a[i] - promedio;
            c[i] = acum;
        }

        long long mediana = calcularMediana(c);
        long long resultado = 0;
        for (int i = 0; i < n; ++i) {
            resultado += abs(c[i] - mediana);
        }

        cout << resultado << endl;
    }
    return 0;
}