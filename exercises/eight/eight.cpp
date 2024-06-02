#include <iostream>
using namespace std;

struct Alumno {
    string nombre;
    int edad;
    float promedio;
};

struct Promedios {
    int mayores;
    int menores;
};

void llenarAlumnos(Alumno alumnos[], int len);
int buscarAlumno(Alumno alumnos[], int len, string nombreAlumno);
Promedios cantidadPromedios(Alumno alumnos[], int len, Alumno alumno);

int main() {
    string alumnoBuscado;
    Alumno alumnos[10];

    llenarAlumnos(alumnos, 10);

    cout << "Que alumno estas buscando? " << endl;
    cin >> alumnoBuscado;

    int posAlumno = buscarAlumno(alumnos, 10, alumnoBuscado);

    if(posAlumno == -1) {
        cout << "No esta ese alumno en el nuestra base de datos" << endl;
    } else {
        cout << "Alumno con nombre " << alumnoBuscado << " encontrado. A continuacion se detallara su info" << endl;
        cout << "Nombres: " << alumnos[posAlumno].nombre << endl;
        cout << "Edad: " << alumnos[posAlumno].edad << endl;
        cout << "Promedio: " << alumnos[posAlumno].promedio << endl;

        Promedios promedios = cantidadPromedios(alumnos, 10, alumnos[posAlumno]);

        cout << "El alumno " << alumnos[posAlumno].nombre << " tiene otros " << promedios.mayores << " alumnos con promedio mas alto" << endl;
        cout << "El alumno " << alumnos[posAlumno].nombre << " tiene otros " << promedios.menores << " alumnos con promedio mas bajo" << endl;
    }

    return 0;
}

void llenarAlumnos(Alumno alumnos[], int len) {
    for(int i = 0; i < len; i++) {
        cout << "Nombre del alumno: " << endl;
        cin >> alumnos[i].nombre;
        cout << endl;

        cout << "Edad del alumno: " << endl;
        cin >> alumnos[i].edad;
        cout << endl;

        cout << "Promedio del alumno: " << endl;
        cin >> alumnos[i].promedio;
        cout << endl;
    }
}

int buscarAlumno(Alumno alumnos[], int len, string nombreAlumno) {
    int i = 0;

    while(alumnos[i].nombre != nombreAlumno && i < len) {
        i++;
    }

    return i == len ? -1 : i;
}

Promedios cantidadPromedios(Alumno alumnos[], int len, Alumno alumno) {
    Promedios promedios;
    promedios.menores = 0;
    promedios.mayores = 0;

    for(int i = 0; i < len; i++) {
        if(alumnos[i].promedio > alumno.promedio) {
            promedios.mayores++;
        }
        if(alumnos[i].promedio < alumno.promedio) {
            promedios.menores++;
        }
    }

    return promedios;
}