#include <iostream>
using namespace std;

struct AnioConcurrencia {
    int anio;
    int cantidad;
};

struct Estudiante {
    string nombre;
    int fecha_nacimiento;
    int anio_ingreso;
    int codigo_barrio;
};

struct Barrio {
    int distancia_facultad;
    int codigo;
    int cantidad_estudiantes;
};

struct Result {
    Barrio barriosMasLejano;
    Estudiante estudianteMasJoven;
    int anioDeIngresoMasRepetido;
    Barrio barrioMasConcurrido;
    Barrio barrios[20];
};

Result ejercicio();
void insertarBarrioYOrdenar(Barrio barrios[], int& len, Barrio barrio);
void insertarBarrio(Barrio barrios[], int& len, Barrio barrioAInsertar);
void ordenarBarrioArray(Barrio barrios[], int len);
void insertarEstudiante(Barrio barrios[], int barriosLen, Estudiante estudiantes[], int& estudiantesLen, Estudiante estudianteAInsertar);
int encontrarBarrioSec(Barrio barrios[], int len, int codigo);
Barrio encontrarBarrioMasLejano(Barrio barrios[], int len);
Estudiante encontrarEstudianteMasJoven(Estudiante estudiantes[], int len);
int anioDeIngresoConMasConcurrencia(Estudiante estudiantes[], int len);
Barrio barrioConMasEstudiantes(Barrio barrio[], int len);

int main() {
    Result result = ejercicio();

    return 0;
}

Result ejercicio() {
    int barriosLen = 3;
    Barrio barrios[barriosLen];
    barrios[0].distancia_facultad = 20;
    barrios[0].codigo = 1;
    barrios[0].cantidad_estudiantes = 30;

    barrios[1].distancia_facultad = 90;
    barrios[1].codigo = 2;
    barrios[1].cantidad_estudiantes = 500;

    barrios[2].distancia_facultad = 909;
    barrios[2].codigo = 3;
    barrios[2].cantidad_estudiantes = 1;

    int estudiantesLen = 3;
    Estudiante estudiantes[estudiantesLen];

    estudiantes[0].anio_ingreso = 2020;
    estudiantes[0].codigo_barrio = 1;
    estudiantes[0].fecha_nacimiento = 20040508;
    estudiantes[0].nombre = "Carlos Maidana";

    estudiantes[1].anio_ingreso = 2020;
    estudiantes[1].codigo_barrio = 2;
    estudiantes[1].fecha_nacimiento = 20100608;
    estudiantes[1].nombre = "Carlos Suarez";

    estudiantes[2].anio_ingreso = 2010;
    estudiantes[2].codigo_barrio = 3;
    estudiantes[2].fecha_nacimiento = 20080708;
    estudiantes[2].nombre = "Carlos Irlan";
    
    Barrio barrioAInsertar;
    barrioAInsertar.distancia_facultad = 1;
    barrioAInsertar.codigo = 4;
    barrioAInsertar.cantidad_estudiantes = 90;

    insertarBarrioYOrdenar(barrios, barriosLen, barrioAInsertar);

    for(int i = 0; i < barriosLen; i++) {
        cout << "BARRIO: " << barrios[i].codigo << endl;
    }

    Estudiante estudianteAInsertar;
    estudianteAInsertar.anio_ingreso = 2019;
    estudianteAInsertar.codigo_barrio = 3;
    estudianteAInsertar.fecha_nacimiento = 20240808;
    estudianteAInsertar.nombre = "Pepe";

    insertarEstudiante(barrios, barriosLen, estudiantes, estudiantesLen, estudianteAInsertar);

    for(int i = 0; i < estudiantesLen; i++) {
        cout << "ESTUDIANTE: " << estudiantes[i].nombre << endl;
    }

    Barrio masLejano = encontrarBarrioMasLejano(barrios, barriosLen);

    cout << "BARRIO MAS LEJANO: " << masLejano.codigo << endl;

    Estudiante masJoven = encontrarEstudianteMasJoven(estudiantes, estudiantesLen);

    cout << "EL ESTUDIANTE MAS JOVEN: " << masJoven.nombre << endl;

    int anioConMasConcurrencia = anioDeIngresoConMasConcurrencia(estudiantes, estudiantesLen);

    cout << "EL ANIO CON MAS CONCURRENCIA ES: " << anioConMasConcurrencia << endl;

    Barrio barrioMasConcurrente = barrioConMasEstudiantes(barrios, barriosLen);

    cout << "EL BARRIO MAS CONCURRIDO: " << barrioMasConcurrente.codigo << endl;

    Result result;
    result.anioDeIngresoMasRepetido = anioConMasConcurrencia;
    result.barrioMasConcurrido = barrioMasConcurrente;
    result.barrios = barrios;
    result.barriosMasLejano = masLejano;
    result.estudianteMasJoven = masJoven;
}

Barrio barrioConMasEstudiantes(Barrio barrio[], int len) {
    Barrio barrioMasConcurrente = barrio[0];

    for(int i = 0; i < len; i++) {
        if(barrio[i].cantidad_estudiantes > barrioMasConcurrente.cantidad_estudiantes) {
            barrioMasConcurrente = barrio[i];
        }
    }

    return barrioMasConcurrente;
}

int anioDeIngresoConMasConcurrencia(Estudiante estudiantes[], int len) {
    AnioConcurrencia aniosConcurrencias[len];

    for(int i = 0; i < len; i++) {
        aniosConcurrencias[i].anio = estudiantes[i].anio_ingreso;
        aniosConcurrencias[i].cantidad = 0;
    }

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(aniosConcurrencias[j].anio == estudiantes[i].anio_ingreso) {
                aniosConcurrencias[j].cantidad++;
                break;
            }
        }
    }

    AnioConcurrencia masRepetido = aniosConcurrencias[0];

    for(int i = 1; i < len; i++) {
        if(aniosConcurrencias[i].cantidad > masRepetido.cantidad) {
            masRepetido = aniosConcurrencias[i];
        }
    }

    return masRepetido.anio;
}

Estudiante encontrarEstudianteMasJoven(Estudiante estudiantes[], int len){
    Estudiante masJoven = estudiantes[0];

    for(int i = 1; i < len; i++) {
        if(estudiantes[i].fecha_nacimiento > masJoven.fecha_nacimiento)
            masJoven = estudiantes[i];
    }

    return masJoven;
}

Barrio encontrarBarrioMasLejano(Barrio barrios[], int len) {
    return barrios[len - 1];
}

int encontrarBarrioSec(Barrio barrios[], int len, int codigo) {
    int i = 0;

    while(i < len && barrios[i].codigo != codigo) {
        i++;
    }

    return i == len ? -1 : i;
}

void insertarEstudiante(Barrio barrios[], int barriosLen, Estudiante estudiantes[], int& estudiantesLen, Estudiante estudianteAInsertar) {
    estudiantes[estudiantesLen] = estudianteAInsertar;
    estudiantesLen++;

    int barrioPos = encontrarBarrioSec(barrios, barriosLen, estudianteAInsertar.codigo_barrio);
    barrios[barrioPos].cantidad_estudiantes++;

    // ! NO FUNCIONA
    // ordenarBarrioArray(barrios, barriosLen);
}

void insertarBarrio(Barrio barrios[], int& len, Barrio barrioAInsertar) {
    barrios[len] = barrioAInsertar;
    len++;
}

void intercambiar(Barrio& a, Barrio& b) {
    Barrio temp = a;
    a = b;
    b = temp;
}

void ordenarBarrioArray(Barrio barrios[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (barrios[j].distancia_facultad < barrios[minIndex].distancia_facultad) {
                minIndex = j;
            } else if (barrios[j].distancia_facultad == barrios[minIndex].distancia_facultad && barrios[j].cantidad_estudiantes < barrios[minIndex].cantidad_estudiantes) {
                minIndex = j;
            }
        }
        Barrio temp = barrios[i];
        barrios[i] = barrios[minIndex];
        barrios[minIndex] = temp;
    }
}

void insertarBarrioYOrdenar(Barrio barrios[], int& len, Barrio barrio) {
    insertarBarrio(barrios, len, barrio);
    ordenarBarrioArray(barrios, len);
}