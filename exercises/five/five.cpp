#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    int precio;
    int stock;
};

void llenarArreglo(Producto productos[], int len);
int busquedaSequencial(Producto productos[], int len, string nombre);

int main() {
    Producto productos[2];
    llenarArreglo(productos, 2);
    string productoABuscar;

    cout << "Que producto estas buscando? " << endl;
    cin >> productoABuscar;

    int pos = busquedaSequencial(productos, 2, productoABuscar);

    if(pos == -1) {
        cout << "El producto no esta en stock";
    } else {
        cout << "El producto " << productoABuscar << " esta en la posicion: " << pos << "Y a continuacion detallare su informacion: " << endl;

        cout << "Nombre: " << productos[pos].nombre << endl;
        cout << "Precio: " << productos[pos].precio << endl;
        cout << "Stock: " << productos[pos].stock << endl;
    }


    return 0;
}

void llenarArreglo(Producto productos[], int len) {
    for(int i = 0; i < len; i++) {
        cout << "#" << i << " Nombre del producto: " << endl;
        cin >> productos[i].nombre;

        cout << "#" << i << " Precio del producto: " << endl;
        cin >> productos[i].precio;

        cout << "#" << i << " Stock del producto: " << endl;
        cin >> productos[i].stock;
    }
}

int busquedaSequencial(Producto productos[], int len, string nombre) {
    int i = 0;

    while(i < len && productos[i].nombre != nombre) {
        i++;
    }

    return i == len ? -1 : i;
}