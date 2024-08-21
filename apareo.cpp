#include <iostream>

struct Registro {
    int id;
    int cantidad;
};

void generarArchivoInventario1() {
    Registro registros[] = {
        {1, 100},
        {3, 150},
        {5, 200},
        {7, 3000},
        {8, 3200},
    };

    FILE* archivo = fopen("inventario1.dat", "wb");

    if (!archivo) {
        std::cerr << "No se pudo crear el archivo." << std::endl;
        return;
    }

    fwrite(registros, sizeof(Registro), 5, archivo);
    fclose(archivo);
}

void generarArchivoInventario2() {
    Registro registros[] = {
        {2, 50},
        {4, 75},
        {6, 300},
    };

    FILE* archivo = fopen("inventario2.dat", "wb");

    if (!archivo) {
        std::cerr << "No se pudo crear el archivo." << std::endl;
        return;
    }

    fwrite(registros, sizeof(Registro), 3, archivo);
    fclose(archivo);
}

void aparearArrays(Registro arr1[], int len1, Registro arr2[], int len2, Registro resultado[]) {
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (arr1[i].id < arr2[j].id) {
            resultado[k++] = arr1[i++];
        } else {
            resultado[k++] = arr2[j++];
        }
    }
    while (i < len1) {
        resultado[k++] = arr1[i++];
    }
    while (j < len2) {
        resultado[k++] = arr2[j++];
    }
}

void generarArchivoResultado() {
    // ! REGISTRO 1
    Registro registro1[5];
    FILE* archivo_registro1 = fopen("inventario1.dat", "rb");

    if (!archivo_registro1) {
        std::cerr << "No se pudo leer el archivo registro1." << std::endl;
        return;
    }

    fread(registro1, sizeof(Registro), 5, archivo_registro1);
    fclose(archivo_registro1);

    // ! REGISTRO 2
    Registro registro2[3];
    FILE* archivo_registro2 = fopen("inventario2.dat", "rb");

    if (!archivo_registro2) {
        std::cerr << "No se pudo leer el archivo registro2." << std::endl;
        return;
    }

    fread(registro2, sizeof(Registro), 3, archivo_registro2);
    fclose(archivo_registro2);

    // ! REGISTRO RESULTADO
    Registro registros_resultado[8];

    aparearArrays(registro1, 5, registro2, 3, registros_resultado);

    FILE* archivo_resultado = fopen("inventarioFusionado.dat", "wb");

    if (!archivo_resultado) {
        std::cerr << "No se pudo crear el archivo resultado inventario." << std::endl;
        return;
    }

    fwrite(registros_resultado, sizeof(Registro), 8, archivo_resultado);
    fclose(archivo_resultado);

    return;
}

void mostrarArchivo() {
    FILE* archivo = fopen("inventarioFusionado.dat", "rb");

    Registro reg;
    while (fread(&reg, sizeof(Registro), 1, archivo)) {
        std::cout << "ID: " << reg.id << " - Cantidad: " << reg.cantidad << std::endl;
    }

    fclose(archivo);
}

int main() {
    generarArchivoInventario1();
    generarArchivoInventario2();

    //ACÁ DEBEN UTILIZAR APAREO Y CREAR UN NUEVO ARCHIVO CON LOS DATOS APAREADOS
    generarArchivoResultado();
    
    mostrarArchivo();
    // debe mostrar esto:
        // ID: 1 - Cantidad: 100
        // ID: 2 - Cantidad: 50
        // ID: 3 - Cantidad: 150
        // ID: 4 - Cantidad: 75
        // ID: 5 - Cantidad: 200
        // ID: 6 - Cantidad: 300
        // ID: 7 - Cantidad: 3000
        // ID: 8 - Cantidad: 3200

    return 0;
}
