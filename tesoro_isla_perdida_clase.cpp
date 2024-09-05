#include <iostream>

using namespace std;

struct Pista {
    int codigo;
    int dificultad;
    char desc[256];
    int resultadoEsperado;
};

struct Estadistica {
    int codigo;
    float promedioAprobados;
    float cantidadAprobados;
    int cantidadRechazados;
};

struct Registro {
    int codigo;
    int dificultad;
    char desc[256];
    bool resuelta;
};

struct MasBajo {
    int codigo;
    float promedioDif;
};

// Función para crear archivos binarios con datos "dummy"
void crearArchivosDummy() {
    FILE *file1 = fopen("archivo1.dat", "wb");
    FILE *file2 = fopen("archivo2.dat", "wb");


    // Pistas para archivo1.dat
    Pista pistas1[] = {
        {1, 5, "Pista A1", 10},
        {3, 2, "Pista A2", 20},
        {3, 8, "Pista A3", 1},
        {5, 7, "Pista A4", 30}
    };

    // Pistas para archivo2.dat
    Pista pistas2[] = {
        {1, 6, "Pista B5", 10},
        {2, 4, "Pista B10", 15},
        {3, 6, "Pista B20", 25},
        {6, 9, "Pista B30", 35}
    };

    // Escribir las pistas en archivo1.dat
    for (int i = 0; i < 4; i++) {
        fwrite(&pistas1[i], sizeof(Pista), 1, file1);
    }

    // Escribir las pistas en archivo2.dat
    for (int i = 0; i < 4; i++) {
        fwrite(&pistas2[i], sizeof(Pista), 1, file2);
    }

    fclose(file1);
    fclose(file2);

    cout << "Archivos dummy creados con éxito." << endl;
}

// Función para mostrar todos los elementos de un archivo binario
void mostrarArchivo() {
    FILE *file = fopen("pistas_combinadas.dat", "rb");

    if (!file) {
        cout << "Error al abrir el archivo " << "pistas_combinadas.dat" << endl;
        return;
    }

    Pista pista;
    while (fread(&pista, sizeof(Pista), 1, file)) {
        cout << "Código: " << pista.codigo << ", Dificultad: " << pista.dificultad
             << ", Descripción: " << pista.desc << ", Resultado esperado: " << pista.resultadoEsperado << endl;
    }

    fclose(file);
}

void combinarPistas() {
    FILE *archivo1 = fopen("archivo1.dat", "rb");
    FILE *archivo2 = fopen("archivo2.dat", "rb");
    FILE *archivoSalida = fopen("pistas_combinadas.dat", "wb");

    Pista pis1, pis2;

    bool hayPista1 = fread(&pis1, sizeof(Pista), 1, archivo1);
    bool hayPista2 = fread(&pis2, sizeof(Pista), 1, archivo2);

    while (hayPista1 && hayPista2) {
        if (pis1.codigo < pis2.codigo) {
            fwrite(&pis1, sizeof(Pista), 1, archivoSalida);
            hayPista1 = fread(&pis1, sizeof(Pista), 1, archivo1);
        } else {
            fwrite(&pis2, sizeof(Pista), 1, archivoSalida);
            hayPista2 = fread(&pis2, sizeof(Pista), 1, archivo2);
        }
    }

    while (hayPista1)  {
        fwrite(&pis1, sizeof(Pista), 1, archivoSalida);
        hayPista1 = fread(&pis1, sizeof(Pista), 1, archivo1);
    }
    
    while (hayPista2) {
        fwrite(&pis2, sizeof(Pista), 1, archivoSalida);
        hayPista2 = fread(&pis2, sizeof(Pista), 1, archivo2);
    }

    fclose(archivo1);
    fclose(archivo2);
    fclose(archivoSalida);
    
}

void conteoPorCodigo() {
    FILE *archivo = fopen("pistas_combinadas.dat", "rb");
    Pista pista;
    int codigoActual = -1;
    float contadorDif = 0.00;
    float promedioDif = 0.00;
    int contador = 0;
    MasBajo promedioMasBajo = {-1, 0.00};

    while (fread(&pista, sizeof(Pista), 1, archivo)) {
        if (codigoActual != pista.codigo) {
            if (contador > 0) {
                
                if(promedioDif < promedioMasBajo.promedioDif) {
                    promedioMasBajo.codigo = codigoActual;
                    promedioMasBajo.promedioDif = promedioDif;
                }

                cout << "Codigo: " << codigoActual << ", Cantidad de Pistas: " << contador << ", Promedio Dificultad: " << promedioDif << endl;
            }
            if(promedioMasBajo.codigo == -1) {
                promedioMasBajo.codigo = codigoActual;
                promedioMasBajo.promedioDif = promedioDif;
            }

            contadorDif = pista.dificultad;
            promedioDif = pista.dificultad;

            codigoActual = pista.codigo;
            contador = 1;
        } else {
            contador++;
            contadorDif += pista.dificultad;

            promedioDif = contadorDif / contador;
        }
    }

    if (contador > 0) {
        if(promedioDif < promedioMasBajo.promedioDif) {
            promedioMasBajo.codigo = codigoActual;
            promedioMasBajo.promedioDif = promedioDif;
        }
        cout << "Codigo: " << codigoActual << ", Cantidad de Pistas: " << contador << ", Promedio Dificultad: " << promedioDif << endl;
    }

    fclose(archivo);

    cout << "EL PROMEDIO MAS BAJO DE DIFICULTAD ES: " << promedioMasBajo.promedioDif << " Y LE CORRESPONDE AL CODIGO " << promedioMasBajo.codigo << endl;

    return;
}

void leerRespuestas() {
    FILE *resultado = fopen("resultado.dat", "rb");
    
    Registro registro;
    while (fread(&registro, sizeof(Registro), 1, resultado)) {
        cout << "Codigo: " << registro.codigo << ", Dificultad: " << registro.dificultad << ", Descripcion: " << registro.desc << ", Acertaste: " << registro.resuelta << endl;
    }

    fclose(resultado);
}

void resolverPista() {
    FILE *archivo = fopen("pistas_combinadas.dat", "rb");
    FILE *resultado = fopen("resultado.dat", "wb");
    Pista pista;
    int codigoQuerido;
    int contadorPista = 0;
    int respuesta = -1;

    cout << "Que codigo queres?" << endl;
    cin >> codigoQuerido;

   while (fread(&pista, sizeof(Pista), 1, archivo)) {
    if(pista.codigo == codigoQuerido) {
        contadorPista++;
        cout << "Esta es la pista " << contadorPista << " de tu codigo: " << codigoQuerido << ". La respuesta deberia ser: " << pista.resultadoEsperado << endl;
        cout << "Cual es tu respuesta?" << endl;
        cin >> respuesta;

        Registro reg;
        reg.codigo = codigoQuerido;
        reg.dificultad = pista.dificultad;
        strcpy(reg.desc, pista.desc);
        reg.resuelta = (respuesta == pista.resultadoEsperado);

        fwrite(&reg, sizeof(Registro), 1, resultado);
    } else {
        if(respuesta == -1) {
            cout << "No existe pista con el codigo " << codigoQuerido << endl;
        }
        break;
    }
   }

    fclose(archivo);
    fclose(resultado);

    leerRespuestas();
}

void estadisticas() {
    FILE *archivoResultados = fopen("resultado.dat", "rb");
    if (!archivoResultados) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Registro registro;
    Estadistica estadisticas[20];
    int numCodigos = 0;

    // Inicializa las estadísticas con 0
    for (int i = 0; i < 20; i++) {
        estadisticas[i].codigo = -1;  // Código -1 indica que está vacío
        estadisticas[i].promedioAprobados = 0.0f;
        estadisticas[i].cantidadAprobados = 0.0f;  // Inicializa como float
        estadisticas[i].cantidadRechazados = 0;
    }

    // Lee los registros y actualiza las estadísticas
    while (fread(&registro, sizeof(Registro), 1, archivoResultados)) {
        // Busca si el código ya está registrado en el array de estadísticas
        int index = -1;
        for (int i = 0; i < numCodigos; i++) {
            if (estadisticas[i].codigo == registro.codigo) {
                index = i;
                break;
            }
        }

        // Si no está, agrega un nuevo código al array de estadísticas
        if (index == -1 && numCodigos < 20) {
            index = numCodigos++;
            estadisticas[index].codigo = registro.codigo;
        }

        // Actualiza las estadísticas según si está resuelta o no
        if (registro.resuelta) {
            estadisticas[index].cantidadAprobados += 1.0f;  // Incrementa como float
        } else {
            estadisticas[index].cantidadRechazados++;
        }
    }

    // Calcula el promedio de aprobados para cada código
    for (int i = 0; i < numCodigos; i++) {
        float total = estadisticas[i].cantidadAprobados + estadisticas[i].cantidadRechazados;  // Total como float
        if (total > 0) {
            estadisticas[i].promedioAprobados = (estadisticas[i].cantidadAprobados / total) * 100;
        }
    }

    // Muestra las estadísticas
    for (int i = 0; i < numCodigos; i++) {
        cout << "Código: " << estadisticas[i].codigo 
             << ", Promedio de Aprobados: " << estadisticas[i].promedioAprobados << "%"
             << ", Cantidad Aprobados: " << estadisticas[i].cantidadAprobados 
             << ", Cantidad Rechazados: " << estadisticas[i].cantidadRechazados << endl;
    }

    fclose(archivoResultados);
}

int main() {
    // Crear archivos dummy antes de combinar
    crearArchivosDummy();

    // Combinar los archivos creados
    combinarPistas();

    // Mostrar el contenido del archivo combinado
    mostrarArchivo();

    int continuar = true;
    while (continuar) {
        int accion;
        cout << "Ingrese la acción deseada: " << endl;
        cout << "1 - Conteo de pistas por código "<< endl;
        cout << "2 - Resolver pista "<< endl;
        cout << "Cualquier otro valor - Salir "<< endl;
        cin >> accion;
        switch (accion)
        {
        case 1:
            conteoPorCodigo();
            break;
        case 2:
            resolverPista();
            continuar = false;
            break;
        default:
            continuar = false;
            break;
        }
    }

    estadisticas();

    return 0;
}