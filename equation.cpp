#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Función para determinar la prioridad de los operadores
int Prioridad(char op) {
    if(op == '+' || op == '-') {
        return 1;
    }
    if(op == '*' || op == '/') {
        return 2;
    }
    return 0; // Para paréntesis u otros caracteres
}

// Función que convierte una expresión infija a postfija
void infixToPostfix(const string& expresion) {
    stack<char> operadores;
    string postfija = "";

    for(char c : expresion) {
        if(isdigit(c)) {
            postfija += c;
        }
        else if(c == '(') {
            operadores.push(c);
        }
        else if(c == ')') {
            while(!operadores.empty() && operadores.top() != '(') {
                postfija += operadores.top();
                operadores.pop();
            }
            if(!operadores.empty()) {
                operadores.pop(); // Saca el '('
            }
        }
        else { // Si es un operador
            while(!operadores.empty() && operadores.top() != '(' && Prioridad(c) <= Prioridad(operadores.top())) {
                postfija += operadores.top();
                operadores.pop();
            }
            operadores.push(c);
        }
    }

    while(!operadores.empty()) {
        postfija += operadores.top();
        operadores.pop();
    }
    cout << postfija << endl;
}

int main() {
    int num_casos;
    string linea_vacia;
    cin >> num_casos;
    getline(cin, linea_vacia); // Consume el resto de la línea después del entero

    for (int i = 0; i < num_casos; ++i) {
        // Ignora la línea en blanco entre expresiones, si no es la primera
        if (i > 0) {
            getline(cin, linea_vacia);
        }
        
        string expresion_completa = "";
        string linea;
        while (getline(cin, linea) && !linea.empty()) {
            expresion_completa += linea;
        }

        if (!expresion_completa.empty()) {
            infixToPostfix(expresion_completa);
        }
        
        // El problema pide una línea en blanco entre las salidas
        if (i < num_casos - 1) {
            cout << endl;
        }
    }

    return 0;
}