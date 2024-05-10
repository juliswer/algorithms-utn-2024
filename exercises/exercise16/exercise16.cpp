#include <iostream>
using namespace std;

float CalcularPorcentajeDiferencia(int A, int B);

int main() {
    float value = CalcularPorcentajeDiferencia(4, 5);
    cout << "VALUE GENRATED: " << value << endl;

    return 0;
}

float CalcularPorcentajeDiferencia(int A, int B) {
    return (B - A) * 100 / (A + B);
}