#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
int esNumero(char *dataPtr)
{
    int i = 0;
    int noNum = TRUE;
    while (*(dataPtr + i) != '\0')
    {
        if (!(*(dataPtr + i) >= '0' && *(dataPtr + i) <= '9'))
        {
            noNum = FALSE;
        }
        i++;
    }
    return noNum == TRUE ? TRUE : FALSE;
}
int longitud(char *v)
{
    int i = 0;
    while (*(v + i) != '\0')
    {
        i++;
    }
    return i;
}

int convertirA_Int(char *dataPtr)
{
    int n = 0, largo, exponente;

    if (esNumero(dataPtr) == TRUE)
    {
        largo = longitud(dataPtr);
        exponente = largo - 1;

        for (int i = 0; i < largo; i++)
        {
            n += (*(dataPtr + i) - '0') * (pow(10, exponente));
            exponente--;
        }
    }
    else
    {
        n = ERROR;
    }

    return n;
}
int main(void)
{
    char str[20];
    char *p;
    int entero;
    printf("Ingrese string de numeros: ");
    scanf("%s", str);
    p = &str[0];
    entero = convertirA_Int(p);

    if (entero == ERROR)
    {
        printf("No se pudo convertir\n");
    }
    else
    {
        printf("numero convertido a entero: '%d'\n", entero);
    }

    return 0;
}