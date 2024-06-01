#include <iostream>
using namespace std;

int busquedaSecuencial(int vec[], int len, int num);
void llenarArray(int arr[], int len);

int main() {
    int arr[5];
    llenarArray(arr, 5);

    int numero;
    cout << "Dame un numero y te digo en que pos esta (-1 = no esta)" << endl;
    cin >> numero;

    int pos = busquedaSecuencial(arr, 4, numero);

    cout << "Lo encontre en: " << pos << endl;

    return 0;
}

void llenarArray(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        cout << "Dame un numero para la pos " << i << endl;
        cin >> arr[i];
    }
}

int busquedaSecuencial(int vec[], int len, int num) {
    int i = 0;
    while(i < len && vec[i] != num) {
        i++;
    }
    
    return i == len ? -1 : i;
}