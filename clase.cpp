#include <iostream>
using namespace std;

struct Libro {
    char titulo[256];
    int paginas;
};

void intercambiar(int* a, int* b) {
    int temp = *a;

    *a = *b;
    *b = temp;
    
    return;
}

void modificarLibro(Libro* libro) {
    cout << "Inserte titulo nuevo" << endl;
    cin >> libro->titulo;

    cout << "Inserte cantidad de paginas" << endl;
    cin >> libro->paginas;
}

int main() {
    int a = 10;
    int b = 20;
    
    cout << "dir a: " << &a << " | valor a: " << a << endl;
    cout << "dir b: " << &b << " | valor b: " << b << endl;
    cout << "------" << endl;

    intercambiar(&a, &b);

    cout << "dir a: " << &a << " | valor a: " << a << endl;
    cout << "dir b: " << &b << " | valor b: " << b << endl;

    // Libro* libro;
    // libro = new Libro;
    // strcpy(libro->titulo, "Cualquier cosa");
    // libro->paginas = -1;

    // cout << "Titulo [ANTES] de ser editado: " << libro->titulo << endl;
    // cout << "Paginas [ANTES] de ser editadas: " << libro->paginas << endl;

    // modificarLibro(libro);

    // cout << "Titulo [DESPUES] de ser editado: " << libro->titulo << endl;
    // cout << "Paginas [DESPUES] de ser editadas: " << libro->paginas << endl;
    
    return 0;
}

