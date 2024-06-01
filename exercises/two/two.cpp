#include <iostream>
using namespace std;

int busquedaBinaria(int vec[], int len, int num);
void llenarArray(string vec[], int len);

int main() {
    string nombres[3];
    llenarArray(nombres, 5);

    int nums[4] = {0, 1, 2, 3};

    int pos = busquedaBinaria(nums, 4, 2);

    cout << "POS RECIBIDA: " << nombres[1] << endl;
    
    return 0;
}

void llenarArray(string vec[], int len) {
    for(int i = 0; i < len; i++) {
        cout << "Decime un nombre asi lo meto al arreglo: " << endl;
        cin >> vec[i];
    }
}

int busquedaBinaria(int vec[], int len, int num) {
    int izquierda = 0;
    int derecha = len - 1;

    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;
        if(vec[medio] == num) {
            return medio;
        } else if(vec[medio] < num) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return -1;
}