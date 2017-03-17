#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int main()
{
  char Respuesta;
  int Numero;
  int ContadorPar = 0;
  int ContadorImpar = 0;
  int ContadorNumeros = 0;
  int SumaImpar = 0;
  int SumaTotal = 0;
  float Promedio;
  int NumeroMaximo;
  int NumeroMinimo;
  int ContadorMayorTreinta = 0;
  int ContadorMediano = 0;
  int ContadorMenor = 0;
  int SumaAntecedentes = 0;

  do
  {
      printf("Introdusca un numero:");
      scanf("%d", &Numero);
      while(Numero < 0)
      {
          printf("\nIntrodusca un numero positivo:");
          scanf("%d", &Numero);
      }
      if(Numero % 2 == 0)
      {
          ContadorPar++;
      }
      else
      {
          ContadorImpar++;
          SumaImpar += Numero;
      }
      if(ContadorNumeros == 0)
      {
          NumeroMaximo = Numero;
          NumeroMinimo = Numero;
      }
      else
      {
          if(Numero > NumeroMaximo)
          {
              NumeroMaximo = Numero;
          }
          if(Numero < NumeroMinimo)
          {
              NumeroMinimo = Numero;
          }
      }
      if(Numero > 30)
      {
          ContadorMayorTreinta++;
      }
      else
      {
          if(Numero < 30 && Numero > 15)
          {
              ContadorMediano++;
          }
          else
          {
              if(Numero > 2)
              {
                  ContadorMenor++;
              }
          }
      }
      SumaTotal += Numero;
      ContadorNumeros++;

      printf("Para seguir introdusca s/n:");
      Respuesta = tolower(getche());
      while(!(Respuesta == 's' || Respuesta == 'n'))
      {
          printf("\nIngrese una respuesta valida s/n:");
          Respuesta = tolower(getche());
      }
      printf("\n");
  }
  while(Respuesta == 's');
/*
  for(SumaImpar;SumaImpar > 0;SumaImpar--)
  {
      SumaAntecedentes = SumaAntecedentes + SumaImpar;
      printf("El Numero Actual es: %d \n", SumaImpar);
  }
*/
  Promedio =(float)SumaTotal / ContadorNumeros;
  printf("\nLa cantidad de numeros pares es de %d", ContadorPar);
  printf("\nLa cantidad de numeros impares es de %d", ContadorImpar);
  printf("\nLa suma de todos los numeros impares es de %d", SumaImpar);
  printf("\nEl promedio de los numeros es de %f", Promedio);
  printf("\nEl numero maximo es %d", NumeroMaximo);
  printf("\nEl numero minimo es %d", NumeroMinimo);
  printf("\nLa suma es de %d", SumaAntecedentes);



    return 0;
}








