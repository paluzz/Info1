#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define IGUALES 0
int startsWith(char *str, char *endStr)
{
    int longitud = strlen(endStr);
    int i, j = 0;
    char aux[longitud];

    for (i = 0; i < longitud; i++, j++)
    {
        *(aux + j) = *(str + i);
    }
    aux[longitud] = '\0';

    return (strcmp(aux, endStr) == IGUALES) ? TRUE : FALSE;
}

int main(void)
{
    char str[] = "hola como te va";
    char *frase[] = {"como", "adios", "va", "hola", "ho"};
    int comienzo;
    for (int i = 0; i < 5; i++)
    {
        comienzo = startsWith(str, frase[i]);
        if (comienzo == TRUE)
        {
            printf("La frase '%s' SI inicia con '%s'\n", str, frase[i]);
        }
        else
        {
            printf("La frase '%s' NO inicia con '%s'\n", str, frase[i]);
        }
    }
    return 0;
}