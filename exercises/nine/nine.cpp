#include <iostream>
using namespace std;

struct Cliente {
    string nombre;
    int edad;
    float saldo;
};

void llenarClientes(Cliente clientes[], int len);
int buscarCliente(Cliente clientes[], int len, string nombre);
int cantidadSaldosMasAltos(Cliente clientes[], int len, Cliente cliente);

int main() {
    string clienteBuscado;
    Cliente clientes[3];
    llenarClientes(clientes, 3);

    cout << "Cual es el nombre del cliente que esta buscando?" << endl;
    cin >> clienteBuscado;

    int clienteBuscadoPos = buscarCliente(clientes, 3, clienteBuscado);

    if(clienteBuscadoPos == -1) {
        cout << "No existe ese cliente" << endl;
    } else {
        cout << "Cliente con nombre " << clienteBuscado << " existe. Su informacion es: " << endl;
        cout << "Nombre: " << clientes[clienteBuscadoPos].nombre << endl;
        cout << "Edad: " << clientes[clienteBuscadoPos].edad << endl;
        cout << "Saldo: " << clientes[clienteBuscadoPos].saldo << endl;

        int saldosMayores = cantidadSaldosMasAltos(clientes, 3, clientes[clienteBuscadoPos]);

        cout << "A su vez, hay " << saldosMayores << " clientes con saldos mas altos que " << clientes[clienteBuscadoPos].nombre << endl;
    }
    
    return 0;
}

void llenarClientes(Cliente clientes[], int len) {
    for(int i = 0; i < len; i++) {
        cout << "Ingrese nombre del cliente: ";
        cin >> clientes[i].nombre;

        cout << "Ingrese edad del cliente: ";
        cin >> clientes[i].edad;

        cout << "Ingrese saldo del cliente: ";
        cin >> clientes[i].saldo;
    }
}

int buscarCliente(Cliente clientes[], int len, string nombre) {
    int i = 0;

    while(i < len && clientes[i].nombre != nombre) {
        i++;
    }

    return i == len ? -1 : i;
}

int cantidadSaldosMasAltos(Cliente clientes[], int len, Cliente cliente) {
    int saldos = 0;
    
    for(int i = 0; i < len; i++) {
        if(clientes[i].saldo > cliente.saldo) {
            saldos++;
        }
    }

    return saldos;
}