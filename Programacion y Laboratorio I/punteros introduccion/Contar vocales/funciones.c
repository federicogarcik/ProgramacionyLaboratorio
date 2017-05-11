#include "funcinoes.h"
int contarVocales(char* input)
{
    int i;
    int contVocales = 0;
    for(i = 0; *(input + i) != '\0'; i++)
    {
        if(*(input + i) == 'A' || *(input + i) == 'E' || *(input + i) == 'I' || *(input + i) == 'O' || *(input + i) == 'U' || *(input + i) == 'a' || *(input + i) == 'e' || *(input + i) == 'i' || *(input + i) == 'o' || *(input + i) == 'u')
        {
            contVocales++;
        }
    }
    return contVocales;
}
