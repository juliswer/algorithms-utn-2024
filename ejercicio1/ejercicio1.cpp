#include "iostream"

using namespace std;

struct Cancion {
    string artista;
    string titulo;
    int calificacion;
};

struct Nodo {
    Cancion cancion;
    Nodo* siguiente;
};

void push(Nodo*& pila, string titulo, string artista, int calificacion);
float ver_estrellas_promedio(Nodo* pila);
Cancion pop(Nodo*& pila);
Nodo* crearNodo(string titulo, string artista, int calificacion);
void revertir_playlist(Nodo*& original);
void historial(Nodo*& pila);
void recorrer_pila(Nodo* pila);
float ver_estrellas_promedio(Nodo* pila);
Nodo* eliminarNodo(Nodo* inicio);
void mostrar_historial_filtrado(Nodo* historial);
Nodo* push_ordenado_historial(Nodo*& historial, string titulo, string artista, int calificacion);

int main() {
    Nodo* pila = nullptr;
    bool continuar = true;
    int respuesta;
    string cancion_respuesta;
    string artista_respuesta;
    
    while(continuar) {
        cout << endl << endl << "------ Entrando al Menu ------" << endl;
        cout << endl << endl<< "Que queres hacer?" << endl;
        cout << "[1]: Agregar cancion a la pila" << endl;
        cout << "[2]: Mover siguiente cancion" << endl;
        cout << "[3]: Ver siguiente cancion sin moverla" << endl;
        cout << "[4]: Revertir Playlist" << endl;
        cout << "[5]: Historial" << endl;
        cin >> respuesta;

        switch(respuesta) {
            case 1:
                cout << "ENTRASTE EN LA OPCION 1" << endl;
                cout << "Como se llama la siguiente cancion?" << endl;
                cin >> cancion_respuesta;
                cout << "Quien la compuso?" << endl;
                cin >> artista_respuesta;
                push(pila, cancion_respuesta, artista_respuesta, -1);
                cancion_respuesta = "";
                artista_respuesta = "";
                break;
            case 2:
                cout << "ENTRASTE EN LA OPCION 2" << endl;
                cancion_respuesta = pop(pila).titulo;
                cout << "Siguiente cancion: " << cancion_respuesta << endl;
                cancion_respuesta = "";
                break;
            case 3:
                cout << "ENTRASTE EN LA OPCION 3" << endl;
                if(pila == nullptr) {
                    cout << "No hay siguiente" << endl;
                } else {
                    cancion_respuesta = pila->cancion.titulo;
                    cout << "Siguiente cancion: " << cancion_respuesta << endl;
                    cancion_respuesta = "";
                }
                break;
            case 4:
                cout << "---- PRE-REVERSO ----" << endl;
                cout << "ACTUAL: " << pila->cancion.titulo << endl;
                cout << "SIGUIENTE: " << pila->siguiente->cancion.titulo << endl;
                cout << "SIGUIENTE DEL SIGUIENTE: " << pila->siguiente->siguiente->cancion.titulo << endl;
                
                revertir_playlist(pila);
                
                cout << "---- POST-REVERSO ----" << endl;
                cout << "ACTUAL: " << pila->cancion.titulo << endl;
                cout << "SIGUIENTE: " << pila->siguiente->cancion.titulo << endl;
                cout << "SIGUIENTE DEL SIGUIENTE: " << pila->siguiente->siguiente->cancion.titulo << endl;

                break;
            case 5:
                historial(pila);
                break;
            default:
                cout << "Elegiste otra opcion. Saliendo..." << endl;
                continuar = false;
                break;
        }
    }

    return 0;
}

void historial(Nodo*& pila) {
    Nodo* historial = nullptr;
    
    if(pila == nullptr) {
        cout << "No hay nada en tu pila." << endl;
        return;
    }

    while(pila != nullptr) {
        cout << "Queres escuchar la cancion | " << pila->cancion.titulo << " de " << pila->cancion.artista << " |" << endl;
        cout << "[1]: Si" << endl;
        cout << "[2]: No" << endl;
        int respuesta;
        cin >>respuesta;
        if(respuesta == 1) {
            int calificacion;
            cout << "Que te parecio la cancion?" << endl;
            cout << "[1]: Mala" << endl;
            cout << "[2]: Maso" << endl;
            cout << "[3]: Buena" << endl;
            cout << "[4]: Muy Buena" << endl;
            cout << "[5]: De perlas" << endl;
            cin >> calificacion;
            
            push_ordenado_historial(historial, pila->cancion.titulo, pila->cancion.artista, calificacion);
            pop(pila);
        }
    }

    float promedio_estrellas = 0;
    bool continuar = true;
    while(continuar) {
        int respuesta;
        cout << "[1]: Recorrer Historial" << endl;
        cout << "[2]: Ver filtrando por estrellas" << endl;
        cout << "[3]: Ver cantidad de estrellas promedio" << endl;
        cout << "[4]: Eliminar canciones del historial" << endl;
        cin >> respuesta;
        
        switch(respuesta) {
            case 1:
                recorrer_pila(historial);
                break;
            case 2:
                mostrar_historial_filtrado(historial);
                break;
            case 3:
                promedio_estrellas = ver_estrellas_promedio(historial);
                cout << "EL PROMEDIO DE ESTRELLAS ES: " << promedio_estrellas << endl;
                break;
            case 4:
                eliminarNodo(historial);
                break;
            
            default:
                continuar = false;
                break;
        }
    }
}

Nodo* eliminarNodo(Nodo* inicio) {
    cout << "Ahora vamos a eliminar la cancion que me digas" << endl;
    cout << "Dame el titulo:";
    string cancion_titulo = "";
    cin >> cancion_titulo;

    if (inicio == nullptr) {
        return nullptr;
    }
    if (inicio->cancion.titulo == cancion_titulo) {
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
        return inicio;
    }
    Nodo* actual = inicio;
    while (actual->siguiente != nullptr) {
        if (actual->siguiente->cancion.titulo == cancion_titulo) {
            Nodo* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            return inicio;
        }
        actual = actual->siguiente;
    }
    return inicio;
}

void mostrar_historial_filtrado(Nodo* historial) {
    int calificacion = 0;
    cout << "Te voy a mostrar las canciones con las estrellas que vos me digas" << endl;
    cin >> calificacion;

    Nodo* actual = historial;
    while (actual != nullptr) {
        if(actual->cancion.calificacion == calificacion) {
            cout << "TITULO: " << actual->cancion.titulo << " " << endl;
            cout << "ARTISTA: " << actual->cancion.artista << " " << endl;
            cout << endl;
        }
        actual = actual->siguiente;
    }
    cout << endl;
}

float ver_estrellas_promedio(Nodo* pila) {
    int cantidad_registros = 0;
    int sum_estrellas = 0;
    Nodo* actual = pila;
    while (actual != nullptr) {
        cantidad_registros++;
        sum_estrellas += actual->cancion.calificacion;
        actual = actual->siguiente;
    }
    cout << endl;

    cout << cantidad_registros << endl;
    cout << sum_estrellas << endl;
    
    return sum_estrellas / cantidad_registros;
}

void recorrer_pila(Nodo* pila) {
    Nodo* actual = pila;
    while (actual != nullptr) {
        cout << "Listando..." << endl;
        cout << "TITULO: " << actual->cancion.titulo << " " << endl;
        cout << "ARTISTA: " << actual->cancion.artista << " " << endl;
        if(actual->cancion.calificacion != -1) {
            cout << "CALIFICACION: " << actual->cancion.calificacion << " " << endl;
        }
        cout << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}

void revertir_playlist(Nodo*& original) {
    Nodo* reverso = nullptr;

    while(original != nullptr) {
        Cancion temp = pop(original);
        
        push(reverso, temp.titulo, temp.artista, temp.calificacion);
    }

    original = reverso;

    return;
}

Nodo* crearNodo(string titulo, string artista, int calificacion) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->cancion.titulo = titulo;
    nuevoNodo->cancion.artista = artista;
    nuevoNodo->cancion.calificacion = calificacion;
    nuevoNodo->siguiente = nullptr;

    return nuevoNodo;
}

Nodo* push_ordenado_historial(Nodo*& historial, string titulo, string artista, int calificacion) {
    Nodo* nuevoNodo = crearNodo(titulo, artista, calificacion);

    if (historial == nullptr || artista < historial->cancion.artista) {
        nuevoNodo->siguiente = historial;
        historial = nuevoNodo;
        return historial;
    }

    Nodo* actual = historial;
    while (actual->siguiente != nullptr && actual->siguiente->cancion.artista < artista) {
        actual = actual->siguiente;
    }

    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    return historial;
}

void push(Nodo*& pila, string titulo, string artista, int calificacion) {
    Nodo* nuevoNodo = crearNodo(titulo, artista, calificacion);
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

Cancion pop(Nodo*& pila) {
    if (pila == nullptr) {
        cout << "La pila está vacía." << endl;
        return {"", "", -1};
    }
    
    Cancion valor = pila->cancion;
    Nodo* temp = pila;
    pila = pila->siguiente;
    delete temp;
    
    return valor;
}