#include <iostream>
using namespace std;

void push (int n);
void pop();
void prt();

struct node {
    int data;
    node *nxt;
};

node *iStack = NULL;

void push (int n) {
    node *guide = new node;
    guide -> data = n;
    guide -> nxt = iStack;

    iStack = guide;
    cout << "Se introdujo el elemento: " << n << " en la cima de la pila.";
}

void prt() {
    node *guide = new node;
    guide = iStack;
    if (guide == NULL) {
        cout << "\n\n Ningun elemento en la pila.";
    } else {
        do {
            cout << guide -> data << " -> ";
            guide = guide -> nxt;
        } while (guide != NULL);
    }

}

void pop() {
    if (iStack == NULL) {
        cout << "\n\n Ningun elemento en la pila.";
    } else {
        iStack = iStack -> nxt;
    }
}


int main() {
    int opt, input;
    do {
        cout << "\n|-------------------------------------|";
        cout << "\n|              - Stack -              |";
        cout << "\n|------------------|------------------|";
        cout << "\n| 1. Push                             |";
        cout << "\n| 2. Pop                              |";
        cout << "\n| 3. Show                             |";
        cout << "\n|------------------|------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin >> opt;
        switch (opt){
            case 1:
                cout << "\n\n Inserte numero a push: ";
                cin >> input;
                push(input);
                break;
            case 2:
                cout << "\n\n Sacando el ultimo elemento almacenado en Stack: ";
                pop();
                break;
            case 3:
                cout << "\n\n Imprimiendo... ";
                prt();
                break;
            default:
                cout << "\n\n Problem has ocurred...";
                break;
        }

    } while (opt != 4);
    std::cout << "Hello World!\n";
}
