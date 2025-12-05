#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long MOD;

struct Matrix {
    long long mat[2][2];
    Matrix() {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
    }
};

Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, int p) {
    Matrix res;
    res.mat[0][0] = 1; res.mat[1][1] = 1;
    A.mat[0][1] = 1;
    while (p > 0) {
        if (p & 1) res = multiply(res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return res;
}

void solve() {
    long long a;
    long long b;
    int n;
    int m;
    cin >> a >> b >> n >> m;
    MOD = 1;
    for(int i=0; i<m; ++i) MOD *= 10;

    if (n == 0) {
        cout << a % MOD << "\n";
        return;
    }
    if (n == 1) {
        cout << b % MOD << "\n";
        return;
    }
    Matrix T;
    T.mat[0][0] = 1; T.mat[0][1] = 1;
    T.mat[1][0] = 1; T.mat[1][1] = 0;
    T = power(T, n - 1);
    long long ans = (T.mat[0][0] * (b % MOD)) % MOD;
    ans = (ans + (T.mat[0][1] * (a % MOD)) % MOD) % MOD;

    cout << ans << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}