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
int luhnAlg(char *tarjeta)
{

    int l = strlen(tarjeta);
    int card[16];
    int resultado = 0, valida;

    // Longitud correcta
    if (l != 16)
    {
        return (-1);
    }
    // Solo strings de numero
    if (validaString(tarjeta) != 2)
    {
        return (-2);
    }
    else
    {
        // convertimos a enteros
        convertirEntero(tarjeta, card);

        for (int i = 0; i <= 16; i += 2)
        {
            card[i] *= 2;
            if (card[i] >= 10)
            {
                card[i] = (card[i] % 10) + 1;
            }
        }
        for (int i = 0; i <= 16; i++)
        {
            resultado += card[i];
        }
        valida = resultado % 10;

        return (valida == 0) ? 0 : -2;
    }
}
int main(void)
{
    int resultado;

    resultado = luhnAlg("abc");
    printf("-1 : %d\n", resultado);

    resultado = luhnAlg("abcdefghijklmnop");
    printf("-2 : %d\n", resultado);

    resultado = luhnAlg("0123456789123456");
    printf("-2 : %d\n", resultado);

    resultado = luhnAlg("0123456789012347");
    printf("0: %d\n", resultado);

    return 0;
}