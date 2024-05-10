#include <iostream>
using namespace std;

/*
Dados N valores informar el mayor, 
el menor y en que posición del 
conjunto fueron ingresados.
*/

void exerciseEleven(const int* values, int arrLength);

int main() { 
    int values[] = {10, 1, 5, 1, 5, 11, 0};
    int valuesLength = sizeof(values)/ sizeof(values[0]);
    
    exerciseEleven(values, valuesLength);
    return 0;
}

void exerciseEleven(const int* values, int arrLength) {
    int highestNumber = values[0];
    short highestPos = 0;
    int lowestNumber = values[0];
    short lowestPos = 0;

    for(int i = i; i < arrLength; i++) {
        if(values[i] > highestNumber) {
            highestNumber = values[i];
            highestPos = i;
        }
        if(values[i] < lowestNumber) {
            lowestNumber = values[i];
            lowestPos = i;
        }
    }

    cout << "Highest Number: " << highestNumber << "\tLowest Number: " << lowestNumber << endl;
    cout << "Found at: " << highestPos << " \tFound at: " << lowestPos << endl;
}