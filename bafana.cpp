#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createCircularList(int n) {
    if (n <= 0){ 
        return nullptr;
    }

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 1; i <= n; i++) {
        Node* newNode = new Node();
        newNode->data = i;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head;
    return head;
}

int main() {
    int c;
    cin >> c;
    while(c--){
        int n, v, mv;
        int bucle = 1;
        cin >> n >> v >> mv;
        Node* head = createCircularList(n);

        Node* current = head;
        while (current->data != v && current->next != head) {
            current = current->next;
        }
        if (current->data != v) {
            cout << "Nodo de inicio no encontrado." << endl;
            return 1;
        }

        for (int i = 0; i < mv; ++i) {
            current = current->next;
        }

        cout << "Case " << bucle << ": " << current->data << endl;
        
        Node* p = head;
        while (p->next != head) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
        delete p;
        bucle+=1;
    }    
    return 0;
}