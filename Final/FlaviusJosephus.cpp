#include <iostream>
#include <unordered_map>

using namespace std ;

long long siguiente (long long x, long long a, long long b, long long N){
    long long modX = x % N;                 
    long long cuadrado = (modX * modX) % N;   
    long long terminoA = (a * cuadrado) % N;  
    long long suma = terminoA + b;          
    long long resultado = suma % N;              
    return resultado;
}

int main(){
    long long N;
    long long a;
    long long b;
    while (cin >> N){
        if (N == 0) {
            break;
        }
        cin >> a >> b;
        unordered_map<long long, int> repetidos;
        long long vivos = N;
        long long actual = 0;
        for (long long paso = 0;; paso++){
            int &cnt = repetidos[actual];
            cnt++;                     

            if (cnt == 2){
                vivos--;
            }
            if (cnt == 3){
                break;
            }
            actual = siguiente(actual, a, b, N);
        }
        cout << vivos << "\n";
    }
    return 0 ;
}
