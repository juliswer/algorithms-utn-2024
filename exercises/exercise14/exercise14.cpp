#include <iostream>
using namespace std;

/*
Un buque de carga traslada 100 contenedores a tres diferentes puertos del país. Los
puertos se identifican con los números 1, 2 y 3.
De cada contenedor que el buque traslade se registran los siguientes datos:
• Identificación del contenedor (entero)
• Peso del contenedor en kg (entero)
• Puerto de arribo(un valor de 1 a 3).
Se pide calcular e informar:
i. El peso total que el buque debe trasladar
ii. La identificación del contenedor de mayor peso
iii. La cantidad de contenedores que debe trasladar a cada puerto
*/

enum PUERTOS {
    PUERTO_1 = 1,
    PUERTO_2 = 2,
    PUERTO_3 = 3,
};

struct Contenedor {
    int identificacion;
    int peso;
    PUERTOS puertoDeArribo;
};

void exerciseFourteen(Contenedor contenedores[100]);

int main() {
    Contenedor contenedor1;
    contenedor1.identificacion = 1;
    contenedor1.peso = 200;
    contenedor1.puertoDeArribo = PUERTOS::PUERTO_1;

    Contenedor contenedores[100] = {contenedor1};
    exerciseFourteen(contenedores);

    return 0;
}

void exerciseFourteen(Contenedor contenedores[100]) {
    int pesoATrasladar = 0;
    int mayorPesoRegistrado = 0;
    int identifiacionMayorPeso = -1;
    int cantidadAPuerto1 = 0;
    int cantidadAPuerto2 = 0;
    int cantidadAPuerto3 = 0;

    for(int i = 0; i < 4; i++) {
        pesoATrasladar += contenedores[i].peso;
        
        if(contenedores[i].peso > mayorPesoRegistrado) {
            mayorPesoRegistrado = contenedores[i].peso;
            identifiacionMayorPeso = contenedores[i].identificacion;
        }
        
        switch(contenedores[i].puertoDeArribo) {
            case PUERTOS::PUERTO_1 :
                cantidadAPuerto1++;
                break;
            case PUERTOS::PUERTO_2 :
                cantidadAPuerto2++;
                break;
            case PUERTOS::PUERTO_3 :
                cantidadAPuerto3++;
                break;
        }
    }
    
    cout << "ESTOY TRASLADANDO: " << pesoATrasladar << "kg" << endl;
    cout << "EL MAYOR PESO REGISTRADO FUE DE: " << mayorPesoRegistrado << " Y ES DEL CONTENEDOR IDENTIFICADO CON: " << identifiacionMayorPeso << endl;
    cout << "CONTENEDORES A PUERTO 1: " << cantidadAPuerto1 << endl;
    cout << "CONTENEDORES A PUERTO 2: " << cantidadAPuerto2 << endl;
    cout << "CONTENEDORES A PUERTO 3: " << cantidadAPuerto3 << endl;
}