#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> pila;

    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout << "El elemento en la cima es: " << pila.top() << endl;
    pila.pop();

    cout << "El nuevo elemento en la cima es: " << pila.top() << endl;

    if(pila.empty()) {
        cout << "La pila está vacía." << endl;
    } else {
        cout << "La pila no está vacía. Tiene " << pila.size() << " elementos." << endl;
    }
    return 0;
}