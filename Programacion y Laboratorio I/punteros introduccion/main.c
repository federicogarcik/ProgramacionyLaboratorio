#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[5];
    int* p;
    p = x;
    int i;

    for(i = 0; i < 5; i++)
    {
        *(p + i) = 0;
         printf("%d\n", *p);
    }


  /*  p = x;
    *(p + 1) = 3;
    *(p + 2) = 7;
    *p = 1;
  */








//ARITMETICA DE PUNTEROS
    /*int a = 7;
    int* punt;
    punt = &a;//= a punt++;
    punt = punt + 1;

    printf("%p\n", punt);
    printf("%p\n", punt + 1);
    printf("%p", punt - 2);
    */
    return 0;
}
