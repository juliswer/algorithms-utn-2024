#include "iostream"
using namespace std;

struct Pedido {
    int mesaBuscada;
};

struct Nodo {
    Pedido pedido;
    Nodo* siguiente;
};

struct MesaArchivo {
    int mesaIdentificador;
    bool estaOcupada;
    int totalFacturado;
};

struct MesaCola {
    int mesaIdentificador;
    bool estaOcupada;
    int totalFacturado;
    Nodo* cola_inicio;
    Nodo* cola_fin;
};

void createDummyData();
void leerMesas(MesaCola mesas[]);
Nodo* crearNodo(Pedido pedido);
Pedido desencolarPedido(MesaCola &mesa);
bool isEmpty(MesaCola mesa);
void encolarPedidos(MesaCola mesas[]);
void encolar(Nodo*& frente, Nodo*& final, Pedido pedido);
Pedido desencolar(Nodo*& frente, Nodo*& final);

int main() {
    createDummyData();

    MesaCola mesas[20];

    leerMesas(mesas);

    encolarPedidos(mesas);

    int mesaBuscada;
    bool mesaValida = false;

    cout << "Que mesa buscas atender ahora? (Numero entre 1 y 20)" << endl;
    cin >> mesaBuscada;
    
    mesaValida = mesaBuscada >= 1 && mesaBuscada <= 20;
    
    if(!mesaValida) {
        cout << "Codigo de mesa invalido" << endl;
        return -1;
    }

    MesaCola mesaQuerida = mesas[mesaBuscada - 1];

    if(isEmpty(mesaQuerida)) {
        cout << "Mesa #" << mesaQuerida.mesaIdentificador << " vacia" << endl;
    }

    int i = 0;
    
    while(!isEmpty(mesaQuerida)) {
        i++;
        cout << "Atendiendo al #" << i << " de la mesa #" << mesaQuerida.mesaIdentificador << endl;
        Pedido siguiente = desencolarPedido(mesaQuerida);
    }

    cout << "Total facturado de la mesa: $" << mesaQuerida.totalFacturado << endl;

    return 0;
}

Nodo* crearNodo(Pedido pedido) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->pedido = pedido;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void encolar(Nodo*& frente, Nodo*& final, Pedido pedido) {
    Nodo* nuevoNodo = crearNodo(pedido);
    if (final == nullptr) {
        frente = final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
}

void encolarPedidos(MesaCola mesas[]) {
    FILE* archivo = fopen("pedidos.dat", "rb");
    if (archivo != NULL) {
        Pedido pedido;
        while (fread(&pedido, sizeof(Pedido), 1, archivo) == 1) {
            Nodo* nuevoNodo = crearNodo(pedido);
            
            encolar(mesas[pedido.mesaBuscada - 1].cola_inicio, mesas[pedido.mesaBuscada - 1].cola_fin, pedido);
        }
        fclose(archivo);
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
}

Pedido desencolar(Nodo*& frente, Nodo*& final) {
    if (frente == nullptr) {
        cerr << "La cola está vacía." << endl;
        return {-1};
    }
    Pedido valor = frente->pedido;
    Nodo* temp = frente;
    frente = frente->siguiente;
    if (frente == nullptr) {
        final = nullptr;
    }
    delete temp;
    return valor;
}

Pedido desencolarPedido(MesaCola &mesa) {
    int gastado = 0;
    cout << "Cuanto gasto este pedido?" << endl;
    cin >> gastado;

    mesa.totalFacturado += gastado;

    return desencolar(mesa.cola_inicio, mesa.cola_fin);
}

bool isEmpty(MesaCola mesa) {
    return mesa.cola_inicio == nullptr;
}

void leerMesas(MesaCola mesas[]) {
    FILE* archivo = fopen("mesas.dat", "rb");
    if (archivo != NULL) {
        MesaArchivo mesa;
        while (fread(&mesa, sizeof(MesaArchivo), 1, archivo) == 1) {
            mesas[mesa.mesaIdentificador - 1].estaOcupada = mesa.estaOcupada;
            mesas[mesa.mesaIdentificador - 1].mesaIdentificador = mesa.mesaIdentificador;
            mesas[mesa.mesaIdentificador - 1].totalFacturado = mesa.totalFacturado;
            mesas[mesa.mesaIdentificador - 1].cola_inicio = nullptr;
            mesas[mesa.mesaIdentificador - 1].cola_fin = nullptr;
        }
        fclose(archivo);
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }
}

void createDummyData() {
    FILE* archivoMesas = fopen("mesas.dat", "wb");
    FILE* archivoPedidos = fopen("pedidos.dat", "wb");

    Pedido pedidosDummy[5] = {{1}, {1}, {1}, {1}, {1}};

    MesaArchivo mesasDummy[20] = {
        {1, true, 2000},
        {2, true, 81375},
        {3, false, 135},
        {4, true, 1935},
        {5, false, 13513},
        {6, false, 135613},
        {7, false, 1234},
        {8, true, 184},
        {9, true, 91218},
        {10, true, 1351},
        {11, false, 18351},
        {12, true, 183571},
        {13, false, 18122023},
        {14, true, 13957},
        {15, false, 111},
        {16, false, 0},
        {17, true, 1385},
        {18, false, 8787},
        {19, false, 777},
        {20, true, 9163},
    };

    if(archivoMesas != NULL) {
        fwrite(mesasDummy, sizeof(MesaArchivo), 20, archivoMesas);
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }

    if(archivoPedidos != NULL) {
        fwrite(pedidosDummy, sizeof(Pedido), 5, archivoPedidos);
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }

    fclose(archivoMesas);
    fclose(archivoPedidos);
}