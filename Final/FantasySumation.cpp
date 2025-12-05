#include <iostream>
#include <vector>

using namespace std ;

long long potencia (long long base, long long expo, long long mod){
    long long resultado = 1 % mod;
    long long potencia  = base % mod;

    while (expo > 0){
        if (expo & 1){
            resultado = (resultado * potencia) % mod;
        }
        potencia = (potencia * potencia) % mod;
        expo >>= 1;
    }
    return resultado;
}

int main(){
    int casos; 
    cin >> casos;
    for (int id = 1; id <= casos; id++){
        int n;
        long long K;
        long long MOD;
        cin >> n >> K >> MOD;

        vector<long long> numeros(n);
        long long suma = 0;

        for (int i = 0; i < n; i++){
            cin >> numeros[i];
            long long valor = numeros[i] % MOD;
            suma += valor;
            if (suma >= MOD) {
                suma -= MOD;
            }
        }

        long long factorN = n % MOD;
        long long nPot = 1;                
        if (K > 1){
            nPot = potencia(factorN, K - 1, MOD);
        }

        long long coef = ((K % MOD) * nPot) % MOD;
        long long ans = (coef * suma) % MOD;

        cout << "Case " << id << ": " << ans << "\n";
    }
    return 0 ;
}
