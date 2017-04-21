
typedef struct
{
    int idSerie;
    char nombre[50];
    int temporadas;
    char genero[30];
    int estado;
} eSerie;

void inicializarSeries(eSerie[], int);

eSerie crearSerie(int, char[], int, char[]);

void mostrarNetflix(eSerie[], int);
void mostrarSerie(eSerie);
void ordenarSeries(eSerie[], int);

int buscarLibre(eSerie[], int);
