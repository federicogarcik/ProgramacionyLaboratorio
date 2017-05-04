#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define A 10
#define B 10

int main()
{
    char seguir = 's';
    int opcion;
    Eabonado abonados[A];
    Ellamada llamadas[B];
    int indice;
    int bandera = 0;
    int idAux;
    int indiceAux;
    int flagLlamadas;

    while(seguir=='s')
    {
        printf("1-ALTA DEL ABONADO \n");
        printf("2-MODIFICAR DATOS DEL ABONADO \n");
        printf("3-BAJA DEL ABONADO \n");
        printf("4-NUEVA LLAMADA \n");
        printf("5-FIN LLAMADA \n");
        printf("6-INFORMAR \n");
        printf("7- Salir\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            estadoLibreAbonados(abonados, A, bandera);
            indice = obtenerEspacioLibre(abonados,  A);
            cargarDatos(abonados, indice, A);
            bandera = 1;
            break;
        case 2:
            idAux = ingresarID();
            indiceAux = buscarPorId(abonados, idAux, A);
            modNombreApe(abonados, indiceAux);
            break;
        case 3:
            idAux = ingresarID();
            indiceAux = buscarPorId(abonados, idAux, A);
            darDeBaja(abonados, indiceAux);
            break;
        case 4:
            estadoLibreLlamadas(llamadas, B, flagLlamadas);
            indice = obtenerEspacioLibreLlamada(llamadas, B);
            initLlamada(llamadas, indice, A, abonados);
            flagLlamadas = 1;
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            seguir = 'n';
            break;
        default:
            printf("ERROR: esa no es una opcion valida");
            break;
        }
    }
    return 0;
}
