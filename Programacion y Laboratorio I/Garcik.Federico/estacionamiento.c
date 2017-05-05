#include <stdio.h>
#include <stdlib.h>
#include "estacionamiento.h"
#include <string.h>

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4


void estadoLibrePropietarios(Epropietarios propietarios[], int capacidad, int bandera)
{
    if(bandera ==0)
    {
        int i;
        for(i = 0; i < (capacidad+1); i++)
        {
            propietarios[i].estado = 0;
        }
    }
}

int obtenerEspacioLibrePropietarios(Epropietarios propietarios[], int capacidad)
{
    int i;
    for(i = 0; i < capacidad; i++)
    {
        if(propietarios[i].estado == 0)
        {
            break;
        }
    }
    return i;
}

void cargarDatos(Epropietarios propietario[], int indice)
{
    printf("Introdusca el id del propietario: \n");
    scanf("%d", &propietario[indice].idPropietarios);
    printf("Introdusca el nombre y apellido: \n");
    fflush(stdin);
    gets(propietario[indice].nombreYApellido);
    printf("Introdusca la direccion: \n");
    scanf("%d", &propietario[indice].direccion);
    printf("Introdusca el numero de la tarjeta de credito: \n");
    scanf("%d", &propietario[indice].NumeroTarjetaDeCredito);

    propietario[indice].estado = 1;
    printf("Datos cargados correctamente");
}

int buscarPorId(Epropietarios propietarios[], int capacidad, int flagCarga)
{
    int banderaId = 0;
    int i;
    int id;
    if(flagCarga == 0)
    {
        printf("ERROR: falta cargar los datos\n");
        return 0;
    }
    else
    {
        printf("ingrese el id del propietario a ser modificado:");
        scanf("%d", &id);
        for(i = 0; i < capacidad; i++)
        {
            if(propietarios[i].idPropietarios == id)
            {
                banderaId = 1;
                break;
            }
            if(banderaId == 0)
            {
                printf("ERROR: id inexistente\n");
                return -1;
            }
        }
    }
    return i;
}

void modificarPropietario(Epropietarios propietarios[], int indice, int flagCarga)
{
    if(flagCarga == 1 && indice != -1)
    {


        printf("Ingrese el nuevo numero de la tarjeta de credito");
        scanf("%d", &propietarios[indice].NumeroTarjetaDeCredito);
        printf("%d\t%s\t%d\t%d\t", propietarios[indice].idPropietarios, propietarios[indice].nombreYApellido, propietarios[indice].direccion, propietarios[indice].NumeroTarjetaDeCredito);
        printf("\nDato correctamente modificado\n");

    }

}

void estadoLibreAutomoviles(Eautomovil automoviles[], int capacidad, int bandera)
{
    if(bandera ==0)
    {
        int i;
        for(i = 0; i < (capacidad+1); i++)
        {
            automoviles[i].estado = 0;
        }
    }

}

int obtenerEspacioLibreAutomovil(Eautomovil automoviles[], int capacidad)
{
    int i;
    for(i = 0; i < capacidad; i++)
    {
        if(automoviles[i].estado == 0)
        {
            break;
        }
    }
    return i;
}

void ingresoAutomovil(Eautomovil automoviles[], int indice, int flagCarga, Epropietarios propietarios[], int capacidadPropietarios)
{
    int marcaAux;
    int flagPropietario = 0;
    int i;
    int horarioAux;
    if(flagCarga == 1)
    {
        printf("Introdusca la patente del auto\n");
        fflush(stdin);
        gets(automoviles[indice].patente);
        printf("Elija la marca de su auto: \n");
        printf("1-ALPHA ROMEO\n");
        printf("2-FERRARI\n");
        printf("3-AUDI\n");
        printf("4-OTROS\n");
        scanf("%d", &marcaAux);
        while(marcaAux > 5 || marcaAux < 1)
        {
            printf("ERROR: reingrese una opcion valida (1-4)");
            scanf("%d", &marcaAux);
        }
        automoviles[indice].marca = marcaAux;
        printf("ingrese la id del propietario:\n");
        scanf("%d", &automoviles[indice].idPropietarios);
        do
        {
            for(i=0; i < capacidadPropietarios; i++)
            {
                if(automoviles[indice].idPropietarios == propietarios[i].idPropietarios)
                {
                    flagPropietario = 1;
                    break;
                }
                printf("ERROR id inexistente reingres: \n");
                scanf("%d", &automoviles[indice].idPropietarios);
                break;
            }
        }
        while(flagPropietario != 1);
        printf("Ingrese el horario de entrada: \n");
        scanf("%d", &horarioAux);
        while(horarioAux < 1 && horarioAux > 24)
        {
            printf("horario inexistente por favor reingrese: \n");
            scanf("%d", &horarioAux);
        }
        automoviles[indice].horarioDeEntrada = horarioAux;
        automoviles[indice].estado = 1;
        printf("Datos cargados correctamente");
    }
    else
    {
        printf("ERROR: falta cargar los datos\n");
    }
}

int buscarPorPatente(Eautomovil automoviles[], int capacidad, int flagCarga)
{
    char patenteAux[30];
    int i;
    int banderaPatente = 0;

    if(flagCarga == 0)
    {
        printf("ERROR: falta cargar los datos\n");
        return 0;
    }
    else
    {
        printf("Ingrese la patente del auto a buscar:");
        fflush(stdin);
        gets(patenteAux);
        for(i = 0; i < capacidad; i++)
        {
            if(strcmp(automoviles[i].patente, patenteAux) == 0)
            {
                banderaPatente = 1;
                break;
            }
            if(banderaPatente == 0)
            {
                printf("ERROR: patente inexistente\n");
                return 0;
            }
        }
    }
    return i;
}

void calcularEstadia(Eautomovil automoviles[], int indice, Epropietarios propietarios[], int capacidadPropietarios, int flagCarga)
{
    if(flagCarga == 1)
    {
    int tiempoEstadia;
    int valorEstadia;
    int i;
    printf("Ingrese el horario de salida: \n");
    scanf("%d", &automoviles[indice].horarioDeSalida);
    if(automoviles[indice].horarioDeSalida < automoviles[indice].horarioDeEntrada)
    {
        tiempoEstadia = (automoviles[indice].horarioDeSalida + 24) - automoviles[indice].horarioDeEntrada;
    }
    else
    {
        tiempoEstadia = automoviles[indice].horarioDeSalida - automoviles[indice].horarioDeEntrada;
    }
    if(automoviles[indice].marca == ALPHA_ROMEO)
    {
        valorEstadia = tiempoEstadia * 150;
    }
    else
    {
        if(automoviles[indice].marca == FERRARI)
        {
            valorEstadia = tiempoEstadia * 175;
        }
        else
        {
            if(automoviles[indice].marca == AUDI)
            {
                valorEstadia = tiempoEstadia * 200;
            }
            else
            {
                valorEstadia = tiempoEstadia * 250;
            }
        }
    }
    for(i = 0; i < capacidadPropietarios; i++)
    {
        if(automoviles[indice].idPropietarios == propietarios[i].idPropietarios)
        {
            break;
        }
    }
    printf("Nombre: %s\t", propietarios[i].nombreYApellido);
    printf("Patente: %s\t", automoviles[indice].patente);
    if(automoviles[indice].marca == ALPHA_ROMEO)
    {
        printf("Marca: ALPHA ROMEO\t");
    }
    else
    {
        if(automoviles[indice].marca == FERRARI)
        {
            printf("Marca: FERRARI\t");
        }
        else
        {
            if(automoviles[indice].marca == AUDI)
            {
                printf("Marca: AUDI\t");
            }
            else
            {
                printf("Marca: OTROS\t");
            }
        }
    }
    printf("Valor estadia: %d\t\n", valorEstadia);
    }
}


