#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char buffer[2000];
    char nombre[20];
    char apellido[20];
    char apeNombre[20];

    printf("ingrese su nombre: ");
    gets(buffer);
    fflush(stdin);
    while (strlen(buffer) > 19)
    {
        printf("el nombre es muy largo, por favor reingrese nombre: ");
        gets(buffer);
    }
    fflush(stdin);
    strcpy(nombre, buffer);
    printf("ingrese su apellido:");
    gets(buffer);
     while (strlen(buffer) > 19)
    {
        printf("el apellido es muy largo, por favor reingrese nombre: ");
        gets(buffer);
    }
    strcpy(apellido, buffer);
    buffer[0] = buffer[0] - 32;
    strcpy(apeNombre, buffer);
    strcat(apeNombre, " ");
    strcpy(buffer, nombre);
    buffer [0] = buffer[0] - 32;
    strcat(apeNombre, buffer);
    printf("%s", apeNombre);
    return 0;
}
