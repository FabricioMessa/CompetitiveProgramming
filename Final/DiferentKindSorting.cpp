#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int max_n = 2000005;
int spf[max_n];
int fac_count[max_n];
vector<int> numbers;

void sieve() {
    for (int i = 1; i < max_n; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < max_n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < max_n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void countFactors() {
    fac_count[1] = 0; 
    for (int i = 2; i < max_n; i++) {
        fac_count[i] = 1 + fac_count[i / spf[i]];
    }
}

bool compare(int a, int b) {
    if (fac_count[a] != fac_count[b]) {
        return fac_count[a] < fac_count[b];
    }
    return a < b;
}

int main() {
    sieve();
    countFactors();
    for (int i = 1; i <= 2000000; i++) {
        numbers.push_back(i);
    }
    sort(numbers.begin(), numbers.end(), compare);
    int n;
    int caseNum = 1;
    while (cin >> n && n != 0) {
        cout << "Case " << caseNum++ << ": " << numbers[n - 1] << "\n";
    }
    return 0;
}