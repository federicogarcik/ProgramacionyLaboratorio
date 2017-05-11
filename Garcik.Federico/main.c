#include <stdio.h>
#include <stdlib.h>
#include "estacionamiento.h"

#define A 20
#define B 20
#define C 20

int main()
{
    char seguir = 's';
    int opcion;
    Epropietarios propietarios[A];
    Eautomovil automoviles[B];
    Eautomovil autoAux[C];
    EsumAutos sumAutos [1];
    int flagCargaPropietarios = 0;
    int flagCargaAutos = 0;
    int flagHardCoded = 0;


    do
    {
        printf("1-Alta de propietario \n");
        printf("2-Modificacion de propietario \n");
        printf("3-Ingreso automovil \n");
        printf("4-Egreso automovil \n");
        printf("5-Informar \n");
        printf("6- Salir\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            /*Ingreso por teclado:
            cargarDatos(propietarios, A, flagCargaPropietarios);
            */
            //Datos hardcodeados:
            cargarPropietarios(propietarios);
            flagCargaPropietarios = 1;
            break;
        case 2:
            modificarPropietario(propietarios, A, flagCargaPropietarios);
            break;
        case 3:
            /*Ingreso por teclado:
            //ingresoAutomovil(automoviles, flagCargaPropietarios, propietarios, A, flagCargaAutos);
            */
            //Datos hardcodeados
            cargarAutomoviles(automoviles);
            flagCargaAutos = 1;
            break;
        case 4:
            calcularEstadia(automoviles, propietarios, A, flagCargaPropietarios, flagCargaAutos, sumAutos);
            break;
        case 5:
            mostrar(automoviles, B, propietarios, A, autoAux, flagCargaPropietarios, flagCargaPropietarios, sumAutos, flagHardCoded);
            flagHardCoded = 1;
            break;
        case 6:
            seguir = 'n';
            break;
        default:
            printf("ERROR: esa opcion no es valida\n");
            break;
        }
    }
    while(seguir=='s');
        return 0;
}
