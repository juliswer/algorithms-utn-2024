#include <iostream>
using namespace std;

struct Redes {
    string instragram;
    string twitter;
};

struct Instagamer {
    string nombre;
    int edad;
    Redes redes;
};

int buscarInstagamer(Instagamer instagamer[], int len, string nombre);

int main() {
    string nombreABuscar;
    Instagamer instagamers[3];
    instagamers[0].nombre = "Pepe";
    instagamers[0].edad = 20;
    instagamers[0].redes.instragram = "pepeig";
    instagamers[0].redes.twitter = "pepetw";

    instagamers[1].nombre = "Marcos";
    instagamers[1].edad = 45;
    instagamers[1].redes.instragram = "marcosig";
    instagamers[1].redes.twitter = "marcostw";

    instagamers[2].nombre = "Lautarin";
    instagamers[2].edad = 60;
    instagamers[2].redes.instragram = "lautarinig";
    instagamers[2].redes.twitter = "lautaringtw";

    cout << "Que nombre estas buscando?" << endl;
    cin >> nombreABuscar;

    int posInstagamer = buscarInstagamer(instagamers, 3, nombreABuscar);

    if(posInstagamer == -1) {
        cout << "No esta el nombre: " << nombreABuscar << " en el arreglo";
    } else {
        cout << "Encontre a " << nombreABuscar << " en el arreglo. Te detallo su data:" << endl;
        cout << "Nombre: " << instagamers[posInstagamer].nombre << endl;
        cout << "Edad: " << instagamers[posInstagamer].edad << endl;
        cout << "Instagram: " << instagamers[posInstagamer].redes.instragram << endl;
        cout << "Twitter: " << instagamers[posInstagamer].redes.twitter << endl;
    }

    return 0;
}

int buscarInstagamer(Instagamer instagamer[], int len, string nombre) {
    int i = 0;

    while(instagamer[i].nombre != nombre && i < len) {
        i++;
    }

    return i == len ? -1 : i;
}