typedef struct
{
    int idPropietarios;
    char nombreYApellido[30];
    int direccion;
    int NumeroTarjetaDeCredito;
    int estado;
}Epropietarios;

typedef struct
{
    char patente[30];
    int marca;
    int idPropietarios;
    int horarioDeEntrada;
    int estado;
    int horarioDeSalida;
}Eautomovil;

/** \brief pone el estado de los indices del array propietarios en cero
 *
 * \param propietarios: el array
 * \param capacidad: tamaño del array
 * \param bandera: bandera que indica si ya se han puesto los estados en 0
 */

void estadoLibrePropietarios(Epropietarios propietarios[], int capacidad, int bandera);

/**
 * Obtiene el primer indice libre del array propietarios.
 * @param lista el array se pasa como parametro.
 * @param capacidad: el tamaño del array
 * @return el primer indice disponible
 */

int obtenerEspacioLibrePropietarios(Epropietarios propietarios[], int capacidad);

/** \brief  carga los datos de una propietario en el array
 *
 * \param lista: el array
 * \param indice: indice del array en donde se va a cargar los datos
 *
 */



void cargarDatos(Epropietarios propietarios[], int indice);



/**
 * Obtiene el indice que coincide con el id pasado por parametro.
 * @param propìetarios el array se pasa como parametro.
 * @param Id el id a ser buscado en el array.
 * \param capacidad: el tamaño del array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro id
 */

int buscarPorId(Epropietarios[], int capacidad, int flagCarga);

/** \brief modifica el numero de la tarjeta de credito
 *
 * \param el array de propietarios
 * \param el indice del dueño a ser modificado
 *
 */

 void modificarPropietario(Epropietarios propietarios[], int indice, int flagCarga);

 /** \brief pone el estado de los indices del array automoviles en cero
 *
 * \param propietarios: el array
 * \param capacidad: tamaño del array
 * \param bandera: bandera que indica si ya se han puesto los estados en 0
 */

void estadoLibreAutomoviles(Eautomovil automoviles[], int capacidad, int bandera);

/**
 * Obtiene el primer indice libre del array automovil.
 * @param lista el array se pasa como parametro.
 * @param capacidad: el tamaño del array
 * @return el primer indice disponible
 */

int obtenerEspacioLibreAutomovil(Eautomovil automoviles[], int capacidad);


 /** \brief
  *
  * \param automoviles : el array
  * \param indice: el indice donde se van a cargar los datos
  * \return
  *
  */

void ingresoAutomovil(Eautomovil automoviles[], int indice, int flagCarga, Epropietarios propietarios[], int capacidadPropietarios);

/** \brief busca un automovil por patente
 *
 * \param automoviles: el array
 * \param capacidad: el tamaño del array
 * \return devuelve el indice del automovil que coincide con la patente
 *
 */

 int buscarPorPatente(Eautomovil automoviles[], int capacidad, int flagCarga);

 /** \brief calcula la estadia de un auto en el estacionamiento
  *
  * \param automovil: el array de autos
  * \param indice: el indice del auto a ser calculado
  * \param propietarios: el array de propietarios
  * \param capacidadPropietarios: el tamaño del array propietarios
  * \param flagCarga: flag de que los datos estan cargados
  *
  */

 void calcularEstadia(Eautomovil automovil[], int indice, Epropietarios propietarios[], int capacidadPropietarios, int flagCarga);

