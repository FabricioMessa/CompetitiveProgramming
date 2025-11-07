#include <iostream>

using namespace std;

struct Matrix {
    long long mat[2][2];
    Matrix(){
        mat[0][0] = 0;
        mat[0][1] = 0;
        mat[1][1] = 0;
        mat[1][0] = 0;
    }
};

long long Mod;

Matrix multi(Matrix a, Matrix b) {
    Matrix c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % Mod;
            }
        }
    }
    return c;
}

Matrix potencia(Matrix a, long long n) {
    Matrix result;
    result.mat[0][0] = 1;
    result.mat[1][1] = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            result = multi(result, a);
        }
        a = multi(a, a);
        n /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a;
        long long b;
        long long n;
        long long m;
        cin >> a >> b >> n >> m;

        Mod = 1;
        for (int i = 0; i < m; i++) {
            Mod *= 10;
        }

        if (n == 0) {
            cout << a % Mod << endl;
            continue;
        }
        if (n == 1) {
            cout << b % Mod << endl;
        }

        Matrix T;
        T.mat[0][0] = 1;
        T.mat[0][1] = 1;
        T.mat[1][0] = 1;
        T.mat[1][1] = 0;

        Matrix T_pow = potencia(T, n - 1);

        long long ans = (T_pow.mat[0][0] * b + T_pow.mat[0][1] * a) % Mod;
        cout << ans << endl;
    }
    return 0;
}

