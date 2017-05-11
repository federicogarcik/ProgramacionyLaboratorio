#include <stdio.h>
#include <stdlib.h>
#include "estacionamiento.h"
#include <string.h>


#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4


void ingresarDatoCadenaCaracteres(char input[])
{
    fflush(stdin);
    gets(input);
}

int validarLetras(char input[])
{
    int i = 0;
    while(input[i] != '\0')
    {
        if((input[i] != ' ') && (input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int validarNumero(char numero[])
{
    int numAux;
    int flagNum = 0;
    numAux = atoi(numero);
    while(flagNum == 0)
    {
        if(numAux == 0)
        {
            printf("ERROR: ese no es un numero reingrese: \n");
            ingresarDatoCadenaCaracteres(numero);
            numAux = atoi(numero);
        }
        else
        {
            flagNum = 1;
        }
    }
    return numAux;
}


void estadoLibrePropietarios(Epropietarios propietarios[], int capacidad, int bandera)
{
    if(bandera ==0)
    {
        int i;
        for(i = 0; i < (capacidad+1); i++)
        {
            propietarios[i].estado = 0;
        }
    }
}

int obtenerEspacioLibrePropietarios(Epropietarios propietarios[], int capacidad)
{
    int i;
    for(i = 0; i < capacidad; i++)
    {
        if(propietarios[i].estado == 0)
        {
            break;
        }
    }
    return i;
}

void cargarDatos(Epropietarios propietario[], int capacidad, int flagCargaPropietarios)
{
    int indice;
    char inputId[30];
    char inputNombreApe[30];
    char inputDireccion[30];
    char inputTarjeta[30];
    int stringAux;
    int flagStr = 0;
    estadoLibrePropietarios(propietario, capacidad, flagCargaPropietarios);
    indice = obtenerEspacioLibrePropietarios(propietario, capacidad);
    printf("Introdusca el id del propietario: \n");
    ingresarDatoCadenaCaracteres(inputId);
    propietario[indice].idPropietarios = validarNumero(inputId);
    printf("Introdusca el nombre y apellido: \n");
    fflush(stdin);
    gets(inputNombreApe);
    stringAux = validarLetras(inputNombreApe);
    while(flagStr == 0)
    {
        if(stringAux == 0)
        {
            printf("ERROR: esas no son letras reingrese: \n");
            fflush(stdin);
            gets(inputNombreApe);
            stringAux = validarLetras(inputNombreApe);
        }
        else
        {
            strcpy(propietario[indice].nombreYApellido, inputNombreApe);
            flagStr = 1;
        }
    }
    printf("Introdusca la direccion: \n");
    ingresarDatoCadenaCaracteres(inputDireccion);
    propietario[indice].direccion = validarNumero(inputDireccion);
    printf("Introdusca el numero de la tarjeta de credito: \n");
    ingresarDatoCadenaCaracteres(inputTarjeta);
    propietario[indice].NumeroTarjetaDeCredito = validarNumero(inputTarjeta);

    propietario[indice].estado = 1;
    printf("Datos cargados correctamente \n");
}

int buscarPorId(Epropietarios propietarios[], int capacidad, int flagCarga)
{
    int i;
    int id;
    char inputId[30];
    int flagErrorId = 0;
    if(flagCarga == 0)
    {
        printf("ERROR: falta cargar los datos\n");
        return 0;
    }
    else
    {
        printf("ingrese el id del propietario a ser modificado:");
        ingresarDatoCadenaCaracteres(inputId);
        id = validarNumero(inputId);
        while(flagErrorId == 0)
        {
            for(i = 0; i < capacidad; i++)
            {
                if(propietarios[i].idPropietarios == id)
                {
                    flagErrorId = 1;
                    break;
                }

            }
            if(flagErrorId == 0)
            {
                printf("ERROR: id inexistente reingrese: \n");
                ingresarDatoCadenaCaracteres(inputId);
                id = validarNumero(inputId);
            }
        }
        return i;
    }
}

void modificarPropietario(Epropietarios propietario[], int capacidad, int flagCarga)
{
    char inputTarjeta[30];
    int indice;
    indice = buscarPorId(propietario, capacidad, flagCarga);
    if(flagCarga == 1)
    {
        printf("Ingrese el nuevo numero de la tarjeta de credito");
        ingresarDatoCadenaCaracteres(inputTarjeta);
        propietario[indice].NumeroTarjetaDeCredito = validarNumero(inputTarjeta);
        printf("%d\t%s\t%d\t%d\t", propietario[indice].idPropietarios, propietario[indice].nombreYApellido, propietario[indice].direccion, propietario[indice].NumeroTarjetaDeCredito);
        printf("\nDato correctamente modificado\n");
    }

}

void estadoLibreAutomoviles(Eautomovil automoviles[], int capacidad, int bandera)
{
    if(bandera ==0)
    {
        int i;
        for(i = 0; i < (capacidad+1); i++)
        {
            automoviles[i].estado = 0;
        }
    }

}

int obtenerEspacioLibreAutomovil(Eautomovil automoviles[], int capacidad)
{
    int i;
    for(i = 0; i < capacidad; i++)
    {
        if(automoviles[i].estado == 0)
        {
            break;
        }
    }
    return i;
}

void ingresoAutomovil(Eautomovil automoviles[], int flagCarga, Epropietarios propietarios[], int capacidadPropietarios, int flagaCargaAutos)
{
    int marcaAux;
    int flagPropietario = 0;
    int i;
    int horarioAux;
    int indice;
    char inputId[30];
    char inputHorario[30];
    char patenteAux[30];
    estadoLibreAutomoviles(automoviles, capacidadPropietarios, flagaCargaAutos);
    indice = obtenerEspacioLibreAutomovil(automoviles, capacidadPropietarios);
    if(flagCarga == 1)
    {
        printf("Introdusca la patente del auto\n");
        fflush(stdin);
        gets(patenteAux);
        deMinusAMayus(patenteAux);
        strcpy(automoviles[indice].patente, patenteAux);
        printf("Elija la marca de su auto: \n");
        printf("1-ALPHA ROMEO\n");
        printf("2-FERRARI\n");
        printf("3-AUDI\n");
        printf("4-OTROS\n");
        scanf("%d", &marcaAux);
        while(marcaAux > 5 || marcaAux < 1)
        {
            printf("ERROR: reingrese una opcion valida (1-4)");
            scanf("%d", &marcaAux);
        }
        automoviles[indice].marca = marcaAux;
        printf("ingrese la id del propietario:\n");
        ingresarDatoCadenaCaracteres(inputId);
        automoviles[indice].idPropietarios = validarNumero(inputId);
        do
        {
            for(i=0; i < capacidadPropietarios; i++)
            {
                if(automoviles[indice].idPropietarios == propietarios[i].idPropietarios)
                {
                    flagPropietario = 1;
                    break;
                }
            }
            if(i == capacidadPropietarios)

            {

            printf("ERROR id inexistente reingres: \n");
            ingresarDatoCadenaCaracteres(inputId);
            automoviles[indice].idPropietarios = validarNumero(inputId);
            }
        }
        while(flagPropietario != 1);
        printf("Ingrese el horario de entrada: \n");
        ingresarDatoCadenaCaracteres(inputHorario);
        horarioAux = validarNumero(inputHorario);
        while(horarioAux < 1 || horarioAux > 24)
        {
            printf("horario inexistente por favor reingrese: \n");
            ingresarDatoCadenaCaracteres(inputHorario);
            horarioAux = validarNumero(inputHorario);
        }
        automoviles[indice].horarioDeEntrada = horarioAux;
        automoviles[indice].estado = 1;
        printf("Datos cargados correctamente\n");
    }
    else
    {
        printf("ERROR: falta cargar los datos\n");
    }
}

int buscarPorPatente(Eautomovil automoviles[], int capacidad, int flagCarga)
{
    char patenteAux[30];
    int i;
    int banderaPatente = 0;

    if(flagCarga == 0)
    {
        printf("ERROR: falta cargar los datos\n");
        return 0;
    }
    else
    {
        printf("Ingrese la patente del auto a buscar:");
        fflush(stdin);
        gets(patenteAux);
        deMinusAMayus(patenteAux);
        while(banderaPatente == 0)
        {
            for(i = 0; i < capacidad; i++)
            {
                if(strcmp(automoviles[i].patente, patenteAux) == 0)
                {
                    banderaPatente = 1;
                    break;
                }
                if(i ==  capacidad)
                {
                    printf("ERROR: patente inexistente reingrese: \n");
                    fflush(stdin);
                    gets(patenteAux);
                    continue;
                }
            }
        }
    }
    return i;
}

void calcularEstadia(Eautomovil automoviles[], Epropietarios propietarios[], int capacidadPropietarios, int flagCarga, int flagCargaAutos)
{
    int indice;
    indice = buscarPorPatente(automoviles, capacidadPropietarios, flagCarga);
    if(flagCarga == 1 && flagCargaAutos == 1)
    {
        int tiempoEstadia;
        int valorEstadia;
        int horarioAux;
        int i;
        char inputHorario[30];
        printf("Ingrese el horario de salida: \n");
        ingresarDatoCadenaCaracteres(inputHorario);
        horarioAux = validarNumero(inputHorario);
        while(horarioAux < 1 || horarioAux > 24)
        {
            printf("horario inexistente por favor reingrese: \n");
            ingresarDatoCadenaCaracteres(inputHorario);
            horarioAux = validarNumero(inputHorario);
        }
        automoviles[indice].horarioDeSalida = validarNumero(inputHorario);
        if(automoviles[indice].horarioDeSalida < automoviles[indice].horarioDeEntrada)
        {
            tiempoEstadia = (automoviles[indice].horarioDeSalida + 24) - automoviles[indice].horarioDeEntrada;
        }
        else
        {
            tiempoEstadia = automoviles[indice].horarioDeSalida - automoviles[indice].horarioDeEntrada;
        }
        if(automoviles[indice].marca == ALPHA_ROMEO)
        {
            valorEstadia = (tiempoEstadia * 150);
        }
        else
        {
            if(automoviles[indice].marca == FERRARI)
            {
                valorEstadia = (tiempoEstadia * 175);
            }
            else
            {
                if(automoviles[indice].marca == AUDI)
                {
                    valorEstadia = tiempoEstadia * 200;
                }
                else
                {
                    valorEstadia = tiempoEstadia * 250;
                }
            }
        }
        for(i = 0; i < capacidadPropietarios; i++)
        {
            if(automoviles[indice].idPropietarios == propietarios[i].idPropietarios)
            {
                break;
            }
        }
        printf("Nombre: %s\t", propietarios[i].nombreYApellido);
        printf("Patente: %s\t", automoviles[indice].patente);
        if(automoviles[indice].marca == ALPHA_ROMEO)
        {
            printf("Marca: ALPHA ROMEO\t");
        }
        else
        {
            if(automoviles[indice].marca == FERRARI)
            {
                printf("Marca: FERRARI\t");
            }
            else
            {
                if(automoviles[indice].marca == AUDI)
                {
                    printf("Marca: AUDI\t");
                }
                else
                {
                    printf("Marca: OTROS\t");
                }
            }
        }
        printf("Valor estadia: %d\t\n", valorEstadia);
    }
}

void deMinusAMayus(char cadena[])
{
    int i ;
    for(i = 0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] >= '0' && cadena[i] <= '9')
        {
            continue;
        }
        else
        {
            if(cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
}

void ordenarHoraPatente(Eautomovil automovil[], int capacidad, Eautomovil autoAux[])
{
    int i;
    int j;
    for(i = 0; i < capacidad; i++)
    {
        for(j = i + 1; j > capacidad; i++)
        {
            if(automovil[i].horarioDeEntrada > automovil[j].horarioDeEntrada)
            autoAux[0] = automovil[i];
            automovil[i] = automovil[j];
            automovil[j] = autoAux[0];
        }
    }
}

void mostrarAutosConPropietarios(Eautomovil automovil[], Epropietarios propietario[], int capacidadPropietarios, int capacidadAutos, Eautomovil autoAux[], int flagCarga, int flagCargaAutos)
{
    int i;
    int j;
    if(flagCarga == 1 && flagCargaAutos == 1)
    {
        ordenarHoraPatente(automovil, capacidadAutos, autoAux);
        for(i = 0; i < capacidadAutos; i++)
        {
            if(automovil[i].estado == 1)
            {


                if(automovil[i].marca == ALPHA_ROMEO)
                {
                    printf("Marca: ALPHA ROMEO\t");
                }
                else
                {
                    if(automovil[i].marca == FERRARI)
                    {
                        printf("Marca: FERRARI\t");
                    }
                    else
                    {
                        if(automovil[i].marca == AUDI)
                        {
                            printf("Marca: AUDI\t");
                        }
                        else
                        {
                            printf("Marca: OTROS\t");
                        }
                    }
                }
                for(j = 0; j < capacidadPropietarios; j++)
                {
                    if(automovil[i].idPropietarios == propietario[j].idPropietarios)
                    {
                        break;
                    }
                }
                printf("Nombre: %s\t", propietario[j].nombreYApellido);
                printf("Horario de entrada %d\t", automovil[i].horarioDeEntrada);
                printf("Patente: %s\n", automovil[i].patente);
            }
        }
    }
    else
    {
        printf("ERROR: falta cargar los datos\n");
    }
}

void mostrarPropietariosConAutosAudi(Eautomovil automovil[], int capacidadAutos, Epropietarios propietario[], int capacidadPropietarios)
{
    int i;
    int j;
    for(i = 0; i < capacidadAutos; i++)
        if(automovil[i].marca == 3)
        {
            for(j = 0; j < capacidadPropietarios; j++)
            {
                if(propietario[j].idPropietarios == automovil[i].idPropietarios)
                {
                    printf("ID:\n %d\t Nombre y apellido\n %s\t  direccion\n %d\t  Numero de tarjeta de credito\n %d\n", propietario[i].idPropietarios, propietario[i].nombreYApellido, propietario[i].direccion, propietario[i].NumeroTarjetaDeCredito);
                }
            }
        }
}

int mostrarRecaudacionTotalPorMarca(Eautomovil automovil[], int capacidad)
{
    int sumAlpha = 0;
    int sumFerrari = 0;
    int sumAudi = 0;
    int sumOtros = 0;
    int tiempoEstadia;
    int valorEstadia;
    int i;
    for(i = 0; i < capacidad; i++)
    {
        if(automovil[i].estado == 1)
        {
            if(automovil[i].horarioDeSalida < automovil[i].horarioDeEntrada)
            {
                tiempoEstadia = (automovil[i].horarioDeSalida + 24) - automovil[i].horarioDeEntrada;
            }
            else
            {
                tiempoEstadia = automovil[i].horarioDeSalida - automovil[i].horarioDeEntrada;
            }
            if(automovil[i].marca == ALPHA_ROMEO)
            {
                valorEstadia = (tiempoEstadia * 150);
                sumAlpha = sumAlpha + valorEstadia;
            }
            else
            {
                if(automovil[i].marca == FERRARI)
                {
                    valorEstadia = (tiempoEstadia * 175);
                    sumFerrari =  sumFerrari + valorEstadia;
                }
                else
                {
                    if(automovil[i].marca == AUDI)
                    {
                        valorEstadia = (tiempoEstadia * 200);
                        sumAudi =  sumAudi + valorEstadia;
                    }
                    else
                    {
                        valorEstadia = (tiempoEstadia * 150);
                        sumOtros =  sumOtros + valorEstadia;
                    }
                }
            }
        }
    }
    printf("La recaudacion de la marca Alpha romeo a sido de: %d\n", sumAlpha);
    printf("La recaudacion de la marca Ferrari a sido de: %d\n", sumFerrari);
    printf("La recaudacion de la marca Audi a sido de: %d\n", sumAudi);
    printf("La recaudacion de las otras marcas a sido de: %d\n", sumOtros);
    int sumaTotal = 0;
    sumaTotal = sumAlpha + sumAudi + sumFerrari + sumOtros;
    return sumaTotal;
}

void mostrar(Eautomovil automovil[], int capacidadAutos, Epropietarios propietario[], int capacidadPropietarios, Eautomovil autoAux[], int flagCarga, int flagCargaAutos)
{
    int sumaTotal;
    printf("*********************AUTOS CON PROPIETARIOS ORDENADO POR HORARIO DE ENTRADA*****************************\n");
    mostrarAutosConPropietarios(automovil, propietario, capacidadPropietarios, capacidadAutos, autoAux, flagCarga, flagCargaAutos);
    printf("***********************PROPIETARIOS CON AUTO AUDI*************************\n");
    mostrarPropietariosConAutosAudi(automovil, capacidadAutos, propietario, capacidadPropietarios);
    printf("************************RECAUDACION TOTAL POR MARCA*************************\n");
    sumaTotal = mostrarRecaudacionTotalPorMarca(automovil, capacidadAutos);
    printf("************************RECAUDACION TOTAL POR ESTACIONAMIENTO**************\n");
    printf("La recaudacion total del estacionamiento es de: %d \n", sumaTotal);
}
