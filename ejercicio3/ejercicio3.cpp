#include "iostream"
using namespace std;

struct DataArchivo {
    int categoria;
    char producto[100];
    int cantidad;
};

struct Producto {
    char nombre[100];
    int cantidad;
};

struct NodoLista {
    Producto producto;
    NodoLista* siguiente;
};

struct Categoria {
    int id;
    NodoLista* lista;
};

// lista
NodoLista* crearNodoLista(Producto producto);
void imprimirListaSimple(NodoLista* inicio);
NodoLista* cargarLista(NodoLista* inicio, Producto producto);
bool existeElementoLista(NodoLista* inicio, char nombre[]);
NodoLista* cargarSinRepetir(NodoLista* inicio, Producto producto);
NodoLista* buscarElementoLista(NodoLista* inicio, char nombre[]);
NodoLista* eliminarNodoLista(NodoLista* inicio, char nombre[]);

// general
void cargarProductosEnLista(Categoria categorias[]);
void eliminarProducto(Categoria categorias[]);
void mostrarInventario(Categoria categorias[]);
void generarDummyData();

int main() {
    generarDummyData();
    /*Para mayor simpleza voy a suponer que los IDs van
    * de menor a mayor empezando en 1 y terminando en 5.
    */
    Categoria categorias[5] = {
        {1, nullptr},
        {2, nullptr},
        {3, nullptr},
        {4, nullptr},
        {5, nullptr},
    };
    bool continuar = true;
    int accion;

    while(continuar) {
        cout << "\nAccion a realizar:" << endl;
        cout << "*[0]*: Cargar Productos" << endl;
        cout << "*[1]*: Eliminar Producto de una Categoria" << endl;
        cout << "*[2]*: Mostrar Inventario" << endl;
        cout << "*[Otro]*: Salir" << endl;
        cin >> accion;

        switch(accion) {
            case 0:
                cargarProductosEnLista(categorias);
                break;
            case 1:
                eliminarProducto(categorias);
                break;
            case 2:
                mostrarInventario(categorias);
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
void generarDummyData() {
    FILE* archivo = fopen("inventario.dat", "w+");

    if(archivo == NULL) {
       cout << "El archivo no se pudo abrir" << endl;
        return; 
    }

    DataArchivo data[10] = {
        {1, "Maquillaje", 20},
        {2, "Remera", 30},
        {3, "Pantalon", 40},
        {4, "Gorra", 50},
        {5, "Anteojos", 7},
        {1, "Maquillaje", 20},
        {2, "Zapatillas", 307},
        {3, "Vaso", 476},
        {4, "Tazas", 15},
        {5, "Auto", 165}
    };

    fwrite(&data, sizeof(DataArchivo), 10, archivo);

    fclose(archivo);
}

void cargarProductosEnLista(Categoria categorias[]) {
    FILE* archivo = fopen("inventario.dat", "rb");

    if(archivo == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    DataArchivo data;
    while(fread(&data, sizeof(DataArchivo), 1, archivo) == 1) {
        // TODO: Improve this method.
        NodoLista* listaActual = categorias[data.categoria - 1].lista;
        
        if(existeElementoLista(listaActual, data.producto)) {
            NodoLista* elemento = buscarElementoLista(listaActual, data.producto);
            elemento->producto.cantidad += data.cantidad;
        } else {
            Producto producto;
            strcpy(producto.nombre, data.producto);
            producto.cantidad = data.cantidad;

            categorias[data.categoria - 1].lista = cargarLista(listaActual, producto);
        }
    }

    fclose(archivo);
    return;
}

void eliminarProducto(Categoria categorias[]) {
    int id;
    cout << "De que categoria queres borrar un producto?" << endl;
    cin >> id;

    Categoria categoria = {-1, nullptr};
    int i = 0;

    while(i < 5) {
        if(categorias[i].id == id) {
            categoria = categorias[i];
            break;
        }
        i++;
    }

    if(categoria.id == -1) {
        cout << "Categoria no encontrada" << endl;
        return;
    }

    char productoNombre[100] = "";

    cout << "Que producto queres eliminar?" << endl;
    cin >> productoNombre;

    categorias[i].lista = eliminarNodoLista(categoria.lista, productoNombre);;

    return;
}

void mostrarInventario(Categoria categorias[]) {
    for(int i = 0; i < 5; i++) {
        cout << "\nImprimiendo Lista de Categoria Nro: " << categorias[i].id << endl;
        imprimirListaSimple(categorias[i].lista);
    }
    return;
}

// lista
NodoLista* crearNodoLista(Producto producto) {
    NodoLista* nuevoNodo = new NodoLista;
    nuevoNodo->producto = producto;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void imprimirListaSimple(NodoLista* inicio) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        cout << "Producto: " << actual->producto.nombre << " | Cantidad: " << actual->producto.cantidad << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}

NodoLista* cargarLista(NodoLista* inicio, Producto producto) {
    NodoLista* nuevoNodo = crearNodoLista(producto);
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

bool existeElementoLista(NodoLista* inicio, char nombre[]) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        
        if (strcmp(actual->producto.nombre, nombre) == 0) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

NodoLista* cargarSinRepetir(NodoLista* inicio, Producto producto) {
    if (!existeElementoLista(inicio, producto.nombre)) {
        return cargarLista(inicio, producto);
    }
    return inicio;
}

NodoLista* buscarElementoLista(NodoLista* inicio, char nombre[]) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        if (strcmp(actual->producto.nombre, nombre) == 0) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

NodoLista* eliminarNodoLista(NodoLista* inicio, char nombre[]) {
    if (inicio == nullptr) {
        return nullptr;
    }
    if (strcmp(inicio->producto.nombre, nombre) == 0) {
        NodoLista* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
        return inicio;
    }
    NodoLista* actual = inicio;
    while (actual->siguiente != nullptr) {
        if (strcmp(inicio->producto.nombre, nombre) == 0) {
            NodoLista* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            return inicio;
        }
        actual = actual->siguiente;
    }
    return inicio;
}