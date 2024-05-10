#include <iostream>
using namespace std;

/*
Desarrolle un procedimiento que reciba el costo en pesos de un abono telefónico, 
la cantidad de minutos libres que incluye el abono, el cargo en pesos por minuto 
excedente y la cantidad de minutos utilizados por un abonado, retorne la cantidad 
de minutos excedidos y el monto en pesos a abonar (costo del abono mas minutos 
excedidos por el costo de minutos excedidos) mas el 21% del valor del IVA.
UTILICE FUNCIONES.
*/

struct AbonoTelefonico {
    float costo;
    int minutosLibres;
    float precioMinutoExcedido;
    int minutosUtilizados;
};

struct FacturaAbono {
    int minutosExcedidos;
    float montoFinal;
};

float agregarIVA(float valor, float porcentajeIVA);

FacturaAbono pagarAbono(AbonoTelefonico abono);

int main() {
    AbonoTelefonico abono;
    abono.costo = 100;
    abono.minutosLibres = 30;
    abono.minutosUtilizados = 20;
    abono.precioMinutoExcedido = 40.74;

    FacturaAbono factura =  pagarAbono(abono);
    cout << "ME PASE: " << factura.minutosExcedidos << " MINUTOS" << endl;
    cout << "TENGO QUE PAGAR: " << factura.montoFinal << " PESOS" << endl;

    return 0;
}

float agregarIVA(float valor, float porcentajeIVA) {
    return valor + ((valor / 100) * porcentajeIVA);
}

FacturaAbono pagarAbono(AbonoTelefonico abono) {
    int minutosExcedidos = 0;

    // si hago una resta entre utilizados y libres, 
    // y esta misma me da mayor a cero, quiere decir
    // que hay un excedente, por ende obtengo su cantidad.
    if((abono.minutosUtilizados - abono.minutosLibres) > 0)  {
        minutosExcedidos = abono.minutosUtilizados - abono.minutosLibres;
    }

    float montoMinutosExcedidos = minutosExcedidos * abono.precioMinutoExcedido;
    float totalAPagar = agregarIVA((abono.costo + montoMinutosExcedidos), 21);

    FacturaAbono factura;
    factura.minutosExcedidos = minutosExcedidos;
    factura.montoFinal = totalAPagar;

    return factura;
}