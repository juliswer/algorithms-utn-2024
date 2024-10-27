#include "iostream"
using namespace std;

struct NodoPila {
    int codigoOperacion;
    NodoPila* siguiente;
};

struct NodoLista {
    string nombre;
    NodoLista* siguiente;
    NodoPila* operaciones;
};

// lista
NodoLista* crearNodoLista(string nombre);
NodoLista* cargarLista(NodoLista* inicio, string nombre);
bool existeElementoLista(NodoLista* inicio, string valor);
NodoLista* cargarSinRepetir(NodoLista* inicio, string valor);
NodoLista* buscarElementoLista(NodoLista* inicio, string nombre);

// pila
NodoPila* crearNodoPila(int codigoOperacion);
void push(NodoPila*& pila, int codigoOperacion);
int pop(NodoPila*& pila);
bool isEmptyPila(NodoPila* pila);

// general
NodoLista* agregarPestania(NodoLista* pestanias);
void agregarAccion(NodoLista* pestanias);
NodoLista* vaciarPestanias(NodoLista* pestanias);
void vaciarAcciones(NodoPila* acciones);
void leerPestanias(NodoLista* pestanias);

int main() {
    NodoLista* pestanias = nullptr;
    bool continuar = true;
    int accion;

    while(continuar) {
        cout << "Accion a realizar:" << endl;
        cout << "*[0]*: Agregar Pestania" << endl;
        cout << "*[1]*: Agregar Operacion" << endl;
        cout << "*[2]*: Vaciar Pestanias" << endl;
        cout << "*[3]*: Leer Pestanias" << endl;
        cout << "*[Otro]*: Salir" << endl;
        cin >> accion;

        switch(accion) {
            case 0:
                pestanias = agregarPestania(pestanias);
                break;
            case 1:
                agregarAccion(pestanias);
                break;
            case 2:
                pestanias = vaciarPestanias(pestanias);
                break;
            case 3:
                leerPestanias(pestanias);
                break;
            default:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
        }
    }

    return 0;
}

// general
void leerAcciones(NodoPila* acciones) {
    NodoPila* actual = acciones;
    while(actual != nullptr) {
        cout << "Operacion Nro: " << actual->codigoOperacion << endl;
        if(actual->siguiente != nullptr) {
            actual = actual->siguiente;
        } else {
            actual = nullptr;
        }
    }
}

void leerPestanias(NodoLista* pestanias) {
    NodoLista* actual = pestanias;

    while(actual != nullptr) {
        cout << "\n Leyendo pestania :" << actual->nombre << endl;
        cout << "Operaciones:" << endl;
        leerAcciones(actual->operaciones);
        if(actual->siguiente != nullptr) {
            actual = actual->siguiente;
        } else {
            actual = nullptr;
        }
    }
}

NodoLista* agregarPestania(NodoLista* pestanias) {
    string nombre;
    cout << "Nombre de la pestania " << endl;
    cin >> nombre;

    if(buscarElementoLista(pestanias, nombre)) {
        cout << "Pestania ya existente..." << endl;
        return pestanias;
    }

    return cargarLista(pestanias, nombre);
}

void agregarAccion(NodoLista* pestanias) {
    string nombre;
    cout << "Nombre de la pestania a agregarle la accion" << endl;
    cin >> nombre;

    NodoLista* pestania = buscarElementoLista(pestanias, nombre);

    if(pestania == nullptr) {
        cout << "Elemento no encontrado";
        return;
    }

    int accion;
    cout << "Codigo de la accion a realizar:" << endl;
    cin >> accion;

    push(pestania->operaciones, accion);

    return;
}

NodoLista* vaciarPestanias(NodoLista* pestanias) {
    NodoLista* actual = pestanias;

    while(actual != nullptr) {
        vaciarAcciones(actual->operaciones);
        NodoLista* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    return actual;
}

void vaciarAcciones(NodoPila* acciones) {
    while(!isEmptyPila(acciones)) {
        pop(acciones);
    }
}

// pila
NodoPila* crearNodoPila(int codigoOperacion) {
    NodoPila* nuevoNodo = new NodoPila;
    nuevoNodo->codigoOperacion = codigoOperacion;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void push(NodoPila*& pila, int codigoOperacion) {
    NodoPila* nuevoNodo = crearNodoPila(codigoOperacion);
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

int pop(NodoPila*& pila) {
    if (pila == nullptr) {
        cout << "La pila está vacía." << endl;
        return -1; // Valor de error
    }
    int valor = pila->codigoOperacion;
    NodoPila* temp = pila;
    pila = pila->siguiente;
    delete temp;
    return valor;
}

bool isEmptyPila(NodoPila* pila) {
    return pila == nullptr;
}

// lista
NodoLista* crearNodoLista(string nombre) {
    NodoLista* nuevoNodo = new NodoLista;
    nuevoNodo->nombre = nombre;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->operaciones = nullptr;
    return nuevoNodo;
}

void imprimirListaSimple(NodoLista* inicio) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        cout << actual->nombre << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

NodoLista* cargarLista(NodoLista* inicio, string nombre) {
    NodoLista* nuevoNodo = crearNodoLista(nombre);
    if (inicio == nullptr) {
        inicio = nuevoNodo;
    } else {
        NodoLista* actual = inicio;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
    return inicio;
}

bool existeElementoLista(NodoLista* inicio, string valor) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        if (actual->nombre == valor) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

NodoLista* cargarSinRepetir(NodoLista* inicio, string valor) {
    if (!existeElementoLista(inicio, valor)) {
        return cargarLista(inicio, valor);
    }
    return inicio;
}

NodoLista* buscarElementoLista(NodoLista* inicio, string nombre) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        if (actual->nombre == nombre) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}