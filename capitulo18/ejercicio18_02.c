#include <stdio.h>
#define TRUE 1
#define FALSE 0
int validaString(char *dataPtr)
{
    int noNum = TRUE, noStr = TRUE, i = 0, status;

    while (*(dataPtr + i) != '\0')
    {
        // si algun caracter no es numero, apagamos la bandera
        if (!(*(dataPtr + i) >= '0' && *(dataPtr + i) <= '9'))
        {
            noNum = FALSE;
        }
        // si algun caracter no es string, apagamos la bandera
        else if (!(*(dataPtr + i) >= 'a' && *(dataPtr + i) <= 'z') || !(*(dataPtr + i) >= 'A' && *(dataPtr + i) <= 'Z'))
        {
            noStr = FALSE;
        }
        i++;
    }

    if (noStr == TRUE)
    {
        status = 1;
    }
    else if (noNum == TRUE)
    {
        status = 2;
    }
    else
    {
        status = 0;
    }

    return status;
}

int main(void)
{
    char *v[] = {"minuscula", "0123456", "M3zc14", "MAYUSCULA", "CamelCase"};
    int i, valida;

    for (i = 0; i < 5; i++)
    {
        valida = validaString(v[i]);
        printf("El texto '%s' ", v[i]);
        if (valida == 1)
        {
            printf("es String.\n");
        }
        else if (valida == 2)
        {
            printf("es Numero.\n");
        }
        else
        {
            printf("no es nada.\n");
        }
    }

    return 0;
}