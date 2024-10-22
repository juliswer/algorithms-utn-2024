#include "iostream"
using namespace std;

// Definición de un nodo de árbol binario de búsqueda AVL
struct TreeNode {
    int dniUsuario;
    TreeNode* left;
    TreeNode* right;
    int height; // Altura del nodo
};

struct Sucursal {
    string nombre;
    TreeNode* arbol;
};

struct NodoLista {
    Sucursal dato;
    NodoLista* siguiente;
};

// lista
NodoLista* crearNodoLista(Sucursal valor);
NodoLista* cargarLista(NodoLista* inicio, Sucursal valor);
bool existeElementoLista(NodoLista* inicio, Sucursal valor);
NodoLista* cargarSinRepetirLista(NodoLista* inicio, Sucursal valor);
void imprimirListaSimple(NodoLista* inicio);
Sucursal* buscarSurcursal(NodoLista* inicio, string nombre);

// arbol
int obtenerAlturaArbol(TreeNode* node);
void recalcularAlturaArbol(TreeNode* node);
TreeNode* rotacionDerecha(TreeNode* y);
TreeNode* rotacionIzquierda(TreeNode* x);
TreeNode* crearNodo(int valor);
TreeNode* insertarArbol(TreeNode* root, int valor);
void inorden(TreeNode* root);

// sucursal
bool buscarCliente(TreeNode* root, int dni);
TreeNode* agregarCliente(TreeNode* root);
TreeNode* eliminarCliente(TreeNode* root, int dni);
TreeNode* encontrarMinimo(TreeNode* node);

// general
void agregarClienteSucursal(NodoLista* sucursales, string nombreSucursal);
void consultarClienteSucursal(NodoLista* sucursales, string nombreSucursal);
void eliminarClienteSucursal(NodoLista* sucursales, string nombreSucursal);

int main() {
    NodoLista* sucursales = nullptr;

    bool continuar = true;
    int accion;

    while(continuar) {
        cout << "Accion a realizar:" << endl;
        cout << "*[0]*: Crear Nueva Sucursal" << endl;
        cout << "*[1]*: Agregar Cliente a una sucursal" << endl;
        cout << "*[2]*: Consultar DNI de un cliente en una sucursal" << endl;
        cout << "*[3]*: Eliminar cliente de una sucursal por DNI" << endl;
        cout << "*[Otro]*: Salir" << endl;
        cin >> accion;
        
        Sucursal nuevaSucursal;
        string sucursalBuscada;
        switch(accion) {
            case 0:
                cout << "Ingrese nombre de la nueva sucursal" << endl;
                cin >> nuevaSucursal.nombre;
                nuevaSucursal.arbol = nullptr;
                sucursales = cargarSinRepetirLista(sucursales, nuevaSucursal);
                cout << "Imprimiendo sucursales" << endl;
                imprimirListaSimple(sucursales);
                break;
            case 1:
                cout << "A que sucursal quiere agregar el cliente" << endl;
                cin >> sucursalBuscada;
                agregarClienteSucursal(sucursales, sucursalBuscada);
                cout << "Imprimiendo sucursales" << endl;
                imprimirListaSimple(sucursales);
                break;
            case 2:
                cout << "A que sucursal quiere consultar el cliente" << endl;
                cin >> sucursalBuscada;
                consultarClienteSucursal(sucursales, sucursalBuscada);
                break;
            case 3:
                cout << "A que sucursal le queres eliminar un cliente" << endl;
                cin >> sucursalBuscada;
                eliminarClienteSucursal(sucursales, sucursalBuscada);
                imprimirListaSimple(sucursales);
                break;
            default:
                continuar = false;
                break;
        }
    }

    return 0;
}

// general

void eliminarClienteSucursal(NodoLista* sucursales, string nombreSucursal) {
    Sucursal* sucursal = buscarSurcursal(sucursales, nombreSucursal);

    if(sucursal == nullptr) {
        return;
    }

    int dniBuscado;

    cout << "Que cliente buscas en la sucursal " << sucursal->nombre << endl;
    cin >> dniBuscado;

    eliminarCliente(sucursal->arbol, dniBuscado);

    return;
}

void consultarClienteSucursal(NodoLista* sucursales, string nombreSucursal) {
    Sucursal* sucursal = buscarSurcursal(sucursales, nombreSucursal);

    if(sucursal == nullptr) {
        return;
    }

    int dniBuscado;

    cout << "Que cliente buscas en la sucursal " << sucursal->nombre << endl;
    cin >> dniBuscado;

    buscarCliente(sucursal->arbol, dniBuscado);
    
    return;
}

void agregarClienteSucursal(NodoLista* sucursales, string nombreSucursal) {
    Sucursal* sucursal = buscarSurcursal(sucursales, nombreSucursal);

    if(sucursal == nullptr) {
        return;
    }

    sucursal->arbol = agregarCliente(sucursal->arbol);
    
    return;
}

// lista
Sucursal* buscarSurcursal(NodoLista* inicio, string nombre) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        if (actual->dato.nombre == nombre) {
            return &actual->dato;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

NodoLista* crearNodoLista(Sucursal valor) {
    NodoLista* nuevoNodo = new NodoLista;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

NodoLista* cargarLista(NodoLista* inicio, Sucursal valor) {
    NodoLista* nuevoNodo = crearNodoLista(valor);
    if (inicio == nullptr) {
        inicio = nuevoNodo;
        cout << "Sucursal agregada con exito" << endl;
    } else {
        NodoLista* actual = inicio;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        cout << "Sucursal agregada con exito" << endl;
    }
    return inicio;
}

bool existeElementoLista(NodoLista* inicio, Sucursal valor) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        if (actual->dato.nombre == valor.nombre) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

NodoLista* cargarSinRepetirLista(NodoLista* inicio, Sucursal valor) {
    if (!existeElementoLista(inicio, valor)) {
        return cargarLista(inicio, valor);
    }
    return inicio;
}

void imprimirListaSimple(NodoLista* inicio) {
    NodoLista* actual = inicio;
    while (actual != nullptr) {
        cout << actual->dato.nombre << endl;
        inorden(actual->dato.arbol);
        actual = actual->siguiente;
    }
    cout << endl;
}

// sucursal
TreeNode* encontrarMinimo(TreeNode* node) {
    TreeNode* actual = node;
    while (actual->left != nullptr) {
        actual = actual->left;
    }
    return actual;
}

TreeNode* eliminarCliente(TreeNode* root, int dniEliminar) {
    if (root == nullptr) {
        cout << "Usuario con DNI " << dniEliminar << " no encontrado." << endl;
        return root;
    }

    if (dniEliminar < root->dniUsuario) {
        root->left = eliminarCliente(root->left, dniEliminar);
    } else if (dniEliminar > root->dniUsuario) {
        root->right = eliminarCliente(root->right, dniEliminar);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = encontrarMinimo(root->right);

        root->dniUsuario = temp->dniUsuario;

        root->right = eliminarCliente(root->right, temp->dniUsuario);
    }

    return root;
}

bool buscarCliente(TreeNode* root, int dniBuscado) {
    if (root == nullptr) {
        cout << "Usuario con DNI " << dniBuscado << " no encontrado." << endl;
        return false;
    }

    if (dniBuscado < root->dniUsuario) {
        buscarCliente(root->left, dniBuscado);
    } else if (dniBuscado > root->dniUsuario) {
        buscarCliente(root->right, dniBuscado);
    } else {
        cout << "Usuario encontrado: " << root->dniUsuario << endl;
        return true;
    }

    return false;
}

TreeNode* agregarCliente(TreeNode* root) {
    int dniUsuario;

    cout << "DNI del Usuario" << endl;
    cin >> dniUsuario;

    return insertarArbol(root, dniUsuario);
}

// arbol

void inorden(TreeNode* root) {
    if (root == nullptr) return;
    inorden(root->left);            // Recorre el subárbol izquierdo
    cout << root->dniUsuario << endl; // Visita el nodo
    inorden(root->right);           // Recorre el subárbol derecho
}

// Función para obtener la altura de un nodo (teniendo en cuenta nodos nulos)
int obtenerAlturaArbol(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Función para recalcular la altura de un nodo
void recalcularAlturaArbol(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    node->height = 1 + max(obtenerAlturaArbol(node->left), obtenerAlturaArbol(node->right));
}

// Función para realizar una rotación simple a la derecha
TreeNode* rotacionDerecha(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    recalcularAlturaArbol(y);
    recalcularAlturaArbol(x);
    
    return x;
}

// Función para realizar una rotación simple a la izquierda
TreeNode* rotacionIzquierda(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    recalcularAlturaArbol(x);
    recalcularAlturaArbol(y);
    
    return y;
}

// Función para crear un nuevo nodo con el valor dado
TreeNode* crearNodo(int valor) {
    TreeNode* nuevoNodo = new TreeNode;
    nuevoNodo->dniUsuario = valor;
    nuevoNodo->left = nullptr;
    nuevoNodo->right = nullptr;
    nuevoNodo->height = 1;
    return nuevoNodo;
}

// Función para insertarArbol un nuevo elemento en el árbol AVL
TreeNode* insertarArbol(TreeNode* root, int valor) {
    if (root == nullptr) {
        return crearNodo(valor); // Si el nodo es nulo, crea un nuevo nodo con el valor dado
    }
    
    if (valor < root->dniUsuario) {
        root->left = insertarArbol(root->left, valor);
    }
    else if (valor > root->dniUsuario) {
        root->right = insertarArbol(root->right, valor);
    }
    else {
        return root; // Valor duplicado, no se permite en un AVL
    }
    
    recalcularAlturaArbol(root);
    
    int diferenciaAltura = obtenerAlturaArbol(root->left) - obtenerAlturaArbol(root->right);
    
    // Verificar y realizar rotaciones para mantener el equilibrio
    // Rotación a la derecha (simple o doble)
    if (diferenciaAltura > 1 && valor < root->left->dniUsuario) {
        return rotacionDerecha(root);
    }
    // Rotación a la izquierda (simple o doble)
    if (diferenciaAltura < -1 && valor > root->right->dniUsuario) {
        return rotacionIzquierda(root);
    }
    // Rotación izquierda-derecha (doble)
    if (diferenciaAltura > 1 && valor > root->left->dniUsuario) {
        root->left = rotacionIzquierda(root->left);
        return rotacionDerecha(root);
    }
    // Rotación derecha-izquierda (doble)
    if (diferenciaAltura < -1 && valor < root->right->dniUsuario) {
        root->right = rotacionDerecha(root->right);
        return rotacionIzquierda(root);
    }
    
    return root;
}