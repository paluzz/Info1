#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int validarPassword(char *dataPtr)
{
    int l = strlen(dataPtr), i, mayor = 0, menor = 0, simflag = 0, numeros = 0;
    char simbolo[] = "+-*/._!=?¿¡=()[]{}&$# ";
    char *p = NULL;
    // CARACTERES
    if (l < 8)
    {
        return -1;
    }
    // ESPACIOS
    for (i = 0; i < l; i++)
    {
        if (*(dataPtr + i) == ' ')
        {
            return (-2);
        }
    }

    // MAYUSC Y MINUSC
    for (i = 0; i < l; i++)
    {
        if (*(dataPtr + i) >= 'A' && *(dataPtr + i) <= 'Z')
        {
            mayor = 1;
        }
        else if (*(dataPtr + i) >= 'a' && *(dataPtr + i) <= 'z')
        {
            menor = 1;
        }
    }
    if (!(mayor == 1 && menor == 1))
    {
        return (-3);
    }

    // SIMBOLOS
    for (i = 0; i < l; i++)
    {
        p = strchr(simbolo, *(dataPtr + i));
        if (p != NULL)
        {
            simflag = 1;
        }
    }
    if (simflag == 0)
    {
        return (-4);
    }
    // NUMEROS
    for (i = 0; i < l; i++)
    {
        if (*(dataPtr + i) >= '0' && *(dataPtr + i) <= '9')
        {
            numeros = 1;
        }
    }
    if ((numeros != 1))
    {
        return (-5);
    }

    return 1;
}
int main(void)
{
    int valida;

    valida = validarPassword("Passw0r.d");
    printf("esperado: 1\treturn: %d\n", valida);

    valida = validarPassword("Pass");
    printf("esperado: -1\treturn: %d\n", valida);

    valida = validarPassword("Pass w0r.d");
    printf("esperado: -2\treturn: %d\n", valida);

    valida = validarPassword("passw0r.d");
    printf("esperado: -3\treturn: %d\n", valida);
    valida = validarPassword("PASSW0R.D");
    printf("esperado: -3\treturn: %d\n", valida);

    valida = validarPassword("Passw0rdd");
    printf("esperado: -4\treturn: %d\n", valida);

    valida = validarPassword("Passwor.d");
    printf("esperado: -5\treturn: %d\n", valida);
    return 0;
}