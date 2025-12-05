#include <iostream>
#include <vector>

using namespace std;

const int LIM = 1000000;

int  primoMenor [LIM + 1];         
int  totalPrimos[LIM + 1];        
double esperada [LIM + 1];         

void construirCriba(){
    for (int i = 2; i <= LIM; i++){
        if (primoMenor[i] == 0){
            primoMenor[i] = i;
            if (1LL * i * i <= LIM){
                for (int j = i * i; j <= LIM; j += i){
                    if (primoMenor[j] == 0) primoMenor[j] = i;
                }
            }
        }
        totalPrimos[i] = totalPrimos[i - 1] + (primoMenor[i] == i);
    }
}

int main(){
    construirCriba();
    esperada[1] = 0.0; 

    for (int x = 2; x <= LIM; x++){
        int aux = x;
        vector<int> divisoresPrimos;
        while (aux > 1){
            int p = primoMenor[aux];
            divisoresPrimos.push_back(p);
            while (aux % p == 0) aux /= p;
        }

        int k = divisoresPrimos.size();      
        int P = totalPrimos[x];           
        double sumaEsperadas = 0.0;
        for (int p : divisoresPrimos){
            int siguiente = x / p;
            sumaEsperadas += esperada[siguiente];
        }
        double promedio = sumaEsperadas / k;

        double coef = static_cast<double>(P) / k;
        esperada[x] = coef + promedio;     // fórmula derivada
    }

    int casos; 
    cin >> casos;
    cout.setf(ios::fixed);
    cout.precision(10);

    for (int id = 1; id <= casos; id++){
        int n; 
        cin >> n;
        cout << "Case " << id << ": " << esperada[n] << "\n";
    }
    return 0 ;
}
