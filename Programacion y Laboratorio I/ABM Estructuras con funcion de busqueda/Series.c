#include "Series.h"
#include <conio.h>


void inicializarSeries(eSerie series[], int tam)
{

    int i;
     for(i=0; i<tam; i++)
    {
        series[i].estado=0;
    }
}

void mostrarNetflix(eSerie series[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(series[i].estado!=0)
        {
            mostrarSerie(series[i]);
        }
    }
}
void mostrarSerie(eSerie serie)
{
    printf("\n%d\t%s\t%d\t%s\n",serie.idSerie, serie.nombre, serie.temporadas, serie.genero);
}
void ordenarSeries(eSerie series[], int tam)
{
    int i, j;
    eSerie auxSerie;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(series[i].nombre,series[j].nombre)>0)
            {
                auxSerie = series[i];
                series[i] = series[j];
                series[j] = auxSerie;
            }
        }
    }
}

eSerie crearSerie(int id, char nombre[], int tem, char genero[])
{
    eSerie miSerie;

    miSerie.idSerie = id;
    strcpy(miSerie.nombre,nombre);
    strcpy(miSerie.genero,genero);
    miSerie.temporadas = tem;

    miSerie.estado = 1;


    return miSerie;
}

int buscarLibre(eSerie series[], int tam)
{
    int lugar = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(series[i].estado==0)
        {
            lugar = i;
            break;
        }
    }



    return lugar;
}

