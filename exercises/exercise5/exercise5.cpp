#include <iostream>
using namespace std;

void exerciseFive(int ladoUno, int ladoDos, int ladoTres);

int main() {
    exerciseFive(2,2,2);
    
    return 0;
}

void exerciseFive(int ladoUno, int ladoDos, int ladoTres) {
    if(ladoUno == ladoDos && ladoDos == ladoTres)
        cout << "Equilatero";

    if(ladoUno != ladoDos && ladoUno != ladoTres && ladoDos != ladoTres)
        cout << "Escaleno";

    if(ladoUno == ladoDos && ladoUno != ladoTres)
        cout << "Isosceles";

    if(ladoUno == ladoTres && ladoUno != ladoDos)
        cout << "Isosceles";

    if(ladoDos == ladoTres && ladoUno != ladoDos)
        cout << "Isosceles";
}