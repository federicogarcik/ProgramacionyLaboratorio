#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A 4
int main()
{
    char* pLetras;
    int i;
    char eliminar;
    int posicion;
    char* auxiliar;

    pLetras = (char*) malloc(sizeof(char) * A);
    auxiliar = (char*) malloc(sizeof(char) * A);

    if(pLetras != NULL)
    {
        printf("ingrese 4 letras");
        fflush(stdin);
        gets(pLetras);

        printf("ingrese la letra a eliminar");
        scanf("%c", &eliminar);

       for(i = 0; i < A; i++)
        {
            if(*(pLetras + i) == eliminar)
            {
               posicion = i;
               break;
            }
        }


        for(i = posicion; i < (A - 1) ; i++)
        {
            *auxiliar  = *(pLetras + i);
            *(pLetras + i) = *(pLetras + (i + 1));
            *(pLetras + (i + 1)) = *auxiliar;
        }

        for(i = 0; i < A; i++)
        {
            printf("-%c-\t", *(pLetras + i));
        }

        auxiliar = realloc(pLetras, sizeof(char) * (A - 1));
        if(auxiliar != NULL)
        {
            pLetras = auxiliar;
        }
        printf("\n");
        for(i = 0; i < (A - 1); i++)
        {
            printf("-%c-\t", *(pLetras + i));
        }
    }
    return 0;
}
