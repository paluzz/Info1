#include <stdio.h>
#include <string.h>
#include <ctype.h>
int esLetra(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int esNum(char c)
{
    return (c >= '0' && c <= '9');
}
int analizaString(char *dataPtr, int *palabrasCant, int *caracteresCant)
{
    if (dataPtr == NULL || palabrasCant == NULL || caracteresCant == NULL)
    {
        return -1;
    }

    int palabras = 0;
    int caracteres = strlen(dataPtr);
    int i = 0, status = 0, letra = 0, simbolo = 0;

    while (*(dataPtr + i) != '\0')
    {
        if (esNum(dataPtr[i]))
        {
            status = -1;
        }
        if (esLetra(dataPtr[i]))
        {
            letra++;
        }
        if (ispunct(dataPtr[i]))
        {
            simbolo++;
        }

        if (isspace(*(dataPtr + i)) || ispunct(*(dataPtr + i)))
        {
            if (esLetra(dataPtr[i - 1]))
            {
                palabras++;
            }
        }
        i++;
    }
    if ((!ispunct(dataPtr[caracteres - 1]) && palabras != 0))
    {
        palabras++;
    }

    *palabrasCant = palabras;
    *caracteresCant = caracteres;

    if (letra == 0 || simbolo == 0)
    {
        status = -1;
    }
    return status;
}
int main(void)
{
    int num;
    int cantidades[] = {0, 0};
    int *palabra = &cantidades[0];
    int *caracter = &cantidades[1];

    num = analizaString("#$&/()=?", palabra, caracter);
    printf("caracter: %d\tpalabra: %d\treturn: %d\n", *caracter, *palabra, num);

    num = analizaString("444444 4444 44 4444", palabra, caracter);
    printf("caracter: %d\tpalabra: %d\treturn: %d\n", *caracter, *palabra, num);

    num = analizaString("aaaa bbbb cccc", palabra, caracter);
    printf("caracter: %d\tpalabra: %d\treturn: %d\n", *caracter, *palabra, num);

    num = analizaString("2+4 = 6", palabra, caracter);
    printf("caracter: %d\tpalabra: %d\treturn: %d\n", *caracter, *palabra, num);

    num = analizaString("Hola, mundo!", palabra, caracter);
    printf("caracter: %d\tpalabra: %d\treturn: %d\n", *caracter, *palabra, num);

    num = analizaString("Hola, mundo", palabra, caracter);
    printf("caracter: %d\tpalabra: %d\treturn: %d\n", *caracter, *palabra, num);

    return 0;
}
