#include "iostream"
using namespace std;

struct NodoCola {
    int dni;
    NodoCola* siguiente;
};

struct NodoLista {
    string especialidad;
    NodoLista* siguiente;
    NodoCola* colaFrente;
    NodoCola* colaFinal;
};

// cola
NodoCola* crearNodoCola(int dni);
void encolar(NodoCola*& frente, NodoCola*& final, int dni);
int desencolar(NodoCola*& frente, NodoCola*& final);
bool isEmptyCola(NodoCola* frente);

// lista
NodoLista* crearNodoLista(string especialidad);
// void imprimirListaSimple(NodoLista* inicio);
NodoLista* cargarLista(NodoLista* inicio, string especialidad);
bool existeElementoLista(NodoLista* inicio, string valor);
NodoLista* cargarSinRepetir(NodoLista* inicio, string valor);
NodoLista* buscarElementoLista(NodoLista* inicio, string especialidad);

// general
NodoLista* agregarEspecialidad(NodoLista* especialidades);
void agregarPaciente(NodoLista* especialidades);
void verSiguientesPacientes(NodoLista* especialidades);

int main() {
    NodoLista* especialidades = nullptr;
    bool continuar = true;
    int accion;

    while(continuar) {
        cout << "Accion a realizar:" << endl;
        cout << "*[0]*: Agregar Especialidad" << endl;
        cout << "*[1]*: Agregar Paciente" << endl;
        cout << "*[2]*: Ver Siguientes Pacientes" << endl;
        cout << "*[Otro]*: Salir" << endl;
        cin >> accion;

        switch(accion) {
            case 0:
                especialidades = agregarEspecialidad(especialidades);
                break;
            case 1:
                agregarPaciente(especialidades);
                break;
            case 2:
                verSiguientesPacientes(especialidades);
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
NodoLista* agregarEspecialidad(NodoLista* especialidades) {
    string especialidad;
    cout << "Nombre de la especialidad a crear" << endl;
    cin >> especialidad;

    if(buscarElementoLista(especialidades, especialidad)) {
        cout << "Especialidad ya existente" << endl;
        return especialidades;
    }

    return cargarLista(especialidades, especialidad);
}

void agregarPaciente(NodoLista* especialidades) {
    string especialidad = "";

    cout << "De que especialidad queres agregar el paciente?" << endl;
    cin >> especialidad;

    NodoLista* especialidadNodo = buscarElementoLista(especialidades, especialidad);

    if(especialidadNodo != nullptr) {
        int dni;
        cout << "Ingrese DNI a agregar" << endl;
        cin >> dni;

        encolar(especialidadNodo->colaFrente, especialidadNodo->colaFinal, dni);
        return;
    }
    
    cout << "Especialidad no encontrada. Saludos" << endl;
    return;
}

void verSiguientesPacientes(NodoLista* especialidades) {
    NodoLista* actual = especialidades;

    while(actual != nullptr) {
        cout << "ESPECIALIDAD : " << actual->especialidad << endl;
        cout << "Siguiente: " << endl;
        if(actual->colaFrente != nullptr) {
            cout << "DNI: " << actual->colaFrente->dni << endl;    
        } else {
            cout << "Disponible" << endl;
        }
        actual = actual->siguiente;
    }
}

// cola
NodoCola* crearNodoCola(int dni) {
    NodoCola* nuevoNodo = new NodoCola;
    nuevoNodo->dni = dni;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void encolar(NodoCola*& frente, NodoCola*& final, int dni) {
    NodoCola* nuevoNodo = crearNodoCola(dni);
    if (final == nullptr) {
        frente = final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
}

int desencolar(NodoCola*& frente, NodoCola*& final) {
    if (frente == nullptr) {
        cerr << "La cola está vacía." << endl;
        return -1; // Valor de error
    }
    int valor = frente->dni;
    NodoCola* temp = frente;
    frente = frente->siguiente;
    if (frente == nullptr) {
        final = nullptr; // Si se elimina el último elemento, actualizar 'final'
    }
    delete temp;
    return valor;
}

bool isEmptyCola(NodoCola* frente) {
    return frente == nullptr;
}

// lista
NodoLista* crearNodoLista(string especialidad) {
    NodoLista* nuevoNodo = new NodoLista;
    nuevoNodo->especialidad = especialidad;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->colaFrente = nullptr;
    nuevoNodo->colaFinal = nullptr;
    return nuevoNodo;
}

void imprimirListaSimple(NodoLista* inicio) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        cout << actual->especialidad << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

NodoLista* cargarLista(NodoLista* inicio, string especialidad) {
    NodoLista* nuevoNodo = crearNodoLista(especialidad);
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
        if (actual->especialidad == valor) {
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

NodoLista* buscarElementoLista(NodoLista* inicio, string especialidad) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        if (actual->especialidad == especialidad) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}