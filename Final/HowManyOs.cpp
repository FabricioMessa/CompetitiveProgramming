#include <iostream>
#include <cmath>

using namespace std ;
using int64 = long long ;

int64 contarCerosHasta(int64 limite){
    if (limite < 0) {
        return 0;
    }

    int64 total = 1;              
    int64 factor = 1;

    while (factor <= limite) {
        int64 parteAlta  = limite / (factor * 10) ;
        int64 digActual  = (limite / factor) % 10 ;
        int64 parteBaja  = limite % factor;

        if (digActual == 0){
            if (parteAlta > 0){
                total += (parteAlta - 1) * factor;
                total += parteBaja + 1;
            }
        } 
        else {
            total += parteAlta * factor;
        }
        factor *= 10;
    }
    return total;
}

int main(){
    long long m;
    long long n;
    while (cin >> m >> n){
        if (m < 0 && n < 0) {
            break;
        }
        if (m > n) {
            swap(m, n);
        }
        long long respuesta = contarCerosHasta(n)- contarCerosHasta(m - 1);
        cout << respuesta << "\n";
    }
    return 0 ;
}
