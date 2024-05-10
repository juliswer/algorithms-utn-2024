#include <iostream>
using namespace std;

/*
Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si
hubo valores):
• El valor máximo negativo
• El valor mínimo positivo
• El valor mínimo dentro del rango -17.3 y 26.9
• El promedio de todos los valores.
*/

void exerciseThirteen(const float* arrOfValues, int arrLength);

int main() {
    
    return 0;
}

void exerciseThirteen(const float* arrOfValues, int arrLength) {
   float maxNegativeValue = 0;
   float minPositiveValue = 0;
   float minValueOnRange = 0;
   float generalCounter = 0;
   const float minValueRange = -17.3;
   const float maxValueRange = 26.9;

   for(int i = 0; arrOfValues[i] != '\0'; i++) {
       generalCounter += arrOfValues[i];

       if(arrOfValues[i] < 0) {
           if(maxNegativeValue == 0)
               maxNegativeValue = arrOfValues[i];
           if(arrOfValues[i] > maxNegativeValue)
               maxNegativeValue = arrOfValues[i];
       }

       if(arrOfValues[i] > 0) {
           if(maxNegativeValue == 0)
               minPositiveValue = arrOfValues[i];
           if(arrOfValues[i] < minPositiveValue)
               minPositiveValue = arrOfValues[i];
       }

       if(arrOfValues[i] >= minValueRange && arrOfValues[i] <= maxValueRange) {
           if(minValueOnRange == 0)
               minValueOnRange = arrOfValues[i];
           if(arrOfValues[i] <= minValueOnRange)
               minValueOnRange = arrOfValues[i];
       }
   }

   if(maxNegativeValue == 0) {
       cout << "NO HUBO VALOR MAXIMO NEGATIVO" << '\n';
   } else {
       cout << "VALOR MAXIMO NEGATIVO: " << maxNegativeValue << '\n';
   }

   if(minPositiveValue == 0) {
       cout << "NO HUBO VALOR MINIMO POSITIVO" << '\n';
   } else {
       cout << "VALOR MINIMO POSITIVO: " << minPositiveValue << '\n';
   }

   if(minValueOnRange == 0) {
       cout << "NO HUBO VALOR MINIMO EN RANGO" << '\n';
   } else {
       cout << "VALOR MINIMO DENTRO DEL RANGO: " << minValueRange << " y " << maxValueRange << " ES: " << minValueOnRange << '\n';
   }

   cout << "LA SUMA ES: " << generalCounter << " Y TIENE UN PROMEDIO DE: " << generalCounter / arrLength << '\n';
}