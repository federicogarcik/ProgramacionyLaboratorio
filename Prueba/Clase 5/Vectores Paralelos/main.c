#include <stdio.h>
#include <stdlib.h>

#define A 3



int main()
{
    int legajos[A], edades[A];
    int i, flagCarga = 0;
    int flag = 0;
    int flagEncontro = 0;
    int flagModifica = 0;
    int leg;
    float maxProm;
    float promedios[A];
    float prom;
    char respuesta, seguir='s';
    int opcion;


    do
    {
        printf("1. Ingreso de datos\n");

        printf("2. Maximo alumno\n");

        printf("3. Busqueda por legajo\n");

        printf("4. Modificacion del promedio\n");

        printf("5. Baja de alumno\n");

        printf("6. Listar\n");

        printf("7. Salir\n");

        printf("Ingrese una opcion: ");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            for(i=0; i<A; i++)
            {
                printf("Ingrese legajo: ");
                scanf("%d", &legajos[i]);

                printf("Ingrese edad: ");
                scanf("%d", &edades[i]);

                printf("Ingrese promedio: ");
                scanf("%f", &promedios[i]);

            }
            flagCarga =1;
            break;
        case 2:
            if(flagCarga==1)
            {
                for(i=0; i<A; i++)
                {
                    if(legajos[i]!=-1)
                    {
                        if(flag==0 || promedios[i]>maxProm)
                        {
                            maxProm = promedios[i];
                            flag = 1;
                        }
                    }

                }



                for(i=0; i<A; i++)
                {
                    if(promedios[i] == maxProm)
                    {
                        printf("%d\t%d\t%f\n", legajos[i], edades[i], promedios[i]);
                    }


                }
            }
            else
            {
                printf("Debe por lo menos existir un alumno para esta operacion!");
            }

            break;
        case 3:
            printf("Ingrese legajo a buscar: ");
            scanf("%d", &leg);

            for(i=0; i<A; i++)
            {
                if(legajos[i] == leg)
                {
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], promedios[i]);
                    flagEncontro = 1;
                    break;
                }

            }
            if(flagEncontro == 0)
            {
                printf("Legajo inexistente!!!");
            }
            break;
        case 4:
            printf("Ingrese legajo a modificar: ");
            scanf("%d", &leg);

            for(i=0; i<A; i++)
            {
                if(legajos[i] == leg)
                {
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], promedios[i]);

                    printf("Ingrese nuevo promedio: ");
                    scanf("%f", &prom);
                    printf("Esta seguro de modificar el promedio? s/n: ");
                    respuesta =getche();
                    if(respuesta == 's')
                    {
                        promedios[i] = prom;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario");
                    }
                    flagModifica = 1;
                    break;
                }

            }
            if(flagModifica == 0)
            {
                printf("Legajo inexistente!!!");
            }
            break;
        case 5:
            flagModifica =0;

            printf("Ingrese legajo a eliminar: ");
            scanf("%d", &leg);

            for(i=0; i<A; i++)
            {
                if(legajos[i] == leg)
                {
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], promedios[i]);


                    printf("Esta seguro de eliminar al alumno? s/n: ");
                    respuesta =getche();
                    if(respuesta == 's')
                    {
                        legajos[i] = -1;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario");
                    }
                    flagModifica = 1;
                    break;
                }

            }
            if(flagModifica == 0)
            {
                printf("Legajo inexistente!!!");
            }

            break;

        case 6:
            for(i=0; i<A; i++)
            {
                if(legajos[i]!=-1)
                    printf("%d\t%d\t%f\n", legajos[i], edades[i], promedios[i]);
            }
            break;
        case 7:
            seguir = 'n';
            break;

        }




    }
    while(seguir=='s');














    return 0;
}
