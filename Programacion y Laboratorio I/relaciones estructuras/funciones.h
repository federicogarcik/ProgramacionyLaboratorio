typedef struct
    {
        int idSerie;
        char titulo[20];
        int temporadas;
        char genero[20];
        int estado;
    } eSerie;

    typedef struct
    {
        int idCliente;
        char nombre[30];
        int estado;
        int idSerie;
    } eCliente;

    typedef struct
    {
        int idSerie;
        int cont;
    } eLoser;

void cargarSeries(eSerie[]);

void cargarClientes(eCliente[]);

void mostrarSeries(eSerie[], int capacidad);

void mostrarClientes(eCliente[], int capacidad);

void mostrarClientesConSerie(eCliente[], eSerie[], int, int);

void mostrarSeriesConClientes(eCliente[], eSerie[], int capacidadClientes, int capacidadSeries);

void mostrarSerieLoser(eCliente[], eSerie[], int capacidadClientes, int capacidadSeries);

void mostrarClientesTBBT(eCliente[], int capacidadClientes);
