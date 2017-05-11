#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcinoes.h"

int main()
{
    int auxiliar;
    char inputChar[30];
    char* puntChar;
    puntChar = inputChar;

    fflush(stdin);
    gets(puntChar);

    auxiliar = contarVocales(puntChar);
    printf("%d", auxiliar);




    return 0;
}
