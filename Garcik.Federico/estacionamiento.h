typedef struct
{
    int idPropietarios;
    char nombreYApellido[30];
    int direccion;
    int NumeroTarjetaDeCredito;
    int estado;
} Epropietarios;

typedef struct
{
    char patente[30];
    int marca;
    int idPropietarios;
    int horarioDeEntrada;
    int estado;
    int horarioDeSalida;
} Eautomovil;

typedef struct
{
    int sumAudi;
    int sumFerrari;
    int sumAlpha;
    int sumOtros;
}EsumAutos;


/**brief permite ingresar al usuario un dato de tipo cadena de caracteres
*
* \return el dato ingresado por el usuario
* \param input: donde se cargara el dato
*
*/

void ingresarDatoCadenaCaracteres(char input[]);

/** \brief valida que la cadena de caracteres no contenga numeros
 *
 * \param la cadena a ser analizada
 * \return 1aaa si son solo letras y 0 si hay numeros
 *
 */


int validarLetras(char input[]);


/** \brief valida que sea un numero
 *
 * \param el numero ingresado como cadena de caracteres
 * \return
 *
 */

int validarNumero(char numero[]);

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



void cargarDatos(Epropietarios propietarios[], int indice, int flagCargaPropietarios);



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
 * \param capacidad: la capacidad del array
 *
 */

void modificarPropietario(Epropietarios propietarios[], int capacidad, int flagCarga);

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

void ingresoAutomovil(Eautomovil automoviles[], int flagCarga, Epropietarios propietarios[], int capacidadPropietarios, int flagCargaAutos);

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

void calcularEstadia(Eautomovil automovil[], Epropietarios propietarios[], int capacidadPropietarios, int flagCarga, int flagCargaAutos, EsumAutos sumAutos[]);

/** \brief tranforma las letras de uan cadena de caracteres a maysuculas
 *
 * \param la cadena de caracteres
 * \param
 *
 */

void deMinusAMayus(char cadena[]);

/** \brief ordena el array por hora de entrada y patente
 *
 * \param el array de autos
 * \param la capacidad del array de autos
 * \param array auxiliar de autos
 * \return
 *
 */

void ordenarHoraPatente(Eautomovil automovil[], int capacidad, Eautomovil autoAux[]);

/** \brief muestra los autos con su dueño ordenados por hora de entrada
 *
 * \param el array de autos
 * \param el array de propietarios
 * \param la capacidad del array de propietarios
 * \param la capacidad del array de autos
 * \param array auxiliar de autos
 * \return
 *
 */

void mostrarAutosConPropietarios(Eautomovil automovil[], Epropietarios propietario[], int capacidadPropietarios, int capacidadAutos, Eautomovil autoAux[], int flagCarga, int flagCargaAutos);


/** \brief lista todos los propietarios de autos marca audi
 *
 * \param el array de autos
 * \param el array de propietarios
 * \param la capacidad del array de autos
 * \param la capacidad del array de propietarios
 * \return
 *
 */

 void mostrarPropietariosConAutosAudi(Eautomovil automovil[], int capacidadAutos, Epropietarios propietario[], int capacidadPropietarios);

 /** \brief muestra la recaudacion total de cada marca
  *
  * \param el array de automovil
  * \param la capacidad del array de automovil
  * \return
  *
  */


 int mostrarRecaudacionTotalPorMarca(Eautomovil automovil[], int capacidad, EsumAutos sumAutos[], int flagHardCoded);

 /** \brief muestra todos los listados
  *
  * \param el array de automovil
  * \param la capacidad del array de automoviles
  * \return regresa la suma total del estacionamiento
  *
  */


 void mostrar(Eautomovil automovil[], int capacidadAutos, Epropietarios propietario[], int capacidadPropietarios, Eautomovil autoAux[], int flagCarga, int flagCargaAutos, EsumAutos sumAutos[], int flagHardCoded);

 /** \brief hardcodea los datos de los propietarios
  *
  * \param el array de propietarios
  * \return
  *
  */

 void cargarPropietarios(Epropietarios propietarios[]);

 /** \brief hardcodea los datos de los automoviles
  *
  * \param el array de automoviles
  * \return
  *
  */

void cargarAutomoviles(Eautomovil automovil[]);
