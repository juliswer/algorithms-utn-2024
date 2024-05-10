#include <iostream>
using namespace std;

string Tendencia(int A, int B);

int main() {
    
    string tendencia = Tendencia(99, 100);
    cout << "Tendencia Generada: " << tendencia << endl;

    return 0;
}

string Tendencia(int A, int B) {
    if(B - A < 0)
        return "Decreciente";
    if((B - A) < ((A / 100) * 2)) 
        return "Estable";
    
    if((B - A) < ((A / 100) * 5)) 
        return "Leve Ascenso";
    
    return "En ascenso";
}