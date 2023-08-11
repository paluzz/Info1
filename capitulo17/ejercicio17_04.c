#include <stdio.h>
#include <string.h>
int trim(char *str, char chr, char *strRes)
{
    int i, j = 0, cantidad = 0;
    int longitud = strlen(str);

    for (i = 0; i < longitud; i++, j++)
    {
        // copiamos el string
        if (*(str + i) != chr)
        {
            *(strRes + j) = *(str + i);
        }
        else
        {
            j--;
            cantidad++;
        }
    }
    j = (longitud - cantidad);
    strRes[j] = '\0';

    // si existe chr en str -> cantidad, else -1
    return (strchr(str, chr) != NULL) ? cantidad : -1;
}

int main(void)
{
    char str[] = "hola como te va";
    char *chr[] = {"", " ", "a", "o", "j"};
    char strRes[strlen(str)];
    int retornado;

    for (int i = 0; i < 5; i++)
    {
        retornado = trim(str, *chr[i], strRes);
        if (retornado >= 0)
        {
            printf("El string modificado es '%s', return:%d\n", strRes, retornado);
        }
        else
        {
            printf("No se pudo modificar el str, return:%d\n", retornado);
        }
    }

    return 0;
}