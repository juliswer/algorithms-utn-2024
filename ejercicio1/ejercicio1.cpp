#include "iostream"
using namespace std;

struct Usuario {
    int dni;
    string nombre;
};

// Definición de un nodo de árbol binario de búsqueda AVL
struct TreeNode {
    Usuario data;
    TreeNode* left;
    TreeNode* right;
    int height; // Altura del nodo
};

// arbol
int obtenerAltura(TreeNode* node);
void recalcularAltura(TreeNode* node);
TreeNode* rotacionDerecha(TreeNode* y);
TreeNode* rotacionIzquierda(TreeNode* x);
TreeNode* crearNodo(Usuario valor);
TreeNode* insertar(TreeNode* root, Usuario valor);
void inorden(TreeNode* root);

// general
TreeNode* agregarUsuario(TreeNode* root);

int main() {
    TreeNode* arbol = nullptr;

    bool continuar = true;
    int accion;

    while(continuar) {
        cout << "Accion a realizar:" << endl;
        cout << "*[0]*: Agregar Usuario" << endl;
        cout << "*[1]*: Ver arbol de usuarios" << endl;
        cout << "*[Otro]*: Salir" << endl;
        cin >> accion;

        switch(accion) {
            case 0:
                arbol = agregarUsuario(arbol);
                break;
            case 1:
                inorden(arbol);
                break;
            default:
                continuar = false;
                break;
        }
    }

    return 0;
}

TreeNode* agregarUsuario(TreeNode* root) {
    Usuario usuario;

    cout << "Nombre del Usuario" << endl;
    cin >> usuario.nombre;
    cout << "DNI del Usuario" << endl;
    cin >> usuario.dni;

    return insertar(root, usuario);
}

void inorden(TreeNode* root) {
    if (root == nullptr) return;
    inorden(root->left);            // Recorre el subárbol izquierdo
    cout << root->data.dni << " - " << root->data.nombre << endl; // Visita el nodo
    inorden(root->right);           // Recorre el subárbol derecho
}

// Función para obtener la altura de un nodo (teniendo en cuenta nodos nulos)
int obtenerAltura(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Función para recalcular la altura de un nodo
void recalcularAltura(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    node->height = 1 + max(obtenerAltura(node->left), obtenerAltura(node->right));
}

// Función para realizar una rotación simple a la derecha
TreeNode* rotacionDerecha(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    recalcularAltura(y);
    recalcularAltura(x);
    
    return x;
}

// Función para realizar una rotación simple a la izquierda
TreeNode* rotacionIzquierda(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    recalcularAltura(x);
    recalcularAltura(y);
    
    return y;
}

// Función para crear un nuevo nodo con el valor dado
TreeNode* crearNodo(Usuario valor) {
    TreeNode* nuevoNodo = new TreeNode;
    nuevoNodo->data = valor;
    nuevoNodo->left = nullptr;
    nuevoNodo->right = nullptr;
    nuevoNodo->height = 1;
    return nuevoNodo;
}

// Función para insertar un nuevo elemento en el árbol AVL
TreeNode* insertar(TreeNode* root, Usuario valor) {
    if (root == nullptr) {
        cout << "Root nulo" << endl;
        return crearNodo(valor); // Si el nodo es nulo, crea un nuevo nodo con el valor dado
    }
    
    if (valor.dni < root->data.dni) {
        root->left = insertar(root->left, valor);
    }
    else if (valor.dni > root->data.dni) {
        root->right = insertar(root->right, valor);
    }
    else {
        return root; // Valor duplicado, no se permite en un AVL
    }
    
    recalcularAltura(root);
    
    int diferenciaAltura = obtenerAltura(root->left) - obtenerAltura(root->right);
    
    // Verificar y realizar rotaciones para mantener el equilibrio
    // Rotación a la derecha (simple o doble)
    if (diferenciaAltura > 1 && valor.dni < root->left->data.dni) {
        return rotacionDerecha(root);
    }
    // Rotación a la izquierda (simple o doble)
    if (diferenciaAltura < -1 && valor.dni > root->right->data.dni) {
        return rotacionIzquierda(root);
    }
    // Rotación izquierda-derecha (doble)
    if (diferenciaAltura > 1 && valor.dni > root->left->data.dni) {
        root->left = rotacionIzquierda(root->left);
        return rotacionDerecha(root);
    }
    // Rotación derecha-izquierda (doble)
    if (diferenciaAltura < -1 && valor.dni < root->right->data.dni) {
        root->right = rotacionDerecha(root->right);
        return rotacionIzquierda(root);
    }
    
    return root;
}