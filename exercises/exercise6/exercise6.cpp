#include <iostream>
using namespace std;

void exerciseSix(unsigned short age);

int main() { 
    exerciseSix(10);

    return 0;
}

void exerciseSix(unsigned short age) {
    if(age <= 12)
        cout << "Menor";
    if(age >= 13 && age <=18)
        cout << "Cadete";
    if(age > 18 && age <= 26)
        cout << "Juvenil";
    if(age > 26)
        cout << "Mayor";
}