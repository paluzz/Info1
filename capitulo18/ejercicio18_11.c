#include <stdio.h>
#include <string.h>
int validaString(char *dataPtr)
{
    int esNum = 1, esStr = 1, i = 0, status;

    while (*(dataPtr + i) != '\0')
    {
        // si algun caracter no es numero, apagamos la bandera
        if (!(*(dataPtr + i) >= '0' && *(dataPtr + i) <= '9'))
        {
            esNum = 0;
        }
        // si algun caracter no es string, apagamos la bandera
        else if (!(*(dataPtr + i) >= 'a' && *(dataPtr + i) <= 'z') || !(*(dataPtr + i) >= 'A' && *(dataPtr + i) <= 'Z'))
        {
            esStr = 0;
        }
        i++;
    }

    if (esStr == 1)
    {
        status = 1;
    }
    else if (esNum == 1)
    {
        status = 2;
    }
    else
    {
        status = 0;
    }

    return status;
}
void convertirEntero(char *c, int *n)
{
    for (int i = 0; *(c + i) != '\0'; i++)
    {
        n[i] = c[i] - '0';
    }
}

int cuitValida(char *cuit)
{
    int l = strlen(cuit);
    int i, j, suma = 0, digito;
    int ncuit[10];

    // LONGITUD
    if (l != 10)
    {
        return (-1);
    }
    // SOLO NUMEROS
    if (validaString(cuit) != 2)
    {
        return (-2);
    }
    convertirEntero(cuit, ncuit);
    for (i = l - 1, j = 2; i >= 0; i--, j++)
    {
        if (j > 7)
        {
            j = 2;
        }
        ncuit[i] *= j;
        suma += ncuit[i];
    }
    digito = suma % 11;
    return (11 - digito);
}

int main(void)
{
    int valida;

    valida = cuitValida("2012");
    printf("esperado: -1\tobtenido: %d\n", valida);

    valida = cuitValida("abcdefghij");
    printf("esperado: -2\tobtenido: %d\n", valida);

    valida = cuitValida("2012345678");
    printf("esperado: 6\tobtenido: %d\n", valida);

    return 0;
}