#include <iostream>
#include <cmath>

using namespace std;
using int64 = long long;

int64 egcd(int64 a, int64 b, int64 &x, int64 &y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int64 x1, y1;
    int64 g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main(){
    while (true){
        int64 n; cin >> n;
        if (n == 0) break;

        int64 c1, n1, c2, n2;
        cin >> c1 >> n1 >> c2 >> n2;

        int64 x0, y0;
        int64 g = egcd(n1, n2, x0, y0);

        if (n % g != 0){
            cout << "failed\n";
            continue;
        }

        int64 factor = n / g;
        x0 *= factor;
        y0 *= factor;
        int64 pasoX = n2 / g;
        int64 pasoY = n1 / g;

        long double t1 =(-(long double) x0) / pasoX;
        long double t2 = ((long double) y0) / pasoY;

        long long tMin = (long long) ceil(t1);
        long long tMax = (long long) floor(t2);

        if (tMin > tMax){
            cout << "failed\n";
            continue ;
        }

        auto costo = [&](long long t)->int64{
            int64 x = x0 + pasoX * t;
            int64 y = y0 - pasoY * t;
            return c1 * x + c2 * y;
        };

        long long mejorT = tMin;
        if (costo(tMax) < costo(tMin)){
            mejorT = tMax;
        }

        long long m1 = x0 + pasoX * mejorT;
        long long m2 = y0 - pasoY * mejorT;

        cout << m1 << " " << m2 << "\n";
    }
    return 0 ;
}
