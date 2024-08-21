#include <iostream>
using namespace std;

struct Registro {
    int id;
    char departamento[30];
    float ingreso;
};

void corteDeControl(Registro registros[], int len) {
    char departamentoActual[10] = "";
    float contador = 0.00;

    for (int i = 0; i < len; i++) {
        if (strcmp(departamentoActual, registros[i].departamento) != 0) {
            if (contador > 0) {
                cout << "Departamento: " << departamentoActual << " - Ingreso Total: " << contador << endl;
            }
            strcpy(departamentoActual, registros[i].departamento);
            contador = registros[i].ingreso;
        } else {
            contador += registros[i].ingreso;
        }
    }
    if (contador > 0) {
        cout << "Departamento: " << departamentoActual << " - Ingreso Total: " << contador << endl;
    }
}

void generarArchivoIngresos() {
    FILE* archivo = fopen("ingresos.dat", "wb");
    if (!archivo) {
        std::cerr << "No se pudo crear el archivo." << std::endl;
        return;
    }

    Registro registros[] = {
        {1, "Ventas", 1500.75},
        {2, "Ventas", 2000.50},
        {3, "Marketing", 3000.00},
        {4, "Marketing", 1200.75},
        {5, "IT", 5000.25},
        {6, "IT", 2500.30},
        {7, "Ventas", 1000.2},
    };

    int numRegistros = sizeof(registros) / sizeof(Registro);

    for (int i = 0; i < numRegistros; ++i) {
        fwrite(&registros[i], sizeof(Registro), 1, archivo);
    }

    fclose(archivo);

    // ! APLICO CORTE DE CONTROL
    corteDeControl(registros, numRegistros);
}

int main() {
    generarArchivoIngresos();

// Tienen que hacer el código para que el sistema termine mostrando por pantalla lo siguiente:
// ! Departamento: Ventas - Ingreso Total: 3501.25
// * Departamento: Marketing - Ingreso Total: 4200.75
// ? Departamento: IT - Ingreso Total: 7500.55
// ! Departamento: Ventas - Ingreso Total: 1000.2 
    return 0;
}
