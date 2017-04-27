#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void cargarSeries(eSerie series[])
{
    int idSerie[5]= {100,101,102,103,104};
    int estado[5]= {1,1,1,1,1};
    char titulo[5][30]= {"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]= {9,7,7,6,1};
    char genero[5][30]= {"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
    for(i=0; i<5; i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]= {"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};
    int idSerie[10]= {100,100,101,103,103,101,102,103,100,100};
    int i;

    for(i=0; i<10; i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];
        clientes[i].idSerie = idSerie[i];
    }

}

void mostrarSeries(eSerie series[], int capacidad)
{
    int i;
    for(i = 0; i < capacidad; i++)
    {
        printf("%d\t", series[i].idSerie);
        printf("%s\t", series[i].titulo);
        printf("%d\t", series[i].temporadas);
        printf("%s\t", series[i].genero);
        printf("%d\n", series[i].estado);
    }
}

void mostrarClientes(eCliente clientes[], int capacidad)
{
    int i;
    for(i = 0; i < capacidad; i++)
    {
        printf("%d\t", clientes[i].idCliente);
        printf("%s\t", clientes[i].nombre);
        printf("%d\t", clientes[i].idSerie);
        printf("%d\n", clientes[i].estado);
    }
}

void mostrarClientesConSerie(eCliente clientes[], eSerie series[], int capacidadClientes, int capacidadSeries)
{
    int i;
    int l;
    for(l = 0; l < capacidadClientes; l++)
    {
        for (i = 0; i < capacidadSeries; i++)
        {
            if(series[i].idSerie == clientes[l].idSerie)
            {
                printf("%d\t", clientes[l].idCliente);
                printf("%s\t", clientes[l].nombre);
                printf("%s\t", series[i].titulo);
                printf("%d\n", clientes[i].estado);
                break;
            }
        }
    }
}

void mostrarSeriesConClientes(eCliente clientes[], eSerie series[], int capacidadClientes, int capacidadSeries)
{
    int i;
    int l;
    for (i = 0; i < capacidadSeries; i++)
    {
        for(l = 0; l < capacidadClientes; l++)
        {
            if(series[i].idSerie == clientes[l].idSerie)
            {
                printf("%d\t", series[i].idSerie);
                printf("%s\t", series[i].titulo);
                printf("%d\t", series[i].temporadas);
                printf("%s\t\t", series[i].genero);
                printf("%s\t", clientes[l].nombre);
                printf("%d\n", series[i].estado);
                break;
            }
        }
    }
}
void mostrarClientesTBBT(eCliente clientes[], int capacidadClientes)
{
    int i;
    for(i = 0; i < capacidadClientes; i++)
    {
        if(clientes[i].idSerie == 100)
        {
            printf("%d\t", clientes[i].idCliente);
            printf("%s\t", clientes[i].nombre);
            printf("%d\t", clientes[i].idSerie);
            printf("%d\n", clientes[i].estado);
        }
    }

}
void mostrarSerieLoser(eCliente clientes[], eSerie series[], int capacidadSeries, int capacidadClientes)
{
    int i;
    int l;
    int serieMin = 0;
    int contAux = 0
    int serieLoser[30];
    for(i = 0; i < capacidadSeries; i++)
    {
        if(serieMin > contAux)
        {

            serieMin = contAux;
            strcpy(serieLoser, series[i].titulo);
        }
        for(l = 0; l < capacidadClientes; l++)
        {
            if(series[i].idSerie == clientes[l].idCliente)
            {
                contAux++;
            }
        }
    }
}
