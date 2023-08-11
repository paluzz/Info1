#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define IGUALES 0
int endsWith(char *str, char *endStr)
{
    int longStr = strlen(str);
    int longEnd = strlen(endStr);
    int i, j = 0;
    char aux[longEnd];

    for (i = (longStr - longEnd); i <= longStr; i++, j++)
    {
        *(aux + j) = *(str + i);
    }

    return (strcmp(aux, endStr) == IGUALES) ? TRUE : FALSE;
}

int main(void)
{
    char str[] = "hola como te va";
    char *frase[] = {"como", "adios", "te", "te va", "va"};
    int termina;
    for (int i = 0; i < 5; i++)
    {
        termina = endsWith(str, frase[i]);
        if (termina == TRUE)
        {
            printf("La frase '%s' SI termina con '%s'\n", str, frase[i]);
        }
        else
        {
            printf("La frase '%s' NO termina con '%s'\n", str, frase[i]);
        }
    }
    return 0;
}