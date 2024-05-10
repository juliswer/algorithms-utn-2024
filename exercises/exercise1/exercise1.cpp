#include <iostream>
using namespace std;

void exerciseOne(int valueA, int valueB);

int main () {
    exerciseOne(40, 50);
    
    return 0;
}

void exerciseOne(int valueA, int valueB) {
    cout << "La suma es " << valueA + valueB << '\n';
    cout << "La resta es " << valueA - valueB << '\n';;
    cout << "El producto es " << valueA * valueB << '\n';;
}