#include <iostream>
using namespace std;

int MAX_LIBROS = 300;

struct Libro {
    int codigo;
    string titulo;
    string autor;
    int fecha_publicacion;
    string genero;
};

struct AutorCounter {
    string nombre;
    int contador;
};

struct GeneroCounter {
    string nombre;
    int contador;
};

struct AnioCounter {
    int anio;
    int contador;
};

void execute();

void insertar_libro(Libro libros[], int& len, Libro l);
bool compararLibrosFecha(const Libro& a, const Libro& b);
Libro libro_mas_reciente(Libro libros[]);
string autor_mas_libros(Libro libros[], int len);
int buscar_autor_sec(AutorCounter autores[], int len, string autor);
string genero_mas_libros(Libro libros[], int len);
int buscar_genero_sec(GeneroCounter generos[], int len, string genero);
int anio_mas_libros_publicados(Libro libros[], int len);
int obtener_anio_de_fecha(int fecha);
int buscar_anio_sec(AnioCounter anios[], int len, int anio_buscado);

int main() {
    execute();

    return 0;
}

void execute() {
    int libros_init_len = 3;
    Libro libros[libros_init_len];
    libros[0].autor = "Tatin";
    libros[0].codigo = 1;
    libros[0].fecha_publicacion = 20240304;
    libros[0].genero = "Policial";
    libros[0].titulo = "El libro de tatin";

    libros[1].autor = "Insertado";
    libros[1].codigo = 2;
    libros[1].fecha_publicacion = 20200304;
    libros[1].genero = "suspenso";
    libros[1].titulo = "El libro de marlon";

    libros[2].autor = "Insertado";
    libros[2].codigo = 3;
    libros[2].fecha_publicacion = 20240618;
    libros[2].genero = "suspenso";
    libros[2].titulo = "El libro del papu";

    Libro libro_a_insertar;
    libro_a_insertar.autor = "Insertado";
    libro_a_insertar.codigo = 4;
    libro_a_insertar.fecha_publicacion = 20220618;
    libro_a_insertar.genero = "suspenso";
    libro_a_insertar.titulo = "El libro insertado";

    insertar_libro(libros, libros_init_len, libro_a_insertar);

    for(int i = 0; i < libros_init_len; i++) {
        cout << "EL LIBRO CON TITULO: " << libros[i].titulo << endl;
    }

    Libro libro_reciente = libro_mas_reciente(libros);
    cout << "EL LIBRO MAS RECIENTE: " << libro_reciente.titulo << endl;

    string autor_con_mas_libros = autor_mas_libros(libros, libros_init_len);

    cout << "EL AUTOR CON MAS LIBROS ES: " << autor_con_mas_libros << endl;

    string genero_con_mas_libros = genero_mas_libros(libros, libros_init_len);

    cout << "EL GENERO CON MAS LIBROS ES: " << genero_con_mas_libros << endl;

    int anio_con_mas_libros_publicados = anio_mas_libros_publicados(libros, libros_init_len);

    cout << "EL ANIO CON MAS LIBROS PUBLICADOS ES: " << anio_con_mas_libros_publicados << endl;
}

void insertar_libro(Libro libros[], int& len, Libro l) {
    if(len == MAX_LIBROS) {
        cout << "Limite de libros excedido. Maximo 300" << endl;
    }
    libros[len] = l;
    len++;

    sort(libros, libros + len, compararLibrosFecha);
}

bool compararLibrosFecha(const Libro& a, const Libro& b) {
    return a.fecha_publicacion > b.fecha_publicacion;
}

Libro libro_mas_reciente(Libro libros[]) {
    return libros[0];
}

int buscar_autor_sec(AutorCounter autores[], int len, string autor) {
    int i = 0;

    while(i < len && autores[i].nombre != autor) {
        i++;
    }

    return i == len ? -1 : i;
}

string autor_mas_libros(Libro libros[], int len) {
    AutorCounter autores[len];

    for(int i = 0; i < len; i++) {
        int autorPos = buscar_autor_sec(autores, len, libros[i].autor);
        if(autorPos != -1) {
            autores[autorPos].contador++;
        } else {
            autores[i].nombre = libros[i].autor;
            autores[i].contador = 1;
        }
    }

    int autoresLen = sizeof(autores) / sizeof(autores[0]);

    AutorCounter autor_con_mas = autores[0];

    for(int i = 1; i < autoresLen; i++){
        if(autores[i].contador > autor_con_mas.contador) {
            autor_con_mas = autores[i];
        }
    }

    return autor_con_mas.nombre;
}

int buscar_genero_sec(GeneroCounter generos[], int len, string genero) {
    int i = 0;

    while(i < len && generos[i].nombre != genero) {
        i++;
    }

    return i == len ? -1: i;
}

string genero_mas_libros(Libro libros[], int len) {
    GeneroCounter generos[len];
    
    for(int i = 0; i < len; i++) {
        int generoPos = buscar_genero_sec(generos, len, libros[i].genero);
        if(generoPos != -1) {
            generos[generoPos].contador++;
        } else {
            generos[i].nombre = libros[i].genero;
            generos[i].contador = 1;
        }
    }

    int generosLen = sizeof(generos) / sizeof(generos[0]);

    GeneroCounter genero_con_mas = generos[0];

    for(int i = 1; i < generosLen; i++){
        if(generos[i].contador > genero_con_mas.contador) {
            genero_con_mas = generos[i];
        }
    }

    return genero_con_mas.nombre;
}

int obtener_anio_de_fecha(int fecha) {
    // fecha en formato AAAAMMDD
    return fecha / 10000;
}

int buscar_anio_sec(AnioCounter anios[], int len, int anio_buscado) {
    int i = 0;

    while(i < len && anios[i].anio != anio_buscado) {
        i++;
    }

    return i == len ? -1 : i;
}

int anio_mas_libros_publicados(Libro libros[], int len) {
    AnioCounter anios[len];

    for(int i = 0; i < len; i++){
        int libro_anio = obtener_anio_de_fecha(libros[i].fecha_publicacion);

        int anio_pos = buscar_anio_sec(anios, len, libro_anio);

        if(anio_pos != -1) {
            anios[anio_pos].contador++;
        } else {
            anios[i].anio = libro_anio;
            anios[i].contador = 1;
        }
    }

    int anios_len = sizeof(anios) / sizeof(anios[0]);

    AnioCounter anio_mas_repetido = anios[0];

    for(int i = 1; i < anios_len; i++) {
        if(anios[i].contador > anio_mas_repetido.contador) {
            anio_mas_repetido = anios[i];
        }
    }

    return anio_mas_repetido.anio;
}