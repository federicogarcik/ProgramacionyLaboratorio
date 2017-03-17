#include <stdio.h>
#include <stdlib.h>

int main()
{
    system(cls);

    int NumeroUno;
    int NumeroDos;

    printf("Ingrese un numero");
    scanf("%d", &NumeroUno);
    printf("Ingrese otro numero");
    scanf("%d", &NumeroDos);

    while(NumeroUno == 0 || NumeroDos == 0)
    {
        printf("Ese numero no es valido");
        printf("Ingrese un numero");
        scanf("%d", &NumeroUno);
        printf("Ingrese otro numero");
        scanf("%d", &NumeroDos);
    }

    int Producto = NumeroUno * NumeroDos;
    printf("El producto es", Producto\n);

    int CuadradoUno = NumeroUno * NumeroUno;
    printf("el Cuadrado del primer numero es", CuadradoUno);
    return 0;
}
