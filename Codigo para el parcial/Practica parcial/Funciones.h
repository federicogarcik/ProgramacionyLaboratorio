typedef struct {
    char nombre[50];
    char apellido[50];
    int idAbonado;
    int numero;
    int estado;
}Eabonado;

typedef struct
{
    int idAbonado;
    int idLlamada;
    int motivo;
    int tiempo;
    int estado;
}Ellamada;

/** \brief pone el estado de los indices del array en cero
 *
 * \param abonados: el array
 * \param capacidad: el tamaño del array
 * \param bandera: bandera que indica si ya se han puesto los estados en 0
 */

void estadoLibreAbonados(Eabonado abonados[], int capacidad, int bandera);

/**
 * Obtiene el primer indice libre del array.
 * @param abonado el array se pasa como parametro.
 * @param capacidad: el tamaño del array
 * @return el primer indice disponible
 */

int obtenerEspacioLibre(Eabonado abonados[], int capacidad);


/** \brief  carga los datos de una persona
 *
 * \param abonados: el array
 * \param indice: indice del array en donde se va a cargar los datos
 *
 */

 void cargarDatos(Eabonado abonados[], int indice, int capacidad);

 /** \brief auto incrementa un  numero y lo guarda como dato en el array
  *
  * \param abonados: el array
  * \param capacidad: tamaño del array
  *
  */

 void autoIncremento(Eabonado abonados[], int capacidad);

/** \brief ingresa el id a ser buscado para modificar
 *
 * \return el id ingresado
 *
 */

 int ingresarID();

 /**
 * \brief Obtiene el indice que coincide con el id pasado por parametro.
 * @param abonados el array se pasa como parametro.
 * @param id el id a ser buscado en el array.
 * \param capacidad: el tamaño del array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro id
 */

 int buscarPorId(Eabonado abonados[], int dni, int capacidad);

 /** \brief modifica el nombre y el apellido del abonado del indice
  *
  * \param abonados: el array
  * \param indice: el indice del array a ser modificado
  *
  */

  void modNombreApe(Eabonado abonados[], int indice);

/** \brief da de baja a la persona correspondiente al indice
 *
 * \param abonados: el array
 * \param indice: el indice de la persona a ser dada de baja
 *
 */

void darDeBaja(Eabonado abondaos[], int indice);

/** \brief pone el estado de los indices del array en cero
 *
 * \param abonados: el array
 * \param capacidad: el tamaño del array
 * \param bandera: bandera que indica si ya se han puesto los estados en 0
 */

void estadoLibreLlamadas(Ellamada llamadas[], int capacidad, int bandera);

/** \brief carga los datos de la llamada
 *
 * \param el array de llamadas
 * \param indice de la llamada a ser cargada
 * \param capacidad de el array abonados
 * \param el array de abonados
 *
 */

 void initLlamada(Ellamada llamadas[], int indice, int capacidadAbonados, Eabonado abonados[]);

/**
 * Obtiene el primer indice libre del array.
 * @param abonado el array se pasa como parametro.
 * @param capacidad: el tamaño del array
 * @return el primer indice disponible
 */

 int obtenerEspacioLibreLlamada(Ellamada llamadas[], int capacidad);
