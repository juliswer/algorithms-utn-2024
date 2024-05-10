#include <iostream>
using namespace std;

void exerciseFour(int valueOne, int valueTwo, int valueThree);

int main() {
    exerciseFour(1, 2, 3);
    return 0;
}

void exerciseFour(int valueOne, int valueTwo, int valueThree) {
    if((valueOne + valueTwo) > valueThree)
        cout << "Forman Triangulo";
    if((valueOne + valueThree) > valueTwo)
        cout << "Forman Triangulo";
    if((valueTwo + valueThree) > valueOne) {
        cout << "Forman Triangulo";
    }
}