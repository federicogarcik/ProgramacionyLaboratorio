#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char buffer[2000];
    char nombre[20];
    char apellido[20];

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
    strcpy(buffer, nombre);
    strcat(buffer, " ");
    strcat(buffer, apellido);
    printf("%s", buffer);
    return 0;
}
