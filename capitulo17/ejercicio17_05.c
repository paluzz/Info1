#include <stdio.h>
#include <string.h>

int padRigth(char *str, int len, char chr)
{
    int longitud = strlen(str);
    int i, contador = 0;

    if (longitud < len)
    {
        // insertamos el caracter
        for (i = longitud; i < len; i++)
        {
            *(str + i) = chr;
            contador++;
        }

        *(str + i) = '\0';
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
        agregados = padRigth(str[i], len[i], 'X');
        printf("Cadena resultante: %s\n", str[i]);
        printf("Caracteres agregados: %d\n", agregados);
    }

    return 0;
}
