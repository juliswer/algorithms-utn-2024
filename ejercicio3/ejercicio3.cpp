#include "iostream"
using namespace std;

struct Equipo {
    string nombre;
    int puntos;
};

struct Partido {
    Equipo rival1;
    Equipo rival2;
};

struct NodoLista {
    Equipo dato;
    NodoLista* siguiente;
};

struct NodoCola {
    Partido dato;
    NodoCola* siguiente;
};

struct PartidosCola {
    NodoCola* frente;
    NodoCola* final;
};

// lista
NodoLista* crearNodoEquipo(Equipo valor);
void imprimirEquipos(NodoLista* inicio);

// cola
NodoCola* crearNodoPartido(Partido valor);
void encolarPartido(NodoCola*& frente, NodoCola*& final, Partido valor);
Partido desencolarPartido(NodoCola*& frente, NodoCola*& final);
bool isEmptyPartidos(NodoCola* frente);
void imprimirPartidos(PartidosCola partidos);

// general
void crearEquipo(NodoLista*& equipos);
void imprimirEquipo(Equipo equipo);
void asignarPartido(PartidosCola& partidos, NodoLista* listaEquipos);
NodoLista* buscarEquipoEnLista(NodoLista* listaEquipos, string nombreEquipo);
void jugarPartidos(PartidosCola partidos, NodoLista*& listaEquipos);
Equipo verEquipoCampeon(NodoLista* listaEquipos);

int main() {
    NodoLista* listaEquipos = nullptr;
    PartidosCola partidosCola = {nullptr, nullptr};

    bool continuar = true;

    while(continuar) {
        int accion;
        cout << endl << endl;
        cout << "----- TORNEO DE FUTBOL -----" << endl;
        cout << "Que accion desea realizar?" << endl << endl;
        cout << "*[1]* Agregar Equipo" << endl;
        cout << "*[2]* Agregar Partido" << endl;
        cout << "*[3]* Jugar Partidos" << endl;
        cout << "*[4]* Ver Campeon" << endl;
        cout << "*[Otro]* Salir " << endl;
        cout << "-----";
        cout << endl << endl;

        cin >> accion;

        switch (accion) {
            case 1:
                crearEquipo(listaEquipos);
                imprimirEquipos(listaEquipos);
                break;
            case 2:
                asignarPartido(partidosCola, listaEquipos);
                break;
            case 3:
                jugarPartidos(partidosCola, listaEquipos);
                imprimirEquipos(listaEquipos);
                break;
            case 4:
                verEquipoCampeon(listaEquipos);
                break;
            default:
                cout << "Saliendo del sistema. Gracias" << endl;
                continuar = false;
                break;
        }
    }

    return 0;
}

// lista

NodoLista* crearNodoEquipo(Equipo valor) {
    NodoLista* nuevoNodo = new NodoLista;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void imprimirEquipos(NodoLista* inicio) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        imprimirEquipo(actual->dato);

        actual = actual->siguiente;
    }
    cout << endl;
}

// cola

void imprimirPartidos(PartidosCola partidos) {
    int i = 1;
    while(!isEmptyPartidos(partidos.frente)) {
        Partido partido = desencolarPartido(partidos.frente, partidos.final);
        cout << "PARTIDO #" << i << ":" << " [" << partido.rival1.nombre << "] VS. [" << partido.rival2.nombre << "]" << endl;
        i++;
    }
}

NodoCola* crearNodoPartido(Partido valor) {
    NodoCola* nuevoNodo = new NodoCola;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void encolarPartido(NodoCola*& frente, NodoCola*& final, Partido valor) {
    NodoCola* nuevoNodo = crearNodoPartido(valor);
    if (final == nullptr) {
        frente = final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
}

Partido desencolarPartido(NodoCola*& frente, NodoCola*& final) {
    if (frente == nullptr) {
        cerr << "La cola está vacía." << endl;
        return {{"", -1}, {"", -1}};
    }
    Partido valor = frente->dato;
    NodoCola* temp = frente;
    frente = frente->siguiente;
    if (frente == nullptr) {
        final = nullptr; // Si se elimina el último elemento, actualizar 'final'
    }
    delete temp;
    return valor;
}

bool isEmptyPartidos(NodoCola* frente) {
    return frente == nullptr;
}

// general

void crearEquipo(NodoLista*& equipos) {
    Equipo equipo;
    equipo.puntos = 0;

    cout << "Como se llama tu equipo nuevo?" << endl;
    cin >> equipo.nombre;

    NodoLista* nuevoNodo = crearNodoEquipo(equipo);

    if(equipos == nullptr) {
        equipos = nuevoNodo;
    } else {
        NodoLista* actual = equipos;
        while(actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void imprimirEquipo(Equipo equipo) {
    cout << "Nombre Equipo: [" << equipo.nombre << "] con [" << equipo.puntos << "] puntos" << endl;

    return;
}

NodoLista* buscarEquipoEnLista(NodoLista* listaEquipos, string nombreEquipo) {
    NodoLista* respuesta = nullptr;

    NodoLista* actual = listaEquipos;
    while (actual != nullptr) {
        if(actual->dato.nombre == nombreEquipo) {
            return actual;
        }
        actual = actual->siguiente;
    }
    
    return respuesta;
}

void asignarPartido(PartidosCola& partidos, NodoLista* listaEquipos) {
    string rival1Nombre, rival2Nombre;
    cout << "Nombre rival 1:" << endl;
    cin >> rival1Nombre;
    
    cout << "Nombre rival 2:" << endl;
    cin >> rival2Nombre;

    NodoLista* rival1 = buscarEquipoEnLista(listaEquipos, rival1Nombre);
    NodoLista* rival2 = buscarEquipoEnLista(listaEquipos, rival2Nombre);

    if(rival1->dato.puntos == -1) {
        return;
    }

    if(rival2->dato.puntos == -1) {
        return;
    }

    Partido nuevoPartido = {rival1->dato, rival2->dato};

    encolarPartido(partidos.frente, partidos.final, nuevoPartido);

    return;
}

void jugarPartidos(PartidosCola partidos, NodoLista*& listaEquipos) {
    srand(static_cast<unsigned int>(time(nullptr)));

    while(!isEmptyPartidos(partidos.frente)) {
        Partido partido = desencolarPartido(partidos.frente, partidos.final);

        cout << "JUGANDO PARTIDO: [" << partido.rival1.nombre << "] VS. [" << partido.rival2.nombre << "]" << endl;

        int min = 1;
        int max = 100;

        int random_number = rand() % (max - min + 1) + min;

        cout << "Numero RANDOM generado: " << random_number << endl;

        if(random_number % 3 == 1) {
            // gana rival1
            NodoLista* equipo1 = buscarEquipoEnLista(listaEquipos, partido.rival1.nombre);
            equipo1->dato.puntos += 3;
        } else if(random_number % 3 == 2) {
            // gana rival2
            NodoLista* equipo2 = buscarEquipoEnLista(listaEquipos, partido.rival2.nombre);
            equipo2->dato.puntos += 3;
        }  else {
            // empate
            NodoLista* equipo1 = buscarEquipoEnLista(listaEquipos, partido.rival1.nombre);
            NodoLista* equipo2 = buscarEquipoEnLista(listaEquipos, partido.rival2.nombre);
            equipo1->dato.puntos += 1;
            equipo1->dato.puntos += 1;
        }

    }

    if(partidos.frente == nullptr) {
        cout << "No hay partidos pendientes por jugar" << endl;
    }
}

Equipo verEquipoCampeon(NodoLista* listaEquipos) {
    NodoLista* actual = listaEquipos;
    Equipo campeon = listaEquipos->dato;

    while (actual != nullptr) {
        if(actual->dato.puntos > campeon.puntos) {
            campeon = actual->dato;
        }
        actual = actual->siguiente;
    }

    cout << "EL CAMPEON ES: "<< endl;
    imprimirEquipo(campeon);

    return campeon;
}