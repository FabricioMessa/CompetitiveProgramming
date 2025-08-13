#include <iostream>
using namespace std;

void operation(char a, char b, char letras[], int size){
    for(int i=0; i<size; i++){
        if(a == letras[i]){
            letras[i] = b;
        }
    }
    cout << "Resultado: ";
    for(int i=0; i < size; i++){
        cout << letras[i] << " ";
    }
}

int main() {
    int N;
    cout << "Digite el numero de letras: ";
    cin >> N;
    char A[N];
    for(int i=0; i<N; i++){
        cout << "Digite la letra " << i+1 << ": ";
        cin >> A[i];
    }
    int Q;
    cout << "Digite el numero de operaciones: ";
    cin >> Q;
    for(int i=0; i<Q; i++){
        cout << "Digite la letra que desea cambiar: ";
        char var1;
        cin >> var1;
        cout << "Digite la letra por la que desea cambiar: ";
        char var2;
        cin >> var2;
        operation(var1, var2, A, N);
        cout << endl;
    }
    return 0;
}