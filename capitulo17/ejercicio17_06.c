#include <stdio.h>
#include <string.h>

int padLeft(char *str, int len, char chr)
{
    int longitud = strlen(str);
    int final = (len - longitud);
    int i, contador = 0;
    char aux[longitud];

    if (longitud < len)
    {
        // guardamos el original
        if (longitud > 0)
        {
            strcpy(aux, str);
        }

        // insertamos el caracter
        for (i = 0; i < final; i++)
        {
            *(str + i) = chr;
            contador++;
        }
        *(str + i) = '\0';

        // pegamos el original encima del \0
        if (longitud > 0)
        {
            strcat(str, aux);
        }
    }
    return contador;
}

int main()
{
    char str[][20] = {"hola", "hola", "hola", ""};
    int len[] = {4, 3, 5, 3};
    int agregados;
    for (int i = 0; i < 4; i++)
    {
        agregados = padLeft(str[i], len[i], 'X');
        printf("Cadena resultante: %s\n", str[i]);
        printf("Caracteres agregados: %d\n", agregados);
    }

    return 0;
}