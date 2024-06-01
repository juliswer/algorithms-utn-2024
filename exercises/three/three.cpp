#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    int precio;
};

int busquedaSequencial(Producto vec[], int len, string palabra);

int main() {
    string productoBuscado;
    Producto productos[3];
    productos[0].nombre = "Zapatilla";
    productos[0].precio = 10;

    productos[1].nombre = "Bufanda";
    productos[1].precio = 500;

    productos[2].nombre = "Remera";
    productos[2].precio = 2000;

    cout << "Ingrese el nombre de un producto a buscar: " << endl;
    cin >> productoBuscado;

    int pos = busquedaSequencial(productos, 3, productoBuscado);

    if(pos == -1) {
        cout << "El producto " << productoBuscado << " no existe el arreglo" << endl;
    } else {
        cout << "La posicion de " << productoBuscado << " es: " << pos << endl;
    }


    return 0;
}

int busquedaSequencial(Producto vec[], int len, string palabra) {
    int i = 0;

    while(i < len && vec[i].nombre != palabra) {
        i++;
    }

    return i == len ? -1 : i;
}