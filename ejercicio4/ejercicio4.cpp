#include "iostream"
using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
};

struct Cola {
    Nodo* frente;
    Nodo* final;
};

struct Espectaculo {
    string nombreArtista;
    int cantidadPublicoMax;
    int cantidadTicketsComprados;
    Cola cola;
};

Nodo* crearNodo(string valor);
void encolar(Nodo*& frente, Nodo*& final, string valor);
string desencolar(Nodo*& frente, Nodo*& final);
bool isEmpty(Nodo* frente);
void venderTickets(Espectaculo espectaculo);

int main() {
    Espectaculo espectaculo;
    espectaculo.nombreArtista = "Viejas Locas";
    espectaculo.cantidadPublicoMax = 200;
    espectaculo.cantidadTicketsComprados = 195;
    espectaculo.cola.frente = nullptr;
    espectaculo.cola.final = nullptr;

    encolar(espectaculo.cola.frente, espectaculo.cola.final, "Tato");
    encolar(espectaculo.cola.frente, espectaculo.cola.final, "Jesus");
    encolar(espectaculo.cola.frente, espectaculo.cola.final, "Romina");

    venderTickets(espectaculo);

    return 0;
}

Nodo* crearNodo(string valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void encolar(Nodo*& frente, Nodo*& final, string valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    if (final == nullptr) {
        frente = final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
}

string desencolar(Nodo*& frente, Nodo*& final) {
    if (frente == nullptr) {
        cerr << "La cola está vacía." << endl;
        return "n/a"; // Valor de error
    }
    string valor = frente->dato;
    Nodo* temp = frente;
    frente = frente->siguiente;
    if (frente == nullptr) {
        final = nullptr; // Si se elimina el último elemento, actualizar 'final'
    }
    delete temp;
    return valor;
}

bool isEmpty(Nodo* frente) {
    return frente == nullptr;
}

void venderTickets(Espectaculo espectaculo) {
    int ticketsDisponibles = espectaculo.cantidadPublicoMax - espectaculo.cantidadTicketsComprados;

    cout << "Tickets disponibles: [" << ticketsDisponibles << "]" << endl << endl;

    while(!(isEmpty(espectaculo.cola.frente))) {
        if(ticketsDisponibles > 0) {
            string comprador = desencolar(espectaculo.cola.frente, espectaculo.cola.final);
            cout << "Ticket adquirido por: " << comprador << endl;
            ticketsDisponibles--;
            cout << "Queda/n [" << ticketsDisponibles << "] ticket/s" << endl;
        } else {
            cout << "SOLD OUT DE " << espectaculo.nombreArtista << endl;
            return;
        }
    }
}