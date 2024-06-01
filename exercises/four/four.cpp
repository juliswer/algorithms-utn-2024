#include <iostream>
using namespace std;

int busquedaBinaria(int arr[], int len, int fecha);

int main() {
    int fechas[3] = {20220405, 20230210, 20110627};
    int fechaBuscada;

    cout << "Que fecha estas buscando? (Formato AAAAMMDD)" << endl;
    cin >> fechaBuscada;

    int pos = busquedaBinaria(fechas, 3, fechaBuscada);

    if(pos == -1) {
        cout << "No existe esa fecha en el arreglo" << endl;
    } else {
        cout << "Posicion de la fecha dada: " << pos << endl;
    }

    return 0;
}

int busquedaBinaria(int arr[], int len, int fecha) {
    int izquierda = 0;
    int derecha = len - 1;

    while(izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;

        if(arr[medio] == fecha) {
            return medio;
        } else if(arr[medio] < fecha) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return -1;
}