#include <iostream>
#include <algorithm> 

using namespace std;

long long Com(int n, int m) {
    if (m == 0) {
        return 1;
    }
    if (m > n / 2) { 
        m = n - m;
    }

    long long res = 1;
    for (int i = 1; i <= m; ++i) {
        res = res * (n - i + 1); 
        res /= i;                
    }
    
    return res;
}

void sol() {
    int n;
    int m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        long long result = Com(n, m);
        cout << n << " things taken " << m << " at a time is " << result << " exactly.\n";
    }
}

int main() {
    sol();
    return 0;
}