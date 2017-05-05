#include <stdio.h>
#include <stdlib.h>
#include "estacionamiento.h"

#define A 20
#define B 20

int main()
{
    char seguir = 's';
    int opcion;
    Epropietarios propietarios[A];
    Eautomovil automoviles[B];
    int flagCargaPropietarios = 0;
    int flagCargaAutos = 0;
    int indice;


    do
    {
        printf("1-Alta de propietario \n");
        printf("2-Modificacion de propietario \n");
        printf("3-Ingreso automovil \n");
        printf("4-Egreso automovil \n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            estadoLibrePropietarios(propietarios, A, flagCargaPropietarios);
            indice = obtenerEspacioLibrePropietarios(propietarios, A);
            cargarDatos(propietarios, indice);
            flagCargaPropietarios = 1;
            break;
        case 2:
            indice = buscarPorId(propietarios, A, flagCargaPropietarios);
            modificarPropietario(propietarios, indice, flagCargaPropietarios);

            break;
        case 3:
            estadoLibreAutomoviles(automoviles, B, flagCargaAutos);
            indice = obtenerEspacioLibreAutomovil(automoviles, B);
            ingresoAutomovil(automoviles, indice, flagCargaPropietarios, propietarios, A);
            flagCargaAutos = 1;
            break;
        case 4:
            indice = buscarPorPatente(automoviles, B, flagCargaPropietarios);
            calcularEstadia(automoviles, indice, propietarios, A, flagCargaPropietarios);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("ERROR: esa opcion no es valida\n");
        }
    }
    while(seguir=='s');
        return 0;
}
