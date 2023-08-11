#include <stdio.h>
#include <string.h>
#include <math.h>
int rangoHexa(char *dataPtr)
{
    int l = strlen(dataPtr), contador = 0;
    for (int i = 0; i < l; i++)
    {
        if ((dataPtr[i] >= '0' && dataPtr[i] <= '9') || (dataPtr[i] >= 'A' && dataPtr[i] <= 'F'))
        {
            contador++;
        }
    }
    return (contador == l) ? 1 : -1;
}

int hexaToDec(char *dataPtr)
{
    int l = strlen(dataPtr);
    int dec[4];
    int resultado = 0;
    if (l != 4)
    {
        return (-2);
    }
    if (rangoHexa(dataPtr) != 1)
    {
        return (-1);
    }
    else
    {
        for (int i = 0, j = l - 1; i < l; i++, j--)
        {
            if (dataPtr[i] >= '0' && dataPtr[i] <= '9')
            {
                dec[i] = dataPtr[i] - '0';
            }
            else
            {
                dec[i] = (dataPtr[i] - 'A') + 10;
            }
            resultado += dec[i] * pow(16, j);
        }
    }

    return resultado;
}
int main(void)
{
    int resultado;

    resultado = hexaToDec("0001");
    printf("1: %d\n", resultado);

    resultado = hexaToDec("A12B");
    printf("41259: %d\n", resultado);

    resultado = hexaToDec("CAFE");
    printf("51966: %d\n", resultado);

    resultado = hexaToDec("JJJJ");
    printf("-1: %d\n", resultado);

    resultado = hexaToDec("1");
    printf("-2: %d\n", resultado);

    return 0;
}