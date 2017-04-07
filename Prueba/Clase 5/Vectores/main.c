#include <stdio.h>
#include <stdlib.h>
#define V 5
int main()
{

    int numeros[V]={0};
    int posicion;
    int i, j;
    char seguir;
    int aux;

    /*for(i=0; i<10; i++)
    {
        numeros[i] = 0;
    }*/
/*
    do
    {
        printf("Ingrese posicion: ");
        scanf("%d", &posicion);

        printf("Ingrese un numero: ");
        scanf("%d", &numeros[posicion-1]);

        printf("Desea continuar? s/n: ");
        seguir = getche();

    }while(seguir=='s');
*/

    for(i=0; i<V; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }




    for(i=0; i<V-1; i++)
    {
        for(j=i+1; j<V; j++)
        {
            if(numeros[i]>numeros[j])
            {
                aux = numeros[i];
                numeros[i] =  numeros[j];
                 numeros[j] = aux;
            }
        }
    }


    for(i=0; i<V; i++)
    {
        if(numeros[i]!=0)
            printf("%d\n", numeros[i]);
    }
    return 0;
}
