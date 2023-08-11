#include <stdio.h>
#include <string.h>
#include <math.h>

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
int strtoInt(char *dataPtr)
{
    int n = 0, i = 0, largo, exponente;
    if (validaString(dataPtr) == 2)
    {
        largo = strlen(dataPtr);
        exponente = largo - 1;

        for (i = 0; i < largo; i++)
        {
            n += (*(dataPtr + i) - '0') * (pow(10, exponente));
            exponente--;
        }
    }
    else
    {
        return -1;
    }

    return n;
}
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

// funcion del ejercicio
float calcularPromedio(char *dataPtr)
{
    float resultado = 0, prom;
    int v[10], i, j, k, numero;
    int longitud = strlen(dataPtr);
    char temp[10], dataTrim[99];

    if (dataPtr[longitud - 1] != ' ' || longitud == 0)
    {
        return NAN;
    }
    // copiamos el string sin espacios
    if (trim(dataPtr, ' ', dataTrim) == 1)
    {
        // comprobamos que sea solo de numeros
        numero = validaString(dataTrim);
        if (numero != 2)
        {
            return NAN;
        }
    }
    // comprobar numeros
    for (i = 0, j = 0, k = 0; i < longitud; i++)
    {
        // copiamos string
        if (dataPtr[i] != ' ')
        {
            temp[k] = dataPtr[i];
            k++;
        }
        else
        {
            // si encontramos espacio, convertimos los caracteres acumulados en un numero
            temp[k] = '\0';
            v[j] = strtoInt(temp);
            j++;
            // reiniciamos el string temporal
            k = 0;
            temp[k] = '\0';
        }
    }

    for (i = 0; i < j; i++)
    {
        resultado += (float)v[i];
    }

    prom = resultado / j;
    return prom;
}
int main(void)
{
    float num;

    num = calcularPromedio("Hola");
    printf("esperado: NaN\tobtenido: %.2f\n", num);

    num = calcularPromedio("");
    printf("esperado: NaN\tobtenido: %.2f\n", num);

    num = calcularPromedio("4 5 6");
    printf("esperado: NaN\tobtenido: %.2f\n", num);

    num = calcularPromedio("0 1 2 3 4 5 6 7 8 9 ");
    printf("esperado: 7\tobtenido: %.2f\n", num);

    return 0;
}