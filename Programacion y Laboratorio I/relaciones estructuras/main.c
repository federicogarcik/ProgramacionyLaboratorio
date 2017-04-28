#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define A 5
#define B 10

int main()
{
    eSerie series[A];
    eCliente clientes[B];

    cargarSeries(series);
    cargarClientes(clientes);
    printf("SERIES:\n");
    mostrarSeries(series, A);
    printf("\n*********************************************************\n\nCLIENTES:\n");
    mostrarClientes(clientes, B);
    printf("\n*********************************************************\n\nCLIENTES CON SERIES:\n");
    mostrarClientesConSerie(clientes, series, B, A);
    printf("\n*********************************************************\n\nSERIES CON CLIENTES:\n");
    mostrarSeriesConClientes(clientes, series, B, A);
    printf("\n*********************************************************\n\nCLIENTES QUE VEN TBBT:\n");
    mostrarClientesTBBT(clientes, B);
    printf("\n*********************************************************\n\nSERIE MENOS VISTA:\n");
    mostrarSerieLoser(clientes, series, A, B);


    return 0;
}
