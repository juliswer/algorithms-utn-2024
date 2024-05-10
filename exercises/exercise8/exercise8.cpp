#include <iostream>
#include <vector>
using namespace std;

void exerciseEight(int arrayOfNumbers[10]);

int main() {
    int values[10] = {200, -20, -30, 4, 5, 6, 7, 8, 9, 200};
    exerciseEight(values);

    return 0;
}

void exerciseEight(int arrayOfNumbers[10]) {
    int sumMinusTen = 0;
    int sumHigherThanHundred = 0;
    int higherThanHundredCounter = 0;
    float averageHundred = 0.00;
    
    for (int i = 0; i < 10; i++) {
        cout << arrayOfNumbers[i] << endl;
        if (arrayOfNumbers[i] < -10) {
            sumMinusTen += arrayOfNumbers[i];
        } else if(arrayOfNumbers[i] > 100) {
            sumHigherThanHundred += arrayOfNumbers[i];
            cout << "TENGO UN > 100" << arrayOfNumbers[i] << endl;
            higherThanHundredCounter++;
        } else {
            cout << "NO ENTRE EN NINGUNO";
        }
    }

    averageHundred = sumHigherThanHundred / higherThanHundredCounter;
    cout << "La suma de los -10 es " << sumMinusTen << endl;
    cout << "AVG Hundred " << averageHundred << endl;
}