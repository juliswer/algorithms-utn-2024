#include <iostream>
using namespace std;

// fecha en formato AAAAMMDD
struct Factura {
    int numero;
    int fecha;
    int monto;
};

int buscarFactura(Factura facturas[], int len, int facturaABuscar);
void llenarFacturas(Factura facturas[], int len);

int main() {
    int numeroFacturaBuscada;
    Factura facturas[3];

    llenarFacturas(facturas, 3);

    cout << "Que numero de factura estas buscando?" << endl;
    cin >> numeroFacturaBuscada;

    int posFactura = buscarFactura(facturas, 3, numeroFacturaBuscada);

    if(posFactura == -1) {
        cout << "La factura buscada no existe" << endl;
    } else {
        cout << "A continuacion se detallar los datos de la factura buscada: " << endl;
        cout << "Numero: " << facturas[posFactura].numero << endl;
        cout << "Monto: " << facturas[posFactura].monto << endl;
        cout << "Fecha: " << facturas[posFactura].fecha << endl;
    }

    return 0;
}

int buscarFactura(Factura facturas[], int len, int facturaABuscar) {
    int izquierda = 0;
    int derecha = len - 1;

    while(izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;
        if(facturas[medio].numero == facturaABuscar) {
            return medio;
        }
        if(facturas[medio].numero < facturaABuscar) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return -1;
}

void llenarFacturas(Factura facturas[], int len) {
    for(int i = 0; i < len; i++) {
        cout << "Numero de factura: " << endl;
        cin >> facturas[i].numero;

        cout << "Fecha de factura (AAAAMMDD): " << endl;
        cin >> facturas[i].fecha;

        cout << "Monto de factura: " << endl;
        cin >> facturas[i].monto;
    }
}