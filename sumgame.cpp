#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N-1];
    for(int i=0; i < N-1; i++){
        cin >> A[i];
    }
    int sum = 0;
    for(int i=0; i < N-1; i++){
        sum += A[i];
    }
    cout << -sum;
    return 0;
}