#include <iostream>
using namespace std;

void push (int n);
void pop ();
void prt ();

struct node {
    int data;
    node *nxt;
};

node *iQueue = NULL;
node *fQueue = NULL;


void push (int n) {
    node *guide = new node;
    if (iQueue == NULL || fQueue == NULL) {
        guide -> data = n;
        guide -> nxt = NULL;

        fQueue = guide;
        iQueue = fQueue;
    } else {
        guide -> data = n;
        guide -> nxt = NULL;

        fQueue -> nxt = guide;
        fQueue = guide;
    }
}

void prt () {
    node *guide = new node;
    guide = iQueue;
    if (iQueue == NULL) {
        cout << "Lista vacia.";
    } else {
        do {
            cout << " -> " << guide -> data;
            guide = guide -> nxt;
        } while (guide != NULL);
    }
}

void pop () {
    if (iQueue == NULL) {
        cout << "\n\n Lista vacia: ";
    } else if (iQueue -> nxt == NULL) {
        cout << "\n\n Se ha eliminado el primer elemento de la lista: " << iQueue -> data << " y ya no queda ningun elemento en la lista.";
        iQueue = iQueue -> nxt;
        iQueue = NULL;
        fQueue = NULL;
        cout << "Pulse 3 en el menu para comprobar...";
    } else {
        cout << "\n\n Se ha eliminado el primer elemento de la lista: " << iQueue -> data;
        iQueue = iQueue -> nxt;
        cout << ", pulse 3 en el menu para comrpobar...";
    }

}

int main() {
    int input, opt;
    do {
        cout << "\n|-------------------------------------|";
        cout << "\n|              ° Queue °              |";
        cout << "\n|------------------|------------------|";
        cout << "\n| 1. Push                             |";
        cout << "\n| 2. Pop                              |";
        cout << "\n| 3. Show                             |";
        cout << "\n|------------------|------------------|";
        cout << "\n\n Escoja una Opcion: ";
        cin >> input;
        switch (input) {
            case 1:
                cout << "\n\n Inserte numero a push: ";
                cin >> opt;
                push(opt);
                break;
            case 2:
                cout << "\n\n Sacando el primer elemento almacenado en Queue: ";
                pop();
                break;
            case 3:
                cout << "\n\n Imprimiendo... ";
                prt();
                break;
            default:
                cout << "Problem has ocurred....";
                break;
        }
    } while (input != 4);

    return 0;
}
