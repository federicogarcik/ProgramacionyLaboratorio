#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Series.h"
#define S 3



int main()
{
    eSerie netflix[S];
    inicializarSeries(netflix, S);
    int i, flagCapacidad, auxInt;
    char seguir='s', opcion, respuesta;


    int id, temp, posicion;
    char nombre[50], genero[50];

    do
    {
        printf("1. ALTAS\n2. BAJAS\n3.MODIFICACIONES\n4.LISTAR\n5. Listar mas de 2 temp\n6. listar terror \n9.SALIR");
        printf("Elija una opcion: ");
        opcion = getche();

        switch(opcion)
        {
        case '1':
            flagCapacidad=0;

            posicion = buscarLibre(netflix, S);

            if(posicion!=-1)
            {
                printf("\nIngrese Id: ");
                    scanf("%d", &id);
                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(nombre);
                    printf("Ingrese cant temporadas: ");
                    scanf("%d", &temp);
                    printf("Ingrese genero: ");
                    fflush(stdin);
                    gets(genero);

                    netflix[posicion] = crearSerie(id, nombre,temp,genero);

                    mostrarSerie( netflix[posicion]);
            }
            else
            {
                printf("No hay espacio disponible!");
            }







            break;
        case '2':

              flagCapacidad=0;
            printf("Ingrese el id de la serie que desea eliminar: ");
            scanf("%d", &auxInt);

            for(i=0; i<S; i++)
            {
                if(netflix[i].estado==1 &&auxInt == netflix[i].idSerie)//encontro la serie
                {

                    mostrarSerie(netflix[i]);

                    printf("Esta seguro de eliminar? ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        netflix[i].estado=0;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario");
                    }
                   flagCapacidad=1;
                break;
                }
            }
            if(flagCapacidad==0)
            {
                printf("La serie es inexistente!");
            }



            break;

        case '3':
        flagCapacidad=0;
            printf("Ingrese el id de la serie que desea modificar: ");
            scanf("%d", &auxInt);

            for(i=0; i<S; i++)
            {
                if(netflix[i].estado==1 && auxInt == netflix[i].idSerie)//encontro la serie
                {

                    mostrarSerie(netflix[i]);
                    printf("Ingrese la nueva cantidad de temporadas: ");
                    scanf("%d", &auxInt);
                    printf("Esta seguro de modificar? ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        netflix[i].temporadas = auxInt;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario");
                    }
                   flagCapacidad=1;
                break;
                }
            }
            if(flagCapacidad==0)
            {
                printf("La serie es inexistente!");
            }



            break;
        case '4':

        ordenarSeries(netflix,S);
            mostrarNetflix(netflix, S);

            break;
        case '5':
            for(i=0; i<S; i++)
            {
                if(netflix[i].estado==1 && netflix[i].temporadas>2)
                {
                    mostrarSerie(netflix[i]);
                }
            }

            break;
        case '6':
               for(i=0; i<S; i++)
            {
                if(netflix[i].estado==1 && stricmp(netflix[i].genero,"terror")==0)
                {
                    mostrarSerie(netflix[i]);
                }
            }
            break;


        }


    }
    while(seguir=='s');


    return 0;
}

