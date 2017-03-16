#include <stdio.h>
#include <stdlib.h>

int main()
{
    int NumeroUno;
    int NumeroDos;

    printf("Ingrese un numero:");
    scanf("%d", &NumeroUno);

    printf("Ingrese otro numero:");
    scanf("%d", &NumeroDos);

    int Resultado = NumeroUno + NumeroDos;

    if(Resultado > 0)
    {
        printf("El resultado es positivo y es %d", Resultado);
    }
    else
    {
        if(Resultado < 0)
        {
            printf("El resultado es negativo y es %d", Resultado);
        }
        else
        {
            printf("El resultado es 0");
        }

    }






    return 0;
}
