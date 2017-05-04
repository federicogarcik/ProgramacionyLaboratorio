#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define FALLA_3G 1
#define FALLA_LTE 2
#define FALLA_EQUIPO 3

#define EN_CURSO 0
#define SOLUCIONADO 1
#define NO_SOLUCIONADO 2;

void estadoLibreAbonados(Eabonado abonados[], int capacidad, int bandera)
{
    if(bandera ==0)
    {
        int i;
        for(i = 0; i < (capacidad+1); i++)
        {
            abonados[i].estado = 0;
        }
    }
}

int obtenerEspacioLibre(Eabonado abonados[], int capacidad)
{
    int i;
    for(i = 0; i < capacidad; i++)
    {
        if(abonados[i].estado == 0)
        {
            break;
        }
    }
    return i;
}


void cargarDatos(Eabonado abonados[], int indice,int capacidad)
{
    autoIncremento(abonados, capacidad);
    printf("Introdusca el numero\n");
    scanf("%d", &abonados[indice].numero);
    printf("Introdusca el nombre\n");
    fflush(stdin);
    gets(abonados[indice].nombre);
    printf("Introdusca el apellido\n");
    fflush(stdin);
    gets(abonados[indice].apellido);

    abonados[indice].estado = 1;
}

void autoIncremento(Eabonado abonados[], int capacidad)
{
    int i;
    int acumuladorAux = 0;
    for(i = 0; i < capacidad; i++)
    {
        acumuladorAux = acumuladorAux + 1;
        abonados[i].idAbonado = acumuladorAux;
    }
}

int ingresarID()
{
    int id;
    printf("Ingrese el id del abonado a ser modificado: ");
    scanf("%d", &id);
    return id;
}

int buscarPorId(Eabonado abonados[], int id, int capacidad)
{
    int banderaId = 0;
    int i;
    for(i = 0; i < capacidad; i++)
    {
        if(abonados[i].idAbonado == id)
        {
            banderaId = 1;
            break;
        }
        if(banderaId == 0)
        {
            printf("ERROR: id inexistente\n");
        }
    }
    return i;
}

void modNombreApe(Eabonado abonados[], int indice)
{
    printf("Introdusca el nuevo nombre\n");
    fflush(stdin);
    gets(abonados[indice].nombre);
    printf("Introdusca el nuevo apellido\n");
    fflush(stdin);
    gets(abonados[indice].apellido);
}

void darDeBaja(Eabonado abonados[], int indice)
{
    abonados[indice].estado = 0;
    printf("Se ha dado de baja a %s ID: %d\n", abonados[indice].nombre, abonados[indice].idAbonado);
}

void estadoLibreLlamadas(Ellamada llamadas[], int capacidad, int bandera)
{
    if(bandera ==0)
    {
        int i;
        for(i = 0; i < (capacidad+1); i++)
        {
            llamadas[i].estado = 0;
        }
    }
}

void initLlamada(Ellamada llamadas[], int indice, int capacidadAbonados, Eabonado abonados[])
{
    int idAux;
    int motivoAux;
    int i;
    int flagValidId = 0;
    printf("Ingrese el id del abonado que hace el reclamo");
    scanf("%d", &idAux);
    do
    {
        for(i = 0; i < capacidadAbonados; i++)
        {
            if(idAux == abonados[i].idAbonado)
            {
                llamadas[indice].idAbonado = idAux;
                flagValidId = 1;
            }
            else
            {
                printf("El id es inexistente reingrese");
                scanf("%d", &idAux);
            }
        }
    }while(flagValidId != 1);
    printf("1-FALLA 3G\n");
    printf("2-FALLA LTE\n");
    printf("3-FALLA SISTEMA\n");
    printf("ingrese el motivo (1-3)");
    scanf("%d", &motivoAux);
    while(!(motivoAux > 0 && motivoAux < 4))
    {
        printf("ERROR: esa no es una opcion valida, reingrese");
        scanf("%d", &motivoAux);
    }
    llamadas[indice].motivo = motivoAux;
}

 int obtenerEspacioLibreLlamada(Ellamada llamadas[], int capacidad)
 {
     int i;
    for(i = 0; i < capacidad; i++)
    {
        if(llamadas[i].estado == 0)
        {
            break;
        }
    }
    return i;
 }
