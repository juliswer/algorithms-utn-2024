#include <iostream>
using namespace std;

// ! PUNTO 1
struct AuxMasProduccion {
    int fecha;
    int cantidad;
};

struct Silla {
    int codigo;
    string tipo_madera;
    int fecha_produccion;
    int codigo_linea;
};

struct LineaProduccion {
    string nombre;
    int capacidad_diaria;
    int cantidad;
};

void execute();

// --- lineas
bool compararLineasCapacidad(const LineaProduccion& a, const LineaProduccion& b);
void insertarLineaYOrdenar(LineaProduccion lineas[], int& len, LineaProduccion l);
LineaProduccion encontrarLineaMayorCapacidad(LineaProduccion lineas[]);
LineaProduccion lineaMasSillasProducidas(LineaProduccion lineas[], int len);

// --- sillas
bool compararSillasFechaProduccion(const Silla& a, const Silla& b);
void insertarSillaYOrdenar(Silla sillas[], int& len, Silla s);
void mostrarSillas(Silla sillas[], int len);
Silla sillaMasReciente(Silla sillas[]);
int laMayorProd(Silla sillas[], int len);

int main() {
    execute();

    return 0;
}

void execute() {
    int lineasLen = 2;
    LineaProduccion lineas[lineasLen];
    lineas[0].cantidad = 0;
    lineas[0].capacidad_diaria = 20;
    lineas[0].nombre = "La linea con 20";
    
    lineas[1].cantidad = 0;
    lineas[1].capacidad_diaria = 10;
    lineas[1].nombre = "La linea con 10";

    LineaProduccion lineaAInsetar;
    lineaAInsetar.cantidad = 0;
    lineaAInsetar.capacidad_diaria = 35;
    lineaAInsetar.nombre = "La linea con 35 (INSERTADA)";

    insertarLineaYOrdenar(lineas, lineasLen, lineaAInsetar);

    int sillasLen = 4;
    Silla sillas[sillasLen];
    sillas[0].codigo = 0;
    sillas[0].codigo_linea = 1;
    sillas[0].fecha_produccion = 20181209;
    sillas[0].tipo_madera = "Pino";

    sillas[1].codigo = 1;
    sillas[1].codigo_linea = 2;
    sillas[1].fecha_produccion = 19900907;
    sillas[1].tipo_madera = "Roble";

    sillas[2].codigo = 2;
    sillas[2].codigo_linea = 3;
    sillas[2].fecha_produccion = 20181209;
    sillas[2].tipo_madera = "Roble";

    sillas[3].codigo = 3;
    sillas[3].codigo_linea = 3;
    sillas[3].fecha_produccion = 20181209;
    sillas[3].tipo_madera = "Roble";

    Silla sillaAInsertar;
    sillaAInsertar.codigo = 2;
    sillaAInsertar.codigo_linea = 3;
    sillaAInsertar.fecha_produccion = 20221218;
    sillaAInsertar.tipo_madera = "Abedul";

    insertarSillaYOrdenar(sillas, sillasLen, sillaAInsertar);

    int fecha = laMayorProd(sillas, sillasLen);    
}

bool compararLineasCapacidad(const LineaProduccion& a, const LineaProduccion& b) {
    return a.capacidad_diaria > b.capacidad_diaria;
}

// ! PUNTO 2
void insertarLineaYOrdenar(LineaProduccion lineas[], int& len, LineaProduccion l) {
    lineas[len] = l;
    len++;

    sort(lineas, lineas + len, compararLineasCapacidad);
}

// ! PUNTO 5
LineaProduccion encontrarLineaMayorCapacidad(LineaProduccion lineas[]) {
    return lineas[0];
}

// ! PUNTO 8
LineaProduccion lineaMasSillasProducidas(LineaProduccion lineas[], int len) {
    LineaProduccion lineaMasProductiva = lineas[0];

    for(int i = 1; i < len; i++) {
        if(lineas[i].cantidad > lineaMasProductiva.cantidad) {
            lineaMasProductiva = lineas[i];
        }
    }

    return lineaMasProductiva;
}

bool compararSillasFechaProduccion(const Silla& a, const Silla& b) {
    return a.fecha_produccion > b.fecha_produccion;
}

// ! PUNTO 3
void insertarSillaYOrdenar(Silla sillas[], int& len, Silla s) {
    sillas[len] = s;
    len++;

    sort(sillas, sillas + len, compararSillasFechaProduccion);
}

// ! PUNTO 4
void mostrarSillas(Silla sillas[], int len) {
    for(int i = 0; i < len; i++) {
        cout << "Silla: " << sillas[i].codigo << endl;
    }
}

// ! PUNTO 6
Silla sillaMasReciente(Silla sillas[]) {
    return sillas[0];
}

int busquedaAuxiliarSec(AuxMasProduccion auxs[], int len, int fecha) {
    int i = 0;

    while(i < len && auxs[i].fecha != fecha) {
        i++;
    }

    return i == len ? -1 : i;
}

// ! PUNTO 7
int laMayorProd(Silla sillas[], int len) {
    AuxMasProduccion unidades[len];

    for(int i = 0; i < len; i++) {
        int fechaPos = busquedaAuxiliarSec(unidades, len, sillas[i].fecha_produccion);
        if(fechaPos == -1) {
            unidades[i].fecha = sillas[i].fecha_produccion;
            unidades[i].cantidad = 1;
        } else {
            unidades[fechaPos].cantidad += 1;
        }
    }

    AuxMasProduccion mayorRegistro = unidades[0];
    int unidadesLen = sizeof(unidades) / sizeof(unidades[0]);

    for(int i = 1; i < unidadesLen; i++) {
        if(unidades[i].cantidad > mayorRegistro.cantidad) {
            mayorRegistro = unidades[i];
        }
    }

    return mayorRegistro.fecha;
}