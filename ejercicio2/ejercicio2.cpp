#include "iostream"
using namespace std;

/*
### Nuevo banco

1. **Cola del banco:** Implementa una estructura de datos para representar una cola en un banco. Añade funciones para ingresar un cliente a la cola (encolar), atender al próximo cliente (desencolar) y mostrar al próximo cliente en ser atendido (primero en la cola).
2. **Cola de prioridad:** Implementa una cola de prioridad en la cola del banco. Todas las personas mayores de 65 años tendrán prioridad.

*/

struct Persona {
    string nombre;
    int edad;
};

struct Nodo {
    Persona dato;
    Nodo* siguiente;
};

struct Cola {
    Nodo* frente;
    Nodo* final;
};

Nodo* crearNodo(Persona valor);
void encolar(Nodo*& frente, Nodo*& final, Persona valor);
Persona desencolar(Nodo*& frente, Nodo*& final);
bool isEmpty(Nodo* frente);

int main() {
    cout << "Hello world!" << endl;
    Cola colaGeneral = {nullptr, nullptr};
    Cola colaPrioridad = {nullptr, nullptr};

    Persona persona1;
    persona1.nombre = "Maria";
    persona1.edad = 90;

    Persona persona2;
    persona2.nombre = "Marta";
    persona2.edad = 80;

    Persona persona3;
    persona3.nombre = "Antonia";
    persona3.edad = 70;

    Persona persona4;
    persona4.nombre = "Luis";
    persona4.edad = 32;

    Persona persona5;
    persona5.nombre = "Romina";
    persona5.edad = 23;

    Persona persona6;
    persona6.nombre = "Jorge";
    persona6.edad = 57;

    encolar(colaGeneral.frente, colaGeneral.final, persona1);
    encolar(colaGeneral.frente, colaGeneral.final, persona2);
    encolar(colaGeneral.frente, colaGeneral.final, persona3);
    encolar(colaGeneral.frente, colaGeneral.final, persona4);
    encolar(colaGeneral.frente, colaGeneral.final, persona5);
    encolar(colaGeneral.frente, colaGeneral.final, persona6);

    cout << "---- COLA GENERAL ----" << endl;
    while(!isEmpty(colaGeneral.frente)) {
        Persona persona = desencolar(colaGeneral.frente, colaGeneral.final);

        cout << "Estas viendo a: [" << persona.nombre << "] y tiene [" << persona.edad << "] anios" << endl;

        if(persona.edad >= 65) {
            encolar(colaPrioridad.frente, colaPrioridad.final, persona);
        }

    }

    cout << endl << endl;

    cout << "---- COLA PRIORIDAD ----" << endl;
    while(!isEmpty(colaPrioridad.frente)) {
        Persona persona = desencolar(colaPrioridad.frente, colaPrioridad.final);

        cout << "Estas viendo a: [" << persona.nombre << "] y tiene [" << persona.edad << "] anios" << endl;
    }

    return 0;
}

Nodo* crearNodo(Persona valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void encolar(Nodo*& frente, Nodo*& final, Persona valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    if (final == nullptr) {
        frente = final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
}

Persona desencolar(Nodo*& frente, Nodo*& final) {
    if (frente == nullptr) {
        cerr << "La cola está vacía." << endl;
        return {"", -1};
    }
    Persona valor = frente->dato;
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